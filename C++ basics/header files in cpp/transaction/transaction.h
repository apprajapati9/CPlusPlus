struct Transaction{
	
	int acct;
	char type;
	double amount;
};

void enter(struct Transaction* tr);
void display(struct Transaction* tr);
