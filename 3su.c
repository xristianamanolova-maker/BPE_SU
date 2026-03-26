#include <stdio.h>

int main()
{
    int choice;

    printf("Choose exercise (1-9): ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
        {
            int n;

            printf("Enter N: ");
            scanf("%d", &n);

            int arr[n];

            printf("Enter the sorted array elements:\n");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }

            int bestStart = 0;
            int maxLength = 1;
            int currentStart = 0;
            int currentLength = 1;

            for (int i = 1; i < n; i++)
            {
                if (arr[i] == arr[i - 1])
                {
                    currentLength++;
                }
                else
                {
                    currentStart = i;
                    currentLength = 1;
                }

                if (currentLength > maxLength)
                {
                    maxLength = currentLength;
                    bestStart = currentStart;
                }
            }

            printf("Start index: %d\n", bestStart);
            printf("Length: %d\n", maxLength);
            break;
        }

        case 2:
        {
            int n;

            printf("Enter N: ");
            scanf("%d", &n);

            int arr[n];

            printf("Enter the sequence elements:\n");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }

            int valid = 1;

            for (int i = 1; i < n; i++)
            {
                if (i % 2 == 1)
                {
                    if (arr[i] <= arr[i - 1])
                    {
                        valid = 0;
                        break;
                    }
                }
                else
                {
                    if (arr[i] >= arr[i - 1])
                    {
                        valid = 0;
                        break;
                    }
                }
            }

            if (valid)
            {
                printf("The sequence satisfies the condition.\n");
            }
            else
            {
                printf("The sequence does NOT satisfy the condition.\n");
            }

            break;
        }

        case 3:
        {
            int n;

            printf("Enter N: ");
            scanf("%d", &n);

            int arr[n];

            printf("Enter elements:\n");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }

            for (int i = 0; i < n / 2; i++)
            {
                int temp = arr[i];
                arr[i] = arr[n - 1 - i];
                arr[n - 1 - i] = temp;
            }

            printf("Reversed array:\n");
            for (int i = 0; i < n; i++)
            {
                printf("%d ", arr[i]);
            }

            printf("\n");
            break;
        }

        case 4:
        {
            int n;

            printf("Enter N: ");
            scanf("%d", &n);

            int arr[n];

            printf("Enter elements:\n");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }

            int k;
            printf("Enter K: ");
            scanf("%d", &k);

            k = k % n;

            for (int step = 0; step < k; step++)
            {
                int last = arr[n - 1];

                for (int i = n - 1; i > 0; i--)
                {
                    arr[i] = arr[i - 1];
                }

                arr[0] = last;
            }

            printf("Shifted array:\n");
            for (int i = 0; i < n; i++)
            {
                printf("%d ", arr[i]);
            }

            printf("\n");
            break;
        }

        case 5:
        {
            int n;
            printf("Enter N: ");
            scanf("%d", &n);

            int arr[n];
            printf("Enter elements:\n");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }

            int k;
            printf("Enter K: ");
            scanf("%d", &k);

            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - 1 - i; j++)
                {
                    if (arr[j] < arr[j + 1])
                    {
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }

            if (k >= 1 && k <= n)
            {
                printf("The K-th largest element is: %d\n", arr[k - 1]);
            }
            else
            {
                printf("Invalid K.\n");
            }

            break;
        }

        case 6:
        {
            int n;
            printf("Enter N: ");
            scanf("%d", &n);

            int arr[n];
            printf("Enter elements:\n");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }

            int incStart = 0, incLen = 1;
            int currIncStart = 0, currIncLen = 1;

            int decStart = 0, decLen = 1;
            int currDecStart = 0, currDecLen = 1;

            for (int i = 1; i < n; i++)
            {
                if (arr[i] > arr[i - 1])
                {
                    currIncLen++;
                }
                else
                {
                    if (currIncLen > incLen)
                    {
                        incLen = currIncLen;
                        incStart = currIncStart;
                    }
                    currIncStart = i;
                    currIncLen = 1;
                }

                if (arr[i] < arr[i - 1])
                {
                    currDecLen++;
                }
                else
                {
                    if (currDecLen > decLen)
                    {
                        decLen = currDecLen;
                        decStart = currDecStart;
                    }
                    currDecStart = i;
                    currDecLen = 1;
                }
            }

            if (currIncLen > incLen)
            {
                incLen = currIncLen;
                incStart = currIncStart;
            }

            if (currDecLen > decLen)
            {
                decLen = currDecLen;
                decStart = currDecStart;
            }

            if (incLen >= decLen)
            {
                printf("Longest increasing subsequence:\n");
                for (int i = incStart; i < incStart + incLen; i++)
                {
                    printf("%d ", arr[i]);
                }
                printf("\nLength: %d\n", incLen);
            }
            else
            {
                printf("Longest decreasing subsequence:\n");
                for (int i = decStart; i < decStart + decLen; i++)
                {
                    printf("%d ", arr[i]);
                }
                printf("\nLength: %d\n", decLen);
            }

            break;
        }

        case 7:
        {
            int n;
            printf("Enter N: ");
            scanf("%d", &n);

            int arr[n];
            printf("Enter elements:\n");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }

            int target;
            printf("Enter target sum: ");
            scanf("%d", &target);

            int found = 0;

            for (int i = 0; i < n; i++)
            {
                int sum = 0;

                for (int j = i; j < n; j++)
                {
                    sum += arr[j];

                    if (sum == target)
                    {
                        printf("Sequence found:\n");
                        for (int k = i; k <= j; k++)
                        {
                            printf("%d ", arr[k]);
                        }
                        printf("\n");
                        found = 1;
                        break;
                    }
                }

                if (found)
                {
                    break;
                }
            }

            if (!found)
            {
                printf("No such sequence.\n");
            }

            break;
        }

        case 8:
        {
            int arr[20];
            int n = 10;

            printf("Enter 10 elements:\n");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }

            int num, pos;

            while (n < 20)
            {
                printf("Enter number (0 to stop): ");
                scanf("%d", &num);

                if (num == 0)
                    break;

                printf("Enter position: ");
                scanf("%d", &pos);

                if (pos < 0 || pos > n)
                {
                    printf("Invalid position\n");
                    continue;
                }

                for (int i = n; i > pos; i--)
                {
                    arr[i] = arr[i - 1];
                }

                arr[pos] = num;
                n++;
            }

            printf("Final array:\n");
            for (int i = 0; i < n; i++)
            {
                printf("%d ", arr[i]);
            }

            printf("\n");

            break;
        }

        case 9:
        {
            int n;

            printf("Enter N: ");
            scanf("%d", &n);

            int arr[n];

            printf("Enter elements:\n");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }

            int bestStart = 0, maxLen = 1;
            int currStart = 0, currLen = 1;

            for (int i = 1; i < n; i++)
            {
                if (arr[i] == arr[i - 1])
                {
                    currLen++;
                }
                else
                {
                    currStart = i;
                    currLen = 1;
                }

                if (currLen > maxLen)
                {
                    maxLen = currLen;
                    bestStart = currStart;
                }
            }

            printf("Longest sequence:\n");
            for (int i = bestStart; i < bestStart + maxLen; i++)
            {
                printf("%d ", arr[i]);
            }

            printf("\n");

            break;
        }

        default:
        {
            printf("Invalid choice.\n");
            break;
        }
    }

    return 0;
}

