# Philosophers
Multi-threading introduction by "Dining philosophers problem" solving

nbr_of_philosopher time_to_die time_to_eat time_to_sleep [max_meal]

Testings:
./philo_one 200 410 200 200 1 | grep "is eating" | wc -l

Nbdy die :
 4 410 200 200
 4 311 150 150
 5 600 150 150
 5 800 200 200 7
 7 600 150 150
 8 311 150 150
 50 311 150 150


 Sbdy die :
 3 310 200 100
 4 100 200 200
 4 310 200 100
