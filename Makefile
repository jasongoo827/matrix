NAME := matrix

all: $(NAME)_debug

debug: $(NAME)_debug
release: $(NAME)_release

$(NAME)_debug:
	@cmake -Bbuild .
	@cmake --build build --config Debug	
	@if exist ".\build\bin\Debug\$(NAME).exe" ( \
		cmd /c move ".\build\bin\Debug\$(NAME).exe" ".\$(NAME)_debug.exe" \
	) else ( \
		echo [ERROR] .\build\bin\Debug\$(NAME).exe not found! & exit 1 \
	)

$(NAME)_release:
	@cmake -Bbuild .
	@cmake --build build --config Release
	@if exist ".\build\bin\Release\$(NAME).exe" ( \
		cmd /c move ".\build\bin\Release\$(NAME).exe" ".\$(NAME)_release.exe" \
	) else ( \
		echo [ERROR] .\build\bin\Release\$(NAME).exe not found! & exit 1 \
	)

clean:
	@if exist build rmdir /s /q build

fclean: clean
	@if exist $(NAME)_debug.exe del $(NAME)_debug.exe
	@if exist $(NAME)_release.exe del $(NAME)_release.exe

.PHONY: all build clean
