/*
-정의 : 시작 정점에서부터 출발하여 신장 트리 집합을 단계적으로 확장해나가는 방법이다.
- 위의 Kruskal 알고리즘과 차이
  > kruskal은 간선을 기반 + 무조건 최저 간선만을 선택
  > Prim은 정점을 기반 + 이전 단계에서 만들어진 신장 트리를 확장

(알고리즘 11.4 Prim의 최소 비용 신장 트리 알고리즘 #1)
//최소 비용 신장 트리를 구하는 Prim의 알고리즘
//입력 : 네트워크 G = (V, E), S는 시작 정점
//출력 : Vr, 최소 비용 신장 트리를 이루는 정점들의 집합
Prim(G, s) :
	Vt <- {s}; vcounter<-1
	while vcounter < n do
		(u, v)는 u (= Vt and !(- Vt인 최저 비용 간선;
		if (그러한 (u,v)가 존재하면)
			then Vt <- Vt U v ; vcunter <- vcounter + 1
		else 실패
	return Vt
*/
