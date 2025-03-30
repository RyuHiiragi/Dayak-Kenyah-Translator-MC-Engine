#include <WiFi.h>
#include <WebServer.h>
#include <ArduinoJson.h>

// 1. KONFIGURASI WIFI
const char* ssid = "AMARIA";      // Ganti dengan SSID Anda
const char* password = "AMARIA1401";   // Ganti dengan password WiFi

// 2. KAMUS LENGKAP (Semua 500+ kosakata)
const char dictionary_json[] PROGMEM = R"rawliteral(
{
  "apa": "inu",
  "kemana": "kenpi",
  "dimana": "kenpi",
  "siapa": "ahe",
  "kapan": "mi'an",
  "bagaimana": "kumpin",
  "putih": "putek",
  "hitam": "saleng",
  "merah": "bala",
  "1": "ca'",
  "2": "dua",
  "3": "telu",
  "4": "pat",
  "5": "lema",
  "6": "nem",
  "7": "tujuk",
  "8": "aya",
  "9": "pe'en",
  "10": "puluk",
  "11": "ca' elas",
  "12": "dua elas",
  "13": "telu elas",
  "14": "pat elas",
  "15": "lema elas",
  "16": "nem elas",
  "17": "tujuk elas",
  "18": "aya elas",
  "19": "pe'en elas",
  "20": "dua puluk",
  "30": "telu puluk",
  "40": "pat puluk",
  "50": "lema puluk",
  "60": "nem puluk",
  "70": "tujuk puluk",
  "80": "aya puluk",
  "90": "pe'en puluk",
  "100": "ca' ato",
  "1000": "ca' ibu",
  "1000000": "ca' juta",
  "satu": "ca'",
  "dua": "dua",
  "tiga": "telu",
  "empat": "pat",
  "lima": "lema",
  "enam": "nem",
  "tujuh": "tujuk",
  "delapan": "aya",
  "sembilan": "pe'en",
  "sepuluh": "puluk",
  "sebelas": "ca' elas",
  "dua belas": "dua elas",
  "tiga belas": "telu elas",
  "empat belas": "pat elas",
  "lima belas": "lema elas",
  "enam belas": "nem elas",
  "tujuh belas": "tujuk elas",
  "delapan belas": "aya elas",
  "sembilan belas": "pe'en elas",
  "dua puluh": "dua puluk",
  "tiga puluh": "telu puluk",
  "empat puluh": "pat puluk",
  "lima puluh": "lema puluk",
  "enam puluh": "nem puluk",
  "tujuh puluh": "tujuk puluk",
  "delapan puluh": "aya puluk",
  "sembilan puluh": "pe'en puluk",
  "seratus": "ca' ato",
  "seribu": "ca' ibu",
  "sejuta": "ca' juta",
  "ratus": "ato",
  "ribu": "ibu",
  "belas": "elas",
  "nya": "la",
  "aku": "ake",
  "ada": "aun",
  "anjing": "udut",
  "ayam": "yap",
  "babi": "babui",
  "banteng": "kalasiau",
  "bebek": "bidik",
  "belalang": "kade",
  "beruang": "buang",
  "biawak": "kabuk",
  "buaya": "baya",
  "burung": "sui",
  "cicak": "aru",
  "gajah": "kesun",
  "harimau": "lenjau",
  "ikan": "atuk",
  "lele": "kati",
  "patin": "selareng",
  "kambing": "kadeng",
  "kancil": "pelanuk",
  "kecoa": "lepa",
  "kepiting": "yu",
  "kijang": "payak",
  "kodok": "sui",
  "kucing": "sing",
  "kupu-kupu": "bamper",
  "lalat": "langau",
  "cacing": "lati",
  "macan": "kule",
  "monyet": "kuyata",
  "nyamuk": "jamok",
  "rusa": "uca",
  "siput": "sik/ulung",
  "tikus": "belabau",
  "ular": "tuduk",
  "bagus": "tia",
  "baru": "mading",
  "besar": "bio",
  "cepat": "sangit",
  "kelakuan": "puyan",
  "kosong": "mpi un",
  "malas": "malat",
  "nyata": "lan",
  "pelit": "ma'em",
  "ringan": "nyian",
  "sehat": "agat",
  "pagi": "tading nempam",
  "siang": "naktau",
  "malam": "nataup",
  "sibuk": "lamak",
  "berbagai": "kado",
  "atau": "ataw",
  "dan": "ngan",
  "dari": "cen",
  "berasal": "cen",
  "diantara": "dalau",
  "juga": "pe",
  "karena": "uban",
  "ke": "koq",
  "mending": "lepa ini",
  "saat": "sa taup",
  "sebelum": "ken'a",
  "tapi": "untepu'o",
  "tetapi": "untepu'o",
  "setelah": "lepa kadi",
  "supaya": "apan",
  "agar": "apan",
  "untuk": "un",
  "yang": "yak",
  "adalah": "ja ne",
  "ialah": "ialah",
  "kalau": "awa'",
  "badan": "usa",
  "baju": "sapai",
  "buah": "buaq",
  "keledang": "ta'ep",
  "cempedak": "nakan",
  "lay": "pakit",
  "rambutan": "sangit",
  "desa": "lepo",
  "gula": "gula'k",
  "jendela": "sekan",
  "kamar": "tilung lundo",
  "kursi": "adan",
  "lemari": "buan",
  "lontong": "kanen lema'k",
  "makanan": "penguman",
  "memakan": "uman",
  "dimakan": "uman",
  "meja": "mejak",
  "minuman": "nisep ia",
  "minyak": "lenya",
  "mobil": "oto",
  "goreng": "saga",
  "pasar": "pasen",
  "piring": "kiyat",
  "pondok": "lepau",
  "rumah": "amin",
  "sungai": "alo",
  "tas": "bek",
  "telur": "telo",
  "kandang": "liwang",
  "sudah": "lepa",
  "sampai": "pa",
  "balik": "liwer",
  "bangun": "taga",
  "belajar": "pekalai",
  "berangkat": "tai te",
  "bermain": "piat",
  "berpikir": "pekimet",
  "bikin": "uyan",
  "buat": "uyan",
  "bilang": "kun",
  "sampaikan": "kun",
  "bohong": "pala",
  "bolos": "tai kelap",
  "jalan": "masat",
  "jalan-jalan": "masat-masat",
  "jangan": "ain",
  "keluar": "kawang",
  "bekerja": "gayeng",
  "kerja": "gayeng",
  "kerjakan": "gayeng",
  "ketahui": "tisen",
  "tau": "tisen",
  "makan": "uman",
  "mandi": "ndu'",
  "masak": "pesak",
  "masuk": "ke dalem",
  "melihat": "ngeneng",
  "melihatnya": "ngeneng ia",
  "membeli": "meli",
  "mendengar": "ngeninga",
  "menyanyi": "ngendau",
  "minum": "nisep",
  "nyaring": "bia",
  "singgah": "ngena'k",
  "tinggal": "ngena'k",
  "disini": "ki",
  "terima": "tiga",
  "kasih": "tawai",
  "tidur": "lundog",
  "pindah": "buaw",
  "berteduh": "ngedingan",
  "petubo": "pelihara",
  "adegan": "kaa",
  "banyak": "kado",
  "sekali": "ale",
  "boleh": "kong",
  "dulu": "ading",
  "hari": "tau",
  "ingatan": "kimet",
  "kemarin": "nya'ep rei",
  "memang": "adang",
  "suka": "uba",
  "cinta": "uba",
  "sayang": "uba",
  "melewati": "lapa",
  "sama": "kuwa",
  "nama": "ngadan",
  "namaku": "ngadan keq",
  "ku": "keq",
  "oke": "aha",
  "iya": "aha",
  "pulang": "ula",
  "sangat": "ali'",
  "semua": "mung",
  "seperti": "kuaq",
  "suaranya": "isu'a",
  "tentu": "ina",
  "saja": "na",
  "tidak": "nda",
  "gayeng": "tugas",
  "sekolah": "sekula",
  "kabar": "denga",
  "berita": "denga",
  "hal": "denga",
  "kejadian": "denga",
  "salah": "bep",
  "datang": "nay",
  "tersisa": "naung",
  "bapak": "amai",
  "bersama": "ilu mung",
  "hantu": "bali",
  "ibu": "uweq",
  "kalian": "ikem",
  "kami": "ame",
  "kamu": "ikoq",
  "kau": "ikoq",
  "kita": "ilu",
  "saya": "ake",
  "teman": "tuyang",
  "mereka": "ida",
  "masing": "tengen",
  "masing-masing": "tengen-tengen",
  "senin": "keca",
  "selasa": "kedua",
  "rabu": "ketelu",
  "kamis": "tepat",
  "jumat": "kelema",
  "sabtu": "kenem",
  "minggu": "minggu",
  "adik": "ari'",
  "angin": "bayu",
  "air": "sungai",
  "rumahmu": "lamin engku",
  "ambil": "alak",
  "baik": "lemeli",
  "berenang": "nyatung",
  "bocor": "tudok",
  "berak": "lepin",
  "berdiri": "ngrejeng",
  "bicara": "petirak",
  "bintang": "betuen",
  "besok": "nembam",
  "banjir": "layap",
  "berapa": "kudak",
  "celana": "seluen",
  "cabe": "lia",
  "duduk": "adung",
  "dingin": "nyeng",
  "gelap": "mendem",
  "gigi": "jipen",
  "gemuk": "lembo",
  "gendong": "bak",
  "gunung": "mudung",
  "gundul": "ulok",
  "garam": "usen",
  "hidup": "mudip",
  "hidung": "ndung",
  "hutan": "a'ut",
  "haus": "moang laset",
  "jernih": "litut",
  "mamak": "tinam",
  "jatuh": "labok",
  "jauh": "cok",
  "jelek": "ja'at",
  "kencing": "nyengit",
  "kenyang": "beso",
  "kepala": "ulu",
  "keatas": "kempou",
  "naik": "kempou",
  "kembali": "ulek",
  "kemarau": "tagak",
  "kakek": "pui",
  "nenek": "pui",
  "kakak": "seken",
  "kaki": "taket",
  "kurus": "mae",
  "kecil": "ang",
  "lihat": "maat",
  "lapar": "lau",
  "laki": "laki",
  "lidah": "uma",
  "alkohol": "jakan",
  "mabok": "meduk",
  "madu": "layuk",
  "orang": "lakeng",
  "mencari": "mita",
  "malu": "sa'e",
  "menyelam": "lemeset",
  "memanjat": "lemaket",
  "menanam": "mula",
  "menari": "kanjet",
  "mau": "obak",
  "mata": "mata",
  "mimpi": "ngenupi",
  "mencuri": "mengelau",
  "menangis": "menange",
  "mana": "mpi",
  "mati": "matae",
  "menyeberang": "pelawat",
  "peluk": "nyekapu",
  "panen": "maju",
  "perut": "batek",
  "pahit": "pait",
  "pintu": "pamen",
  "pakaian": "sapai",
  "perahu": "alut",
  "parang": "mandau",
  "panjang": "dadok",
  "pendek": "bu'et",
  "pedas": "sanit",
  "pergi": "tei",
  "pandai": "encam",
  "pohon": "puun",
  "rindu": "menok menawai",
  "sayur": "lekey",
  "suami mu": "laki koq",
  "satu bulan": "ca bulan",
  "setuju": "aha",
  "selimut": "kelumah",
  "benar": "sio",
  "di": "ka",
  "sini": "ini",
  "sana": "ina",
  "situ": "ina",
  "berlari": "kasa",
  "berbaring": "meken",
  "bersandar": "nyendei",
  "berkebun": "uyam pula",
  "nasi": "kenan",
  "pedagang": "toke",
  "nangis": "nange",
  "main": "piat",
  "ya": "aha",
  "antara": "aang",
  "hilir": "aba",
  "peraturan": "adet",
  "kenapa": "adi",
  "mengapa": "adi",
  "kesatu": "ading",
  "dahulu": "ading",
  "terdahulu": "ading",
  "lalang": "ai'",
  "pasir": "ait",
  "tuntun": "ajak",
  "baris": "ajat",
  "keberanian": "akang",
  "memberanikan": "ngakang",
  "berani": "makang",
  "ide": "aken",
  "pikiran": "aken",
  "kebijaksanaan": "aken",
  "pinggang": "aking",
  "rakit": "akit",
  "kapal": "akit",
  "meraup": "makup",
  "cupu": "a'i'",
  "jantan": "a'ung",
  "belukar": "ma'ut",
  "semak": "ma'ut",
  "bersemak": "ma'ut",
  "berumput": "ma'ut",
  "rumput": "ma'ut",
  "dapat": "ala'",
  "mendapatkan": "ala'",
  "bisa": "ala'",
  "ranting": "alan",
  "setengah": "alang",
  "kebiasaan": "alay",
  "lazim": "alay",
  "jalur": "ale",
  "banding": "aliu",
  "arus": "alo",
  "mengukur": "alut",
  "simpan": "mambin",
  "menyimpan": "mambin",
  "memegang": "mambin",
  "pegang": "mambin",
  "memelihara": "mambim",
  "tersimpan": "pambin",
  "rantai": "ambit",
  "bodoh": "ameng",
  "bisu": "ameng",
  "keluarga": "amit",
  "mungkin": "amu'",
  "kekanakkanakan": "pekanak",
  "kembar": "pit",
  "saudara": "aung",
  "saudari": "aung",
  "menatap": "aneng",
  "tatap": "aneng",
  "kulit": "anit",
  "punya": "anun",
  "milik": "anun",
  "rintangan": "apat",
  "aral": "apat",
  "halangan": "apat",
  "terlintang": "papat",
  "tertahan": "papat",
  "terhalang": "papat",
  "menara": "apaw",
  "penara": "apaw",
  "bukit": "apaw",
  "tali": "apay",
  "cacat": "apet",
  "kapur": "apo",
  "tertarik": "arep",
  "berminat": "arep",
  "keinginan": "arep",
  "cenderung": "arep",
  "lahap": "asam",
  "rakus": "asam",
  "likut": "mundur",
  "asal": "asen",
  "jurang": "asep",
  "lembah": "asep",
  "beratus": "ato",
  "meletakkan": "maung",
  "menempatkan": "maung",
  "menaruh": "maung",
  "andai": "awa'",
  "basi": "basi",
  "basa'": "basah",
  "batu": "batu",
  "bayar": "bayan",
  "teriak": "bika'",
  "kuning": "bila'",
  "pesawat": "bilun",
  "racun": "bisa'",
  "sisir": "bit",
  "cemas": "bisaw",
  "buku": "buk",
  "bersih": "bui'",
  "bola": "bula",
  "aneh": "bulen",
  "gila": "buling",
  "bom": "bum",
  "bermusuhan": "pebunu'",
  "selamat": "bunut",
  "memar": "buok",
  "marah": "busi'",
  "botol": "butun",
  "lain": "cena'an",
  "darah": "daa'",
  "janji": "daji'",
  "tangkap": "dakep",
  "ketika": "dalaw",
  "daerah": "dalé",
  "sesat": "daru",
  "alat": "de'buat",
  "terang": "dema",
  "hemat": "demun",
  "lambat": "dena'",
  "kuat": "denggep",
  "tahu": "tisen",
  "lampu": "titiw",
  "bengkak": "tukuk",
  "lupa": "turan",
  "susu": "tusu",
  "muntah": "tuta'",
  "dermaga": "tuun",
  "hujan": "ujan",
  "tangan": "uju' ",
  "langsung": "umba",
  "dada": "usuk",
  "otak": "utek",
  "membuat": "uyan"
}
)rawliteral";

