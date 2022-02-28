### This indeicates a line that I have removed/replaced

import re
import string


# print multiplication table of n
def MultiplicationTable():
    n = int(input("\nEnter number: "))
    for i in range(1, 11):
        print (str(n) + " x "+str(i) + " = " + str(n * i))
         
### v# input number n from user
### n = int(input('\nEnter number: '))

### #print Multiplication Table
### MultiplicationTable()

# print Double Value of v     
def DoubleValue():
    v = int(input("\nDouble of value: "))
###    print ('Double of value: ', end='')
    print(str(v) + " doubled is " + str(2 * v))
  
### v = int(input('\nEnter number: '))

### DoubleValue()

