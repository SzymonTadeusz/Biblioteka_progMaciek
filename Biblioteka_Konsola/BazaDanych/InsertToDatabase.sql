INSERT INTO Osoba(NumerKarty, PESEL,NAZWISKO,IMIE,Stanowisko,MIEJSCOWOSC,ULICA,NumerLOKALU,Poczta)
        VALUES
(1,'92041303149','Wojciechowska','Ada','K','Warszawa','al. Niepodległości','2/5','adawojciechowska@wp.pl'),
(2,'82042016205','Mazur','Dawid','K','Warszawa','Grunwaldzka','1/8','dawidmazur820420@gmail.com'),
(3,'83071813667','Wiśniewski','Jan','K','Warszawa','Lotnicza',46,'janko432@gmail.com'),
(4,'62091105275','Adamczyk','Izabela','K','Warszawa','Piastowska','28/12','iza324@wp.pl'),
(5,'75113003804','Mucha','Zuzanna','K','Janki','Kijowska',21,'muchazuza@gmail.com'),
(6,'83102108320','Wojciechowski','Mateusz','P','Warszawa','Czarnieckiego','41/7','wojciechowskimm6767@gmail.com'),
(7,'80092402306','Kot','Piotr','P','Marki','Brzeska',10,'kotpiotr80@gmail.com'),
(8,'89061010447','Leśniak','Anna','K','Warszawa','Świętokrzyska','7/12','lesniakanna@hotmail.com'),
(9,'86013117726','Kozłowska','Maja','K','Warszawa','Toruńska',15,'kozlowska.maja86@onet.pl'),
(10,'82051818304','Maciejewski','Adrian','P','Warszawa','Ostrobramska',13,'adrianmaciejewski@gmail.com'),
(11,'67092514361','Stasiak','Magdalena','K','Gdańsk','Plac Zawiszy',45,'stasiakm67@wp.pl'),
(12,'66090113329','Ciesielska','Justyna','K','Warszawa','Kamieńskiego','17/13','ciesielska.justyna@onet.pl'),
(13,'79030503489','Paluch','Weronika','K','Warszawa','Arabska',45,'weronikapaluch@wp.pl'),
(14,'86042617367','Jankowski','Mikołaj','K','Pruszków','Algierska',26,'janowski.miki@gmail.com'),
(15,'94010316345','Wieczorek','Kamil','P','Warszawa','Dolna',37,'kamilwieczorek94@gmail.com'),
(16,'63092104874','Kowalski','Damian','K','Warszawa','Gagarina',46,'dkowalski@gmail.com');



INSERT INTO `biblioteka`.`katalog`(`IdKatalogu`,`NazwaKatalogu`)
VALUES 	(1,'Literatura piękna'),
		(2,'Informatyka'),
        (3,'Prawo'),
        (4,'Ekonomia'),
		(5,'Matematyka'),
        (6,'Nauki przyrodnicze'),
		(7, 'Inne');



