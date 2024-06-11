#include <stdio.h>
#include <stdlib.h>
int signal(int);
    int wait(int);
    void producer();
    void consumer();
int full = 0, empty = 3, x = 0, mutex = 1;
int main()
{
    int n;
    printf("1.producer\t2.consumer\t3.exit");
    while (1)
    {
        printf("\nenter your choice");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            if (mutex == 1 && empty != 0)
            {
                producer();
            }
            else
            {
                printf("buffer is full");
            }
            break;
        case 2:
            if (mutex == 1 && full != 0)
            {
                consumer();
            }
            else
            {
                printf("buffer is empty");
            }
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
        }
    }
}
int signal(int s)
{
    return ++s;
}
int wait(int s)
{
    return --s;
}
void producer()
{
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    printf("producer produces the item %d", x);
    mutex = signal(mutex);
}
void consumer()
{
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("consumer consumes the item %d", x);
    x--;
    mutex = signal(mutex);
}