// Sert toi d'alias la prochaine fois 

#include <iostream>
#include <vector>
#include <algorithm>
#include <locale>
#include <limits>


struct student
{
    std::string name{};
    int grade{};  
};


bool compareStudentsByGrades (const student& a, const student& b )
{
return a.grade > b.grade;
}

bool isDigit (std::string text)
{
    for (int index {} ; index<text.length(); ++index)
        {
            if ( std::isdigit(text[index] ) )
                return true;
        }

return false;
}

int getGrade()
{
    int studentGrade ;
    while (true)
    {
        std::cin >> studentGrade;
          
        if (std::cin.fail()) 
		    {
            std::cerr << "Input invalide";
			std::cin.clear(); 
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
			continue; 
		    }

        if (studentGrade < 0 || studentGrade > 100)
		    {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cerr << "Veuillez rentre une valeur entre 1 et 100 : ";
			continue; 
		    }
        
    
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return studentGrade;
    }
}
 
std::string getName()
{
std::string studentName ;
    while (true)
    {
        std::cin >> studentName;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (std::cin.fail() || isDigit (studentName)  ) 
		    {
            std::cerr << "Prénom invalide, veuillez retenter : " ;
			std::cin.clear(); 
             
			continue; 
		    }
    
		return studentName;
    }
}

std::vector<student> generateStudentList (int nbStudent) 
{
    std::vector<student> studentList(nbStudent);
    for (int index{}; index<nbStudent; ++index) 
        { 
            
           
            std::cout<< "Veuillez rentrer le nom de l'élève numéro " 
                    << index+1 <<" : " ;

            studentList[index].name = getName()  ;
            std::cout<<"Son score : " ;
            studentList[index].grade = getGrade()  ; 
            std::cout<<'\n';

           
            
        }

return studentList ; 
}


void printVector (std::vector<student> studentList )
{
    for (auto student: studentList ) 
        {   
            std::cout<< student.name<<" a : " << student.grade << " points" 
                    <<'\n' ;       
        }
}



int main() 
{
std::vector<student> studentList {generateStudentList(3)};
std::sort(studentList.begin(),studentList.end(),compareStudentsByGrades);
printVector(studentList);

return 0;

}

