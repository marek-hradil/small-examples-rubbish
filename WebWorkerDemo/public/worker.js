importScripts("https://unpkg.com/dexie@latest/dist/dexie.js");

var db = new Dexie("FriendDatabase");
db.version(1).stores({
  friends: "++id,name,age",
});

self.addEventListener("message", () => {
  db.friends
    .add({ name: "Josephine", age: 21 })
    .then(function () {
      return db.friends.where("age").below(25).toArray();
    })
    .then(function (youngFriends) {
      self.postMessage(youngFriends);
    })
    .catch(function (e) {
      self.postMessage(`Error: ${e}`);
    });
});
