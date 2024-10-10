# Project : Car ECU Software

## API Compilation

```
gcc -c drv_api.c -o drv_api.o
```

## Static Library Creation

```
ar rcs drv_api.a drv_api.o
```

## Main Project Compilation

```
gcc -o projet_hsi main.c drv_api.a
```

## Driver Startup

```
./driver &
```

## Main Application Execution

```
./projet_hsi
```
