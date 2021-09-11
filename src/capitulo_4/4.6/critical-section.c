#include <pthread.h>
#include <stdio.h>
#include <string.h>

float account_balances[] = {750.50, 675.25, 450.75, 982.66, 286.26, 937.34, 965.43, 384.77, 195.82, 996.10};
const int num_transactions = 5;
const int num_accounts = 10;

struct transaction{
	int from_acct, to_acct;
	float dollars;
};

void* process_transaction(void* thread_args){
	struct transaction tr = *((struct transaction*)thread_args);

	int old_cancel_state;

	if(account_balances[tr.from_acct] < tr.dollars)
		return (void*)1;

	/* Begin critical section */

	pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, &old_cancel_state);

	/* Move the money */

	account_balances[tr.to_acct] += tr.dollars;
	account_balances[tr.from_acct] -= tr.dollars;

	/* End critical section */

	pthread_setcancelstate(old_cancel_state, NULL);

	return (void*)0;

}

int main(){

	struct transaction transactions[] = {	{0, 1, 250.65},
											{7, 6, 150.25},
											{2, 9, 350.67},
											{5, 3, 150.77},
											{4, 1, 250.00}};

	int i;

	pthread_t threads_id[num_transactions];

	printf("Account balances before transactions\n");

	for(i = 0; i < num_accounts; ++i)
		printf("%d: %.2f\n", i, account_balances[i]);

	for(i = 0; i < num_transactions; ++i)
		pthread_create(&threads_id[i], NULL, &process_transaction, &transactions[i]);

	/* To demonstrate that threads are uncancelable */
	for(i = 0; i < num_transactions; ++i)
		pthread_cancel(threads_id[i]);

	for(i = 0; i < num_transactions; ++i)
		pthread_join(threads_id[i], NULL);

	printf("\nAccount balances before transactions\n");

	for(i = 0; i < num_accounts; ++i)
		printf("%d: %.2f\n", i, account_balances[i]);

	return 0;
}