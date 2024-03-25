// binary search requires the array is sorted
function binary_search(array, value) {
  let guesses = 0;
  let bottom = 0;
  let top = array.length - 1;
  while (bottom <= top) {
    let middle = Math.floor((bottom + top) / 2);

    if (array[middle] === value) {
      return [middle, guesses];
    } else if (array[middle] < value) {
      bottom = middle + 1;
    } else {
      top = middle - 1;
    }
    guesses++;
  }
  return -1;
}

let array = [1, 4, 7, 9, 25, 34, 84, 137, 445, 893, 1245, 2357];
let value = 25;
let [index, guesses] = binary_search(array, value);
console.log("index of " + value + ": " + index);
console.log("number of guesses: " + guesses)
