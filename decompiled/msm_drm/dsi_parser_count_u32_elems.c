__int64 __fastcall dsi_parser_count_u32_elems(__int64 a1, char *s2)
{
  __int64 v2; // x21
  __int64 v4; // x22
  const char *v5; // x20
  unsigned int v6; // w19

  v2 = *(unsigned int *)(a1 + 24);
  if ( (int)v2 < 1 )
    goto LABEL_8;
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
      goto LABEL_8;
  }
  if ( v4 )
  {
    v6 = *(_DWORD *)(v4 + 36);
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: prop %s has %d items\n", v5, v6);
    return v6;
  }
  else
  {
LABEL_8:
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s not found\n", s2);
    return 0;
  }
}
