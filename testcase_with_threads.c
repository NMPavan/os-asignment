#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<pthread.h>
#define MIN_PID 100
#define MAX_PID 1000
#define ARR_SIZE MAX_PID-MIN_PID+1
int pid_position[ARR_SIZE];

int allocate_map(){                   //creates and initializes a datastructure for representing pids
int i;
for(i=0;i<ARR_SIZE;i++){
pid_position[i]=0;                    //initializing pid statuses
}
}
int allocate_pid(){

int i;

for(i=0;i<ARR_SIZE;i++){              //allocates and return a pid

if(pid_position[i]==0)                //checking for free pid{

pid_position[i]=1;                    //changing pid status of pid

return i+100;                         //returning pid
    }
  }
}

int pid_verify(int pid){

if(pid>=100){                         //here in this function checking whether the pid is assigned or not.

printf("\n pid %d id assigned \n",pid);

return 0;                            //it is indicate pid is set to be free

}
else{

printf("id allocation is not allowed"); //here in this id can't be allocated because here pid pid_position is 1

return 1;
}
}
void display()
{
	printf("\n[0] = %d\n",pid_position[0]);
}
int sleeptime()
{
return rand()%5;                          //giving sleep time in range 0-5 secs.
}
void *thread_fun(void *pro)               //In each thread, this body of code executes.
{
struct prog *p = (struct proc *) pro;

printf("\n%d: Fetching pid...\n",p->number);

p->pid = allocate_pid();                               //fetching pid

while(pid_check(p->pid)==1)                            //until pid is assigned, this loop will run.
{
  sleep(5);                                            //for every loop or again asking for pid, it sleeps for 5 secs.
  printf("\n%d: Fetching pid...\n",p->number);
  p->pid = allocate_pid();                             //trying to fetch pid once more.
}
display();

p->sleep_time = sleeptime();                      //setting of sleep time for every process or thread.

printf("\n%d: pid = %d,sl_time = %d\n",p->number,p->pid,p->sleep_time);

printf("\n%d - %d: Entered Sleep time\n",p->number,p->pid);

sleep(p->sleep_time);                                  //every thread sleep for its allocated time.

printf("\n%d - %d: Exited Sleep time\n",p->number,p->pid);

release_pid(p->pid);                                   //after sleep time completes, every thread releases its pid.

display();
}
void release_pid(pid)                                 //releases a pid
{
pid_position[pid]=0;                                 //taking pid from passed parameter.
	                                                   //changing pid status.
	return 0;		                                       //return status 0 to representing success.
}
}
struct prog{
  int number;
  int pid;
  int sleep_time;
};
int main()
{
	int i, no_of_threads;
  
  printf("Enter no of threads: ");
  
  scanf("%d",&no_of_threads);                       //getting no of threads from user input.
  
  printf("program getting stared\n");
	
  struct prog pro[no_of_threads];                  //creating process structures of the number given by user.
  
  
  pthread_t pro_threads[no_of_threads];            //creating threads references of number given by user.
  
  for(i=0;i<no_of_threads;i++)
  {
  
  pr[i].number = i;                                //giving every structure its serial number, starting from 0.
  
  pthread_create(&pr_threads[i],NULL,&thread_fun,&pr[i]);    
                                                   //creating threads with function associated with every thread.
  }

  for(i=0;i<no_of_threads;i++)
  {
    pthread_join(pr_threads[i],NULL);             //waiting for every thread to get execute.
  }
}
