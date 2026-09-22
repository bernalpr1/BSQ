Oq e
-> Recebe um mapa com espacos livres e obstaculos
encontra o maior quadrado sem obstaculos e marca-o
no mapa

Ex: 27.ox
27 -> Numero de linhas
. -> espaco livre
o -> obstaculo
x -> simbolo usado para preencher quadrado encontrado

A largura e descoberta ao contra os chars da primeira linha
do amapa

bsq.h
Temos duas estruturas
T_square(Dados do Mapa)
T_square x y -> largura e altura
T_square emp, obs, ful -> simbolos de espacos e livres
obstaculo e preenchimento

T_max -> cv_x, cv_y -> Cordenadas do canto inferior direito
do quadrado encontrado
T_max -> max -> quadrado vencedor cordenadas
