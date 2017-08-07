import sys
import math
def clean(x):
    y = ["\n","\r","\t"]
    for i in y:
        x = x.replace(i," ")
    m = x.split()
    for i in range(len(m)):
        if m[i] == "=" and m[i+1] != "(":
            m.insert(i+1,"(")
            m.insert(i+3,")")
    n = " ".join(m)
    return n
def cut(x):
    m = 0
    n = 0
    u = ""
    command = []
    for i in range(len(x)):
        u = u + x[i]
        if x[i] == "(" : m = m + 1
        if x[i] == ")" : n = n + 1
        if m == n and m != 0 and n != 0:
            command.append(u)
            m = 0 
            n = 0
            u = ""
    return command
def simp(x):

    y = []
    for i in x:
        m = i.split()
        for t in m:
            if t == "=" and len(m) == 6:
                i = i.replace("let","",1)
                i = i.replace("(","")
                i = i.replace(")","")
                y.append(i)
                n = 1
                break
            elif t == "=" and len(m) != 6:
                i = i.replace("let","",1)
                y.append(i)
                n = 1
                break
            else:
                n = 0
        if n == 0:
            y.append(i)
    return y
def line(w,x,y,z):
    print(w,x,"moveto")
    print(y,z,"lineto")
    print("stroke")
def rect(w,x,y,z):
    print(w,x,"moveto")
    print(w + y,x,"lineto")
    print(w + y,x + z,"lineto")
    print(w,x + z,"lineto")
    print(w,x,"lineto")
    print("stroke")
def filledrect(w,x,y,z):
    print(w,x,"moveto")
    print(w + y,x,"lineto")
    print(w + y,x + z,"lineto")
    print(w,x + z,"lineto")
    print(w,x,"lineto")
    print("fill")
def square(x,y,z):
    rect(x,y,z,z)
def filledsquare(x,y,z):
    filledrect(x,y,z,z)
def ngon(w,x,y,z):
    print(w + y,x,"moveto")
    for i in range(1,z+1):
        print(w + y * math.cos(2 * math.pi / z * i),x + y * math.sin(2 * math.pi / z * i),"lineto")
    print("stroke")
def filledngon(w,x,y,z):
    print(w + y,x,"moveto")
    for i in range(1,z+1):
        print(w + y * math.cos(2 * math.pi / z * i),x + y * math.sin(2 * math.pi / z * i),"lineto")
    print("fill")    
def tri(x,y,z):
    ngon(x,y,z,3)
def filledtri(x,y,z):
    filledngon(x,y,z,3)
def penta(x,y,z):
    ngon(x,y,z,5)
def filledpenta(x,y,z):
    filledngon(x,y,z,5)
def hexa(x,y,z):   
    ngon(x,y,z,6)
def filledhexa(x,y,z):   
    filledngon(x,y,z,6)
def sector(v,w,x,y,z):
    print(v,w,"moveto")
    print(v + x * math.cos(math.pi * y / 180),w + x * math.sin( math.pi * y / 180),"lineto")
    print(v,w,x,y,z,"arc")
    print(v,w,"lineto")
    print("stroke")
def filledsector(v,w,x,y,z):
    print(v,w,"moveto")
    print(v + x * math.cos(math.pi * y / 180),w + x * math.sin( math.pi * y / 180),"lineto")
    print(v,w,x,y,z,"arc")
    print(v,w,"lineto")
    print("fill")
def judge(x):
    n = 0
    for i in range(len(x)):
        if i != "=":
            n = 0
        else:
            n = 1
            break
    if n == 0 :
        return True
    else:
        return False
def pick(x):
    m = 0
    n = 0
    y = ""
    for i in range(len(x)):
        y = y + x[i]
        if x[i] == "(" : m = m + 1
        if x[i] == ")" : n = n + 1
        if m = n and m != 0 :
            return y
def judge_stop(x):
    if x == "line" or "rect" or "tri" or "square" or "penta" or "hexa" or "ngon" or "sector" or "filledrect" or "filledtri" or "filledsquare" or "filledpenta" or "filledhexa" or "filledngon" or "filledsector":
        return True
    else:
        return False
def stack(x):
    x_copy = ""
    z = []
    final = []
    for i in range(len(x)):
        x_copy = x_copy + x[i]
    for i in range(len(x)):
        y = y + x[i]
        if x[i] == "(":
            if judge_stop(y):
                final.append(x_copy)
                break
            else:
                z.append(y)
                x_copy = x_copy.replace(y,"")
                token = pick(x_copy)
                w = x_copy.replace(token,"")
                z.append(w)
                x_copy = x_copy.replace(w,"")
                final.append(z)
                z = []
    return final
info = sys.stdin.read()
command = cut(clean(info))
command = simp(command)
for i in command:
   if judge(i):


    
print(command)
