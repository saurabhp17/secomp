#Linear and Fibbonacci
roll = []
n= int(input("Enter The No of students-->"))
print("Enter Roll no of students  :")
for i in range (n):
    roll.append(int(input()))

key = int(input("enter the roll no to be searched :"))



def LinearSearch(arr,key,n):
    flag = 0 
    for i in range (n):
        if ( arr[i]==key ):
            flag = 1
            break
    
    if(flag==1):
        print(key,"  found at -->",i)
    else:
        print("not found")

fibo = []
def FibonacciGenerate(n):
    a = 0
    b = 1
    fibo.append(a)
    fibo.append(b)
    for i in range(n):
        next = a + b 
        a = b
        b = next
        fibo.append(next)


    
def FibonacciSearch(arr,key,n):
    
    m=0
    while(fibo[m] < n ):       # find the smallest fibonacci number greater than or equal to
          m = m+1                #  length of array
      
    offset = -1


    while (fibo[m] > 1):
        i = min(  (offset + fibo[m-2]  )  , n-1 )

        if(arr[i] < key):
            m = m-1
            offset = i 

        elif(arr[i] > key):
            m = m -2

        else:
            return i

        if(arr[n-1 ]== key):
            return n-1

    return -1

while True:
    print("\n1.Linear Search \n2.Fibonacci Search \n3.exit")
    choice = int(input("\nEnter your choice :"))
    if(choice==1):
        print("\n**** Linear Search ****")
        LinearSearch(roll,key,n)
    if(choice==2):
        print("\n**** Fibonacci Search ****")
        roll.sort()
        FibonacciGenerate(n)
        index = FibonacciSearch(roll,key,n)
        if(index > 0):
            print(key," Found at ->" , index)
        else:
            print(key , " Not found")
    if choice ==3:
        break;
    

