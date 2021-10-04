#include <stdio.h>

int main()
{
    int n;
    printf("Enter the Size of array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int ch = 1;
    int temp;
    int position;
    int choice;
    while (ch)
    {
        printf("Enter the element to be searched: ");
        scanf("%d", &temp);
        for (int i = 0; i < n; i++)
        {
            if (temp == a[i])
            {
                position = i;
                break;
            }
            else
                position = -1;
        }
        if (position == -1)
        {
            printf("There is no such element.");
            goto ab;
        }
        else
        {
            printf("The element is at %d position.\nDo you want to delete this element?(Enter 1 for yes and 0 for no): ", position + 1);
            scanf("%d", &choice);
            if (choice)
            {
                for (int i = position; i < n; i++)
                {
                    a[i] = a[i + 1];
                }
                printf("Enter the last element in the array: ");
                scanf("%d", &temp);
                a[n - 1] = temp;
            }
        }
    ab:
        printf("The array is:\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\nDo you want to do more operations on array(Enter 1 for yes and 0 for no): ");
        scanf("%d", &ch);
    }
    return 0;
}