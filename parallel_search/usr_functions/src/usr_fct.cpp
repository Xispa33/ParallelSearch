#include "usr_fct.h"

extern void USR_FCT__GetRandomWords(vector<string>* words_vector)
{
    string word(4, 'A');
    for (int i = 'A'; i <= 'C'; ++i) {
        word[0] = i; 
        for (int j = 'A'; j <= 'C'; ++j) {
            word[1] = j;
            for (int k = 'A'; k <= 'C'; ++k) {
                word[2] = k; 
                for (int l = 'A'; l <= 'C'; ++l) {
                    word[3] = l; 
                    words_vector->push_back(word);
                }
            }
        }
    }
}

extern void USR_FCT__DisplayAllWords(vector<string>* words_vector)
{
    vector<string>::iterator it;
    for (it = words_vector->begin(); it != words_vector->end(); ++it) {
        cout << *it << endl;
    }
}

extern void USR_FCT__ShuffleWords(vector<string>* words_vector)
{
    // obtain a time-based seed
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(words_vector->begin(), words_vector->end(), default_random_engine(seed));
}

extern int USR_FCT__RunClient()
{
    int sock = 0, valread;
	struct sockaddr_in serv_addr;
	char *hello = "AB";
    //string hello = "";
	char buffer[1024] = {0};
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
		return -1;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	
	// Convert IPv4 and IPv6 addresses from text to binary form
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
	{
		printf("\nInvalid address/ Address not supported \n");
		return -1;
	}

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("\nConnection Failed \n");
		return -1;
	}

    //cout << "[CLIENT]: PATTERN TO SEARCH: ";
    //cin >> hello;
    //scanf("%s", hello);
    //printf("\n%s", hello);
    send(sock , hello , strlen(hello) , 0 );
	//printf("Hello message sent\n");

    //valread = read( sock , buffer, 1024);
	printf("[CLIENT]: Result received:\n%s\n",buffer );
    
}