'''
CH-231-A
a6_p2.cpp
Timofei Podkorytov
tpodkoryto@jacobs-university.de
tpodkoryto@constructor.university
'''

'''
In this section we plot the data on a graph
'''
file=open("out.txt")
data=file.readlines()#opening the file
title = "Heap sort algorithm performance"
plt.title(title)
labels=["regular", "bottomup"]#labels for graphs and table
colors=["purple", "pink"]
i=0
#we plot the data on a graph
smooth=10#this is needed to get rid of the noise/smooth the data
for line in data:#here we extract the actual data
    row=[float(el) for el in line.split()]
    print(len(row))
    rowsmooth=[]
    for j in range(len(row)):#here i make the graph less noisy and more smooth
        if j<smooth:#corner cases when close to the ends of the list
            rowsmooth.append(sum(row[:j+smooth+1])/len(row[:j+smooth+1]))
        elif j>len(row)-smooth:
            rowsmooth.append(sum(row[j-smooth:])/len(row[j-smooth:]))
        else:#we basically avergae elementd around the index
            rowsmooth.append(sum(row[j-smooth:j+smooth+1])/len(row[j-smooth:j+smooth+1]))
    x=np.linspace(1,len(row)+1, len(row))#create an arguement
    #plt.plot(x,np.array(row), label=labels[i], color="red")-not smoothed
    plt.plot(x,np.array(rowsmooth), label=labels[i], color=colors[i])
    i+=1
#we add some detials to the graph
plt.xlabel("n")
plt.ylabel("time in seconds")
plt.grid()
plt.legend()
plt.savefig("graph.png")#save the file
file.close()#close the file


