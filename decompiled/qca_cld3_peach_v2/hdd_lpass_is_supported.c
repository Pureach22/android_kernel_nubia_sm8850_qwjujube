__int64 __fastcall hdd_lpass_is_supported(__int64 *a1)
{
  __int64 v1; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  _BYTE v11[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *a1;
  v11[0] = 0;
  if ( (unsigned int)wlan_mlme_get_lpass_support(v1, v11) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to get LPASS support config",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "hdd_lpass_is_supported");
  _ReadStatusReg(SP_EL0);
  return v11[0];
}
