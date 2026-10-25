# Taller-2-EdD

- Nombre: Tomás Johao Sabando Jofré
- RUT: 22.368.978-7
- Carrera: ITI
- Username: 0xbadcoded
- Paralelo: C2

## Compilar
g++ -I.h .cpp/ArbolAVL.cpp .cpp/ArbolDecision.cpp .cpp/Main.cpp .cpp/Sistema.cpp -o taller2

./taller2

## Jerarquía del árbol de decisiones.
¿Dolor >= 8 || Temperatura >= 38.5?
|-- Si: Urgencia
|
|-- No:
    ¿Edad >= 18 años?
    |-- No: Pediatria
    |
    |-- Si:
        ¿Trauma == 1 || requiereCirugia == 1?
        |-- Si:
            ¿requiereCirugia == 1?
            |-- Si: Cirugia
            |-- No: Traumatologia
        |
        |
        |-- No:
            ¿sintomasNeurologicos == 1?
            |-- Si: Neurologia
            |
            |-- No:
                ¿tipoDolor == "pecho"?
                |-- Si: Cardiología
                |
                |-- No:
                    ¿diasHospitalizacion >= 2?
                    |-- Si: Hospitalizacion
                    |-- No: Medicina general
--
Se eligió este orden debido al planteamiento de "prioridades" a la hora de
evaluar inicialmente que tan en riesgo se encuentra el paciente, para posteriormente realizar una evaluación completa del estado en el que llegó.
