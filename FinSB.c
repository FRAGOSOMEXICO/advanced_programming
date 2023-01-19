#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<assert.h>
#include<semaphore.h>
#include<semaphore.h>
#include<fcntl.h>
#include<pthread.h>
#include<time.h>
#include<string.h>
#include <stdint.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <time.h>
#define precio_hamburguesa 120
sem_t bench_for_clients;
sem_t puerta;
sem_t sem_for_orders;
sem_t local,dormidos;
sem_t raw_materials;
//sem_t limpieza;
// sem_t FuegoA;
sem_t cocineros;
sem_t meseros;
sem_t mantenimiento;
sem_t cajas;
sem_t Charcoal;
sem_t employees_begin_to_work;
sem_t cliente;
sem_t jarra;
int sustracion_from_the_total_orders=0,llave_veces_ordenes=0,times_the_waiters=0,pointer=0,flag_orders=0,another_random_fckg_number=0;
int spots_for_clients_has_came[5],total_orders=0,permiso_2=0,visualize_the_cooks_working=0;
int permiso_ordenes=0;
void abandonaded_function();
void*preparations_check();
void*cooks_deal_with_orders();
void*spots_for_clients_came_earlier_than_expected();
void alarma();/*captura la senial de alarma SIGALARM*/
void cortar();/*captura la senial de interrupcion SIGINT*/
int counter_waiters=0,bandera_dormir=0,bandera_dormir_2=0,llave_maestra=0,orders_were_just_settled=0;
int Hora=10, costo = 120, clientesA, clientesB, esperaA, esperaB,j=0,bucle=1,numcortes=0,spot_within_the_waiters_array=0,spot_within_the_cooks_array=0;
int several_waiters[2],several_cooks[1];
void abre_grafico();
void cierra_grafico();
void The_fire_is_put_out();
void*Cook();
void*Clean();
void*Caja();
void*Tomar_pedido();
void*Clientes();
int servicio=0,randomly_generated_amount_of_orders=0,sustraction=0,sustraction_sec_saver=0;
int permiso=0,timing_the_waiters[20];
int clientes_afterorbefore=0;
int clientes_afterorbefore_decision=0,profit=0;
//bool permiso=0/*,raw_mat_chk=0,cocin1_chk=0,cocin2_chk=0,cocin3_chk=0,mese1_chk=0,mese2_chk=0,caj_chk=0,mant_chk=0,charc_chk=0*/;
int raw_mat_chk=0,cocin1_chk=0,cocin2_chk=0,cocin3_chk=0,mese1_chk=0,mese2_chk=0,caj_chk=0,mant_chk=0,charc_chk=0,randomly_generated_clients=0;
int orders[20];
void*clien();
/*unsigned int num=profit*precio_hamburguesa;
char total_mandar[10];*/

