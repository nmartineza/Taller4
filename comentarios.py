#!/usr/bin/env python
# coding: utf-8

# # Welcome to Jupyter!

# In[ ]:


import numpy as np
import matplotlib.pyplot as plt

datos45=np.genfromtxt('angcuarentaycinco.dat',delimiter=',')
datosvar=np.genfromtxt('angvariados.dat',delimiter=',')

### Aqui se hace lo mismo con los archivos que se deberían generar en el punto 3 ###
### punto3a=np.genfromtxt('resultado1.dat',delimiter=',') Condiciones iniciales
### punto3b=np.genfromtxt('resultado2.dat',delimiter=',') Estado intermedio del sistema
### punto3c=np.genfromtxt('resultado3.dat',delimiter=',') Estado intermedio del sistema
### punto3d=np.genfromtxt('resultado4.dat',delimiter=',') Configuracion de equilibrio


#plt.figure()
#plt.plot(punto3a[0],punto3a[1])
#plt.savefig('Condicionesiniciales.pdf')

#plt.figure()
#plt.plot(punto3b[0],punto3b[1])
#plt.savefig('Estadointermediodelsistema.pdf')

#plt.figure()
#plt.plot(punto3c[0],punto3c[1])
#plt.savefig('Estadointermediodelsistema2.pdf')

#plt.figure()
#plt.plot(punto3d[0],punto3d[1])
#plt.savefig('ConfiguracionEquilibrio.pdf')


distx45=datos45[:,4] #Distancia en x para angulos de 45
disty45=datos45[:,6] #Distancia en y para angulo de 45

distxv=datosvar[:,4] #Distancia en x para angulos variados
distyv=datosvar[:,6] #Distancia en y para angulos variads

#Grafica 1
plt.figure()
plt.plot(distx45,disty45)
plt.savefig('45grados.pdf')

#Grafica 2
plt.figure()
plt.plot(distxv,distyv)
plt.savefig('variados.pdf')


# This repo contains an introduction to [Jupyter](https://jupyter.org) and [IPython](https://ipython.org).
# 
# Outline of some basics:
# 
# * [Notebook Basics](../examples/Notebook/Notebook%20Basics.ipynb)
# * [IPython - beyond plain python](../examples/IPython%20Kernel/Beyond%20Plain%20Python.ipynb)
# * [Markdown Cells](../examples/Notebook/Working%20With%20Markdown%20Cells.ipynb)
# * [Rich Display System](../examples/IPython%20Kernel/Rich%20Output.ipynb)
# * [Custom Display logic](../examples/IPython%20Kernel/Custom%20Display%20Logic.ipynb)
# * [Running a Secure Public Notebook Server](../examples/Notebook/Running%20the%20Notebook%20Server.ipynb#Securing-the-notebook-server)
# * [How Jupyter works](../examples/Notebook/Multiple%20Languages%2C%20Frontends.ipynb) to run code in different languages.

# You can also get this tutorial and run it on your laptop:
# 
#     git clone https://github.com/ipython/ipython-in-depth
# 
# Install IPython and Jupyter:
# 
# with [conda](https://www.anaconda.com/download):
# 
#     conda install ipython jupyter
# 
# with pip:
# 
#     # first, always upgrade pip!
#     pip install --upgrade pip
#     pip install --upgrade ipython jupyter
# 
# Start the notebook in the tutorial directory:
# 
#     cd ipython-in-depth
#     jupyter notebook
