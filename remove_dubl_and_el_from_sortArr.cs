//26 and 27
using System.Collections.Specialized;

public class Solution
{
    public int RemoveDuplicates(int[] nums)
    {
        int k = 1;
        int sizee = nums.Length;
        for (int i = k; i < sizee; i++)
        {
            if (nums[i] != nums[i - 1])
            {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
    public int RemoveElement(int[] nums, int val)
    {
        int k = 0;
        for (int i = 0; i < nums.Length; i++)
        {
            if (nums[i] != val) { nums[k] = nums[i]; k++; }
        }
        return k;  

    }

}

public class Program
{
    public static void Main()
    {
        int[] nums = { 1, 1, 3, 3, 3, 4, 5, 6, 6 };
        int[] nums2 = { 1, 1, 3, 3, 3, 4, 5, 6, 6 };
        Console.WriteLine("array:");
        foreach (int i in nums)
        {
            Console.Write(nums[i] + ", ");
        }

        Console.WriteLine();
        
        Solution solution1 = new Solution();
        int k = solution1.RemoveDuplicates(nums);

        Console.WriteLine("amount of unique elements: " + k);
        Console.WriteLine("new unique array:");
        for (int i = 0; i < k; i++)
        {
            Console.Write(nums[i] + ", ");
        }
        Console.WriteLine();

        Solution solution2 = new Solution();
        int val = 3;
        int not_val = solution2.RemoveElement(nums2, val);
        Console.WriteLine("new array without '3' :");
        for (int i = 0; i < not_val; i++)
        {
            Console.Write(nums2[i] + ", ");
        }
    }
}

