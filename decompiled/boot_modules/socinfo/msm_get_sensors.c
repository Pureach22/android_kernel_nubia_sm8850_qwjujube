__int64 __fastcall msm_get_sensors(__int64 a1, __int64 a2, __int64 a3)
{
  _DWORD *v4; // x0
  _BOOL4 v5; // w9
  unsigned int v6; // w10
  _DWORD *v7; // x20
  int v8; // w21
  int v9; // w19

  v4 = (_DWORD *)_kmalloc_cache_noprof(single_open, 3264, 4);
  if ( v4 )
  {
    v5 = 0;
    if ( socinfo )
    {
      v6 = 0;
      if ( (unsigned int)socinfo_format >= 0xE )
      {
        v6 = *(_DWORD *)(socinfo + 168);
        v5 = *(_DWORD *)(socinfo + 164) != 0;
      }
      if ( (unsigned int)socinfo_format < 0x15 )
        goto LABEL_9;
    }
    else
    {
      v6 = 0;
      if ( (unsigned int)socinfo_format < 0x15 )
        goto LABEL_9;
    }
    if ( !socinfo )
    {
LABEL_13:
      v7 = v4;
      v8 = scnprintf(a3, 4096, "0x%x", *v4);
      v9 = scnprintf(a3 + v8, 4096LL - v8, "\n") + v8;
      kfree(v7);
      return v9;
    }
    v6 = *(_DWORD *)(socinfo + 220);
LABEL_9:
    if ( !v6 )
      v5 = 0;
    if ( v5 )
      *v4 = *(_DWORD *)(socinfo + v6 + 36);
    goto LABEL_13;
  }
  return -12;
}
