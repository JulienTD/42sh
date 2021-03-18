#!/bin/sh
##
## AUTOMATED TEST : 42sh / EPITECH 2018 PROJECT
## 
## florent.poinsard@epitech.eu
## more test > arnaud.nommay@epitech.eu

BUFFER="__buffer__"
BUFFER2="__buffer2__"
BUFFER3="__buffer3__"
RESULT_FILE="__result_file__.txt"

prepare_repo() {
  mv 42sh_tests.sh ..
  clear
  make re
  rm $RESULT_FILE
  make
  mkdir __exec_file__
  clear
}

end_repo() {
  mv ./42sh_tests.sh ./bonus
  mv $RESULT_FILE ./bonus
  mv __exec_file__ ./bonus
  rm $BUFFER
  rm $BUFFER2
  rm $BUFFER3
}

write_test_result() {
  if [ $1 -eq $2 ]
  then
    printf "[  SUCCESS  ] -> Test %s\n" $3 >> $RESULT_FILE
  else
    printf "[  FAILURE  ] -> Test %s\n" $3 >> $RESULT_FILE
  fi
}

## invalid command
{
  test_invalid_command_1() {
    echo -ne "exitt" | ./42sh > ./__exec_file__/file_ref_1_log.txt
    grep "exitt: Command not found." ./__exec_file__/file_ref_1_log.txt > /dev/null
    write_test_result "$?" "0" "basic_invalid_1"
  }

  test_invalid_command_2() {
    echo -ne "/usr/pwd" | ./42sh > ./__exec_file__/file_ref_2_log.txt
    grep "/usr/pwd: Command not found." ./__exec_file__/file_ref_2_log.txt > /dev/null
    write_test_result "$?" "0" "basic_invalid_2"
  }

  test_invalid_command_3() {
    echo -ne "e cd" | ./42sh > ./__exec_file__/file_ref_3_log.txt
    grep "e: Command not found." ./__exec_file__/file_ref_3_log.txt > /dev/null
    write_test_result "$?" "0" "basic_invalid_3"
  }
}

## simple exec
{
  test_simple_exec_1() {
    echo -ne "/usr/bin/ls 42sh" | ./42sh > ./__exec_file__/simple_exec_1.txt
    grep "42sh" ./__exec_file__/simple_exec_1.txt > /dev/null
    write_test_result "$?" "0" "simple_exec_1"
  }

  test_simple_exec_2() {
    echo -ne "hey guys how are you ?\n" > $BUFFER
    echo "/usr/bin/cat __buffer__" | ./42sh > ./__exec_file__/simple_exec_2.txt
    grep "hey guys how are you ?" ./__exec_file__/simple_exec_2.txt > /dev/null
    write_test_result "$?" "0" "simple_exec_2"
    rm $BUFFER
  }
}

## cd builtins
{
  test_cd_builtins_1() {
    echo -ne "cd ..\nunsetenv OLDPWD\nenv\n" | tcsh -f > $BUFFER
    grep "PWD=" $BUFFER > $BUFFER2
    echo -ne "cd ..\nunsetenv OLDPWD\nenv\n" | ./42sh > $BUFFER
    grep "PWD=" $BUFFER > $BUFFER3
    diff $BUFFER3 $BUFFER2 > ./__exec_file__/cd_builtins_1.txt
    write_test_result "$?" "0" "cd_builtins_1"
    rm $BUFFER
    rm $BUFFER2
    rm $BUFFER3
  }

  test_cd_builtins_2() {
    echo -ne "cd\nunsetenv OLDPWD\nenv\n" | tcsh -f > $BUFFER
    grep "PWD=" $BUFFER > $BUFFER2
    echo -ne "cd\nunsetenv OLDPWD\nenv\n" | ./42sh > $BUFFER
    grep "PWD=" $BUFFER > $BUFFER3
    diff $BUFFER3 $BUFFER2 > ./__exec_file__/cd_builtins_2.txt
    write_test_result "$?" "0" "cd_builtins_2"
    rm $BUFFER
    rm $BUFFER2
    rm $BUFFER3
  }

  test_cd_builtins_3() {
    echo -ne "cd ../../\nunsetenv OLDPWD\nenv\n" | tcsh -f > $BUFFER
    grep "PWD=" $BUFFER > $BUFFER2
    echo -ne "cd ../../\nunsetenv OLDPWD\nenv\n" | env -i ./42sh > $BUFFER
    grep "PWD=" $BUFFER > $BUFFER3
    diff $BUFFER3 $BUFFER2 > ./__exec_file__/cd_builtins_3.txt
    write_test_result "$?" "0" "cd_builtins_3"
    rm $BUFFER
    rm $BUFFER2
    rm $BUFFER3
  }

  test_cd_builtins_4() {
    echo -ne "cd /\nunsetenv OLDPWD\nenv\n" | env -i tcsh -f > $BUFFER
    grep "PWD=" $BUFFER > $BUFFER2
    echo -ne "cd /\nunsetenv OLDPWD\nenv\n" | env -i ./42sh > $BUFFER
    grep "PWD=" $BUFFER > $BUFFER3
    diff $BUFFER3 $BUFFER2 > ./__exec_file__/cd_builtins_4.txt
    write_test_result "$?" "0" "cd_builtins_4"
    rm $BUFFER
    rm $BUFFER2
    rm $BUFFER3
  }
}