void *Everything_happens()
{
 //  int j=0;
 // if(j==0){j=0;}
 // else if(j==11){j=10;}
 printf("Empieza a correr el tiempo\n");
 signal(SIGINT,cortar);
            signal(SIGALRM,alarma);
            printf("\n");
            printf("Pulsa CTRL-C para aumentar la hora en una unidad\n");
            //printf("%d",numcortes);
            //alarm(15);
            while(bucle);
            signal(SIGINT,SIG_IGN);
            // printf("Has intentado cortar %d veces\n",j);
            
            //printf("Hasta luego lucas\n");
            exit(0);
 
}
int llave_para_mesero_principal=0;
void *abrir()//el empleado abre la surcursal
{
 int value=0;
  sem_getvalue(&local, &value);
  // printf("semaforo en abrir %d\n", value);
  //sem_wait(&local);
 // while(sem_getvalue(&local, &value)!=-1&&j!=10||sem_getvalue(&local, &value)!=-1&&j!=23){
 while(sem_getvalue(&local, &value)!=-1&&j!=10||sem_getvalue(&local, &value)!=-1&&j!=23){
 //while(/*sem_getvalue(&local, &value)!=-1&&*/j>=10||/*sem_getvalue(&local, &value)!=-1&&*/j<=23){
  // sem_wait(&local);
  // printf("bam bam");
  if(j==10&&sem_getvalue(&local, &value)==0||j==23&&sem_getvalue(&local, &value)==0)
  {
  // printf("AHLELULLA");
 //  printf("se ejecuta abrir %d\n",j);
 //  int value;
 //  sem_getvalue(&local, &value);
 //  printf("semaforo en abrir %d\n", value);
  }
 //printf("se ejecuta abrir %d\n",j);
    if( j== 10)
    {  /*Estamos a las 10 y transcurre una hora*/
      
     sem_wait(&local); //the semaphore decremets one unit
     printf("Los locales estan abiertos");//se debe hacer la limpieza y mostrar que ya esta limpiio
  /// si no se ha acabado la limpieza hacerlos esperar en sillas y darles una jarra 
  //el encargado  de corte de caja reune todo el dinero
  //solo el PID del que recibe el dinero
  //cierra_grafico();
  abre_grafico(); //the employees get into the restaurant, the goods get delivered
  if(clientes_afterorbefore_decision==1){
      permiso=3;
  	sem_post(&cliente);
       sleep(1);
      //printf("En total son %d ordenes\n",total_orders);
      permiso_2=4;
    sem_post(&bench_for_clients);
    sem_post(&jarra);
  }
  sem_post(&raw_materials);  //we allow the process to be done just at this time.
  sleep(2);
  sem_post(&cocineros);   
  sleep(1);
  sem_post(&cocineros);
  sleep(1);
  sem_post(&cocineros);
  sleep(1);
  llave_para_mesero_principal=1;
  sem_post(&meseros);
  sleep(1);
  llave_para_mesero_principal=1;
  sem_post(&meseros);
  sleep(1);
  llave_para_mesero_principal=0;
  
  sem_post(&cajas);
  sem_post(&mantenimiento);
  sleep(1);
  printf("La cocina esta lista\n");
    
  if(clientes_afterorbefore_decision==2){
  	permiso=3;
    
      sem_post(&cliente);
       sleep(1);
      permiso_2=4;
      // printf("En total son %d ordenes\n",total_orders);
      sem_post(&bench_for_clients);
      sem_post(&jarra);
  }

    }

    else if(j== 23) 
    {/*Estamos a las 23 y transcurre una hora*/
  sem_wait(&local); //the semaphore decremets one unit
     printf("Los locales cerraron");
  cierra_grafico();
  clien();
  sleep(1);
  printf("Son las 00:00 horas  el restaurante esta cerrado\n");
     //sem_post(&DineroA);
  //The charcoal has to be turned off, the charcoal value is 1
  sem_wait(&Charcoal);
  j=0;// we avoid a crash
    }
    
 // pthread_exit(0);
   } 

}

void *The_employee_recieves_raw_materials_delivery_from_the_provider() //this works as a thread
{
 while(1){
 sem_wait(&raw_materials);
 raw_mat_chk=1;
 printf("La mercancia es recibida en el local a las %d:00 horas por el empleado de PID %li \n",j,pthread_self());
 printf("\n");
 printf("_______________________\n");
 printf("|             |       |\n");
 printf("|  MERCANCIA  |       |\n");
 printf("|             |       |\n");
 printf("|  FRAGILE    |FRAGILE|\n");
 printf("|             |       |\n");
 printf("|_____________|_______|\n");
 //we gotta allow the employee to set up the charcoal for the hamburgers
 //the charcoal have to being setted for all day long.
  ///checks the value of a semaphore
  int value=0;
 if(sem_getvalue(&Charcoal, &value)==0)//This is going to work unless if the charcoal has not been set up 
 {/*-1 is the initial value when the restaurant is closed*/
 sem_post(&Charcoal);
 sem_post(&Charcoal);
 
 charc_chk=1;
 // printf("The charcoal's value is %d <----------\n ",value);
 }
      
 }
 // sem_wait(&raw_materials);
}


void *fuego()
{
// Is going to be ejecutated just once until the restaurant closes
sem_wait(&Charcoal);
printf("El empleado ha regulado el fuego y sera apagado hasta que el restaurante cierre, su PID es,%li \n",pthread_self());
printf(".... .... .... ....\n");
printf(" ... ... ... ...\n");
printf("  . . . . . . .\n");
printf("  火火火火火火火火 \n");
 int value=0;
 sem_getvalue(&Charcoal, &value);
//  printf("actual value of the charcoal %d\n",value);
 //We need to know what happens to that value in order to turn off the charcoal when the restarutant closes
}




