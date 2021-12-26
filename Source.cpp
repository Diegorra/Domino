//Esta práctica ha sido realizada por Diego Ramón Sanchis- estudiante de Ing.Informática
//La practica consiste en la elaboración de un dominó
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <stdlib.h>
#include <array>
using namespace std;

//Tipos
const int NumFichas = 28;
const int FichasJugador = 7;
typedef short int tArray[NumFichas];

//Prototipos
int mostrarMenu(int& pos);
void mostrarTablero(string tablero, int numColocadas, int numRobadas, string fichasJug);
int aleat();
string toStr(int n);
string fichaToStr(int izquierda, int derecha);
bool puedePonerIzq(string tablero, short int fichaN1, short int fichaN2);
bool rotarIzq(string tablero, int ficha);
string ponerIzq(string tablero, short int fichaN1, short int fichaN2);
bool puedePonerDer(string tablero, short int fichaN1, short int fichaN2);
bool rotarDer(string tablero, int ficha);
string ponerDer(string tablero, short int fichaN1, short int fichaN2);
void guardarTablero(ofstream& archivo1, string tablero, string ficha, tArray fichas1, tArray fichas2, int numColocadas, int numRobadas);
//void cargarPartida(string tablero, short int fichaN1, short int fichaN2, int numColocadas, int numRobadas);
void desordenaPozo(tArray pozo1, tArray pozo2);
void generarPozo(tArray pozo1, tArray pozo2, int maxvalor);
void robaficha(tArray pozo1, tArray pozo2, short int& cont, short int& fichaN1, short int& fichaN2);
void eliminaficha(tArray fichas1, tArray fichas2, short int& fichasCont, short int fichaNum);
bool puedeColocarFicha(tArray fichas1, tArray fichas2, short int fichasCont, string tablero);
short int sumaPuntos(tArray fichas1, tArray fichas2, short int fichasCont);