## echo builtins
{
  test_echo_builtins_1() {
    echo -ne "echo 'this is a text' > ./test.txt\n cat test.txt" | ./42sh > ./__exec_file__/echo_builtins_1.txt
    grep "this is a text" ./__exec_file__/echo_builtins_1.txt > /dev/null
    write_test_result "$?" "0" "echo_builtins_1"
    rm test.txt
  }

  test_echo_builtins_2() {
    echo -ne 'ls\necho $? > text.txt/n' | ./42sh > ./__exec_file__/echo_builtins_2.txt
    grep "0" ./__exec_file__/echo_builtins_2.txt > /dev/null
    write_test_result "$?" "0" "echo_builtins_2"
    rm test.txt
  }
}

## setenv builtins
{
  test_setenv_builtins_1() {
    echo -ne "setenv TITI 123\nenv\n" | ./42sh > ./__exec_file__/setenv_builtins_1.txt
    grep "TITI=" __exec_file__/setenv_builtins_1.txt > /dev/null
    write_test_result "$?" "0" "setenv_builtins_1"
  }

  test_setenv_builtins_2() {
    echo -ne "setenv TITI 123\nsetenv TOTO 789AZE\nenv\n" | ./42sh > ./__exec_file__/setenv_builtins_2.txt
    grep "TITI=123" __exec_file__/setenv_builtins_2.txt > /dev/null
    write_test_result "$?" "0" "setenv_builtins_2"
  }

  test_setenv_builtins_3() {
    echo -ne "setenv TITI 123=123=123=123=ABCDEF\nenv\n" | env -i ./42sh > ./__exec_file__/setenv_builtins_3.txt
    grep "TITI=123=123=123=123=ABCDEF" __exec_file__/setenv_builtins_3.txt > /dev/null
    write_test_result "$?" "0" "setenv_builtins_3"
  }
}

## unsetenv builtins
{
  test_unsetenv_builtins_1() {
    echo -ne "setenv TITI 123\nunsetenv TITI\nenv\n" | ./42sh > ./__exec_file__/unsetenv_builtins_1.txt
    grep "TITI=" __exec_file__/unsetenv_builtins_1.txt > /dev/null
    write_test_result "$?" "1" "unsetenv_builtins_1"
  }

  test_unsetenv_builtins_2() {
    echo -ne "setenv TITI 123\nsetenv TOTO 789AZE\nunsetenv TITI\nenv\n" | ./42sh > ./__exec_file__/unsetenv_builtins_2.txt
    grep "TITI=123" __exec_file__/unsetenv_builtins_2.txt > /dev/null
    write_test_result "$?" "1" "unsetenv_builtins_2"
  }

  test_unsetenv_builtins_3() {
    echo -ne "setenv TITI 123=123=123=123=ABCDEF\nunsetenv TITI\nenv\n" | env -i ./42sh > ./__exec_file__/unsetenv_builtins_3.txt
    grep "TITI=123=123=123=123=ABCDEF" __exec_file__/unsetenv_builtins_3.txt > /dev/null
    write_test_result "$?" "1" "unsetenv_builtins_3"
  }
}

