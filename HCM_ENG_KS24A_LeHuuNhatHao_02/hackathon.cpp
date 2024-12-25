#include <stdio.h>

int main(){
    int choice,element,arr[1000],i, currentLength, addElement, deleteIndex, searchElement, found,foundPrime = 0, temp;
    int count, j, left, right;
    do
    {
        printf ("**************************************************\n");
        printf ("MENU\n");
        printf ("\n");
        printf ("1. Nhap so phan tu va gia tri cho mang\n");
        printf ("2. In cac phan tu trong mang\n");
        printf ("3. Dem so luong cac phan tu chan, le trong mang\n");
        printf ("4. Tim gia tri lon thu 2 trong mang\n");
        printf ("5. Them mot phan tu vao dau mang\n");
        printf ("6. Xoa phan tu tai vi tri cu the\n");
        printf ("7. Sap xep mang theo thu tu giam dan dung Insertion Sort\n");
        printf ("8. Tim kiem mot phan tu trong mang dung Binary Search\n");
        printf ("9. In ra toan bo so nguyen to trong mang va binh phuong chung len\n");
        printf ("10. Sap xep mang theo thu tu giam dan dung Bubble Sort\n");
        printf ("11. Thoat\n");
        printf ("**************************************************\n");
        printf ("Lua chon cua ban: ");
        scanf ("%d", &choice);
        switch (choice)
        {
        case 1:
            printf ("Nhap so phan tu cua mang: ");
            scanf ("%d", &element);
            currentLength = element;
            for (i = 0; i < element; i++)
            {
                printf ("Nhap phan tu thu %d: ", i);
                scanf ("%d", &arr[i]);
            }
            break;
        case 2:
            printf ("Cac phan tu trong mang la: ");
            for (i = 0; i < currentLength; i++)
            {
                printf ("arr[%d] = %d ",i, arr[i]);
            }
            printf ("\n");
            break;
        case 3: {
            int evenCount = 0, oddCount = 0;
            for (i = 0; i < currentLength; i++)
            {
                if (arr[i]%2==0)
                {
                    evenCount++;
                }else {
                    oddCount++;
                }
            }
            printf ("So luong cac phan tu chan la: %d\n", evenCount);
            printf ("So luong cac phan tu le la: %d\n", oddCount);
            break;
        }
        case 4: {
            int max1, max2;
            if (currentLength < 2) {
                printf("Mang phai co it nhat 2 phan tu de tim gia tri lon thu 2\n");
            } else {
                if (arr[0] > arr[1]) {
                    max1 = arr[0];
                    max2 = arr[1];
                } else {
                    max1 = arr[1];
                    max2 = arr[0];
                }
                for (i = 2; i < currentLength; i++) {
                    if (arr[i] > max1) {
                        max2 = max1;
                        max1 = arr[i];
                    } else if (arr[i] > max2) {
                        max2 = arr[i];
                    }
                }
                printf("Gia tri lon thu 2 trong mang la: %d\n", max2);
            }
            break;
        }
        case 5:
            printf ("Nhap gia tri ban muon them vao dau mang: ");
            scanf ("%d", &addElement);
            for (i = currentLength; i > 0; i--)
            {
                arr[i] = arr[i-1];
            }
            arr[0] = addElement;
            currentLength++;
            break;
        case 6:
            printf ("Nhap vi tri ban muon xoa: ");
            scanf ("%d", &deleteIndex);
            if (deleteIndex >= 0 && deleteIndex < currentLength) {
                for (i = deleteIndex; i < currentLength - 1; i++)
                {
                    arr[i] = arr[i+1];
                }
                currentLength--;
            } else {
                printf("Vi tri xoa khong hop le!\n");
            }
            break;
        case 7:
            for (i = 1; i < currentLength; i++)
            {
                int key = arr[i];
                int j = i-1;
                while (j>=0 && arr[j]<key)
                {
                    arr[j+1] = arr[j];
                    j--;
                }
                arr[j+1] = key;
            }
            printf ("Mang da duoc sap xep theo thu tu giam dan dung Insertion sort\n");
            break;
        case 8:
            printf ("Nhap gia tri ban muon tim kiem: ");
            scanf ("%d", &searchElement);
            for (i = 0; i < currentLength; i++)
            {
                for (int j = 0; j < currentLength-1; j++)
                {
                    if (arr[j] > arr[j+1])
                    {
                        int temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
                    }
                }
            }
            left = 0;
            right = currentLength-1;
            found = 0;
            while (left<=right)
            {
                int mid = (left+right)/2;
                if (arr[mid]==searchElement)
                {
                    printf ("Gia tri %d duoc tim thay tai vi tri %d\n", searchElement, mid);
                    found = 1;
                    break;
                }else if (arr[mid]<searchElement)
                {
                    left = mid+1;
                }else {
                    right = mid-1;
                }
            }
                if (!found)
                {
                    printf ("Khong tim thay gia tri %d trong mang\n", searchElement);
                }
                break;
        case 9:
            foundPrime = 0;
            for (i = 0; i < currentLength; i++)
            {
                count = 0;
                for (j = 1; j <= arr[i]; j++)
                {
                    if (arr[i]%j==0)
                    {
                        count++;
                    }
                }
                if (count==2)
                {
                    printf ("So nguyen to: %d\n", arr[i]);
                    printf ("Binh phuong cua so nguyen to: %d\n", arr[i]*arr[i]);
                    foundPrime = 1;
                }
            }
            if (!foundPrime)
            {
                printf ("Khong co so nguyen to trong mang\n");
            }
            break;
        case 10:
            for (i = 0; i < currentLength; i++)
            {
                for (j = 0; j < currentLength-1; j++)
                {
                    if (arr[j]<arr[j+1])
                    {
                        temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
                    }
                }
            }
            printf ("Mang da duoc sap xep theo thu tu giam dan dung Bubble Sort\n");
            break;
        case 11:
            printf ("Thoat Chuong Trinh\n");
            break;
        default:
            printf ("Vui long chon dung chuc nang!! (1-11)\n");
            break;
        }
    } while (choice!=11);
    return 0;
}