/*
  Catatan:
  - Jika ada frasa yang sering muncul (misalnya "apa kabar"), Anda dapat langsung memasukkannya ke kamus 
    seperti "apa kabar": "inu denga" agar pencocokan multi-kata lebih mudah.
  - Sisanya tetap sama seperti sebelumnya, dipersingkat di sini hanya untuk ilustrasi.
*/

// 3. KODE HTML/CSS/JS (Dalam PROGMEM)
//    Halaman utama dengan gradien (#89C4F4 -> #F5C3CB), efek blur, border-radius besar, dsb.
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="id">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
  <title>Dayak Kenyah Translator & MC Engine</title>
  <link
    rel="stylesheet"
    href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.0.0/css/all.min.css"
  />
  <style>
    @import url('https://fonts.googleapis.com/css2?family=Inter:wght@400;500;600&display=swap');

    /* Warna gradien latar belakang */
    body {
      margin: 0;
      padding: 0;
      font-family: 'Inter', sans-serif;
      /* Gradien: biru bubuk (#89C4F4) ke merah muda lembut (#F5C3CB) */
      background: linear-gradient(135deg, #89C4F4, #F5C3CB);
      background-repeat: no-repeat;
      background-attachment: fixed;
      min-height: 100vh;
      display: flex;
      flex-direction: column;
      color: #1A1A2E; /* teks biru gelap untuk kontras */
    }

    /* Container dengan efek blur & transparansi */
    .container {
      flex: 1;
      max-width: 900px;
      margin: 2rem auto;
      padding: 2rem;
      background: rgba(255, 255, 255, 0.6);
      backdrop-filter: blur(10px);
      border-radius: 20px;
      box-shadow: 0 8px 20px rgba(0,0,0,0.2);
    }

    h1, h2 {
      margin-bottom: 1rem;
      text-align: center;
    }

    .header {
      text-align: center;
      margin-bottom: 2rem;
    }

    .logo {
      width: 120px;
      border-radius: 8px;
      margin-bottom: 1rem;
    }

    .description {
      margin-top: 0.5rem;
      font-size: 0.9rem;
      text-align: center;
    }

    .translator-box, .mc-box {
      margin-bottom: 2rem;
    }

    .box-title {
      font-weight: 600;
      margin-bottom: 0.5rem;
      font-size: 1.2rem;
    }

    .input-group, .mc-group {
      display: flex;
      gap: 1rem;
      margin: 1rem 0;
      flex-wrap: wrap;
    }

    textarea, input, select, button {
      font-family: 'Inter', sans-serif;
      font-size: 1rem;
      border-radius: 12px;
      border: none;
      padding: 1rem;
      outline: none;
      transition: all 0.3s ease;
    }

    textarea, input {
      flex: 1;
      min-height: 60px;
      resize: vertical;
      background-color: rgba(255, 255, 255, 0.8);
    }

    textarea:focus, input:focus, select:focus {
      box-shadow: 0 0 8px rgba(0, 0, 0, 0.2);
      background-color: rgba(255, 255, 255, 0.9);
    }

    .swap-btn, .mc-btn {
      background-color: #1A1A2E;
      color: #fff;
      cursor: pointer;
      min-width: 100px;
    }

    .swap-btn:hover, .mc-btn:hover {
      background-color: #333C55;
      transform: translateY(-2px);
      box-shadow: 0 6px 12px rgba(0,0,0,0.15);
    }

    .output-box, .mc-output {
      background-color: rgba(255,255,255,0.8);
      padding: 1rem;
      border-radius: 12px;
      min-height: 60px;
      margin-top: 1rem;
      transition: background-color 0.3s ease;
    }

    .output-box:hover, .mc-output:hover {
      background-color: rgba(255,255,255,0.9);
    }

    .social-section {
      text-align: center;
      padding: 1rem;
    }

    .social-link {
      color: #1A1A2E;
      margin: 0 0.5rem;
      font-size: 1.2rem;
      transition: color 0.3s ease;
    }
    .social-link:hover {
      color: #000;
    }

    .footer {
      font-size: 0.8rem;
      margin-top: 0.5rem;
      color: #333;
    }

    @media (max-width: 768px) {
      .container {
        margin: 1rem;
        padding: 1rem;
      }
      textarea, input, select, button {
        font-size: 0.9rem;
      }
    }
  </style>
</head>
<body>
  <div class="container">
    <div class="header">
      <img
        src="https://i.pinimg.com/736x/cc/82/6d/cc826d6dccc9dcf66760320f295a688f.jpg"
        class="logo"
      />
      <h1>Dayak Kenyah Translator & MC Engine</h1>
      <p class="description">
        Penerjemah bahasa Indonesia ↔ Dayak Kenyah dengan 500+ kosakata yang berjalan pada ESP32.<br/>
        Menangani soal pilihan ganda dengan pendekatan tokenisasi & partial matching.
      </p>
    </div>

    <!-- Bagian Penerjemah -->
    <div class="translator-box">
      <div class="box-title">Translator</div>
      <p><strong>Translate from:</strong> <span id="currentLang">Indonesian</span></p>
      <div class="input-group">
        <textarea
          id="inputText"
          placeholder="Enter Indonesian text..."
        ></textarea>
        <button class="swap-btn" onclick="swapLanguage()">↔</button>
      </div>
      <p><strong>Translation Result (<span id="targetLang">Dayak Kenyah</span>):</strong></p>
      <div class="output-box">
        <p id="outputText"></p>
      </div>
    </div>

    <!-- Bagian Soal Pilihan Ganda -->
    <div class="mc-box">
      <div class="box-title">Pemilihan Jawaban Pilihan Ganda</div>
      <div class="mc-group">
        <textarea
          class="mc-input"
          id="mcQuestion"
          placeholder="Masukkan pertanyaan (multi-kata atau satu kata)"
        ></textarea>
      </div>
      <div class="mc-group">
        <input
          type="text"
          id="mcOptions"
          placeholder="Pisahkan pilihan dengan koma, misal: kamu lagi ngapain, kamu dimana, apa kabar, terimakasih untukmu"
          style="flex:1"
        />
      </div>
      <div class="mc-group">
        <select id="mcLang" style="flex:1">
          <option value="id">Soal Bahasa Indonesia (pilihan dalam Dayak)</option>
          <option value="dyk">Soal Bahasa Dayak (pilihan dalam Indonesia)</option>
        </select>
        <button class="mc-btn" onclick="submitMC()">Submit MC</button>
      </div>
      <div class="mc-output">
        <p id="mcResult"></p>
      </div>
    </div>

    <div class="social-section">
      <div class="social-links">
        <a
          href="https://github.com/RyuHiiragi"
          class="social-link"
          target="_blank"
          ><i class="fab fa-github"></i
        ></a>
        <a
          href="https://www.instagram.com/kysukamieayam"
          class="social-link"
          target="_blank"
          ><i class="fab fa-instagram"></i
        ></a>
      </div>
      <div class="footer">
        <p>Muhammad Rizky Saputra</p>
        <p>XI TJKT 2</p>
      </div>
    </div>
  </div>

  <script>
    let currentLang = 'id';

    function swapLanguage() {
      currentLang = currentLang === 'id' ? 'dyk' : 'id';
      document.getElementById('currentLang').textContent =
        currentLang === 'id' ? 'Indonesian' : 'Dayak Kenyah';
      document.getElementById('targetLang').textContent =
        currentLang === 'id' ? 'Dayak Kenyah' : 'Indonesian';
      document.getElementById('inputText').placeholder = `Enter ${
        currentLang === 'id' ? 'Indonesian' : 'Dayak'
      } text...`;
      document.getElementById('inputText').value = '';
      document.getElementById('outputText').textContent = '';
    }

    function translateText() {
      const input = document.getElementById('inputText').value.trim().toLowerCase();
      if (!input) return;
      fetch(`/translate?text=${encodeURIComponent(input)}&lang=${currentLang}`)
        .then((response) => response.text())
        .then((result) => {
          document.getElementById('outputText').textContent = result;
        });
    }
    document.getElementById('inputText').addEventListener('input', translateText);

    function submitMC() {
      const question = document.getElementById('mcQuestion').value.trim();
      const options = document.getElementById('mcOptions').value.trim();
      const lang = document.getElementById('mcLang').value;
      if (!question || !options) {
        document.getElementById('mcResult').textContent =
          'Pertanyaan dan pilihan tidak boleh kosong!';
        return;
      }
      fetch(
        `/mc?question=${encodeURIComponent(question)}&options=${encodeURIComponent(
          options
        )}&lang=${lang}`
      )
        .then((response) => response.text())
        .then((result) => {
          document.getElementById('mcResult').textContent = result;
        });
    }
  </script>
</body>
</html>
)rawliteral";

