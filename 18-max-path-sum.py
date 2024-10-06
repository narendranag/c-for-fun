'''
Find the maximum total from top to bottom

    3
   7 4
  2 4 6
 8 5 9 3

OR

3
7 4
2 4 6
8 5 9 3


Let's break this down

row 0 has 1 number
row 1 has 2 numbers
...
row 4 has 5 mumbers

or row n has n+1 numbers

In four rows there are 8 (2 x total number of rows) sums

first sequence

1,1 > 2,1 > 3,1 > 4,1 = 3 + 7 + 2 + 8 = 20

1,1 > 2,1 > 3,1 > 4,2 = 3 + 7 + 2 + 5 = 17
1,1 > 2,1 > 3,2 > 4,2 = 3 + 7 + 4 + 5 = 19
1,1 > 2,2 > 3,2 > 4,2 = 3 + 4 + 4 + 5 = 16

1,1 > 2,1 > 3,2 > 4,3 = 3 + 7 + 4 + 9 = 23
1,1 > 2,2 > 3,2 > 4,3 = 3 + 4 + 4 + 9 = 20
1,1 > 2,2 > 3,3 > 4,3 = 3 + 4 + 6 + 9 = 22


1,1 > 2,2 > 3,3 > 4,4 = 3 + 4 + 6 + 3 = 16

'''

triangle = [3], [7,4], [2,4,6], [8,5,9,3]

iteration, i,j = 0,0,0
multiplier = 0
sum[i] = 0

while(iteration < 13):
    sum[i] += triangle[i][j]
    i += 1
    if(i == 4):
        multiplier += 1

    j += (multiplier * i)










