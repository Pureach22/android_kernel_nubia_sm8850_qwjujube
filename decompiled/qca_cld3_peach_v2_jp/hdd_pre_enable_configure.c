__int64 __fastcall hdd_pre_enable_configure(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x20
  __int64 v20; // x8
  void (*v21)(void); // x8
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // w0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int v39; // w20
  const char *v40; // x2
  unsigned int v41; // w1
  unsigned int v42; // w0
  __int64 result; // x0
  unsigned int tx_chainmask_1ss; // w0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // x0
  __int64 v54; // x0
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  int v63; // w21
  int v64; // w9
  __int64 v65; // x0
  _DWORD *v66; // x8
  int v67; // w20
  _DWORD *v68; // x8
  int v69; // w9
  int v70; // w9
  _DWORD *v71; // x8
  int v72; // w9
  _DWORD *v73; // x8
  unsigned int v74; // w0
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  unsigned int v83; // w19
  unsigned int inited; // w0
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  _BYTE v93[4]; // [xsp+4h] [xbp-5Ch] BYREF
  int v94; // [xsp+8h] [xbp-58h] BYREF
  _BYTE v95[4]; // [xsp+Ch] [xbp-54h] BYREF
  char v96[4]; // [xsp+10h] [xbp-50h] BYREF
  _BYTE v97[4]; // [xsp+14h] [xbp-4Ch] BYREF
  _DWORD v98[4]; // [xsp+18h] [xbp-48h] BYREF
  __int64 v99; // [xsp+28h] [xbp-38h]
  __int64 v100; // [xsp+30h] [xbp-30h]
  __int64 v101; // [xsp+38h] [xbp-28h]
  __int64 v102; // [xsp+40h] [xbp-20h]
  __int64 v103; // [xsp+48h] [xbp-18h]
  __int64 v104; // [xsp+50h] [xbp-10h]
  __int64 v105; // [xsp+58h] [xbp-8h]

  v105 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v97[0] = 0;
  v96[0] = 0;
  v95[0] = 0;
  v94 = 0;
  context = _cds_get_context(71, (__int64)"hdd_pre_enable_configure", a2, a3, a4, a5, a6, a7, a8, a9);
  v19 = (__int64)context;
  v103 = 0;
  v104 = 0;
  v101 = 0;
  v102 = 0;
  v99 = 0;
  v100 = 0;
  v93[0] = 0;
  if ( context && *context )
  {
    v20 = *(_QWORD *)(*context + 112LL);
    if ( v20 )
    {
      v21 = *(void (**)(void))(v20 + 16);
      if ( v21 )
      {
        if ( *((_DWORD *)v21 - 1) != 436699132 )
          __break(0x8228u);
        v21();
      }
    }
  }
  else
  {
    qdf_trace_msg(0x89u, 8u, "%s: invalid instance", v11, v12, v13, v14, v15, v16, v17, v18, "cdp_register_pause_cb");
  }
  v22 = hdd_tx_latency_register_cb(v19);
  ucfg_dp_register_rx_mic_error_ind_handler(v19, v22, v23, v24, v25, v26, v27, v28, v29);
  v30 = hdd_set_sme_config(a1);
  if ( v30 )
  {
    v39 = v30;
    v40 = "%s: Failed hdd_set_sme_config: %d";
LABEL_11:
    v41 = 2;
LABEL_14:
    qdf_trace_msg(0x33u, v41, v40, v31, v32, v33, v34, v35, v36, v37, v38, "hdd_pre_enable_configure", v39);
LABEL_15:
    result = qdf_status_to_os_return(v39);
    goto LABEL_16;
  }
  v42 = hdd_set_policy_mgr_user_cfg(a1);
  if ( v42 )
  {
    v39 = v42;
    v40 = "%s: Failed hdd_set_policy_mgr_user_cfg: %d";
    v41 = 1;
    goto LABEL_14;
  }
  tx_chainmask_1ss = wlan_mlme_get_tx_chainmask_1ss(*a1, v97);
  if ( tx_chainmask_1ss )
  {
    v39 = tx_chainmask_1ss;
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Get tx_chainmask_1ss from mlme failed",
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      "hdd_pre_enable_configure");
    goto LABEL_15;
  }
  v53 = *a1;
  v98[0] = 77;
  v98[1] = v97[0];
  wlan_mlme_get_mgmt_max_retry(v53, v96);
  v54 = *a1;
  v98[2] = 109;
  v98[3] = (unsigned __int8)v96[0];
  wlan_mlme_get_mgmt_6ghz_rate_support(v54, v95);
  if ( v95[0] == 1 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: HE rates for 6GHz mgmt frames are supported",
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      "hdd_pre_enable_configure");
    v63 = 3;
    v99 = 0x400000000C0LL;
  }
  else
  {
    v63 = 2;
  }
  wlan_mlme_get_tx_retry_multiplier(*a1, &v94);
  v64 = v94;
  v65 = *a1;
  v66 = &v98[2 * v63];
  v67 = v63 + 1;
  *v66 = 213;
  v66[1] = v64;
  if ( !(unsigned int)ucfg_get_smart_chainmask_enabled(v65, v93) )
  {
    v68 = &v98[2 * v67];
    v69 = v93[0];
    v67 = v63 + 2;
    *v68 = 144;
    v68[1] = v69;
  }
  if ( !(unsigned int)ucfg_get_alternative_chainmask_enabled(*a1, v93) )
  {
    v70 = v93[0];
    v71 = &v98[2 * v67++];
    *v71 = 145;
    v71[1] = v70;
  }
  if ( !(unsigned int)ucfg_fwol_get_ani_enabled(*a1, v93) )
  {
    v72 = v93[0];
    v73 = &v98[2 * v67++];
    *v73 = 37;
    v73[1] = v72;
  }
  result = hdd_set_pcie_params(a1, v67, v98);
  if ( !(_DWORD)result )
  {
    v74 = sme_send_multi_pdev_vdev_set_params(result, 0, v98, (unsigned int)(v67 + 1));
    if ( v74 )
    {
      v83 = v74;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: failed to send pdev set params",
        v75,
        v76,
        v77,
        v78,
        v79,
        v80,
        v81,
        v82,
        "hdd_pre_enable_configure");
      result = v83;
      goto LABEL_16;
    }
    result = ucfg_fwol_configure_global_params(*a1, a1[1]);
    if ( (_DWORD)result )
      goto LABEL_16;
    inited = sme_init_chan_list(a1[2], *((unsigned int *)a1 + 158));
    if ( inited )
    {
      v39 = inited;
      v40 = "%s: Failed to init channel list: %d";
      goto LABEL_11;
    }
    if ( hdd_update_config_cfg() )
    {
      hdd_init_channel_avoidance(a1);
      result = 0;
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: config update failed",
        v85,
        v86,
        v87,
        v88,
        v89,
        v90,
        v91,
        v92,
        "hdd_pre_enable_configure");
      result = 4294967274LL;
    }
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
