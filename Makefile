
# auto-find waf path?
node-waf = node-waf

default:
	$(node-waf) configure build
	ls ./build/Release/*.node
clean:
	$(node-waf) clean
test:
	node test.js
