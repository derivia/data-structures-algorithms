const {randomArray} = require("../../misc/random_array.js");

function merge(arrLeft, arrRight) {
  let finalArray = [];
  while (arrLeft.length !== 0 && arrRight.length !== 0) {
    if (arrLeft[0] <= arrRight[0]) {
      finalArray.push(arrLeft.shift());
    } else {
      finalArray.push(arrRight.shift());
    }
  }
  return finalArray.concat(arrLeft, arrRight);
}

function mergeSort(arr) {
  if (arr.length === 1) return arr;
  let [arrLeft, arrRight] = [
    arr.slice(0, arr.length / 2),
    arr.slice(arr.length / 2),
  ];
  arrLeft = mergeSort(arrLeft);
  arrRight = mergeSort(arrRight);
  return merge(arrLeft, arrRight);
}

let testArray = randomArray(16);
console.log(mergeSort(testArray).join(" -> "));

/*
 * Basically splits the array into smallers arrays until there are only arrays with two elements
 * this makes comparing the elements after sorting the previous arrys better, because
 * as example, these two, after being initially sorted, [1, 2] & [4, 5] only need to have two comparisons
 * to create an array with 4 elements [1, 2, 4, 5], then, this can be compared to another with 4, etc.
 */
