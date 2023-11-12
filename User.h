#pragma once
#include <iostream>
#include <string>



const int PORT = 12345;
const std::string SERVER_IP = "127.0.0.1";

class Client {
public:
	void start() {
		// Создаем сокет
		int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
		if (clientSocket < 0) {
			std::cerr << "Error opening socket" << std::endl;
			return;
		}

		// Настраиваем адрес сервера
		struct sockaddr_in serverAddress;
		serverAddress.sin_family = AF_INET;
		serverAddress.sin_port = htons(PORT);
		if (inet_pton(AF_INET, SERVER_IP.c_str(), &(serverAddress.sin_addr)) <= 0) {
			std::cerr << "Invalid address" << std::endl;
			return;
		}

		// Подключаемся к серверу
		if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
			std::cerr << "Error connecting to server" << std::endl;
			return;
		}

		// Логика работы с сервером

		// Закрытие сокета клиента
		close(clientSocket);
	}
};

