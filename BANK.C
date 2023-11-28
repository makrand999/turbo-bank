#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

time_t t;   //ttt
int x[20], y[20];
char a, ch, cpin[22], cpin1[22], username[] = "team5", tusername[22];
int p, u, i = 0, j, J, in, I[22] = {0}, X, L = 0; // i is for new acc counter and I[] is for transection counter p is independent
int temp_acc_number;
long int pin;

struct tran
{
  int tdate[9];
  long long int transfer, balance;
};

struct tran h[11][22];

struct cust
{
  int acc_date[5], dob[5], acc_type;
  char name[55], pan[22], pin1, address[111],aadhar[12], phone_number[10];
  long long int  acc_balance;
  int b, acc_number;
  long int score;
};

struct cust m[10];

struct loan
{
  char l_purpose[55], l_type[22], employment_status[20], acc_number;
  long long int m_income, l_amount;
  int ldate[3], rdate[3];
};
struct loan l[10];

void Time();
void set();
void login();
void home();
void deposite();
void create_account();
void acc_details();
void withdraw();
void history();
void DOB();
void blank(int);
void acc_update();
void phone_number();
void aadhar_number();
void pan_number();
void transection();
void send1();
void loan();
void loanc();
void acc();
void get(int);

int main()
{

  clrscr();
  loanc();
  login();
  home();

  return 0;
}

void home()
{
  clrscr();

  printf("\n\nSTUDENT BANK OF MIT\n\n\n");

  printf("1] create new account\n\n");
  printf("2] check account details\n\n");
  printf("3] transaction\n\n");
  printf("4] view transection history\n\n");
  printf("5] loan\n\n");
  a = getch();
  clrscr();

  switch (a)
  {
  case 0:
    main();
    break;
  case '1':
    create_account();
    break;

  case '2':
    get(1);
  acc_num:
    set(1);
    printf("account number:- ");
    get(0);
    blank(20);
    set(0);
    j = 0;
    while (1)
    {
      ch = getch();
      if (ch == 13 || ch == 27)
      {
	break;
      }
      if (ch == 8 && j > 0)
      {
	printf("\b \b");
	j--;
	continue;
      }
      if (ch > 47 && ch < 58)
      {
	cpin[j] = ch;
	printf("%c", ch);
	j++;
      }
    }
    if (ch == 27)
    {
      home();
    }
    cpin[j] = '\0';
    temp_acc_number = atoi(cpin);

    for (j = 0; j < i; j++)
    {
      if (temp_acc_number == m[j].acc_number)
      {
	in = 1;
	break;
      }
      else
      {
	in = 0;
      }
    }
    if (in == 0)
    {
      goto acc_num;
    }

    in = temp_acc_number % 10;

    if (temp_acc_number == 1)
    {
      home();
    }

    clrscr();
    acc_details();
    break;

  case '3':
    transection();
    break;

  case '4':
    history();
    break;

  case '5':
    loan();
    break;
  case 65:
  {
    exit(0);
  }

  default:
    clrscr();
    home();
  }
}

void create_account()
{
  printf("\n\n1] Name: ");
  scanf(" %[^\n]", m[i].name);
  printf("\n");
  get(1);
  DOB();
  printf("\n\n");
  get(2);
  aadhar_number();
  printf("\n\n");
  get(3);
  phone_number();
  printf("\n\n");
  get(4);
  pan_number();
  printf("\n\n");
  printf("address:- ");
  scanf(" %[^\n]", m[i].address);

  printf("\n\n1] current\n2] saving\n3] fixed\n\n");

  while (1)
  {
    a = getch();
    if (a == 27)
    {
      break;
    }
    if (a < 52 && a != 48)
    {
      m[i].b = a - 48;
      m[i].acc_type = m[i].b;
      break;
    }
  }
  if (a == 27)
  {
    home();
  }
  if (m[i].b == 3)
  {

    printf("\n\n1] for 1 year\n2] for 2 year\n3] for 3 year\n\n");

    m[i].b = 4;

    while (m[i].b > 3)
    {
      ch = getch();
      if (ch == 27)
      {
	break;
      }
      m[i].b = ch - 48;
    }
    if (ch == 27)
    {
      home();
    }
    m[i].acc_type = 30 + m[i].b; // ex(33 for fixed account for 3 year)
  }

  clrscr();
  srand(time(NULL));
  m[i].acc_number = ((rand() % 100) + 99) * 10 + i;
  m[i].score = 700;
  get(0);
  x[0] /= 4;
  y[0] /= 4;
  set(0);

  printf("\nyour account created succesesfully\n\n\n");
  printf("your account number is  \n\n%d", m[i].acc_number);

  i++;
  while (1)
  {
    a = getch();

    if (a == 27)
      break;
  }
  clrscr();
  home();
}

