
# Урок: Работа с файлами в языке C

## 1. Введение в файловый ввод/вывод
Файлы используются для **сохранения данных** на диске. Работа с файлами включает **открытие, чтение, запись и закрытие** файлов. 
В языке C для работы с файлами используется библиотека `<stdio.h>`.

Файлы бывают:
- **Текстовые файлы** – хранят данные в текстовом виде (например, `.txt`).
- **Бинарные файлы** – хранят данные в двоичном виде (например, `.dat`).

---

## 2. Основные операции с файлами

### 2.1. Открытие файла: `fopen()`
```c
FILE *fopen(const char *filename, const char *mode);
```
- `filename` – имя файла.
- `mode` – режим открытия:
  - `"r"` – чтение (файл должен существовать).
  - `"w"` – запись (файл будет создан/очищен, если существует).
  - `"a"` – добавление (данные дописываются в конец файла).
  - `"rb"`, `"wb"`, `"ab"` – режимы для **бинарных файлов**.

Пример:
```c
FILE *file = fopen("example.txt", "r");
if (file == NULL) {
    printf("Ошибка: Не удалось открыть файл.\n");
    return 1;
}
```

### 2.2. Закрытие файла: `fclose()`
```c
fclose(file);
```

---

## 3. Чтение и запись в текстовые файлы

### 3.1. Запись в текстовый файл: `fprintf()` и `fputs()`
#### Пример использования `fprintf()`:
```c
FILE *file = fopen("output.txt", "w");
fprintf(file, "Это пример записи в файл.\n");
fclose(file);
```

#### Пример использования `fputs()`:
```c
FILE *file = fopen("output.txt", "a");
fputs("Добавление новой строки.\n", file);
fclose(file);
```

### 3.2. Чтение из текстового файла: `fscanf()` и `fgets()`
#### Пример использования `fscanf()`:
```c
FILE *file = fopen("output.txt", "r");
char buffer[100];
while (fscanf(file, "%99s", buffer) != EOF) {
    printf("%s ", buffer);
}
fclose(file);
```

#### Пример использования `fgets()`:
```c
FILE *file = fopen("output.txt", "r");
char line[100];
while (fgets(line, sizeof(line), file)) {
    printf("%s", line);
}
fclose(file);
```

---

## 4. Работа с бинарными файлами

### 4.1. Запись в бинарный файл: `fwrite()`
```c
FILE *file = fopen("data.bin", "wb");
int number = 12345;
fwrite(&number, sizeof(int), 1, file);
fclose(file);
```

### 4.2. Чтение из бинарного файла: `fread()`
```c
FILE *file = fopen("data.bin", "rb");
int number;
fread(&number, sizeof(int), 1, file);
printf("Прочитанное число: %d\n", number);
fclose(file);
```

---

## 5. Управление потоками ввода/вывода

### 5.1. Перемещение указателя в файле: `fseek()` и `ftell()`
```c
FILE *file = fopen("output.txt", "r");
fseek(file, 0, SEEK_END);
long size = ftell(file);
printf("Размер файла: %ld байт\n", size);
fclose(file);
```

### 5.2. Очистка выходного буфера: `fflush()`
```c
FILE *file = fopen("output.txt", "w");
fprintf(file, "Данные для записи.");
fflush(file);
fclose(file);
```

---

## 6. Проверка ошибок при работе с файлами

### 6.1. Проверка наличия файла: `fopen()` и `NULL`
```c
FILE *file = fopen("example.txt", "r");
if (file == NULL) {
    printf("Файл не найден!\n");
} else {
    printf("Файл открыт успешно.\n");
    fclose(file);
}
```

### 6.2. Обработка ошибок: `feof()` и `ferror()`
```c
FILE *file = fopen("example.txt", "r");
char ch;
while ((ch = fgetc(file)) != EOF) {
    putchar(ch);
}
if (ferror(file)) {
    printf("Произошла ошибка при чтении файла.\n");
}
fclose(file);
```

---

## 7. Заключение

В этом уроке вы узнали:
- Как открывать, читать и записывать данные в **текстовые и бинарные файлы**.
- Как управлять **потоками ввода/вывода**.
- Как обрабатывать **ошибки** при работе с файлами.
