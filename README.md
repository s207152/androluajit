# androluajit
Write Android apps with luaJIT

It is highly experimental !!!

###Basic Idea
LuaJIT and Java communicate with each other with socket/json-rpc/named pipe (will try all three depends on speed and stability), so that scripts can be executed in root environment and take advantage of multithreading.  Java side is used to expose native api for UI interface.
