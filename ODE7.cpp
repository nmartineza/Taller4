#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

#define PI 3.14
double c=0.2;
double gravedad[2]; //Se declara la gravedad como un vector de dos posiciones//

double masa=2;



double ecuacion(double x,double desp_y1,double desp_y2,int i); //Ecuacion del movimiento//
double paso(double x,double desp_y1,double desp_y2,int i); //Paso que se dara//
void todo(double angulo);

int main()
{
double tetha=10;
todo(45); // Se aplica la funcion para el angulo de 45
for (int i=1;i<8;i++)
	{
		double r=tetha*i; //Este for crea angulos multiplos de 10, hasta 70//
		todo(r);
	}
  
return 0;
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
void todo(double angulo)
{
	double tiempo_max;
  double h;
  double vinicial;
  int iteraciones; 
  double tetha;
 
  
  tiempo_max=10;
  h=0.01;
  vinicial=300; 
  iteraciones=tiempo_max/h;
  tetha=10;
  
  
  
//Componentes de la gravedad//
  
  gravedad[0]=10; 
  gravedad[1]=0;

// Se definen los cursores para recorrer los arreglos// 
	
  double** distancia_x=new double* [iteraciones];
  double** velocidad=new double *[iteraciones];
  double tiempo[iteraciones];
  for (int i = 0; i < iteraciones; i++)
  {
  distancia_x[i]=new double[2];
  }
  for (int i = 0; i < iteraciones; i++)
  {
    velocidad[i]=new double[2];
  }
  for (int i = 0; i < iteraciones; i++) 
  {
    tiempo[i]=h*i;
  }
//Condiciones Iniciales para angulo de 45//
	


  velocidad[0][0]=vinicial*cos(angulo*PI/180);
  velocidad[0][1]=vinicial*sin(angulo*PI/180);
  distancia_x[0][0]=0;
  distancia_x[0][1]=0;

//Runge-Kutta

  ofstream datos;
  if(angulo==45)
  {
  	datos.open("angcuarentaycinco.dat");
  }
  else
  {
  	datos.open("angvariados.dat");
  }
  
  double k1,k2,k3,k4,l1,l2,l3,l4;
  double total=0;

  for (int i = 0; i < iteraciones-1; i++) 
  {
//Velocidad coordenada y y x.

   k1=h*ecuacion(tiempo[i],velocidad[i][0],velocidad[i][1],0);
   l1=h*ecuacion(tiempo[i],velocidad[i][0],velocidad[i][1],1);

   k2=h*ecuacion(tiempo[i]+h/2,velocidad[i][0]+k1/2,velocidad[i][1]+l1/2,0);
   l2=h*ecuacion(tiempo[i]+h/2,velocidad[i][0]+k1/2,velocidad[i][1]+l1/2,1);

   k3=h*ecuacion(tiempo[i]+h/2,velocidad[i][0]+k2/2,velocidad[i][1]+l2/2,0);
   l3=h*ecuacion(tiempo[i]+h/2,velocidad[i][0]+k2/2,velocidad[i][1]+l2/2,1);

   k4=h*ecuacion(tiempo[i]+h,velocidad[i][0]+l3, velocidad[i][1]+k3,0);
   l4=h*ecuacion(tiempo[i]+h,velocidad[i][0]+l3,velocidad[i][1]+k3,1);

   velocidad[i+1][0]=velocidad[i][0]+(k4+2*(k2+k3)+k1)/6;
   velocidad[i+1][1]=velocidad[i][1]+(l4+2*(l2+l3)+l1)/6;
  }
  for (int i = 0; i < iteraciones-1; i++) 
  {
//Posicion coordenada y y x.

   k1=h*paso(tiempo[i],distancia_x[i][0],distancia_x[i][1],0);
   l1=h*paso(tiempo[i],distancia_x[i][0],distancia_x[i][1],1);

   k2=h*paso(tiempo[i]+h/2,distancia_x[i][0]+k1/2,distancia_x[i][1]+l1/2,0);
   l2=h*paso(tiempo[i]+h/2,distancia_x[i][0]+k1/2,distancia_x[i][1]+l1/2,1);

   k3=h*paso(tiempo[i]+h/2,distancia_x[i][0]+k2/2,distancia_x[i][1]+l2/2,0);
   l3=h*paso(tiempo[i]+h/2,distancia_x[i][0]+k2/2,distancia_x[i][1]+l2/2,1);

   k4=h*paso(tiempo[i]+h,distancia_x[i][0]+l3,distancia_x[i][1]+k3,0);
   l4=h*paso(tiempo[i]+h,distancia_x[i][0]+l3,distancia_x[i][1]+k3,1);

   distancia_x[i+1][0]=distancia_x[i][0]+(k4+2*(k2+k3)+k1)/6;
   distancia_x[i+1][1]=distancia_x[i][1]+(l4+2*(l2+l3)+l1)/6;


	//Se agregan las variables al archivo//
   datos<<",tiempo,"<<tiempo[i]<<" ,distancia_X, "<<distancia_x[i][0]<<", distancia_y ,"<<distancia_x[i][1]<<",Velocidad_x, "<<velocidad[i][0]<<", Velocidad_y,  "<<velocidad[i][1]<<endl;
	total+=sqrt(pow(distancia_x[i][0],2)+pow(distancia_x[i][1],2));
  }
  datos.close();
  cout<<"La distancia total recorrida es de:"<<" "<<total;
}