int main()
{
 pthread_t h_puerta, h_local,thr_mercancia,thr_Charcoal,thr_cocina1,thr_cocina2,thr_cocina3,th_limpieza,th_mesero1,th_mesero2
 ,th_corte_caja,th_client,thr_check_if_the_preparations_are_done,th_client_BorA,th_bench_for_clients,th_dealing_with_orders,th_jarra;
 /* Inicializar semaforos */
 sem_init(&sem_for_orders,0,0);
 sem_init(&dormidos,0,0);
 sem_init(&cliente,0,1);
 sem_init(&puerta,0,0); //this should be initialized at -1, since our counter starts at 0
 sem_init(&local,0,0);//this should be initialized at -1, since our counter starts at 0
 sem_init(&raw_materials,0,0);
 sem_init(&Charcoal,0,0);
 sem_init(&cajas,0,0);
 sem_init(&bench_for_clients,0,0);
 sem_init(&meseros,0,0);
 sem_init(&mantenimiento,0,0);
 sem_init(&cocineros,0,0);
 sem_init(&jarra,0,0);
 //           antes -1 funcionaba bien  con el 0 inicializado en local no funciona, 
 // debe ser -1 osea wait, porque asumimos que esta cerrado pues nuestra cuenta inicia en las 0 horas

 /* Crear los procesos ligeros */
 pthread_create(&h_puerta,NULL,Everything_happens,NULL);
 pthread_create(&h_local,NULL,abrir,NULL);
 pthread_create(&th_dealing_with_orders,NULL,cooks_deal_with_orders,NULL);
 pthread_create(&thr_check_if_the_preparations_are_done,NULL,preparations_check,NULL);
 pthread_create(&th_bench_for_clients,NULL,spots_for_clients_came_earlier_than_expected,NULL);
  pthread_create(&th_jarra,NULL,spots_for_clients_came_earlier_than_expected,NULL);
 pthread_create(&thr_mercancia,NULL,The_employee_recieves_raw_materials_delivery_from_the_provider,NULL);
 pthread_create(&thr_Charcoal,NULL,fuego,NULL);
 pthread_create(&thr_cocina1,NULL,Cook,NULL);
 pthread_create(&thr_cocina2,NULL,Cook,NULL);
 pthread_create(&thr_cocina3,NULL,Cook,NULL);
 pthread_create(&th_limpieza,NULL,Clean,NULL);
 pthread_create(&th_corte_caja,NULL,Caja,NULL);
 pthread_create(&th_mesero1,NULL,Tomar_pedido,NULL);
 pthread_create(&th_mesero2,NULL,Tomar_pedido,NULL);
 pthread_create(&th_client,NULL,Clientes,NULL);
 
 /* Esperar su finalizacion */
 pthread_join(h_puerta,NULL);
 pthread_join(h_local,NULL);
 pthread_join(thr_mercancia,NULL);
 pthread_join(thr_Charcoal,NULL);
 pthread_join(thr_cocina1,NULL);
 pthread_join(thr_cocina2,NULL);
 pthread_join(thr_cocina3,NULL);
 pthread_join(th_limpieza,NULL);
 pthread_join(th_corte_caja,NULL);
 pthread_join(th_mesero1,NULL);
 pthread_join(th_mesero2,NULL);
 pthread_join(th_client,NULL);
 pthread_join(thr_mercancia,NULL);
 pthread_join(thr_check_if_the_preparations_are_done,NULL);
 pthread_join(th_dealing_with_orders,NULL);
 pthread_join(th_jarra,NULL);
 sem_destroy(&sem_for_orders);
 sem_destroy(&puerta);
 sem_destroy(&local);
 sem_destroy(&raw_materials);
 sem_destroy(&Charcoal);
 sem_destroy(&cocineros);
 sem_destroy(&meseros);
 sem_destroy(&mantenimiento);
 sem_destroy(&cajas);
 sem_destroy(&dormidos);
 sem_destroy(&bench_for_clients);
 sem_destroy(&cliente); 
 sem_destroy(&jarra);
 
 exit(0);
}
void abre_grafico()
{
printf("\n");
printf("___________________________\n");
printf("|  HAMBURGUESAS MONSTRUO  |\n");
printf("|         ABIERTO         |\n");
printf("|            B            |\n");
printf("|      _____________      |\n");
printf("|      |           |      |\n");
printf("|      |           |      |\n");
printf("|______|           |______|\n");
}

