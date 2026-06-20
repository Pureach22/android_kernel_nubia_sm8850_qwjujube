__int64 __fastcall policy_mgr_ll_lt_sap_restart_concurrent_sap(__int64 a1, unsigned int a2)
{
  __int64 context; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 *v12; // x20
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x25
  __int64 v23; // x4
  __int64 v24; // x5
  const char *v25; // x2
  unsigned int *v26; // x21
  unsigned int v27; // w8
  unsigned int ll_lt_sap_restart_freq; // w23
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  int v38; // w22
  unsigned int v39; // w24
  __int64 v40; // x0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  void (__fastcall *v49)(__int64, __int64, __int64); // x8
  __int64 v50; // x0
  __int64 v51; // x1
  __int64 v52; // x2
  unsigned int v53; // w19
  __int64 v54; // x0
  unsigned int user_config_sap_freq; // w0
  unsigned int v56; // w22
  __int64 v57; // x0
  __int64 v58; // x28
  _DWORD *v59; // x22
  __int64 v60; // x27
  __int64 v61; // x22
  __int64 v62; // [xsp+0h] [xbp-2B0h]
  __int64 v63; // [xsp+8h] [xbp-2A8h]
  unsigned int v64; // [xsp+20h] [xbp-290h]
  unsigned int v65; // [xsp+24h] [xbp-28Ch]
  unsigned int v66; // [xsp+28h] [xbp-288h] BYREF
  unsigned int v67; // [xsp+2Ch] [xbp-284h] BYREF
  __int64 v68; // [xsp+30h] [xbp-280h]
  __int64 v69; // [xsp+38h] [xbp-278h]
  int v70; // [xsp+40h] [xbp-270h]
  unsigned int v71; // [xsp+44h] [xbp-26Ch] BYREF
  char v72[4]; // [xsp+48h] [xbp-268h] BYREF
  unsigned int v73; // [xsp+4Ch] [xbp-264h] BYREF
  _QWORD v74[22]; // [xsp+50h] [xbp-260h] BYREF
  int v75; // [xsp+100h] [xbp-1B0h]
  _DWORD s[102]; // [xsp+108h] [xbp-1A8h] BYREF
  __int64 v77; // [xsp+2A0h] [xbp-10h]

  v77 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v75 = 0;
  memset(v74, 0, sizeof(v74));
  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v12 = (__int64 *)context;
    qdf_mutex_acquire(context + 56);
    qdf_mem_copy(v74, &pm_conc_connection_list, 0xB4u);
    result = qdf_mutex_release((__int64)(v12 + 7));
    v22 = 0;
    v64 = a2;
    v65 = a2 - 1;
    while ( 1 )
    {
      v26 = (unsigned int *)v74 + 9 * v22;
      if ( *((_BYTE *)v26 + 28) != 1 )
        goto LABEL_5;
      v27 = *v26;
      if ( *v26 > 6 || ((1 << *v26) & 0x4A) == 0 )
        goto LABEL_5;
      v70 = 0;
      v69 = 0;
      v68 = 0;
      v66 = 16;
      if ( (v27 | 2) != 3 )
      {
        ll_lt_sap_restart_freq = wlan_get_ll_lt_sap_restart_freq(
                                   v12[1],
                                   v26[1],
                                   v26[6],
                                   (int *)&v66,
                                   v14,
                                   v15,
                                   v16,
                                   v17,
                                   v18,
                                   v19,
                                   v20,
                                   v21);
        goto LABEL_17;
      }
      result = policy_mgr_is_dynamic_sbs_enabled(*v12);
      if ( (result & 1) != 0 )
        goto LABEL_5;
      if ( v65 > 1 )
      {
        if ( a2 == 3 )
        {
          result = wlan_reg_is_24ghz_ch_freq(v26[1]);
          if ( (result & 1) == 0 )
            goto LABEL_5;
          v38 = 1;
          goto LABEL_24;
        }
      }
      else
      {
        result = wlan_reg_is_24ghz_ch_freq(v26[1]);
        if ( (result & 1) != 0 )
          goto LABEL_5;
      }
      v38 = 0;
LABEL_24:
      v39 = *v26;
      if ( *v26 == 3 )
      {
        if ( a2 == 2 )
          goto LABEL_5;
        if ( a2 == 1 )
        {
          result = policy_mgr_any_other_vdev_on_same_mac_as_freq(*v12, v26[1], v26[6]);
          if ( (result & 1) == 0 )
            goto LABEL_5;
          v39 = *v26;
        }
        else
        {
          v39 = 3;
        }
      }
      v53 = *((unsigned __int8 *)v26 + 24);
      ll_lt_sap_restart_freq = v26[1];
      v73 = 0;
      v72[0] = 0;
      memset(s, 0, sizeof(s));
      v54 = *v12;
      v71 = 0;
      policy_mgr_get_mcc_scc_switch(v54, v72);
      if ( !v38 )
      {
        v57 = _qdf_mem_malloc(0x204u, "policy_mgr_ll_lt_sap_get_restart_freq_for_concurent_sap", 228);
        if ( !v57 )
        {
          ll_lt_sap_restart_freq = 0;
          goto LABEL_17;
        }
        v58 = v57;
        v59 = (_DWORD *)(v57 + 512);
        if ( (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64, __int64, __int64, _QWORD))policy_mgr_get_pcl_for_vdev_id)(
                             *v12,
                             v39,
                             v58,
                             v58 + 512,
                             v58 + 408,
                             102,
                             v53)
          || !*v59 )
        {
          _qdf_mem_free(v58);
          goto LABEL_48;
        }
        v60 = 0;
        ll_lt_sap_restart_freq = 0;
        while ( 2 )
        {
          if ( v60 == 102 )
          {
LABEL_82:
            __break(0x5512u);
            __break(1u);
          }
          if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v58 + 4 * v60))
            && (((__int64 (__fastcall *)(__int64, _QWORD))policy_mgr_is_safe_channel)(
                  *v12,
                  *(unsigned int *)(v58 + 4 * v60))
              & 1) != 0 )
          {
            if ( ll_lt_sap_restart_freq )
            {
              if ( v39 != 1 )
              {
LABEL_63:
                if ( !policy_mgr_go_scc_enforced(*v12) )
                  goto LABEL_55;
              }
            }
            else
            {
              ll_lt_sap_restart_freq = *(_DWORD *)(v58 + 4 * v60);
              if ( v39 != 1 )
                goto LABEL_63;
            }
            if ( (unsigned int)policy_mgr_get_connection_count_with_ch_freq(*(_DWORD *)(v58 + 4 * v60)) )
            {
              ll_lt_sap_restart_freq = *(_DWORD *)(v58 + 4 * v60);
LABEL_78:
              _qdf_mem_free(v58);
              a2 = v64;
              if ( !ll_lt_sap_restart_freq )
              {
LABEL_48:
                if ( (unsigned int)policy_mgr_get_valid_chans(*v12, s, &v71) )
                {
                  qdf_trace_msg(
                    0x4Fu,
                    2u,
                    "%s: Error in getting valid channels",
                    v30,
                    v31,
                    v32,
                    v33,
                    v34,
                    v35,
                    v36,
                    v37,
                    "policy_mgr_ll_lt_sap_get_restart_freq_for_concurent_sap");
                  ll_lt_sap_restart_freq = 0;
                }
                else if ( v71 )
                {
                  v61 = 0;
                  while ( 1 )
                  {
                    if ( v61 == 102 )
                      goto LABEL_82;
                    a2 = v64;
                    if ( wlan_reg_is_24ghz_ch_freq(s[v61])
                      && (((__int64 (__fastcall *)(__int64, _QWORD))policy_mgr_is_safe_channel)(
                            *v12,
                            (unsigned int)s[v61])
                        & 1) != 0 )
                    {
                      break;
                    }
                    if ( v71 <= (unsigned int)++v61 )
                      goto LABEL_73;
                  }
                  ll_lt_sap_restart_freq = s[v61];
                  qdf_trace_msg(
                    0x4Fu,
                    8u,
                    "%s: vdev %d Selected first valid 2.4 Ghz freq %d",
                    v30,
                    v31,
                    v32,
                    v33,
                    v34,
                    v35,
                    v36,
                    v37,
                    "policy_mgr_ll_lt_sap_get_restart_freq_for_concurent_sap",
                    v53,
                    ll_lt_sap_restart_freq);
                }
                else
                {
LABEL_73:
                  ll_lt_sap_restart_freq = 0;
                }
              }
              goto LABEL_17;
            }
          }
