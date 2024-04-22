const {getRandomInt, randomArray} = require("../../misc/random_array.js")

function quicksort(array) {
  if (array.length === 0 ) return [];
  else if (array.length === 1) return array;
  let pivot = array[getRandomInt(0, array.length - 1)];
  let head = array.filter(n => n < pivot);
  let equal = array.filter(n => n === pivot);
  let tail = array.filter(n => n > pivot);
  return quicksort(head).concat(equal).concat(quicksort(tail));
}

let array = randomArray(16);
console.log(quicksort(array).join(" -> "));

/*
 * Basically recursively makes smaller arrays with different pivots and concatenate them in the end.
*/
