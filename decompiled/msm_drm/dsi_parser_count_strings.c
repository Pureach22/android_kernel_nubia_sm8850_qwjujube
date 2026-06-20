__int64 __fastcall dsi_parser_count_strings(__int64 a1, char *s2)
{
  __int64 v2; // x22
  __int64 v4; // x21
  const char *v5; // x19
  int v6; // w8
  int v7; // w8
  const char *v9; // x4
  unsigned int v10; // w19

  v2 = *(unsigned int *)(a1 + 24);
  if ( (int)v2 < 1 )
    goto LABEL_10;
  v4 = *(_QWORD *)(a1 + 16);
  while ( 1 )
  {
    v5 = *(const char **)v4;
    if ( *(_QWORD *)v4 )
    {
      if ( !strcmp(*(const char **)v4, s2) )
        break;
    }
    --v2;
    v4 += 40;
    if ( !v2 )
      goto LABEL_10;
  }
  if ( v4 )
  {
    v6 = *(_DWORD *)(v4 + 32);
    if ( v6 )
    {
      if ( v6 == 1 )
        v7 = *(_DWORD *)(v4 + 36);
      else
        v7 = 0;
    }
    else
    {
      v7 = 1;
    }
    v9 = v5;
    v10 = v7;
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: prop %s has %d items\n", v9, v7);
    return v10;
  }
  else
  {
LABEL_10:
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s not found\n", s2);
    return 0;
  }
}
