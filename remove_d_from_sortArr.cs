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
} 

public class Program
{
    public static void Main()
    {
        int[] nums = { 1, 1, 3, 3, 3, 4, 5, 6, 6 };
        Console.WriteLine("array:");
        foreach (int i in nums)
        {
            Console.Write(nums[i] + ", ");
        }

        Console.WriteLine();
        
        Solution solution = new Solution();
        int k = solution.RemoveDuplicates(nums);

        Console.WriteLine("amount of unique elements: " + k);
        Console.WriteLine("new array:");
        for (int i = 0; i < k; i++)
        {
            Console.Write(nums[i] + ", ");
        }
    }
}
