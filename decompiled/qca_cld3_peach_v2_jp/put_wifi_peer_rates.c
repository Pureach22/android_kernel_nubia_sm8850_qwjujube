__int64 __fastcall put_wifi_peer_rates(__int64 a1, __int64 a2)
{
  __int64 v4; // x21
  __int64 v5; // x22
  int v6; // w8
  __int64 result; // x0
  _WORD *v8; // x21
  unsigned __int64 v9; // x22
  _DWORD *v10; // x23
  __int64 v11; // x24
  __int64 v12; // x25
  int v13; // w8
  _WORD *v14; // x24
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  int v31; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v32; // [xsp+8h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_DWORD *)(a1 + 16) )
    goto LABEL_21;
  v4 = *(_QWORD *)(a2 + 216);
  v5 = *(unsigned int *)(a2 + 208);
  v6 = nla_put(a2, 32837, 0, 0);
  result = 0;
  if ( v6 < 0 )
    goto LABEL_23;
  v8 = (_WORD *)(v4 + v5);
  if ( !v8 )
    goto LABEL_23;
  if ( !*(_DWORD *)(a1 + 16) )
  {
LABEL_20:
    *v8 = *(_WORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v8;
LABEL_21:
    result = 1;
    goto LABEL_23;
  }
  v9 = 0;
  v10 = (_DWORD *)(a1 + 24);
  while ( 1 )
  {
    v11 = *(_QWORD *)(a2 + 216);
    v12 = *(unsigned int *)(a2 + 208);
    v13 = nla_put(a2, (unsigned int)v9 | 0x8000, 0, 0);
    result = 0;
    if ( v13 < 0 )
      break;
    v14 = (_WORD *)(v11 + v12);
    if ( !v14 )
      break;
    LOBYTE(v31) = *(_BYTE *)(v10 - 1) & 7;
    if ( (unsigned int)nla_put(a2, 38, 1, &v31) )
      goto LABEL_22;
    LOBYTE(v31) = (*((_BYTE *)v10 - 4) >> 3) & 3;
    if ( (unsigned int)nla_put(a2, 39, 1, &v31) )
      goto LABEL_22;
    LOBYTE(v31) = *((_BYTE *)v10 - 4) >> 5;
    if ( (unsigned int)nla_put(a2, 40, 1, &v31) )
      goto LABEL_22;
    LOBYTE(v31) = BYTE1(*(v10 - 1));
    if ( (unsigned int)nla_put(a2, 41, 1, &v31)
      || (v31 = *v10, (unsigned int)nla_put(a2, 42, 4, &v31))
      || (v31 = v10[1], (unsigned int)nla_put(a2, 43, 4, &v31))
      || (v31 = v10[2], (unsigned int)nla_put(a2, 44, 4, &v31))
      || (v31 = v10[3], (unsigned int)nla_put(a2, 45, 4, &v31))
      || (v31 = v10[4], (unsigned int)nla_put(a2, 46, 4, &v31))
      || (v31 = v10[5], (unsigned int)nla_put(a2, 47, 4, &v31))
      || (v31 = v10[6], (unsigned int)nla_put(a2, 48, 4, &v31)) )
    {
LABEL_22:
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: QCA_WLAN_VENDOR_ATTR put fail",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "put_wifi_rate_stat");
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: QCA_WLAN_VENDOR_ATTR put fail",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "put_wifi_peer_rates");
      result = 0;
      break;
    }
    ++v9;
    v10 += 8;
    *v14 = *(_DWORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v14;
    if ( v9 >= *(unsigned int *)(a1 + 16) )
      goto LABEL_20;
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