LABEL_55:
          if ( *v59 <= (unsigned int)++v60 )
            goto LABEL_78;
          continue;
        }
      }
      user_config_sap_freq = policy_mgr_get_user_config_sap_freq(*v12, v53);
      if ( user_config_sap_freq != ll_lt_sap_restart_freq )
      {
        v56 = user_config_sap_freq;
        if ( v39 == 1 )
          goto LABEL_43;
        if ( v39 != 3 )
        {
          ll_lt_sap_restart_freq = user_config_sap_freq;
          goto LABEL_17;
        }
        if ( policy_mgr_go_scc_enforced(*v12) )
        {
LABEL_43:
          ((void (__fastcall *)(__int64, unsigned int *, _QWORD, _QWORD, _QWORD))policy_mgr_check_scc_channel)(
            *v12,
            &v73,
            v56,
            v53,
            (unsigned __int8)v72[0]);
          ll_lt_sap_restart_freq = v73;
          if ( !v73 )
            ll_lt_sap_restart_freq = v56;
        }
        else if ( (((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64, _QWORD, _QWORD))policy_mgr_allow_concurrency)(
                     *v12,
                     3,
                     v56,
                     3,
                     0,
                     v53)
                 & 1) != 0 )
        {
          ll_lt_sap_restart_freq = v56;
        }
        else
        {
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: vdev %d User freq %d not allowed, keep current freq %d",
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            "policy_mgr_ll_lt_sap_get_restart_freq_for_concurent_sap",
            v53,
            v56,
            ll_lt_sap_restart_freq);
        }
      }
