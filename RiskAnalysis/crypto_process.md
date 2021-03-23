Dobrý den,

posílam jen nějaké info k tomu, co bychom chtěli řešit. Není nutné to nějak moc studovat(je toho fakt hodně), takže spíš jen abychom se měli čeho chytnout.

## Outline - co bychom chtěli řešit

- primárně bezpečnost, potřebovali bychom vědět jak:
  - vyřešit šifrování dat
    - už nějaké samozřejmně máme, ale konečně jsme dostali prostor pro jeho zlepšení, protože momentálně je dost nedostatečné
    - vypracovali jsme nějaký návrh, s kterým si už pár týdnů hrajeme, ale nevíme jestli je to správná cesta
    - taky by se nám hodilo vědět, jaká je praxe se šifrováním ve větších firmách
      - tím se myslí hlavně: co vše šifrovat? zatím máme zašifrovaná všechny upozornění a informace kolem, ale co třeba uživatelé(emaily, jméno, telefon, ...) ?
  - infrastruktura
    - tím že nemáme zatím nikoho se vzděláním, které by bylo vyloženě v oblasi kyberbezpečnosti,
      nevíme jestli děláme všechny věci, které bychom měli dělat, hlavně v technické oblasti
    - některé oblasti, které nás napadly
      - bezpečností monitoring
        - jak, má to cenu když je všechno v cloudu?
      - penetrační testy
        - už jsme se snažili někoho si na to najmout, ale zatím se to nepovedlo
        - kdy to má cenu začít řešit?
  - ostatní
    - uživatelské zabezpečení
      - momentálně máme nasazené 2FA, ale přemýšlíme jestli neřešit třeba i Single Sign On

## Obecné info

### Co je NNTB

Pokusím se to nějak stručně shrnout. Marketingová verze tohohle popisu je dostupná tady:
https://www.firmy.nntb.cz/o-nas

Jsme v podstatě platforma, která sbírá feedback, který je ale o něco citlivější na ochranu dat, než ten klasický.
Pokud se zaměstnanec(nebo žák školy) necítí dobře, vidí něco co ho na pracovišti znepokojuje nebo má feedback,
který nechce podávat osobně, má možnost přijít na naše webové stránky a prostřednictvím jich poslat upozornění zaměstnavateli(klasicky nějaké HR odělení), které dál problém řeší.

### Platformy

- Webové stránky
  - funkčně slouží hlavně pro registraci firmy a odeslání upozornění
- Mobilní appka
  - ještě jednodušší platforma, lze jen odeslat upozornění
- Follow up
  - webová aplikace, která slouží pro odesílatele
  - po odeslání upozornění nagenerujeme kód, kterým se lze přihlásit do chatu, ve kterém si může odesílatel dopisovat s řešitelem
- Administrace
  - slouží pro rešitele upozornění, může zde:
    - prohlížet upozornění
    - chatovat s odesílatelem
    - managment kolem upozornění(přiřazování, komentování, atd.)
- Backend
  - všechny tyto aplikace obsluhuje

## Šifrování dat

- momentálně šifrujeme všechno symetrickou AES šifrou
- chtěli bychom to změnit hlavně ve smyslu:
  - nemít žádnou možnost jak se k upozorněním dostat(tu momentálně prakticky taky nemáme, ale teoreticky je ten klíč pořád někde uložený, takže bychom ho mohli získat a upozornění rozšifrovat)
  - nemít ke všem datům jediný dlouhý klíč
- řešení zatím vidíme v implementaci E2E šifrování, ke kterému jsme udělali nějaký návrh, který by asi fungoval,
  ale má pořád slabá místa, které nevíme jak rozumně řešit:
  - ukládání private klíče na klientovi
    - při dešifrování dat, by měl mít každý klient svůj private klíč, kterým bude schopen rozšifrovat si data
    - ten si natáhne po zadání hesla při loginu, ale nevíme kam
      - je bezpečné aby tyto data ležela čistě jen v browseru(localstorage, sessionstorage, ...), nebudou náchylné třeba k XSS?
  - effektivní ukládání zašifrovaných upozornění
    - momentálně bychom to dělali jako PGP, kdy nagenerujeme klíč, kterým zašifrujem upozornění symetricky
      a tento klíč zašifrujeme pro každého uživatele jeho public klíčem
    - to se mi ale nezdá effektivní, budeme ukládat x různých částí pro každého uživatele se stejným klíčem
  - reset hesla
    - jsme schopni dělat rozumný reset hesla a zároveň E2E encryption?
    - jediné co mě napadlo bylo nešifrovat private klíč uživatele v db jeho heslem, ale místo toho:
      - použít funkci pro derivaci klíčů a dostat nový klíč, kterým se privátní klíč zašifruje
      - z toho uložit polovinu na server a polovinu vrátit uživateli po registraci, třeba jako certifikát, který bude nutný pro obnovení hesla
      - nebude to ale spíš zhoršovat security? bude to pořád E2E, kde nemáme přístup k datům?s
  - přidávání nového uživatele
    - uživatel který přidává jiného uživatele, nemusí mít přístup k upozorněním, ke kterým by nový uživatel přístup mít měl
    - je možnost nějak navrhnout systém šifrování, který to bude splňovat, nebo je prostě potřeba vysvětlit projekťákovi že je to blbost(už jsme se o to snažili)?
