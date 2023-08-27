const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});
let idx = 0;
let n, m;
const arr = [];
rl.on("line", (line) => {
  const input = line.split(" ");
  if (idx == 0) {
    n = parseInt(input[0]);
    m = parseInt(input[1]);
  } else {
    const input = line.split(" ");
    const act = [];
    let p = -1;
    let next = 0;
    for (const x of input) {
      if (p == -1) p = parseInt(x);
      else if (next == 0) next = parseInt(x);
      else act.push(parseInt(x));
    }
    arr.push([p, act]);
  }
  idx++;
  if (idx == n + 1) rl.close();
});

rl.once("close", () => {
  for (let i = 0; i < arr.length; i++) {
    for (let j = 0; j < arr.length; j++) {
      if (j == i) continue;
      if (arr[i][0] >= arr[j][0]) {
        let flag = true;
        for (const x of arr[i][1]) {
          if (arr[j][1].indexOf(x) == -1) {
            flag = false;
            break;
          }
        }
        if (!flag) continue;
        if (flag && arr[i][0] > arr[j][0]) {
          console.log("Yes");
          return;
        }
        let cnt = 0;
        for (const x of arr[j][1]) {
          cnt += arr[i][1].indexOf(x) == -1 ? 1 : 0;
        }
        if (cnt && flag) {
          console.log("Yes");
          return;
        }
      }
    }
  }

  console.log("No");
});
