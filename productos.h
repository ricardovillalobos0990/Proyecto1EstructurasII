struct producto
{
	int id;
	char nombre[30];
	float valor;
} productos, copiaproductos, *pproductos = &productos, *pcopiaproductos = &copiaproductos;

int subOpcion, i =0;

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



void editar_productos (int *pBuscar){
	
	FILE *archivo;
	archivo=fopen("datos/productos","rb+");
	rewind(archivo);
	int bandera=0;
	while(fread(&productos, sizeof(productos), 1, archivo)){
	if (*pBuscar==pproductos->id){
		bandera=1;
		break;
		}i++;
	}
if(bandera ==0){
	printf("El dato no existe");
}else{
	int modifica=1;
	while(modifica!=0){
		gotoxy(4,12);printf(" Editar Producto");
		gotoxy(4,13);printf(" ID");
		gotoxy(4,14);printf(" Nombre");
		gotoxy(4,15);printf(" Valor");
		if (*pBuscar==pproductos->id){
		gotoxy(3,7+i);printf("%d", pproductos->id);
		gotoxy(3,8+i);printf("%s", pproductos->nombre);
		gotoxy(3,9+i);printf("%f", pproductos->valor);
		}
		gotoxy(34,2);printf("CONSULTA DE PRODUCTOS");
		gotoxy(3,4);printf("ID");
		gotoxy(3,5);printf("Nombre");
		gotoxy(3,6);printf("Valor");
		printf("Seleccione la opcion");
		scanf("%d", &subOpcion);
		switch (subOpcion){
		case 1:{
					system("cls");
					int n_id, *pn_id=&n_id;
					printf("Editar Producto \n");
					printf("Digite el numero de la cedula \n");
					scanf("%d", pn_id);
	                fseek(archivo,ftell(archivo)-sizeof(pproductos),SEEK_SET);
		            (fread(&productos, sizeof(productos),1,archivo));
		            pproductos->id=*pn_id;
		            fseek(archivo,ftell(archivo)-sizeof(productos),SEEK_SET);
		            fwrite(&productos,sizeof(productos),1,archivo);
					break;
					}
					case 0:
					{
					break;
					}
					default:
					{
					system("cls");
					dibujaRectangulo(1,1,79,24);
					gotoxy(34,6);
					printf( " MODIFICAR " );
					gotoxy(3,5);
					printf("\n Opcion Invalida");
					system("pause");
					break;
					}
			}
		}
	}
}

