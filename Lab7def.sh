name=""
count=0

# Обработка опций с помощью getopts
while getopts ":n:c:" opt; do
    case $opt in
        n)
            name="$OPTARG"
            ;;
        c)
            count="$OPTARG"
            ;;
        \?)
            echo "Неверная опция: -$OPTARG" >&2
            exit 1
            ;;
        :)
            echo "Опция -$OPTARG требует аргумент." >&2
            exit 1
            ;;
    esac
done

# Вывод информации о переданных параметрах
echo "Количество переданных параметров: $#"
echo "Имя: $name"
echo "Число: $count"

# Проверка, если имя файла задано, и вывод его содержимого
if [ -n "$name" ]; then
    if [ -f "$name" ]; then
        echo "Содержимое файла $name:"
        cat "$name"
    else
        echo "$name не является файлом."
    fi
else
    echo "Имя файла не указано."
fi
