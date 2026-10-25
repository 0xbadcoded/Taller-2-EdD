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
El árbol evalúa primero los criterios de urgencia. Si el paciente no cumple ese criterio, continúa con la edad y las demás características:

```mermaid
flowchart TD
    A{"¿Dolor ≥ 8 o temperatura ≥ 38.5?"}
    A -- Sí --> U[Urgencias]
    A -- No --> B{"¿Edad ≥ 18 años?"}
    B -- No --> P[Pediatría]
    B -- Sí --> C{"¿Trauma = 1 o requiere cirugía = 1?"}
    C -- Sí --> D{"¿Requiere cirugía = 1?"}
    D -- Sí --> CI[Cirugía]
    D -- No --> T[Traumatología]
    C -- No --> E{"¿Tiene síntomas neurológicos?"}
    E -- Sí --> N[Neurología]
    E -- No --> F{"¿El tipo de dolor es pecho?"}
    F -- Sí --> CA[Cardiología]
    F -- No --> G{"¿Días de hospitalización ≥ 2?"}
    G -- Sí --> H[Hospitalización]
    G -- No --> M[Medicina general]
```

Se eligió este orden para evaluar primero los criterios de urgencia y luego derivar al paciente según su edad y características. Por eso, si cumple el criterio de urgencia, se asigna a Urgencias antes de evaluar las demás preguntas.
