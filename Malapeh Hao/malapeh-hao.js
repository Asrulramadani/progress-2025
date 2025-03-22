const lyrics = [
  'denai kini marasai',
  'ndeh malang dek ulah cinto',
  'uda den sangko sarai',
  'ilalang malah kironyo',
  '\n',
  'denai kini marasai',
  'ndeh malang dek ulah cinto',
  'uda den sangko sarai',
  'ilalang malah kironyo',

  ];
  
  const lineDurations = [1500, 2800 ,2200, 3600, 100, 1500, 2800 ,2200, 3600]; // Durasi mengetik tiap baris dalam ms
  const delays = [100, 1500, 200, 50, 80, 1500, 200 ]; // Delay sebelum baris berikutnya
  
  let i = 0;
  function typeLine(line, duration, callback) {
    let index = 0;
    let interval = duration / line.length;
  
    function typeChar() {
      if (index < line.length) {
        process.stdout.write(line[index]);
        index++;
        setTimeout(typeChar, interval);
      } else {
        process.stdout.write('\n');
        setTimeout(callback, delays[i] || 500);
      }
    }
    typeChar();
  }
  
  function displayLyrics() {
    if (i < lyrics.length) {
      typeLine(lyrics[i], lineDurations[i], () => {
        i++;
        displayLyrics();
      });
    }
  }
  
  displayLyrics();
  