// 4. KONFIGURASI SERVER
WebServer server(80);
StaticJsonDocument<16384> dict; // Diperbesar untuk 500+ kosakata + frasa

// Deklarasi fungsi
void handleRoot();
void handleTranslate();
void handleMC();

// -------------------------------------------------------
// BAGIAN ENGINE
// -------------------------------------------------------

/*
  Fungsi partialMatch():
  - Melakukan pencocokan "parsial" secara sederhana: 
    memeriksa apakah 'token' adalah substring dari 'dictWord' atau sebaliknya.
  - Bisa diganti dengan algoritma yang lebih canggih (Levenshtein distance) 
    untuk pencocokan lebih baik.
*/
bool partialMatch(const String& token, const String& dictWord) {
  // Keduanya sudah di-lowercase di luar
  // Cek substring (contoh: "kabar" & "denga kabar" => tidak match, 
  //   tapi "kabar" & "apa kabar" => match jika mau substring)
  // Sederhana: cek jika token adalah substring dari dictWord 
  //   atau dictWord adalah substring dari token.
  if (dictWord.indexOf(token) != -1 || token.indexOf(dictWord) != -1) {
    return true;
  }
  return false;
}

/*
  Fungsi tokenizeSentence():
  - Memecah kalimat (dengan menghapus tanda baca sederhana) menjadi token-token kata.
*/
std::vector<String> tokenizeSentence(const String& sentence) {
  String tmp = sentence;
  tmp.replace("?", " ");
  tmp.replace("!", " ");
  tmp.replace(".", " ");
  tmp.replace(",", " ");
  tmp.replace(":", " ");
  tmp.replace(";", " ");
  tmp.trim();
  
  std::vector<String> tokens;
  int start = 0;
  while (true) {
    int spacePos = tmp.indexOf(' ', start);
    if (spacePos == -1) {
      String last = tmp.substring(start);
      last.trim();
      if (last.length() > 0) tokens.push_back(last);
      break;
    } else {
      String piece = tmp.substring(start, spacePos);
      piece.trim();
      if (piece.length() > 0) tokens.push_back(piece);
      start = spacePos + 1;
    }
  }
  return tokens;
}

