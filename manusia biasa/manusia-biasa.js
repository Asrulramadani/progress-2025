const lyrics = [
  '\n',
  'Masih kuingat selalu',
  'Saat kau berjanji padaku',
  'Takkan pernah ada cinta yang lainnya',
  'Terasa begitu indah',
  '\n',
  'Tapi semua berbeda',
  'Saat kaukenali dirinya',
  'Sadarkah dirimu diriku terluka',
  'Saat kausebut namanya?',
  '\n',
  'Aku memang manusia biasa',
  'Yang tak sempurna dan kadang salah',
  'Namun, di hatiku hanya satu',
  'Cinta untukmu luar biasa',
  '\n'
  ];
  
  const lineDurations = [0, 3000, 2800 ,3500, 3000, 800, 2300, 3000, 3800, 3100, 0, 3500, 3000, 3000, 4000]; // Durasi mengetik tiap baris dalam ms
  const delays = [0, 400, 1500, 200, 0, 100, 500, 900, 300, 100, 200, 700, 200, ]; // Delay sebelum baris berikutnya
  
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
  