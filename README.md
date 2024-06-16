Tento projekt umožňuje ovládání tří LED diod (červené, zelené a modré) pomocí infračerveného dálkového ovládání a Arduino.

Hardwarové požadavky:
Arduino
IR přijímač (připojený na pin 12)
Červená LED (připojená na pin 6)
Zelená LED (připojená na pin 5)
Modrá LED (připojená na pin 9)
Rezistory (pokud jsou potřeba pro LED diody)
Návod k použití:
Připojení komponent:

Připojte IR přijímač k pinu 12 na Arduinu.
Připojte červenou LED k pinu 6 (přes rezistor).
Připojte zelenou LED k pinu 5 (přes rezistor).
Připojte modrou LED k pinu 9 (přes rezistor).
Nahrání kódu:

Nahrajte přiložený kód na Arduino.
Nastavení sériového monitoru:

Otevřete Serial Monitor v Arduino IDE a nastavte rychlost na 9600 baudů.
Použití:
Zapněte Serial Monitor:

Umožní sledování výstupů a interakci s Arduinem.
Zadávání hodnot pro LED:

Pomocí dálkového ovládání zadejte hodnoty (0-255) pro jednotlivé LED diody v následujícím pořadí:
První hodnota nastaví jas červené LED.
Druhá hodnota nastaví jas zelené LED.
Třetí hodnota nastaví jas modré LED.
Postup:
Zadávání čísel:

Stiskněte tlačítka na dálkovém ovládání odpovídající číslům (0-9).
Každý stisk tlačítka zobrazí aktuální stav zadávaného čísla v Serial Monitoru.
Potvrzení hodnoty:

Po zadání čísla stiskněte tlačítko ENTER (EQ) na dálkovém ovládání, aby se hodnota nastavila na aktuální LED.
Opakování cyklu:

Po nastavení modré LED (třetí hodnoty) se cyklus opakuje a můžete zadávat hodnoty znovu od červené LED.
Příklad:
Chcete nastavit červenou LED na hodnotu 150, zelenou LED na hodnotu 100 a modrou LED na hodnotu 200:

Červená LED:

Stiskněte tlačítka: 1, 5, 0
Poté stiskněte tlačítko ENTER (EQ)
Zelená LED:

Stiskněte tlačítka: 1, 0, 0
Poté stiskněte tlačítko ENTER (EQ)
Modrá LED:

Stiskněte tlačítka: 2, 0, 0
Poté stiskněte tlačítko ENTER (EQ)
