SELECT
    rok,
    COUNT(id) as "vsech",
    COUNT(
        CASE
            WHEN nasledky_chodce = 'usmrcení' THEN 1
        END
    ) AS "z toho usmrcenych"
FROM crashes
GROUP BY rok
ORDER BY rok;

SELECT
    druh_komun AS "Druh komunikace",
    COUNT(id) AS "Vzorky",
    ROUND(AVG(hodina)) AS "Průměrná hodina",
    STDDEV(hodina) AS "Směrodatná odchylka hodin"
FROM crashes
GROUP BY druh_komun
ORDER BY "Vzorky" DESC;


SELECT den_v_tydnu, COUNT(id) FROM crashes GROUP BY den_v_tydnu ORDER BY count DESC;

SELECT
    misto_nehody AS "Místo",
    situace_nehody AS "Situace",
    COUNT(CASE WHEN nasledky_chodce IN ('usmrcení', 'těžké zranění') THEN 1 END) AS "Vážné",
    COUNT(id) AS "Všichni",
    ((COUNT(CASE WHEN nasledky_chodce IN ('usmrcení', 'těžké zranění') THEN 1 END) * 100 ) / COUNT(id)) AS "Procentuelně"
FROM crashes
GROUP BY misto_nehody, situace_nehody HAVING COUNT(misto_nehody) >= 10
ORDER BY "Procentuelně" DESC
LIMIT 10;