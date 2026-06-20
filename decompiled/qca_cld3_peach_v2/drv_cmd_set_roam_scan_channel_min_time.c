__int64 __fastcall drv_cmd_set_roam_scan_channel_min_time(__int64 a1, __int64 a2, __int64 a3, unsigned __int8 a4)
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
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 result; // x0
  unsigned __int8 v25[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v26; // [xsp+8h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25[0] = 20;
  v6 = kstrtou8(a3 + a4 + 1, 10, v25);
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
      "drv_cmd_set_roam_scan_channel_min_time",
      10,
      40);
LABEL_6:
    result = 4294967274LL;
    goto LABEL_7;
  }
  if ( (unsigned int)v25[0] - 10 >= 0x1F )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: scan min channel time value %d is out of range (Min: %d Max: %d)",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "drv_cmd_set_roam_scan_channel_min_time");
    goto LABEL_6;
  }
  v15 = v6;
  qdf_mtrace(51, 51, 0x3Cu, *(_BYTE *)(a1 + 8), v25[0]);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Received Command to change channel min time = %d",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "drv_cmd_set_roam_scan_channel_min_time",
    v25[0]);
  sme_set_neighbor_scan_min_chan_time(*(_QWORD *)(a2 + 16), v25[0], *(unsigned __int8 *)(a1 + 8));
  result = v15;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
