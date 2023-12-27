/** 
* @file ServerClientInterface.h
* @author Кижватова Ю.О.
* @version 1.0
* @date 26.12.2023
* @copyright ИБСТ ПГУ
* @brief Заголовочный файл для модуля ServerClientInterface
*/

#pragma once
#include <sys/types.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fstream>
#include <vector>
#include <random>

#include <string>
#include <locale>
#include <codecvt>

#include "DataReader.h"
#include "User.h"

using namespace std;

/** 
* @brief Класс для взаимодействия сервера с клиентами
* @param address Адрес сервера
* @param port Порт сервера
* @param vec Вектор для вычисления расчетов
* @param DB_clients БД клиентов
* @param Err объект класса Errors обработки ошибок
*/
class ServerClientInterface{
    public:
        int interaction(string database, string logFile);
        int32_t sum_vec();

        string get_address();
        void set_address(string address1);

        int get_port();
        void set_port(int port1);

        vector<int32_t> get_vec();
        void set_vec(vector<int32_t> v);

        string get_salt();
        void set_salt();

        pair<vector<string>, vector<string>> get_DB_clients();
        void set_DB_clients(vector<string> login, vector<string> password);

    private:
        string address;
        int port;
        vector<int32_t> vec;
        string salt;
        pair<vector<string>, vector<string>>DB_clients;
        Errors Err;
};
