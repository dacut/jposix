grep -E 'public static final int ([A-Z0-9_]+);' src/java/jposix/Posix.java | \
  sed -e 's/public static final int \([A-Z0-9_]*\);/private static native int _get_\1();/'
