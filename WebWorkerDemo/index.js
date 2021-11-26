console.log("works");

if (!window.Worker) {
  console.error("No web worker");
}

const worker = new Worker("./public/worker.js");

worker.addEventListener("message", (e) => {
  console.log(`Worker said`, e.data);
});

worker.postMessage("Hi fam");
