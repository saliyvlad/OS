while true; do
    ps -eo pid,lwp,nlwp,time,cmd --sort=pid
    sleep 5  # Задержка между выводами
done
