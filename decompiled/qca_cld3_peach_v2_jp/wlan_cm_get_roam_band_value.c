__int64 __fastcall wlan_cm_get_roam_band_value(int a1, __int64 a2)
{
  int v2; // w1
  unsigned int v3; // w19
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  _QWORD v13[5]; // [xsp+8h] [xbp-28h] BYREF

  v13[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned __int8 *)(a2 + 104);
  memset(v13, 0, 32);
  wlan_cm_roam_cfg_get_value(a1, v2, 27, (int)v13);
  v3 = v13[0];
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: [ROAM BAND] band mask:%d",
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    "wlan_cm_get_roam_band_value",
    LODWORD(v13[0]));
  _ReadStatusReg(SP_EL0);
  return v3;
}
