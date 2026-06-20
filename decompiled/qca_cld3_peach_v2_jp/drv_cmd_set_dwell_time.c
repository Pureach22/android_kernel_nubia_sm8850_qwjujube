__int64 __fastcall drv_cmd_set_dwell_time(
        int a1,
        __int64 *a2,
        char *s1,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x19
  unsigned int active; // w0
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int v23; // w1
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x20
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // x20
  __int64 v50; // x20
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 v59; // x20
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  __int64 v68; // x20
  __int64 v69; // x20
  unsigned int v70; // [xsp+0h] [xbp-10h] BYREF
  unsigned int v71; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v72; // [xsp+8h] [xbp-8h]

  v72 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *a2;
  v70 = 0;
  if ( !v11 )
  {
    qdf_trace_msg(0x33u, 2u, "%s: psoc is null", a4, a5, a6, a7, a8, a9, a10, a11, "hdd_set_dwell_time");
    result = 4294967274LL;
    goto LABEL_48;
  }
  if ( !strncmp(s1, "SETDWELLTIME ACTIVE MAX", 0x17u) )
  {
    if ( s1[23] != 32 )
      goto LABEL_42;
    if ( (unsigned int)kstrtouint(s1 + 24, 10, &v70) || (v23 = v70, v70 >= 0x2711) )
    {
      v40 = jiffies;
      if ( hdd_set_dwell_time___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: argument passed for SETDWELLTIME ACTIVE MAX is incorrect",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "hdd_set_dwell_time");
        hdd_set_dwell_time___last_ticks = v40;
      }
      goto LABEL_47;
    }
LABEL_14:
    wlan_scan_cfg_set_active_dwelltime(v11, v23);
    result = 0;
    goto LABEL_48;
  }
  if ( !strncmp(s1, "SETDWELLTIME PASSIVE MAX", 0x18u) )
  {
    if ( s1[24] == 32 )
    {
      if ( !(unsigned int)kstrtouint(s1 + 25, 10, &v70) && v70 < 0x2711 )
      {
        wlan_scan_cfg_set_passive_dwelltime(v11, v70);
        result = 0;
        goto LABEL_48;
      }
      v50 = jiffies;
      if ( hdd_set_dwell_time___last_ticks_252 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: argument passed for SETDWELLTIME PASSIVE MAX is incorrect",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "hdd_set_dwell_time");
        hdd_set_dwell_time___last_ticks_252 = v50;
      }
      goto LABEL_47;
    }
    goto LABEL_42;
  }
  if ( !strncmp(s1, "SETDWELLTIME 2G MAX", 0x13u) )
  {
    if ( s1[19] == 32 )
    {
      if ( !(unsigned int)kstrtouint(s1 + 20, 10, &v70) && v70 < 0x2711 )
      {
        wlan_scan_cfg_set_active_2g_dwelltime(v11, v70);
        result = 0;
        goto LABEL_48;
      }
      v59 = jiffies;
      if ( hdd_set_dwell_time___last_ticks_255 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: argument passed for SETDWELLTIME 2G MAX is incorrect",
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          "hdd_set_dwell_time");
        hdd_set_dwell_time___last_ticks_255 = v59;
      }
      goto LABEL_47;
    }
    goto LABEL_42;
  }
  if ( !strncmp(s1, "SETDWELLTIME", 0xCu) )
  {
    if ( s1[12] != 32 )
      goto LABEL_42;
    if ( (unsigned int)kstrtouint(s1 + 13, 10, &v70) || (v23 = v70, v70 >= 0x2711) )
    {
      v49 = jiffies;
      if ( hdd_set_dwell_time___last_ticks_257 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: argument passed for SETDWELLTIME is incorrect",
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          "hdd_set_dwell_time");
        hdd_set_dwell_time___last_ticks_257 = v49;
      }
      goto LABEL_47;
    }
    goto LABEL_14;
  }
  v71 = 0;
  if ( !strncmp(s1, "SETDWELLTIME 6G MAX", 0x13u) )
  {
    if ( s1[19] == 32 )
    {
      if ( !(unsigned int)kstrtouint(s1 + 20, 10, &v71) && v71 < 0x2711 )
      {
        active = wlan_scan_cfg_set_active_6g_dwelltime(v11, v71);
        goto LABEL_9;
      }
      v68 = jiffies;
      if ( hdd_set_dwell_time_6g___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: argument passed for SETDWELLTIME 6G MAX is incorrect",
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          "hdd_set_dwell_time_6g");
        hdd_set_dwell_time_6g___last_ticks = v68;
      }
LABEL_47:
      result = 4294967282LL;
      goto LABEL_48;
    }
LABEL_42:
    result = 4294967274LL;
    goto LABEL_48;
  }
  if ( !strncmp(s1, "SETDWELLTIME PASSIVE 6G MAX", 0x1Bu) )
  {
    if ( s1[27] == 32 )
    {
      if ( !(unsigned int)kstrtouint(s1 + 28, 10, &v71) && v71 < 0x2711 )
      {
        active = wlan_scan_cfg_set_passive_6g_dwelltime(v11, v71);
        goto LABEL_9;
      }
      v69 = jiffies;
      if ( hdd_set_dwell_time_6g___last_ticks_262 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: argument passed for SETDWELLTIME PASSIVE 6G MAX is incorrect",
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          "hdd_set_dwell_time_6g");
        hdd_set_dwell_time_6g___last_ticks_262 = v69;
      }
      goto LABEL_47;
    }
    goto LABEL_42;
  }
  active = 4;
LABEL_9:
  result = qdf_status_to_os_return(active);
LABEL_48:
  _ReadStatusReg(SP_EL0);
  return result;
}
