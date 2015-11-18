#include <lua.h>
#include <luajit.h>
#include <lualib.h>
#include <lauxlib.h>

#include <stdlib.h>
#include <stdio.h>

#include "client.h"
#include "compat.h"
#include "bin2c_lanes_lua.h"
#include "lanes.h"
#include "lanes_test.h"

int load_lanes_lua(lua_State* L) {
	// printf("load_lanes_lua before\n");
	// if(luaL_dofile( L, "lanes.lua"))

	int ret = luaL_loadstring(L, bin2c_lanes_lua);
    if( !ret)
    {
        ret = lua_pcall(L, 0, 1, 0);
    }
    return ret ? 0 : 1;

	// if(luaL_dostring(L, bin2c_lanes_lua))
	// 	printf("lanes.lua do file:%s\n", lua_tostring(L, -1));;
	// printf("load_lanes_lua after\n");
}

int luaHello() {
	lua_State *L;

	/* Create new Lua state */
	L = luaL_newstate();

	/* Load Lua libraries */
	luaL_openlibs(L); 

	// Embedding Lanes by using custom loader
	luaopen_lanes_embedded(L, load_lanes_lua);
	// lua_pop(L, 1);

	luaL_loadstring(L, lanes_test);
	// luaL_loadstring(L, "local lanes = require 'lanes'.configure{with_timers = false}");
	if(lua_pcall(L, 0, 0, 0))
	// if(luaL_dostring( L, "print('hi'); local lanes = require 'lanes'.configure{with_timers = false}; local l = lanes.linda(); print('end')"))
		printf("lua pcall failed: %s\n", lua_tostring(L, -1));
	// luaL_dostring( L, "print('hi'); local lanes = require 'lanes'.configure{with_timers = false}; local l = lanes.linda(); print('end')");

	/* Close Lua state */
	lua_close(L);

	return 0;
}

int main() {
	luaHello();
	socketSend("socketSend message from client");
}