void deposite() //  deposite function
{

  clrscr();

  printf("\n\naccount balance:- %ld", m[in].acc_balance);

  printf("\n\n\nenter amount:-");

  j=0;
  while (1)
  {
    ch = getch();
    if (ch == 13 || ch == 27)
    {
      break;
    }
    if (ch == 8)
    {
      printf("\b \b");
      j--;
      continue;
    }
    if (ch > 47 && ch < 58)
    {
      cpin1[j] = ch;
      printf("%c", ch);
      j++;
    }
  }
  if (ch == 27)
  {
    home();
  }
  cpin1[j] = '\0';
  h[in][I[in]].transfer = atol(cpin1);

  m[in].acc_balance += h[in][I[in]].transfer;
  h[in][I[in]].balance = m[in].acc_balance;
  printf("\ntransection successfull");
  Time();
  m[in].score = m[in].score + (h[in][I[in]].transfer / 100);
  I[in]++;

  while (1)
  {
    a = getch();
    if (a == 27)
      break;
  }
  clrscr();
  home();
}

void login() // login function
{
  printf("\n\n");

  printf("username:- ");
  j = 0;

  while (1)
  {
    ch = getch();


    if (ch == 13)
      break;

    if (ch == 8 && j > 0)
    {
      printf("\b \b");
      j--;
    }
    if (ch != 8 || ch == 32)
    {
      tusername[j] = ch;
      printf("%c", ch);
      j++;
    }
  }
  tusername[j] = '\0';
  u = strcmp(username, tusername);

  if (u != 0)
  {
    clrscr();
    login();
  }
  printf("\n\n\nEnter your PIN: "); // pin start
pin:
  get(0);
  j = 0;
  while (1)
  {
    ch = getch();

    if (ch == 13)
      break;
    if (ch == 8 && j > 0)
    {
      printf("\b \b");
      j--;
      continue;
    }

    if (ch >= 48 && ch <= 57)
    {
      cpin[j] = ch;
      printf("*");
      j++;
    }
  }
  blank(22);
  get(1);
  blank(22);
  set(1);

  cpin[j] = '\0';
  pin = atol(cpin);

  if (pin != 261224)
  {
    set(0);
    blank(j + 1);
    set(0);
    goto pin;
  }

  clrscr();
}

void acc_details() // acc detail function
{
  printf("\n\naccount details\n\n");

udone:

  printf("1] NAME:- ");
  get(0);
  printf("%s\n\n\n", m[in].name);
  get(1);
  printf("2] date of birth:- %d/%d/%d\n\n\n", m[in].dob[0], m[in].dob[1], m[in].dob[2]);
  get(2);
  printf("3] aadhar no.:- %s\n\n\n", m[in].aadhar);
  get(3);
  printf("4] phone number:- %s\n\n\n", m[in].phone_number);
  get(4);
  printf("5] pan number:- %s\n\n\n", m[in].pan);
  get(5);
  printf("6] address:- %s\n\n\n", m[in].address);
  printf("balance:- %ld\n\n", m[in].acc_balance);
  printf("cibil score:- %ld\n\n", m[in].score);
  printf("type of account:- ");
  switch (m[in].acc_type)
  {
  case 1:
    printf("current");
    break;
  case 2:
    printf("saving");
    break;
  default:
    printf("fixed for %d year", m[in].b);
  }

  while (1)
  {
    a = getch();
    if (a == 27 || a > 48 && a < 55)
      break;
  }
  if (a == 27)
    home();
  if (a > 48 && a < 55)
  {
    acc_update();
    goto udone;
  }
}

