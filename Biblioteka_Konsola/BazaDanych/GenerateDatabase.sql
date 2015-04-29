/*==============================================================*/
/* DBMS name:      MySQL 5.0                                    */
/* Created on:     2015-04-30 00:23:42                          */
/*==============================================================*/


drop table if exists Autor;

drop table if exists AutorzyTytulu;

drop table if exists EgzemplarzKsiazki;

drop table if exists Ksiazka;

drop table if exists Osoba;

drop table if exists WypozyczenieEgzemplarza;

/*==============================================================*/
/* Table: Autor                                                 */
/*==============================================================*/
create table Autor
(
   IdAutora             int not null AUTO_INCREMENT,
   Imie                 varchar(20) not null,
   Nazwisko             varchar(30) not null,
   DataUr               date,
   primary key (IdAutora)
);

/*==============================================================*/
/* Table: AutorzyTytulu                                         */
/*==============================================================*/
create table AutorzyTytulu
(
   IdKsiazki            int not null,
   IdAutora             int not null,
   primary key (IdKsiazki, IdAutora)
);

/*==============================================================*/
/* Table: EgzemplarzKsiazki                                     */
/*==============================================================*/
create table EgzemplarzKsiazki
(
   IdEgzemplarza        int not null AUTO_INCREMENT,
   IdKsiazki            int not null,
   primary key (IdEgzemplarza)
);

/*==============================================================*/
/* Table: Ksiazka                                               */
/*==============================================================*/
create table Ksiazka
(
   IdKsiazki            int not null AUTO_INCREMENT,
   Tytul                varchar(50) not null,
   RokWydania           numeric(4,0),
   Gatunek              varchar(70),
   Format               varchar(4),
   LiczbaStron          int,
   PierwszyRozdzial     text,
   primary key (IdKsiazki)
);

alter table Ksiazka comment 'Ksiazka';

/*==============================================================*/
/* Table: Osoba                                                 */
/*==============================================================*/
create table Osoba
(
   PESEL                char(11) not null,
   Imie                 varchar(20) not null,
   Nazwisko             varchar(30) not null,
   KodPocztowy          char(5),
   Poczta               varchar(50),
   Miejscowosc          varchar(50),
   Ulica                varchar(100),
   NumerLokalu          varchar(10),
   NumerKarty           int not null,
   primary key (PESEL)
);

/*==============================================================*/
/* Table: WypozyczenieEgzemplarza                               */
/*==============================================================*/
create table WypozyczenieEgzemplarza
(
   IdWypozyczenia       int not null AUTO_INCREMENT,
   IdEgzemplarza        int not null,
   KlientPESEL          char(11) not null,
   DataWypozyczenia     datetime not null,
   DataZwrotu           datetime,
   primary key (IdWypozyczenia)
);

alter table AutorzyTytulu add constraint FK_AutorzyTytulu foreign key (IdKsiazki)
      references Ksiazka (IdKsiazki) on delete restrict on update restrict;

alter table AutorzyTytulu add constraint FK_AutorzyTytulu2 foreign key (IdAutora)
      references Autor (IdAutora) on delete restrict on update restrict;

alter table EgzemplarzKsiazki add constraint FK_EgzemplarzeKsiazki foreign key (IdKsiazki)
      references Ksiazka (IdKsiazki) on delete restrict on update restrict;

alter table WypozyczenieEgzemplarza add constraint FK_Relationship_3 foreign key (KlientPESEL)
      references Osoba (PESEL) on delete restrict on update restrict;

alter table WypozyczenieEgzemplarza add constraint FK_WypozyczanyEgzemplarz foreign key (IdEgzemplarza)
      references EgzemplarzKsiazki (IdEgzemplarza) on delete restrict on update restrict;