void cierra_grafico()
{
printf("\n");
printf("___________________________\n");
printf("|  HAMBURGUESAS MONSTRUO  |\n");
printf("|            B            |\n");
printf("|         CERRADO         |\n");
printf("|      _____________      |\n");
printf("|      |     |     |      |\n");
printf("|      |     |     |      |\n");
printf("|______|_____|_____|______|\n");
}
int moto=0;
void cortar(){
             signal (SIGINT,SIG_IGN);
             //printf("has pulsado CTRL-C\n");
             printf("\n%d",j);
             if(j==24)
            {       
              
              
              
                    signal(SIGINT,cortar);
                    // siginterrupt( );
                    alarm(1);
            }
//            j++;
             signal(SIGINT,cortar);

  //for(j=0;j<24;j++){
      sleep(1);
      if(j>=0&&j<=9){
        
  //printf("%d\n",j);
      printf("Son las 0%d:00 horas ",j);printf(" el restaurante esta cerrado\n");
      }else if(j>9&&j<=23)
    {
      pointer=0;
         printf("Son las %d:00 horas \n",j);
          if(j>10&&j<23)
          { 
            total_orders=0,llave_maestra=0;
            permiso=3; // si sube hora
            
           bandera_dormir=3;

           sem_post(&meseros);//////M
           sleep(1);
          //  bandera_dormir=3;
           sem_post(&meseros);//////           
           sleep(1);
          //  bandera_dormir=3;
           sem_post(&cocineros);//////
           sleep(1);
          //  bandera_dormir=3;
           sem_post(&cocineros);
           sleep(1);
          //  bandera_dormir=3;
           sem_post(&cocineros);
           sleep(1);
           
           bandera_dormir=0;

              
      // sem_wait(&dormidos);
            /**/
      //  sem_post(&cliente);     
      do{
    if(bandera_dormir==0)
    {
        
       sem_post(&dormidos);
      llave_maestra=1;
      sem_post(&cliente);     
      // sem_wait(&dormidos);
      printf("Dormidos\n");
      sleep(4);
       permiso_2=4;
       sem_post(&bench_for_clients);
       sem_post(&jarra);
       sleep(2);
      //  sem_post(&meseros);          //
      // orders_were_just_settled=4;   //
      // sleep(1);                     //
      // sem_wait(&meseros);           //
       sem_wait(&dormidos);
    }else
    {
      bandera_dormir=0;
      sleep(1);}
    }while (bandera_dormir!=0);
    

      //  sleep(4);
      //  permiso_2=4;
      //  sem_post(&bench_for_clients);
      //  sleep(2);
      
      // sleep(2);
          }


   if(j==10)
         {//the restautants are now available 
         llave_maestra=1;
   printf("Restaurante abre\n");
  //  sleep(2);
   sem_post(&local); //allows the local increments the semaphore
  //  sem_post(&puerta); //allows the door increments the semaphore
   sleep(2);
         }else if(j==23)
         {//the restarutants close
   printf("Restaurante cierra\n");
        sem_post(&local); //blocks the local
  int value;
  //sem_getvalue(&local, &value);

    // printf("The initial value of the semaphore is en if j=23 %d\n", value);
  //  sem_wait(&puerta); //blocks the door
  sem_wait(&Charcoal);
  The_fire_is_put_out();
  //printf("Las ganacias totales son %d que dan como resultado $%d de ganancia \n",profit,profit*precio_hamburguesa);
  sleep(2);

         }
        }
              j++;
     //}
}
void alarma()
{
    signal (SIGALRM, SIG_IGN);
    bucle=0;/*salir del bucle*/
    //printf("\nAlarma!!!!\n");
}
void The_fire_is_put_out()
{
printf("El fuego ha sido apagado\n");
printf("-    -       -       -    -\n"); 
printf("-    -       -       -    -\n"); 
printf(" -  -   -   -   -   -  -\n"); 
printf("   -   -   -   -   - \n"); 
printf("   - - - - - - - - -\n"); 
printf("   - - - - - - - - -\n"); 
printf("   -----------------\n");
}
int i=0;
int counter=0;
void*Cook()
{
  while(1){
  sem_wait(&cocineros);
  if(bandera_dormir==3)
        {
          printf(" El cocinero de PID %li esta dormido \n",pthread_self());
          sleep(1);
          //sem_wait(&cocineros);
        }else if(bandera_dormir==0)
        {
        //   bandera_dormir=0;
        // }
  if(visualize_the_cooks_working==2){
  printf("El cocinero %ld esta preparando ordenes...\n", pthread_self());  
  visualize_the_cooks_working=0;
  }else if(visualize_the_cooks_working==0){
  printf("El cocinero %ld esta listo para recibir las ordenes...\n", pthread_self());
                  if(counter==0)
                  {
                  //several_cooks[counter]=pthread_self();
                  cocin1_chk=1;
                  several_cooks[counter]=cocin1_chk;
                  // printf(" cooks %d %i\n",several_cooks[counter],counter);    

                  }else if(counter==1)
                  {
                  //several_cooks[counter]=pthread_self();
                  cocin2_chk=1;
                  several_cooks[counter]=cocin2_chk;
                  // printf(" cooks %d %i\n",several_cooks[counter],counter);    
                  }else if(counter==2)
                  {
                  //several_cooks[counter]=pthread_self();
                  cocin3_chk=1;
                  several_cooks[counter]=cocin3_chk;
                  // printf(" cooks %d %i\n",several_cooks[counter],counter);    
                  }
                  sem_post(&sem_for_orders);
                  permiso_ordenes=2;
            //this array might contain 1's on every cell

 counter++;
  }
     //bandera_dormir=0;
        }
  }
}

