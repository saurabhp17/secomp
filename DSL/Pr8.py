#Practical no:8
#selection and bubble sort
arr=[]
n=int((input("Enter no of students:")))
for i in range(n):
    arr.append((float(input("Enter student percentage:"))))
print(arr)
def SelectionSort(arr,n):
    for i in range(n):
        min=i
        for j in range(i+1,n):
            if(arr[j]<arr[min]):
                min=j
        arr[i],arr[min]=arr[min],arr[i]

def BubbleSort(arr,n):
    for i in range(n):
        for j in range(0,n-i-1):
            if arr[j]>arr[j+1]:
                arr[j],arr[j+1]=arr[j+1],arr[j]

while True:
    print("***MENU***")
    print("1.Selection sort \n 2.Bubble sort\n 3.exit")
    choice=int(input("Enter choice:"))
    if choice==1:
        SelectionSort(arr,n)
        print(arr)
    elif choice==2:
        BubbleSort(arr,n)
        print(arr)
    elif choice==3:
        break;
    else:
        print("You have enter wrong choice!!!")