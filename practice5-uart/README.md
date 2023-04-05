# Programación de Microcontroladores - Práctica 5

## Descripción
Implementar un módulo de software sencillo para trabajar con la UART.

El programa, al igual que la práctica 4, realiza las siguientes acciones:
- Tooglea el LED1 al presionar el pulsador.
- Tooglea el LED3 al soltar el pulsador.
- Blink del LED2 con un período que se varía entre 100ms y 500ms en pasos de 100ms cada vez que se presiona el pulsador.

Además, se incorpora la conexión UART. Una vez inicializado el periférico, se envía por UART un mensaje con la configuración del mismo.

Ante cada flanco descendente o ascendente se notifica por UART el evento.

## Conexión
LEDs, USER_BUTTON y líneas de UART conectadas en:
- LED1 -> B12
- LED2 -> B13
- LED3 -> B14
- USER_BUTTON -> A9
- UART RX -> B6
- UART TX -> B7

## Compilación
El proyecto se compila mediante el comando `make` dentro de la carpeta de la práctica. Luego encontrará dentro de la carpeta build el binario a descargar en la placa.
