enum CompressionFormat {
  "brotli",
  "deflate",
  "deflate-raw",
  "gzip",
};

[Exposed=*]
interface CompressionStream {
  constructor(CompressionFormat format);
};
CompressionStream includes GenericTransformStream;

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