/*
  Fungsi translateSentencePartial():
  - Menerjemahkan kalimat per token. 
  - Untuk ID->Dayak, jika ketemu exact match di kamus -> pakai itu,
    kalau tidak ketemu exact, coba partial match.
  - Untuk Dayak->ID, hal serupa tapi kebalik (harus bandingkan value->key).
*/
String translateSentencePartial(const String& input, const String& lang, const JsonObject& dictObj) {
  std::vector<String> tokens = tokenizeSentence(input);
  String result;
  
  // ID -> Dayak
  if (lang == "id") {
    for (auto &t : tokens) {
      t.toLowerCase();
      // Cek exact match
      if (dictObj.containsKey(t)) {
        result += dictObj[t].as<String>() + " ";
      } else {
        // Cek partial match
        bool matched = false;
        for (JsonPair pair : dictObj) {
          String key = pair.key().c_str();
          key.toLowerCase();
          if (partialMatch(t, key)) {
            // Gunakan value kamus
            result += pair.value().as<String>() + " ";
            matched = true;
            break;
          }
        }
        if (!matched) {
          // Kalau tetap tidak ketemu, pakai kata aslinya
          result += t + " ";
        }
      }
    }
  }
  // Dayak -> ID
  else {
    // Kita perlu cek ke pair.value() -> pair.key() 
    //   plus partial matching
    for (auto &t : tokens) {
      bool foundExact = false;
      t.toLowerCase();
      // Cek full match di value
      for (JsonPair pair : dictObj) {
        String val = pair.value().as<String>();
        val.toLowerCase();
        if (val == t) {
          result += String(pair.key().c_str()) + " ";
          foundExact = true;
          break;
        }
      }
      if (foundExact) continue;

      // Kalau belum foundExact, coba partial match
      bool partialFound = false;
      for (JsonPair pair : dictObj) {
        String val = pair.value().as<String>();
        val.toLowerCase();
        if (partialMatch(t, val)) {
          // Gunakan pair.key()
          result += String(pair.key().c_str()) + " ";
          partialFound = true;
          break;
        }
      }
      if (!partialFound && !foundExact) {
        // Tidak ketemu sama sekali
        result += t + " ";
      }
    }
  }
  result.trim();
  return result;
}

