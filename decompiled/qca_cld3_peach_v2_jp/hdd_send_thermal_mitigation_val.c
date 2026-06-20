__int64 __fastcall hdd_send_thermal_mitigation_val(__int64 *a1, unsigned int a2, char a3)
{
  __int64 v6; // x0
  __int64 result; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x20
  unsigned int v17; // w21
  __int64 v18; // x4
  int v19; // w9
  unsigned int v20; // w21
  int v21; // w8
  const char *v22; // x2
  unsigned int v23; // w20
  __int64 v24; // x4
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x21
  unsigned int v34; // w19
  _DWORD v35[3]; // [xsp+8h] [xbp-F8h] BYREF
  __int64 v36; // [xsp+14h] [xbp-ECh]
  __int64 v37; // [xsp+1Ch] [xbp-E4h]
  __int64 v38; // [xsp+24h] [xbp-DCh]
  __int64 v39; // [xsp+2Ch] [xbp-D4h]
  __int64 v40; // [xsp+34h] [xbp-CCh]
  __int64 v41; // [xsp+3Ch] [xbp-C4h]
  __int64 v42; // [xsp+44h] [xbp-BCh]
  __int64 v43; // [xsp+4Ch] [xbp-B4h]
  __int64 v44; // [xsp+54h] [xbp-ACh]
  __int64 v45; // [xsp+5Ch] [xbp-A4h]
  __int64 v46; // [xsp+64h] [xbp-9Ch]
  __int64 v47; // [xsp+6Ch] [xbp-94h]
  __int64 v48; // [xsp+74h] [xbp-8Ch]
  __int64 v49; // [xsp+7Ch] [xbp-84h]
  __int64 v50; // [xsp+84h] [xbp-7Ch]
  __int64 v51; // [xsp+8Ch] [xbp-74h]
  __int64 v52; // [xsp+94h] [xbp-6Ch]
  __int64 v53; // [xsp+9Ch] [xbp-64h]
  __int64 v54; // [xsp+A4h] [xbp-5Ch]
  int v55; // [xsp+ACh] [xbp-54h]
  _QWORD v56[7]; // [xsp+B0h] [xbp-50h] BYREF
  __int64 v57; // [xsp+E8h] [xbp-18h]
  __int64 v58; // [xsp+F0h] [xbp-10h]
  __int64 v59; // [xsp+F8h] [xbp-8h]

  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *a1;
  v57 = 0;
  v58 = 0;
  memset(v56, 0, sizeof(v56));
  v55 = 0;
  v54 = 0;
  v53 = 0;
  v52 = 0;
  v51 = 0;
  v50 = 0;
  v49 = 0;
  v48 = 0;
  v47 = 0;
  v46 = 0;
  v45 = 0;
  v44 = 0;
  v43 = 0;
  v42 = 0;
  v41 = 0;
  v40 = 0;
  v39 = 0;
  v38 = 0;
  v37 = 0;
  v36 = 0;
  result = ucfg_fwol_get_thermal_temp(v6, v56);
  if ( (_DWORD)result )
  {
    v16 = jiffies;
    if ( hdd_send_thermal_mitigation_val___last_ticks - jiffies + 125 < 0 )
    {
      v17 = result;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to get fwol thermal obj",
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        "hdd_send_thermal_mitigation_val");
      result = v17;
      hdd_send_thermal_mitigation_val___last_ticks = v16;
    }
    goto LABEL_16;
  }
  if ( a2 >= 6 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Invalid thermal state",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "hdd_send_thermal_mitigation_val");
    result = 4;
    goto LABEL_16;
  }
  v18 = (unsigned __int16)v57;
  LODWORD(v38) = 0;
  v19 = *((unsigned __int8 *)a1 + 6922);
  BYTE4(v36) = 1;
  v20 = *((_DWORD *)&v56[4] + a2);
  v21 = dword_A2B388[a2];
  v35[0] = 0;
  v39 = v20;
  v35[1] = v21;
  v35[2] = (unsigned __int16)v57;
  if ( v19 == 1 )
  {
    if ( a3 == 2 )
    {
      LODWORD(v37) = 2;
      v22 = "%s: Thermal client:%d priority_wpps: %d";
      v23 = (unsigned __int16)v57;
      v24 = 2;
      BYTE4(v37) = BYTE4(v57);
      LODWORD(v39) = 50;
    }
    else
    {
      if ( a3 != 1 )
        goto LABEL_12;
      LODWORD(v37) = 1;
      v22 = "%s: Thermal client:%d priority_apps: %d";
      BYTE4(v37) = BYTE3(v57);
      v23 = (unsigned __int16)v57;
      v24 = 1;
    }
    qdf_trace_msg(0x33u, 8u, v22, v8, v9, v10, v11, v12, v13, v14, v15, "hdd_thermal_fill_clientid_priority", v24);
    v18 = v23;
  }
LABEL_12:
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: dc %d dc_off_per %d",
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    "hdd_send_thermal_mitigation_val",
    v18,
    v20);
  result = sme_set_thermal_throttle_cfg(a1[2], v35);
  if ( (_DWORD)result )
  {
    v33 = jiffies;
    if ( hdd_send_thermal_mitigation_val___last_ticks_5 - jiffies + 125 < 0 )
    {
      v34 = result;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to set throttle configuration %d",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "hdd_send_thermal_mitigation_val",
        (unsigned int)result);
      result = v34;
      hdd_send_thermal_mitigation_val___last_ticks_5 = v33;
    }
  }
  else
  {
    *((_BYTE *)a1 + 6777) = v20;
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
