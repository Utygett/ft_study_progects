#include <vector>
#include <iostream>
#include <string>
#include <map>
using namespace std;
// 2 7 11 15

// 2  2  2
// 7  11 15

// 7 7
// 11 15

// 11
// class Solution1 { 
// public:
//     std::vector<int> twoSum(std::vector<int>& nums, int target) {
//         std::vector<int> res(2,0);
// 		for(size_t i = 0; i < nums.size(); ++i)
// 		{
// 			for(size_t j = i + 1; j < nums.size();++j)
// 			{
// 				if(nums[i] + nums[j] == target)
// 				{
// 					res[0] = i;
// 					res[1] = j;
// 					return(res);
// 				}
// 			}
// 		}
// 		return(res);
//     }
// };

// class Solution1 {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int,int> val;
// 		for(int i = 0; i < nums.size(); ++i)
// 		{
//             auto j = val.find(target - nums[i]);
//              if(j != val.end())
//              {
//                  return{j->second, i};             
//              }
//             val[nums[i]] = i;
//         }
//         return{-1,-1};
//     }
// };

// int main()
// {
// 	vector<int> nums;
// 	vector<int> nums1;
// 	nums.push_back(2);
// 	nums.push_back(7);
// 	nums.push_back(11);
// 	nums.push_back(15);
// 	Solution1 a;
// 	nums1 = a.twoSum(nums, 9);
// 	cout << "First  " << nums1[0] << endl; 
// 	cout << "Second " << nums1[1] << endl;
// }


// #include <stdexcept>
// #include <string>
// #include <iostream>

// class Node
// {
// public:
//     Node(int value, Node* left, Node* right)
//     {
//         this->value = value;
//         this->left = left;
//         this->right = right;
//     }

//     int getValue() const
//     {
//         return value;
//     }

//     Node* getLeft() const
//     {
//         return left;
//     }

//     Node* getRight() const
//     {
//         return right;
//     }

// private:
//     int value;
//     Node* left;
//     Node* right;
// };



// class BinarySearchTree
// {
// public:
//     static bool contains(const Node& root, int value)
//     {
//         if(root.getValue() > value)
//             return BinarySearchTree::contains(*(root.getLeft()), value);
//         else if(root.getValue() < value)
//             return BinarySearchTree::contains(*(root.getRight()), value);
//         else if(root.getValue() == value)
//             return (true);
//         else
//             throw std::logic_error("Waiting to be implemented");
//     }
// };

// #ifndef RunTests
// int main()
// {
//     Node n1(1, NULL, NULL);
//     Node n3(3, NULL, NULL);
//     Node n2(2, &n1, &n3);
    
    

//     std::cout << BinarySearchTree::contains(n2, 3);
// }

// #endif

// #include <stdexcept>
// #include <iostream>
// #include <vector>
// #include <utility>
// #include <algorithm>


// std::pair<int, int> findTwoSum(const std::vector<int>& list, int sum)
// {
//     if(list.size() < 2)
//         throw std::logic_error("Waiting to be implemented");
//     std::pair<int, int> res;
//     for(int i = 0; i < list.size(); i++)
//     {
//         auto j = find(list.begin(), list.end(), sum - list[i]);
//         if(j != list.end())
//         {
//             res.first = i;
//             res.second = list.end() - j;
//             return(res);
//         }
        
//     }
//     res.first = -1;
//     res.second = -1;
//     return(res);
// }

// #ifndef RunTests
// int main()
// {
//     std::vector<int> list = {3, 1, 5, 7, 5, 9};
//     std::pair<int, int> indices = findTwoSum(list, 10);
//     std::cout << indices.first << '\n' << indices.second;
// }
// #endif


// struct ListNode {
// 	int val;
// 	ListNode *next;
// 	ListNode() : val(0), next(nullptr) {}
// 	ListNode(int x) : val(x), next(nullptr) {}
// 	ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

// class Solution2 {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         size_t a;
//         size_t b;
//         size_t c;
//         a = 0;
//         b = 0;
// 		c = 0;
// 		ListNode *res;
//         res = nullptr;
//         while(l1 || l2)
//         {
// 			if(l1)
// 			{	
// 				b = l1->val;
// 				l1 = l1->next;
// 			}
// 			else
// 				b = 0;
// 			if(l2)
// 			{
// 				c = l2->val;
//           		l2 = l2->next;
// 			}
// 			else
// 				c = 0;
//             ListNode *tmp = new ListNode(0);
// 			tmp->val = b + c + a;
// 			if (a)
// 				a = 0;
// 			if(tmp->val >= 10)
// 			{
// 				a = 1;
// 				tmp->val -= 10;
// 			}
// 			addBack(&res, tmp);
// 		}
// 		if(a)
// 		{
// 			addBack(&res, new ListNode(a));
// 		}
//         return res;
//     }
// 	void addBack(ListNode **start, ListNode *node)
// 	{
// 		ListNode *tmp;
// 		tmp = *start;
// 			cout << "node : "<< node->val << endl;
// 		if(!*start)
// 		{
// 			*start = node;
// 		}
// 		else
// 		{
// 			while(tmp->next)
// 			{
// 				tmp = tmp->next;
// 			}
// 			tmp->next = node;
// 		}
// 	}
// };
// //

// int main()
// {
// 	ListNode *l1;
// 	ListNode *l2;
// 	ListNode *res;
// 	l1 = new ListNode(9,nullptr);
// 	l1 = new ListNode(4,l1);
// 	l1 = new ListNode(2,l1);

// 	l2 = new ListNode(9,nullptr);
// 	l2 = new ListNode(4,l2);
// 	l2 = new ListNode(6,l2);
// 	l2 = new ListNode(5,l2);
// 	Solution2 a;
// 	res = a.addTwoNumbers(l1, l2);
// 	while(res)
// 	{
// 		cout << res->val << endl;
// 		res = res->next;
// 	}
// }


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		map<char,char> a;
		int res = 0;
        for(size_t i = 0; i < s.size(); ++i)
        {
			auto it = a.find(s[i]);
  			if (it == a.end())
			  a.insert({s[i],s[i]});
            else
            {
				if(a.size() > res)
					res = a.size();
				i -= a.size();
                a.clear();
            }
        }
		if(a.size() > res)
					res = a.size();
        return (res);
    }
};

int main()
{
	Solution a;
	
	cout << a.lengthOfLongestSubstring("aab") << endl;
}