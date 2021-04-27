# Philosophers
Multi-threading introduction by "Dining philosophers problem" solving

nbr_of_philosopher time_to_die time_to_eat time_to_sleep [max_meal]


Nbdy die :
 4 410 200 200
 4 311 150 150
 5 600 150 150
 5 800 200 200 7
 7 600 150 150
 8 311 150 150
 50 311 150 150

 ./philo_one 200 410 200 200 1 | grep "is eating" | wc -l

 Sbdy die :
 3 310 200 100
 4 100 200 200
 4 310 200 100


Pour faire simple, tu dois éviter une situation où tous tes philosophes sont bloqués (ex: ils ont tous une fourchette, du coup ils ne peuvent pas manger).

Pour éviter ça, tu peux :
- Éviter que les philosophes se battent pour les mêmes fourchettes (tu lances d'abord les threads des philosophes pair puis impair).
- Tu peux aussi garantir aux philosophes d'avoir la seconde fourchette s'ils peuvent attraper la première (tous les philosophes pairs essaient de prendre en premier la fourchette à leur gauche, et ceux impair essaient de prendre celle à leur droite). Si tu fais un schéma, tu verras que dans le pire des cas, un philosophe pourra toujours manger


- Faire un thread pour checker la death et un autre pour checker le max meal