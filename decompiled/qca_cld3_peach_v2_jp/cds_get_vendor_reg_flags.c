__int64 __fastcall cds_get_vendor_reg_flags(
        __int64 a1,
        unsigned int a2,
        unsigned __int16 a3,
        char a4,
        char a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  int channel_state_for_pwrmode; // w0
  unsigned int v19; // w19
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int v36; // w3
  bool v37; // zf
  int v38; // w8
  int v39; // w9
  int v40; // w8
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  _QWORD v58[3]; // [xsp+8h] [xbp-18h] BYREF

  v58[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v58[0] = 0;
  v58[1] = 0;
  channel_state_for_pwrmode = wlan_reg_get_channel_state_for_pwrmode(a1, a2, 0, a6, a7, a8, a9, a10, a11, a12, a13);
  v19 = 0;
  if ( channel_state_for_pwrmode == 4 )
    goto LABEL_51;
  if ( channel_state_for_pwrmode == 2 )
    v19 = 512;
  if ( !channel_state_for_pwrmode )
    v19 |= 0x2000000u;
  if ( wlan_reg_is_24ghz_ch_freq(a2) )
  {
    v19 |= 0x80u;
    if ( (unsigned int)a3 - 2 < 3 )
    {
      qdf_mem_set(v58, 0x10u, 0);
      goto LABEL_25;
    }
  }
  else
  {
    v19 |= 0x100u;
  }
  qdf_mem_set(v58, 0x10u, 0);
  if ( a3 <= 2u )
  {
    if ( !a3 )
      goto LABEL_40;
    if ( a3 == 1 )
    {
LABEL_25:
      qdf_mem_set(v58, 0x10u, 0);
      LODWORD(v58[0]) = 1;
      wlan_reg_set_channel_params_for_pwrmode(a1, a2, 0, (__int64)v58, 0, v28, v29, v30, v31, v32, v33, v34, v35);
      if ( BYTE4(v58[0]) == 3 )
      {
        v36 = a2 - 20;
      }
      else
      {
        v36 = 0;
        if ( BYTE4(v58[0]) == 1 )
          v36 = a2 + 20;
      }
      if ( (unsigned int)wlan_reg_get_bonded_channel_state_for_pwrmode(a1, a2, 1u, v36, 0) == 4 )
        goto LABEL_40;
      if ( BYTE4(v58[0]) == 3 )
      {
        v37 = (a5 & 1) == 0;
        v38 = 0x40000;
        v39 = 4456448;
        goto LABEL_37;
      }
      if ( BYTE4(v58[0]) == 1 )
      {
        v37 = (a5 & 1) == 0;
        v38 = 0x20000;
        v39 = 2228224;
LABEL_37:
        if ( !v37 )
          v38 = v39;
        v19 |= v38;
      }
LABEL_40:
      v40 = v19 | 0x100000;
      if ( (a5 & 1) == 0 )
        v40 = v19;
      if ( (a4 & 1) != 0 )
        v19 = v40 | 0x10000;
      else
        v19 = v40;
LABEL_45:
      if ( (unsigned int)wlan_reg_get_bonded_channel_state_for_pwrmode(a1, a2, 6u, 0, 0) != 4
        && cds_is_10_mhz_enabled(v41, v42, v43, v44, v45, v46, v47, v48) )
      {
        v19 |= 0x4000u;
      }
      goto LABEL_48;
    }
LABEL_22:
    LODWORD(v58[0]) = 2;
    if ( (unsigned int)wlan_reg_get_5g_bonded_channel_state_for_pwrmode(
                         a1,
                         a2,
                         (unsigned int *)v58,
                         0,
                         v20,
                         v21,
                         v22,
                         v23,
                         v24,
                         v25,
                         v26,
                         v27) != 4
      && (a5 & 1) != 0 )
    {
      v19 |= 0x800000u;
    }
    goto LABEL_25;
  }
  if ( a3 <= 4u )
  {
    if ( a3 != 3 )
    {
      LODWORD(v58[0]) = 4;
      if ( (unsigned int)wlan_reg_get_5g_bonded_channel_state_for_pwrmode(
                           a1,
                           a2,
                           (unsigned int *)v58,
                           0,
                           v20,
                           v21,
                           v22,
                           v23,
                           v24,
                           v25,
                           v26,
                           v27) != 4
        && (a5 & 1) != 0 )
      {
        v19 |= 0x8000000u;
      }
    }
    LODWORD(v58[0]) = 3;
    if ( (unsigned int)wlan_reg_get_5g_bonded_channel_state_for_pwrmode(
                         a1,
                         a2,
                         (unsigned int *)v58,
                         0,
                         v20,
                         v21,
                         v22,
                         v23,
                         v24,
                         v25,
                         v26,
                         v27) != 4
      && (a5 & 1) != 0 )
    {
      v19 |= 0x4000000u;
    }
    goto LABEL_22;
  }
  if ( a3 != 5 )
  {
    if ( a3 != 6 )
    {
      qdf_trace_msg(
        0x38u,
        4u,
        "%s: invalid channel width value %d",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "cds_get_vendor_reg_flags",
        a3);
      goto LABEL_51;
    }
    goto LABEL_45;
  }
LABEL_48:
  if ( (unsigned int)wlan_reg_get_bonded_channel_state_for_pwrmode(a1, a2, 5u, 0, 0) != 4
    && cds_is_5_mhz_enabled(v49, v50, v51, v52, v53, v54, v55, v56) )
  {
    v19 |= 0x8000u;
  }
LABEL_51:
  _ReadStatusReg(SP_EL0);
  return v19;
}
