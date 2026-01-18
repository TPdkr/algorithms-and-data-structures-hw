'''
CH-231-A
a3_p2.cpp
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
csc=[]
sample=int(data[0])#number of samples
data=data[1:]#get rid of first line
numb=len(data)
for line in data:#here we extract the actual data
    #first we transform the line into array of floats
    row =np.array([float(el) for el in line.split()])
    #then we split it and count the averages
    csa.append(np.average(row[:sample]))
    csb.append(np.average(row[sample:2*sample]))
    csc.append(np.average(row[2*sample:3*sample]))
    av.append(np.average(row[3*sample:]))
#turn intp numpy arrays
avg=np.array(av)
caseA=np.array(csa)
caseB=np.array(csb)
caseC=np.array(csc)
n=np.linspace(1,numb,numb)#arguement
#Here we plot the acual grpah
plt.title("Sorting time-Selection sort")
plt.plot(n,avg, color="blue",label="average time")
plt.plot(n,caseA, color="red",label="case A")
plt.plot(n,caseB, color="green",label="case B")
plt.plot(n,caseC, color="purple",label="case C")
plt.xlabel("number of elements")
plt.ylabel("time in seconds")
plt.grid()
plt.legend()
plt.savefig("graph.png")#save the file
file.close()#close the file