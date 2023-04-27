#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "seamcarving.h"
#include "c_img.h"

void calc_energy(struct rgb_img *im, struct rgb_img **grad){
    int height = im->height;
    int width = im->width;
    create_img(grad, height, width);
    int rgb_arr[height][width][3];
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            for (int k = 0; k < 3; k++){
                rgb_arr[i][j][k] = get_pixel(im, i, j, k);
            }
        }
    }
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            int x_sum = 0;
            int y_sum = 0;
            int top_val = i - 1;
            int bottom_val = i + 1;
            int left_val = j - 1;
            int right_val = j + 1;
            if (i == 0)
                top_val = height - 1;
            if (i == height - 1)
                bottom_val = 0;
            if (j == 0)
                left_val = width - 1;
            if (j == width - 1)
                right_val = 0;
            for (int k = 0; k < 3; k++){
                x_sum = x_sum + (rgb_arr[i][right_val][k]-rgb_arr[i][left_val][k])*(rgb_arr[i][right_val][k]-rgb_arr[i][left_val][k]);
                y_sum = y_sum + (rgb_arr[top_val][j][k]-rgb_arr[bottom_val][j][k])*(rgb_arr[top_val][j][k]-rgb_arr[bottom_val][j][k]);                 
            }
            int dual_gradient = (uint8_t)(sqrt(x_sum + y_sum)/10);
            set_pixel(*grad, i, j, dual_gradient, dual_gradient, dual_gradient);
        }
    }
}

void dynamic_seam(struct rgb_img *grad, double **best_arr){
    int height = grad->height;
    int width = grad->width;
    *best_arr = (double*)malloc(height*width*sizeof(double));
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            if (i == 0){
                (*best_arr)[i*width+j] = get_pixel(grad, i, j, 0);
            } else if (j == 0){
                int case1 = (*best_arr)[(i-1)*width+j];
                int case2 = (*best_arr)[(i-1)*width+j+1];
                (*best_arr)[i*width+j] = ((case1 < case2) ? case1 : case2) + get_pixel(grad, i, j, 0);
            } else if (j == width-1){
                int case1 = (*best_arr)[(i-1)*width+j];
                int case2 = (*best_arr)[(i-1)*width+j-1];
                (*best_arr)[i*width+j] = ((case1 < case2) ? case1 : case2) + get_pixel(grad, i, j, 0);
            } else {
                int case1 = (*best_arr)[(i-1)*width+j];
                int case2 = (*best_arr)[(i-1)*width+j-1];
                int case3 = (*best_arr)[(i-1)*width+j+1];
                int min1 = ((case1 < case2) ? case1 : case2);
                (*best_arr)[i*width+j] = ((case3 < min1) ? case3 : min1) + get_pixel(grad, i, j, 0);
            }
        }
    }
}

void recover_path(double *best, int height, int width, int **path){
    *path = (int*)malloc(height*sizeof(int));
    for (int i = height - 1; i > -1; i--){
        if (i == height - 1){
            int min = best[i*width];
            int index = 0;
            for (int j = 0; j < width; j++){
                if (best[i*width+j] < min){
                    index = j;
                    min = best[i*width+j];
                }
            }
            (*path)[height-1] = index;
        } else if ((*path)[i+1] == 0){
            int case1 = best[i*width+(*path)[i+1]];
            int case2 = best[i*width+(*path)[i+1]+1];
            if (case1 < case2){
                (*path)[i] = 0;
            } else {
                (*path)[i] = 1;
            }     
        } else if ((*path)[i+1] == width-1){
            int case1 = best[i*width+(*path)[i+1]];
            int case2 = best[i*width+(*path)[i+1]-1];
            if (case1 < case2){
                (*path)[i] = width-1;
            } else {
                (*path)[i] = width-2;
            }    
        } else {
            int case1 = best[i*width+(*path)[i+1]];
            int case2 = best[i*width+(*path)[i+1]-1];
            int case3 = best[i*width+(*path)[i+1]+1];
            if (case1 <= case2 && case1 <= case3){
                (*path)[i] = (*path)[i+1];
            } else if (case2 <= case1 && case2 <= case3){
                (*path)[i] = (*path)[i+1] - 1;
            } else {
                (*path)[i] = (*path)[i+1] + 1;
            } 
        }
    }
}

void remove_seam(struct rgb_img *src, struct rgb_img **dest, int *path){
    int height = src->height;
    int width = src->width-1;
    create_img(dest, height, width);
    for (int i = 0; i < height; i++){
        for (int j = 0; j < path[i]; j++){
            int arr[3];
            for (int k = 0; k < 3; k++){
                arr[k] = (int)get_pixel(src, i, j, k);
            }
            set_pixel(*dest, i, j, arr[0], arr[1], arr[2]);
        }
        for (int j = path[i]; j < width; j++){
            int arr[3];
            for (int k = 0; k < 3; k++){
                arr[k] = (int)get_pixel(src, i, j+1, k);
            }
            set_pixel(*dest, i, j, arr[0], arr[1], arr[2]);
        }
    }
}

/*
int main(){
    struct rgb_img *im;
    struct rgb_img *cur_im;
    struct rgb_img *grad;
    double *best;
    int *path;

    read_in_img(&im, "HJoceanSmall.bin");
    
    for(int i = 0; i < 250; i++){
        printf("i = %d\n", i);
        calc_energy(im,  &grad);
        dynamic_seam(grad, &best);
        recover_path(best, grad->height, grad->width, &path);
        remove_seam(im, &cur_im, path);

        char filename[200];
        sprintf(filename, "img%d.bin", i);
    

        destroy_image(im);
        destroy_image(grad);
        free(best);
        free(path);
        im = cur_im;
    }
    write_img(cur_im, "output.bin");

    destroy_image(im);

    return 0;
}

int main1(){
    struct rgb_img *im;
    struct rgb_img *cur_im;
    struct rgb_img *grad;
    double *best;
    int *path;

    read_in_img(&im, "okhere.bin");
    
    calc_energy(im,  &grad);
    dynamic_seam(grad, &best);
    recover_path(best, grad->height, grad->width, &path);
    remove_seam(im, &cur_im, path);

    char filename[200];
    sprintf(filename, "img.bin");
    write_img(cur_im, filename);


    destroy_image(im);
    destroy_image(grad);
    free(best);
    free(path);
    im = cur_im;

    destroy_image(im);
}

// gcc -o a.out seamcarving.c c_img.c

*/