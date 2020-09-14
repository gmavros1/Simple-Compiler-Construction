mainclass Fibonacci {
       public static void main ( )
       {
         int first, second, third, i;
         i=0;
         first = 3;
         second = 2;
         third = first - second + (1 + second);

         while(i<10){
           if(third == 4){
              println(third);
              i=i+1;
           }
         }

        third = 3 * second + 1 ;
        println(third);
         for(i=0; i<10; i=i+1){
           if (third == 7){
             println(i);
           }
         }

       }
}
