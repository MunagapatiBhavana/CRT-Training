int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int maxArea = 0;

    while (left < right) {
        int h = height[left] < height[right] ? height[left] : height[right];
        int w = right - left;
        int area = h * w;
        if (area > maxArea)
            maxArea = area;

        // Move the shorter line inward
        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return maxArea;
}
