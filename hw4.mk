


resultados_hw4.pdf : 45grados.pdf variados.pdf resultados_hw4.tex
	pdflatex resultados_hw4.tex

45grados.pdf variados.pdf : angcuarentaycinco.dat angvariados.dat Plots_hw4.py
	python Plots_hw4.py


angcuarentaycinco.dat angvariados.dat : ODE.cpp
	g++ ODE.cpp -o compilado.out
	./compilado.out
