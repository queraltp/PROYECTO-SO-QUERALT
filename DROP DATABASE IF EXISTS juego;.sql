DROP DATABASE IF EXISTS juego;
CREATE DATABASE juego;
USE juego;
CREATE TABLE jugadores(
       idJ INT NOT NULL,
       username VARCHAR (20),     
       password VARCHAR (20),

) ENGINE = InnoDB;

CREATE TABLE partidas(
       idP INT NOT NULL,     
       fecha VARCHAR (20),
       hora VARCHAR(20),
       duracion FLOAT,
       ganador VARCHAR (20),

) ENGINE = InnoDB;

CREATE TABLE participacion(
       idP INT NOT NULL,
       idJ INT NOT NULL,

) ENGINE = InnoDB;


INSERT INTO jugadores VALUES (1,'Ona02', 'ona142')
INSERT INTO jugadores VALUES (2,'Aritz09', 'aritz149')
INSERT INTO jugadores VALUES (3,'Miki05', 'miki145')

INSERT INTO partidas VALUES (1,'19/03/2023','19:00',3.9,'Aritz09')
INSERT INTO partidas VALUES (2,'22/03/2023','13:00',2.3,'Ona02')
INSERT INTO partidas VALUES (3,'31/03/2023','11:00',3.1,'Miki05')

INSERT INTO participacion VALUES (2,1)
INSERT INTO participacion VALUES (3,3)
INSERT INTO participacion VALUES (1,2)


       