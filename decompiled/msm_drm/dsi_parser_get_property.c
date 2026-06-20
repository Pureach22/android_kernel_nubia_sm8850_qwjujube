const char *__fastcall dsi_parser_get_property(__int64 a1, char *s2, int *a3)
{
  __int64 v3; // x21
  __int64 v5; // x22
  const char *result; // x0
  const char *v8; // x21
  int v9; // w8
  __int64 v10; // x21
  int v11; // w5

  v3 = *(unsigned int *)(a1 + 24);
  if ( (int)v3 < 1 )
    goto LABEL_12;
  v5 = *(_QWORD *)(a1 + 16);
  while ( !*(_QWORD *)v5 || strcmp(*(const char **)v5, s2) )
  {
    --v3;
    v5 += 40;
    if ( !v3 )
      goto LABEL_12;
  }
  if ( v5 )
  {
    result = *(const char **)(v5 + 16);
    if ( !*(_DWORD *)(v5 + 32) )
    {
      v8 = *(const char **)(v5 + 16);
      _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s=%s\n", s2, v8);
      result = v8;
    }
    if ( a3 )
    {
      v9 = *(_DWORD *)(v5 + 32);
      v10 = (__int64)result;
      if ( (unsigned int)(v9 - 2) >= 2 )
      {
        if ( v9 == 4 )
          v11 = *(_DWORD *)(v5 + 36);
        else
          v11 = strlen(*(const char **)(v5 + 8)) + 1;
      }
      else
      {
        v11 = 4 * *(_DWORD *)(v5 + 36);
      }
      *a3 = v11;
      _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s len=%d\n", s2, v11);
      return (const char *)v10;
    }
  }
  else
  {
LABEL_12:
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s not found\n", s2);
    return nullptr;
  }
  return result;
}
