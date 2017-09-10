struct producto
{
	int id;
	char nombre[30];
	float valor;
} productos, copiaproductos, *pproductos = &productos, *pcopiaproductos = &copiaproductos;

bool crear_productos()
{
	FILE *archivo;
	
	archivo = fopen("datos/productos.txt", "rb");
	
	if(archivo == NULL)
	{
		return false;
	}
	rewind(archivo);
	fseek(archivo,ftell(archivo)-sizeof(*pproductos),SEEK_END);
	fread(pproductos, sizeof(*pproductos), 1, archivo);
	printf("%d", pproductos->id);
	pproductos->id = pproductos->id+1;
	fclose(archivo);
	color(azulclaro);
	fflush(stdin);
	gotoxy(24,7);printf("Nombre del producto");
	color(azulclaro);
	gotoxy(24,8);fgets(pproductos->nombre, 30, stdin);
	fflush(stdin);
	color(azulclaro);
	gotoxy(24,10);printf("Valor del Producto");
	color(azulclaro);
	fflush(stdin);
	gotoxy(24,11);scanf("%2f", &pproductos->valor, 10, stdin);
	fflush(stdin);	
	archivo = fopen("datos/productos.txt", "ab");
	
	if(archivo == NULL)
	{
		color(rojoclaro);
		gotoxy(24, 16);printf("No se pudo guardar el registro");
	}
	else
	{
		fwrite(pproductos,sizeof(*pproductos),1,archivo);
		rewind(archivo);
		fclose(archivo);
		color(verdeclaro);
		gotoxy(32, 16);printf("Registro Exitos");
	}
}

bool mostrar_productos()
{
	FILE *archivo;
	
	archivo = fopen("datos/productos.txt", "rb");
	
	if(archivo == NULL)
	{
		return false;
	}
	else
	{
		while(fread(pproductos, sizeof(*pproductos), 1, archivo))
		{
			printf("%d \n", pproductos->id);
			printf("%s", pproductos->nombre);
			printf("%d", pproductos->valor);
			printf("\n");
		}
	}
	fclose(archivo);
}



