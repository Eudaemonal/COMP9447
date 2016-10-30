




https://github.com/google/angle/commit/5677e4d136883f681b491daa492366db29fa3a78

+    size_t mapSize = std::min(size, mBufferSize - offset);
+
     uint8_t *writePointer = nullptr;
-    ANGLE_TRY(map(offset, size, GL_MAP_WRITE_BIT, &writePointer));
+    ANGLE_TRY(map(offset, mapSize, GL_MAP_WRITE_BIT, &writePointer));
 
-    memcpy(writePointer, data, size);
+    memcpy(writePointer, data, mapSize);
 
https://github.com/google/angle/commit/c52f6f1a36826deba882ce7e064809c1a1941300
-                                             depth, border, format, type, -1, pixels);
+                                             depth, border, format, type, bufSize, pixels);


































