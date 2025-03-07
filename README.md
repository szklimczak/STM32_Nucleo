# STM32_Nucleo
Kody programów z zajęć Technika Mikroporcesorowa. Wykorzystano płytkę NUCLEO-F411RE wraz z nakładką KA-Nucleo-Multisensor

Materiały producenta:
- https://www.st.com/en/evaluation-tools/nucleo-f411re.html
- https://wiki.kamamilabs.com/?title=KA-Nucleo-Multisensor

Wykorzystano środowisko STM32CubeIDE

### Diody RGB
Zadanie polegało na stworzeniu programu pozwalającego wyświetlić dowolną kombinacje kolorów czterech diod RGB. Finalny program powinien zaświecić wszystkie cztery diody RGB w wybranej kombinacji (np.: R G B W). Literki oznaczają kolor świecenia diody.

### Wyświetlacz 7-segmentowy
W zadaniu należało napisać procedurę wyświetlającą na zadanym wyświetlaczu zadaną cyfrę. Początkowo trzeba było ustalić w „Pinout & Configuration” funkcje wyprowadzeń odpowiedzialnych za sterowanie
wyświetlaczami siedmiosegmentowymi. PC8, PC9, PC10 i PC11 odpowiadają za wybór wyświetlacza. PC0 do PC7 odpowiadają za
wybór pola wyświetlacza.

### Przyciski
Zadanie polegało na napisaniu programu prezentującego liczbę naciśniętych przycisków na wyświetlaczu (2 wyświetlacze siedmiosegmentowa na licznik od każdego z przycisków). W ćwiczeniu należało najpierw zdefiniować sygnały PB0 i PB5 związane z przyciskami jako GPIO_EXTI0 oraz GPIO_EXTI5 oraz zezwolić na przerwania od linii EXTI0 i EXTI5. Gotowy program pozwala na zliczanie liczby przyciśnięć w górę i w dół (prawy przycisk zwiększa liczbę naciśnięć, lewy zmniejsza).

### ADC
Program wysyła po porcie szeregowym procentowy poziom jasności otoczenia oczytany za pomocą fotorezystora. Dane są aktualizowane z częstotliwością 1Hz, po wysłaniu z komputera znaku inicjalizującego logowanie danych (np.: ’#’). Przy testowaniu programu wykorzystano aplikację CuteCom.

### ADC DMA
Akwizycja danych z przetwornika A/C za pomocą przerwania. W obsłudze przerwania zegara wypełniamy danymi dwie tablice: BufferT i BufferAD. Pierwsza z tablic zawiera czas wejścia do obsługi przerwania, druga zawiera wynik odczytany z przetwornika A/D.
