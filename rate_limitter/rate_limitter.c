#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define RATE_LIMIT 10
#define TIME_WINDOW 60

// Struct to store each request time
typedef struct {
	time_t requests[RATE_LIMIT];
	int count;
} User;

int is_allowed(User *user) {
	time_t current_time = time(NULL);

	// Remove timestamps outside time window
	int valid_count = 0;
	for (int i = 0; i < user->count; i++) {
		if (current_time - user->requests[i] <= TIME_WINDOW) {
			user->requests[valid_count++] = user->requests[i];
		}
	}
	user->count = valid_count;

	// Check if within limit
	if (user->count < RATE_LIMIT) {
		user->requests[user->count++] = current_time;
		return 1; // Request allowed
	} else {
		return 0; // Rate limit reached
	}
}

int main() {
	User user = {{0}, 0};
	
	for (int i = 0; i < 15; i++) {
		if (is_allowed(&user)) {
			printf("Request %d: Request Allowed\n", i + 1);
		} else {
			printf("Request %d: Rate Limit exceeded\n", i + 1);
		}
		sleep(5);
	}
	return 0;
}
