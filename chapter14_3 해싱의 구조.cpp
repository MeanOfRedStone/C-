//�˰��� 14.1 �̻����� �ؽ� �˰���
add(key, value) :
	index <- hash_function(key)
	ht[index] = value
	
search(key) :
	index <- hash_function(key)
	return ht[index] 
