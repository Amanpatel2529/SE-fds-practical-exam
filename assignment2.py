def average_marks(student_marks):
    if len(student_marks) == 0:
        return "Everybody was absent.."


sum = 0
for marks in student_marks:
    sum = sum + marks
    return sum/len(student_marks)


def highest_marks(student_marks):
    if len(student_marks) == 0:
        return "Everybody was absent.."
    else:
        highest = student_marks[0]


for marks in student_marks:
    if marks > highest:
        highest = marks
        return highest


def lowest_marks(student_marks):
    if len(student_marks) == 0:
        return "Everybody was absent.."
    else:
        lowest = student_marks[0]


for marks in student_marks:
    if marks < lowest:
        lowest = marks
        return lowest


def frequency(student_marks):
    if len(student_marks) == 0:
        return "Everybody was absent.."
    else:


my_dict = {}
for index, marks in enumerate(student_marks):
if my_dict.get(marks, 0):
continue
else:
my_dict[marks] = student_marks.count(marks)
highest_num = 0
highest_freq = 0
for key, value in my_dict.items():
    highest_num = key
    highest_freq = value
break
for key, value in my_dict.items():
if value > highest_freq:
highest_num = key
highest_freq = value
return [highest_num, highest_freq]

student_marks = []
absent_count = 0
N = int(input("Please enter number of students: "))
print(f"Enter marks for {N} students(write 'absent' for absent student): \n")

for mark in range(N):
marks = input()
if marks.lower() == 'absent':
absent_count += 1
else:
student_marks.append(int(marks))
print(f"Average marks = {average_marks(student_marks)}")
print(f"Highest marks = {highest_marks(student_marks)}")
print(f"Lowest marks = {lowest_marks(student_marks)}")
print(f"Total absent students = {absent_count}")
frequency_count = frequency(student_marks)
print(
    f"Marks {frequency_count[0]} have the highest frequency of {frequency_count[1]}")
