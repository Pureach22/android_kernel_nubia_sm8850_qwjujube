__int64 __fastcall dsi_pwr_panel_regulator_mode_set(__int64 *a1, char *s2, unsigned int a3)
{
  unsigned int v3; // w23
  __int64 v4; // x25
  unsigned int v8; // w22
  __int64 v9; // x24
  __int64 result; // x0
  unsigned int v11; // w21

  v3 = *((_DWORD *)a1 + 2);
  if ( !v3 )
    return 4294967274LL;
  v4 = *a1;
  if ( !*a1 )
    return 4294967274LL;
  v8 = 0;
  while ( 1 )
  {
    v9 = v4 + 80LL * (int)v8;
    if ( !strcmp((const char *)(v9 + 8), s2) )
      break;
    if ( v3 == ++v8 )
    {
      result = 0;
      v8 = v3;
      goto LABEL_9;
    }
  }
  result = regulator_set_mode(*(_QWORD *)v9, a3);
  if ( (_DWORD)result )
  {
    v11 = result;
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: Regulator %s set mode %d failed\n",
      (const char *)(v9 + 8),
      result);
    result = v11;
  }
LABEL_9:
  if ( v8 >= *((_DWORD *)a1 + 2) )
  {
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: Regulator %s was not found\n", s2);
    return 4294967274LL;
  }
  return result;
}
