mainclass Fibonacci {
       public static void main ( )
       {
         int first, second, third, i;
         i=0;
         first = 3;
         second = 2;
         third = first - second;

         while(i<10){
           if(third == 1){
              println(third);
              i=i+1;
           }
         }

        third = 3 * second;
         for(i=0; i<10; i=i+1){
           if (third == 6){
             println(i);
           }
         }

       }
}
