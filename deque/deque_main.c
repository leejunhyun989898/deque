#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef int element;
typedef struct {
	element data[MAX];
	int front, rear;

}DequeType;

void error(char* message)
{
    //fprintf(stderr, "%s\n", message);
	
}

void init_deque(DequeType* q)
{
	q->front = q->rear = 0;
}

int is_empty(DequeType* q)
{
	return (q->front == q->rear);
}

int is_full(DequeType* q)
{
	return ((q->rear + 1) % MAX == q->front);
}

void deque_print(DequeType* q)
{
	printf("DEQUE(front = %d rear = %d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) & (MAX);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

void add_rear(DequeType* q, element item)
{
	if (is_full(q))
		error("Queue MAX");
	q->rear = (q->rear + 1) % MAX;
	q->data[q->rear] = item;
}

element delete_front(DequeType* q)
{
	if (is_empty(q))
		error("Queue empty");
	q->front = (q->front + 1) % MAX;
	return q->data[q->front];
}

element get_front(DequeType* q)
{
	if(is_empty(q))
		error("Queue empty");
	return q->data[(q->front + 1) % MAX];
}

void add_front(DequeType* q, element val)
{
	if (is_full(q))
		error("Queue MAX");
	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX) % MAX;
}

element delete_rear(DequeType* q)
{
	int prev = q->rear;
	if (is_empty(q))
		error("Queue empty");
	q->rear = (q->rear - 1 + MAX) % MAX;
	return q->data[prev];
}

element get_rear(DequeType* q)
{
	if (is_empty(q))
		error("Queue empty");
	return q->data[q->rear];
}
int palindrome(char string[])
{
    DequeType q;
    int i = 0;
    init_deque(&q);

    while (string[i] != NULL)
    {
        if (isalpha(string[i]))
        {
            char c = tolower(string[i]); 
            add_rear(&q, c);
        }
        i++;
    }

    i = 0;
    while (string[i] != NULL)
    {
        if (isalpha(string[i]))
        {
            char c = tolower(string[i]); 
            if (delete_rear(&q) != delete_front(&q))
            {
                return 0; // 스택과 비교한 결과가 다를때
            }
        }
        i++;
    }
    if (is_empty)return 1;
    else return 0;

}
int main(void)
{
    char string[MAX] = { NULL };
    char check[MAX] = { NULL };
    int c = 1;
    while (c)
    {
        printf("문자열을 입력하세요: ");
        gets(string);
        if (palindrome(string) == 1)
        {
            printf("화문입니다\n");
        }
        else {
            printf("화문이 아닙니다\n");
        }
        printf("\n계속 하시려면 아무키나, 그만두시려면 no를 입력해주세요: ");
        gets(check);
        printf("\n");
        if (strcmp(check, "no") == 0) // 입력값이 "no"일 때
        {
            
            printf("종료합니다.\n");
            break;
        }
    }

    return 0;
}