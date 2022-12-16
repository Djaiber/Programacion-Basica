#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <windows.h>

#define NUMUSERS 11
using namespace std;

struct database{
    char numerotarjeta[10];
    char pin[4];
    char saldo[6];
    char comprobantetarjeta[10];
    char comprobantepin[4];
};

int main() {
	//inicializacion de variables 
	int rd,opcion=0,opcion2=0,opcion3=0,opcionAdm=0,a=0,b,c=0,numero,deposito=0,total,retiro,dec=0,deci=0;	
	struct database datauser[NUMUSERS][3];
	char saldoActual[6];
	char auxNewarr[NUMUSERS];
	char auxPin[4];
	/*Definicion de variables: 
	opcion:Es la variable encargada de entrar o salir de los ciclos de comprobacion del numero de la tarjeta,del pin y de repetir el ciclo que mantiene el portal de transacciones abierto. 
	opcion2:Es la variable encargada de salir del ciclo de comprobacion del pin.  */
	//Creacion de archivo y registro por default de datos
	
	ofstream dataBase;
	dataBase.open("dataUser.txt",ios::out);
	
	cout<<"Desea Reiniciar el database y poner los datos por defecto\n(Esta opcion no tiene vuelta atras)\n1.Para si\t2.Para no"<<endl;
	cin>>rd;
	if(rd=1){
		char saldod[]={"000000"};
		char pind[]={"3657"};
		char pind1[]={"4785"};
		char pind2[]={"5681"};
		char pind3[]={"5124"};
		char pind4[]={"9432"};
		char pind5[]={"7581"};
		char pind6[]={"2274"};
		char pind7[]={"6182"};
		char pind8[]={"4357"};
		char pind9[]={"3175"};
		char pindAdmin[]={"1111"};
		char newarr0[]={"0000000000"};
		char newarr1[]={"1111111111"};
		char newarr2[]={"2222222222"};
		char newarr3[]={"3333333333"};
		char newarr4[]={"4444444444"};
		char newarr5[]={"5555555555"};
		char newarr6[]={"6666666666"};
		char newarr7[]={"7777777777"};
		char newarr8[]={"8888888888"};
		char newarr9[]={"9999999999"};
		char admin[]={"ADMIN"};
		//asignacion numero de tarjeta
		copy(newarr0,newarr0+11,datauser[0][0].numerotarjeta);
		copy(newarr1,newarr1+11,datauser[1][0].numerotarjeta);
		copy(newarr2,newarr2+11,datauser[2][0].numerotarjeta);
		copy(newarr3,newarr3+11,datauser[3][0].numerotarjeta);
		copy(newarr4,newarr4+11,datauser[4][0].numerotarjeta);
		copy(newarr5,newarr5+11,datauser[5][0].numerotarjeta);
		copy(newarr6,newarr6+11,datauser[6][0].numerotarjeta);
		copy(newarr7,newarr7+11,datauser[7][0].numerotarjeta);
		copy(newarr8,newarr8+11,datauser[8][0].numerotarjeta);
		copy(newarr9,newarr9+11,datauser[9][0].numerotarjeta);
		copy(admin,admin+11,datauser[10][0].numerotarjeta);
		//Asignacion de pin
		copy(pind,pind+5,datauser[0][1].pin);
		copy(pind1,pind1+5,datauser[1][1].pin);
		copy(pind2,pind2+5,datauser[2][1].pin);
		copy(pind3,pind3+5,datauser[3][1].pin);
		copy(pind4,pind4+5,datauser[4][1].pin);
		copy(pind5,pind5+5,datauser[5][1].pin);
		copy(pind6,pind6+5,datauser[6][1].pin);
		copy(pind7,pind7+5,datauser[7][1].pin);
		copy(pind8,pind8+5,datauser[8][1].pin);
		copy(pind9,pind9+5,datauser[9][1].pin);
		copy(pindAdmin,pindAdmin+5,datauser[10][1].pin);
		//asignacion saldo	
		for(int i=0; i<NUMUSERS; i++){ copy(saldod,saldod+7,datauser[i][2].saldo);}
	}
	
	if (dataBase.is_open()){
		for (int i=0;i<NUMUSERS;i++){
			dataBase<<datauser[i][0].numerotarjeta<<" "<<datauser[i][1].pin<<" "<<datauser[i][2].saldo<<endl;
		}
	}
	if (dataBase.fail()){
		cout<<"no se pudo crear el archivo";
		exit(1);
	} 
	dataBase.close();
	
	//Inicio Portal transacciones u/o interfaz usuario.
	do{ 															//ciclo para mantener el portal de transacciones abierto.
		opcion=0,opcion2=0,opcion3=0,opcionAdm=0,a=0,b,c=0,dec=0,deci=0;	//volvemos a asignar los valores por defecto de las variables manipuladas.
		system("cls");											//Limpiamos la salida por conosola.
		cout<<"Bienvenido a DistriPlata su banco de confianza\n\n"; //mensaje al ususario.
		//Comprobamos el numero de cuenta
		cout<<"ingrese su numero de tarjeta: "; //mensaje al ususario.
		cin>>datauser[0][3].comprobantetarjeta; //lectura del dato que ingresa en el usuario, este dato es almacenado en el struct database. 
			for(int i=0; i<NUMUSERS; i++){      //ciclo for para cotejar que el numero ingresado por el usuario se encuentre en el archivo y pueda ingresar.
				if(strcmp(datauser[i][0].numerotarjeta,datauser[0][3].comprobantetarjeta)==0){ //ciclo if que con un strcmp(perite comparar el contenido de las cadenas y regresa un 0 si son iguales) coteja que lso datos sean iguales para dar aceso
					opcion=1;
					b=i;

				}
			}
		while(opcion==0){ 	//ciclo que da tres intentos mas al usuario en caso de que el dato ingresado sea incorrecto
				a=a+1; 		//contador para garantizar que solo se les de 3 intentos mas
				if(a<4){	//ciclo if para garantizar los tres intentos
					cout<<"EL numero de tarjeta ingresado es incorrecto.\nPorfavor vuelva a ingresar su numero de tarjeta: ";
					cin>>datauser[0][3].comprobantetarjeta;
					for(int i=0; i<NUMUSERS; i++){
						if(strcmp(datauser[i][0].numerotarjeta,datauser[0][3].comprobantetarjeta)==0){
							opcion=1;
							b=i;
						}
					}	
				}else{
					cout<<"No tiene mas intentos, intente mas tarde\n\n";
					a=0;
					opcion=25;
					Sleep(3000);
					system("cls");
				}
			}
			
		if(opcion==1){
			cout<<"ingrese su PIN: ";
			cin>>datauser[0][4].comprobantepin;
			for(int i=0; i<NUMUSERS; i++){
				if(strcmp(datauser[b][1].pin,datauser[0][4].comprobantepin)==0){
					if(strcmp(datauser[10][1].pin,datauser[0][4].comprobantepin)==0){
						opcion2=77;
					}else{
						opcion2=1;	
					}
				}
			}	
			while(opcion2==0){
				a=a+1;
				if(a<4){
					cout<<"EL PIN ingresado es incorrecto.\nPorfavor vuelva a ingresar su PIN: ";
					cin>>datauser[0][4].comprobantepin;
					for(int i=0; i<NUMUSERS; i++){
						if(strcmp(datauser[b][1].pin,datauser[0][4].comprobantepin)==0){
							if(strcmp(datauser[10][1].numerotarjeta,datauser[0][3].comprobantetarjeta)==0){
								opcion2=77;
							}else{
								opcion2=1;	
							}
						}
					}
				}else{
					cout<<"No tiene mas intentos, intente mas tarde\n\n";
					a=0;
					opcion=25;
					Sleep(3000);
					system("cls");
				}
			}
		}
		//Menu solo para el administrador
		if(opcion2==77){
			cout<<"Que desea hacer:\n1.Modificar numero de tarjeta\n2.Cerrar programa\n3.Reiniciar"<<endl;
			cin>>opcionAdm;
			switch(opcionAdm){
				case 1:
					//funcion modificar
				break;
				
				case 2:
					cout<<"Cerrando el programa...\n";
					Sleep(1000);
					exit(1);
				break;
				
				case 3:
					opcion=25;
					opcion2=0;
					opcion3=0;
				break;
		
				
				default:
					opcion2=77;
				break;
			}
		}
		
		//Menu solo para el Usuario
		do{
			c=c+1;
			if(opcion2==1){
				system("cls");
				cout<<"Que desea hacer:\n1.Para consultar saldo.\n2.Para depositar.\n3.Para retirar."<<endl;
				cin>>opcion3;
			}
			//opciones 
			switch(opcion3){
				case 1:
					system("cls");
					cout<<"\tNumero de cuenta: "<<datauser[b][0].numerotarjeta<<"\n"<<endl;
					numero=atoi(datauser[b][2].saldo);
					cout<<"\t Saldo= "<<numero;	
					cout<<"\n\n1.Para realizar otra transaccion\t(cualquier otro numero para cerrar sesion y salir)"<<endl;
					cin>>dec;
					if(dec!=1){
						opcion=25;
					}else{
						opcion2=1;
					}
				break;
				
				case 2:
					system("cls");
					cout<<"\t\tDEPOSITAR:\nDigite el valor que desea depositar:\n\t$";
					cin>>deposito;
					while(deposito<0){
						cout<<"Lo sentimos solo puede depositar valores superiores a 0 y menores a 10000"<<endl;;
						cout<<"Porfavor vuelva a Digitar el valor que desea depositar"<<endl;
						cin>>deposito;
					}
					while(deposito>10000){
						cout<<"Lo sentimos solo puede depositar valores superiores a 0 y menores a 10000"<<endl;;
						cout<<"Porfavor vuelva a Digitar el valor que desea depositar"<<endl;
						cin>>deposito;
					}
					numero=atoi(datauser[b][2].saldo);
					total=numero+deposito;
					system("cls");
					cout<<"Transaccion en progreso...";
					Sleep(3000);
					system("cls");
					cout<<"Transaccion exitosa";
					Sleep(600);
					system("cls");
					cout<<"\n\tNumero de cuenta: "<<datauser[b][0].numerotarjeta<<"\n"<<endl;
					cout<<"\tSu saldo actual es $"<<total;
					itoa(total,saldoActual,10);
					copy(saldoActual,saldoActual+7,datauser[b][2].saldo);
					//ingreso al archivo del saldo
					dataBase.open("dataUser.txt",ios::out);
					dataBase<<datauser[b][2].saldo<<endl;
					dataBase.close();
					
					cout<<"\n\n1.Para realizar otra transaccion\t(cualquier otro numero para cerrar sesion y salir)"<<endl;
					cin>>dec;
					if(dec!=1){
						opcion=25;
					}else{
						opcion2=1;
					}
				break;
				
				case 3:
					system("cls");
					cout<<"\t\tRETIRAR:\nDigite el valor que desea retirar $";
					cin>>retiro;
					while(retiro<0){
						cout<<"Lo sentimos solo puede retirar valores superiores a 0 y menores a 1000"<<endl;;
						cout<<"Porfavor vuelva a Digitar el valor que desea retirar"<<endl;
						cin>>retiro;
					}
					while(retiro>1000){
						cout<<"Lo sentimos solo puede retirar valores superiores a 0 y menores a 1000"<<endl;;
						cout<<"Porfavor vuelva a Digitar el valor que desea retirar"<<endl;
						cin>>retiro;
					}
					numero=atoi(datauser[b][2].saldo);
					if(numero<0){
						cout<<"Fondos insuficientes"<<endl;
						cout<<"\t Su saldo es "<<numero;
						Sleep(3000);
						deci=1;
					}else{
						if(retiro<=numero){
							total=numero-retiro;
							system("cls");
							cout<<"Transaccion en progreso...";
							Sleep(3000);
							system("cls");
							cout<<"Transaccion exitosa";
							Sleep(600);
							system("cls");
							cout<<"\n\tNumero de cuenta: "<<datauser[b][0].numerotarjeta<<"\n"<<endl;
							cout<<"\tSu saldo actual es $"<<total;
							itoa(total,saldoActual,10);
							copy(saldoActual,saldoActual+7,datauser[b][2].saldo);
						
							cout<<"\n\n1.Para realizar otra transaccion\t(cualquier otro numero para cerrar sesion y salir)"<<endl;
							cin>>dec;
							if(dec!=1){
								opcion=25;
							}else{
								opcion2=1;
							}		
						}else{
							cout<<"no posee fondos suficientes"<<endl;
							cout<<"\t Su saldo es "<<numero;
							Sleep(3000);
							deci=1;
						}			
					}
				break;
				default:
					cout<<"Cerrando...";
					Sleep(1000);
					opcion=25;
				break;
			}	
			if(dec==1){
				if(c<3){
					deci=1;
				}else{
					cout<<"Lo sentimos no es posible realizar mas de 3 transacciones.\nSi desea realizar otra transaccion porfavor vuelva a iniciar sesion."<<endl;
					deci=0;
					opcion=25;	
					Sleep(4000);
					system("cls");
				}
			}
		}while(deci==1);
	}while(opcion==25);
}
/*void modificar(){
	ofstream aux;
	ifstream dataBase;
	bool encontrado=false;
	dataBase.open("dataUser.txt",ios::out|ios::in);
	if(dataBase.is_open()){
		
	}
	
}*/
