__int64 __fastcall hdd_populate_wifi_signal_info(__int64 result, __int64 a2)
{
  unsigned int v2; // w20
  __int64 v4; // x21
  __int64 v5; // x22
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  const char *v14; // x2
  __int64 v15; // x23
  __int64 v16; // x24
  _WORD *v17; // x23
  __int64 v18; // x24
  unsigned int *v19; // x25
  __int64 v20; // x26
  __int64 v21; // x27
  _WORD *v22; // x26
  unsigned int v23; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v24; // [xsp+8h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
  {
    v2 = *(_DWORD *)(result + 136);
    v4 = result;
    if ( v2 >= 8 )
      v5 = 8;
    else
      v5 = v2;
    v23 = v5;
    if ( (unsigned int)nla_put(a2, 63, 4, &v23) )
    {
LABEL_6:
      v14 = "%s: QCA_WLAN_VENDOR_ATTR put fail";
LABEL_20:
      qdf_trace_msg(0x33u, 2u, v14, v6, v7, v8, v9, v10, v11, v12, v13, "hdd_populate_wifi_signal_info");
      result = 4294967274LL;
      goto LABEL_21;
    }
    v15 = *(_QWORD *)(a2 + 216);
    v16 = *(unsigned int *)(a2 + 208);
    if ( (nla_put(a2, 32832, 0, 0) & 0x80000000) != 0 || (v17 = (_WORD *)(v15 + v16)) == nullptr )
    {
LABEL_19:
      v14 = "%s: nla_nest_start failed";
      goto LABEL_20;
    }
    if ( v2 )
    {
      v18 = 0;
      v19 = (unsigned int *)(v4 + 72);
      do
      {
        v20 = *(_QWORD *)(a2 + 216);
        v21 = *(unsigned int *)(a2 + 208);
        if ( (nla_put(a2, (unsigned int)v18 | 0x8000, 0, 0) & 0x80000000) != 0 )
          goto LABEL_19;
        v22 = (_WORD *)(v20 + v21);
        if ( !v22 )
          goto LABEL_19;
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: SNR=%d, NF=%d, Rx=%d, Tx=%d",
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          "hdd_populate_wifi_signal_info",
          *(v19 - 16),
          *(v19 - 8),
          *v19,
          v19[8]);
        v23 = *(v19 - 16);
        if ( (unsigned int)nla_put(a2, 65, 4, &v23) )
          goto LABEL_6;
        v23 = *(v19 - 8);
        if ( (unsigned int)nla_put(a2, 66, 4, &v23) )
          goto LABEL_6;
        v23 = *v19;
        if ( (unsigned int)nla_put(a2, 38, 4, &v23) )
          goto LABEL_6;
        v23 = v19[8];
        if ( (unsigned int)nla_put(a2, 22, 4, &v23) )
          goto LABEL_6;
        ++v18;
        ++v19;
        *v22 = *(_WORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v22;
      }
      while ( v5 != v18 );
    }
    result = 0;
    *v17 = *(_WORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v17;
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
