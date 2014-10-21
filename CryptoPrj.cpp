// CryptoPrj.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include<string>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include "dict1.h"
#include<algorithm>


using namespace std;

void mergesort(int *a, int low, int high);
void merge(int *a, int low, int high, int mid);
bool compare_arrays(int a[], int b[], int x, int t);
int check_dictionary(char ciphertext[], int t, string s, int flag);
void check_dictionary2(char ciphertext[], int t);
string make_combinations(char str[], string dict2[], char ciphertext[], int dict2_length, int t);
string make_string(char *str, string word);


/*
calculate one key
store it in temp array
find key for other chunk
sort both the keys
compare both the keys till size of temp keys
if same then move forward else start from other character
*/

void main()
{
	int t, difference;
	int temp, key[40], duplicate_key[40];
	int i = 0, j = 0, k = 0, x = 0, found = 0, round = 1;
	int dict_length1, cipher_length;
	char ciphertext[200];
	bool compare_result = false;
	
	/*
	cout << "Enter the ciphertext";
	cin >> ciphertext;
	cout << "Enter the size of key (t)";
	cin >> t;

	
	cout << "\n" << ciphertext << "\n" << t;

	dict_length1 = strlen(DICTIONARY1);
	cipher_length = strlen(ciphertext);
	
	while (i<dict_length1)
	{
		for (j = 0; j<cipher_length;)
		{


			difference = ciphertext[j] - DICTIONARY1[i + j];
			if (difference < 0)
				difference = difference + 26;

			if (round == 1)
			{
				key[x] = difference;
				temp = j;
			}

			if (j>t && key[x] != difference)
			{
				i++;
				x = 0;
				round = 1;
				break;
			}

			if (((cipher_length - j) <= t) && x < t - 1)
			{
				temp++;
				j = temp;
				x++;
				round = 1;
			}
			else if (x == t - 1)
				break;

			else
			{
				j = j + t;
				round++;

			}
		}

		if (x == t - 1)
			break;
	}

	cout << "\n";
	for (j = 0; j<t; j++)
		cout << "\n" << j << "--" << key[j];

	cin >> j;	*/
	

	/*------------------------------------------------------------------------------------*/
	cout << "Enter the ciphertext" << endl;
	cin >> ciphertext;
	cout << "Enter the size of key (t)" << endl;
	cin >> t;

	
	if (strlen(ciphertext) > 150)
		found = 0;
	else
		found = check_dictionary(ciphertext, t, "NONE", 1);

	if (found==0)
		check_dictionary2(ciphertext, t);

	/*string comb_result;
	string dict2[] = { "hello", "desire", "category", "navin", "gaurav", "dheeraj", "prakash", "manoj", "medidata" };
	comb_result = make_combinations("", dict2, ciphertext, 9, t);*/
	
	cout << "\n Press any character to exit" << endl;
	cin >> j;

}


//string make_string(char str[], string word)
//{
//	char temp[250];
//	int i;
//
//	for (i = 0; i < strlen(str); i++)
//		temp[i] = str[i];
//
//	for (int j = 0; j < word.size(); j++, i++)
//		temp[i] = word[j];
//
//	temp[i] = '\0';
//	cout <<  "\n" << temp << endl;
//
//	return temp;
//}

string make_combinations(char str[], string dict2[], char ciphertext[], int dict2_length, int t)
{

	if ((strlen(str) >= strlen(ciphertext)) || (strlen(str)>=t*2))
		return str;

	char convert_string_array[250];
	char convert_string_array2[250];
	
	int j;
	string combined_string, combined_string2;

	for (int i = 0; i < dict2_length; i++)
	{
		

		string c(str);
		if (c.find(dict2[i]) != string::npos)
			continue;
		
		

		int x = 0, y=0;
		for (j = 0; j < dict2[i].size(); j++)
			convert_string_array[x++] = dict2[i][j];

		for (j = 0; j < strlen(str); j++)
			convert_string_array[x++] = str[j];

		//------------------------------------reversing the string
		/*for (j = 0; j < strlen(str); j++)
			convert_string_array2[y++] = str[j];

		for (j = 0; j < dict2[i].size(); j++)
			convert_string_array2[y++] = dict2[i][j];*/

		convert_string_array[x] = '\0';
		//convert_string_array2[y] = '\0';

		string combined_string = make_combinations(convert_string_array, dict2, ciphertext,9, t);
		if (combined_string.length() > 200)
			return combined_string;

		//myfile << "\n" << combined_string;
		//string combined_string2 = make_combinations(convert_string_array2, dict2, ciphertext,9, t);

		////cout << str<<endl;
		if ((combined_string.length() >= strlen(ciphertext)) || (combined_string.length() >= (t*2)))
		{
			cout << "\n checking combination: " << combined_string;
			int found = check_dictionary(ciphertext, t, combined_string, 2);
			if (found == 1)
			{
				cout << "Found in Dictionary 2" << endl;
				cout << "Decrypted Text: " << combined_string << endl;
				dict2_length = 0;
				combined_string = "eopleincloaksmrdursleycouldntbearpeoplewhodressedinbutontheedgeoftondrillsweredrivenoutofhismindbysomethingelseashesatintheusualmorninghewatchevbutpoorjonevergotheelaughforshewastransfixeduponthethresholdbyaspectaclewhichheldhertherestaringwithhermouthnearlyaswideopenashereyesgoingintoexulto";
				return combined_string;
			}
		}

		
		//cout << "reverse :  " << combined_string2 << endl;
		cout << "\n";

		
	}

	return str;
}

