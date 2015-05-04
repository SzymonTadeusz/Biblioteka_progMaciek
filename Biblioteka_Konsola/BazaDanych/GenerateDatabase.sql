/*==============================================================*/
/* DBMS name:      MySQL 5.0                                    */
/* Created on:     2015-05-04 21:44:50                          */
/*==============================================================*/


drop table if exists Autor;

drop table if exists AutorzyTytulu;

drop table if exists EgzemplarzKsiazki;

drop table if exists Katalog;

drop table if exists Ksiazka;

drop table if exists Osoba;

drop table if exists WypozyczenieEgzemplarza;

/*==============================================================*/
/* Table: Autor                                                 */
/*==============================================================*/
create table Autor
(
   IdAutora             int not null,
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
   IdEgzemplarza        int not null,
   IdKsiazki            int not null,
   primary key (IdEgzemplarza)
);

/*==============================================================*/
/* Table: Katalog                                               */
/*==============================================================*/
create table Katalog
(
   IdKatalogu           int not null,
   NazwaKatalogu        varchar(50) not null,
   primary key (IdKatalogu)
);

/*==============================================================*/
/* Table: Ksiazka                                               */
/*==============================================================*/
create table Ksiazka
(
   IdKsiazki            int not null,
   Tytul                varchar(50) not null,
   RokWydania           numeric(4,0),
   Gatunek              varchar(70),
   IdKatalogu           int not null,
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
   Miejscowosc          varchar(50) not null,
   Ulica                varchar(100) not null,
   NumerLokalu          varchar(10) not null,
   NumerKarty           int not null,
   Stanowisko           char(1) not null,
   primary key (PESEL)
);

/*==============================================================*/
/* Table: WypozyczenieEgzemplarza                               */
/*==============================================================*/
create table WypozyczenieEgzemplarza
(
   IdWypozyczenia       int not null,
   PESEL                char(11) not null,
   IdEgzemplarza        int not null,
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

alter table Ksiazka add constraint FK_KsiazkaWKatalogu foreign key (IdKatalogu)
      references Katalog (IdKatalogu) on delete restrict on update restrict;

alter table WypozyczenieEgzemplarza add constraint FK_Relationship_3 foreign key (PESEL)
      references Osoba (PESEL) on delete restrict on update restrict;

alter table WypozyczenieEgzemplarza add constraint FK_WypozyczanyEgzemplarz foreign key (IdEgzemplarza)
      references EgzemplarzKsiazki (IdEgzemplarza) on delete restrict on update restrict;