void*Clean(){
      sem_wait(&mantenimiento);
      
      printf("El empleado %li esta haciendo la limpieza\n",pthread_self());
      sleep(2);
      printf("El local esta limpio y listo para recibir a los clientes\n");
      mant_chk=1;
}
void*Caja(){
      sem_wait(&cajas);
      printf("Ya esta lista la caja soy el empledo de PID %li \n",pthread_self());
      caj_chk=1;
      //sleep(5);
      //printf("El empleado %i cobrara el total de su compra\n",pthread_self());
}

// int counter_waiters=0,bandera_dormir=0,bandera_dormir_2=0;
void*Tomar_pedido(){
      // sem_wait(&meseros);
      
       while(1)
      {
        if(bandera_dormir==3)
        {
          // printf("looo meseros\n");
          printf(" El mesero de PID %ld esta dormido \n",pthread_self());
          sleep(1);
          // sem_wait(&meseros);
        }else if(bandera_dormir==0)
        {
      if(counter_waiters==0)
                  {
                  //several_cooks[counter]=pthread_self();
                  mese1_chk=1;
                  several_waiters[counter_waiters]=mese1_chk;
                  // printf(" waiters %d %i\n",several_waiters[counter_waiters],counter_waiters);    
                  counter_waiters=1;
                  }
                  else if(counter_waiters==1)
                  {
                  //several_cooks[counter]=pthread_self();
                  mese2_chk=1;
                  several_waiters[counter_waiters]=mese2_chk;
                  // printf(" waiters %d %i\n",several_cooks[counter_waiters],counter_waiters);    
                  counter_waiters=1;
                  }
                  if(llave_para_mesero_principal==1)
                  {
                  printf("El mesero %li esta listo para tomar las ordenes...\n", pthread_self());
                  llave_para_mesero_principal=0;
                  }
        if(flag_orders==1)
        {
          sem_wait(&meseros);
          if(pointer==randomly_generated_clients){
            printf("El mesero %li entrega las %d ordenes al cliente %d (ULTIMO CLIENTE DE LA FILA)...[ENTREGA]\n", pthread_self(),orders[pointer-1],pointer);
          }else if(pointer==1){
            printf("El mesero %li entrega las %d ordenes al cliente %d (PRIMER CLIENTE DE LA FILA)...[ENTREGA]\n", pthread_self(),orders[pointer-1],pointer);
          }
          else
          {
          printf("El mesero %li entrega las %d ordenes al cliente %d...        [ENTREGA]\n", pthread_self(),orders[pointer-1],pointer);
          }
          flag_orders=0;
          sleep(1);
        }
        }
        if(orders_were_just_settled==4){
          printf("El mesero %li las va por las %d ordenes de todos los clientes ...     [VA POR ORDENES]\n", pthread_self(),total_orders);
          orders_were_just_settled=0;
        }
        //sem_wait(&dormidos);
        // sem_wait(&dormidos);
        // if(bandera_dormir==3)
        // {
        //   printf(" El mesero de PID %ld esta dormido \n",pthread_self());
        //   sleep(1);
        //   bandera_dormir=0;
        //   //sem_wait(&meseros);
        // }
        // sem_post(&dormidos);
       }
       pthread_exit(0);
}

