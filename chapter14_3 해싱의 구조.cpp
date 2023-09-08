//알고리즘 14.1 이상적인 해싱 알고리즘
add(key, value) :
	index <- hash_function(key)
	ht[index] = value
	
search(key) :
	index <- hash_function(key)
	return ht[index] 
