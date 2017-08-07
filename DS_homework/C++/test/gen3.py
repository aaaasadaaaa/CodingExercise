import random
month = ["Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"]
N_day = [31,28,31,30,31,30,31,31,30,31,30,31]
L_day = [31,29,31,30,31,30,31,31,30,31,30,31]

def isGLeapYear(y):
  if (y%4000 == 0) :return False
  if ((y%400 == 0) and (y%4000 != 0)) : return True
  if ((y%100 == 0) and (y%400 != 0)) :return False
  if (y%4 == 0 and y%100 != 0) :return True
  if y%4 != 0 :return False

m = int(random.randint(1,12))
y = int(random.randint(1,9999))

if isGLeapYear(y) :
    d = int(random.randint(1,L_day[m-1]))
else :
    d = int(random.randint(1,N_day[m-1]))


print(month[m-1]+" "+str(d)+", "+str(y))
