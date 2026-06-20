__int64 __fastcall hdd_set_reduce_power_scan_mode(__int64 *a1, __int64 a2)
{
  __int64 v3; // x8
  unsigned int v4; // w19
  __int64 *v5; // x21
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  const char *v14; // x2
  unsigned int v15; // w1
  __int64 result; // x0
  char v17[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a1;
  v4 = *(unsigned __int8 *)(a2 + 4);
  v17[0] = 0;
  v5 = *(__int64 **)(v3 + 24);
  if ( (unsigned int)wlan_mlme_get_reduce_pwr_scan_mode(*v5, v17) )
  {
    v14 = "%s: get scan only mode failed";
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: vdev_id %d scan_mode %d cfg_val %d",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "hdd_set_reduce_power_scan_mode",
      *((unsigned __int8 *)a1 + 8),
      (unsigned __int8)v17[0],
      v4);
    if ( v4 > 1 )
      goto LABEL_5;
    if ( v17[0] != 1 )
    {
      v14 = "%s: enable_reduce_pwr_mode INI is not enabled";
      v15 = 8;
      goto LABEL_4;
    }
    result = wma_send_reduce_pwr_scan_mode(*(unsigned __int8 *)(v5[1] + 40), v4);
    if ( !(_DWORD)result )
      goto LABEL_6;
    v14 = "%s: Set Scan only mode failed";
  }
  v15 = 2;
LABEL_4:
  qdf_trace_msg(0x33u, v15, v14, v6, v7, v8, v9, v10, v11, v12, v13, "hdd_set_reduce_power_scan_mode");
LABEL_5:
  result = 4294967274LL;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
