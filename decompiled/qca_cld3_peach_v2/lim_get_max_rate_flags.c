__int64 __fastcall lim_get_max_rate_flags(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10)
{
  __int64 v10; // x29
  __int64 v11; // x30
  unsigned int v12; // w8
  unsigned int v13; // w8
  __int64 v15; // x8
  unsigned int v16; // w8

  if ( !a10 )
  {
    qdf_trace_msg(0x35u, 2u, "%s: sta_ds is NULL", a1, a2, a3, a4, a5, a6, a7, a8, "lim_get_max_rate_flags", v10, v11);
    return 0;
  }
  if ( (*(_BYTE *)(a10 + 68) & 1) != 0 )
  {
    v12 = *(_DWORD *)(a10 + 360) - 1;
    if ( v12 >= 7 )
      v13 = 0x2000;
    else
      v13 = dword_AFC1B0[v12];
    goto LABEL_35;
  }
  if ( (*(_BYTE *)(a10 + 32) & 0x18) != 0 )
  {
    if ( (*(_BYTE *)(a10 + 38) & 1) != 0 )
      goto LABEL_8;
    if ( (*(_BYTE *)(a10 + 32) & 0x10) != 0 )
    {
      v16 = *(_DWORD *)(a10 + 360);
      if ( v16 < 2 )
      {
        if ( (*(_BYTE *)(a10 + 346) & 8) != 0 )
          v13 = 64;
        else
          v13 = 32;
        goto LABEL_35;
      }
      if ( v16 - 3 < 2 )
      {
        v13 = 4096;
        goto LABEL_35;
      }
      if ( v16 == 2 )
      {
        v13 = 128;
        goto LABEL_35;
      }
    }
    else if ( (*(_BYTE *)(a10 + 32) & 8) != 0 )
    {
      if ( (*(_BYTE *)(a10 + 346) & 8) != 0 )
        v13 = 4;
      else
        v13 = 2;
      goto LABEL_35;
    }
    v13 = 0;
  }
  else
  {
    if ( (*(_BYTE *)(a10 + 38) & 1) != 0 )
    {
LABEL_8:
      v15 = *(_QWORD *)(a10 + 865);
      if ( (v15 & 0x30000000000000LL) != 0 )
      {
        v13 = 2048;
      }
      else if ( (v15 & 0x8000000000000LL) != 0 )
      {
        if ( *(_DWORD *)(a10 + 360) == 2 )
          v13 = 1024;
        else
          v13 = 512;
      }
      else if ( (v15 & 0x4000000000000LL) != 0 )
      {
        v13 = 512;
      }
      else
      {
        v13 = 256;
      }
      goto LABEL_35;
    }
    v13 = 1;
  }
LABEL_35:
  if ( (*(_BYTE *)(a10 + 344) & 6) != 0 )
    return v13 | 8;
  else
    return v13;
}
