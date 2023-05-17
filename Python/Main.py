def writeEmployee():  
    with open('Employee.txt','a') as file :
        c = 'y'
        while c =='y' or c=='Y' :
            Id=input('Enter id : ')
            Name=input('Enter name : ')
            file.write(Id+'\t'+Name+'\n')
            c=input('Do you want to enter records again ? (y or n) ')
 
 
 
#*******************************************************************************#*******************************************************************************#
 
            
            
def readEmployee():
    with open('Employee.txt','r') as file :
        print('ID\tName')
        print('------------------------')
        for line in file:
            print(line, end='')
 
 
 
#*******************************************************************************#*******************************************************************************#
 
 
 
def writeCustomer():
    with open('Customer.txt','a') as file :
        Name=input('Enter your  name : ')
        Phone=input('Enter your phone number : ')
        file.write(Name+'\t'+Phone+'\n')
 
 
 
#*******************************************************************************#*******************************************************************************#
 
        
        
def readCustomer():
    with open('Customer.txt','r') as file :
        print('Name\tPhoneNumber')
        print('--------------------------')
        for line in file:
            print(line, end='')
 
 
 
#*******************************************************************************#*******************************************************************************#
 
            
            
def writeProduct(Employee_ID):
    with open('Product.txt', 'a')as file:
        c='y'
        while c=='y' or c=='Y':
            ID=input('Enter the product id: ')
            Name=input('Enter the product name: ')
            Price=input('Enter the product price: ')
            file.write(ID+'\t'+Name+'\t'+Price+'\t'+Employee_ID+'\n')
            c=input('Enter records of product again (y/n)? ')
            
 
            
#*******************************************************************************#*******************************************************************************#
 
 
            
def readProduct(): # with employeeId
    with open('Product.txt', 'r')as file:
        print('ID\tName\tPrice\tEmployee_ID')
        print('-----------------------------------')
        for line in file:
            print(line , end='')
 
            
 
#*******************************************************************************#*******************************************************************************#
 
 
 
def readProduct2(): # without employeeId
    with open('Product.txt', 'r')as file:
        print('ID\tName\tPrice')
        print('---------------------')
        for line in file:
             l=line.split('\t')
             print(l[0] + '\t' + l[1] + '\t' + l[2])
 
 
            
 
 
 
 
#*******************************************************************************#*******************************************************************************#
 
 
 
            
def searchProduct():
    Name=input('Enter the name for the product to search: ')
    found=False
    with open('Product.txt', 'r') as file:
        for line in file:
            pr=line.split('\t')
            if Name==pr[1]:
                found=True
                print('ID:',pr[0],'\tName:',pr[1],'\tPrice:',pr[2])
        if not found:
            print('\n"Sorry, The product is not found!"\n')
 
 
 
 
 
#*******************************************************************************#*******************************************************************************#
 
 
        
 
def deleteProduct():
    import os
    ID=input('Enter the id for the product: ')
    found=False
    file=open('Product.txt', 'r')
    tempProduct=open('TempProduct.txt', 'w')
    for line in file:
        pr=line.split('\t')
        if ID==pr[0]:
            found=True
        else:
            tempProduct.write(line)
    file.close()
    tempProduct.close()
    os.remove('Product.txt')
    os.rename('TempProduct.txt','Product.txt')
    if found:
        print('\n"Product record deleted successfuly"\n')
    else :
        print('\n"Sorry, The product is not found!"\n')
 
 
 
 
#*******************************************************************************#*******************************************************************************#
 
 
 
def updateprice(EmployeeID):
    import os
    ID=input('Enter the ID of the product you want to update this price: ')
    flag=False
    file=open("Product.txt","r")
    tempfile=open("TempProduct.txt","w")
    for line in file:
        pr=line.split('\t')
        if ID==pr[0]:
            flag =True
            price=input('Enter the new price of the product: ')
            line =pr[0]+'\t'+pr[1]+'\t'+price+'\t'+str(EmployeeID)+'\n'
        tempfile.write(line)
    file.close()
    tempfile.close()
    os.remove('Product.txt')
    os.rename('TempProduct.txt','Product.txt')
    if flag:
       print("The price of product is sucessfully updated")
       print("The employee_ID is sucessfully updated\n")
    else :
        print("No price_id matched to update!")
 
 
 
 
        
 
#*******************************************************************************#*******************************************************************************#
 
 
 
 
 
def countCustomer(Phone):
    with open('Customer.txt','r') as file :
        counter=0
        Phone+='\n'  # as cc[1] contain phone+'\n'
        for line in file:
            cc=line.split('\t')
            if Phone==cc[1]:
                counter+=1
    return counter
 
 
 
 
 
#*******************************************************************************#*******************************************************************************#
 
 
 
 
def validLogIn( ID  , name ):
    with open('Employee.txt', 'r') as file:
        for line in file:
            temp=line.strip()
            l=temp.split('\t')
            if l[0]==ID and l[1]==name :
               return True;
        
        return False;
 
 
 
 
 
