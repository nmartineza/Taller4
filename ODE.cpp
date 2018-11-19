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


}
