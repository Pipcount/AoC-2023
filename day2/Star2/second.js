const { readFileSync } = require('fs');

// open file
const file = readFileSync('./data.txt', 'utf8');

let sum = 0;

for (let line of file.split('\n')) {
    let minRed = 0;
    let minGreen = 0;
    let minBlue = 0;
    let gameID = line.split(':')[0].split(' ')[1];
    for (let round of line.split(':')[1].split(';')) {
        for (let cubes of round.split(',')) {
            let cubesTrimmed = cubes.trim().replace(/\s+/g, ' ');
            let color = cubesTrimmed.split(' ')[1];
            let num = parseInt(cubesTrimmed.split(' ')[0]);
            if (color === 'red' && num > minRed) {
                minRed = num;
            }
            if (color === 'green' && num > minGreen) {
                minGreen = num;
            }
            if (color === 'blue' && num > minBlue) {
                minBlue = num;
            }
        }
    }
    console.log(minRed, minGreen, minBlue);
    let power = minRed * minGreen * minBlue;
    console.log(power);
    sum += power;
}
console.log(sum);