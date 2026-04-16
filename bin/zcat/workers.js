function reqListener () {
    var originalInput = pako.ungzip(this.response,{ to: 'string' });
    document.write("<pre>"+originalInput+"</pre>");
  }

  const req = new XMLHttpRequest();
  req.addEventListener("load", reqListener);
  req.open("GET", "C80.txt.gz");
  req.responseType = "arraybuffer";
  req.send();
