__int64 __fastcall hif_display_ce_stats(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x24
  __int64 result; // x0
  __int64 v5; // x23
  unsigned __int8 v6; // w8
  int v7; // w26
  unsigned __int8 v8; // w27
  int v9; // w0
  bool v10; // vf
  _QWORD v11[17]; // [xsp+8h] [xbp-88h] BYREF

  v11[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v11, 0, 128);
  qdf_trace_msg(56, 8, "%s: CE interrupt statistics:", "hif_display_ce_stats");
  v2 = 0;
  v3 = a1 + 29160;
  do
  {
    v5 = 0;
    v6 = 0;
    v7 = 128;
    do
    {
      v8 = v6;
      if ( v6 >= 0x81u )
        __break(0x5512u);
      v9 = snprintf((char *)v11 + v6, v7, "[%d]:%d ", v5, *(_DWORD *)(v3 + 4 * v5));
      if ( v9 < 1 )
        break;
      v10 = __OFSUB__(v7, v9);
      v7 -= v9;
      if ( (v7 < 0) ^ v10 | (v7 == 0) )
        break;
      ++v5;
      v6 = v9 + v8;
    }
    while ( v5 != 32 );
    result = qdf_trace_msg(56, 8, "%s: CE id[%2d] - %s", "hif_display_ce_stats", v2++, (const char *)v11);
    v3 += 128;
  }
  while ( v2 != 12 );
  _ReadStatusReg(SP_EL0);
  return result;
}
