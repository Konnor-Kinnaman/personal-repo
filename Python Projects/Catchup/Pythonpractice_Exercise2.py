'''Exercise 2 (and Solution)
The exercise comes first (with a few extras if you want the extra challenge or want to spend more time), followed by a discussion. Enjoy!

Ask the user for a number. Depending on whether the number is even or odd, print out an appropriate message to the user. 
Hint: how does an even / odd number react differently when divided by 2?

Extras:

If the number is a multiple of 4, print out a different message.
Ask the user for two numbers: one number to check (call it num) and one number to divide by (check). 
If check divides evenly into num, tell that to the user. If not, print a different appropriate message.'''

#Program by Konnor Kinnaman

def main():
    while (1):
        UserNum = input("Enter a number: ")

        if(int(UserNum) == 0):
            return 1
        if (int(UserNum) % 2 == 0):
            print("Even")
        elif(int(UserNum)%2 != 0):
            print("Odd")

def ExtraOne():
    while (1):
        UserNum = input("Enter a number: ")

        if (int(UserNum)%4 == 0):
            print("4 Multiple")
        elif (int(UserNum)%2 == 0):
            print("Even")
        else:
            print("Odd")

def ExtraTwo():
    while(1):
        Num = input("Enter a number ")
        Check = input("Enter a check num ")

        if ((int(Num)%int(Check))==0):
            print('Success')
        else:
            print('Fail')
        



ExtraTwo()
exit(1)