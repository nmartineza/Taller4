import numpy as np
import matplotlib.pyplot as plt

datos45=np.genfromtxt('angcuarentaycinco.dat',delimiter=',')
datosvar=np.genfromtxt('angvariados.dat',delimiter=',')


distx45=datos45[:,4]
disty45=datos45[:,6]

distxv=datosvar[:,4]
distyv=datosvar[:,6]

plt.figure()
plt.plot(distx45,disty45)
plt.savefig('45grados.pdf')


plt.figure()
plt.plot(distxv,distyv)
plt.savefig('variados.pdf')




