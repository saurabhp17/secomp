#Problem statement no:3
#1 To display a word with longest length in the string

string = input("Enter the string: ")

def LongestWord():
    
    
    s = string.split( )
    print(s)
    count=0
    
    for i in s:
        
        if len(i)>count:
            count=len(i)
            longest_word = i

    print("word with maximum length in given string is :" , longest_word)
    print("length of longest word is : " , count)
#2.To count occurance of each word
def Freq_word():

    string_list = string.split(" ")
    dict = {}
    for i in string_list :      # for each word in list
        dict[i] = str(string_list.count(i)) 

    for key, value in dict.items():
        print(key + " Occurs " + value + " Times")
  
while True:
    print("\n***  MENU  *** ")
    print("\n 1.Display the word with longest length ")
    print("\n 2.To Count the frequency of each word ")
    print("\n 3. Exit")
    choice = int(input("\n Enter the choice :"))

    if choice == 1:
       LongestWord()

    elif choice == 2:
        Freq_word()

    elif choice== 3:
        break
    else :
        print("\n Incorrect Choice")


    



        