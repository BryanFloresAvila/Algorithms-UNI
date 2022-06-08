#include<iostream>
#include<string>
#include <ctime>
#include <cstdlib>
using namespace std;
class Nodo
{
	private:
        int dato;      // Dato del nodo
        Nodo *enlace; // Direccion a otro Nodo,
	public:
        Nodo(int d)
        {
            dato=d; //Asigna el dato=d a este Nodo
            enlace=NULL; //Este nodo apunta a NULL
        }
        Nodo(int d,Nodo *n)
        {
            dato=d;
            enlace=n;
        }
        int getDato() //Devuelve el dato
        {
            return dato;
        }
        void setDato(int nuevoDato) //Fija un nuevo dato
        {
            dato=nuevoDato;
        }
        Nodo *getEnlace() //Devuelve la dirección a donde apunta
        {
            return enlace;
        }
        void setEnlace(Nodo *sgte) //Fija un nuevo enlace
        {
            enlace=sgte;
        }
};
class Producto : public Nodo
{
    private:
        int day;
        int month;
        int year;
    public:
        Producto(int day,int month,int year, int dato):Nodo(dato){
            this->day = day;
            this->month = month;
            this->year = year;
        }
        void setDay(int day){
            this->day = day;
        }
        void setMonth(int month){
            this->month = month;
        }
        void setYear(int year){
            this->year = year;
        }
        int getDay()
        {
            return day;
        }
        int getMonth()
        {
            return month;
        }
        int getYear()
        {
            return year;
        }
        string getFecha(){
            string fecha, dia, mes, anio;
            dia = to_string(this->day);
            mes = to_string(this->month);
            anio = to_string(this->year);
            if (dia.length() == 1)
                dia = "0" + dia;
            if (mes.length() == 1)
                mes = "0" + mes;
            fecha = dia + "/" + mes + "/" + anio;
            return fecha;
        }
        int fechaToInt(){
            string fecha, dia, mes, anio;
            dia = to_string(this->day);
            mes = to_string(this->month);
            anio = to_string(this->year);
            if (dia.length() == 1)
                dia = "0" + dia;
            if (mes.length() == 1)
                mes = "0" + mes;
            fecha = anio + mes + dia;
            return stoi(fecha);
        }

};
class ListaProducto{
    private:
        Producto* first;
    public:
        ListaProducto(){
            first = NULL;
        }
        void crearLista(int longitud){
            int peso,day,month,year;
            srand(time(NULL));
            for(int i=0; i<longitud; i++){
                peso =rand() % 11 + 10;
                month = rand() % 3 + 1;
                year = rand() % 6 + 2015;
                if(month==2){
                    if(year%4==0) day = rand() % 29 + 1;
                    else day = rand() % 28 + 1;
                }
                else day = rand() % 31 + 1;
                insertar(day,month,year,peso);
            }
            
        }
        void visualizarLista(){
            Producto *indice;
            /* cout<<"Dir. Producto\tPeso\tDay\tMonth\tYear\tAdonde apunta" << endl;
            for (indice = first; indice != NULL; indice = (Producto *)indice->getEnlace())
                cout << indice << "\t" << indice->getDato() << "\t" << indice->getDay() << "\t" << indice->getMonth() << "\t" << indice->getYear() << "\t" << indice->getEnlace() << endl;
            */
            cout<<"Dir. Producto\tPeso\tFecha\t\tAdonde apunta" << endl;
            for (indice = first; indice != NULL; indice = (Producto *)indice->getEnlace())
                cout << indice << "\t" << indice->getDato() << "\t" << indice->getFecha() << "\t" << indice->getEnlace() << endl;
        }
        void ordenarLista(int longitud){
            Producto *indicej, *indicejNext;
            int fechaj, fechajNext;
            int tempPeso, tempDay, tempMonth, tempYear;
            for (int i = 0; i < longitud - 1; i++)
            {
                indicej = first;
                for (int j = 0; j < longitud - 1 - i; j++)
                {
                    fechaj = indicej->fechaToInt();
                    indicejNext = (Producto *)indicej->getEnlace();
                    fechajNext = indicejNext->fechaToInt();
                    if (fechaj > fechajNext)
                    {

                        tempPeso = indicej->getDato();
                        tempDay = indicej->getDay();
                        tempMonth = indicej->getMonth();
                        tempYear = indicej->getYear();

                        indicej->setDato(indicejNext->getDato());
                        indicej->setDay(indicejNext->getDay());
                        indicej->setMonth(indicejNext->getMonth());
                        indicej->setYear(indicejNext->getYear());

                        indicejNext->setDato(tempPeso);
                        indicejNext->setDay(tempDay);
                        indicejNext->setMonth(tempMonth);
                        indicejNext->setYear(tempYear);
                    }
                    indicej = (Producto *)indicej->getEnlace();
                }
            }
        }
        void insertar(int day,int month, int year, int dato){
            string nombre;
            Producto* nuevo = new Producto(day,month,year,dato);
            if(first == NULL){
                first = nuevo;
            }else{
                nuevo->setEnlace(first);
                first = nuevo;
            }
        }
};
int main(){
    int opcion;
    int longitud;
    ListaProducto miLista;
    while (true)
    {
        cout << "1. Crear Lista\n";
        cout << "2. Visualizar Lista\n";
        cout << "3. Ordenar Lista\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        if (opcion == 4)
            break;
        else if (opcion == 1)
        {
            cout << "Ingrese la longitud de la lista: ";
            cin >> longitud;
            miLista.crearLista(longitud);
        }
        else if (opcion == 2)
            miLista.visualizarLista();
        else if (opcion == 3)
            miLista.ordenarLista(longitud);
        else
            cout << "Esta opcion no existe\n";
    }
}