void modificar (int *peditar){
	
	
}
case 4: {
	int modifica=1;
	char n_nombre [15];
	char n_apellido [15];
	float n_nota1,n_nota2,n_nota3,n_definitiva;	
	system("cls");
 	archivo = fopen("archivos/estudiantes.txt","rb+");
 	rewind(archivo);  
 	cout << " Ingrese la Cedula a Modificar " << endl;
 	cin>>buscar;
 	int bandera = 0;
 	while(fread(&dato,sizeof(dato),1,archivo)){
	if(strcmp(buscar,dato.cedula)==0){
				bandera = 1;
				break;
		       }i++;   
	        }
	if(bandera == 0){
	cout << "El dato no existe" << endl;
	    		}else{
	while(modifica!=0){  	
		 		if(strcmp(buscar,dato.cedula)==0){
				system("cls");
				rectangulo(22,76);
				gotoxy(34,2);cout<<"CONSULTA DE CEDULAS";
				gotoxy(3,4);cout<<"ID";
				gotoxy(7,4);cout<<"CEDULA";
				gotoxy(18,4);cout<<"NOMBRE";
				gotoxy(39,4);cout<<"APELLIDOS";
				gotoxy(60,4);cout<<"N1";
				gotoxy(64,4);cout<<"N2";
				gotoxy(68,4);cout<<"N3";
				gotoxy(72,4);cout<<"DEF";
				gotoxy(3,5+i);cout<<i;
				gotoxy(7,5+i);cout<<dato.cedula;
				gotoxy(18,5+i);cout<<dato.nombre;
				gotoxy(39,5+i);cout<<dato.apellido;
				gotoxy(60,5+i);cout<<dato.nota1;
				gotoxy(64,5+i);cout<<dato.nota2;
				gotoxy(68,5+i);cout<<dato.nota3;
				gotoxy(72,5+i);
				cout<<dato.notadefinitiva<<endl;
				}
	    		cout<< " MENU"<<endl;
	            cout<< " 1. Modificar Nombre"<<endl;
	            cout<< " 2. Modificar Apellido"<<endl;
	            cout<< " 3. Modificar Nota 1"<<endl;
	            cout<< " 4. Modificar Nota 2"<<endl;
	            cout<< " 5. Modificar Nota 3"<<endl;
	            cout<< " 0. Salir"<<endl;
	            cout<< " Seleccione la Opcion";
	            cin>>modifica;
	            cin.ignore(256,'\n');
	            switch (modifica){
	                case 1:{
	                cout<< " Ingrese el nuevo NOMBRE " << endl;
	                cin.getline(n_nombre,15);
	                fseek(archivo,ftell(archivo)-sizeof(dato),SEEK_SET);
		            (fread(&dato,sizeof(dato),1,archivo));
		            strcpy(dato.nombre,n_nombre);
		            fseek(archivo,ftell(archivo)-sizeof(dato),SEEK_SET);
		            fwrite(&dato,sizeof(dato),1,archivo);
					break;
					}
					case 2:{
					cout<< " Ingrese el APELLIDO"<<endl;
					cin.getline(n_apellido,20);
					fseek(archivo,ftell(archivo)-sizeof(dato),SEEK_SET);
		            (fread(&dato,sizeof(dato),1,archivo));
		            strcpy(dato.apellido,n_apellido);
		            fseek(archivo,ftell(archivo)-sizeof(dato),SEEK_SET);
		            fwrite(&dato,sizeof(dato),1,archivo);
					break;
					}
					case 3:{
					cout<< " Ingrese el nuevo Valor para la NOTA 1 " << endl;
					cin>>n_nota1;
					fseek(archivo,ftell(archivo)-sizeof(dato),SEEK_SET);
		            (fread(&dato,sizeof(dato),1,archivo));
		            dato.nota1=n_nota1;
		            dato.notadefinitiva=(dato.nota1*0.35)+(dato.nota2*0.35)+(dato.nota3*0.30);
		            fseek(archivo,ftell(archivo)-sizeof(dato),SEEK_SET);
		            fwrite(&dato,sizeof(dato),1,archivo);
					break;
					}
					case 4:{
					cout<< " Ingrese el nuevo Valor para la NOTA 2 " <<endl;
					cin>>n_nota2;
					fseek(archivo,ftell(archivo)-sizeof(dato),SEEK_SET);
		            (fread(&dato,sizeof(dato),1,archivo));
		            dato.nota2=n_nota2;
		            dato.notadefinitiva=(dato.nota1*0.35)+(dato.nota2*0.35)+(dato.nota3*0.30);
		            fseek(archivo,ftell(archivo)-sizeof(dato),SEEK_SET);
		            fwrite(&dato,sizeof(dato),1,archivo);
					break;
					}
					case 5:{
					cout<< " Ingrese el nuevo Valor para la NOTA 3"<<endl;
					cin>>n_nota3;
					fseek(archivo,ftell(archivo)-sizeof(dato),SEEK_SET);
		            (fread(&dato,sizeof(dato),1,archivo));
		            dato.nota3=n_nota3;
		            dato.notadefinitiva=(dato.nota1*0.35)+(dato.nota2*0.35)+(dato.nota3*0.30);
		            fseek(archivo,ftell(archivo)-sizeof(dato),SEEK_SET);
		            fwrite(&dato,sizeof(dato),1,archivo);      
	                rewind(archivo);
					break;
							}
					case 0:
					{
					break;
					}
					default:
					{
					system("cls");
					rectangulo(22,76);
					gotoxy(34,6);
					cout<<"MODIFICAR";
					gotoxy(3,5);
					cout<<"Opcion Invalida"<<endl;
					system("pause");
					break;
					}
				}
	    	}
	    }
		fclose(archivo);
		break;	  	
       	}
