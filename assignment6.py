percentages = []
start = 1


def input_elems():
    global percentages

    size = int(input("Enter number of student percentages: "))
    for i in range(size):
     percentages.append(float(input(f"Enter percentage of student {i + 1}: ")))


def quick_sort(pivot, iter_low, iter_high):
    global percentages
    low = iter_low
    high = iter_high
    list_sorted = 0
    while not list_sorted:
     list_sorted = 1
    while (low <= pivot):
     if percentages[pivot] < percentages[low]:
      temp = percentages[pivot]

percentages[pivot] = percentages[low]
percentages[low] = temp
pivot = low
list_sorted = 0
break
low += 1

while (high >= pivot):
  if percentages[pivot] > percentages[high]:
    temp = percentages[pivot] 
    percentages[pivot] = percentages[high]
    percentages[high] = temp
    pivot = high
     list_sorted = 0
 break
    high -= 1
    left_sorted = 1

for i in range(pivot):
if percentages[i] > percentages[i + 1]:
    left_sorted = 0
    right_sorted = 1
for i in range(pivot, iter_high):
if percentages[i] > percentages[i + 1]:
    right_sorted = 0
if not left_sorted:
    quick_sort(pivot=iter_low, iter_low=iter_low, iter_high=pivot-1)

if not right_sorted:
    quick_sort(pivot=pivot+1, iter_low=pivot+1, iter_high=iter_high)

while (start):
    print("\nEnter 1 to input elems: ")
    print("Enter 2 to display elems: ")
    print("Enter 3 to sort using quick sort: ")
    print("Enter 4 to list top 5: ")
    print("Enter 5 to exit: ")
    print("Choose: ", end=" ")
    choice = int(input())

if choice == 1:
    input_elems()

elif choice == 2:
    print("Percentages in array : ")
    print(", ".join([str(value) for value in percentages]))

elif choice == 3:
    quick_sort(0, 0, len(percentages)-1)
    print("Sorted array of percentages: ")
    print(", ".join([str(value) for value in percentages]))

elif choice == 4:
    quick_sort(0, 0, len(percentages) - 1)
    print("Top 5 percentages: ")
    print(", ".join([str(value) for value in percentages[:-6:-1]]))
elif choice == 5:
   start = 0
