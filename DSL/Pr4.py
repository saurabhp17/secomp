string = input("Enter the string : ")
# 1.To display frequency of occurance of particular character in the string

def Freq_char():

    
    character = input("Enter the character to check frequency : ")
    count=0
    for i in string :             # to  traverse through each character in the string
        if i==character :
            count += 1

    print( character , "occurs", count+1 , "times")

# 2.To check whether string is palindrome(same when read from forward and backward)

def Palindrome():
    
    
    temp = []
    temp1=[]
    temp = string.casefold()   #converting all alphabets to lower case
    for i in temp:
        if (  ord(i)!= 32):
            temp1.append(i)


    reverse_string = temp1[::-1]
    if temp1 == reverse_string :
        print("Given string is palindrome")
    else:
        print("string is not palindrome")

# 3. To display the index  of first appearance of substring
def Sub_string():

    substring= input("\n Enter the substring :")
    ind = string.find(substring)
    print("\n First occurence of sub_string  is   " ,  ind)

while True:
    print("\n***  MENU  *** ")
    print("\n 1.To count frequency of particular character ")
    print("\n 2.To check whether string  is palindrome or not  ")
    print("\n 3.To display index of first appearance of the substring  ")
    print("\n 4. Exit")
    choice = int(input("\n Enter the choice :"))
    if choice == 1:
        Freq_char()

    elif choice == 2:
        Palindrome()

    elif choice ==3:
        Sub_string()

    elif choice== 4:
        break
    else :
        print("\n Incorrect Choice")