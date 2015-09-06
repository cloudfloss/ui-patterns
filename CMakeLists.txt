cmake_minimum_required(VERSION 3.3)
project(moodwatch_time)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    resources/images/config-required.png
    resources/images/confirm.png
    resources/images/cross.png
    resources/images/pill.png
    resources/images/tick.png
    resources/images/tick_black.png
    resources/images/tick_white.png
    resources/images/warning.png
    screenshots/checkbox-list.png
    screenshots/config-window.png
    screenshots/dialog-choice.png
    screenshots/dialog-message.gif
    screenshots/list-message.png
    screenshots/menu.png
    screenshots/pin.png
    screenshots/progress-bar.gif
    screenshots/progresslayer.gif
    screenshots/radio-button.png
    screenshots/text-change-anim.gif
    src/layers/progress_layer.c
    src/layers/progress_layer.h
    src/layers/selection_layer.c
    src/layers/selection_layer.h
    src/windows/checkbox_window.c
    src/windows/checkbox_window.h
    src/windows/dialog_choice_window.c
    src/windows/dialog_choice_window.h
    src/windows/dialog_config_window.c
    src/windows/dialog_config_window.h
    src/windows/dialog_message_window.c
    src/windows/dialog_message_window.h
    src/windows/list_message_window.c
    src/windows/list_message_window.h
    src/windows/pin_window.c
    src/windows/pin_window.h
    src/windows/progress_bar_window.c
    src/windows/progress_bar_window.h
    src/windows/progress_layer_window.c
    src/windows/progress_layer_window.h
    src/windows/radio_button_window.c
    src/windows/radio_button_window.h
    src/windows/text_animation_window.c
    src/windows/text_animation_window.h
    src/main.c
    appinfo.json
    LICENSE
    README.md
    wscript src/windows/out_of_bed_window.c src/windows/out_of_bed_window.h src/windows/breakfast_window.c src/windows/breakfast_window.h src/windows/say_hello_window.c src/windows/say_hello_window.h)

add_executable(moodwatch_time ${SOURCE_FILES})