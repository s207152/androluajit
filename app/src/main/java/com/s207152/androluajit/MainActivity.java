package com.s207152.androluajit;

import android.app.Activity;
import android.os.Bundle;
import java.io.IOException;
import android.util.Log;

public class MainActivity extends Activity
{
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        new Thread() {
        	@Override
        	public void run() {
        		try {
        			new LuajitServer().start();
        		} catch (IOException ex) {
        			Log.i("LuajitServer", "IOException" + ex.toString());
        			ex.printStackTrace();
        		}
        	}
        }.start();
    }
}
