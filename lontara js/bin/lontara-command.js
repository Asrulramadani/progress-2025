#!/usr/bin/env node

const fs = require("fs");
const path = require("path");

// Ambil file dari argumen CLI
const filePath = process.argv[2];
if (!filePath) {
  console.error("Harap masukkan file Lontara seperti: ᨍᨆᨕᨗ index.ᨒᨚᨈᨑ");
  process.exit(1);
}

// Baca file
const lontaraCode = fs.readFileSync(filePath, "utf-8");

// Import interpreter
const { translateAndRun } = require("../interpreter");

// Jalankan kode
translateAndRun(lontaraCode);

