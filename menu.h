void menu()
{
	//---------------------------------------------------------
	int opcion = 0, subOpcion = 0, buscar=0, *pBuscar;
	int* pOpcion = &opcion, *pSubOpcion = &subOpcion;
	pBuscar=&buscar;
	char nombre[10] = "sebastian";
	printf("%d", sizeof(char[10]));
	
	do{
		system("cls");
		dibujaRectangulo(1,1,79,24);
		color(verdeclaro);
		gotoxy(28,3);printf("Sistema de facturacion");
		
		color(rojoclaro);
		gotoxy(32,5);printf("Menu principal");
		
		color(cyan);
		gotoxy(33, 7);printf("1. Clientes");
		gotoxy(33, 8);printf("2. Productos");
		gotoxy(33, 9);printf("3. Facturas");
		gotoxy(33, 10);printf("0. Salir");
		
		gotoxy(28, 12);printf("Ingrese la opcion: ");
		scanf("%d", &opcion);
		
		switch(*pOpcion)
		{
			case 0:
			{
				break;
			}
			case 1:
			{
				do{
					system("cls");
					dibujaRectangulo(1,1,79,24);
					color(verdeclaro);
					gotoxy(28,3);printf("Sistema de facturacion");
					
					color(rojoclaro);
					gotoxy(35,5);printf("Clientes");
					
					color(cyan);
					gotoxy(30, 7);printf("1. Crear Cliente");
					gotoxy(30, 8);printf("2. Buscar Cliente");
					gotoxy(30, 9);printf("3. Editar Cliente");
					gotoxy(30, 10);printf("4. Mostrar Clientes");
					gotoxy(30, 11);printf("0. Salir");
					
					gotoxy(28, 13);printf("Ingrese la opcion: ");
					scanf("%d", &subOpcion);
					
					switch(*pSubOpcion)
					{
						case 0:
						{
							break;
						};
						case 1:
						{
							system("cls");
							dibujaRectangulo(1,1,79,24);
							crear_cliente();
							getch();
							break;
						};
						case 2:
						{
							gotoxy(20,15);printf("Ingrese el id del cliente a buscar ");
							scanf("%d", &pBuscar);
							system("cls");
							dibujaRectangulo(1,1,79,24);
							buscar_cliente(pBuscar);
							getch();
							break;
						};
						case 3:
						{
							
						};
						case 4:
						{
							system("cls");
							dibujaRectangulo(1,1,80,24);
							mostrar_clientes();
							getch();
							break;
						};
					}
					
				} while(*pSubOpcion != 0);
			}
			case 2:
			{
				do{
					system("cls");
					dibujaRectangulo(1,1,80,24);
					color(verdeclaro);
					gotoxy(28,3);printf("Sistema de facturacion");
					
					color(rojoclaro);
					gotoxy(34,5);printf("Productos");
					
					color(cyan);
					gotoxy(17, 7);printf("1. Crear Producto");
					gotoxy(17, 8);printf("2. Mostrar Productos");
					gotoxy(17, 9);printf("3. Editar Productos");
					gotoxy(17, 10);printf("4. Listar Productos con la cantidad vendida");
					gotoxy(17, 11);printf("0. Salir");
					
					gotoxy(17, 12);printf("Ingrese la opcion: ");
					scanf("%d", &subOpcion);
					
					switch(*pSubOpcion)
					{
						case 0:
						{
							break;
						};
						case 1:
						{
							system("cls");
							dibujaRectangulo(1,1,79,24);
							crear_productos();
							getch();
							break;
						};
						case 2:
						{
							system("cls");
							dibujaRectangulo(1,1,80,24);
							mostrar_productos();
							getch();
							break;
						};
						case 3:
						{	
							system("cls");
							gotoxy(20,15);printf("Ingrese el id del cliente a buscar ");
							scanf("%d", &buscar);
							dibujaRectangulo(1,1,80,24);
							editar_productos(pBuscar);
							getch();
							break;
						};
						
					}
					
				} while(*pSubOpcion != 0);
			}
			case 3:
			{
				do{
					system("cls");
					dibujaRectangulo(1,1,80,24);
					color(verdeclaro);
					gotoxy(28,3);printf("Sistema de facturacion");
					
					color(rojoclaro);
					gotoxy(35,5);printf("Facturas");
					
					color(cyan);
					gotoxy(27, 7);printf("1. Crear Factura");
					gotoxy(27, 8);printf("2. Buscar Factura");
					gotoxy(27, 9);printf("3. Editar Factura");
					gotoxy(27, 10);printf("4. Mostrar Facturas");
					gotoxy(27, 11);printf("5. Facturas por cliente");
					gotoxy(27, 12);printf("6. Facturas pagadas");
					gotoxy(27, 13);printf("7. Facturas sin pagar");
					gotoxy(27, 14);printf("0. Salir");
					
					gotoxy(27, 16);printf("Ingrese la opcion: ");
					scanf("%d", &subOpcion);
					
					switch(*pSubOpcion)
					{
						case 0:
						{
							
						};
						case 1:
						{
							
						};
						case 2:
						{
						
						};
						case 3:
						{
						
						};
						
					}
					
				} while(*pSubOpcion != 0);
			}
		}
		
		
	} while(*pOpcion != 0);
}
