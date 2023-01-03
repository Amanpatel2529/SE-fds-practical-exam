# Code for matrix multiplication

matrix1 = []
matrix2 = []
result_matrix = []
rows1 = int(input('Enter number of rows for 1st matrix :'))
columns1 = int(input('Enter number of columns for 1st matrix :'))
rows2 = int(input('Enter number of rows for 2nd matrix :'))
columns2 = int(input('Enter number of columns for 2nd matrix :'))

if columns1 != rows2:
    print("Matrix multiplication not possible!")
    exit()
rows = rows1 
columns = columns2

print("\nFor matrix 1 : ")
for i in range(rows1):
       temp = []
for j in range(columns1):
           temp.append(int(input(f'Enter element a{i+1}{j+1} :')))
           matrix1.append(temp)

           print("\nFor matrix 2 : ")
for i in range(rows2):
   temp = []
for j in range(columns2):
    temp.append(int(input(f'Enter element b{i+1}{j+1} :')))
    matrix2.append(temp)

for i in range(rows1):
    temp = []
    for j in range(columns2):
        sum = 0
    for k in range(rows2):
           sum += matrix1[i][k] * matrix2[k][j]
    temp.append(sum)
    result_matrix.append(temp)

    print("\nResult matrix after multiplication :")
    for row in result_matrix:
       for element in row:
          print(element, end=' ')
          print('\n', end='')