void*Clientes(){
  // clientes_afterorbefore=srand(time(NULL));
  // clientes_afterorbefore=rand()%100+1; //the clients come earlier
  clientes_afterorbefore=rand()%100; //the clients come later
  if(clientes_afterorbefore%2==1){
  	clientes_afterorbefore_decision=1;
  }else if(clientes_afterorbefore%2==0){
  	clientes_afterorbefore_decision=2;
  }
  while(1)
  {
  if(permiso==3&&llave_maestra!=0)
  {
   sem_wait(&cliente);
   //printf("Valor de permiso= %d\n",permiso);
   randomly_generated_clients=rand()%20;
   printf("Han llegado %d clientes\n",randomly_generated_clients);
   for(int i=0;i<randomly_generated_clients;i++)
   {
      randomly_generated_amount_of_orders=rand()%10+1;
      orders[i]=randomly_generated_amount_of_orders;
      printf("El cliente numero %d hace %d ordenes\n",i+1,orders[i]);
      total_orders=total_orders+orders[i];
      profit=profit+orders[i];
   }
  

  // sem_post(&meseros);
  // orders_were_just_settled=4;
  // sleep(1);
  // sem_wait(&meseros);
  

    
    sem_post(&bench_for_clients);
    sem_post(&jarra);
    // sleep(2);
   permiso=0;
   }
  }  
}
void abandonaded_function(){
//   int raw_mat_chk=0,cocin1_chk=0,cocin2_chk=0,cocin3_chk=0,mese1_chk=0,mese2_chk=0,caj_chk=0,mant_chk=0,charc_chk=0;
//   sem_getvalue(&raw_materials, &raw_mat_chk);
//   sem_getvalue(&cocineros, &cocin1_chk);
//   sem_getvalue(&cocineros, &cocin2_chk);
//   sem_getvalue(&cocineros, &cocin3_chk);
//   sem_getvalue(&meseros, &mese1_chk);  
//   sem_getvalue(&meseros, &mese2_chk);  
//   sem_getvalue(+&cajas, &caj_chk);  
//   sem_getvalue(&mantenimiento,&mant_chk);  
//   printf("raw %d\n",raw_mat_chk);
//   printf("cocin %d\n",cocin1_chk);
//   printf("cocin %d\n",cocin2_chk);
//   printf("cocin %d\n",cocin3_chk);
//   printf("mese %d\n",mese1_chk);
//   printf("mese %d\n",mese2_chk);
//   printf("caja %d\n",caj_chk);
//   printf("manten %d\n",mant_chk); 
}
int check_value=0;
void*preparations_check()
{  //this function has to work with a while condition until a semaphore changes into another value
      
  while(1)
  {
      if(raw_mat_chk==1&&cocin1_chk==1&&cocin2_chk==1&&cocin3_chk==1&&mese1_chk==1&&mese2_chk==1&&caj_chk==1&&mant_chk==1&&charc_chk==1&&check_value==0)
      {
      printf("\n Los preparativos estan listos, los clientes pueden pasar\n");
      sem_post(&meseros);
      orders_were_just_settled=4;
      sleep(1);
      sem_wait(&meseros);
      check_value=1;
      }
  }
}

