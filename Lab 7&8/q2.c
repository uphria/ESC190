#include <stdlib.h>
#include <stdint.h>
#include "c_img.h"

void brighten(struct rgb_img *img, float num){
    int height = img->height;
    int width = img->width;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            int arr[3];
            for (int k = 0; k < 3; k++){
                arr[k] = (int)get_pixel(img, i, j, k)*num;
                if (arr[k] > 255){
                    arr[k] = 255;
                }
            }
            set_pixel(img, i, j, arr[0], arr[1], arr[2]);
        }
    }
}

// how to do negative?
// is the float method ok?

int main(void) {
    struct rgb_img *img;
    read_in_img(&img, "image.bin");
    brighten(img, 1);
    write_img(img, "cannon_change.bin");
}