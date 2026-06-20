__int64 __fastcall hdd_update_scan_config(__int64 *a1)
{
  __int64 v2; // x20
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned int v11; // w19
  const char *v12; // x2
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  int v22; // [xsp+4h] [xbp-7Ch] BYREF
  _QWORD v23[13]; // [xsp+8h] [xbp-78h] BYREF
  int v24; // [xsp+70h] [xbp-10h]
  __int64 v25; // [xsp+78h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v24 = 0;
  memset(v23, 0, sizeof(v23));
  v22 = 0;
  qdf_mem_set(v23, 0x6Cu, 0);
  if ( (unsigned int)wlan_mlme_get_sta_miracast_mcc_rest_time(*a1, &v22) )
  {
    v11 = -5;
    v12 = "%s: ucfg_mlme_get_sta_miracast_mcc_rest_time, use def";
  }
  else
  {
    v24 = v22;
    v13 = ((double (__fastcall *)(_QWORD *, __int64 *))hdd_update_ie_allowlist_attr)(v23, a1);
    if ( !(unsigned int)ucfg_scan_update_user_config(v2, (__int64)v23, v13, v14, v15, v16, v17, v18, v19, v20) )
    {
      v11 = 0;
      goto LABEL_6;
    }
    v11 = -22;
    v12 = "%s: failed pmo psoc configuration";
  }
  qdf_trace_msg(0x33u, 2u, v12, v3, v4, v5, v6, v7, v8, v9, v10, "hdd_update_scan_config");
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return v11;
}
