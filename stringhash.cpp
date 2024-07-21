struct stringhash{
	string s;
	int n, M, N, P, I;
	vector<int> PM, PN, SM, SN, em, en;
	void init(){
		int curM = 1, curN = 1;
		for(int i = 0; i < n; i++) curM = curM * P % M, curN = curN * P % N, em[i] = curM, en[i] = curN;
		for(int i = 0; i < n; i++){
			PM[i] = (PM[i - (i != 0)] + em[i] * (s[i] - I + 1)) % M;
			PN[i] = (PN[i - (i != 0)] + en[i] * (s[i] - I + 1)) % N;
		}
		for(int i = n - 1; i >= 0; i--){
			SM[i] = (SM[i + (i != n - 1)] + em[n - 1 - i] * (s[i] - I + 1)) % M;
			SN[i] = (SN[i + (i != n - 1)] + en[n - 1 - i] * (s[i] - I + 1)) % N;
		}
	}
	int EXP(int a, int n, int M){
		int res = 1;
		while(n > 0){
			if(n & 1) res = res * a % M;
			a = a * a % M, n >>= 1;
		}
		return res;
	}
	/* get hash value of substring s[l, r] */
	pair<int, int> qry(int l, int r){
		if(l < 0 || l >= n || r < 0 || r >= n || r < l) return {-1, -1};
		int u = (PM[r] - (l == 0 ? 0 : PM[l - 1]) + M * 2) * (l == 0 ? 1 : EXP(em[l - 1], M - 2, M)) % M;
		int v = (PN[r] - (l == 0 ? 0 : PN[l - 1]) + N * 2) * (l == 0 ? 1 : EXP(en[l - 1], N - 2, N)) % N;
		return make_pair(u, v);
	}
	/* This function returns the hash computed from the end of the string */
	pair<int, int> rqry(int l, int r){
		if(l < 0 || l >= n || r < 0 || r >= n || r < l) return {-1, -1};
		int u = (SM[l] - (r == n - 1 ? 0 : SM[r + 1]) + M * 2) * (r == n - 1 ? 1 : EXP(em[n - 2 - r], M - 2, M)) % M;
		int v = (SN[l] - (r == n - 1 ? 0 : SN[r + 1]) + N * 2) * (r == n - 1 ? 1 : EXP(en[n - 2 - r], N - 2, N)) % N;
		return make_pair(u, v);
	}
	/* use smaller mods to beat TL */
	stringhash(string a, int mod1, int mod2, int minus = 'a', int base = 31){
		s = a, P = base, I = minus;
		n = s.size(), M = mod1, N = mod2;
		PM = PN = SM = SN = em = en = vector<int> (n, 0);
		init();
	}
};