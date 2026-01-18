'''
CH-231-A
a5_p1.cpp
Timofei Podkorytov
tpodkoryto@jacobs-university.de
tpodkoryto@constructor.university
'''
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
'''
In this section we plot the data on a graph
'''
file=open("out.txt")
data=file.readlines()#opening the file
numb=len(data)
title = "Creating a fiboanchi sequence of length n elements"
plt.title(title)
labels=["naive", "bottom up", "closed form","matrix"]#labels for graphs and table
colors=["red", "pink", "purple", "blue"]
i=0
rows=[]
#we plot the data on a graph
for line in data:#here we extract the actual data
    row=[float(el) for el in line.split()]
    rows.append(row)
    x=np.linspace(1,len(row)+1, len(row))#create an arguement
    plt.plot(x,np.array(row), label=labels[i], color=colors[i])
    i+=1
#we add some detials to the graph
plt.xlabel("n")
plt.ylabel("time")
plt.grid()
plt.legend()
plt.yscale('log')
plt.savefig("graph.png")#save the file
file.close()#close the file
'''
This section is needed to create the table and output it to csv
'''
labelstable=[]
i=0
for lab in labels:
    labelstable.append(lab+" "+str(len(rows[i])))
    i+=1

table=pd.DataFrame(columns=labelstable)#create a data frame
i=0
maxln=max([len(el) for el in rows])#maximum lemgth in order to fill the gaps
for el in labelstable:
    table[el]=rows[i]+[-1]*(maxln-len(rows[i]))#we fill the gaps
    i+=1
table.to_csv("table.csv", sep=',', index=False, encoding='utf-8')#save as a file

