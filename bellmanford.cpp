REP(x1,n-1){
	REP(i,m){
		int a,b,w;
		a = edges[i].a;
		b = edges[i].b;
		w = edges[i].w;
		if(reachable[a]){
			if(dist[a]+w<dist[b]){
				dist[b] = dist[a]+w;
			}
			if(dist[b]<min)min=dist[b];
		}
	}
}
//P4(dist[1],dist[2],dist[3],dist[4]);
REP(i,m){
	int a,b,w;
	a = edges[i].a;
	b = edges[i].b;
	w = edges[i].w;
	if(reachable[a]){
		if(dist[a]+w<dist[b]){
			ncycle = 1;
		}
	}
}