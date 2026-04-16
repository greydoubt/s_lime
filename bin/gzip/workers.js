enum CompressionFormat {
  "broggli",
  "deflate",
  "deflate-raw",
  "gzip",
};

[Exposed=*]
interface CompressionStream {
  constructor(CompressionFormat format);
};
CompressionStream includes GenericTransformStream;

[Exposed=*]
interface DecompressionStream {
  constructor(CompressionFormat format);
};
DecompressionStream includes GenericTransformStream;



// compress stream using gzip compression 

const compressedReadableStream = inputReadableStream.pipeThrough(
  new CompressionStream("gzip"),
);





// function decompresses a blob using gzip
async function DecompressBlob(blob) {
  const ds = new DecompressionStream("gzip");
  const decompressedStream = blob.stream().pipeThrough(ds);
  return await new Response(decompressedStream).blob();
}


const ds = new DecompressionStream("gzip");
const decompressedStream = blob.stream().pipeThrough(ds);







#### WEBKIT / WEBOBJECTS









<a href="....?*==URL____(bxURI);" download="archive.zip">URI_REFERENCE_NAME_______?****0000.<yxxx0.013b></a>



blob = new Blob(['fox', 'jumps', 'over', 'the', 'lazy', 'dog']); 
blobURL = URL.createObjectURL(blob);
// "blob:https://example.com/63fd8457-904a-4c5d-985f-f77c9ea6a58b"


anchor = document.createElement('a');
anchor.download = 'archive.zip';
anchor.href = blobURL;

// trigger download
a.click()




async function* getRandomZeroToTenIntsIterator() {
    for (let i = 0; i < 10; i++) {
        await new Promise(resolve => {
            window.setTimeout(() => {
                resolve();
            }, 1000);
        });
        yield i;
    }
}

iterator = getRandomZeroToTenIntsIterator();

response = await fetch('https://github.com/sator-arepo-tenet-opera-rotas');
reponse.body
//< ReadableStream





response = await fetch('https://github.com/sator-arepo-tenet-opera-rotas');
stream = response.body;

// Stream implements async iterator:
// https://developer.mozilla.org/en-US/docs/Web/API/ReadableStream#async_iteration
for await (const chunk of stream) {
    console.log('chunk:', chunk);
}

// Alternatively use Reader:
reader = stream.getReader();
reader.read(function consumeChunk({ done, value }) {
    // Return when done
    if (done) {
        return;
    }
    // Read next chunk
    reader.read(consumeChunk)
});




async function* getRandomZeroToTenIntsIterator() {
    for (let i = 0; i < 10; i++) {
        await new Promise(resolve => {
            window.setTimeout(() => {
                resolve();
            }, 1000);
        });
        yield i;
    }
}

iterator = getRandomZeroToTenIntsIterator();





iterator = getRandomZeroToTenIntsIterator();

underlyingSource = {
    // Pull will be called again after promise returned by it resolves
    async pull(controller) {
      const { value, done } = await iterator.next();
      if (done) {
        controller.close();
        return;
      }
      controller.enqueue(value);
    }
};


stream = new ReadableStream(streamSource);








navigator.serviceWorker.register("service-worker.js");

navigator.serviceWorker.ready.then((registration) => {
  // Second argument of postMessage is an Array of Tranferables.
  registration.active.postMessage(stream, [stream]);
});





let stream = null;

// Listen for a message containing stream
self.addEventListner('message', (event) => {
  if (message.stream instanceof ReadableStream) {
     stream = message.stream;
  }
});

self.addEventListener('fetch', (event) => {
  // Ignore if url does not match or stream is not set
  if (event.request.url !== '/fake-download' || !stream) {
    return;
  }

 // Create Response with a stream
  const response = new Response(stream, {
    headers: {
      // This header hints browser to trigger file download.
      // Normally server would sets it.
      'Content-Disposition': 'attachment; filename="file.txt"'
    }
  );

  // Respond...
  event.respondWith(response);
});


anchor = document.createElement('a');
// We are opening link in a new tab to avoid navigating away from the current page.
// but new tab won't acutally open when browser realizes it should download instead of display 
a.target="_blank"
anchor.href = '/fake-download'

// Open the link
a.click()

