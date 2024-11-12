// adding element when array is not full

#include <stdio.h>

// function to add elements in the list
void add(int arr[], int data, int i)
{
    arr[i] = data;
}

// function for printing the elements of array
void print(int arr[], int size)
{

    printf("The elements in the list are : {");

    for (int p = 0; p < size; p++)
    {
        printf(" %d ", arr[p]);
    }

    printf("}\n");
}

int main()
{

    int n;
    printf("Do you want to create an array? 1/0 ");
    scanf("%d", &n);

    if (n == 1)
    {
        int size;
        printf("Enter the number of elements inside the array : ");
        scanf("%d", &size);

        int arr[size];

        for (int i = 0; i < size; i++)
        {
            int input;
            printf("Input value : ");
            scanf("%d", &input);
            add(arr, input, i);
        }

        print(arr, size);

        int more;
        printf("Do you want to add more in the list? 1/0 ");
        scanf("%d", &more);

        if (more == 1)
        {
            int newelements;
            printf("How many more elements do you want to add in the array? : ");
            scanf("%d", &newelements);

            //creating a new array 
            int newarr[size + newelements];

            //copying the elements from the full array
            for (int i = 0; i < size; i++)
            {
                newarr[i] = arr[i];
            }

            //inputting new values
            for (int i = size; i < size + newelements; i++)
            {
                int input;
                printf("Input value :");
                scanf("%d", &input);
                add(newarr, input, i);
            }

            print(newarr, size + newelements);
        }

        else
        {
            return 1;
        }
    }

    else
    {
        return 1;
    }

    return 0;
}