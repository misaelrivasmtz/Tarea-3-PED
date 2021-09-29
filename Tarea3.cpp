#include<iostream>
#include<string.h>

using namespace std;
//registro que almacena los datos de la orden
struct orden{
    int cant;
    string masa;
    string coke;
    string ingredientes;
};

struct nodo{
    orden datos;
    nodo *sig;
};

class Ordenes{
    private:
    nodo *pInicio;

    public:
    Ordenes();
    ~Ordenes();

    void insertar(orden);
    void insertarOrden();
    void mostrarOrdenes();
};

Ordenes::Ordenes(){
    pInicio = NULL;
}

Ordenes::~Ordenes(){
    nodo *p;
    while(pInicio){
        p = pInicio;
        pInicio = pInicio->sig;
        delete p;
    }
}

void Ordenes::insertar(orden info){
    nodo *nuevo;
    nuevo = new nodo;
    nuevo->datos = info;
    nuevo->sig = NULL;

    if(!pInicio){
        pInicio = nuevo;
    }
    else{
        nodo *aux = pInicio;
        while(aux->sig){
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void Ordenes::insertarOrden(){
    orden datos;
    char opc, opcCoke;
    int opcMasa;
    cout<<"\nAgregar orden (s/n): ";
    cin>>opc;
    while(opc!='n'){
        cout<<"_________________________________"<<endl;
        cout<<"Cantidad: ";
        cin>>datos.cant; cin.ignore();
        cout<<"Masa: "<<endl;
        cout<<"1. Maiz"<<endl;
        cout<<"2. Arroz"<<endl;
        cout<<"Opcion: "; 
        cin>>opcMasa; cin.ignore();
            if(opcMasa == 1)
                datos.masa = "Maiz";
            else if(opcMasa == 2)
                datos.masa = "Arroz";
        cout<<"Agregar cocacola (s/n): ";
        cin>>opcCoke; cin.ignore();
            if(opcCoke == 's')
                datos.coke = "Sí";
            else if(opcCoke == 'n')
                datos.coke = "No";
        cout<<"Ingredientes: ";
        getline(cin, datos.ingredientes);
        insertar(datos);
    cout<<"\nAgregar orden (s/n): ";
    cin>>opc;
    }
}

void Ordenes::mostrarOrdenes(){
    int i = 1;
    nodo *p;
    cout<<"Mostrando ordenes"<<endl;
    p = pInicio;
    while(p){
        cout<<"_________________________________"<<endl;
        cout<<"Orden #"<<i<<endl;
        cout<<"Cantidad: "<<p->datos.cant<<endl;
        cout<<"Masa: "<<p->datos.masa<<endl;
        cout<<"Cocacola: "<<p->datos.coke<<endl;
        cout<<"Ingredientes: "<<p->datos.ingredientes<<endl;
        p = p->sig;
        i++;
    }
}

int main(void){
    Ordenes ordenes;
    int opc;
    bool continuar = true;
    do{
        cout<<"\n\tPUPUSERIA UCA"<<endl;
        cout<<"1. Insertar orden"<<endl;
        cout<<"2. Mostrar ordenes"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"Opcion: ";
        cin>>opc;
        switch(opc){
            case 1:
            ordenes.insertarOrden();
            cin.clear();
            break;
            case 2:
            ordenes.mostrarOrdenes();
            cin.clear();
            break;
            case 0:
            continuar = false;
            break;
            default:
            cout<<"Opcion invalida"<<endl;
            break;
        }
    }while(continuar);
    return 0;
}