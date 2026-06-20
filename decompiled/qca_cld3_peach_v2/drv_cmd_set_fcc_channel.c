__int64 __fastcall drv_cmd_set_fcc_channel(__int64 a1, __int64 *a2, __int64 a3, unsigned __int8 a4)
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
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  int v24; // w23
  unsigned int v25; // w22
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  const char *v43; // x2
  unsigned int band; // w0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  unsigned int v53; // w21
  unsigned int v54; // w0
  __int64 v55; // x4
  unsigned int v56; // w21
  char is_6ghz_supported; // w0
  unsigned int v58; // w24
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  unsigned int v67; // w0
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  unsigned int v76; // w22
  unsigned int v77; // w20
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  unsigned int v86; // w0
  unsigned int v88; // w0
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  unsigned int v97; // w19
  char v98[4]; // [xsp+Ch] [xbp-14h] BYREF
  unsigned int v99; // [xsp+10h] [xbp-10h] BYREF
  char v100[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v101; // [xsp+18h] [xbp-8h]

  v101 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v100[0] = 0;
  v99 = 0;
  v98[0] = 0;
  v6 = kstrtos8(a3 + a4 + 1, 10, v100);
  if ( !v6 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: input_value = %d",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "drv_cmd_set_fcc_channel",
      (unsigned int)v100[0]);
    v24 = (unsigned __int8)v100[0] + 1;
    if ( (unsigned __int8)(v100[0] + 1) >= 4u )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Invalie input value",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "drv_cmd_set_fcc_channel");
      v15 = -22;
      goto LABEL_25;
    }
    v25 = 6u >> (v24 & 0xF);
    wlan_mlme_is_rf_test_mode_enabled(*a2, v98);
    v34 = a2[1];
    if ( (v98[0] & 1) != 0 )
    {
      if ( (((unsigned int)ucfg_reg_is_fcc_constraint_set(v34, v26, v27, v28, v29, v30, v31, v32, v33) ^ v25) & 1) == 0 )
      {
        v43 = "%s: Same FCC constraint value";
LABEL_7:
        qdf_trace_msg(0x33u, 8u, v43, v35, v36, v37, v38, v39, v40, v41, v42, "drv_cmd_set_fcc_channel");
        v15 = 0;
        goto LABEL_25;
      }
LABEL_20:
      v77 = ucfg_reg_set_fcc_constraint(a2[1], v25 & 1, v35, v36, v37, v38, v39, v40, v41, v42);
      if ( !v77 )
      {
        v77 = wlan_reg_recompute_current_chan_list(*a2, a2[1], v78, v79, v80, v81, v82, v83, v84, v85);
        if ( !v77 )
        {
          v15 = 0;
          goto LABEL_25;
        }
      }
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to update tx power for channels 12/13",
        v78,
        v79,
        v80,
        v81,
        v82,
        v83,
        v84,
        v85,
        "hdd_apply_fcc_constraint");
      v54 = v77;
      goto LABEL_23;
    }
    band = ucfg_reg_get_band(v34, &v99, v26, v27, v28, v29, v30, v31, v32, v33);
    if ( band )
    {
      v53 = band;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: failed to get band",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "drv_cmd_set_fcc_channel");
      v54 = v53;
    }
    else
    {
      if ( (v24 & 1) != 0 )
      {
        v55 = v99;
        v56 = 3;
      }
      else
      {
        is_6ghz_supported = wlan_reg_is_6ghz_supported(*a2, v45, v46, v47, v48, v49, v50, v51, v52);
        v55 = v99;
        if ( (is_6ghz_supported & 1) != 0 )
          v56 = 7;
        else
          v56 = v99;
      }
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Current band bitmap = %d, set band bitmap = %d",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "drv_cmd_set_fcc_channel",
        v55,
        v56);
      v58 = v99;
      if ( (((unsigned int)ucfg_reg_is_fcc_constraint_set(a2[1], v59, v60, v61, v62, v63, v64, v65, v66) ^ v25) & 1) == 0
        && (((unsigned int)ucfg_reg_get_keep_6ghz_sta_cli_connection(a2[1], v35, v36, v37, v38, v39, v40, v41, v42)
           ^ v24)
          & 1) == 0
        && v56 == v58 )
      {
        v43 = "%s: Same FCC constraint and band bitmap value";
        goto LABEL_7;
      }
      if ( v56 == v58 )
        goto LABEL_20;
      v67 = ucfg_reg_set_fcc_constraint(a2[1], v25 & 1, v35, v36, v37, v38, v39, v40, v41, v42);
      if ( v67 )
      {
        v76 = v67;
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Failed to update tx power for channels 12/13",
          v68,
          v69,
          v70,
          v71,
          v72,
          v73,
          v74,
          v75,
          "hdd_apply_fcc_constraint_update_band");
        v54 = v76;
      }
      else
      {
        v88 = ucfg_reg_set_keep_6ghz_sta_cli_connection(a2[1], v24 & 1, v68, v69, v70, v71, v72, v73, v74, v75);
        if ( !v88 )
        {
          v86 = hdd_reg_set_band(*(_QWORD *)(*(_QWORD *)a1 + 32LL), v56);
          goto LABEL_24;
        }
        v97 = v88;
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Failed to update keep sta cli connection",
          v89,
          v90,
          v91,
          v92,
          v93,
          v94,
          v95,
          v96,
          "hdd_apply_fcc_constraint_update_band");
        v54 = v97;
      }
    }
LABEL_23:
    v86 = qdf_status_to_os_return(v54);
LABEL_24:
    v15 = v86;
    goto LABEL_25;
  }
  v15 = v6;
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: error %d parsing userspace fcc parameter",
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    "drv_cmd_set_fcc_channel",
    v6);
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return v15;
}
