cricket_set = {"Amit", "Ravi", "Raj", "Priya"}
badminton_set = {"Ravi", "Rahul", "Raj", "Meena"}
football_set = {"Rahul", "Meena", "Amit", "Mahesh"}

intersection_set = set()
sym_diff_set = set()
diff_set = set()
fourth_set =set()

for student in cricket_set:
  if student in badminton_set:
   intersection_set.add(student)

  print("Students who play both cricket and badminton: ")

for element in intersection_set:
  print(element, end=' ')

for student in cricket_set:
  if student not in badminton_set:
   sym_diff_set.add(student)

for student in badminton_set:
  if student not in cricket_set:
   sym_diff_set.add(student)

print("\nStudents who play either cricket or badminton but not both: ")


for element in sym_diff_set:
  print(element, end=' ')

for student in football_set:
   if student not in cricket_set and student not in badminton_set:
     diff_set.add(student)

print(f"\nNumber of students who play neither cricket not badminton: \n {len(diff_set)}")


for student in cricket_set:
   if student in football_set and student not in badminton_set:
    fourth_set.add(student)

   print(f"Number of students who play cricket and football but not badminton: \n {len(fourth_set)}")