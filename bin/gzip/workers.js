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
