#include <stdio.h>

// Implementación de mi_strcmp
int mi_strcmp(const char *str1, const char *str2) {
    // Iterar mientras ambos caracteres sean iguales y no sean el final del string
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    // Devolver la diferencia entre los caracteres en el primer punto de diferencia
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

int main() {
    // Casos de prueba
    const char *str1 = "Hola";
    const char *str2 = "Hola";
    const char *str3 = "HolaMundo";
    const char *str4 = "Holanda";
    const char *str5 = "Aloha";
    const char *str6 = "holA";

    // Prueba: Ambos strings son iguales
    printf("Comparación de '%s' y '%s': %d\n", str1, str2, mi_strcmp(str1, str2));

    // Prueba: El primer string es menor al segundo string
    printf("Comparación de '%s' y '%s': %d\n", str1, str3, mi_strcmp(str1, str3));
    printf("Comparación de '%s' y '%s': %d\n", str1, str4, mi_strcmp(str1, str4));
    printf("Comparación de '%s' y '%s': %d\n", str1, str5, mi_strcmp(str1, str5));

    // Prueba: El primer string es mayor al segundo string
    printf("Comparación de '%s' y '%s': %d\n", str3, str1, mi_strcmp(str3, str1));
    printf("Comparación de '%s' y '%s': %d\n", str4, str1, mi_strcmp(str4, str1));

    // Prueba: Strings con diferentes mayúsculas y minúsculas
    printf("Comparación de '%s' y '%s': %d\n", str1, str6, mi_strcmp(str1, str6));

    return 0;
}
