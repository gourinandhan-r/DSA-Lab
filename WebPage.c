#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
    char url[100];
    struct Node *prev, *next;
};
struct Node *current = NULL;
struct Node* createNode(char *url) {
    struct Node* newNode = malloc(sizeof(struct Node));
    strcpy(newNode->url, url);
    newNode->prev = newNode->next = NULL;
    return newNode;
}
void visit(char *url) {
    struct Node* newPage = createNode(url);
    if (current) {
        current->next = newPage;
        newPage->prev = current;
    }
    current = newPage;
    printf("Visited: %s\n", current->url);
}
void back() {
    if (current && current->prev) {
        current = current->prev;
        printf("Back to: %s\n", current->url);
    } else printf("No previous page.\n");
}
void forward() {
    if (current && current->next) {
        current = current->next;
        printf("Forward to: %s\n", current->url);
    } else printf("No next page.\n");
}
int main() {
    visit("google.com");
    visit("github.com");
    visit("openai.com");
    back();
    back();
    forward();
    return 0;
}
