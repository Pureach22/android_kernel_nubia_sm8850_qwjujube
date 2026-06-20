__int64 __fastcall drv_cmd_set_scan_channel_time(__int64 a1, __int64 a2, __int64 a3, unsigned __int8 a4)
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
  v17 = 40;
  v6 = kstrtou16(a3 + a4 + 1, 10, &v17);
  if ( (v6 & 0x80000000) != 0 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: kstrtou16 failed range [%d - %d]",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "drv_cmd_set_scan_channel_time",
      3,
      300);
LABEL_6:
    result = 4294967274LL;
    goto LABEL_7;
  }
  if ( (unsigned int)v17 - 3 >= 0x12A )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: lfr mode value %d is out of range (Min: %d Max: %d)",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "drv_cmd_set_scan_channel_time");
    goto LABEL_6;
  }
  v15 = v6;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Received Command to change channel max time = %d",
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    "drv_cmd_set_scan_channel_time");
  sme_set_neighbor_scan_max_chan_time(*(_QWORD *)(a2 + 16), *(unsigned __int8 *)(a1 + 8), v17);
  result = v15;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
