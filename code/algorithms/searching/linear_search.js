function linear_search(array, value) {
  for (let index = 0; index < array.length; index++) {
    if (array[index] == value) {
      return index;
    }
  }
  return -1;
}

let array = [1, 4, 27, 9, 25, 634, 84, 137, 445, 2893, 1245, 2357];
let value = 25;

console.log("index of value " + value + ": " + linear_search(array, value));
