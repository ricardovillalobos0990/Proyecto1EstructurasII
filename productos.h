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
			gotoxy(30,2);printf("PRODUCTOS");
			gotoxy(3,4);printf("ID");
			gotoxy(6,4);printf("NOMBRE");
			gotoxy(26,4);printf("VALOR");
			gotoxy(3,6+i);printf("%d", pproductos->id);
			gotoxy(6,6+i);printf("%s", pproductos->nombre);
			gotoxy(26,6+i);printf("%f", pproductos->valor);
			i++;
		}
	}i=0;
	fclose(archivo);
}

void editar_productos (int *pBuscar){
	
	FILE *archivo;
	archivo=fopen("datos/productos.txt","r+b");
	rewind(archivo);
	int bandera=0;
	while(fread(&productos, sizeof(productos), 1, archivo)){
	if (*pBuscar==pproductos->id){
		bandera=1;
		break;
		}i++;
	}
if(bandera ==0){
		gotoxy(24,8); printf("NO SE ENCONTRO NINGUN DATO EXISTE");
		gotoxy(20,23); printf(" ");
		system("pause");
}else{
	int opc=1;
	while(opc!=0){
		system("cls");
		dibujaRectangulo(1,1,80,24);
		gotoxy(30,2);printf(" EDITAR PRODUCTO ");
		gotoxy(4,3);printf(" ID :");
		gotoxy(4,4);printf(" Nombre :");
		gotoxy(4,5);printf(" Valor :");
		if (*pBuscar==pproductos->id){
		gotoxy(13,3);printf("%d", pproductos->id);
		gotoxy(13,4);printf("%s", pproductos->nombre);
		gotoxy(13,5);printf("%f", pproductos->valor);
		}
		gotoxy(30,12);printf(" CONSULTA DE PRODUCTOS ");
		gotoxy(3,14);printf(" 1: ID ");
		gotoxy(3,15);printf(" 2: Nombre ");
		gotoxy(3,16);printf(" 3: Valor \n \n");
		printf(" Seleccione la opcion que desea Modificar ");
		scanf("%d", &opc);
		switch (opc){
				case 1:{
				system("cls");
				int n_id, *pn_id=&n_id;
				gotoxy(2,4);printf(" Editar Producto \n ");
				gotoxy(2,5);printf(" Digite el numero del ID \n ");
				scanf("%d", pn_id);
	            fseek(archivo,ftell(archivo)-sizeof(productos),SEEK_SET);
		        (fread(&productos, sizeof(productos),1,archivo));
		        pproductos->id=*pn_id;
		        fseek(archivo,ftell(archivo)-sizeof(productos),SEEK_SET);
		    	fwrite(&productos,sizeof(productos),1,archivo);
				break;
				}
				case 2:{
				system("cls");
				char n_nombre[25], *pn_nombre=n_nombre;
				gotoxy(28,1); printf("EDITAR PRODUCTO");
				fflush(stdin);
				gotoxy(3,3); printf("Ingrese el nuevo nombre del Producto: ");
				fgets(pn_nombre, 25, stdin);
				fflush(stdin);
				fseek(archivo, ftell(archivo)-sizeof(productos), SEEK_SET);
				fread(&productos, sizeof(productos), 1, archivo);
				strcpy(pproductos->nombre, pn_nombre);
				fseek(archivo, ftell(archivo)-sizeof(producto), SEEK_SET);
				fwrite(&productos, sizeof(producto), 1, archivo);
				fclose(archivo);
				break;
				}
				case 3:{
				
				}
				case 0:
				{
				system("cls");
				}
				default:
				{
				system("cls");
				gotoxy(28,1); printf("OPCION INVALIDA \n");
				system("pause");
				break;
				}
			}
		}
	}
}

