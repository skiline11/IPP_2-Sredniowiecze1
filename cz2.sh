#!/bin/bash
wielkosc_planszy = 10
max_liczba_tur_gracza1 = 100
max_liczba_tur_gracza2 = 100
parametr_number = 1
parametr
while [ parametr_number -le 7 ]
then
	parametr = $($parametr_number) 
echo "tralala"

echo "$@"
echo "$1"
if [ "$1" == "-n" ]
then echo "Wczytalem -n"
else echo "Wczytalem cos zlego"
fi
