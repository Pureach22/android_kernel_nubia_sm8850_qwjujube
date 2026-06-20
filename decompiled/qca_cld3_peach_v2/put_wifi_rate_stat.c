__int64 __fastcall put_wifi_rate_stat(__int64 a1, __int64 a2, const char *a3)
{
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 result; // x0
  int v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LOBYTE(v14) = *(_BYTE *)a1 & 7;
  if ( (unsigned int)nla_put(a2, 38, 1, &v14) )
    goto LABEL_12;
  LOBYTE(v14) = (*(_BYTE *)a1 >> 3) & 3;
  if ( (unsigned int)nla_put(a2, 39, 1, &v14) )
    goto LABEL_12;
  LOBYTE(v14) = *(_BYTE *)a1 >> 5;
  if ( (unsigned int)nla_put(a2, 40, 1, &v14) )
    goto LABEL_12;
  LOBYTE(v14) = BYTE1(*(_DWORD *)a1);
  if ( (unsigned int)nla_put(a2, 41, 1, &v14)
    || (v14 = *(_DWORD *)(a1 + 4), (unsigned int)nla_put(a2, 42, 4, &v14))
    || (v14 = *(_DWORD *)(a1 + 8), (unsigned int)nla_put(a2, 43, 4, &v14))
    || (v14 = *(_DWORD *)(a1 + 12), (unsigned int)nla_put(a2, 44, 4, &v14))
    || (v14 = *(_DWORD *)(a1 + 16), (unsigned int)nla_put(a2, 45, 4, &v14))
    || (v14 = *(_DWORD *)(a1 + 20), (unsigned int)nla_put(a2, 46, 4, &v14))
    || (v14 = *(_DWORD *)(a1 + 24), (unsigned int)nla_put(a2, 47, 4, &v14))
    || (v14 = *(_DWORD *)(a1 + 28), (unsigned int)nla_put(a2, 48, 4, &v14)) )
  {
LABEL_12:
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: QCA_WLAN_VENDOR_ATTR put fail",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "put_wifi_rate_stat");
    result = 0;
  }
  else
  {
    result = 1;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
