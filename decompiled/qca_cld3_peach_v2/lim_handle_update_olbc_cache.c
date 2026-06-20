__int64 __fastcall lim_handle_update_olbc_cache(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v9; // w8
  unsigned __int8 v10; // w9
  _BYTE *v11; // x21
  __int64 v12; // x19
  const char *v13; // x2
  unsigned int v14; // w1
  __int64 result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  char v25; // w8
  char v26; // w23
  __int64 v27; // [xsp+8h] [xbp-28h] BYREF
  __int64 v28; // [xsp+10h] [xbp-20h]
  __int64 v29; // [xsp+18h] [xbp-18h]
  int v30; // [xsp+20h] [xbp-10h]
  __int64 v31; // [xsp+28h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(unsigned __int16 *)(a1 + 3992);
  v30 = 0;
  v28 = 0;
  v29 = 0;
  v27 = 0;
  if ( !v9 )
    goto LABEL_9;
  v10 = 0;
  v11 = (_BYTE *)(a1 + 11440);
  while ( 1 )
  {
    v12 = *(_QWORD *)(a1 + 12264) + 14000LL * v10;
    if ( *(_BYTE *)(v12 + 70) )
    {
      if ( *(_DWORD *)(v12 + 88) == 1 )
        break;
    }
    if ( v9 <= ++v10 )
      goto LABEL_9;
  }
  if ( !v12 )
  {
LABEL_9:
    v13 = "%s:  Session not found";
    goto LABEL_10;
  }
  if ( *(_BYTE *)(v12 + 10006) == 1 )
  {
    v13 = "%s: protection offloaded";
LABEL_10:
    v14 = 8;
LABEL_11:
    result = qdf_trace_msg(0x35u, v14, v13, a2, a3, a4, a5, a6, a7, a8, a9, "lim_handle_update_olbc_cache");
    goto LABEL_12;
  }
  qdf_mem_set(&v27, 0x1Cu, 0);
  v25 = *(_BYTE *)(v12 + 10);
  HIWORD(v28) = 0;
  v26 = lim_handle_update_olbc_cache_enable;
  LOBYTE(v27) = v25;
  if ( (lim_handle_update_olbc_cache_enable & 1) != 0 )
  {
    if ( !*(_BYTE *)(v12 + 1224) && *(_BYTE *)(v12 + 1225) && !*(_BYTE *)(v12 + 437) )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Overlap cache clear and no 11B STA set",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "lim_handle_update_olbc_cache");
      lim_enable11g_protection(a1, 0, 1, &v27, v12);
    }
    if ( !*(_BYTE *)(v12 + 1226) && *(_BYTE *)(v12 + 1227) && !*(_BYTE *)(v12 + 441) )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Overlap cache clear and no 11G STA set",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "lim_handle_update_olbc_cache");
      lim_enable_ht_protection_from11g(a1, 0, 1, &v27, v12);
    }
    if ( !*(_BYTE *)(v12 + 1230) && *(_BYTE *)(v12 + 1231) && !*(_BYTE *)(v12 + 445) )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Overlap cache clear and no HT20 STA set",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "lim_handle_update_olbc_cache");
      lim_enable11g_protection(a1, 0, 1, &v27, v12);
    }
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Resetting OLBC cache",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "lim_handle_update_olbc_cache");
    *(_BYTE *)(v12 + 1224) = 0;
    *(_BYTE *)(v12 + 1226) = 0;
    *(_BYTE *)(v12 + 1230) = 0;
    *(_BYTE *)(v12 + 442) = 0;
    *(_BYTE *)(v12 + 446) = 0;
    *v11 = 0;
    v11[12] = 0;
    v11[24] = 0;
    v11[36] = 0;
    v11[48] = 0;
    v11[60] = 0;
    v11[72] = 0;
    v11[84] = 0;
    v11[96] = 0;
    v11[108] = 0;
    v11[120] = 0;
    v11[132] = 0;
    v11[144] = 0;
    v11[156] = 0;
    v11[168] = 0;
    v11[180] = 0;
    v11[192] = 0;
    v11[204] = 0;
    v11[216] = 0;
    v11[228] = 0;
    v11[240] = 0;
    v11[252] = 0;
    v11[264] = 0;
    v11[276] = 0;
    v11[288] = 0;
    v11[300] = 0;
    v11[312] = 0;
    v11[324] = 0;
    v11[336] = 0;
    v11[348] = 0;
    v11[360] = 0;
    v11[372] = 0;
  }
  lim_handle_update_olbc_cache_enable = v26 ^ 1;
  if ( !v11[3441] && HIWORD(v28) )
  {
    sch_set_fixed_beacon_fields(a1, v12);
    lim_send_beacon_params(a1, (unsigned __int16 *)&v27, v12);
  }
  result = tx_timer_activate((char *)(a1 + 1608));
  if ( (_DWORD)result )
  {
    v13 = "%s: tx_timer_activate failed";
    v14 = 2;
    goto LABEL_11;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