void withdraw()
{
  clrscr();

  printf("\n\nWITHDRAW\n\n");
  printf("\n\n\namount:- ");
j=0;
  while (1)
  {
    ch = getch();
    if (ch == 13 || ch == 27)
    {
      break;
    }
    if (ch == 8)
    {
      printf("\b \b");
      j--;
      continue;
    }
    if (ch > 47 && ch < 58)
    {
      cpin1[j] = ch;
      printf("%c", ch);
      j++;
    }
  }
  if (ch == 27)
  {
    home();
  }
  cpin1[j] = '\0';
  h[in][I[in]].transfer = atol(cpin1);
  if (m[in].acc_balance < h[in][I[in]].transfer)
  {
    printf("\n\ninsufficient balance");
    ch = 0;
    while (ch != 27)
    {
      ch = getch();
    }
    home();
  }

  m[in].acc_balance -= h[in][I[in]].transfer;
  h[in][I[in]].balance = m[in].acc_balance;
  printf("\n\ndone\n");
  Time();
  I[in]++;
  while (1)
  {
    a = getch();
    if (a == 27)
      break;
  }
  clrscr();
  home();
}

void history()
{
  printf("\n\nenter account nummber:- ");
  j = 0;
  while (1)
  {

    if (j == 4)
      break;

    ch = getch();
    if (ch == 27 || ch == 32)
    {
      break;
    }
    if (ch == 8 && j > 0)
    {
      printf("\b \b");
      j--;
      continue;
    }

    if (ch >= '0' && ch <= '9')
    {
      cpin1[j] = ch;
      printf("%c", ch);
      j++;
    }
  }
  if (ch == 27)
  {
    home();
  }
  cpin1[j] = '\0';

  temp_acc_number = atoi(cpin1);

  u = temp_acc_number % 10;
  clrscr();
  printf("\n\n%s",m[u].name);
  for (in = 0; in < I[u]; in++)
  {

    printf("\n\n");


    printf("date:- %d/%d/%d     ", h[u][in].tdate[0], h[u][in].tdate[1], h[u][in].tdate[2]);
  if (in==0 || h[u][in-1].balance<h[u][in].balance)
  {
    printf("deposit:- %ld",h[u][in].transfer);
  }
  else 
  {
    printf("withdraw:- %ld",h[u][in].transfer);
  }
  sprintf(cpin, "%ld", h[u][in].transfer);
  j = strlen(cpin);
  blank(15-j);
  printf("balance:- %ld", h[u][in].balance);
  }
  while (1)
  {
    a = getch();
    if (a == 27)
      break;
  }

  clrscr();
  home();
}

void Time()
{
  struct tm *current_time = localtime(&t);
  time(&t);

  h[in][I[in]].tdate[0] = current_time->tm_year + 1900;
  h[in][I[in]].tdate[1] = current_time->tm_mon + 1;
  h[in][I[in]].tdate[2] = current_time->tm_mday;
}

void set(X)
{
  gotoxy(x[X], y[X]);
}

void get(X)
{

  x[X] = wherex();
  y[X] = wherey();
}

void DOB()
{
  set(1);

  get(0);
  printf("2] date of birth:- DD/MM/YYYY\b\b\b\b\b\b\b\b\b\b");

  j = 0;
  while (1)
  {
    if (j == 10)
    {
      if ((cpin[0] - 48) * 10 + cpin[1] - 48 < 32 && (cpin[0] - 48) * 10 + cpin[1] - 48 != 0 && (cpin[3] - 48) * 10 + cpin[4] - 48 < 13 && (cpin[3] - 48) * 10 + cpin[4] - 48 != 0 && (cpin[6] - 48) * 1000 + (cpin[7] - 48) * 100 + (cpin[8] - 48) * 10 + cpin[9] - 48 > 1910 && (cpin[6] - 48) * 1000 + (cpin[7] - 48) * 100 + (cpin[8] - 48) * 10 + cpin[9] - 48 < 2024)

	break;
    }
    if (j == 6 || j == 7 || j == 8 || j == 9)
    {
      printf("Y\b");
    }
    if (j == 3 || j == 4)
    {
      printf("M\b");
    }
    if (j == 0 || j == 1)
    {
      printf("D\b");
    }

    if (j == 2 || j == 5)
    {

      printf("/");
      j++;
    }
    cpin[j] = getch();
if (cpin[j] ==27)
{
  break;
}
    if (cpin[j] == 8 && j > 0)
    {
      if (j == 3 || j == 6)
      {
	printf("\b\b \b");
	j--;
	j--;
      }
      else
      {
	printf("\b \b");
	j--;
      }
      continue;
    }
    if (cpin[j] > 47 && cpin[j] < 58 && j < 10)
    {
      printf("%c", cpin[j]);
      j++;
    }
  }
if (cpin[j] == 27)
{
  home();
}
  m[i].dob[0] = (cpin[0] - 48) * 10 + cpin[1] - 48;                                                // day
  m[i].dob[1] = (cpin[3] - 48) * 10 + cpin[4] - 48;                                                // month
  m[i].dob[2] = (cpin[6] - 48) * 1000 + (cpin[7] - 48) * 100 + (cpin[8] - 48) * 10 + cpin[9] - 48; // year
}
void blank(u)
{

  for (J = 0; J < u; J++)
    printf(" ");
}

