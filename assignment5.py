from typing import Sized


percentages = []
start = 1

def take_input():
 size = int(input("Enter number of percentages: "))
for i in range(Sized):
  percentages.append(float(input(f"Please enter percentage of student {i+1}: ")))


def selection_sort():
 global percentages

for i in range(len(percentages)): smallest = i
for j in range(i, len(percentages)):
 if percentages[j] < percentages[smallest]:
  smallest = j
temp = percentages[smallest]
percentages[smallest] = percentages[i]
percentages[i] = temp

print("Sorted list : ")
print(", ".join([str(elem) for elem in percentages]))
def bubble_sort():
 global percentages

for i in range(len(percentages)):sorted = 0
while(not sorted):
 sorted = 1
for j in range((len(percentages)-1)-i):
 if percentages[j] > percentages[j + 1]:
  temp = percentages[j]
 percentages[j] = percentages[j + 1]
 percentages[j + 1] = temp
sorted = 0

if sorted: 
   break
   
print("Sorted list : ")
print(", ".join([str(elem) for elem in percentages]))

while(start):
 print("\nEnter 1 to give input: ")
 print("Enter 2 to sort using selection sort: ")
 print("Enter 3 to sort using bubble sort: ")
 print("Enter 4 to stop")
 print("Your choice:", end=" ")
 choice = int(input())

 if choice == 1:
   take_input()
 elif choice == 2:
   selection_sort()
 
 elif choice == 3:
   bubble_sort()
 elif choice == 4:
  start = 0
