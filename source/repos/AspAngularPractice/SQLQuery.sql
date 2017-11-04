/*DataBase*/
create database GetYourMovie

/*Tables*/

create table Movies (id int primary key identity(1,1) not null, movieName varchar(60) not null, movieGender varchar(60))
go
create table Users (id int primary key identity (1,1) not null, userEmail varchar(60), userPs varchar(60))
go

/*Queries*/

/*Insert*/

