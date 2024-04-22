function getRandomInt(min, max) {
  return Math.floor(Math.random() * (max - min + 1)) + min;
}

function randomArray(size, min = 1, max = 256) {
  let array = [];
  for (let i = 0; i < size - 1; i++) {
    array[i] = getRandomInt(min, max);
  }
  return array;
}

module.exports = { getRandomInt, randomArray };