void*spots_for_clients_came_earlier_than_expected()
{
 sem_wait(&bench_for_clients);
 sem_wait(&jarra);
 while(1){
  if(permiso_2==4){
  if(randomly_generated_clients==5)
 {
  printf("Matriz sillas son 5 clientes\n");
 for(int i=0;i<5;i++)
 {
 spots_for_clients_has_came[i]=1;
printf("Silla numero %d tiene %d cliente sentado y tomo el Vaso %d\n",i,spots_for_clients_has_came[i],i);
 printf("Y el cliente que esta en la silla numero %d agarra la jarra y sirve agua en su vaso y la pasa...\n",i);
 printf(" _____\n");
 printf(" |~~~~ |  / / ....\n");
 printf(" |~~~~ | / /......\n");
 printf(" |~~~~ |/ /.......\n");
 printf(" |~~~~ |........\n");
 printf(" |~~~~ |........\n");
 printf(" |~~~~ |........\n");
 printf(" |~~~~ |........\n");
 printf(" |~~~~ |........\n");
 printf(" |_____|........\n");
 printf("  -JARRA-\n");
 permiso_2=0;
 }
 }
 else if(randomly_generated_clients<5)
 {
  printf("Matriz sillas son menos de 5 clientes\n");
 for(int i=0;i<randomly_generated_clients;i++){
 spots_for_clients_has_came[i]=1;
 printf("Silla numero %d tiene %d cliente sentado y tomo el Vaso %d\n",i,spots_for_clients_has_came[i],i);
 printf("Y el cliente que esta en la silla numero %d agarra la jarra y sirve agua en su vaso y la pasa...\n",i);
 printf(" _____\n");
 printf(" |~~~~ |  / / ....\n");
 printf(" |~~~~ | / /......\n");
 printf(" |~~~~ |/ /.......\n");
 printf(" |~~~~ |........\n");
 printf(" |~~~~ |........\n");
 printf(" |~~~~ |........\n");
 printf(" |~~~~ |........\n");
 printf(" |~~~~ |........\n");
 printf(" |_____|........\n");
 printf("  -JARRA-\n");
 permiso_2=0;
 }
 }
 else if(randomly_generated_clients>5)
 {
  printf("Matriz sillas son mas de 5 clientes\n");
  printf("SE CUMPLE QUE LAS SILLAS NO ALCANZAN\n");
  for(int i=0;i<5;i++)
  {
  spots_for_clients_has_came[i]=1;
 printf("Silla numero %d tiene %d cliente sentado y tomo el Vaso %d\n",i,spots_for_clients_has_came[i],i);
 printf("Y el cliente que esta en la silla numero %d agarra la jarra y sirve agua en su vaso y la pasa...\n",i);
 printf(" _____\n");
 printf(" |~~~~ |  / / ....\n");
 printf(" |~~~~ | / /......\n");
 printf(" |~~~~ |/ /.......\n");
 printf(" |~~~~ |........\n");
 printf(" |~~~~ |........\n");
 printf(" |~~~~ |........\n");
 printf(" |~~~~ |........\n");
 printf(" |~~~~ |........\n");
 printf(" |_____|........\n");
 printf("  -JARRA-\n");
 }
 printf("Hay formados %d clientes\n",randomly_generated_clients-5);
 permiso_2=0;
 }
  }
 }
}

