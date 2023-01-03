# Code for matrix transpose

matrix = []
result_matrix = []
rows1 = int(input('Enter number of rows for matrix :'))
columns1 = int(input('Enter number of columns for matrix :'))

print("\nFor matrix : ")
for i in range(rows1):
    temp = []
    for j in range(columns1):
        temp.append(int(input(f'Enter element a{i+1}{j+1} :')))
    matrix.append(temp)

for j in range(columns1): 
        temp = []
for i in range(rows1):
        temp.append(matrix[i][j])
result_matrix.append(temp)

print("\nMatrix before transpose :")
for row in matrix:
     for element in row:
         print(element, end=' ')
         print('\n', end='')
         print("Result matrix after transpose :")
         for row in result_matrix:
              for element in row:
                print(element, end=' ')
                print('\n', end='')
