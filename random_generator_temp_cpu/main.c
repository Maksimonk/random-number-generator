#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

// Функция для чтения температур из файла
size_t read_cpu_temperatures(const char *file_path, int *temperatures, size_t max_temps) {
    FILE *fp = fopen(file_path, "r");
    if (!fp) {
        perror("Ошибка открытия файла с температурами");
        return 0;
    }

    size_t count = 0;
    while (count < max_temps && fscanf(fp, "%d", &temperatures[count]) == 1) {
        count++;
    }

    if (!feof(fp)) {
        fprintf(stderr, "Ошибка чтения данных из файла или файл содержит некорректные данные\n");
    }

    fclose(fp);
    return count;
}

// Функция LFSR для генерации псевдослучайного числа
unsigned int lfsr_generate(unsigned int seed) {
    unsigned int lfsr = seed;
    unsigned int bit;

    // Генерируем 32-битное псевдослучайное число
    for (int i = 0; i < 32; i++) {
        // Используем полином x^16 + x^14 + x^13 + x^11 + 1
        bit = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5)) & 1;
        lfsr = (lfsr >> 1) | (bit << 15);
    }

    return lfsr;
}

// Функция для хэширования результата LFSR с использованием SHA-256
void hash_lfsr_output(unsigned int lfsr_output, char *hash_str) {
    unsigned char hash[SHA256_DIGEST_LENGTH];

    // Вычисляем SHA-256 от значения LFSR
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, &lfsr_output, sizeof(lfsr_output));
    SHA256_Final(hash, &sha256);

    // Переводим хэш в строку в шестнадцатеричном формате
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&hash_str[i * 2], "%02x", hash[i]);
    }
    hash_str[64] = '\0';  // Завершающий нулевой символ
}

// Функция для записи хэшированных чисел в файл
void write_hashed_numbers_to_file(const char *file_path, int *temperatures, size_t count) {
    FILE *fp = fopen(file_path, "w");
    if (!fp) {
        perror("Ошибка открытия файла для записи");
        return;
    }

    char hash_str[65];  // 64 символа для SHA-256 и 1 для завершающего нуля

    for (size_t i = 0; i < count; i++) {
        // Генерируем псевдослучайное число с помощью LFSR
        unsigned int lfsr_output = lfsr_generate(temperatures[i]);

        // Хэшируем результат LFSR с использованием SHA-256
        hash_lfsr_output(lfsr_output, hash_str);

        // Записываем полный хэш в файл
        fprintf(fp, "%s\n", hash_str);
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Использование: %s <путь_к_файлу_с_температурами> <путь_к_выходному_файлу>\n", argv[0]);
        return 1;
    }

    const char *input_file_path = argv[1];
    const char *output_file_path = argv[2];

    int temperatures[100];
    size_t temp_count = read_cpu_temperatures(input_file_path, temperatures, 100);

    if (temp_count == 0) {
        fprintf(stderr, "Не удалось получить температуры из файла\n");
        return 1;
    }

    printf("Прочитанные температуры ЦПУ:\n");
    for (size_t i = 0; i < temp_count; i++) {
        printf("%d°C ", temperatures[i]);
    }
    printf("\n");

    // Генерация хэшированных чисел и запись их в файл
    write_hashed_numbers_to_file(output_file_path, temperatures, temp_count);

    printf("Псевдослучайные числа записаны в файл '%s'.\n", output_file_path);

    return 0;
}