// -------------------------------------------------------
// SETUP & ROUTING
// -------------------------------------------------------
void setup() {
  Serial.begin(115200);
  
  // Sambungkan ke WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nTerhubung! IP: " + WiFi.localIP().toString());

  // Parsing kamus dari PROGMEM
  DeserializationError error = deserializeJson(dict, dictionary_json);
  if (error) {
    Serial.println("Error parsing JSON: " + String(error.c_str()));
    return;
  }

  // Routing server
  server.on("/", HTTP_GET, handleRoot);
  server.on("/translate", HTTP_GET, handleTranslate);
  server.on("/mc", HTTP_GET, handleMC);
  server.begin();
}

void loop() {
  server.handleClient();
}

// -------------------------------------------------------
// HANDLER UTAMA
// -------------------------------------------------------
void handleRoot() {
  server.send_P(200, "text/html", index_html);
}

// -------------------------------------------------------
// HANDLER TERJEMAHAN
// -------------------------------------------------------
void handleTranslate() {
  if (!server.hasArg("text") || !server.hasArg("lang")) {
    server.send(400, "text/plain", "Parameter tidak lengkap");
    return;
  }
  String text = server.arg("text");
  String lang = server.arg("lang");
  // Gunakan pendekatan partial untuk multi-kata
  String translated = translateSentencePartial(text, lang, dict.as<JsonObject>());
  server.send(200, "text/plain", translated);
}

