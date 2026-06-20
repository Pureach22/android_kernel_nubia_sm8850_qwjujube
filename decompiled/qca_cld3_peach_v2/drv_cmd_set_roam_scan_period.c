__int64 __fastcall drv_cmd_set_roam_scan_period(__int64 a1, __int64 *a2, __int64 a3, unsigned __int8 a4)
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
  unsigned int v15; // w22
  unsigned int v16; // w21
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 result; // x0
  _BYTE v26[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v27; // [xsp+8h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26[0] = 0;
  v6 = kstrtou8(a3 + a4 + 1, 10, v26);
  if ( (v6 & 0x80000000) != 0 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: kstrtou8 failed Input value may be out of range[%d - %d]",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "drv_cmd_set_roam_scan_period",
      0,
      60);
    goto LABEL_5;
  }
  v15 = v6;
  if ( !ucfg_mlme_validate_scan_period(v7, v8, v9, v10, v11, v12, v13, v14, *a2, 1000 * v26[0]) )
  {
LABEL_5:
    result = 4294967274LL;
    goto LABEL_6;
  }
  qdf_mtrace(51, 51, 7u, *(_BYTE *)(a1 + 8), v26[0]);
  v16 = 1000 * v26[0];
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Received Command to Set roam scan period (Empty Scan refresh period) = %d",
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    "drv_cmd_set_roam_scan_period");
  sme_update_empty_scan_refresh_period(a2[2], *(unsigned __int8 *)(a1 + 8), v16);
  result = v15;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
