#include <iostream>
#include <stdio.h>  
#include <string.h> 


using namespace std;
const char *nombe_archivo = "archivo.dat";
const char *nombe_archivo_temp = "archivo_temp.dat";

struct Empleado{
	int codigo;
	char nombres[50];
	char apellido[50];
	char puesto[50];
	int sueldo_base;
	int bonificacion;
	int sueldo_total;
};

void ingresar_empleado();
void abrir_empleado();
void modificar_empleado();
void eliminar_empleado();
void mostrar_empleado_temp();
void buscar_indice();
void buscar_codigo();

int main (){

int opc=0;
	system("cls");
cout <<"****** EXAMEN PARCIAL NUMERO 1 *******"<<endl<<endl;
cout <<"************* menu *******************"<<endl<<endl;
cout <<"Ingresar Empleado...................1"<<endl;
cout <<"Modificar Empleado..................2"<<endl;
cout <<"Eliminar Empleado...................3"<<endl;
cout <<"Mostrar Empleados ..................4"<<endl;
cout <<"Mostrar Un empleado espesifico......5"<<endl;
cout <<"Buscar Empleado por codigo..........6"<<endl<<endl;
cout<<"digite la opcion que desea realizar: ";
cin>>opc;

switch(opc)
{
	case 1: ingresar_empleado();
		break;
	case 2: modificar_empleado();
		break;
	case 3 : eliminar_empleado();
			mostrar_empleado_temp();
		break;
	case 4 : abrir_empleado();
			system("pause");
			main();
			break;	
	case 5 : buscar_indice();
	system("pause");
	main();
			break;
	case 6 : buscar_codigo();
	system("pause");
	main();
			break;				

}

	return 0;	
}
void buscar_codigo(){
	
	FILE* archivo = fopen(nombe_archivo, "rb");
	
	int indice=0,pos=0,cod=0;
	cout<<"BUSCAR CODIGO : ";
	cin>>cod;
	Empleado empleado;
	
	fread ( &empleado, sizeof(Empleado), 1, archivo );
		
		do{
			
			if (empleado.codigo == cod){
			pos = indice;
			}
	
		fread ( &empleado, sizeof(Empleado), 1, archivo );
		indice += 1;
		} while (feof( archivo ) == 0);
		
		system("cls");
	cout<<"------------------ "<<"ID = "<<pos<<" ------------------"<<endl;
	fseek ( archivo,pos * sizeof(Empleado), SEEK_SET );

    fread ( &empleado, sizeof( Empleado ), 1, archivo );

    	cout << "Codigo del empleado: " << empleado.codigo << endl;
        cout << "Nombre del empleado: " << empleado.nombres << endl;
        cout << "Apellido del empleado: " << empleado.apellido << endl;
        cout << "Puesto del empleado: " << empleado.puesto << endl;
        cout << "Sueldo base del empleado: " << empleado.sueldo_base << endl;
        cout << "Bonificacion del empleado: " << empleado.bonificacion<< endl;
        cout << "Sueldo total del empleado: " << empleado.sueldo_total << endl;
        cout << endl;
	
	fclose(archivo);
		system("pause");
	system("cls");
	main ();
}
void buscar_indice(){
	
	FILE* archivo = fopen(nombe_archivo, "rb");
	
	int pos=0;
	abrir_empleado();
	cout<<"Que registro desea ver: ";
	cin>>pos;
	system("cls");
	cout<<"------------------ "<<"ID = "<<pos<<" ------------------"<<endl;
	fseek ( archivo,pos * sizeof(Empleado), SEEK_SET );
	
	Empleado empleado;
	
    fread ( &empleado, sizeof( Empleado ), 1, archivo );


    	cout << "Codigo del empleado: " << empleado.codigo << endl;
        cout << "Nombre del empleado: " << empleado.nombres << endl;
        cout << "Apellido del empleado: " << empleado.apellido << endl;
        cout << "Puesto del empleado: " << empleado.puesto << endl;
        cout << "Sueldo base del empleado: " << empleado.sueldo_base << endl;
        cout << "Bonificacion del empleado: " << empleado.bonificacion<< endl;
        cout << "Sueldo total del empleado: " << empleado.sueldo_total << endl;
        cout << endl;
	
	fclose(archivo);

		system("pause");
	system("cls");
	main ();
}
void abrir_empleado(){
	
	

	system("cls");
	FILE* archivo = fopen(nombe_archivo, "rb");
	if(!archivo) {
		archivo = fopen(nombe_archivo, "w+b");
	}
	Empleado empleado;
	int registro=0;
	fread ( &empleado, sizeof(Empleado), 1, archivo );
	cout<<"_______________________________________________________________________________________"<<endl<<endl;
	cout << " id "<<"|"<<" CODIGO "<<"|"<<" NOMBRE "<<"|"<<" APELLIDO "<<"|"<<" PUESTO "<<"|"<<" SUELDO BASE "<<"|"<<" BONIFICACION "<<"|"<<" SUELDO TOTAL "<<"|"<<endl;	
		do{
	cout<<"_______________________________________________________________________________________"<<endl<<endl;
		cout<<"  "<<registro<<"   |  "<<empleado.codigo<<"  |  "<<empleado.nombres<<"  |  "<<empleado.apellido<<"  |  "<<empleado.puesto<<"  |  "<<empleado.sueldo_base<<"  |  "<<empleado.bonificacion<<"  |  "<<empleado.sueldo_total<<"  |  "<<endl;
        
        
		fread ( &empleado, sizeof(Empleado), 1, archivo );
		registro += 1;	
		} while (feof( archivo ) == 0);
		
    cout<<endl;
    
		fclose(archivo);


	
	}	
