import urllib.request
import urllib.parse
import json
#print (type(data))
#data_str = json.dumps(data)
#data_str = urllib.parse.urlencode(data).encode('utf-8')
fh = urllib.request.urlopen(url="https://api.map.baidu.com/location/ip?ak=ylOZBnrl0qGC80iev0MYIGCFaGmB34dW&coor=bd09ll")
s = fh.read().decode('unicode_escape')
print(s)
data = json.loads(s)
f = open("../locate.txt", 'w')
print (data['content']['point']['x'],data['content']['point']['y'], file = f)
print (data['content']['address_detail']['city'],data['content']['address_detail']['province'],data['content']['address_detail']['district'],file = f)