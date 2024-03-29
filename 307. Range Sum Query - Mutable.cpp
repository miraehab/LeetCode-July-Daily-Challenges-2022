class NumArray {
    int size;
    vector<int> tree;
public:
    
    NumArray(vector<int>& nums) {
        size = nums.size();
        tree.resize(2*size);
        buildTree(nums);
    }
    
    void buildTree(vector<int>& nums) {
        for (int i = size, j = 0;  i < 2 * size; i++,  j++)
            tree[i] = nums[j];
        for (int i = size - 1; i > 0; --i)
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
    
    void update(int index, int val) {
        index += size;
        tree[index] = val;
        while (index > 0) {
            int left = index;
            int right = index;
            if (index % 2 == 0) {
                right = index + 1;
            } else {
                left = index - 1;
            }
            tree[index / 2] = tree[left] + tree[right];
            index /= 2;
        }
    }
    
    int sumRange(int l, int r) {
        l += size;
        r += size;
        int sum = 0;
        while (l <= r) {
            if ((l % 2) == 1) {
               sum += tree[l];
               l++;
            }
            if ((r % 2) == 0) {
               sum += tree[r];
               r--;
            }
            l /= 2;
            r /= 2;
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */