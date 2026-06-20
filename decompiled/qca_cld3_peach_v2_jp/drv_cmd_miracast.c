__int64 __fastcall drv_cmd_miracast(__int64 a1, __int64 a2, __int64 a3)
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
  int v16; // w8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  const char *v25; // x2
  const char *v26; // x2
  __int64 result; // x0
  bool is_mcc_in_24G; // w8
  _BYTE v29[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v30; // [xsp+8h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29[0] = 0;
  if ( (unsigned int)_wlan_hdd_validate_context(a2, "drv_cmd_miracast") )
    goto LABEL_14;
  v6 = kstrtou8(a3 + 9, 10, v29);
  if ( (v6 & 0x80000000) != 0 )
  {
    v26 = "%s: kstrtou8 failed range";
LABEL_13:
    qdf_trace_msg(0x33u, 2u, v26, v7, v8, v9, v10, v11, v12, v13, v14, "drv_cmd_miracast");
LABEL_14:
    result = 4294967274LL;
    goto LABEL_15;
  }
  v15 = v6;
  qdf_trace_msg(0x33u, 8u, "%s: filter_type %d", v7, v8, v9, v10, v11, v12, v13, v14, "drv_cmd_miracast", v29[0]);
  v16 = v29[0];
  if ( v29[0] >= 3u )
  {
    if ( (unsigned int)v29[0] - 128 <= 1 )
    {
      wma_cli_set_command(*(unsigned __int8 *)(a1 + 8), 53, v29[0] != 128, 2);
      result = 0;
      goto LABEL_15;
    }
    v26 = "%s: accepted Values: 0-Disabled, 1-Source, 2-Sink, 128,129";
    goto LABEL_13;
  }
  *(_BYTE *)(a2 + 1136) = v29[0];
  ucfg_mlme_set_vdev_traffic_low_latency(*(_QWORD *)a2, *(unsigned __int8 *)(a1 + 8), v16 != 0);
  if ( (unsigned int)sme_set_miracast(*(_QWORD *)(a2 + 16), v29[0]) )
  {
    v25 = "%s: Failed to set miracast";
LABEL_11:
    qdf_trace_msg(0x33u, 2u, v25, v17, v18, v19, v20, v21, v22, v23, v24, "drv_cmd_miracast");
    result = 4294967280LL;
    goto LABEL_15;
  }
  if ( (unsigned int)ucfg_scan_set_miracast(*(_QWORD *)a2, v29[0] != 0) )
  {
    v25 = "%s: Failed to set miracastn scan";
    goto LABEL_11;
  }
  is_mcc_in_24G = policy_mgr_is_mcc_in_24G(*(_QWORD *)a2);
  result = v15;
  if ( is_mcc_in_24G )
    result = wlan_hdd_set_mas(*(_QWORD *)a1);
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