void acc_update()
{
  j = i;
  i = in;
  switch (a)
  {
  case 49:
    set(0);
    blank(50);
    set(0);
    scanf(" %[^\n]", m[i].name);

    break;
  case 50:
    set(1);
    blank(50);
    set(1);
    DOB();

    break;
  case 51:
    set(2);
    blank(50);
    set(2);
    aadhar_number();

    break;
  case 52:
    set(3);
    blank(50);
    set(3);
    phone_number();

    break;
  case 53:
    set(4);
    blank(50);
    set(4);
    pan_number();

    break;
  case 54:
    set(5);
    blank(50);
    set(5);
    printf("6] address:- ");
    scanf(" %[^\n]", m[i].address);

    break;
  }
  i = j;
  clrscr();
}

void aadhar_number()
{
  set(2);
  printf("3] aadhar no.:- ");

  get(0);

  j = 0;    // aadhar
  while (1) // this is for no alphabates
  {
    ch = getch();

    if (j == 12 || ch == 27)
    {
      break;
    }
    if (ch == 8 && j > 0)
    {
      printf("\b \b");
      j--;
      continue;
    }

    if (ch >= '0' && ch <= '9')
    {
      cpin[j] = ch;
      printf("%c", ch);
      j++;
    }
  }
  cpin[j]='\0';
  for(j=0;j<11;j++)
 {
  m[i].aadhar[j]=cpin1[j];
 }
if (ch == 27)
{
  home();
}
}
  
void phone_number()
{
  set(3);
  printf("4] phone number:- "); // phone number start

  get(0);
  j = 0;
  while (1)
  {

    if (j == 10 || ch == 27 )
    {

      break;
    }
    ch = getch();

    if (j == 0 && ch < 54 || ch > 57)
      continue;

    if (ch == 8 && j > 0)
    {
      printf("\b \b");
      j--;
      continue;
    }

    if (ch >= '0' && ch <= '9')
    {
      cpin1[j] = ch;
      printf("%c", ch);
      j++;
    }
  }
  cpin1[j]='\0';
 for(j=0;j<11;j++)
 {
  m[i].phone_number[j]=cpin1[j];
 }
 if (ch == 27 )
 {
  home();
 }
 

}

void pan_number()
{
  set(4);
  printf("5] pan number:- "); // pan  number
  get(0);
  j = 0;
  while (1)
  {
    if (j == 10 || ch == 27 )
    {
      break;
    }
    ch = getch();

    if ((j < 5 || j == 9) && ch >= 'a' && ch <= 'z')
    {
      m[i].pan[j] = ch - 32;
      printf("%c", m[i].pan[j]);
      j++;
    }
    else if (j > 4 && j < 9 && ch >= '0' && ch <= '9')
    {
      m[i].pan[j] = ch;
      printf("%c", m[i].pan[j]);
      j++;
    }
    else if (ch == 8 && j > 0)
    {
      printf("\b \b");
      j--;
    }
  }
  if (ch ==27)
  {
    home();
  }
}

void transection()
{

  printf("\n\naccount number:- ");
  j = 0;
  while (1)
  {

    if (j == 4)
      break;

    ch = getch();
    if (ch == 27 || ch == 32)
    {
      break;
    }
    if (ch == 8 && j > 0)
    {
      printf("\b \b");
      j--;
      continue;
    }

    if (ch >= '0' && ch <= '9')
    {
      cpin1[j] = ch;
      printf("%c", ch);
      j++;
    }
  }
  if (ch == 27)
    home();
  if (ch == 32)
  {
    acc();
    transection();
  }
  cpin1[j] = '\0';

  temp_acc_number = atoi(cpin1);
  for (j = 0; j < i; j++)
  {
    if (temp_acc_number == m[j].acc_number)
    {
      in = j;
      j = 33;
      break;
      // cheak how many digit is acc no.
    }
  }

  printf("\n\n%s", m[in].name);

  if (j == 33)
  {
    printf("\n\n1] Deposite");
    printf("\n2] Witndraw");
    printf("\n3] send ");

    while (1)
    {
      a = getch();
      if (a > 48 && a < 52 || a == 27)
	break;
    }

    switch (a)
    {
    case '1':
      deposite();
      break;
    case '2':
      withdraw();
      break;
    case '3':
      send1();
      break;
    case 27 :
    home();
    }
  }
  else
  {
    clrscr();
    transection();
  }
}