int main()
{
	// Variables
	tArray fichas1, fichas2, pozo1, pozo2;
	short int fichaN1, fichaN2, izquierda, derecha, cont, fichasCont, maxvalor, x, y, robIzq, robDer;
	int i, numColocadas, numRobadas, fichaNum, z;
	string tablero, ficharob, ficha1, ficha;
	bool exit;
	ofstream archivo1;
	//Inicializamos variables
	srand(time(NULL));
	numColocadas = 0;
	numRobadas = 0;
	exit = false;
	cont = 28;
	maxvalor = 6;
	fichaN1 = 0;
	fichaN2 = 0;
	fichasCont = 0;
	//
	generarPozo(pozo1, pozo2, maxvalor);
	desordenaPozo(pozo1, pozo2);
	robaficha(pozo1, pozo2, cont, izquierda, derecha);
	tablero = fichaToStr(izquierda, derecha);
	for (i = 0; i < 7; i++)// generamos las fichas del jugador
	{
		robaficha(pozo1, pozo2, cont, x, y);
		fichas1[i] = x;
		fichas2[i] = y;
		ficha += fichaToStr(fichas1[i], fichas2[i]);
		fichasCont++;
	}
	//

	while (exit == false)
	{
		mostrarTablero(tablero, numColocadas, numRobadas, ficha);
		switch (mostrarMenu(fichaNum))
		{
		case 1:
			fichaN1 = fichas1[fichaNum];
			fichaN2 = fichas2[fichaNum];
			if (puedePonerIzq(tablero, fichaN1, fichaN2) == true)
			{
				if (rotarIzq(tablero, fichaN1) == true)
				{
					tablero = ponerIzq(tablero, fichaN2, fichaN1);
					numColocadas++;
					if ((fichasCont - 1) == fichaNum || fichasCont == fichaNum || fichaNum == 0) {
						if (fichaNum == 0) {
							ficha.erase(0, 5); //
							eliminaficha(fichas1, fichas2, fichasCont, fichaNum);
						}
						else {
							z = ficha.length() - 5;
							ficha.erase(z, 5); //
							eliminaficha(fichas1, fichas2, fichasCont, fichaNum);
						}
					}
					else{
						z = ficha.length() - (((fichasCont - 1) - fichaNum) * 5);
						ficha.erase((z - 4), 5); //
						eliminaficha(fichas1, fichas2, fichasCont, fichaNum);
					}
					
				}
				else
				{
					tablero = ponerIzq(tablero, fichaN1, fichaN2);
					numColocadas++;
					if ((fichasCont - 1) == fichaNum || fichasCont == fichaNum || fichaNum == 0) {
						if (fichaNum == 0) {
							ficha.erase(0, 5); //
							eliminaficha(fichas1, fichas2, fichasCont, fichaNum);
						}
						else {
							z = ficha.length() - 5;
							ficha.erase(z, 5); //
							eliminaficha(fichas1, fichas2, fichasCont, fichaNum);
						}
					}
					else{
						z = ficha.length() - (((fichasCont - 1) - fichaNum) * 5);
						ficha.erase((z - 4), 5); //
						eliminaficha(fichas1, fichas2, fichasCont, fichaNum);
					}

				}
			}
			else
			{
				cout << "ERROR" << endl;
				system("pause");
			}
			break;
		case 2:
			fichaN1 = fichas1[fichaNum];
			fichaN2 = fichas2[fichaNum];
			if (puedePonerDer(tablero, fichaN1, fichaN2) == true)
			{
				if (rotarDer(tablero, fichaN1) == true)
				{
					tablero = ponerDer(tablero, fichaN1, fichaN2);
					numColocadas++;
					if ((fichasCont - 1) == fichaNum || fichasCont == fichaNum || fichaNum == 0) {
						if (fichaNum == 0) {
							ficha.erase(0, 5); //
							eliminaficha(fichas1, fichas2, fichasCont, fichaNum);
						}
						else {
							z = ficha.length() - 5;
							ficha.erase(z, 5); //
							eliminaficha(fichas1, fichas2, fichasCont, fichaNum);
						}
					}
					else{
						z = ficha.length() - (((fichasCont - 1) - fichaNum) * 5);
						ficha.erase((z - 4), 5); //
						eliminaficha(fichas1, fichas2, fichasCont, fichaNum);
					}

				}
				else

				{
					tablero = ponerDer(tablero, fichaN2, fichaN1);
					numColocadas++;
					if ((fichasCont - 1) == fichaNum || fichasCont == fichaNum || fichaNum == 0){
						if (fichaNum == 0) {
							ficha.erase(0, 5); //
							eliminaficha(fichas1, fichas2, fichasCont, fichaNum);
						}
						else {
							z = ficha.length() - 5;
							ficha.erase(z, 5); //
							eliminaficha(fichas1, fichas2, fichasCont, fichaNum);
						}
					}
					else{
						z = ficha.length() - (((fichasCont - 1) - fichaNum) * 5);
						ficha.erase((z - 4), 5); //
						eliminaficha(fichas1, fichas2, fichasCont, fichaNum);
					}

				}
			}
			else
			{
				cout << "ERROR" << endl;
				system("pause");
			}
			break;
		case 3:
			if (puedeColocarFicha(fichas1, fichas2, fichasCont, tablero) == false) {
				robaficha(pozo1, pozo2, cont, robIzq, robDer);
				for(i = fichasCont; i > 0; i--) {// Añadimos la ficha robada a las fichas del jugador
					fichas1[i] = fichas1[i-1];
					fichas2[i] = fichas2[i-1];
				}
				fichas1[0] = robIzq;
				fichas2[0] = robDer;
				fichasCont++;
				ficha.insert(0,fichaToStr(robIzq, robDer));
				numRobadas++;
			}
			else {
				cout << "Puedes colocar ficha mira bien!" << endl;
				system("pause");
			}
			break;
			case 4:
				guardarTablero( archivo1, tablero, ficha, fichas1, fichas2, numColocadas, numRobadas);
				cout << "Su partida ha sido guardada con exito" << endl;
				break;
			/*case 5:
				cargarPartida(tablero, fichaN1, fichaN2, numColocadas, numRobadas);
				break;*/
		case 0:
			cout << "La puntuacion obtenida es : " << sumaPuntos(fichas1, fichas2, fichasCont) << endl;// mostramos puntuacion
			exit = true;
			system("pause");
			break;
		}
		fichaN1 = 0;
		fichaN2 = 0;
		system("CLS");
		if (fichasCont == 0) {// el jugador coloca todas sus fichas
			cout << "WINNER!!!!" << endl;
			exit = true;
			system("pause");
		}
		if (pozo1[0] > cont && pozo2[0] > cont && puedeColocarFicha(fichas1, fichas2, fichasCont, tablero) == false)
		{
			cout << "La puntuacion obtenida es : " << sumaPuntos(fichas1, fichas2, fichasCont) << endl;
			exit = true;
			system("pause");
		}
	}
	return 0;
}

