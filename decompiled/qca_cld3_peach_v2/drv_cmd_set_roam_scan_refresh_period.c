__int64 __fastcall drv_cmd_set_roam_scan_refresh_period(__int64 a1, __int64 a2, __int64 a3, unsigned __int8 a4)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  _BYTE v13[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13[0] = 0;
  if ( (kstrtou8(a3 + a4 + 1, 10, v13) & 0x80000000) != 0 )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: kstrtou8 failed Input value may be out of range[%d - %d]",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "drv_cmd_set_roam_scan_refresh_period",
      1,
      60);
  else
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Neighbor scan results refresh period value %d is out of range (Min: %d Max: %d)",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "drv_cmd_set_roam_scan_refresh_period",
      v13[0],
      1,
      60);
  _ReadStatusReg(SP_EL0);
  return 4294967274LL;
}
