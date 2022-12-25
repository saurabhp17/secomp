#Binary search and sentinel search
roll = []
n= int(input("Enter The No of students-->"))
print("Enter Roll no of students  :")
for i in range (n):
    roll.append(int(input()))

key = int(input("enter the roll no to be searched :"))

def SentinelSearch(arr,key,n):
    last = arr[n-1]     # storing last element
    arr[n-1]=key        # replacing last element by key
    i=0
    while(arr[i]!= key):
        i = i+1

    arr[n-1]= last      # original list(replacing key by last element)


    if( (i<n-1) or  (key == arr[n-1]) ):       # checking if i<n-1 (found in between) or 
        print(key," found at -->",i)            # after relacing key by last found at arr[n-1]

    else:
           print("not found")


def BinarySearch(arr,key,n):
    flag = 0
    low = 0
    high = len(roll) - 1
    mid = 0
    while (low<=high):
        mid = (low + high) // 2
        if (roll[mid] == key):
            flag = 1
            print(key ," Found at index--> ",mid)
            break
        elif(roll[mid] > key):
            high = mid-1
        else:
            low = mid+1

        
    
    if(flag==0):
        print("Not found")
while True:
    print("1.Sentinel Search \n2.Binary Search \n3.exit")
    choice = int(input("\nEnter your choice :"))
    if (choice==1):
        print("\n**** Sentinel Search ****")
        SentinelSearch(roll,key,n)
    if(choice==2):
        print("\n**** Binary Search ****")
        roll.sort()
        BinarySearch(roll,key,n)
    if(choice==3):
        break
