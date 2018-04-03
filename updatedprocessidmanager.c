#include<stdio.h>
#include<unistd.h>
#define MIN_PID 100
#define MAX_PID 1000
#define A_SIZE MAX_PID-MIN_PID+1
int pid_status[A_SIZE];
int allocate_map(){
int i;
for(i=0;i<A_SIZE;i++){
pid_status[i]=0;
}
return 0;
}
int allocate_pid(){
int i;
for(i=0;i<A_SIZE;i++){
if(pid_status[i]==0){
pid_status[i]=1;
return i+100;
}
}
return 1;
}
void release_pid(int pid){
int p=pid-100;
pid_status[i]=0;
}
void display(){
int i;
for(int i=0;i<A_SIZE;i++){
printf("[%d]= %d\t",i+100,pid_status[i]);
}
}
int main(){
allocate_map();
printf("after allocation of the status");
display();
int pid1=allocate_pid();
printf("Allocated pid:%d\n",pid1);
printf(""After allocate_pid()\n");
display();
release_pid(pid1);
printf("After release_pid()\n");
display();
}

int main()
{	
	allocate_map();
	printf("\nAfter allocate_map()");
	display();
	int pid1 = allocate_pid();
	printf("Allocated pid: %d\n",pid1);
	printf("After allocate_pid()\n");
	display();
	release_pid(pid1);
	printf("After release_pid()\n");
	display();
	printf("Program run successfully...\n");
	return 0;
}
