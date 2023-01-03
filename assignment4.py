start = 1
members = []
sorted = 0


def accept_club_members():
    num_members = int(input("Enter number of members: "))
    for i in range(num_members):
        members.append(int(input(f'Enter rno of member {i + 1}: ')))


def search_club_member_iteratively():
    if sorted == 0:
        print("List has not been sorted yet")
    return


to_search = int(input("Enter member to search :"))
low = 0
high = len(members) - 1
while (low <= high):
    mid = (low + high) // 2
if members[mid] > to_search:
    high = mid - 1
elif members[mid] < to_search:
    low = mid + 1
else:
    return mid
return -1


def search_club_member_recursively(to_search=0, low=0, high=0):


if low > high:
    print(f'low = {low}, high = {high}')
return -1
if sorted == 0:
print("List has not been sorted yet")
return
mid = (low + high) // 2
if members[mid] > to_search:
high = mid - 1
return search_club_member_recursively(to_search=to_search, low=low, high=high)


elif members[mid] < to_search:
low = mid + 1
return search_club_member_recursively(to_search=to_search, low=low, high=high)

else:
return mid


def sort_members():


global sorted
sorted = 1
for i in range(len(members)):
temp_sorted = 1
for index in range((len(members)-1) - i):
if members[index] > members[index + 1]:
temp = members[index]
members[index] = members[index + 1]
members[index + 1] = temp
temp_sorted = 0
if temp_sorted:
break
print("Sorted list :")
for member in members:
print(member, end=' ')
print("\n")

while (start):
print("----------Menu----------")
print("Enter 1 to enter club members :")
print("Enter 2 to search club members iteratively using Ternary search:")
print("Enter 3 to search club members recursively using Ternary search:")
print("Enter 4 to sort members: ")
print("Enter 5 to exit: \n")
choice = int(input())
if choice == 1:
accept_club_members()
elif choice == 2:
position = search_club_member_iteratively()
if position == -1:
print("Member not found")
else:
print(f"Member is at position {position + 1}")
elif choice == 3:
to_search = int(input("Enter member to search :"))
position = search_club_member_recursively(
    to_search=to_search, high=len(members))

if position == -1:
print("Member not found")
else:
print(f"Member is at position {position + 1}")
elif choice == 4:
sort_members()
elif choice == 5:
start = 0