void ingresar_empleado(){
	
	char continuar;
	FILE* archivo = fopen(nombe_archivo, "ab"); // ab
	
	
		Empleado empleado;
		 string nombre,apellido,puesto;
		 
		do{
			fflush(stdin);
			
		cout<<"Ingrese el codigo de empleado: ";
		cin>>empleado.codigo;
        cin.ignore();
        
		cout<<"Ingrese el nombre del empleado: ";
		getline(cin,nombre);
    	strcpy(empleado.nombres, nombre.c_str()); 
			
		cout<<"Ingrese el apellido del empleado: ";
		getline(cin,apellido);
		strcpy(empleado.apellido, apellido.c_str()); 
		
		cout<<"Ingrese el puesto del empleado: ";
		getline(cin,puesto);
		strcpy(empleado.puesto, puesto.c_str()); 
		
		cout<<"Ingrese el sueldo del empleado: ";
		cin>>empleado.sueldo_base;
		cin.ignore();
		
		cout<<"Ingrese la bonificacion del empleado: ";
		cin>>empleado.bonificacion;
		cin.ignore();
		
		empleado.sueldo_total = ((empleado.sueldo_base)+(empleado.bonificacion));
		
		fwrite( &empleado, sizeof(Empleado), 1, archivo );
		
		cout<<"Desea Agregar otro Empleado s/n : ";
		cin>>continuar;
		} while((continuar=='s') || (continuar=='S') );
		
	
	fclose(archivo);
	abrir_empleado();
		system("pause");
	system("cls");
	main ();
	//buscar_indice();	
//	buscar_codigo();
}
void modificar_empleado(){
	
	FILE* archivo = fopen(nombe_archivo, "r+b");
	
		int id;
		string nombre,apellido,puesto;	
    	Empleado empleado;
    	
    	abrir_empleado();
    
		cout << "Ingrese el ID que desea Modificar: ";
    		cin >> id;
    		fseek ( archivo, id * sizeof(Empleado), SEEK_SET );  
	
	cout<<"Ingrese el codigo de empleado: ";
		cin>>empleado.codigo;
        cin.ignore();
        
		cout<<"Ingrese el nombre del empleado: ";
		getline(cin,nombre);
    	strcpy(empleado.nombres, nombre.c_str()); 
			
		cout<<"Ingrese el apellido del empleado: ";
		getline(cin,apellido);
		strcpy(empleado.apellido, apellido.c_str()); 
		
		cout<<"Ingrese el puesto del empleado: ";
		getline(cin,puesto);
		strcpy(empleado.puesto, puesto.c_str()); 
		
		cout<<"Ingrese el sueldo del empleado: ";
		cin>>empleado.sueldo_base;
		cin.ignore();
		
		cout<<"Ingrese la bonificacion del empleado: ";
		cin>>empleado.bonificacion;
		cin.ignore();
		
		empleado.sueldo_total = ((empleado.sueldo_base)+(empleado.bonificacion));
		
		fwrite( &empleado, sizeof(Empleado), 1, archivo );
		
	fclose(archivo);
	cout<<endl<<"*************El registro se ah modificado exitosamente:************"<<endl;
	system("pause");
	abrir_empleado();
			system("pause");

	main ();
}
void eliminar_empleado(){
	FILE* archivo = fopen(nombe_archivo, "rb");
	FILE* archivo_temp = fopen(nombe_archivo_temp, "ab");

	
	if(!archivo) {
		archivo = fopen(nombe_archivo, "w+b");
	}
	Empleado empleado;
		fflush(stdin);
		

		abrir_empleado();	
		
	int id=0;
	int ids=0;
		cout << "Ingrese el ID que desea eliminar: ";
    		cin >> id;	
			
	fread ( &empleado, sizeof(Empleado), 1, archivo );
	
	do{	

	if(id == ids){
	fread ( &empleado, sizeof(Empleado), 1, archivo );
	ids= ids+1;
	
	}
	
	
		fwrite( &empleado, sizeof(Empleado), 1, archivo_temp );
		fread ( &empleado, sizeof(Empleado), 1, archivo );
		ids= ids+1;
			if(id == ids){
	fread ( &empleado, sizeof(Empleado), 1, archivo );
	ids= ids+1;
	
	}
		
	}while(feof(archivo)==0);
	
	fclose(archivo);	
	fclose(archivo_temp);
	
cout<<endl<<"************* El registro se ah eliminado exitosamente ************"<<endl<<endl;	
		
				
}
void mostrar_empleado_temp(){

	FILE* archivo_temp = fopen(nombe_archivo_temp, "rb");
	if(!archivo_temp) {
		archivo_temp = fopen(nombe_archivo_temp, "w+b");
	}
	Empleado empleado;
	int registro=0;
	fread ( &empleado, sizeof(Empleado), 1, archivo_temp );
	cout<<"_______________________________________________________________________________________"<<endl<<endl;
	cout<<"*************Los nuevos registros son los sigunetes:************"<<endl<<endl;
	cout<<"_______________________________________________________________________________________"<<endl<<endl;
	cout << " id "<<"|"<<" CODIGO "<<"|"<<" NOMBRE "<<"|"<<" APELLIDO "<<"|"<<" PUESTO "<<"|"<<" SUELDO BASE "<<"|"<<" BONIFICACION "<<"|"<<" SUELDO TOTAL "<<"|"<<endl;	
		do{
	cout<<"_______________________________________________________________________________________"<<endl<<endl;
		cout<<"  "<<registro<<"   |  "<<empleado.codigo<<"  |  "<<empleado.nombres<<"  |  "<<empleado.apellido<<"  |  "<<empleado.puesto<<"  |  "<<empleado.sueldo_base<<"  |  "<<empleado.bonificacion<<"  |  "<<empleado.sueldo_total<<"  |  "<<endl;
        
		fread ( &empleado, sizeof(Empleado), 1, archivo_temp );
		registro += 1;	
		} while (feof( archivo_temp ) == 0);
		
    cout<<endl;
    
		fclose(archivo_temp);
		
			remove("archivo.dat");
	rename("archivo_temp.dat","archivo.dat");
	system("pause");
	main ();
		}
	

	

