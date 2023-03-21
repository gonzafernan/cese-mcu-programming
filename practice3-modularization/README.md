# Programación de Microcontroladores - Práctica 3

## Descripción
Implementación de módulo de software para trabajar con retardos no bloqueantes a partir de las funciones creadas en la práctica 2.

El móodulo implementado se encuentra dentro de la carpeta `Drivers/API/`.

El programa principal utiliza el módulo para realizar una secuencia de LEDs donde cada uno se encuentra encendido 200 ms y no se enciende más de un LED simultáneamente.

## Conexión
La práctica se encuentra resuelta para la placa de desarrollo Blue Pill (Stm32f103c8t6).

LEDs conectados en:
- LED1 -> B12
- LED2 -> B13
- LED3 -> B14

## Compilación
El proyecto se compila mediante el comando `make` dentro de la carpeta de la práctica. Luego encontrará dentro de la carpeta build el binario a descargar en la placa.