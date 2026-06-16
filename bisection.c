#include <stdio.h>
#include <math.h>
#define EPS 1e-5


double f(double x) {
  return log(x) - 1; // Example function: f(x) = ln(x) - 1
}
double mean(double a, double b){
  return 0.5 * (a+b);
}
double bisection(double a, double b){
  double root = EPS;
  double m    = mean(a,b);

  if(fabs(a-b) <=EPS){
    root = mean(a,b);
    return root;
  }

  if(f(a) * f(m) < 0){
    return bisection(a,m);
  }

  if(f(m) * f(b) < 0){
    return bisection (m,b);
  }

  return root;
}

double bisection_loop(double a, double b){
  double m = mean(a,b);


  while (fabs(a-b)>EPS){

    m = mean(a,b);
    if(f(a) * f(m) < 0) { b = m;}
    else                { a = m;}
  }
  

  return m;
}



void display_result(double slt){
  char *msg = "Solution :";
  printf("%s %g\n",msg, slt);
}

int main(){
  double  a = 2,
          b = 3;

  display_result(bisection(a,b));
  display_result(bisection_loop(a,b));

  return 0;
}