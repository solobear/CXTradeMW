package com.cxtrade.mw.client.utils;

import android.util.Log;

/**
 * The Class LogUtils for log printing, which help us
 * easy to trace our codes or logics in the project .
 */
public class LogUtils {

    private final static int VERBOSE = 0;
    private final static int DEBUG = 1;
    private final static int INFO = 2;
    private final static int WARN = 3;
    private final static int ERROR = 4;
    private final static int DEFAULT_LEVEL = -1;

    private int level;

    private final String clazz;

    private static final String TAG = "LogUtils";

    public static LogUtils getDebugLog(Class<?> clazz, int l) {
        LogUtils log = new LogUtils(clazz);
        log.level = l;
        return log;
    }

    public static LogUtils getLog(Class<?> clazz) {
        return new LogUtils(clazz);
    }

    public LogUtils(Class<?> clazz) {
        this.clazz = "[" + clazz.getSimpleName() + "] ";
        level = DEFAULT_LEVEL;
    }

    public void verbose(String message) {
        verbose(message, null);
    }

    public void debug(String message) {
        debug(message, null);
    }

    public void info(String message) {
        info(message, null);
    }

    public void warn(String message) {
        warn(message, null);
    }

    public void error(String message) {
        error(message, null);
    }

    public void verbose(String message, Throwable t) {
        if (VERBOSE < level)
            return;
        if (message != null)
            Log.v(TAG, clazz + " : " + message);
        if (t != null)
            Log.v(TAG, clazz + " : " + t.toString());
    }

    public void debug(String message, Throwable t) {
        if (DEBUG < level)
            return;
        if (message != null)
            Log.d(clazz, clazz + " : " + message);
        if (t != null)
            Log.d(clazz, clazz + " : " + t.toString());
    }

    public void info(String message, Throwable t) {
        if (INFO < level)
            return;
        if (message != null)
            Log.i(TAG, clazz + " : " + message);
        if (t != null)
            Log.i(TAG, clazz + " : " + t.toString());
    }

    public void warn(String message, Throwable t) {
        if (WARN < level)
            return;
        if (message != null)
            Log.w(TAG, clazz + " : " + message);
        if (t != null)
            Log.w(TAG, clazz + " : " + t.toString());
    }

    public void error(String message, Throwable t) {
        if (ERROR < level)
            return;
        if (message != null)
            Log.e(TAG, clazz + " : " + message);
        if (t != null)
            Log.e(TAG, clazz + " : " + t.toString());
    }
}