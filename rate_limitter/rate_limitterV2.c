#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define RATE_LIMIT 1
#define TIME_WINDOW 60
#define MAX_USERS 10

// Struct to store request times for each user
typedef struct {
    char ip_address[16];
    time_t requests[RATE_LIMIT];
    int count;
} User;

// Array to store multiple users (IPs)
User users[MAX_USERS];
int user_count = 0;

// Find or create a user by IP address
User* find_or_create_user(const char *ip_address) {
    // Check if user already exists
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].ip_address, ip_address) == 0) {
            return &users[i];
        }
    }

    // If user does not exist and we have space, create a new user
    if (user_count < MAX_USERS) {
        User *new_user = &users[user_count++];
        strncpy(new_user->ip_address, ip_address, 16);
        new_user->count = 0;
        return new_user;
    }

    return NULL;  // No space for new users
}

int is_allowed(User *user) {
    time_t current_time = time(NULL);

    // Remove timestamps outside the time window
    int valid_count = 0;
    for (int i = 0; i < user->count; i++) {
        if (current_time - user->requests[i] <= TIME_WINDOW) {
            user->requests[valid_count++] = user->requests[i];
        }
    }
    user->count = valid_count;

    // Check if within rate limit
    if (user->count < RATE_LIMIT) {
        user->requests[user->count++] = current_time;
        return 1;  // Request allowed
    } else {
        return 0;  // Rate limit exceeded
    }
}

int main() {
    // Simulate incoming requests from different IPs
    const char *test_ips[] = {
        "192.168.1.1", "192.168.1.2", "192.168.1.1", "192.168.1.3",
        "192.168.1.1", "192.168.1.2", "192.168.1.1", "192.168.1.3",
        "192.168.1.1", "192.168.1.2", "192.168.1.1", "192.168.1.3",
        "192.168.1.1", "192.168.1.2", "192.168.1.1"
    };

    for (int i = 0; i < 15; i++) {
        const char *ip = test_ips[i];
        User *user = find_or_create_user(ip);

        if (user != NULL) {
            if (is_allowed(user)) {
                printf("Request from %s: Allowed\n", ip);
            } else {
                printf("Request from %s: Rate limit exceeded\n", ip);
            }
        } else {
            printf("Cannot track more users, request from %s ignored.\n", ip);
        }

        // Delay between requests
        sleep(1);
    }

    return 0;
}

