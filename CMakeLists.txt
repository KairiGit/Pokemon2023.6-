# CMakeのバージョンを設定
cmake_minimum_required(VERSION 3.13)
# プロジェクト名と使用する言語を設定
project(Pokemon2023.6--2 CXX)
# a.outという実行ファイルをmain.cppとhello.cppから作成
add_executable(a.exe main.cpp BattleField.cpp Trainer.cpp Poke.cpp Move.cpp)
