function Create2DArray(rows) {
  var arr = [];

  for (var i = 0; i < rows; i++) {
    arr[i] = [];
  }

  return arr;
}
var total_sp = 121;
var skills = [
  [1, 2],
  [1, 3],
  [3, 6],
  [3, 4],
  [3, 5],
];
var i = 0;
var inNodes = Create2DArray(skills.length + 2);

for (i = 0; i < skills.length; i++) {
  inNodes[skills[i][0]].push(skills[i][1]);
}
console.log(inNodes);

var skillpt = [];
for (i = 0; i < skills.length + 2; i++) {
  if (inNodes[i].length === 0) skillpt[i] = 1;
}
console.log(skillpt);

var j = 0;
var k = 0;

while (j > 3) {
  skillpt.forEach((element) => {
    skillpt[element];
  });
}
// var inNodesObject = Object.assign({}, inNodes);
// console.log(inNodesObject);

// var keys = Object.keys(inNodesObject); // ["A","B","C","D","E","F"]
// output = [];

// while (keys.length) {
//   for (var i in keys) {
//     var key = keys[i]; // "A"
//     var dependencies = inNodesObject[key]; // []

//     if (dependencies.every((dependency) => output.includes(dependency))) {
//       // If all dependencies are already in the output array
//       output.push(key); // Pushing "A" to the output
//       keys.splice(i, 1); // Removing "A" from the keys
//     }
//   }
// }

// console.log(output);
// const imageDependencies = {
//   A: [],
//   B: ["A"],
//   C: ["A", "B"],
//   D: ["F"],
//   E: ["D", "C"],
//   F: [],
// };

// function tsort(edges) {
//   let nodes = {},
//     sorted = [],
//     visited = {};

//   let Node = function (id) {
//     this.id = id;
//     this.afters = [];
//   };

//   edges.forEach((v) => {
//     let from = v[0],
//       to = v[1];
//     if (!nodes[from]) nodes[from] = new Node(from);
//     if (!nodes[to]) nodes[to] = new Node(to);
//     nodes[from].afters.push(to);
//   });

//   Object.keys(nodes).forEach(function visit(idstr, ancestors) {
//     let node = nodes[idstr],
//       id = node.id;

//     if (visited[idstr]) return;
//     if (!Array.isArray(ancestors)) ancestors = [];

//     ancestors.push(id);
//     visited[idstr] = true;
//     node.afters.forEach(function (afterID) {
//       if (ancestors.indexOf(afterID) >= 0)
//         throw new Error("closed chain : " + afterID + " is in " + id);
//       visit(
//         afterID.toString(),
//         ancestors.map(function (v) {
//           return v;
//         })
//       );
//     });
//     sorted.unshift(id);
//   });

//   return sorted;
// }

// const createEdges = (dep) => {
//   let result = [];
//   Object.keys(dep).forEach((key) => {
//     dep[key].forEach((n) => {
//       result.push([n, key]);
//     });
//   });
//   return result;
// };

// const list = createEdges(imageDependencies);
// console.log(tsort(list));

// const imageDependencies = {
//   A: [],
//   B: ["A"],
//   C: ["A", "B"],
//   D: ["F"],
//   E: ["D", "C"],
//   F: [],
// };
// let keys = Object.keys(imageDependencies), // ["A","B","C","D","E","F"]
//   output = [];

// while (keys.length) {
//   for (let i in keys) {
//     let key = keys[i], // "A"
//       dependencies = imageDependencies[key]; // []

//     if (dependencies.every((dependency) => output.includes(dependency))) {
//       // If all dependencies are already in the output array
//       output.push(key); // Pushing "A" to the output
//       keys.splice(i, 1); // Removing "A" from the keys
//     }
//   }
// }

// console.log("output = ", output);

// var answer = 0;
// var num = 11;
// var arr = [];
// var exp = 0;
// var i = 0;
// while (1) {
//   var j = 0;
//   var twoPower = Math.pow(2, exp);
//   var threePower = Math.pow(3, exp);
//   if (twoPower < num) {
//     arr[twoPower - 1] = threePower;
//     for (i = 1; i < twoPower; i++) {
//       arr[twoPower - 1 + i] = arr[twoPower - 1] + arr[j];
//       j++;
//     }
//     exp++;
//   } else {
//     arr[twoPower - 1] = threePower;
//     break;
//   }
// }
// answer = arr[num - 1];
// console.log(answer);

// var num = 1987 + 1;

// while (1) {
//   var isNotDuplicate = true;
//   var digits = ("" + num).split("");
//   console.log(digits);