int mostrarMenu(int& pos)
{
	//Menu
	int opcion;
	cout << " ----------------------" << endl;
	cout << " |  MENU DE OPCIONES  |" << endl;
	cout << " ----------------------" << endl;
	cout << "1. Poner ficha por la izquierda" << endl;
	cout << "2. Poner ficha por la derecha" << endl;
	cout << "3. Robar ficha nueva" << endl;
	cout << "4. Guardar la partida" << endl;
	cout << "5. Cargar partida" << endl;
	cout << "0. Salir" << endl;
	cout << "Elija una opcion : ";
	cin >> opcion;
	while (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5 && opcion != 0)
	{
		cout << "El numero introducido es incorrecto" << endl;
		cout << "Elija opcion : ";
		cin >> opcion;
	}
	if (opcion == 1 || opcion == 2) { // el usuario intruce el numero de la ficha que desea colocar tanto si es por la izq como por la der
		cout << "Que ficha desea colocar? (tenga en cuenta que el valor minimo es el 0) : " << endl;
		cin >> pos;
	}
	return opcion;
}

void mostrarTablero(string tablero, int numColocadas, int numRobadas, string fichasJug)
{ //Muestra el tablero
	short int fichasCont;
	cout << " --------------------" << endl;
	cout << " |     TABLERO      |" << endl;
	cout << " --------------------" << endl;
	cout << tablero << endl; //Variable donde almacenamos nuestras fichas
	cout << "Numero de fichas colocadas : " << numColocadas << " - ";
	cout << "Numero de fichas robadas : " << numRobadas << endl;
	cout << "Fichas del jugador : " << endl;
	cout << fichasJug << endl;
}

string fichaToStr(int izquierda, int derecha)
{ //Genera una ficha con dos numeros enteros
	string ficha, z1, z2;
	z1 = "|";
	z2 = "-";
	ficha = z1 + toStr(izquierda) + z2 + toStr(derecha) + z1;
	return ficha;
}

int aleat()
{ //Genera un numero aleatorio
	int aleat;
	aleat = 0 + rand() % (6 + 1 - 0);
	return aleat;
}

string toStr(int n)
{ //Convierte un numero aleatorio a string
	string tostr;
	char charn;
	charn = '0' + n;
	tostr = charn;
	return tostr;
}

bool puedePonerIzq(string tablero, short int fichaN1, short int fichaN2)
{ //Valora si coincide el extremo izquierdo del tablero con los extremos de la ficha
	int x;
	bool poder;
	poder = false;
	x = tablero[1] - '0';
	if (fichaN1 == x || fichaN2 == x)
	{
		poder = true;
	}
	return poder;
}
bool puedePonerDer(string tablero, short int fichaN1, short int fichaN2)
{ //Valora si coincide el extremo derecho del tablero con los extremos de la ficha
	int y;
	bool poder;
	poder = false;
	y = tablero[tablero.size() - 2] - '0';
	if (fichaN1 == y || fichaN2 == y)
	{
		poder = true;
	}
	return poder;
}

bool rotarIzq(string tablero, int ficha)
{ //Valora si debemos rotar la ficha
	int izquierda;
	bool rotar;
	rotar = false;
	izquierda = tablero[1] - '0';
	if (izquierda == ficha)
	{
		rotar = true;
	}
	return rotar;
}

bool rotarDer(string tablero, int ficha)
{ //Valora si debemos rotar la ficha
	int derecha;
	bool rotar;
	rotar = false;
	derecha = tablero[tablero.size() - 2] - '0';
	if (derecha == ficha)
	{
		rotar = true;
	}
	return rotar;
}

