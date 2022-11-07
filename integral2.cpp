// Programa para calculo da aproximação da área da integral

#include <iostream>
#include <locale>
#include <math.h> //utilizada para a funcao matemáticas
#include <cstdlib> //utilizada para a funcao system(), com o comando "clear" quando for linux ou "cls" quando for windows
#include <stdio.h>//utilizada para a funcao getchar(), pausa a execucao do programa

 using namespace std;

// função da integral da primeira opcao
double func1(double x){

    return (pow(x-1,10));

}
//funcao integral da segunda opcao
double func2(double x){
		return (sqrt(x+1));
}

double func3(double x){
	double y;
	y = pow(x, 2) + 1;
	return ((2*x) * pow(y,3));
}
double func4(double x){
		return (((2*x)+1)* (pow(x, 2)+x));
}
// calculo do delta x
 double deltax (double aa,double bb, double nn){

    return (bb - aa) / nn;

 }
//funcao para calcular a integral com a regra do ponto medio
 double integral(int n, double aa, double bb, int opc){
	double xi[n];
    // Intervalos
    double a = aa;
    double b = bb;
    double sfunc=0;
    double dx = deltax(a, b, n);
    for(int i=1 ; i <= n;i++){
			xi[0] = a;
			xi[i] = xi[i-1] + dx;
			//cout << xi[i];
	}

	for(int i=1 ; i <= n;i++){
		//escolhe de acordo com a opcao enviada
		if (opc == 1)
			sfunc += func1((xi[i-1]+xi[i])/2);
		else if (opc == 2)
			sfunc += func2((xi[i-1]+xi[i])/2);
		else if (opc == 3)
			sfunc += func3((xi[i-1]+xi[i])/2);
		else if (opc == 4)
			sfunc += func4((xi[i-1]+xi[i])/2);
		else
			cout << "opcao invalida";
	}
	//calcula a integral multiplicando o delta e o somatorio da funcao
	double integralx = dx * sfunc;


	return integralx;
}
 //funcao com uma tela do resultado do calculo da integral
 void menu(int a, int b, int opc){
	 //vetor para calcular os retangulos
	 int quantidadeRetangulos[] = {5,10,50,100,500,10000};

	double n = 0;
	cout<<"============================================================"<<endl;
	cout<<"|	n	|                             |  Integral  |"<<endl;
	cout<<"============================================================"<<endl;
	for(int i=0;i<6; i++){
		n = quantidadeRetangulos[i];
		cout<<"|	"<<n<<"	|                             | "<<integral(n, a, b, opc)<<endl;}
		getchar();
}
 //funcao principal
int main(){
	char limpar[] = "clear"; //utilize a palavra "clear" para Linux e "cls" se for Windows
	int opc;
	setlocale(LC_ALL, "Portuguese");
	//enquanto o usuario nao digitar 5 pra sair, a tela entra em loop..
	while (opc != 5){
	cout << "QUAL A FUNCAO A REALIZAR O CALCULO DA INTEGRAL?\n\n";
	cout << "1 - f(x) = (x - 1)^10 \t\t\t(intervalo a = 0 e b = 1)\n2 - f(x) = sqrt(x+1) \t\t\t(intervalo a = 1 e b = 3)\n3 - f(x) = 2x * (x^2 + 1)^3\t\t(intervalo a = 1 e b = 5)";
	cout << "\n4 - f(x) = (2x+1) * (x^2 + x)\t\t(intervalo a = 1 e b = 5)";
	cout << "\n5 - SAIR";
	cout << "\nDigite a Opcao: ";
	cin >> opc;
	//executa as opcoes de acordo com a escolha do usuario
	switch (opc){
			case 1:
				//intervalo (0 a 1)
				menu(0, 1, 1);
				getchar();
				//system("cls");
				system(limpar);
				break;
			case 2:
				//intervalo (1 a 3)
				menu(1, 3, 2);
				getchar();
				//system("cls");
				system(limpar);
				break;
			case 3:
				//intervalo (1 a 5)
				menu(1, 5, 3);
				getchar();
				//system("cls");
				system(limpar);
				break;
			case 4:
				//intervalo (1 a 5)
				menu(1, 5, 4);
				getchar();
				//system("cls");
				system(limpar);
				break;
			case 5:
				break;
			default:
				system(limpar);
				cout << "Opcao Invalida\n";
				break;
		}
	}
    return 0;
}
