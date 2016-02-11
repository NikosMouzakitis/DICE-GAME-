  #include <stdio.h>
  #include <stdlib.h>
  #include <time.h>
  #include <pthread.h>
 
 
  char quit;
  void *fn(void *param)
  {
 
          int *tp = (int *) param;
          int play_time = (rand() % 20) +3 ;
          sleep(play_time) ;
          printf("You exit with cash: %d$",*tp);
          exit(1);
  }
  int main()
  {
          int z1,z2,score1 = 0,score2 = 0,cash=5;
          pthread_t tid;
          pthread_create(&tid, NULL, fn,&cash);
          srand(time(NULL));
          printf("-------------Playing dice against Bob!!!!.------------\n");
 
          while(cash > 0 && !quit) {
                  z1 = rand()%7;
                  z2 = rand()%7;
                  printf("-----------------------------------\n---------------------------\n");
                  printf("\tYOU : %d ----- %d BOB  \n",z1,z2);
 
                  if(z1 > z2) {
 
                          printf("\tyou win !\n") ;
                          cash +=1;
                          printf("\tCash : %d\n",cash);
                  }
                  else if(z1 <z2 ){
                          printf("\tyou lose!\n");
                          cash -=1;
                          printf("\tCash: %d\n",cash);
                  }
                  else{
                          printf("\tPush !\n") ;
                  }
                  printf("-----------------------------------------\n\n");
                  sleep(1);
          }
          pthread_join(tid, NULL);
          return (0);
  }