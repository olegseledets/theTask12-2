#include <iostream>

int main() {
  std::string targetNumber, secondNumber;
  std::string tmp;
  int bulls = 0, cows = 0;
  bool flag = false;

  while (!flag){
    std::cout << "Введите задуманное число: ";
    std::cin >> targetNumber;
    std::cout << "Введите второе число: ";
    std::cin >> secondNumber;
    if (targetNumber.length() != 4 || secondNumber.length() != 4){
      std::cout << "Длина не равна 4м символам\n"; 
    }
    else{
      for(int i = 0; i < targetNumber.length(); ++i){
        if(targetNumber[i] < '0' || targetNumber[i] > '9' || secondNumber[i] < '0' || secondNumber[i] > '9'){
          std::cout << "Вы ввели не числа\n";
          break;
        }
        else{
          flag = true;
        }
      }
    }
  }
  if(targetNumber == secondNumber){
    bulls = 4;
  }
  else{
    for (int i = 0; i < targetNumber.length(); ++i){   
      if (targetNumber[i] == secondNumber[i]){          
        tmp[i] = 'C';                                   
        ++bulls;                                        
      } 
      else{
        tmp[i] = '0';                                  
      }
    }

    for (int i = 0; i < targetNumber.length(); ++i){   
      if (tmp[i] == 'C'){                              
        continue;
      }
      for (int j = 0; j < targetNumber.length(); ++j){
        if (tmp[j] == 'C' || tmp[j] == 'B'){           
          continue;                                    
        }
        if (targetNumber[i] == secondNumber[j]){
          tmp[j] = 'B';                                     
          ++cows;                                      
          break;                       
        }                                    
      }        
    } 
  }
  std::cout << "\nБыков: " << bulls << ", коров: " << cows << std::endl;
}

/*
В логической игре “быки и коровы” первый игрок загадывает четырехзначное число (оно может начинаться и с нулей), а второй игрок должен его отгадать. Отгадывание происходит так: своим ходом второй игрок называет любое четырехзначное число, а первый ему отвечает, сколько в этом числе “быков” и сколько “коров”. Корова — это цифра, которая совпадает по значению с какой-то из цифр задуманного числа, но стоит не на нужном месте. Бык — это цифра, совпадающая с цифрой в задуманном числе и по значению, и по расположению.
Вам нужно написать программу, которая по загаданному числу и по названному вторым игроком числу определяет, сколько во втором числе “быков” и сколько “коров”. Не забудьте, что числа могут начинаться с нулей!
Примечание. Сумма быков и коров не может быть больше 4.

Примеры:

Введите задуманное число: 5671
Введите второе число: 7251
Быков: 1, коров: 2

Введите задуманное число: 1234
Введите второе число: 1234
Быков: 4, коров: 0

Введите задуманное число: 0023
Введите второе число: 2013
Быков: 2, коров: 1

Введите задуманное число: 1111
Введите второе число: 1111
Быков: 4, коров: 0
*/