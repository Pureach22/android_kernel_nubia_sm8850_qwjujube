__int64 __fastcall dsi_parser_find_property(__int64 a1, char *s2, int *a3)
{
  __int64 v3; // x20
  __int64 v6; // x22
  int v7; // w8
  int v8; // w5

  v3 = 0;
  if ( a1 && s2 && a3 )
  {
    v6 = *(unsigned int *)(a1 + 24);
    if ( (int)v6 < 1 )
      goto LABEL_12;
    v3 = *(_QWORD *)(a1 + 16);
    while ( !*(_QWORD *)v3 || strcmp(*(const char **)v3, s2) )
    {
      --v6;
      v3 += 40;
      if ( !v6 )
        goto LABEL_12;
    }
    if ( v3 )
    {
      v7 = *(_DWORD *)(v3 + 32);
      if ( (unsigned int)(v7 - 2) >= 2 )
      {
        if ( v7 == 4 )
          v8 = *(_DWORD *)(v3 + 36);
        else
          v8 = strlen(*(const char **)(v3 + 8)) + 1;
      }
      else
      {
        v8 = 4 * *(_DWORD *)(v3 + 36);
      }
      *a3 = v8;
      _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s len=%d\n", s2, v8);
    }
    else
    {
LABEL_12:
      _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s not found\n", s2);
      return 0;
    }
  }
  return v3;
}
