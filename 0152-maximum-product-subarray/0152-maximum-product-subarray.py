class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        currentProduct = 1
        maxProduct = float('-inf')

        for num in nums:
            currentProduct *= num

            if currentProduct > maxProduct:
                maxProduct = currentProduct

            if currentProduct == 0:
                currentProduct = num

            if num > maxProduct:
                maxProduct = num

        currentProduct = 1
        for num in nums[::-1]:
            currentProduct *= num

            if currentProduct > maxProduct:
                maxProduct = currentProduct

            if currentProduct == 0:
                currentProduct = num



        return maxProduct


        
        