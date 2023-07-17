//알고리즘 11.6 최단거리 알고리즘
//입력: 가중치 그래프 G, 가중치는 음수가 아님.
//출력: distance 배열, distance[u]는 v에서 u까지의 최단 거리이다.
/*
shortest_path(G, v):
	
	S<-{v}
	for 각 정점 w (- G do
		distance[w]<-weight[v][w];
	while 모든 정점이 S에 포함되지 않으면 do
		u<-집합 s에 속하지 않는 정점 중에서 최소 distance 정점;
		S<- S U {u}
		for u에 인접하고 S에 있는 각 정점 z 애
			if distance[u] + weight[u][z] < distance[z]
				then distance[z] <- distance[u] + weight[u][z];  
*/