void send1()
{
  u = in;
  clrscr();
  printf("\n\nSEND\n\n");

  printf("account number:- ");
  j = 0;
  while (1)
  {

    if (j == 4 || ch == 27)
    {
      break;
    }
    ch = getch();

    if (ch == 8 && j > 0)
    {
      printf("\b \b");
      j--;
      continue;
    }

    if (ch >= '0' && ch <= '9')
    {
      cpin1[j] = ch;
      printf("%c", ch);
      j++;
    }
  }
  if (ch == 27)
    home();

  cpin1[j] = '\0';
  temp_acc_number = atoi(cpin1);

  for (j = 0; j < i; j++)
  {
    if (temp_acc_number == m[j].acc_number)
    {
      u = 0;
      break;
    }
  }
  if (u == 0)
  {

   u = j;

    printf("\nname:- %s\n", m[u].name);

    printf("\namount:- ");
    j = 0;
    while (1)
    {
      ch = getch();
      if (ch == 13 || ch == 27)
      {
	break;
      }
      if (ch == 8 && j > 0)
      {
	printf("\b \b");
	j--;
	continue;
      }

      if (ch >= '0' && ch <= '9')
      {
	cpin1[j] = ch;
	printf("%c", ch);
	j++;
      }
    }
    if (ch == 27)
      home();

    cpin1[j] = '\0';
    h[in][I[in]].transfer = atol(cpin1);
    if (m[in].acc_balance < h[in][I[in]].transfer)
    {
      printf("\n\ninsufficient balance");
      ch = 0;
      while (ch != 27)
      {
	ch = getch();
      }
      home();
    }

    m[in].acc_balance += h[in][I[in]].transfer;
    m[u].acc_balance -= h[in][I[in]].transfer;
    h[u][I[u]].transfer = h[in][I[in]].transfer;
    h[in][I[in]].balance = m[in].acc_balance;
    h[u][I[u]].balance = m[u].acc_balance;

    Time();
     I[in]++;
    in = u;
    Time();
    I[u]++;

    printf("\ndone");
  }
  else
    send1();
  while (1)
  {
    a = getch();
    if (a == 27)
      break;
  }

  home();
}

