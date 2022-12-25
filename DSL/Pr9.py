#Quick sort
arr = []
n = int(input("Enter the no of elements :"))
for i in range(n):
    arr.append(float(input("Enter %dth student percentage-->"%i)))


def Partition(arr,low,high):

    pivot = arr[low]   # choosing first element as pivot
    i = low + 1
    j = high
    

    while True:

        #increment i while arr[i] less than pivot
        while (i<=j  and arr[i]<= pivot):
            i = i+1

        #decrement j while arr[j] greater than pivot
        while (i<=j  and arr[j]>= pivot):
            j = j-1

        # swap
        if(i<=j):
            arr[i],arr[j] = arr[j],arr[i]


        else:
            break

    # swap pivot with arr[j]
    arr[low],arr[j] = arr[j],arr[low]

    return j
         

def QuickSort(arr,low,high):
    if(low < high):
        p = Partition(arr,low,high)    # partitioning index returned by Partition function
        QuickSort(arr,low,p-1)
        QuickSort(arr,p+1,high)


QuickSort(arr,0,n-1)

print("\n Sorted array is-->")
print(arr)
print("\nTop Five scores are-->")
for i in range(5):
    print(arr[i])

