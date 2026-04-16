curl -X POST <URI>/v0/sessions \
  -H "Content-Type: application/json" \
  -d '{
    "prompt": "This is line 1\nThis is line 2\nThis is line 3",
    "commands": ["a","This is line 1","This is line 2","This is line 3",".",",p","w example.txt","q"],
    "options": {"p": ".", "s": false, "v": true, "G": false},
    "file": "ed.json"
  }'
