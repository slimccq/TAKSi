// This file is auto-generated by taxi v1.4.0, DO NOT EDIT!

package com.mycompany.csvconfig;

public class AutogenConfigManager {
    final public static String TAB_CSV_SEP = ",";     // CSV field separator
    final public static String TAB_CSV_QUOTE = "\"";   // CSV field quote
    
    final public static String TAB_ARRAY_DELIM = ",";      // array item delimiter
    final public static String TAB_MAP_DELIM1 = ";";       // map item delimiter
    final public static String TAB_MAP_DELIM2 = "=";       // map key-value delimiter
    
    // `Boolean.parseBoolean()` only detects "true"
    public static boolean parseBool(String text) {
        if (text.isEmpty()) {
            return false;
        }        
        return text.equals("1") ||
                text.equalsIgnoreCase("y") ||
                text.equalsIgnoreCase("on") ||
                text.equalsIgnoreCase("yes")  ||
                text.equalsIgnoreCase("true");
    }
}
