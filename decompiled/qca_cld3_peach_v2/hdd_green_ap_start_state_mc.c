__int64 __fastcall hdd_green_ap_start_state_mc(
        __int64 *a1,
        int a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  const char *v15; // x2
  __int64 result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  int v33; // w8
  bool v34; // cc
  unsigned __int8 v35; // w20
  unsigned __int8 v36; // w0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  _BYTE v77[4]; // [xsp+4h] [xbp-1Ch] BYREF
  _BYTE v78[4]; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v79[4]; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v80[4]; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v81[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v82; // [xsp+18h] [xbp-8h]

  v82 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = a1[13];
  v81[0] = 0;
  v80[0] = 0;
  v79[0] = 0;
  v78[0] = 0;
  v77[0] = 0;
  if ( !v11 )
  {
    v15 = "%s: NULL hdd config";
    goto LABEL_5;
  }
  if ( !(unsigned int)wlan_mlme_get_vht_mimo_cap(*a1, v78) )
  {
    if ( !v78[0] )
      qdf_trace_msg(0x33u, 8u, "%s:  2x2 not enabled", a4, a5, a6, a7, a8, a9, a10, a11, "hdd_green_ap_start_state_mc");
    if ( (unsigned int)ucfg_green_ap_get_ps_config(a1[1], v77, a4, a5, a6, a7, a8, a9, a10, a11) )
      goto LABEL_10;
    if ( !v77[0] )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Green AP not enabled",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "hdd_green_ap_start_state_mc");
      result = 0;
      goto LABEL_6;
    }
    ((void (__fastcall *)(__int64, __int64, _BYTE *))policy_mgr_mode_specific_num_active_sessions)(*a1, 1, v80);
    ((void (__fastcall *)(__int64, __int64, _BYTE *))policy_mgr_mode_specific_num_active_sessions)(*a1, 3, v79);
    v33 = a2;
    v34 = a2 <= 1;
    v35 = 0;
    if ( v34 )
    {
      if ( !v33 )
        goto LABEL_20;
      if ( v33 != 1 )
        goto LABEL_31;
    }
    else if ( v33 != 3 )
    {
      if ( v33 != 2 )
      {
LABEL_31:
        result = v35;
        goto LABEL_6;
      }
LABEL_20:
      if ( !(v80[0] | v79[0]) )
      {
LABEL_10:
        result = 0;
        goto LABEL_6;
      }
      if ( (a3 & 1) == 0 )
        goto LABEL_24;
      goto LABEL_27;
    }
    if ( (a3 & 1) != 0 )
    {
LABEL_24:
      v36 = hdd_green_ap_check_enable(a1, v81);
      if ( v36 )
      {
        v35 = v36;
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Failed to check Green AP enable status",
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          "hdd_green_ap_start_state_mc");
        goto LABEL_31;
      }
      if ( v81[0] == 1 )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Enabling Green AP",
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          "hdd_green_ap_start_state_mc");
        ucfg_green_ap_set_ps_config(a1[1], 1, v61, v62, v63, v64, v65, v66, v67, v68);
        wlan_green_ap_start(a1[1], v69, v70, v71, v72, v73, v74, v75, v76);
      }
LABEL_30:
      v35 = 0;
      goto LABEL_31;
    }
    if ( v80[0] | v79[0] )
      goto LABEL_30;
LABEL_27:
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Disabling Green AP",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "hdd_green_ap_start_state_mc");
    ucfg_green_ap_set_ps_config(a1[1], 0, v45, v46, v47, v48, v49, v50, v51, v52);
    wlan_green_ap_stop(a1[1], v53, v54, v55, v56, v57, v58, v59, v60);
    goto LABEL_30;
  }
  v15 = "%s: unable to get vht_enable2x2";
LABEL_5:
  qdf_trace_msg(0x33u, 2u, v15, a4, a5, a6, a7, a8, a9, a10, a11, "hdd_green_ap_start_state_mc");
  result = 4294967274LL;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
