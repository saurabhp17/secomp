#Practical no:1
cricket=list(input("Enter roll no of students who play cricket:").split(','))
badminton=list(input("Enter roll no of students who play badminton:").split(','))
football=list(input("Enter roll no of students who play football:").split(','))
print("\n")
#list of students who play both cricket and badminton
def intersection():
    res=[]
    for i in cricket:
        for j in badminton:
            if i==j:
                res.append(i)
    if len(res)!=0:
        print("Students who play both cricket and badminton are:",res,"\n")
    else:
        print("None of them play both\n")

#list of students who play either cricket or badminton but not both
def CricorBad():
    temp1=[]
    for i in cricket:
        if i not in badminton:
            temp1.append(i)
    for i in badminton:
        if i not in cricket:
            temp1.append(i)
    print("Students who play either cricket or badminton but not both",temp1,"\n")

while True:
    print("****MENU***")
    print("1.Students who play both cricket and badminton \n 2.Students who play either cricket or badminton but not both\n 3.Exit")
    choice=int(input("Enter choice:"))
    if choice==1:
        intersection()
    if choice==2:
        CricorBad()
    if choice==3:
        break;
    else:
        print("you have enter wrong choice")