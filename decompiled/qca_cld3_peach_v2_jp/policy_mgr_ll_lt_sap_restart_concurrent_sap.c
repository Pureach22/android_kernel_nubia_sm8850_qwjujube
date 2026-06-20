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
  unsigned int v53; // w27
  __int64 v54; // x0
  unsigned int user_config_sap_freq; // w0
  unsigned int v56; // w22
  __int64 v57; // x0
  __int64 v58; // x28
  _DWORD *v59; // x22
  __int64 v60; // x26
  __int64 v61; // x22
  __int64 v62; // [xsp+0h] [xbp-2A0h]
  __int64 v63; // [xsp+8h] [xbp-298h]
  unsigned int v64; // [xsp+18h] [xbp-288h]
  unsigned int v65; // [xsp+1Ch] [xbp-284h]
  unsigned int v66; // [xsp+20h] [xbp-280h] BYREF
  unsigned int v67; // [xsp+24h] [xbp-27Ch] BYREF
  __int64 v68; // [xsp+28h] [xbp-278h]
  int v69; // [xsp+30h] [xbp-270h]
  unsigned int v70; // [xsp+34h] [xbp-26Ch] BYREF
  char v71[4]; // [xsp+38h] [xbp-268h] BYREF
  unsigned int v72; // [xsp+3Ch] [xbp-264h] BYREF
  _QWORD v73[22]; // [xsp+40h] [xbp-260h] BYREF
  int v74; // [xsp+F0h] [xbp-1B0h]
  _DWORD s[102]; // [xsp+F8h] [xbp-1A8h] BYREF
  __int64 v76; // [xsp+290h] [xbp-10h]

  v76 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v74 = 0;
  memset(v73, 0, sizeof(v73));
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
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
    goto LABEL_80;
  }
  v12 = (__int64 *)context;
  qdf_mutex_acquire(context + 56);
  qdf_mem_copy(v73, &pm_conc_connection_list, 0xB4u);
  result = qdf_mutex_release((__int64)(v12 + 7));
  v22 = 0;
  v64 = a2;
  v65 = a2 - 1;
  while ( 2 )
  {
    v26 = (unsigned int *)v73 + 9 * v22;
    if ( *((_BYTE *)v26 + 28) != 1 )
      goto LABEL_5;
    v27 = *v26;
    if ( *v26 > 6 || ((1 << *v26) & 0x4A) == 0 )
      goto LABEL_5;
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
    v72 = 0;
    v71[0] = 0;
    memset(s, 0, sizeof(s));
    v54 = *v12;
    v70 = 0;
    policy_mgr_get_mcc_scc_switch(v54, v71);
    if ( v38 )
    {
      user_config_sap_freq = policy_mgr_get_user_config_sap_freq(*v12, v53);
      if ( user_config_sap_freq == ll_lt_sap_restart_freq )
        goto LABEL_17;
      v56 = user_config_sap_freq;
      if ( v39 == 1 )
        goto LABEL_43;
      if ( v39 == 3 )
      {
        if ( policy_mgr_go_scc_enforced(*v12) )
        {
LABEL_43:
          ((void (__fastcall *)(__int64, unsigned int *, _QWORD, _QWORD, _QWORD))policy_mgr_check_scc_channel)(
            *v12,
            &v72,
            v56,
            v53,
            (unsigned __int8)v71[0]);
          ll_lt_sap_restart_freq = v72;
          if ( !v72 )
            ll_lt_sap_restart_freq = v56;
          goto LABEL_17;
        }
        if ( (((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64, _QWORD, _QWORD))policy_mgr_allow_concurrency)(
                *v12,
                3,
                v56,
                3,
                0,
                v53)
            & 1) == 0 )
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
          goto LABEL_17;
        }
      }
      ll_lt_sap_restart_freq = v56;
      goto LABEL_17;
    }
    v57 = _qdf_mem_malloc(0x204u, "policy_mgr_ll_lt_sap_get_restart_freq_for_concurent_sap", 228);
    if ( !v57 )
    {
      ll_lt_sap_restart_freq = 0;
      goto LABEL_17;
    }
    v58 = v57;
    v59 = (_DWORD *)(v57 + 512);
    if ( (unsigned int)policy_mgr_get_pcl_for_vdev_id(
                         *v12,
                         v39,
                         v58,
                         (_DWORD *)(v58 + 512),
                         v58 + 408,
                         0x66u,
                         v53,
                         v30,
                         v31,
                         v32,
                         v33,
                         v34,
                         v35,
                         v36,
                         v37)
      || !*v59 )
    {
      _qdf_mem_free(v58);
      goto LABEL_48;
    }
    v60 = 0;
    ll_lt_sap_restart_freq = 0;
    while ( 1 )
    {
      if ( v60 == 102 )
      {
LABEL_81:
        __break(0x5512u);
        __break(1u);
      }
      if ( !wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v58 + 4 * v60))
        || (((__int64 (__fastcall *)(__int64, _QWORD))policy_mgr_is_safe_channel)(
              *v12,
              *(unsigned int *)(v58 + 4 * v60))
          & 1) == 0 )
      {
        goto LABEL_55;
      }
      if ( ll_lt_sap_restart_freq )
      {
        if ( v39 == 1 )
          goto LABEL_54;
      }
      else
      {
        ll_lt_sap_restart_freq = *(_DWORD *)(v58 + 4 * v60);
        if ( v39 == 1 )
          goto LABEL_54;
      }
      if ( !policy_mgr_go_scc_enforced(*v12) )
        goto LABEL_55;
LABEL_54:
      if ( (unsigned int)policy_mgr_get_connection_count_with_ch_freq(*(_DWORD *)(v58 + 4 * v60)) )
        break;
LABEL_55:
      if ( *v59 <= (unsigned int)++v60 )
        goto LABEL_77;
    }
    ll_lt_sap_restart_freq = *(_DWORD *)(v58 + 4 * v60);
LABEL_77:
    _qdf_mem_free(v58);
    a2 = v64;
    if ( !ll_lt_sap_restart_freq )
    {
LABEL_48:
      if ( (unsigned int)policy_mgr_get_valid_chans(*v12, s, &v70) )
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
      else if ( v70 )
      {
        v61 = 0;
        while ( 1 )
        {
          if ( v61 == 102 )
            goto LABEL_81;
          a2 = v64;
          if ( wlan_reg_is_24ghz_ch_freq(s[v61])
            && (((__int64 (__fastcall *)(__int64, _QWORD))policy_mgr_is_safe_channel)(*v12, (unsigned int)s[v61]) & 1) != 0 )
          {
            break;
          }
          if ( v70 <= (unsigned int)++v61 )
            goto LABEL_72;
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
LABEL_72:
        ll_lt_sap_restart_freq = 0;
      }
    }
LABEL_17:
    if ( !ll_lt_sap_restart_freq )
    {
      v23 = v26[6];
      v24 = v26[1];
      v25 = "%s: vdev %d Restart freq not found, curr freq %d";
      goto LABEL_4;
    }
    if ( ll_lt_sap_restart_freq == v26[1] )
    {
      v23 = v26[6];
      v25 = "%s: vdev %d restart freq %d same as current freq";
      v24 = ll_lt_sap_restart_freq;
LABEL_4:
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
    }
    else
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
    }
LABEL_5:
    if ( ++v22 != 5 )
      continue;
    break;
  }
LABEL_80:
  _ReadStatusReg(SP_EL0);
  return result;
}