void* cooks_deal_with_orders()
{
  sem_wait(&sem_for_orders);
 while(1) 
 {
  if(permiso_ordenes==2&&check_value==1&&mant_chk==1){
  printf("Los cocineros estan preparando las ordenes        [EMPIEZA PREPARACION]\n");
  //the clients as well as the emplooyes have to be paused until the orders are zero
  // for(int i =0;i<total_orders/3;i++)
  // {
      // if(total_orders%1==0){
        do{
          
          if(total_orders==3||total_orders>3){


            // total_orders=total_orders-3;//this is the right way
      printf("Hay %d ordenes, se van a preparar 3 de ellas \n",total_orders);
      if(j>10||j<23){
 sem_post(&meseros);
      orders_were_just_settled=4;
      sleep(1);
      sem_wait(&meseros);
      }
      visualize_the_cooks_working=2;
      sem_post(&cocineros);
      times_the_waiters=times_the_waiters+1;
      if(times_the_waiters==orders[pointer]){
        flag_orders=1;
        sem_post(&meseros);
        
        pointer=pointer+1;
        times_the_waiters=0;
      }
      visualize_the_cooks_working=2;
      sem_post(&cocineros);
      times_the_waiters=times_the_waiters+1;
      if(times_the_waiters==orders[pointer]){
        flag_orders=1;
        sem_post(&meseros);
        
        pointer=pointer+1;
        times_the_waiters=0;
      }
      visualize_the_cooks_working=2;
      sem_post(&cocineros);
      times_the_waiters=times_the_waiters+1;
      if(times_the_waiters==orders[pointer]){
        flag_orders=1;
        sem_post(&meseros);
        
        pointer=pointer+1;
        times_the_waiters=0;
      }
      total_orders=total_orders-3;//this is the right way
      sleep(1);
      printf("Quedan %d ordenes pendientes\n",total_orders);
      printf("__________________________________________________\n");
      // total_orders=total_orders-3;
      // llave_veces_ordenes==0;
      sleep(1);
      if(total_orders<3&&total_orders>0){
            if(total_orders==2){
            //llave_veces_ordenes=1;
            // printf("Las ordenes restantes son %d\n",total_orders);
            printf("Quedan %d ordenes pendientes \n",total_orders);
            visualize_the_cooks_working=2;
            sem_post(&cocineros);
            times_the_waiters=times_the_waiters+1;
            if(times_the_waiters==orders[pointer]){
        flag_orders=1;
        sem_post(&meseros);
        
        pointer=pointer+1;
        times_the_waiters=0;
      }
            visualize_the_cooks_working=2;
            sem_post(&cocineros);
            times_the_waiters=times_the_waiters+1;
            if(times_the_waiters==orders[pointer]){
            flag_orders=1;
            sem_post(&meseros);
            pointer=pointer+1;
            times_the_waiters=0;
            sleep(1);
            }
            flag_orders=0;
            sleep(1);
            printf("Todas las ordenes han sido terminadas \n");
            }
            else if(total_orders==1)
            {
            printf("Queda %d orden pendiente \n",total_orders);
            visualize_the_cooks_working=2;
            times_the_waiters=times_the_waiters+1;
            if(times_the_waiters==orders[pointer])
            {
            sleep(1);
            flag_orders=1;
            sem_post(&meseros);
            // sleep(1);
            pointer=pointer+1;
            times_the_waiters=0;
            sleep(1);
            }
            flag_orders=0;
            sem_post(&cocineros);
            sleep(1);
            printf("Todas las ordenes han sido terminadas \n");
            }
            // if(total_orders==0){
            //   llave_veces_ordenes=1;
            // printf("Todas las ordenes han sido terminadas \n");
            // }
          }
          }
      }while(llave_veces_ordenes==0);
      // if(total_orders>0){
      // sleep(1);
      printf("Las ordenes restantes son %d\n",total_orders);
  printf("Quedan %d ordenes pendientes \n",total_orders);
  permiso_ordenes=0;
      // }
  }
 }
}
void*clien(){
   struct sockaddr_in direcciónServidor;
	direcciónServidor.sin_family = AF_INET;
	direcciónServidor.sin_addr.s_addr = inet_addr("10.0.2.15");
	direcciónServidor.sin_port = htons(8080);

	int cliente = socket(AF_INET, SOCK_STREAM, 0);
	if (connect(cliente, (void*) &direcciónServidor, sizeof(direcciónServidor)) != 0) {
		perror("No se pudo conectar");
		return 1;
	}
       
	//while (1) {
	char mensaje[10];
        time_t tiemponow;
        time(&tiemponow);
        //sprintf(total_mandar,"%u",num);
        printf("|----------------------------------------------------------------------------------------|\n");
        printf("|                                                                                        |\n");
        printf("|----------------------HAMBURGUESAS MOUNSTRO SUCURSAL B----------------------------------|\n");
        printf("|----------------------------------------------------------------------------------------|\n");
        printf("Las ganacias totales de la sucursal B son %d que dan como resultado $%d de ganancia |\n",profit,profit*precio_hamburguesa);
        printf("|MANDO MI CANTIDAD DE INGRESOS TOTALES DEL DIA DE HOY QUE ES:%d                          |\n",profit*precio_hamburguesa);
        printf("|-------------------------------------------------------%s\n",ctime(&tiemponow));
        printf("|Confirma la cifra manualmente por favor: %s", mensaje);		
		scanf("%s", mensaje);
        printf("|----------------------------------------------------------------------------------------|\n");
		send(cliente, mensaje, strlen(mensaje), 0);
       // send(cliente,(char*)&num, sizeof(num),0);
	//}
}

