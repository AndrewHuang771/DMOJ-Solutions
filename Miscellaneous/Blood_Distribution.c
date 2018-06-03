#include <stdio.h>

//Written by Andrew Huang some time ago.
//This problem is basically hard code, though it is technically a greedy algorithm

int main(void) {
  int donations[8],inNeed[8],i=0,j=0,h=0,happyPeople=0;
  for(i=0;i<8;i++){
    scanf("%d",&donations[i]);
  }
  for(j=0;j<8;j++){
    scanf("%d",&inNeed[j]);
  }
  
  //Processing O- people. They can only accept O- blood, so they get first dibs.
  if(donations[0]<inNeed[0] && inNeed[0]!=0){
    inNeed[0]-=donations[0];
    happyPeople+=donations[0];
    donations[0]=0;
  }
  else if(donations[0]>=inNeed[0] && inNeed[0]!=0){
    donations[0]-=inNeed[0];
    happyPeople+=inNeed[0];
    inNeed[0]=0;
  }
  
  //Next, A- blood goes to A- people.
  if(donations[2]<inNeed[2] && inNeed[2]!=0){
    inNeed[2]-=donations[2];
    happyPeople+=donations[2];
    donations[2]=0;
  }
  else if(donations[2]>=inNeed[2] && inNeed[2]!=0){
    donations[2]-=inNeed[2];
    happyPeople+=inNeed[2];
    inNeed[2]=0;
  }
  
  //Next, B- blood goes to B- people.
  if(donations[4]<inNeed[4] && inNeed[4]!=0){
    inNeed[4]-=donations[4];
    happyPeople+=donations[4];
    donations[4]=0;
  }
  else if(donations[4]>=inNeed[4] && inNeed[4]!=0){
    donations[4]-=inNeed[4];
    happyPeople+=inNeed[4];
    inNeed[4]=0;
  }
  
  //Next, AB- blood gpes to AB- people
  if(donations[6]<inNeed[6] && inNeed[6]!=0){
    inNeed[6]-=donations[6];
    happyPeople+=donations[6];
    donations[6]=0;
  }
  else if(donations[6]>=inNeed[6] && inNeed[6]!=0){
    donations[6]-=inNeed[6];
    happyPeople+=inNeed[6];
    inNeed[6]=0;
  }
  
  //O+ blood given to O+ people
  if(inNeed[1]!=0 && donations[1]>inNeed[1]){
    donations[1]-=inNeed[1];
    happyPeople+=inNeed[1];
    inNeed[1]=0;
  }
  else if(inNeed[1]!=0 && donations[1]<=inNeed[1]){
    inNeed[1]-=donations[1];
    happyPeople+=donations[1];
    donations[1]=0;
  }
  
  //A+ people get A+ blood
  if(inNeed[3]!=0 && donations[3]>inNeed[3]){
    donations[3]-=inNeed[3];
    happyPeople+=inNeed[3];
    inNeed[3]=0;
  }
  else if(inNeed[3]!=0 && donations[3]<=inNeed[3]){
    inNeed[3]-=donations[3];
    happyPeople+=donations[3];
    donations[3]=0;
  }
  
  //B+ people get B+ blood
  if(inNeed[5]!=0 && donations[5]>inNeed[5]){
    donations[5]-=inNeed[5];
    happyPeople+=inNeed[5];
    inNeed[5]=0;
  }
  else if(inNeed[5]!=0 && donations[5]<=inNeed[5]){
    inNeed[5]-=donations[5];
    happyPeople+=donations[5];
    donations[5]=0;
  }
  
  //If there's any left, A+ people get A- blood;
  if(donations[2]!=0){
    if(inNeed[3]!=0 && inNeed[3]>=donations[2]){
      inNeed[3]-=donations[2];
      happyPeople+=donations[2];
      donations[2]=0;
    }
    else if(inNeed[3]!=0 && inNeed[3]<donations[2]){
      donations[2]-=inNeed[3];
      happyPeople+=inNeed[3];
      inNeed[3]=0;
      //The leftover blood goes to AB- people
    }
  }
  if(donations[2]!=0 && inNeed[6]!=0){
    if(donations[2]>inNeed[6]){
      donations[2]-=inNeed[6];
      happyPeople+=inNeed[6];
      inNeed[6]=0;
    }
    else if(donations[2]<=inNeed[6]){
      inNeed[6]-=donations[2];
      happyPeople+=donations[2];
      donations[2]=0;
    }
  }
  
  
   //If there's any left, B+ people get B- blood;
  if(donations[4]!=0){
    if(inNeed[5]!=0 && inNeed[5]>=donations[4]){
      inNeed[5]-=donations[4];
      happyPeople+=donations[4];
      donations[4]=0;
    }
    else if(inNeed[5]!=0 && inNeed[5]<donations[4]){
      donations[4]-=inNeed[5];
      happyPeople+=inNeed[5];
      inNeed[5]=0;
      //The leftover blood goes to AB- people
    }
  }
      
  if(donations[4]!=0 && inNeed[6]!=0){
      if(donations[4]>inNeed[6]){
      donations[4]-=inNeed[6];
      happyPeople+=inNeed[6];
      inNeed[6]=0;
    }
    else if(donations[4]<=inNeed[6]){
      inNeed[6]-=donations[4];
      happyPeople+=donations[4];
      donations[4]=0;
    }
  }
      
    
  
  //Next, leftover O- blood (if any) goes to O+ people
  if(donations[0]>0){
    if(inNeed[1]!=0 && inNeed[1]>=donations[0]){
      inNeed[1]-=donations[0];
      happyPeople+=donations[0];
      donations[0]=0;
    }
    else if(inNeed[1]!=0 && inNeed[1]<=donations[0]){
      donations[0]-=inNeed[1];
      happyPeople+=inNeed[1];
      inNeed[1]=0;
    }
  }
  if(donations[0]>0){
      //Next, if there is any left, the O- blood goes to the A- people
    if(inNeed[2]!=0 && inNeed[2]>=donations[0]){
      inNeed[2]-=donations[0];
      happyPeople+=donations[0];
      donations[0]=0;
    }
    else if(inNeed[2]!=0 && inNeed[2]<=donations[0]){
      donations[0]-=inNeed[2];
      happyPeople+=inNeed[2];
      inNeed[2]=0;
    }  
  }
  if(donations[0]>0){
    //Next, if there is any left, the O- blood goes to the B- people    
    if(inNeed[4]!=0 && inNeed[4]>=donations[0]){
      inNeed[4]-=donations[0];
      happyPeople+=donations[0];
      donations[0]=0;
    }
    else if(inNeed[4]!=0 && inNeed[4]<=donations[0]){
      donations[0]-=inNeed[4];
      happyPeople+=inNeed[4];
      inNeed[4]=0;
    }
  }
  if(donations[0]>0){    
  //Next, if there is any left, the O- blood goes to the AB- people
    if(inNeed[6]!=0 && inNeed[6]>donations[0]){
      inNeed[6]-=donations[0];
      happyPeople+=donations[0];
      donations[0]=0;
    }
    else if(inNeed[6]!=0 && inNeed[6]<=donations[0]){
      donations[0]-=inNeed[6];
      happyPeople+=inNeed[6];
      inNeed[6]=0;
    }
  }
  if(donations[0]>0){
  //Next, if there is any left, the O- blood goes to the A+ people
    if(inNeed[3]!=0 && inNeed[3]>=donations[0]){
      inNeed[3]-=donations[0];
      happyPeople+=donations[0];
      donations[0]=0;
    }
    else if(inNeed[3]!=0 && inNeed[3]<donations[0]){
      donations[0]-=inNeed[3];
      happyPeople+=inNeed[3];
      inNeed[3]=0;
    }
  }
  if(donations[0]>0){
  //Next, if there is any left, the O- blood goes to the B+ people
    if(inNeed[5]!=0 && inNeed[5]>=donations[0]){
      inNeed[5]-=donations[0];
      happyPeople+=donations[0];
      donations[0]=0;
    }
    else if(inNeed[5]!=0 && inNeed[5]<=donations[0]){
      donations[0]-=inNeed[5];
      happyPeople+=inNeed[5];
      inNeed[5]=0;
    }
  }
  //O+ blood to A+ and B+!!!!
  
  if(donations[1]>0 && inNeed[3]>0){
    if(inNeed[3]>donations[1]){
      inNeed[3]-=donations[1];
      happyPeople+=donations[1];
      donations[1]=0;
    }
    else if(inNeed[3]<=donations[1]){
      donations[1]-=inNeed[3];
      happyPeople+=inNeed[3];
      inNeed[3]=0;
    }
  }
  
  if(donations[1]>0 && inNeed[5]>0){
    if(inNeed[5]>donations[1]){
      inNeed[5]-=donations[1];
      happyPeople+=donations[1];
      donations[1]=0;
    }
    else if(inNeed[5]<=donations[1]){
      donations[1]-=inNeed[5];
      happyPeople+=inNeed[5];
      inNeed[5]=0;
    }
  }

  for(h=0;h<8;h++){
    if(inNeed[7]>0){  
      if(donations[h]>0 && donations[h]>inNeed[7]){
        donations[h]-=inNeed[7];
        happyPeople+=inNeed[7];
        inNeed[7]=0;
      }
      else if(donations[h]>0 && donations[h]<=inNeed[7]){
        inNeed[7]-=donations[h];
        happyPeople+=donations[h];
        donations[h]=0;
      }
    }
  }
  
  printf("%d",happyPeople);
  return 0;
}
