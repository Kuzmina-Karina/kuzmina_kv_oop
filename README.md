# kuzmina_kv_oop
Репозиторий создан для практики по предмету ООП. Для разбора задач и лабораторных работ


лаба 1
1. создала репозиторий 
2. склонровала репозиторий в свою среду разработки (vs code)
3. создала папку src
4. создала 2 файла main.cpp и util.cpp
5. заполнила файлы. в util.cpp реализацию функций и в main.cpp примеры их использования 
6. создала CMakeLists.txt 
7. добавила папку src как поддиректорию проекта
8. внутри папки src тоже создала CMakeLists.txt и указала в ней как должны собираться файлы 
9. собрала, все сработало
10. добавила файлы и сделала комит 
    git add .
    git commit -m "Initial commit: CMake project setup"
11. создала новую ветку 
    git checkout -b feature-utils
12. изменила util.cpp и main.cpp
13. создала комит 
    git add src/utils.cpp src/main.cpp
    git commit -m "feat: Add multiplication function to utils"
14. переключилась на основную ветку 
    git checkout main
15. поменяла main.cpp
16. закомилила
    git add src/main.cpp
    git commit -m "fix: Update main output message in main branch"
17. попыталась слить ветку в основную
    git merge feature-utils
18. возник конфликт 
19. разрешила его 
20. посмотрела что все нормально и конфликта больше нет
    git status  
21. закомилила 
    git commit -m "Merge branch 'feature-utils' and resolve conflicts"
22. написала файл readme.md
23. отпавила изменения в git.hub 
    git push --all origin
24. поняла что забыла закомитить изменения файла readme.md и корректировки файла CMakeLists.txt
25. закомитила 
    git add CMakeLists.txt README.MD
    git commit -m "fix: Update readme.md and CMakeLists.txt"
24. отпавила изменения в git.hub 
    git push --all origin