//�˰��� 11.6 �ִܰŸ� �˰���
//�Է�: ����ġ �׷��� G, ����ġ�� ������ �ƴ�.
//���: distance �迭, distance[u]�� v���� u������ �ִ� �Ÿ��̴�.
/*
shortest_path(G, v):
	
	S<-{v}
	for �� ���� w (- G do
		distance[w]<-weight[v][w];
	while ��� ������ S�� ���Ե��� ������ do
		u<-���� s�� ������ �ʴ� ���� �߿��� �ּ� distance ����;
		S<- S U {u}
		for u�� �����ϰ� S�� �ִ� �� ���� z ��
			if distance[u] + weight[u][z] < distance[z]
				then distance[z] <- distance[u] + weight[u][z];  
*/
