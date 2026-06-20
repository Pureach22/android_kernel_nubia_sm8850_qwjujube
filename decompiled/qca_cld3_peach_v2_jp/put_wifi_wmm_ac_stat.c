__int64 __fastcall put_wifi_wmm_ac_stat(_DWORD *a1, __int64 a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 result; // x0
  int v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = a1[1];
  if ( (unsigned int)nla_put(a2, 18, 4, &v13) )
    goto LABEL_16;
  v13 = a1[2];
  if ( (unsigned int)nla_put(a2, 19, 4, &v13) )
    goto LABEL_16;
  v13 = a1[3];
  if ( (unsigned int)nla_put(a2, 20, 4, &v13) )
    goto LABEL_16;
  v13 = a1[4];
  if ( (unsigned int)nla_put(a2, 21, 4, &v13) )
    goto LABEL_16;
  v13 = a1[5];
  if ( (unsigned int)nla_put(a2, 22, 4, &v13) )
    goto LABEL_16;
  v13 = a1[6];
  if ( (unsigned int)nla_put(a2, 23, 4, &v13) )
    goto LABEL_16;
  v13 = a1[7];
  if ( (unsigned int)nla_put(a2, 24, 4, &v13) )
    goto LABEL_16;
  v13 = a1[8];
  if ( (unsigned int)nla_put(a2, 25, 4, &v13)
    || (v13 = a1[9], (unsigned int)nla_put(a2, 26, 4, &v13))
    || (v13 = a1[10], (unsigned int)nla_put(a2, 27, 4, &v13))
    || (v13 = a1[11], (unsigned int)nla_put(a2, 28, 4, &v13))
    || (v13 = a1[12], (unsigned int)nla_put(a2, 29, 4, &v13))
    || (v13 = a1[13], (unsigned int)nla_put(a2, 30, 4, &v13))
    || (v13 = a1[14], (unsigned int)nla_put(a2, 31, 4, &v13))
    || (v13 = a1[15], (unsigned int)nla_put(a2, 32, 4, &v13)) )
  {
LABEL_16:
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: QCA_WLAN_VENDOR_ATTR put fail",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "put_wifi_wmm_ac_stat");
    result = 0;
  }
  else
  {
    result = 1;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
