import numpy as np 
import matplotlib.pyplot as plt 
from sklearn import linear_model

X = []
y = []

inp = open("ex1data1.txt", 'r')
for i in inp.readlines():
    xtmp, ytmp = map(float, i.split(','))
    X.append(xtmp)
    y.append(ytmp)
inp.close()

XX = np.array(X).reshape(len(X), 1)
yy = np.array(y).reshape(len(y), 1)
one = np.ones((XX.shape[0], 1))

XXX = np.concatenate((one, XX), axis = 1)

model = linear_model.LinearRegression(fit_intercept = False)
model.fit(XXX, yy)

plt.xlabel("Population of City in 10,000s")
plt.ylabel("Profit in $10,000s")
plt.axis((4, 25, -5, 25))
plt.scatter(XX, yy, marker = 'x')

x0 = np.linspace(5, 24)
y0 = model.coef_[0][0] + model.coef_[0][1] * x0
plt.plot(x0, y0, 'g')

plt.show()