#*******************************************************************************#*******************************************************************************#
 
 
 
 
 
def validPhone( phone ):
    valid=False;
    for i in phone :
        if i>='0' and  i<='9':
            continue
        else :
            return False
        
    return True
 
 
#*******************************************************************************#*******************************************************************************#
 
 
 
 
 
def menuEmpolyee(Id , Name) :
    ch='Y'
    while ch=='Y' or ch=='y' :
        print('1) Add new Employees.')
        print('2) Know all Employees.')
        print('3) Know all products.')
        print('4) Search about product by name.')
        print('5) Delete product by it\'s id.')
        
        # op 6 and 7 need update autometically in field edited by
        print('6) Update at price of product by it\'s id.')
        print('7) Add new product.')
        print('\n\"press any key to exit\"')
        op=int(input('\n\nEnter your choice : \n'))
 
        
        if  op== 1 :
            writeEmployee()
        elif op==2 :
            readEmployee()
        elif op==3 :
            readProduct()
        elif op==4 :
            searchProduct()
        elif op==5 :
            deleteProduct()
        elif op==6 :
            updateprice(Id)
        elif op==7 :
            writeProduct(Id)
        else :
            return
 
        ch=input('\nIf you want to continue press [ Y / N ] : ')
 
        
        
 
 
#*******************************************************************************#*******************************************************************************#
 
        
 
 
 
def  menuCustomer(Name , Phone):
     ch='Y' ; totalPrice =0;
     count_visited = countCustomer(Phone)
     with open("Sales.txt" ,'w' ) as sale:
          while ch=='Y' or ch=='y' :
              
               print('\n1) Know all products to buy from them.')
               print('2) Search about product by name.')
               print('\nNote : ')
               print(' *if you want to buy any product please call \'Know all products\'.')
               print(' *if you want to exit press any key.')
               opt= int(input('\n\nEnter your choice : \t\n'))
 
               
               if opt== 1:
                   readProduct2()
                   wantedID=input('\nEnter id of the needed product : ')
                   quantity=input('Enter the quantity you need of the product : ')
                   with open("Product.txt" ,'r' ) as file :
                        for line in file :
                            l = line.split('\t')
                            if wantedID== l[0] :
                                sale.write(l[0] +'\t' + l[1] + '\t' + l[2] + '\t' +quantity +'\n')
                                totalPrice+=int(l[2])*int(quantity)
                                break
 
           
               elif opt == 2 :
                    searchProduct()
    
               else :
                    break
               ch= input('\nIf you want to continue press [ Y / N ] : ')
 
 
 
          # the customer buy products
     if totalPrice!=0 :
         print('\n\n**********************************************  Receipt  **********************************************\n')
         print('Id\tName\tPrice\tQuantity')
         with open("Sales.txt" ,'r' ) as sale:
                 for line in sale :
                     l = line.split('\t')
                     print(l[0] +'\t' + l[1] + '\t' + l[2] + '\t' +l[3] , end='' )
 
             
         print('\n\nTotal price : ' , totalPrice ,' pounds ')
         if(count_visited > 1) :
             print('Number of visited our system : ', count_visited ,' times')
             print('Discount : ' , (totalPrice * 5 //100 ) ,' pounds ' )
             print('Total price after discount  : ', totalPrice - (totalPrice * 5 //100 ) ,' pounds ')
 
 
     print('\n\n***********************************   thanks for using our system   ***********************************')
 
 
 
 
       
#*******************************************************************************#*******************************************************************************#
 
     
 
     
def Main():
 
    passWord='File'
    
    op1 = int(input('1) Employee.\n2) Customer.\nEnter Your choice : '))
    
    if op1 == 1 : # Employee
        newPass=input('Enter the password for employees : ') 
        cnt=1
        
        while  newPass != passWord and  cnt < 3  :
            newPass=input('Invalid password!\nplease try again : ')
            cnt+=1
            
        if newPass !=passWord :
          return
        
        print('\n*************  Welcome  *************\n')
        
        Id=input('Enter your id : ')
        Name=input('Enter your  name : ')
 
 
        # validate of id , name
        while not validLogIn(Id , Name):
                print('Invalid log in! , please try again')
                Id=input('Enter your id : ')
                Name=input('Enter your  name : ')   
                
            
            
        print('\n******* logged in Successfully *******\n')
        
        menuEmpolyee(Id , Name)
 
 
        
    elif op1==2 : # Customer
        
       with open('Customer.txt','a') as File :
           
        Name=input('Enter your  name : ')
        Phone=input('Enter your phone number : ')
        
        while not validPhone(Phone) :
            print('Invalid Phone! , please try again')
            Phone=input('Enter your phone number : ')
            
        File.write(Name+'\t'+Phone+'\n')
        
        menuCustomer(Name , Phone)
 
 
 
        
    else :
        return 
 
 
Main()
