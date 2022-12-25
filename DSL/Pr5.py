

def Add_Sub():
    row1=int(input("Enter no of rows of first matrix:"))
    col1=int(input("Enter no of columns of fisrt matrix:"))
    Mtr1=[]
    print("\n Enter elements of matrix row wise:")
    for i in range(row1):
        sublist1=[]
        for j in range(col1):
            sublist1.append(int(input("Enter elements of matrix one:")))
        Mtr1.append(sublist1)
    print("\n Matrix 1:")
    for i in Mtr1:
        print(i) 
    
    row2=int(input("Enter no of rows of second matrix:"))
    col2=int(input("Enter no of columns of second matrix:"))
    Mtr2=[]
    print("\n Enter elements of matrix row wise")
    for i in range(row2):
        sublist2=[]
        for j in range(col2):
            sublist2.append(int(input("Enter elements of matrix two:")))
        Mtr2.append(sublist2)
    print("\n Mtrix 2:")
    for i in Mtr2:
        print(i)

    if(row1!=row2 and col1!=col2):
        print("Addition and subtraction is not possible")
    else:
        Add=[]
        for i in range(row1):
            temp1=[]
            for j in range(col1):
                add=Mtr1[i][j]+Mtr2[i][j]
                temp1.append(add)
            Add.append(temp1)
        print("Addition of matrices is:")
        for i in Add:
            print(i)
        Sub=[]
        for i in range(row1):
            temp2=[]
            for j in range(col1):
                sub=Mtr1[i][j]-Mtr2[i][j]
                temp2.append(sub)
            Sub.append(temp2)
        print("Subtraction of matrices is:")
        for i in Sub:
            print(i)

def Mul():
    row1=int(input("Enter no of rows of first matrix:"))
    col1=int(input("Enter no of columns of fisrt matrix:"))
    Mtr1=[]
    print("\n Enter elements of matrix row wise:")
    for i in range(row1):
        sublist1=[]
        for j in range(col1):
            sublist1.append(int(input("Enter elements of matrix one:")))
        Mtr1.append(sublist1)
    print("\n Matrix 1:")
    for i in Mtr1:
        print(i) 
    
    row2=int(input("Enter no of rows of second matrix:"))
    col2=int(input("Enter no of columns of second matrix:"))
    Mtr2=[]
    print("\n Enter elements of matrix row wise")
    for i in range(row2):
        sublist2=[]
        for j in range(col2):
            sublist2.append(int(input("Enter elements of matrix two:")))
        Mtr2.append(sublist2)
    print("\n Mtrix 2:")
    for i in Mtr2:
        print(i)
    if(row1!=row2 and col1!=col2):
        print("Multiplaction is not possible")
    else:
        Mul=[]
        for i in range(row1):
            sublist=[]
            for j in range(col1):
                e=0
                for k in range(col1):
                    e=e+(Mtr1[i][k]*Mtr2[k][j])
                sublist.append(e)
            Mul.append(sublist)
        print("Multiplication of matrix is:")
        for i in Mul:
            print(i)


def transpose():
    row=int(input("Enter no of rows:"))
    col=int(input("Enter no of columns:"))
    Mtr=[]
    print("Enter elements of matrix row wise")
    for i in range(row):
        sublist=[]
        for j in range(col):
            sublist.append(int(input("Enter elements of matrix:")))
        Mtr.append(sublist)
    print("Matrix is:")
    for i in Mtr:
        print(i)

    Trans=[]
    for i in range(row):
        Trans.append([])
        for j in range(col):
            Trans[i].append([])
            Trans[i][j]=Mtr[j][i]
    print("Transpose of matrix is:")
    for i in Trans:
        print(i)

while True:
    print("***Menu***")
    print("1.Addition and Subtraction \n 2.Multiplication\n 3.Transpose \n 4.Exit")
    choice=int(input("Enter choice:"))
    if choice==1:
        Add_Sub()
    if choice==2:
        Mul()
    if choice==3:
        transpose()
    if choice==4:
        break;
    else:
        print("you have entered wrong choice!!!")
