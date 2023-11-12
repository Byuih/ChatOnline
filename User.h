#pragma once
#include <iostream>
#include <string>



const int PORT = 12345;
const std::string SERVER_IP = "127.0.0.1";

class Client {
public:
	void start() {
		// ������� �����
		int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
		if (clientSocket < 0) {
			std::cerr << "Error opening socket" << std::endl;
			return;
		}

		// ����������� ����� �������
		struct sockaddr_in serverAddress;
		serverAddress.sin_family = AF_INET;
		serverAddress.sin_port = htons(PORT);
		if (inet_pton(AF_INET, SERVER_IP.c_str(), &(serverAddress.sin_addr)) <= 0) {
			std::cerr << "Invalid address" << std::endl;
			return;
		}

		// ������������ � �������
		if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
			std::cerr << "Error connecting to server" << std::endl;
			return;
		}

		// ������ ������ � ��������

		// �������� ������ �������
		close(clientSocket);
	}
};

