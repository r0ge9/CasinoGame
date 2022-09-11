#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

using namespace sf;
using namespace std;

void  get_profile_name(string arr[])
{
	fstream file_profiles("name.txt");
	if (!file_profiles.is_open())
	{
		exit(0);
	}
	string number_string;
	for (int i = 0;i < 3;i++)
	{
		getline(file_profiles, number_string);
		if (number_string.empty())
		{
			arr[i] = "";
		}
		else
		{
			arr[i] = number_string;
		}
			number_string.clear();
	}
	file_profiles.close();
	
}


void set_profiles_name(string arr[])
{
	fstream file_record("name.txt");

	if (!file_record.is_open())
	{
		exit(0);
	}

	file_record.clear();

	for (int i = 0; i < 3; i++)
	{
		file_record << arr[i] << "\n";
	}
	file_record.close();
}

void set_profiles_balance(int arr[])
{
	fstream file_record("bal.txt");

	if (!file_record.is_open())
	{
		exit(0);
	}

	file_record.clear();

	for (int i = 0; i < 3; i++)
	{
		file_record << arr[i] << "\n";
	}
	file_record.close();
}

void get_profile_balance(int arr[])
{
	fstream file_profiles("bal.txt");
	if (!file_profiles.is_open())
	{
		exit(0);
	}
	string number_string;
	for (int i = 0;i < 3;i++)
	{
		getline(file_profiles, number_string);
		if (number_string.empty())
		{
			arr[i] = 0;
		}
		else
		{
			arr[i] = stoi(number_string);
		}
		number_string.clear();
	}
	file_profiles.close();

}

void get_profile_goods(int arr[])
{
	fstream file_profiles("goo.txt");
	if (!file_profiles.is_open())
	{
		exit(0);
	}
	string number_string;
	for (int i = 0;i < 3;i++)
	{
		getline(file_profiles, number_string);
		if (number_string.empty())
		{
			arr[i] = 0;
		}
		else
		{
			arr[i] = stoi(number_string);
		}
		number_string.clear();
	}
	file_profiles.close();

}

void set_profiles_goods(int arr[])
{
	fstream file_record("goo.txt");

	if (!file_record.is_open())
	{
		exit(0);
	}

	file_record.clear();

	for (int i = 0; i < 3; i++)
	{
		file_record << arr[i] << "\n";
	}
	file_record.close();
}