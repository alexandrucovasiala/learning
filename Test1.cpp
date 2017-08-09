#include "exercises.h"
bool isCharacter(char c)
{
	if(c<='z'&&c>='a'||c<='Z'&&c>='A')
		return 1;
	return 0;
}
bool isNumber(char c)
{
	if(c<='9'&&c>='0')
		return 1;
	return 0;
}                                                                                                                              



int compare_files(const char *input_file_1, const char *input_file_2)
{
	ifstream getthem(input_file_1,std::ios::binary);
	ifstream getthem1(input_file_2,std::ios::binary);
	char first,second;
	while(getthem.get(first)&&getthem1.get(second))
	{
		if(first!=second)
			return 1;
	}
	if(getthem.get(first)||getthem1.get(second))
		return 1;
	return 0;
	getthem.close();
	getthem1.close();
}

void problema1(const char *input_file_name, const char *output_file_name)
{

	ifstream getthem(input_file_name);
	ofstream putsthem(output_file_name);
	char aux;
	string vocale="aeiouAEIOU";
	int count1=0,count2=0;
	while(getthem>>aux)
	{
		if (isCharacter(aux))
		{
			count1++;
			for(int i=0;i<vocale.length();i++)
				if(vocale[i]==aux)
					count2++;	
		}
	}
	putsthem<<count2<<"|"<<count1-count2<<'\n';
	getthem.close();
	putsthem.close();
}

void problema2(const char *input_file_name, const char *output_file_name)
{


	ifstream getthem(input_file_name);
	ofstream putsthem(output_file_name);
	char anterior,actual,urmator;
	int semne=0,cuvinte=0;
	while(getthem>>actual)
	{
		if ( isCharacter(actual))
		{
			if(!isCharacter(anterior))
				cuvinte++;
			anterior=actual;
		}
		else
			if(isCharacter(actual)==0&&isNumber(actual)==0&&actual!=' '&&actual!='\n')
				if(anterior!='.'&&actual!='.')
				{
					getthem>>urmator;
					if (urmator!='.')
						semne++;
				}
				else
					semne++;
		anterior=actual;

	}
	putsthem<<cuvinte<<'\n'<<semne;
	getthem.close();
	putsthem.close();

}


int problema4(const char *input_file_name, int N)
{

	ifstream getthem(input_file_name);
	char Character;
	string NCharacters="",Minim1,aux2,Init;
	int count=0,Minim2=1,aux=N;
	while(aux!=0)
	{
		getthem>>Character;
		if(isCharacter(Character)==1||isNumber(Character)==1)
			NCharacters=NCharacters+Character;
		aux--;
	}
	Init=NCharacters;
	Minim1=NCharacters;
	count=1;
	count++;
	aux2=NCharacters[0];
	for(int i=1;i<NCharacters.length();i++)
		NCharacters[i-1]=NCharacters[i];
	NCharacters[NCharacters.length()-1]=aux2[0];
	if(NCharacters<Minim1)
	{
		Minim1=NCharacters;
		Minim2=count;
	}
	
	while(NCharacters!=Init)
	{
		count++;
		aux2=NCharacters[0];
		for(int i=1;i<NCharacters.length();i++)
			NCharacters[i-1]=NCharacters[i];
		NCharacters[NCharacters.length()-1]=aux2[0];
			if(NCharacters<Minim1)
		{
			Minim1=NCharacters;
			Minim2=count;
		}
	}
	Minim2--;
	getthem.close();
	return Minim2;
	}	


void problema5(const char *input_file_name, const char *output_file_name)
{

	ifstream getthem(input_file_name);
	ofstream putsthem(output_file_name);
	string first_word,first_word2="",second_word,second_word2;
	getthem.getline(first_word);
	getthem.getline(second_word,50);
	for(int i=first_word.length()-1;i>=0;i--)
		for(int j=0;j<second_word.length()-1;j++)	
			{	
				second_word2=second_word;
				second_word2[j+1]='\0';
				for(int i=first_word.length()-i;i<first_word.length();i++)
					first_word2=first_word2+first_word[i];
				if(first_word2==second_word2)
					putsthem<<second_word2<<'\n';
				first_word2="";
			}
	getthem.close();
	putsthem.close();
}
void problema3(const char *input_file_name, const char *output_file_name)
{

	ifstream getthem(input_file_name);
	ofstream putsthem(output_file_name);
	char c;
	string Cuvinte[1000],aux;
	int count=0;
	while(getthem>>c)
	{
		if(isCharacter(c)==1)
			Cuvinte[count]=Cuvinte[count]+c;
		else
			count++;
	}
	for(int i=0;i<Cuvinte.length()-1;i++)
		for(int j=i;j<Cuvinte.length();j++)
			if(Cuvinte[i]<Cuvinte[j])
			{
				aux=Cuvinte[i];
				Cuvinte[i]=Cuvinte[j];
				Cuvinte[j]=aux;
			}
	int Frecventa[Cuvinte.length()];
	for(int i=0;i<Cuvinte.length();i++)
		Frecventa[i]=1;
	for(int i=1;i<Cuvinte.length();i++)
	{
		if(Cuvinte[i-1]==Cuvinte[i])
		{
			for(int j=i;j<Cuvinte.length();j++)
			{
				Cuvinte[j-1]=Cuvinte[j];
				Cuvinte[Cuvinte.length()]='\0';

			}
			Frecventa[i-1]++;
		}
	}
	for(int i=0;i<Cuvinte.length();i++)
		putsthem<<Cuvinte[i]<<"***"<<Frecventa[i]<<'\n';
	getthem.close();
	putsthem.close();
}


bool rimes(char* first_word, char* second_word, int n)
{
	if(strcmp(first_word+strlen(first_word)-n,second_word+strlen(second_word)-n)==0)
		return 1;
	return 0;
}

 int Find_Sign(char Hi[])
{
	for(int i=strlen(Hi)-2;i>=0;i--)
		if(!isCharacter(Hi[i]))
			return i;
}
void Has_Sign(char &Hi[])
{
	if(!isCharacter(Hi+strlen(Hi)-1))
		Hi[strlen(Hi)-1]='\0';
}

void problema6(const char *input_file, const char *output_file)
{

	ifstream getthem(input_file_name);
	ofstream putsthem(output_file_name);
	char Word1[1000],Word2[1000],Word3[1000],Word4[1000];
	getthem.getline(Word1,1000);
	getthem.getline(Word2,1000);
	getthem.getline(Word3,1000);
	getthem.getline(Word4,1000);
	strcpy(Word1,Word1+Find_Sign(Word1)+1);
	strcpy(Word2,Word2+Find_Sign(Word2)+1);
	strcpy(Word3,Word3+Find_Sign(Word3)+1);
	strcpy(Word4,Word4+Find_Sign(Word4)+1);
	Has_Sign(Word1);
	Has_Sign(Word2);
	Has_Sign(Word3);
	Has_Sign(Word4);
	if(rimes(Word1,Word2)==1)
		if(rimes(Word3,Word4)==1)
			if(rimes(Word2,Word3)==1)
				putsthem<<'D';
			else 
				putsthem<<'A';
	else
		if(rimes(Word1,Word3)&&rimes(Word2,Word4))
		putsthem<<'B';
		else
			if(rimes(Word1,Word4)&&rimes(Word2,Word3))
		putsthem<<'C';
			else
				putsthem<<'E';
	getthem.close();
	putsthem.close();
}

//add a coment for no reason