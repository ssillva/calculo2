// Programa para calculo da aproximação da área da integral

#include <iostream>
#include <locale>
#include <math.h>
#include <iomanip>

 using namespace std;

// função da integral
  double func1(double x){

    return 1 / x;//3 *( x * x);

 }
 double func2(double x){
		double valor = x * x * x;
		return sin(valor);
	 
}

// calculo do delta x
 double deltax (double aa,double bb, double nn){

    return (bb - aa) / nn;

 }

 double integral(int n){
	double xi[n];
    // Intervalos
    double a = 1.0;
    double b = 2.0;
    double sfunc=0;
    double dx = deltax(a, b, n);
    for(int i=1 ; i <= n;i++){
			xi[0] = a;
			xi[i] = xi[i-1] + dx;
			//cout << xi[i];
	}
	
	for(int i=1 ; i <= n;i++){
			sfunc += func1((xi[i-1]+xi[i])/2);
	}
	double integralx = dx * sfunc;
	
    
	return integralx;
}
 
int main(){
	setlocale(LC_ALL, "Portuguese");
	int quantidadeRetangulos[] = {5,10,50,100,500,10000};
	double n = 0;
	cout<<"============================================================"<<endl;
	cout<<"|	n	|                             |  Integral  |"<<endl;
	cout<<"============================================================"<<endl;
	for(int i=0;i<6; i++){
		n = quantidadeRetangulos[i];
	cout<<"|	"<<n<<"	|                             | "<<integral(n)<<endl;
}

    return 0;

 }
