__int64 __fastcall hdd_populate_wifi_channel_cca_info(__int64 result, __int64 a2)
{
  int *v3; // x20
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
  {
    v3 = (int *)result;
    v12 = *(_DWORD *)(result + 4);
    if ( (unsigned int)nla_put(a2, 54, 4, &v12) )
      goto LABEL_11;
    v12 = v3[2];
    if ( (unsigned int)nla_put(a2, 55, 4, &v12) )
      goto LABEL_11;
    v12 = v3[3];
    if ( (unsigned int)nla_put(a2, 61, 4, &v12)
      || (v12 = v3[4], (unsigned int)nla_put(a2, 62, 4, &v12))
      || (v12 = v3[5], (unsigned int)nla_put(a2, 57, 4, &v12))
      || (v12 = v3[6], (unsigned int)nla_put(a2, 58, 4, &v12))
      || (v12 = v3[7], (unsigned int)nla_put(a2, 59, 4, &v12))
      || (v12 = v3[8], (unsigned int)nla_put(a2, 60, 4, &v12))
      || (v12 = *v3, result = nla_put(a2, 11, 4, &v12), (_DWORD)result) )
    {
LABEL_11:
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
        "hdd_populate_wifi_channel_cca_info");
      result = 4294967274LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