LABEL_17:
      if ( ll_lt_sap_restart_freq )
      {
        if ( ll_lt_sap_restart_freq != v26[1] )
        {
          result = policy_mgr_is_chan_switch_in_progress(*v12);
          if ( (result & 1) == 0 )
          {
            v40 = v12[1];
            v67 = 9;
            wlan_reg_set_channel_params_for_pwrmode(
              v40,
              ll_lt_sap_restart_freq,
              0,
              (__int64)&v67,
              0,
              v14,
              v15,
              v16,
              v17,
              v18,
              v19,
              v20,
              v21);
            LODWORD(v63) = v67;
            LODWORD(v62) = ll_lt_sap_restart_freq;
            qdf_trace_msg(
              0x4Fu,
              8u,
              "%s: vdev %d event %d mode %d, %d -> %d, width %d",
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              "policy_mgr_ll_lt_sap_check_for_restart_sap_go",
              v26[6],
              a2,
              *v26,
              v26[1],
              v62,
              v63);
            v49 = (void (__fastcall *)(__int64, __int64, __int64))v12[42];
            if ( v49 )
            {
              v50 = *v12;
              v51 = v26[6];
              v52 = v66;
              if ( *((_DWORD *)v49 - 1) != -1125204353 )
                __break(0x8228u);
              v49(v50, v51, v52);
            }
            policy_mgr_change_sap_channel_with_csa(*v12, v26[6], ll_lt_sap_restart_freq, v67, 1);
            result = policy_mgr_is_chan_switch_in_progress(*v12);
            if ( (result & 1) != 0 )
            {
              result = policy_mgr_wait_chan_switch_complete_evt(*v12);
              if ( (_DWORD)result )
                result = qdf_trace_msg(
                           0x4Fu,
                           2u,
                           "%s: Vdev %d wait for csa event failed!!",
                           v14,
                           v15,
                           v16,
                           v17,
                           v18,
                           v19,
                           v20,
                           v21,
                           "policy_mgr_ll_lt_sap_check_for_restart_sap_go",
                           v26[6]);
            }
          }
          goto LABEL_5;
        }
        v23 = v26[6];
        v25 = "%s: vdev %d restart freq %d same as current freq";
        v24 = ll_lt_sap_restart_freq;
      }
      else
      {
        v23 = v26[6];
        v24 = v26[1];
        v25 = "%s: vdev %d Restart freq not found, curr freq %d";
      }
      result = qdf_trace_msg(
                 0x4Fu,
                 8u,
                 v25,
                 v30,
                 v31,
                 v32,
                 v33,
                 v34,
                 v35,
                 v36,
                 v37,
                 "policy_mgr_ll_lt_sap_check_for_restart_sap_go",
                 v23,
                 v24);
LABEL_5:
      if ( ++v22 == 5 )
        goto LABEL_81;
    }
  }
  result = qdf_trace_msg(
             0x4Fu,
             2u,
             "%s: Invalid pm context",
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             "policy_mgr_ll_lt_sap_restart_concurrent_sap");
LABEL_81:
  _ReadStatusReg(SP_EL0);
  return result;
}