//   var sorted_arr = digits.slice().sort();
//   console.log(sorted_arr);

//   for (var i = 0; i < sorted_arr.length - 1; i++) {
//     if (sorted_arr[i + 1] === sorted_arr[i]) {
//       isNotDuplicate = false;
//       break;
//     }
//   }

//   if (isNotDuplicate) {
//     break;
//   }
//   num++;
// }
// console.log(num);

// function solution(p)
// {
//     var answer = 0;
//     var num = p + 1;

//     while (1) {
//       var isNotDuplicate = true;
//       var digits = ("" + num).split("");

//       var sorted_arr = digits.slice().sort();

//       for (var i = 0; i < sorted_arr.length - 1; i++) {
//         if (sorted_arr[i + 1] === sorted_arr[i]) {
//           isNotDuplicate = false;
//           break;
//         }
//       }

//       if (isNotDuplicate) {
//         break;
//       }
//       num++;
//     }
//     answer = num
//     return answer;

// }

// var input = [112, 1814, 121, 1481, 1184];
// var str = [];

// for (var i = 0; i < input.length; i++) {
//   var num = input[i];
//   var alphabetical = num.toString().split("").sort().join("");
//   str.push(alphabetical);
// }

// console.log(str);

// var uniqueArray = Array.from(new Set(str));

// console.log(uniqueArray);
// var arr = [1, 1, 3, 3, 2, 2, 4, 5, 1, 1, 1, 3, 3, 3];

// function solution(arr) {
//   var answer = -1;
//   var sum = 0;
//   var count = 0;
//   var result = [];
//   for (var i = 0; i < arr.length; i++) {
//     if (arr[i - 1] && arr[i - 1] === arr[i]) {
//       sum += 1;
//       if (!arr[i + 1]) result.push(sum);
//     } else if (arr[i - 1] && arr[i - 1] !== arr[i]) {
//       result.push(sum);
//       sum = 1;
//     } else if (!arr[i - 1]) {
//       sum += 1;
//     }
//   }
//   count += 1;

//   while (1) {
//     var temp = result.slice();

//     result = [];
//     sum = 0;
//     for (var i = 0; i < temp.length; i++) {
//       if (temp[i - 1] && temp[i - 1] === temp[i]) {
//         sum += 1;
//         if (!temp[i + 1]) result.push(sum);
//       } else if (temp[i - 1] && temp[i - 1] !== temp[i]) {
//         result.push(sum);
//         sum = 1;
//         if (!temp[i + 1]) result.push(sum);
//       } else if (!temp[i - 1]) {
//         sum += 1;
//         if (temp.length === 1) result.push(sum);
//       }
//     }

//     count += 1;
//     if (result[0] === 1 && result.length === 1) {
//       break;
//     }
//   }
//   answer = count;
//   return answer;
// }

// solution(arr);

// // stars
// process.stdin.setEncoding("utf8");
// process.stdin.on("data", (data) => {
//   const n = data.split(" ");
//   const a = Number(n[0]);
//   console.log(a);
// });

// // concat console.log
// var year = "2019";
// var month = "04";
// var day = "26";
// var hour = "11";
// var minute = "34";
// var second = "27";

// // var result =
// //   year + "/" + month + "/" + day + " " + hour + ":" + minute + ":" + second;

// var result = year.concat(
//   "/",
//   month,
//   "/",
//   day,
//   " ",
//   hour,
//   ":",
//   minute,
//   ":",
//   second
// );
// console.log(result);
// // concat adds original array with provided inputs in (HERE)

// // duplicating object key
// var d = {
//   height: 180,
//   weight: 20,
//   weight: 40,
//   1: 180,
// };

// console.log(d[1]);

// falthy
// null, undefined, 0, "", NaN, false

// // for
// var a = 10;
// var b = 2;

// for (var i = 1; i < 5; i += 2) {
//   a += i;
// }

// console.log(a + b);

// // type of var
// var arr = [100, 200, 300];
// console.log(typeof arr);

// // built-in functions in array
// var arr = [200, 100, 300];
// arr.splice(2, 0, 10000);
// console.log(arr);
// arr.splice(2, 2);
// console.log(arr);
// arr.splice(2, 0, "yolo", "caly");
// console.log(arr);
// arr.splice(2, 2, "c", "j");
// console.log(arr);
// // splice is used to insert, replace, delete

// // popping array
// var nums = [100, 200, 300, 400, 500];
// nums.pop();
// console.log(nums);
// nums.pop();
// console.log(nums);