void loan()
{
  struct tm *current_time = localtime(&t);

  printf("\n\nLOAN\n\n");
  printf("account number:- ");
  j = 0;
  while (1)
  {

    ch = getch();
    if (ch == 13 ||ch == 27)
    {
      break;
    }
    if (ch == 8 && j > 0)
    {
      printf("\b \b");
      j--;
      continue;
    }

    if (ch >= '0' && ch <= '9')
    {
      cpin1[j] = ch;
      printf("%c", ch);
      j++;
    }
  }
  if (ch == 27)
    home();

  cpin1[j] = '\0';
  temp_acc_number = atoi(cpin1);

  for (j = 0; j < i; j++)
  {
    if (temp_acc_number == m[j].acc_number){
     in = 0;
  break;
  }
  }
  if (in == 0)
  {
    in = j;
    if (m[in].score < 1500)
    {
      printf("\n\nnot eligible");
      while (ch != 27)
      {
	ch = getch();
      }
      home();
    }
    l[L].acc_number = m[in].acc_number;
    printf("\nname:- %s\n\n", m[in].name);
    printf("employment status:-\n\n");
    printf("1] employed\n\n2] self-employed\n\n3] unemployed ");
    while (1)
    {
      a = getch();
      if (ch == 27)
      {
	break;
      }
      if (a == 49)
      {
	strcpy(l[L].employment_status, "employed");
	break;
      }
      else if (a == 50)
      {
	strcpy(l[L].employment_status, "self-employed");
	break;
      }
      else if (a == 51)
      {
	strcpy(l[L].employment_status, "unemployed");
	break;
      }
    }
    if (ch == 27)
    {
      home();
    }
    if (a != 51)
    {
      printf("\n\nmonthly income :- ");
      j = 0;
      while (1)
      {
	a = getch();
	if (a == 8)
	{
	  printf("\b \b");
	  j--;
	  continue;
	}
	if (a < 58 && a > 47)
	{
	  cpin1[j] = a - 48;
	  printf("%c",a);
	  j++;
	}
	if (a == 13 || a == 27)
	{
	  break;
	}
      }
      if ( a == 27 )
      {
	home();
      }
      cpin1[j] = '\0';
      l[L].m_income = atol(cpin1);
    }
    printf("\n\nloan amount repuest:-");
    j = 0;
    while (1)
    {
      ch = getch();
      if (ch == 8)
      {
	printf("\b \b");
	j--;
	continue;
      }
      if (ch < 58 && ch > 47)
      {
	cpin1[j] = ch;
	printf("%c", ch);
	j++;
      }
      if (ch == 13 || ch == 27)
      {
	break;
      }
    }
    if (ch == 27)
    {
      home();
    }
    cpin1[j] = '\0';
    l[L].l_amount = atol(cpin1);
    printf("\n\npurpose of the loan:- ");
    scanf(" [^\n]", l[L].l_purpose[55]);

    time(&t);

    l[L].ldate[0] = current_time->tm_year + 1900;
    l[L].ldate[1] = current_time->tm_mon + 1;
    l[L].ldate[2] = current_time->tm_mday;
    loanc();
    L++;
  }
  else
  {
    clrscr();
    loan();
  }

  get(0);
  printf("repay date :- DD/MM/YYYY\b\b\b\b\b\b\b\b\b\b");

  j = 0;
  while (1)
  {
    if (j == 10)
    {
      if ((cpin[0] - 48) * 10 + cpin[1] - 48 < 32 && (cpin[0] - 48) * 10 + cpin[1] - 48 != 0 && (cpin[3] - 48) * 10 + cpin[4] - 48 < 13 && (cpin[3] - 48) * 10 + cpin[4] - 48 != 0 && (cpin[6] - 48) * 1000 + (cpin[7] - 48) * 100 + (cpin[8] - 48) * 10 + cpin[9] - 48 > 1910 && (cpin[6] - 48) * 1000 + (cpin[7] - 48) * 100 + (cpin[8] - 48) * 10 + cpin[9] - 48 < 2024)
	break;
    }
    if (j == 6 || j == 7 || j == 8 || j == 9)
    {
      printf("Y\b");
    }
    if (j == 3 || j == 4)
    {
      printf("M\b");
    }
    if (j == 0 || j == 1)
    {
      printf("D\b");
    }

    if (j == 2 || j == 5)
    {

      printf("/");
      j++;
    }
    cpin[j] = getch();

    if (cpin[j] == 27)
    {
      break;
    }
    if (cpin[j] == 8 && j > 0)
    {
      if (j == 3 || j == 6)
      {
	printf("\b\b \b");
	j--;
	j--;
      }
      else
      {
	printf("\b \b");
	j--;
      }
      continue;
    }
    if (cpin[j] > 47 && cpin[j] < 58 && j < 10)
    {
      printf("%c", cpin[j]);
      j++;
    }
  }
if(cpin[j]== 27)
{
  home();
}
  l[L].rdate[0] = (cpin[0] - 48) * 10 + cpin[1] - 48; // completed
  l[L].rdate[1] = (cpin[3] - 48) * 10 + cpin[4] - 48;
  l[L].rdate[2] = (cpin[6] - 48) * 1000 + (cpin[7] - 48) * 100 + (cpin[8] - 48) * 10 + cpin[9] - 48;

  printf("\n\nloan requested sucssesfuly  ");

  while (1)
  {
    ch = getch();
    if (ch == 27)
      break;
  }
  home();
}
void loanc()
{
  int A;
      float p, r = 0.01;
      p=l[L].l_amount;
  in = 10;
  Time();
  for (j = 0; j < L; j++)
  {
    if (h[in][I[in]].tdate[0] == l[L].rdate[0] && h[in][I[in]].tdate[1] == l[L].rdate[1] && h[in][I[in]].tdate[2] == l[L].rdate[2])
    {


      l[L].l_amount = p*pow((1 + r), 1 / 30);
    }
  }
}

void acc()
{
  for (j = 0; j < i; j++)
  {
    printf("\n\n%s", m[j].name);
    p = strlen(m[j].name);
    blank(30 - p);
    printf("%d\n\n", m[j].acc_number);
  }
  j = 0;
  while (1)
  {
    ch = getch();
    if (ch == 32)
      break;
  }
  clrscr();
}
