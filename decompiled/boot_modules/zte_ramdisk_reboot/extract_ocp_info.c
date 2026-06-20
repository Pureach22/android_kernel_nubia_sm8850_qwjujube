__int64 __fastcall extract_ocp_info(_QWORD *a1, char *haystack, char *a3, size_t a4)
{
  char *v8; // x23
  char *v9; // x0
  const char *v10; // x24
  bool v11; // cf
  size_t v12; // x23
  size_t v13; // x0

  v8 = strstr(haystack, "OCP Occured: ");
  v9 = strstr(haystack, "Status: ");
  if ( haystack )
  {
    if ( v8 && v9 && (v10 = v8 + 13, v11 = v9 >= v8 + 13, v12 = v9 - (v8 + 13), v11) )
    {
      if ( v12 )
      {
        v13 = strlen(haystack);
        if ( v12 < a4 && v12 < v13 )
        {
          strncpy(a3, v10, v12);
          a3[v12] = 0;
          return 0;
        }
      }
      dev_err(*a1, "ztedbg invalid ocp extract with input: %s\n", haystack);
    }
    else
    {
      dev_err(*a1, "ztedbg invalid ocp input %s\n", haystack);
    }
  }
  else
  {
    dev_err(*a1, "ztedbg null input ocp line\n");
  }
  return 0xFFFFFFFFLL;
}
