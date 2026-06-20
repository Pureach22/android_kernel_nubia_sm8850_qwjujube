__int64 __fastcall hdd_avoid_acs_channels(__int64 *a1, __int64 a2)
{
  __int64 v3; // x0
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x8
  unsigned __int64 v14; // x24
  int v15; // w23
  __int64 v16; // x25
  _BYTE v17[4]; // [xsp+Ch] [xbp-D4h] BYREF
  _QWORD v18[26]; // [xsp+10h] [xbp-D0h] BYREF

  v18[25] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a1;
  memset(v18, 0, 200);
  v17[0] = 0;
  result = ucfg_mlme_get_acs_avoid_freq_list(v3, v18, v17);
  if ( *(_BYTE *)(a2 + 1160) )
  {
    v13 = v17[0];
    v14 = 0;
    v15 = 0;
    do
    {
      if ( !v13 )
        goto LABEL_13;
      v16 = 0;
      while ( 1 )
      {
        if ( v16 == 100 )
          __break(0x5512u);
        if ( *(_DWORD *)(*(_QWORD *)(a2 + 1152) + 4 * v14) == *((unsigned __int16 *)v18 + v16) )
          break;
        if ( v13 == ++v16 )
        {
          v13 = (unsigned __int8)v13;
          goto LABEL_13;
        }
      }
      result = qdf_trace_msg(0x33u, 8u, "%s: skip freq %d", v5, v6, v7, v8, v9, v10, v11, v12, "hdd_avoid_acs_channels");
      v13 = v17[0];
      if ( (_DWORD)v16 == v17[0] )
LABEL_13:
        *(_DWORD *)(*(_QWORD *)(a2 + 1152) + 4LL * v15++) = *(_DWORD *)(*(_QWORD *)(a2 + 1152) + 4 * v14);
      ++v14;
    }
    while ( v14 < *(unsigned __int8 *)(a2 + 1160) );
  }
  else
  {
    LOBYTE(v15) = 0;
  }
  *(_BYTE *)(a2 + 1160) = v15;
  _ReadStatusReg(SP_EL0);
  return result;
}