// -------------------------------------------------------
// HANDLER MC
// -------------------------------------------------------
void handleMC() {
  if (!server.hasArg("question") || !server.hasArg("options") || !server.hasArg("lang")) {
    server.send(400, "text/plain", "Parameter tidak lengkap untuk soal pilihan ganda");
    return;
  }

  String question = server.arg("question");
  String optionsStr = server.arg("options");
  String lang = server.arg("lang"); // "id" atau "dyk"

  // 1. Terjemahkan / cari "makna" dari question -> kita pakai partial approach juga.
  //    Asumsikan: untuk soal bahasa Indonesia, question -> Dayak => kita cari kata kunci 
  //    (kita coba terjemahkan ke Dayak, lalu nanti cocokkan ke key?)
  //    Sebaliknya, untuk Dayak -> Indonesia, kita cari value -> key.
  // Sebenarnya, kita cukup "mendapatkan" kata kunci dengan pendekatan partial, 
  // tapi agar lebih generik, kita terjemahkan question dulu, lalu pakai terjemahan 
  //   untuk mencocokkan.

  // 2. Di sisi "MC", kita asumsikan jawaban benar adalah "correctAnswer" (string) 
  //    yang kita dapat dari question. 
  //    Lalu bandingkan dengan daftar pilihan (yang juga kita partial match).

  // Terjemahkan question -> "target" (apakah ID->Dayak atau Dayak->ID?)
  //   Lalu target inilah yang dianggap "correctAnswer" 
  //   (karena question menanyakan "apa arti ini?" => result = "kunci").

  // Contoh: "Inu denga koq?" -> Dayak -> ID => kita terjemahkan: "apa kabar kamu?" 
  //   Mungkin "apa kabar" = "inu denga", 
  //   result partial = "apa kabar ..."

  // Kita akan ambil 2-3 token pertama dari hasil terjemahan 
  //   sebagai "correctAnswer" (sederhana).
  
  String partialResult = translateSentencePartial(question, lang, dict.as<JsonObject>());
  // Ambil misalnya token pertama atau dua token pertama 
  //   (tergantung pada implementasi; di sini kita coba 2 token)
  std::vector<String> tokens = tokenizeSentence(partialResult);
  String correctAnswer;
  if (tokens.size() == 0) {
    server.send(200, "text/plain", "Tidak ditemukan kata bermakna pada soal.");
    return;
  } else if (tokens.size() == 1) {
    correctAnswer = tokens[0];
  } else {
    // Contoh: kita ambil dua kata pertama
    correctAnswer = tokens[0] + " " + tokens[1];
  }
  correctAnswer.trim();
  correctAnswer.toLowerCase();

  // 3. Parsing opsi
  const int maxOptions = 10;
  String options[maxOptions];
  int count = 0;
  int pos = 0;
  while (pos >= 0 && count < maxOptions) {
    int commaPos = optionsStr.indexOf(',', pos);
    if (commaPos == -1) {
      options[count++] = optionsStr.substring(pos);
      break;
    } else {
      options[count++] = optionsStr.substring(pos, commaPos);
      pos = commaPos + 1;
    }
  }
  for (int i = 0; i < count; i++) {
    options[i].trim();
    options[i].toLowerCase();
  }

  // 4. Cocokkan correctAnswer dengan setiap opsi (partial).
  char answerLetter = '\0';
  const char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for (int i = 0; i < count; i++) {
    // Cek partial match
    if (partialMatch(correctAnswer, options[i])) {
      answerLetter = letters[i];
      break;
    }
  }

  if (answerLetter == '\0') {
    server.send(200, "text/plain", "Jawaban yang benar tidak ditemukan dalam pilihan yang diberikan.");
  } else {
    String response = "Jawaban yang benar kemungkinan: ";
    response += answerLetter;
    response += ") ";
    response += options[answerLetter - 'A']; 
    server.send(200, "text/plain", response);
  }
}
