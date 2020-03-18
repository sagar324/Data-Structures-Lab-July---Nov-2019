#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct process{
       double priority;
       double arrtime;
       int burst;
};
struct process array[201];
int rdque[201];
int size=0;
void printpre(int index){
    printf("%d ",rdque[index]);
    int x,y;
    x=2*index;
    y=x+1;
    if(x<=size&&y<=size){
        printpre(x);
        printpre(y);
        return;
    }
    else if(x==size){
        printpre(x);
        return;
    }
    else{
        return;
    }
}
void percolateup(int index){
    int pindex;
    pindex=index/2;
    int x,y;
    x=rdque[pindex];
    y=rdque[index];
        if(array[x].priority<array[y].priority){
            return;
        }
        else if(array[x].priority>array[y].priority){
            int temp;
            temp=rdque[pindex];
            rdque[pindex]=rdque[index];
            rdque[index]=temp;
            if(pindex!=1){
                percolateup(pindex);
            }
            return;
        }
        else{
            return;
        }
}
void percolatedown(int index,int val){
    int c1,c2,z;
    c1=2*index;c2=c1+1;z=val;
    if(c1<=size&&c2<=size){
        int x,y;
        x=rdque[c1];y=rdque[c2];
        if(array[x].priority<array[y].priority){
            if(array[x].priority<array[z].priority){
               rdque[index]=rdque[c1];
               rdque[c1]=z;  
               percolatedown(c1,val);  
            }
            return;            
        }
        else if(array[x].priority>array[y].priority){
            if(array[y].priority<array[z].priority){
               rdque[index]=rdque[c2];
               rdque[c2]=z; 
               percolatedown(c2,val);
            }
            return;
        }
        else{
            return;    
        }
    }
    else if(c1==size){
        int x;
        x=rdque[c1];
        if(array[x].priority<array[z].priority){
            rdque[index]=rdque[c1];
            rdque[c1]=z;
            percolatedown(c1,val);
        }
        return;
    }
    else{
        return;
    }
    return;
}
void pushtoq(int e){
    rdque[size+1]=e;
    size++;
    if (size!=1){
        percolateup(size);
    }  
    return;
}
int  poptop(){
    printpre(1);
    printf("\n");
    int z,p;
    z=rdque[1];
    p=rdque[size];
    rdque[1]=p;
    if(size!=1){
        percolatedown(1,p);
    }
    else{
        rdque[1]=0;
    }
    size=size-1;
    return z;
}
int  findnumproc(int stindex,int time){
    int n=0,i=stindex;   
    while(array[i].arrtime==time){
        n++;
        i++;
    }
    return n;
       
}
int main() {
    int exec=1,i,j=0,N,t=0,start=2,end,temp,numop,pnum=0;
    int timecum[10000];
    int time[201];
    int proc[1000000];
    scanf("%d",&N);
    for(i=1;i<=N;i++){
        scanf("%d",&temp);
        scanf("%lf",&array[i].priority);
        scanf("%lf",&array[i].arrtime);
        scanf("%d",&array[i].burst);
        array[i].priority=array[i].priority+(array[i].arrtime/100000000);
    }
    for(t=0;t<=100000000;t++){
        numop=findnumproc(start,t);
        if (numop==0){
            if(exec!=0&&time[exec]!=array[exec].burst){
                time[exec]++;
                //continue;
            }
            else if(exec!=0&&time[exec]==array[exec].burst){
                timecum[j]=t;
                j++;
                if(size!=0){
                    proc[pnum]=exec;
                    pnum++;
                    exec=poptop();
                    time[exec]++;                  
                    //continue;
                }
                else{//check whether if it is last process or not;
                    if(start>N){
                        proc[pnum]=exec;
                        pnum++;
                    }
                    exec=0;
                   // continue;
                }
            }
            else{
                exec=0;
                //continue;
            }
        }
        else{
            if(exec!=0&&time[exec]!=array[exec].burst){
                  temp=exec;
                  end=start+numop-1;
                  for(i=start;i<=end;i++){
                      if(array[exec].priority>array[i].priority){
                          pushtoq(exec);
                          exec=i;
                      }
                      else{
                          pushtoq(i);
                      }
                  }
                  if(temp!=exec){
                      timecum[j]=t;
                      j++;
                      proc[pnum]=temp;
                      pnum++;
                  }
                  time[exec]++;
                  //continue;
            }
            else if(exec!=0&&time[exec]==array[exec].burst){
                 timecum[j]=t;
                 j++;
                 proc[pnum]=exec;
                 pnum++;
                 end=start+numop-1;
                 if(size!=0){
                     exec=poptop();
                     for(i=start;i<=end;i++){
                         if(array[exec].priority>array[i].priority){
                             pushtoq(exec);
                             exec=i;
                         }
                         else{
                             pushtoq(i);
                         }
                     }
                  time[exec]++;
                  //continue;
                 }
                 else{
                     exec=start;
                     for(i=start+1;i<=end;i++){
                         if(array[exec].priority>array[i].priority){
                             pushtoq(exec);
                             exec=i;
                         }
                         else{
                             pushtoq(i);
                         }
                     }
                  time[exec]++;
                 // continue;
                 }                  
            }
            else{//exec=0 already implies heap is empty
                 exec=start;
                 end=start+numop-1;
                 
                 for(i=start+1;i<=end;i++){
                         if(array[exec].priority>array[i].priority){
                             pushtoq(exec);
                             exec=i;
                         }
                         else{
                             pushtoq(i);
                         }
                 }
                 
                 time[exec]++;
                 //continue;
            }
            start=end+1;
        }
        if(exec==0&&size==0&&start==N+1){
            break;
        }           
    } 
    
    for(i=0;proc[i]!=0;i++){
        printf("%d ",proc[i]);
    }
    printf("\n");
    for(i=0;timecum[i]!=0;i++){
        printf("%d ",timecum[i]);
    }
    return 0;
    
}