void check_dictionary2(char ciphertext[], int t)
{
	int key[40];
	int dict_count2 = 0;
	int found = 0;
	string dict2[200];
	string line;
	ifstream dict2Str("dictionary2.txt");
	stringstream dict_buffer2;
	dict_buffer2 << dict2Str.rdbuf();

	/*Storing the dictionary2 content in an array*/
	while (getline(dict_buffer2, line))
	{
		dict2[dict_count2] = line;
		dict_count2++;
	}

	
	//make combinations
	string combined_words = make_combinations("", dict2, ciphertext, sizeof(dict2), t);

}


int check_dictionary(char ciphertext[], int t, string s, int flag)
{
	int dict_length, cipher_length;
	int temp, difference, round = 1;
	int i=0, j, k, x = 0;
	int key[40], duplicate_key[40];
	bool compare_result;
	char combination[200];

	cipher_length = strlen(ciphertext);

	if (flag == 1)
		dict_length = strlen(DICTIONARY1);
	else
	{
		int min = cipher_length;
		min > (t * 2) ? (min = (t * 2)) : min = min;
		for (i = 0; i < min; i++)
			combination[i] = s[i];

		combination[i] = '\0';
		dict_length = 1;
	}	

	cout << "\n";
	
	i = 0;
	j = 0;

	while (i < dict_length)
	{
		for (j = 0; j < cipher_length;)
		{
			if (j == 0)
				temp = i;

			for (k = 0; k < t; k++)
			{
				if (flag == 1)
					difference = ciphertext[j] - DICTIONARY1[i + j];
				else
					difference = ciphertext[j] - combination[i + j];

				if (difference < 0)
					difference = difference + 26;

				if (round == 1)
					key[x] = difference;
				else
					duplicate_key[x] = difference;

				x++;	j++;

				if (j == cipher_length)
					break;
			}
			if (round == 1)
			{
				mergesort(key, 0, t - 1);
				round = 2;
				x = 0;
			}
			else if ((round != 1) && ((x == t) || (j == cipher_length)))
			{
				mergesort(duplicate_key, 0, x - 1);
				compare_result = compare_arrays(key, duplicate_key, x, t);
				x = 0;
				if (!compare_result)
				{
					i++;	round = 1;	break;
				}
			}
		}

		if (j == cipher_length)
			break;
	}

	if (j < cipher_length)
	{
		cout << "Not found in Dictionary 1" << endl;
		return 0;
	}
	else
		cout << "\n Found in Dictionary \n";


	cout << " Decrypted text:" << endl;

	for (j = 0; j < cipher_length; j++)
		if (flag == 1)
			cout << DICTIONARY1[i+j];
	
	/*
	if (flag != 1)
		for (j = 0; j < cipher_length; j++)
			cout << combination[j];

			*/
	cout << "\n";

	return 1;
}

void mergesort(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		mergesort(a, low, mid);
		mergesort(a, mid + 1, high);
		merge(a, low, high, mid);
	}
	return;
}

void merge(int *a, int low, int high, int mid)
{
	int i, j, k, c[50];
	i = low;
	k = low;
	j = mid + 1;
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			c[k] = a[i];
			k++;
			i++;
		}
		else
		{
			c[k] = a[j];
			k++;
			j++;
		}
	}
	while (i <= mid)
	{
		c[k] = a[i];
		k++;
		i++;
	}
	while (j <= high)
	{
		c[k] = a[j];
		k++;
		j++;
	}
	for (i = low; i < k; i++)
	{
		a[i] = c[i];
	}
}

bool compare_arrays(int key[], int dup[], int x, int t)
{
	int i = 0, j = 0, flag = 0;

	for (i = 0; i < x; i++)
	{
		if (j == t)
		{
			flag = 0;
			break;
		}

		for (; j < t; )
		{
			if (dup[i] == key[j])
			{
				j++;	 
				flag = 1;
				break;
			}
			j++;
			flag = 0;
		}
	}

	if (flag==0)
		return false;

	return true;
}