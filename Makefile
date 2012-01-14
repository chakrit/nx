
default:
	# mkdir -p ./out/
	# g++ -Wall nx.cpp -o out/nx -I./deps/node/src -I./deps/node/deps/v8/include -I./deps/node/deps/uv/include
	./deps/node/tools/node-waf
