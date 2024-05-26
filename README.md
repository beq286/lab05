### Laboratory V
[![Coverage Status](https://coveralls.io/repos/github/beq286/lab05/badge.svg?branch=main)](https://coveralls.io/github/beq286/lab05?branch=main)
### Задание
1. Создайте `CMakeList.txt` для библиотеки *banking*.
2. Создайте модульные тесты на классы `Transaction` и `Account`.
    * Используйте mock-объекты.
    * Покрытие кода должно составлять 100%.
3. Настройте сборочную процедуру на **TravisCI**.
4. Настройте [Coveralls.io](https://coveralls.io/).
```sh
$ git clone https://github.com/tp-labs/lab05
$ git remote remove origin
$ git remote add origin https://github.com/BaltaevTimur/lab05
```
```sh
$ mkdir third-party
$ git submodule add https://github.com/google/googletest third-party/gtest
```
```sh
$ mkdir coverage && cd coverage
$ touch lcov.info
$ cd..
$ mkdir tests && cd tests
$ touch test_Account.cpp
$ touch test_Transaction.cpp
$ cd..
```

