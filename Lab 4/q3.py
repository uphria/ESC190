def change_name(student, new_name):
    student[0] = new_name

student = ["ab", 20]
change_name(student, "cd")
print(student)


# 40    "ab"
# 44    "cd"
# 48    20
# [#40, #48] --> [#44, #48]
# the pointer changes