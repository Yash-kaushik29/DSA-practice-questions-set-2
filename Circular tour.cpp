class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
       int deficiency = 0;
       int petrolLeft = 0;
       int start = 0;
       
       for(int i=0; i<n; i++) {
           
           petrolLeft += p[i].petrol - p[i].distance;
           
           if(petrolLeft < 0) {
               deficiency += petrolLeft;
               start = i+1;
               petrolLeft = 0;
           }
       }
       
       if(deficiency + petrolLeft >= 0) 
          return start;
     
       else
          return -1;
    }
};
