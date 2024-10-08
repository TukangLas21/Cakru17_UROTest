Soal 2 CAKRU 17 URO ITB
Aria Judhistira / 13523112

Program menggunakan paradigma Object-Oriented Programming (OOP) dengan tiga class utama, yakni class Robot, class Battle, dan class Game

Class Robot berisi atribut-atribut yang dimiliki robot, yakni nama, attack power, defense power, dan HP. Selain itu, terdapat konstruktor untuk membentuk sebuah object pada class Robot dan ada method untuk men-display atribut object pada class tersebut.

Class Battle berisi method start_fight. Method ini memiliki parameter dua Robot yang dipilih untuk diadu dan bertarung. Method ini memanfaatkan while loop untuk sembari menggunakan fungsi external damageBattle yang mengurangi HP secara berkala. HP robot pertama yang mencapai 0 atau di bawahnya akan kalah sedangkan robot lainnya akan menang.

Class Game berisi dua method, yakni add_robot dan start_game. Method add_robot berfungsi untuk menambahkan sebuah objek robot pada vector robot. Robot yang ditambahkan kemudian dapat digunakan untuk battle. Di sisi lain, method start_game berfungsi untuk memberi user pilihan robot dan menjalankan method start_fight dari class Battle untuk memulai pertarungan.

Pada fungsi utama (main), diinisialisasi terlebih dahulu daftar robot-robot pada sebuah vector dan dideklarasikan sebuah object NewGame yang berasal dari Class Game. Kemudian adalah semacam menu utama yang menggunakan while loop agar tetap berjalan. Pengguna dapat memilih untuk menambah robot, memulai pertarungan, atau keluar dari program pada menu tersebut.
