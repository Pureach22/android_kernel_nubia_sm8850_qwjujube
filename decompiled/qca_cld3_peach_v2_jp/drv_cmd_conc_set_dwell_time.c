__int64 __fastcall drv_cmd_conc_set_dwell_time(__int64 *a1, int a2, char *s1)
{
  __int64 v4; // x20
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 result; // x0
  int v14; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x4
  int v24; // w0
  const char *v25; // x2
  unsigned int v26; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v27; // [xsp+8h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a1;
  v26 = 0;
  if ( !strncmp(s1, "CONCSETDWELLTIME ACTIVE MAX", 0x1Bu) )
  {
    if ( s1[27] == 32 )
    {
      v14 = kstrtouint(s1 + 28, 10, &v26);
      v23 = v26;
      if ( !v14 && v26 < 0x2711 )
      {
        wlan_scan_cfg_set_conc_active_dwelltime(**(_QWORD **)(v4 + 24), v26);
LABEL_12:
        result = 0;
        goto LABEL_17;
      }
      v25 = "%s: CONC ACTIVE MAX value %d incorrect";
LABEL_16:
      qdf_trace_msg(0x33u, 2u, v25, v15, v16, v17, v18, v19, v20, v21, v22, "hdd_conc_set_dwell_time", v23);
      result = 4294967282LL;
      goto LABEL_17;
    }
LABEL_13:
    qdf_trace_msg(0x33u, 2u, "%s: Invalid driver command", v5, v6, v7, v8, v9, v10, v11, v12, "hdd_conc_set_dwell_time");
    result = 4294967274LL;
    goto LABEL_17;
  }
  if ( !strncmp(s1, "CONCSETDWELLTIME PASSIVE MAX", 0x1Cu) )
  {
    if ( s1[28] == 32 )
    {
      v24 = kstrtouint(s1 + 29, 10, &v26);
      v23 = v26;
      if ( !v24 && v26 < 0x2711 )
      {
        wlan_scan_cfg_set_conc_passive_dwelltime(**(_QWORD **)(v4 + 24), v26);
        goto LABEL_12;
      }
      v25 = "%s: CONC PASSIVE MAX val %d incorrect";
      goto LABEL_16;
    }
    goto LABEL_13;
  }
  result = 4294967274LL;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
