struct Cliente
{
	int id;
	char cedula[10];
	char nombre[30];
	char direccion[50];
	char telefono[10];
} usuario, copiaUsuario, *pUsuario = &usuario, *pCopiaUsuario = &copiaUsuario;

bool crear_cliente()
{
	FILE *archivo;
	
	archivo = fopen("datos/clientes.txt", "rb");
	
	if(archivo == NULL)
	{
		return false;
	}
	rewind(archivo);
	fseek(archivo,ftell(archivo)-sizeof(*pUsuario),SEEK_END);
	fread(pUsuario, sizeof(*pUsuario), 1, archivo);
	printf("%d", pUsuario->id);
	pUsuario->id = pUsuario->id+1;
	fclose(archivo);
	color(amarillo);
	fflush(stdin);
	gotoxy(24,4);printf("Numero de cedula del cliente");
	color(grisclaro);
	gotoxy(24,5);fgets(pUsuario->cedula, 10, stdin);
	color(amarillo);
	fflush(stdin);
	gotoxy(24,7);printf("Nombre del cliente");
	color(grisclaro);
	gotoxy(24,8);fgets(pUsuario->nombre, 30, stdin);
	fflush(stdin);
	color(amarillo);
	fflush(stdin);
	gotoxy(24,10);printf("Direccion de cliente");
	color(grisclaro);
	gotoxy(24,11);fgets(pUsuario->direccion, 10, stdin);
	fflush(stdin);
	color(amarillo);
	fflush(stdin);
	gotoxy(24,13);printf("Telefono del cliente");
	color(grisclaro);
	gotoxy(24,14);fgets(pUsuario->telefono, 10, stdin);
	fflush(stdin);
	
	archivo = fopen("datos/clientes.txt", "ab");
	
	if(archivo == NULL)
	{
		color(rojoclaro);
		gotoxy(24, 16);printf("No se pudo guardar el registro");
	}
	else
	{
		fwrite(pUsuario,sizeof(*pUsuario),1,archivo);
		rewind(archivo);
		fclose(archivo);
		color(verdeclaro);
		gotoxy(32, 16);printf("Registro Exitos");
	}
}

bool mostrar_clientes()
{
	FILE *archivo;
	
	archivo = fopen("datos/clientes.txt", "rb");
	
	if(archivo == NULL)
	{
		return false;
	}
	else
	{
		while(fread(pUsuario, sizeof(*pUsuario), 1, archivo))
		{
			printf("%d \n", pUsuario->id);
			printf("%s", pUsuario->cedula);
			printf("%s", pUsuario->nombre);
			printf("%s", pUsuario->direccion);
			printf("%s", pUsuario->telefono);
			printf("\n");
		}
	}
	fclose(archivo);
}

bool buscar_cliente(int *pBuscar)
{
	FILE *archivo;
	int cantidad = 0, *pCantidad = &cantidad;
	archivo = fopen("datos/clientes.txt", "rb");
	
	if(archivo == NULL)
	{
		return false;
	}
	else
	{
		while(fread(pUsuario, sizeof(*pUsuario), 1, archivo))
		{
			if(*pBuscar == pUsuario->id)
			{
				printf("%d \n", pUsuario->id);
				printf("%s \n", pUsuario->cedula);
				printf("%s", pUsuario->nombre);
				printf("%s", pUsuario->direccion);
				printf("%s", pUsuario->telefono);
				printf("\n");
				(*pCantidad)++;
				break;
			}
		}
		
		if(*pCantidad <= 0)
		{
			color(rojo);
			gotoxy(24,12);printf("No se encontro ningun registro");
			getch();
		}
	}
	fclose(archivo);
}

void editar_cliente()
{
	
}

