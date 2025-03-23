// Kamus Lontara -> JavaScript
const keywords = {
    "ᨕᨀᨙᨁᨘᨊ": "function",
    "ᨊᨑᨙᨀᨚ": "if",
    "ᨐᨑᨙᨁ": "else",
    "ᨆᨑᨘᨀᨗ": "console.log",
    "ᨕᨚᨋᨚ":"let",
    "ᨕᨘᨒᨁᨗ":"for"
  };
  
  // Fungsi untuk menerjemahkan kode
  function translateLontara(code) {
    let translated = code;
    for (const [lontara, js] of Object.entries(keywords)) {
      const regex = new RegExp(lontara, "g");
      translated = translated.replace(regex, js);
    }
    return translated;
  }
  
  // Fungsi untuk menjalankan kode
  function translateAndRun(code) {
    const jsCode = translateLontara(code);
    console.log("=== Kode Terjemahan ===");
    console.log(jsCode);
    console.log("\n=== Output Program ===");
    eval(jsCode); // Jalankan kode hasil terjemahan
  }
  
  module.exports = { translateAndRun };
  