# Q2

def to_10(a):
    a = 10
    return a

def to_10_global():
    global b
    b = 10

a = 5
a = to_10(a)
print(a)

b = 5
to_10_global()
print(b)

'''similarities: for global version, modifies from the main frame, like how p_a modifies the object at location a in C
   differences: to_10 only works if a is equated to to_10, which is different from the C code. The C version also uses pointers to a's location, 
                rather than directly referencing a in Python'''

#Q3

def change_str(s):
    s = "Goodbye World"
    return s

def change_str_global():
    global s1
    s1 = "Goodbye World"

s = "Hello World"
s = change_str(s)
print(s)

s1 = "Hello World"
change_str_global()
print(s1)