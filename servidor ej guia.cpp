#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
	int sock_conn, sock_listen, ret;
	struct sockaddr_in serv_adr;
	char peticion[512];
	char respuesta[512];
	// INICIALITZACIONS
	// Obrim el socket
	if ((sock_listen = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		printf("Error creant socket");
	// Fem el bind al port
	memset(&serv_adr, 0, sizeof(serv_adr));// inicialitza a zero serv_addr
	serv_adr.sin_family = AF_INET;
	// asocia el socket a cualquiera de las IP de la m?quina. 
	//htonl formatea el numero que recibe al formato necesario
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	// escucharemos en el port 9050
	serv_adr.sin_port = htons(9050);
	if (bind(sock_listen, (struct sockaddr *) &serv_adr, sizeof(serv_adr)) < 0)
		printf ("Error al bind");
	//La cola de peticiones pendientes no podr? ser superior a 4
	if (listen(sock_listen, 3) < 0)
		printf("Error en el Listen");
	int i;
	// Atenderemos solo 10 peticione
	for(i=0;i<5;i++){
		printf ("Escuchando\n");
		
		sock_conn = accept(sock_listen, NULL, NULL);
		printf ("He recibido conexion\n");
		//sock_conn es el socket que usaremos para este cliente
		// Ahora recibimos su nombre, que dejamos en el buffer
		ret=read(sock_conn,peticion, sizeof(peticion));
		printf ("Recibido\n");
		// Tenemos que a?adirle la marca de fin de string 
		// para que no escriba lo que hay despues en el buffer
		peticion[ret]='\0';
		p= strtok( NULL, "/");
		char nombre[20];
		//Escribimos la peticion en la consola
		
		printf ("Peticion: %s\n",peticion);
		char *p = strtok(peticion, "/");
		int codigo =  atoi (p);
		p= strtok( NULL, "/");
		char nombre[20];
		strcpy (nombre, p);
		printf ("Codigo: %d, Nombre:%s\n", codigo, nombre);
		
		if (codigo == 1) //piden la longitd del nombre
			sprintf (respuesta,"%d",strlen (nombre));
		
		else if (codigo ==2)
			// quieren saber si el nombre es bonito
			    if((nombre[0]=='O') || (nombre[0]=='Q'))
					strcpy (respuesta,"SI");
			    else
					strcpy (respuesta,"NO");
			else// decir si es alto
				p= strtok( NULL, "/");
		        float altura = atoi (p);
		        if (altura > 1.70)
					sprintf (respuesta, "%s: eres alto", nombre);
				else
					sprintf (respuesta, "%s: eres bajo", nombre)
			
				
			printf ("Respuesta: %s\n", respuesta);
			// Y lo enviamos
			write (sock_conn, respuesta, strlen(respuesta));
			
			// Se acabo el servicio para este cliente
			close(sock_conn); 
	}
}
