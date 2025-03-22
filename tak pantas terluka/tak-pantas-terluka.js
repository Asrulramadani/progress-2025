const lyrics = [
    'Terlalu lama kusimpan semua perasaanku',
    'Kepada dirimu',
    'Yang kututupi sebagai teman',
    'Terlalu lama ku mencintaimu dalam diam',
    'Tak bisa apa-apa',
    "Kar'na kau t'lah bersamanya",
  ];
  
  const lineDurations = [2900, 2000, 2900, 2800, 2500, 2500];
  const delays = [2200, 3200, 800, 2300, 1000];
  
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
  