INSERT INTO `biblioteka`.`ksiazka`(`IdKsiazki`,`IdKatalogu`,`Tytul`,`RokWydania`,`Gatunek`,`Format`,`LiczbaStron`,`PierwszyRozdzial`)
VALUES
(1,2,'Symfonia C++, T.1',2007,'Informatyka','B5',633,'Jeśli szukasz nowoczesnego języka programowania, to jesteś na dobrej drodze. Poznaj C++ - jeśli chcesz się go nauczyć, ta książka jest właśnie dla Ciebie!'),
(2,2,'Ruby - szybki start',2014, 'Informatyka','B5',212, 'Czy nie zastanawiałeś się nad fenomenem języka Ruby? Programiści obsługujący framework RoR zarabiają 2x więcej niż pozostali - jak to możliwe?'),
(3,2,'Układy mikroprocesorowe. Przykłady rozwiązań',2009,'Automatyka','B5',749, 'Książka prezentuje podstawy konstrukcji urządzeń cyfrowych i mikroprocesorowych. Zawiera ona omówienia wybranych układów scalonych małej, średniej i dużej skali integracji oraz liczne przykłady ich zastosowań.'),
(4,2,'Czysty kod',2011,'Informatyka','A5',317, 'Jak pisać dobry kod, a zły przekształcić w dobry? Jak formatować kod, aby osiągnąć maksymalną czytelność?'),
(5,2,'AngularJS. Profesjonalne techniki',2015,'Informatyka','B5',616, 'Za tym popularnym szkieletem stoi firma Google, która dba o jego ciągły rozwój. Ta książka została w całości poświęcona szkieletowi AngularJS. Sięgnij po nią i przekonaj się, w jaki sposób przygotować środowisko programistyczne'),
(6,7,'Barometr Regionalny : analizy i prognozy',2014,'Rolnictwo','A5',387, 'Tytuł poświęcony jest teoretycznym i empirycznym pracom z zakresu ilościowych badań regionalnych, a zwłaszcza analiz i prognoz rozwoju gospodarczego.'),
(7,6,'Optoelektronika',2014,'Elektronika','A5',416, 'Optoelektronika jest niesłychanie szybko rozwijającą się dyscypliną naukowo-techniczną, a niemal każde usprawnienie i odkrycie w tej dyscyplinie jest, można powiedzieć, błyskawicznie wdrażane do produkcji...'),
(8,1,'Old Shatterhand. Powieść z dzikiego zachodu',1995,'Western','B6',317, 'Old Shatterhand (Grzmocąca Ręka) przybywa jako młody, niedoświadczony człowiek (greenhorn) na Dziki Zachód. Na początku ima się różnych zajęć, aby zarobić na chleb...'),
(9,3,'Kary za niezgodne z prawem postępowanie z odpadami ',2011,'Prawo','B5',682, 'Wszyscy wytwórcy i posiadacze odpadów są odpowiedzialni za właściwe postępowanie z nimi. Jeżeli gospodarka odpadami jest prowadzona w sposób nieprawidłowy, wówczas...'),
(10,4,'Polityka ekonomiczna',2012,'Ekonomia','A5',317, 'Publikacja ta jest adresowana do środowisk naukowych i studentów wyższych uczelni oraz osób, które w praktyce zajmują się aktualnymi problemami polityki ekonomicznej.'),
(11,2,'Jak pozostać anonimowym w sieci',2011,'Bezpieczeństwo','B5',916, 'Problem ochrony danych osobowych we współczesnym świecie staje się coraz bardziej palący. Dotyczy to także — a może przede wszystkim — Internetu. Zawodne systemy weryfikacji danych w połączeniu z olbrzymimi możliwościami nielegalnego ich gromadzenia i wykorzystywania sprawiają, że...');




INSERT INTO `biblioteka`.`egzemplarzksiazki`(`IdEgzemplarza`,idksiazki)
VALUES(1,1),(2,1),(3,1),(4,1),(5,1),(6,1),(7,2),(8,2),(9,2),(10,3),(11,3),(12,3),(13,3),(14,3),(15,3),
(16,4),(17,4),(18,4),(19,4),(20,4),(21,5),(22,5),(23,6),(24,6),(25,6),(26,7),(27,8),(28,8),(29,8),
(30,9),(31,9),(32,9),(33,9),(34,10),(35,10),(36,11);


INSERT INTO `biblioteka`.`autor`(`IdAutora`,`Imie`,`Nazwisko`,`DataUr`)
VALUES
(1,'Jerzy','Grebosz','1960-02-15'),
(2,'Karol','May','1860-07-20'),
(3,'Mariusz','Kopiński','1985-01-09'),
(4,'John','Maxwall','1942-12-15'),
(5,'Graham','Hill','1955-03-16'),
(6,'Bogdan','Wawiński','1978-03-29'),
(7,'Anna','Malińska','1985-01-02');



INSERT INTO `biblioteka`.`autorzytytulu`(`IdAutora`,`IdKsiazki`)
VALUES
(1,1),(1,2),(2,8),(2,9),(3,3),(4,4),(5,5),(5,6),(6,7),(6,10),(7,11);

