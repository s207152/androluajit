package com.s207152.androluajit;

import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.net.*;

import android.util.Log;
import android.net.LocalServerSocket;
import android.net.LocalSocket;
import android.net.LocalSocketAddress;

public class LuajitServer {
	private static final String SERVER_NAME = "LuajitServer";

	private static boolean isStart = false;
	private LocalServerSocket server;

	public LuajitServer() throws IOException {
		server = createServer();
	}

	private LocalServerSocket createServer() throws IOException {
		return new LocalServerSocket(SERVER_NAME);
	}

	public void start() throws IOException {
		isStart = true;

		while(isStart){
			LocalSocket client=server.accept();
			BufferedReader in=new BufferedReader(new InputStreamReader(client.getInputStream()));
			String str=in.readLine();
			Log.i("LuajitServer", str);
			client.close();
		}
	}

	public void stop() {
		isStart = false;
	}

	private void handleClientInput(String input) {
		
	}
}