import numpy as np 
import matplotlib.pyplot as plt
from sklearn import linear_model
# height (cm)
X = np.array([[147, 150, 153, 158, 163, 165, 168, 170, 173, 175, 178, 180, 183]]).T
# weight (kg)
y = np.array([[ 49,  50,  51,  54,  58,  59,  60,  62,  63,  64,  66,  67,  68]]).T

one = np.ones((X.shape[0], 1))
XBar = np.concatenate((one, X, np.square(X)), axis = 1)
model = linear_model.LinearRegression(fit_intercept=False)
model.fit(XBar, y)

x0 = np.linspace(145, 185, 40)
y0 = model.coef_[0][0] + model.coef_[0][1] * x0 + model.coef_[0][2] * x0 ** 2

print(model.coef_)

plt.plot(x0, y0, 'b-')
plt.plot(X, y, 'ro')
plt.axis([140, 190, 40, 80])
plt.xlabel("Height(cm)")
plt.ylabel("Weight(kg)")
plt.show()