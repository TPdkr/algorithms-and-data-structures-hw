'''
CH-231-A
a4_p1.cpp
Timofei Podkorytov
tpodkoryto@jacobs-university.de
tpodkoryto@constructor.university
'''
import numpy as np
import matplotlib.pyplot as plt
 
file=open("out.txt")
data=file.readlines()#opening the file
av=[]
csa=[]
csb=[]
sample=int(data[0])#number of samples
size=int(data[1])
data=data[2:]#get rid of first line
numb=len(data)
for line in data:#here we extract the actual data
    #first we transform the line into array of floats
    row =np.array([float(el) for el in line.split()])
    #then we split it and count the averages
    csa.append(np.average(row[:sample]))
    csb.append(np.average(row[sample:2*sample]))
    av.append(np.average(row[2*sample:]))
#turn intp numpy arrays
avg=np.array(av)
caseA=np.array(csa)
caseB=np.array(csb)
n=np.linspace(1,numb,numb)#arguement
"""
#here i checked my theory about jumps being at 2^n
for i in range(510,520):
    print(i," ", avg[i]-avg[i-1])
"""
#Here we plot the acual grpah
title = "Sorting Merge-sort+Insertion sort of k of "+str(size)+" elements"
plt.title(title)
plt.plot(n,avg, color="blue",label="average time")
plt.plot(n,caseA, color="green",label="case A")
plt.plot(n,caseB, color="red",label="case B")
plt.xlabel("k")
plt.ylabel("time")
plt.grid()
plt.legend()
plt.savefig("graph.png")#save the file
file.close()#close the file