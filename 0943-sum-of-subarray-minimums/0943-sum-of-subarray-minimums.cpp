class Solution {
public:
    int M=1e9+7;
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
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> pse(n);
        vector<int> nse(n);

        solvense(arr,n,nse);
        solvepse(arr,n,pse);
        int sum=0;
        for(int i=0;i<n;i++){
            int total_nse=nse[i]-i;
            int total_pse=i-pse[i];
           sum = (sum + (1LL * total_nse * total_pse % M) * arr[i] % M) % M;

        }
        return sum;
    }
};