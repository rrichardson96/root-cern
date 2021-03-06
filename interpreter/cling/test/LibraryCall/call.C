// RUN: clang -shared %S/call_lib.c -o%p/libcall_lib%shlibext && ls %p/libcall_lib%shlibext && cat %s | %cling -L%p | FileCheck %s

.L libcall_lib
extern "C" int cling_testlibrary_function();
int i = cling_testlibrary_function();
extern "C" int printf(const char* fmt, ...);
printf("got i=%d\n", i); // CHECK: got i=66
.q
