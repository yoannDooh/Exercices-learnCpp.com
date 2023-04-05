#include <iostream>
#include <cmath>
// Calcul distance objet tombant et sol


double square (double var1) 

{

return var1*var1 ; 

}

double distanceFallenFormula (int time) 
// distance fallen = gravity_constant * x_seconds^2 / 2

{


double distanceFallen { 9.8*square(time) /2 } ; 

return distanceFallen ; 

}

double ballHeightFormula (double fallenDist,double heighTower ) 

{



return  heighTower-fallenDist ; 

}




int getFallenTime (int sec) 

{

std::cout<< "Veuillez choisir depuis combien de secondes a commencé la chute: \n \t "  
         << "0, 1, 2, 3, 4, 5 \n " ;

std::cin>>sec ;
if (sec== 1) 
    sec=1    ;

else if (sec== 2) 
    sec=2    ;

else if (sec== 3) 
    sec=3    ;

else if (sec== 4) 
    sec=4    ;

else if (sec== 5) 
    sec=5    ;


return sec; 

}



double getTowerHeight (double height) 

{

std::cout<< "Veuillez la taille en mètre de la tour: \n " ;

std::cin>> height ;

return height; 

}



int main()
 
{
  double usrTowerHeight { getTowerHeight(usrTowerHeight) }  ;
  int fallenTime { getFallenTime (fallenTime) }  ;  

  double ballHeight { ballHeightFormula (fallenTime,usrTowerHeight ) } ;
  
  if (ballHeight>0)

  std::cout<< "A "<< fallenTime <<" secondes, la balle est a cette hauteur: " << ballHeight << " mètres" ;

  else if (ballHeight==0)
   std::cout<< "A "<< fallenTime <<" secondes, la balle est au sol " ;

  else if (ballHeight<0)
   std::cout<< "A "<< fallenTime <<" secondes, la balle est au sol " ;
 
return 0; 

}
