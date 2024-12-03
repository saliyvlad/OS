#!/bin/bash

# Инициализация переменных
param_count=0
command=""

# Обработка параметров командной строки
while getopts "f:m:" opt; do
    case $opt in
        f)
            command="$OPTARG"
            ;;
        m)
            file_name="$OPTARG"
            ;;
        *)
            echo "Неизвестная опция"
            exit 1
            ;;
    esac
    ((param_count++))
done

# Вывод первых двух параметров
shift $((OPTIND - 1))
echo "Первые два параметра: $1 $2"

# Вывод числа параметров
echo "Число параметров: $param_count"

# Проверка опции -f
if [[ -n "$command" ]]; then
    read -p "Введите команду: " input_command
fi

# Проверка опции -m
if [[ -n "$file_name" ]]; then
    if [[ -e "$file_name" ]]; then
        echo "Файл '$file_name' существует."
    else
        echo "Такого файла нет."
    fi
fi
