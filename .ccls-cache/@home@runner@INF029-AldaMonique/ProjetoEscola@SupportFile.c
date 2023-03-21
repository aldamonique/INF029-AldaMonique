case 4:{
              printf("Escluir Aluno\n");
              printf("Digite a matricula\n");
              int matricula;
              scanf("%d", &matricula);
              int achou = 0;
              if (matricula < 0){
                printf("Matrícula Inválida\n");
              }else{
                for (int i = 0; i < qtdAluno; i++)
                {
                  if (matricula == listaAluno[i].matricula){
                    //exclusão lógica
                    listaAluno[i].ativo = -1;
                    
                    for (int j = i; j < qtdAluno - 1; j++){ //shift
                      listaAluno[j].matricula = listaAluno[j+1].matricula;
                      listaAluno[j].sexo = listaAluno[j+1].sexo;
                      listaAluno[j].ativo = listaAluno[j+1].ativo;
                    }

                    qtdAluno --;
                    achou = 1;
                    break;
                  }  
                }
                if (achou)
                  printf("Aluno excluído com sucesso\n");
                else
                  printf("Matrícula inexistente\n");
                
              }
              break;
            }

if (qty_student<SIZESTUDENT){
                      printf("\nEnter the registration number: ");
                      scanf("%d", &listStudent[qty_student].registration);
                      getchar();
                      printf("\nEnter the name: ");
                      fgets(listStudent[qty_student].name, 50, stdin);
                      getchar();
                      printf("\nEnter the birthDate: ");
                      printf("\nDay: ");
                      scanf("%d", &listStudent[qty_student].birthdate.day);
                      printf("\nMonth: ");
                      scanf("%d", &listStudent[qty_student].birthdate.month);
                      printf("\nMonth: ");
                      scanf("%d", &listStudent[qty_student].birthdate.year);
                      getchar();
                      printf("Enter the gender, set F to feminine and M to masculine ");
                      scanf("%c", &listStudent[qty_student].gender);
                      getchar();
                      printf("Enter the CPF");
                      scanf("%d", &listStudent[qty_student].CPF);
                      qty_student++;
                    }else{
                      printf("It's not possible to register new students now, the limit has been exceeded.\n");
                    }


while(!exitStudent){
          printf("\nStudent Cadastre");
          int choiceMenuStudent, menuStudent;
          menuStudent = menuStudentCadastre(choiceMenuStudent);
                switch(menuStudent){
                  case 1:{ 
                    studentCadastre();
                  break;
                  }
                  case 2:{
                    studentListCadastre();
                  break;
                  } 
                  case 3:{
                    studentDelete();
                  break;
                  }
                  case 4:{
                    exitStudent = 1;
                  break;
                  }
                }