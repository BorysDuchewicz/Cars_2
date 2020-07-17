# Cars_2
Aplikacja ta pozwala na obsługę samochodów oraz ich poszczególnych części.
Każdy samochód jest złożony z konkretnych opon,silniku, oraz z podstawowych elementów takich jak model, kolor, ilość przejechanych kilometrów, cena, rodzaj podwozia. 
Informacje pobierane są z plików Json. 
W tym programie użytkownik może: 
-posortować listę samochodów po elemencie który sobie wybierze, 
-zobaczyć kolekcje samochodów o danym podwoziu z podanego przez siebie przedziału cenowego, 
-zobaczyć statystyki samochodów dla podanego elementu np. moc silnika, 
-wyszukać samochody o podanym rodzaju silnika oraz znaleźć samochody które posiadają podane przez użytkownika komponenty. 

Projekt ten posiada w sobie jeszcze metody: 
-zwracająca posortowaną mapę gdzie kluczem jest samochód a wartością ilość przejechanych km, 
-posortowaną po ilości elementów(w wartości) mapę gdzie kluczem jest rodzaj opony a wartością wektor samochodów o takim typie opon.

Aplikacja posiada własną obsługę wyjątków oraz szczegółową walidacje każdego z komponentów.
