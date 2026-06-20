__int64 __fastcall drv_cmd_set_scan_home_away_time(__int64 a1, __int64 a2, __int64 a3, unsigned __int8 a4)
{
  unsigned int v6; // w0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int v15; // w21
  __int64 result; // x0
  unsigned __int16 v17; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 0;
  v6 = kstrtou16(a3 + a4 + 1, 10, &v17);
  if ( (v6 & 0x80000000) != 0 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: kstrtou8 failed range [%d - %d]",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "drv_cmd_set_scan_home_away_time",
      0,
      300);
LABEL_6:
    result = 4294967274LL;
    goto LABEL_7;
  }
  if ( v17 >= 0x12Du )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: home_away_time value %d is out of range (min: %d max: %d)",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "drv_cmd_set_scan_home_away_time");
    goto LABEL_6;
  }
  v15 = v6;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Received Command to Set scan away time = %d",
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    "drv_cmd_set_scan_home_away_time");
  sme_update_roam_scan_home_away_time(*(_QWORD *)(a2 + 16), *(unsigned __int8 *)(a1 + 8), v17, 1);
  result = v15;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
