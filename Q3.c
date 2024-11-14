#include <stdio.h>
void calculate_sum_and_average(int *arr, int n, int *sum, float *average)
{
    *sum = 0;
    for (int i = 0; i < n; i++)
    {
        *sum += arr[i];
    }

    if (n < 0)
    {

        *average = 0.0;
        return;
    }

    *average = (float)*sum / n;
}
int main()
{
    int n;
    printf("Enter size of the array :");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    int sum = 0;
    float average = 0.0;

    calculate_sum_and_average(arr, n, &sum, &average);

    printf("Sum of all elements of the array is :%d", sum);
    printf("\nSum of all elements of the array is :%f", average);
    return 0;
}