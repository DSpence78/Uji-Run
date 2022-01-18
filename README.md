# Uji-Run

#Uji Run Sampel Kecil

DESKRIPSI
	
	Program ini merupakan program aplikasi yang dibuat untuk menjalankan uji statistik non parameterik, yakni uji run untuk menguji apakah data sampel
	yang diambil dari populasi bersifat random atau tidak.
	
	Program ini digunakan untuk data yang bertipe nominal dan khusus untuk kasus sampel kecil dengan tingkat signifikansi yang digunakan adalah 5 persen.
	Sampel kecil berarti bahwa data sampel untuk kejadian m/'sukses' dan kejadian n/'gagal' masing-masing banyaknya tidak lebih dari 20 dengan jumlah
	sampel maksimal yang dapat digunakan adalah sebanyak 40.

	Untuk data sampel yang tidak memenuhi syarat uji run sampel kecil tidak dapat dilakukan analisis, tetapi tetap dapat dilakukan proses penghitungan.

DATA YANG DIGUNAKAN
	
	Terdapat dua data file yang digunakan dalam program aplikasi ini yang harus ada saat program dieksekusi, yakni data tabel run dalam folder 
	'tabel run' yang bernama F1.csv dan F2.csv.
	
	Kedua file tersebut digunakan untuk membuat tabel run F1 dan F2 yang digunakan pada proses analisis.

FITUR
	
	Terdapat 5 pilihan menu yang dapat digunakan oleh user:
	
	* Input data, digunakan untuk menginput data sampel yang akan dipakai untuk melakukan analisis data. User hanya dapat menginput 1 set data sampel,
	  jika user ingin menginput data sampel lainnya, data sampel sebelumnya akan dihapus dan digantikan oleh data sampel terbaru.
	
	* Tampilkan data, digunakan untuk menampilkan data sampel yang sudah diinput oleh user. Jika user belum melakukan input data, data tidak dapat
	  ditampilkan.

	* Analisis data, digunakan untuk melakukan penghitungan dan melakukan analisis data. Hasil penghitungan dan analisis akan ditampilkan ke layar 
	  console. Hasil analisis berupa tolak H0 dan/atau gagal tolak H0 serta deskripsi mengenai makna dari tolak/gagal tolak H0. Jika user belum 
	  melakukan input data, analisis tidak dapat dilakukan.

	* Analisis dan cetak data, memiliki fungsi yang sama dengan menu analisis data tetapi outputnya akan dicetak ke dalam file teks yang bernama 
	  'analisis.txt' di folder utama. Jika user belum melakukan input data, analisis tidak dapat dilakukan. Analisis yang akan dicetak ke dalam file 
	  'analisis.txt' hanya analisis dari satu data sampel saja. Jika dilakukan input data lainnya, isi file 'analisis.txt' sebelumnya akan ditimpa dengan
	  hasil analisis dari data sampel terbaru.

	* Keluar, digunakan untuk keluar dari program saat user selesai menggunakan program ini.

CONTACT

	222011829@stis.ac.id
	089531740080

NOTE

	Program ini sepenuhnya dibuat oleh saya sendiri, Damar Septia Nugraha, dan tanpa mengutip source code orang lain.
