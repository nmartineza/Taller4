#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

#define PI 3.14
double c=0.2;
double gravedad[2]; //Se declara la gravedad como un vector de dos posiciones//
double angulo=45;
double masa=2;

double ecuacion(double x,double desp_y1,double desp_y2,int i); //Ecuacion del movimiento//
double paso(double x,double desp_y1,double desp_y2,int i); //Paso que se dara//

int main()
{
	/*Constantes*/
  double tiempo_max;
  double h;
  double vinicial;
  int iteraciones; 
  
  tiempo_max=10;
  h=0.01;
  vinicial=300; 
  iteraciones=tiempo_max/h;
  
  //Componentes de la gravedad//
  
  gravedad[0]=10; 
  gravedad[1]=0;

  

}

double ecuacion(double x,double desp_y1,double desp_y2,int i )
{
  double movimiento;
  double dist_y;
  dist_y=sqrt(pow(desp_y1,2)+pow(desp_y2,2));
  
  if (i==0)
  {
    movimiento=-gravedad[i]-c*dist_y*desp_y1/masa;
  }
  else
  {
    movimiento=-gravedad[i]-c*dist_y*desp_y2/masa;
  }
  return movimiento;
}
double paso(double x,double desp_y1,double desp_y2,int i)
{
  if (i==0)
  {
    return desp_y1;
  }
  else
  {
    return desp_y2;
  } 

}
