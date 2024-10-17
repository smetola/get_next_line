# Get Next Line

**Get Next Line** es una función que permite leer contenido desde un file descriptor (FD), línea por línea, lo que es fundamental para manejar archivos, entradas o conexiones.

## ¿Qué hace Get Next Line?

La función `get_next_line(int fd)` devuelve una línea cada vez que es llamada. Sigue leyendo desde el punto en el que quedó, hasta que no hay más líneas. Es útil para:

- Leer archivos de texto línea por línea.
- Manejar conexiones o entradas en tiempo real.
- Trabajar con múltiples file descriptors simultáneamente.

## ¿Qué he aprendido?

Este proyecto ha sido un reto, pero me ha permitido aprender:

- **Manejo avanzado de file descriptors**: Entender cómo funcionan los FD y el concepto del "offset", que marca la posición actual de lectura en un archivo.
- **Uso de variables estáticas**: Para conservar el estado entre llamadas a la función sin perder información entre lecturas.
- **Gestión dinámica de buffers**: Cómo manejar de forma eficiente la lectura cuando el tamaño del buffer no es constante, y cómo evitar que se mezclen líneas o caracteres entre lecturas.
- **Funciones del sistema**: Profundización en funciones como `read()`, `open()`, y el manejo de errores al trabajar con archivos.

Este proyecto ha sido clave para desarrollar habilidades avanzadas en la gestión de entradas y salidas en C.
