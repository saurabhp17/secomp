#Practical No2:
cricket=list((input("Enter roll no of students who play cricket:").split(',')))
Badminton=list((input("Enter roll no of students who play Badminton:").split(',')))
Football=list((input("Enter roll no of students who play Football:").split(',')))
#Students who play neither cricket nor badminton
def NorCricNorBad():
    temp1=[]
    for i in Football:
        if (i not in cricket) and (i not in Badminton):
            temp1.append(i)
    print("Number of Students who play neither cricket nor badminton are:",len(temp1),"and they are",temp1,"\n")

#students who play cricket and football but not badminton
def Cric_foot():
    temp2=[]
    for i in cricket:
        for j in Football:
            if i==j:
                if (i not in Badminton):
                    temp2.append(i)
    if(temp2 !=0):
        print("Number of students who play cricket and football but not badminton are:",len(temp2),"and they are:",temp2,"\n")
    else:
        print("None of student play both cricket and football but not badminton !")

while True:
    print("***MENU***\n")
    print("1.Students who play neither cricket nor badminton \n 2.students who play cricket and football but not badminton \n 3.Exit\n")
    choice=int(input("Enter choice:"))
    if choice==1:
        NorCricNorBad()
    if choice==2:
        Cric_foot()
    if choice==3:
        break
    else:
        print("You have enter wrong choice")





