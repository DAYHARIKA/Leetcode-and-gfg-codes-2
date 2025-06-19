class Solution {
public:
    void solvenge(vector<int>& arr,int n,vector<int>& nge){
        stack<int> st;
        int i=n-1;
        while(i >= 0){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }
            if(st.empty())nge[i]=n;
            else nge[i]=st.top();

            st.push(i);
            i--;
        }
    }
    void solvepge(vector<int>& arr,int n,vector<int>& pge){
        stack<int> st;
        int i=0;
        while(i < n){
            while(!st.empty() && arr[st.top()] < arr[i]){
                st.pop();
            }
            if(st.empty())pge[i]=-1;
            else pge[i]=st.top();

            st.push(i);
            i++;
        }
    }
    void solvense(vector<int>& arr,int n,vector<int>& nse){
        stack<int> st;
        int i=n-1;
        while(i >= 0){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty())nse[i]=n;
            else nse[i]=st.top();

            st.push(i);
            i--;
        }
    }
    void solvepse(vector<int>& arr,int n,vector<int>& pse){
        stack<int> st;
        int i=0;
        while(i < n){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(st.empty())pse[i]=-1;
            else pse[i]=st.top();

            st.push(i);
            i++;
        }
    }
    long long sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> pse(n);
        vector<int> nse(n);

        solvense(arr,n,nse);
        solvepse(arr,n,pse);
        long long sum=0;
        for(int i=0;i<n;i++){
            long long total_nse=nse[i]-i;
            long long total_pse=i-pse[i];
            long long contribute = (total_nse * total_pse);
            contribute= (contribute* arr[i]);
            sum = (sum+contribute);
        }
        return sum;
    }
    long long sumSubarrayMaxs(vector<int>& arr) {
        int n=arr.size();
        vector<int> pge(n);
        vector<int> nge(n);

        solvenge(arr,n,nge);
        solvepge(arr,n,pge);
        long long sum=0;
        for(int i=0;i<n;i++){
            long long total_nge=nge[i]-i;
            long long total_pge=i-pge[i];
            long long contribute = (total_nge * total_pge);
            contribute= (contribute* arr[i]);
            sum = (sum+contribute);
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        
        return sumSubarrayMaxs(nums)-sumSubarrayMins(nums);
    }
};