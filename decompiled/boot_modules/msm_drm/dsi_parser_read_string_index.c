__int64 __fastcall dsi_parser_read_string_index(__int64 a1, char *s2, int a3, _QWORD *a4)
{
  __int64 v4; // x23
  __int64 v6; // x22

  v4 = *(unsigned int *)(a1 + 24);
  if ( (int)v4 < 1 )
    goto LABEL_10;
  v6 = *(_QWORD *)(a1 + 16);
  while ( !*(_QWORD *)v6 || strcmp(*(const char **)v6, s2) )
  {
    --v4;
    v6 += 40;
    if ( !v4 )
      goto LABEL_10;
  }
  if ( v6 )
  {
    if ( *(_DWORD *)(v6 + 32) == 1 )
    {
      if ( *(_DWORD *)(v6 + 36) > a3 )
      {
        *a4 = *(_QWORD *)(*(_QWORD *)(v6 + 24) + 8LL * a3);
        return 0;
      }
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: out of bond index %d\n", a3);
    }
    else
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: not a string array property\n");
    }
  }
  else
  {
LABEL_10:
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s not found\n", s2);
  }
  return 4294967274LL;
}