## medium exec
{
  test_medium_exec_1() {
    echo -ne "ls ; pwd ; echo salut > sls ; echo ca va >> sls ; cat sls | grep sa ; rm sls\n" | tcsh -f > $BUFFER
    echo -ne "ls ; pwd ; echo salut > sls ; echo ca va >> sls ; cat sls | grep sa ; rm sls\n" | ./42sh > $BUFFER2
    diff $BUFFER $BUFFER2 > ./__exec_file__/medium_exec_1.txt
    write_test_result "$?" "0" "medium_exec_1"
    rm $BUFFER
    rm $BUFFER2
  }

  test_medium_exec_2() {
    echo -ne "ls ; pwd ; echo salut > sls ; echo ca va >> sls ; cat sls | grep sa ; rm sls\n" | tcsh -f > $BUFFER
    echo -ne "ls > res ; " | ./42sh > $BUFFER2
    diff $BUFFER $BUFFER2 > ./__exec_file__/medium_exec_2.txt
    write_test_result "$?" "0" "medium_exec_2"
    rm $BUFFER
    rm $BUFFER2
  }
    test_medium_exec_3() {
    echo -ne "42sh> cd ; </etc/hosts od -c | grep xx | wc >> /tmp/z -l ; cd - && echo 'OK'\n" | tcsh -f > $BUFFER
    echo -ne "42sh> cd ; </etc/hosts od -c | grep xx | wc >> /tmp/z -l ; cd - && echo 'OK'\n" | ./42sh > $BUFFER2
    diff $BUFFER $BUFFER2 > ./__exec_file__/medium_exec_3.txt
    write_test_result "$?" "0" "medium_exec_3"
    rm $BUFFER
    rm $BUFFER2
  }
}

## separator
{
  test_and_1() {
    echo -ne "pwd > file && ls >> file" | tcsh -f
    echo -ne "pwd > file2 && ls >> file2" | ./42sh
    diff file file2 > ./__exec_file__/test_and_2.txt
    write_test_result "$?" "0" "test_and_1"
    rm file
    rm file2
  }

  test_and_2() {
    echo -ne "truc > file && ls >> file" | tcsh -f
    echo -ne "truc > file2 && ls >> file2" | ./42sh
    diff file file2 > ./__exec_file__/test_and_2.txt
    write_test_result "$?" "0" "test_and_2"
    rm file
    rm file2
  }

  test_or_1() {
    echo -ne "ls > file" | ./42sh
    echo -ne "truc > file2 || ls >> file2" | ./42sh
    diff file file2 > ./__exec_file__/test_and_2.txt
    write_test_result "$?" "0" "test_or_1"
    rm file
    rm file2
  }

  test_or_2() {
    echo -ne "pwd > file || ls >> file" | tcsh -f
    echo -ne "pwd > file2 || ls >> file2" | ./42sh
    diff file file2 > ./__exec_file__/test_and_2.txt
    write_test_result "$?" "0" "test_or_2"
    rm file
    rm file2
  }

  test_globbings() {
    echo -ne "ls src/main.c" | ./42sh > $BUFFER
    echo -ne "ls src/*.c" | ./42sh > $BUFFER2
    diff $BUFFER $BUFFER2 > ./__exec_file__/globbings.txt
    write_test_result "$?" "0" "globbings"
    rm $BUFFER
    rm $BUFFER2
  }
}

# main
prepare_repo
printf "Tests will begin soon...\n"
echo -ne "----- SIMPLE INVALID COMMAND -----\n" > $RESULT_FILE
test_invalid_command_1
test_invalid_command_2
test_invalid_command_3
echo -ne "\n----- SIMPLE EXEC -----\n" >> $RESULT_FILE
test_simple_exec_1
test_simple_exec_2
echo -ne "\n----- MEDIUM EXEC -----\n" >> $RESULT_FILE
test_medium_exec_1
test_medium_exec_2
test_medium_exec_3
echo -ne "\n----- CD BUILTINS -----\n" >> $RESULT_FILE
test_cd_builtins_1
test_cd_builtins_2
test_cd_builtins_3
test_cd_builtins_4
echo -ne "\n----- SETENV BUILTINS -----\n" >> $RESULT_FILE
test_setenv_builtins_1
test_setenv_builtins_2
test_setenv_builtins_3
echo -ne "\n----- UNSETENV BUILTINS -----\n" >> $RESULT_FILE
test_unsetenv_builtins_1
test_unsetenv_builtins_2
test_unsetenv_builtins_3
echo -ne "\n----- ECHO BUILTINS -----\n" >> $RESULT_FILE
test_echo_builtins_1
test_echo_builtins_2
echo -ne "\n----- OR & AND BUILTINS -----\n" >> $RESULT_FILE
test_or_1
test_or_2
test_and_1
test_and_2
test_globbings
echo -ne "\n----- END OF TESTS -----\n" >> $RESULT_FILE
cat $RESULT_FILE
end_repo
