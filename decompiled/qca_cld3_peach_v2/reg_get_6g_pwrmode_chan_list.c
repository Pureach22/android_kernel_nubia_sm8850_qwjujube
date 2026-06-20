__int64 __fastcall reg_get_6g_pwrmode_chan_list(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v12; // x20
  _WORD *v13; // x26
  __int64 v14; // x27
  unsigned int v15; // w8
  int v16; // w9
  int v17; // w10
  _DWORD *v18; // x11
  __int16 v19; // w12
  __int16 v20; // w8
  int v21; // w9
  __int16 v22; // w8
  _DWORD dest[67]; // [xsp+4h] [xbp-11Ch] BYREF
  __int64 v25; // [xsp+110h] [xbp-10h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)(a1 + 11016) == 1 )
  {
    v12 = a1 + 36940;
    v13 = (_WORD *)(a2 + 1540);
    v14 = -16080;
    do
    {
      memcpy(dest, (const void *)(v12 + v14 + 16080), sizeof(dest));
      v15 = dest[1];
      if ( a3 != -1 )
        v15 = a3;
      if ( v15 - 13 >= 0xFFFFFFF4 )
      {
        v16 = dest[v15 + 54];
        v17 = dest[v15 + 15];
        v18 = &dest[2 * v15 + 28];
        v19 = *((_WORD *)&dest[2] + v15);
        v20 = *((_WORD *)&dest[8] + v15 + 1);
        *((_DWORD *)v13 - 5) = v16;
        *((_DWORD *)v13 - 4) = v17;
        v21 = v18[1];
        *(v13 - 3) = v20;
        v22 = *((_WORD *)v18 + 1);
        *((_DWORD *)v13 - 3) = v21;
        LOBYTE(v21) = *(_BYTE *)v18;
        *(v13 - 4) = v19;
        *((_BYTE *)v13 - 1) = v21;
        *v13 = v22;
      }
      v14 += 268;
      v13 += 18;
    }
    while ( v14 );
  }
  else
  {
    qdf_trace_msg(
      0x51u,
      8u,
      "%s: 6G channel list is empty",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "reg_get_6g_pwrmode_chan_list");
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