string ponerIzq(string tablero, short int fichaN1, short int fichaN2)
{ //Añade una ficha al tablero por la izquierda
	tablero = fichaToStr(fichaN1, fichaN2) + tablero;
	return tablero;
}

string ponerDer(string tablero, short int fichaN1, short int fichaN2)
{ //Añade una ficha por la derecha al tablero
	tablero = tablero + fichaToStr(fichaN1, fichaN2);
	return tablero;
}

void guardarTablero(ofstream &archivo1, string tablero, string ficha, tArray fichas1, tArray fichas2, int numColocadas, int numRobadas){
	char x;
	archivo1.open("partida1.txt");
	archivo1 << tablero;
	archivo1 << x;
	archivo1 << numColocadas;
	archivo1 << x;
	archivo1 << numRobadas;
	archivo1 << x;
	archivo1 << ficha;
	archivo1 << x;
	archivo1 << fichas1;
	archivo1 << x;
	archivo1 << fichas2;
	archivo1.close();
}

/*void cargarPartida(ifstream &archivo2, string tablero, string ficha, tArray fichas1, tArray fichas2, int numColocadas, int numRobadas){
	archivo2.open("partida1.txt");
	if (archivo2.is_open()){
		archivo2 >> tablero;
		 archivo2 >> numColocadas >> numRobadas;
		 archivo2.getline(archivo2, ficha);
	}
	else{
		cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
	}
}*/
void generarPozo(tArray pozo1, tArray pozo2, int maxvalor)
{// Generamos numeros aleatorios que almacenamos en nuestro array pozo
	int i;
	for (i = 0; i < 28; i++) {
		pozo1[i] = aleat();
		pozo2[i] = aleat();
	}
}

void desordenaPozo(tArray pozo1, tArray pozo2)
{//
	int idx, i;
	short int tmp1, tmp2;
	for (int i = NumFichas - 1; i >= 0; i--)
	{
		idx = rand() % (i + 1);
		if (i != idx)
		{
			tmp1 = pozo1[i];
			tmp2 = pozo2[i];
			pozo1[i] = pozo1[idx];
			pozo2[i] = pozo2[idx];
			pozo1[idx] = tmp1;
			pozo2[idx] = tmp2;
		}
	}
}
void robaficha(tArray pozo1, tArray pozo2, short int& cont, short int& fichaN1, short int& fichaN2)
{//Quitamos ultima ficha del pozo
	fichaN1 = pozo1[cont - 1];
	fichaN2 = pozo2[cont - 1];
	cont--;
}


void eliminaficha(tArray fichas1, tArray fichas2, short int& fichasCont, short int fichaNum)
{//Eliminamos una ficha segun la posicion que ocupa
	int i;
	for (i = fichaNum; i < fichasCont-1 ; i++) {
		fichas1[i] = fichas1[i + 1];
		fichas2[i] = fichas2[i + 1];
	}
	fichasCont--;
}


bool puedeColocarFicha(tArray fichas1, tArray fichas2, short int fichasCont, string tablero)
{//Comprobamos si es posible poner alguna de las fichas en el tablero
	short int x, y, i;
	bool puede;
	puede = false;
	x = tablero[1] - '0';
	y = tablero[tablero.size() - 2] - '0';
	for (i = 0; i < fichasCont-1; i++) {
		if (fichas1[i] == x || fichas1[i] == y || fichas2[i] == y || fichas2[i] == x)
		{
			puede = true;
		}
	}
	return puede;
}


short int sumaPuntos(tArray fichas1, tArray fichas2, short int fichasCont)
{// Suma puntos de las fichas iniciales - retantes del jugador
	int  valorFin, i;
	valorFin = 0;
	for (i = 0; i <= fichasCont - 1; i++) {
		valorFin = valorFin + fichas1[i] + fichas2[i];
	}
	return valorFin;
}

/*int valorIni, x, y, maxvalor;
	tArray pozo1, pozo2;
	x = 0;
	generarPozo(pozo1, pozo2, maxvalor);
	for(y=26; y>=19; y--){
		valorIni = valorIni + pozo1[y] + pozo2[y];
	}*/
	//x = valorIni - valorFin;