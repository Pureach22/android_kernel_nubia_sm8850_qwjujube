__int64 __fastcall extract_sn_info(_QWORD *a1, char *haystack, char *a3, size_t a4)
{
  char *v8; // x0
  char *v9; // x22
  size_t v10; // x0
  unsigned __int64 v11; // x8
  size_t v12; // x24
  __int64 result; // x0

  v8 = strstr(haystack, " = ");
  if ( !haystack )
  {
    dev_err(*a1, "ztedbg null input sn line\n");
    return 0xFFFFFFFFLL;
  }
  v9 = v8;
  v10 = strlen(haystack);
  if ( !v9 || (v11 = v9 - haystack + 3, v12 = v10 - v11, v10 < v11) )
  {
    dev_err(*a1, "ztedbg invalid sn input %s\n", haystack);
    return 0xFFFFFFFFLL;
  }
  if ( v12 >= a4 || v10 == v11 || v12 >= v10 )
  {
    dev_err(*a1, "ztedbg invalid sn extract with input: %s\n", haystack);
    return 0xFFFFFFFFLL;
  }
  strncpy(a3, v9 + 3, v12);
  result = 0;
  a3[v12] = 0;
  return result;
}
