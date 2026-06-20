__int64 __fastcall hdd_restore_thermal_mitigation_config(__int64 *a1)
{
  __int64 v2; // x0
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x20
  unsigned int v13; // w21
  int v14; // w5
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x21
  unsigned int v24; // w19
  __int64 v25; // [xsp+8h] [xbp-F8h] BYREF
  __int64 v26; // [xsp+10h] [xbp-F0h]
  __int64 v27; // [xsp+18h] [xbp-E8h]
  __int64 v28; // [xsp+20h] [xbp-E0h]
  __int64 v29; // [xsp+28h] [xbp-D8h]
  __int64 v30; // [xsp+30h] [xbp-D0h]
  __int64 v31; // [xsp+38h] [xbp-C8h]
  __int64 v32; // [xsp+40h] [xbp-C0h]
  __int64 v33; // [xsp+48h] [xbp-B8h]
  __int64 v34; // [xsp+50h] [xbp-B0h]
  __int64 v35; // [xsp+58h] [xbp-A8h]
  __int64 v36; // [xsp+60h] [xbp-A0h]
  __int64 v37; // [xsp+68h] [xbp-98h]
  __int64 v38; // [xsp+70h] [xbp-90h]
  __int64 v39; // [xsp+78h] [xbp-88h]
  __int64 v40; // [xsp+80h] [xbp-80h]
  __int64 v41; // [xsp+88h] [xbp-78h]
  __int64 v42; // [xsp+90h] [xbp-70h]
  __int64 v43; // [xsp+98h] [xbp-68h]
  __int64 v44; // [xsp+A0h] [xbp-60h]
  __int64 v45; // [xsp+A8h] [xbp-58h]
  _QWORD v46[7]; // [xsp+B0h] [xbp-50h] BYREF
  __int64 v47; // [xsp+E8h] [xbp-18h]
  __int64 v48; // [xsp+F0h] [xbp-10h]
  __int64 v49; // [xsp+F8h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v47 = 0;
  v48 = 0;
  memset(v46, 0, sizeof(v46));
  v44 = 0;
  v45 = 0;
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  v25 = 0;
  result = ucfg_fwol_get_thermal_temp(v2, v46);
  if ( (_DWORD)result )
  {
    v12 = jiffies;
    if ( hdd_restore_thermal_mitigation_config___last_ticks - jiffies + 125 < 0 )
    {
      v13 = result;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to get fwol thermal obj",
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        "hdd_restore_thermal_mitigation_config");
      result = v13;
      hdd_restore_thermal_mitigation_config___last_ticks = v12;
    }
  }
  else
  {
    v14 = *((unsigned __int8 *)a1 + 6777);
    LOBYTE(v27) = 1;
    HIDWORD(v29) = v14;
    LODWORD(v30) = 0;
    HIDWORD(v28) = 0;
    HIDWORD(v25) = v14 != 0;
    LODWORD(v26) = (unsigned __int16)v47;
    HIDWORD(v27) = 1;
    LOBYTE(v28) = 0;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: dc %d dc_off_per %d enable %d",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "hdd_restore_thermal_mitigation_config");
    result = sme_set_thermal_throttle_cfg(a1[2], &v25);
    if ( (_DWORD)result )
    {
      v23 = jiffies;
      if ( hdd_restore_thermal_mitigation_config___last_ticks_9 - jiffies + 125 < 0 )
      {
        v24 = result;
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Failed to set throttle configuration %d",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "hdd_restore_thermal_mitigation_config",
          (unsigned int)result);
        result = v24;
        hdd_restore_thermal_mitigation_config___last_ticks_9 = v23;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
