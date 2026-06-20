__int64 __fastcall hdd_set_fw_params(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x8
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 *context; // x0
  __int64 *v20; // x20
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  const char *v29; // x2
  __int64 result; // x0
  unsigned int v31; // w21
  int v32; // w9
  __int64 *v33; // x8
  int v34; // w9
  __int64 *v35; // x8
  int v36; // w9
  __int64 *v37; // x8
  int v38; // w9
  __int64 *v39; // x8
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned int v48; // w0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v57; // x4
  const char *v58; // x2
  unsigned int v59; // w0
  unsigned int v60; // w0
  char v61[4]; // [xsp+8h] [xbp-68h] BYREF
  char v62[4]; // [xsp+Ch] [xbp-64h] BYREF
  __int64 v63; // [xsp+10h] [xbp-60h] BYREF
  char v64[4]; // [xsp+18h] [xbp-58h] BYREF
  char v65[4]; // [xsp+1Ch] [xbp-54h] BYREF
  char v66[4]; // [xsp+20h] [xbp-50h] BYREF
  char v67[4]; // [xsp+24h] [xbp-4Ch] BYREF
  unsigned __int16 v68[2]; // [xsp+28h] [xbp-48h] BYREF
  unsigned __int16 v69; // [xsp+2Ch] [xbp-44h] BYREF
  __int64 v70; // [xsp+30h] [xbp-40h] BYREF
  int v71; // [xsp+38h] [xbp-38h]
  int v72; // [xsp+3Ch] [xbp-34h]
  __int64 v73; // [xsp+40h] [xbp-30h]
  __int64 v74; // [xsp+48h] [xbp-28h]
  __int64 v75; // [xsp+50h] [xbp-20h]
  __int64 v76; // [xsp+58h] [xbp-18h]
  __int64 v77; // [xsp+60h] [xbp-10h]
  __int64 v78; // [xsp+68h] [xbp-8h]

  v78 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 32);
  v69 = 0;
  v68[0] = 0;
  v67[0] = 0;
  v66[0] = 0;
  v65[0] = 0;
  v64[0] = 0;
  v63 = 0;
  v62[0] = 0;
  v61[0] = 0;
  v76 = 0;
  v77 = 0;
  v74 = 0;
  v75 = 0;
  v73 = 0;
  qdf_trace_msg(0x33u, 8u, "%s: enter(%s)", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_set_fw_params", v10 + 296);
  context = _cds_get_context(51, (__int64)"hdd_set_fw_params", v11, v12, v13, v14, v15, v16, v17, v18);
  if ( !context )
    goto LABEL_31;
  v20 = context;
  if ( (unsigned int)cds_get_conparam() != 5 )
  {
    v70 = 0x100000098LL;
    wlan_mlme_get_dtim_selection_diversity(*v20, (int *)&v63 + 1);
    v71 = 157;
    v72 = HIDWORD(v63);
    if ( (unsigned int)ucfg_fwol_get_enable_tx_sch_delay(*v20, v65) )
    {
      v31 = 2;
    }
    else
    {
      v31 = 3;
      LODWORD(v73) = 136;
      HIDWORD(v73) = (unsigned __int8)v65[0];
    }
    if ( !(unsigned int)ucfg_fwol_get_ofdm_scrambler_seed(*v20, v61) )
    {
      v32 = (unsigned __int8)v61[0];
      v33 = &v70 + v31++;
      *(_DWORD *)v33 = 219;
      *((_DWORD *)v33 + 1) = v32;
    }
    if ( !(unsigned int)ucfg_fwol_get_enable_secondary_rate(*v20, &v63) )
    {
      v34 = v63;
      v35 = &v70 + v31++;
      *(_DWORD *)v35 = 160;
      *((_DWORD *)v35 + 1) = v34;
    }
    if ( !(unsigned int)ucfg_fwol_get_sap_xlna_bypass(*v20, v62) )
    {
      v36 = (unsigned __int8)v62[0];
      v37 = &v70 + v31++;
      *(_DWORD *)v37 = 196;
      *((_DWORD *)v37 + 1) = v36;
    }
    wlan_mlme_get_dfs_chan_ageout_time(*v20, v64);
    v38 = (unsigned __int8)v64[0];
    v39 = &v70 + v31;
    *(_DWORD *)v39 = 195;
    *((_DWORD *)v39 + 1) = v38;
    if ( (unsigned int)sme_send_multi_pdev_vdev_set_params(0, 0, &v70, v31 + 1) )
      goto LABEL_31;
    if ( !*(_DWORD *)(a1 + 40) )
    {
      if ( (unsigned int)ucfg_get_upper_brssi_thresh(*v20, &v69) )
        goto LABEL_31;
      sme_set_smps_cfg(*(unsigned __int8 *)(*(_QWORD *)(a1 + 52824) + 8LL), 3, v69);
      if ( (unsigned int)ucfg_get_lower_brssi_thresh(*v20, v68) )
        goto LABEL_31;
      sme_set_smps_cfg(*(unsigned __int8 *)(*(_QWORD *)(a1 + 52824) + 8LL), 4, v68[0]);
      if ( (unsigned int)ucfg_get_enable_dtim_1chrx(*v20, v67) )
        goto LABEL_31;
      sme_set_smps_cfg(*(unsigned __int8 *)(*(_QWORD *)(a1 + 52824) + 8LL), 5, (unsigned __int8)v67[0]);
      if ( (unsigned int)hdd_set_dynamic_bw_param(a1, *v20) )
        goto LABEL_31;
    }
    if ( (unsigned int)wlan_mlme_get_vht_mimo_cap(*v20, v66) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: unable to get vht_enable2x2",
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        "hdd_set_fw_params");
    if ( v66[0] )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: configuring 2x2 mode fw params",
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        "hdd_set_fw_params");
      v48 = sme_set_cck_tx_fir_override(v20[2], *(unsigned __int8 *)(*(_QWORD *)(a1 + 52824) + 8LL));
      if ( v48 )
      {
        v57 = v48;
        v58 = "%s: wmi_pdev_param_enable_cck_tfir_override set failed %d";
        goto LABEL_30;
      }
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: configuring 1x1 mode fw params",
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        "hdd_set_fw_params");
      v59 = sme_cli_set_command(*(unsigned __int8 *)(*(_QWORD *)(a1 + 52824) + 8LL), 139266, 2684354560LL, 1);
      if ( v59 )
      {
        v57 = v59;
        v58 = "%s: DTIM 1 chain set failed %d";
        goto LABEL_30;
      }
    }
    wlan_mlme_configure_chain_mask(**(_QWORD **)(a1 + 24));
    v60 = sme_set_enable_mem_deep_sleep(v20[2], *(unsigned __int8 *)(*(_QWORD *)(a1 + 52824) + 8LL));
    if ( !v60 )
    {
      if ( (v20[879] & 1) == 0 )
      {
        hdd_set_fw_log_params(v20, *(unsigned __int8 *)(*(_QWORD *)(a1 + 52824) + 8LL));
        *((_BYTE *)v20 + 7032) = 1;
      }
      if ( !(unsigned int)hdd_send_coex_config_params(v20, a1) )
      {
        v29 = "%s: exit";
        goto LABEL_4;
      }
      qdf_trace_msg(
        0x33u,
        3u,
        "%s: Error initializing coex config params",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "hdd_set_fw_params");
LABEL_31:
      result = 4294967274LL;
      goto LABEL_32;
    }
    v57 = v60;
    v58 = "%s: wmi_pdev_param_hyst_en set failed %d";
LABEL_30:
    qdf_trace_msg(0x33u, 2u, v58, v49, v50, v51, v52, v53, v54, v55, v56, "hdd_set_fw_params", v57);
    goto LABEL_31;
  }
  v29 = "%s: FTM Mode is active; nothing to do";
LABEL_4:
  qdf_trace_msg(0x33u, 8u, v29, v21, v22, v23, v24, v25, v26, v27, v28, "hdd_set_fw_params");
  result = 0;
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return result;
}
