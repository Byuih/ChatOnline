#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>



const int PORT = 12345;

class Server {
public:
	void start() {
		// ������� �����
		int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
		if (serverSocket < 0) {
			std::cerr << "Error opening socket" << std::endl;
			return;
		}

		// ����������� ����� �������
		struct sockaddr_in serverAddress;
		serverAddress.sin_family = AF_INET;
		serverAddress.sin_addr.s_addr = INADDR_ANY;
		serverAddress.sin_port = htons(PORT);

		// ����������� ����� � ������
		if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
			std::cerr << "Error binding socket" << std::endl;
			return;
		}

		// ������� �����������
		listen(serverSocket, 5);

		while (true) {
			// ��������� �����������
			int clientSocket = accept(serverSocket, NULL, NULL);
			if (clientSocket < 0) {
				std::cerr << "Error accepting connection" << std::endl;
				return;
			}

			// ������� ����� ����� ��� ������ � ��������
			pid_t pid = fork();
			if (pid < 0) {
				std::cerr << "Error creating child process" << std::endl;
				return;
			}

			if (pid == 0) {
				// ��������� ����������� �������
				handle(clientSocket);
				close(clientSocket);
				return;
			}
			else {
				// �������� ������ �������
				close(clientSocket);
			}
		}

		// �������� ������ �������
		close(serverSocket);
	}

private:
	void handle(int clientSocket) {
		// ������ ������ � ��������
	}
};
