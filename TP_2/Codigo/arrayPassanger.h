typedef struct{
	int id;
	char name[51];
	char lastname[51];
	float price;
	char flycode[10];
	int typePassanger;
	int statusFlight;
	int isEmpty;
}Passanger;

//brief
//param
//return
int initPassanger(Passanger* , int );

//brief
//param
//return
int addPassanger(Passanger* , int, int ,char* , char* ,float ,char* ,int );

//brief
//param
//return
void modifyPassanger(Passanger* , int, int, int);

//brief
//param
//return
int findPassanger(Passanger* , int , int );

//brief
//param
//return
int removePassanger(Passanger* , int , int );

//brief
//param
//return
int printPassanger(Passanger* , int );

//brief
//param
//return
int sortPassanger(Passanger* , int , int );

//brief
//param
//return
int sortPassangerByCode(Passanger* , int , int );
