__int64 __fastcall pre_cac_validate_and_get_freq(
        __int64 a1,
        unsigned int a2,
        unsigned int *a3,
        unsigned int next_lower_bandwidth)
{
  __int64 v8; // x23
  __int64 comp_private_obj; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x24
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  const char *v27; // x2
  __int64 result; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  int _5g_bonded_channel_state_for_pwrmode; // w21
  char is_channel_valid; // w0
  _BOOL8 v39; // x5
  unsigned __int64 i; // x22
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // [xsp+0h] [xbp-220h] BYREF
  __int64 v50; // [xsp+8h] [xbp-218h]
  unsigned int v51; // [xsp+10h] [xbp-210h] BYREF
  _BYTE v52[4]; // [xsp+14h] [xbp-20Ch] BYREF
  _DWORD s[102]; // [xsp+18h] [xbp-208h] BYREF
  _QWORD v54[14]; // [xsp+1B0h] [xbp-70h] BYREF

  v54[13] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 80);
  v51 = 100;
  memset(v54, 0, 102);
  memset(s, 0, sizeof(s));
  v49 = 0;
  v50 = 0;
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v8, 0x2Du);
  if ( comp_private_obj )
  {
    v18 = comp_private_obj;
    qdf_trace_msg(0x98u, 8u, "%s: flush pre_cac_work", v10, v11, v12, v13, v14, v15, v16, v17, "pre_cac_stop", v49, v50);
    if ( *(_QWORD *)(v18 + 32) )
      flush_work(v18);
  }
  else
  {
    qdf_trace_msg(
      0x98u,
      2u,
      "%s:%u: psoc_priv is NULL",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "pre_cac_stop",
      35,
      v49,
      v50);
  }
  v52[0] = 0;
  wlan_objmgr_iterate_obj_list(v8, 2, pre_cac_is_active_vdev_handler, (__int64)v52, 1, 0x60u);
  if ( v52[0] != 1 )
  {
    if ( a2 )
    {
      qdf_mem_set(&v49, 0x10u, 0);
      LODWORD(v49) = next_lower_bandwidth;
      if ( wlan_reg_is_5ghz_ch_freq(a2) )
      {
        _5g_bonded_channel_state_for_pwrmode = wlan_reg_get_5g_bonded_channel_state_for_pwrmode(
                                                 a1,
                                                 a2,
                                                 (unsigned int *)&v49,
                                                 0,
                                                 v29,
                                                 v30,
                                                 v31,
                                                 v32,
                                                 v33,
                                                 v34,
                                                 v35,
                                                 v36);
        is_channel_valid = wlan_mlme_is_channel_valid(v8, a2);
        v39 = _5g_bonded_channel_state_for_pwrmode == 2;
        if ( _5g_bonded_channel_state_for_pwrmode == 2 && (is_channel_valid & 1) != 0 )
        {
          *a3 = a2;
          goto LABEL_31;
        }
      }
      else
      {
        wlan_mlme_is_channel_valid(v8, a2);
        v39 = 0;
      }
      qdf_trace_msg(
        0x98u,
        2u,
        "%s: Invalid channel for pre cac:%d dfs %d",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "pre_cac_validate_and_get_freq",
        a2,
        v39);
      result = 4294967274LL;
      goto LABEL_32;
    }
    if ( (unsigned int)policy_mgr_get_valid_chans(v8, s, &v51) )
    {
      v27 = "%s: Failed to get channel list";
      goto LABEL_7;
    }
    policy_mgr_update_with_safe_channel_list(v8, s, &v51, v54, 0);
    if ( !v51 )
      goto LABEL_24;
LABEL_18:
    for ( i = 0; i < v51; ++i )
    {
      qdf_mem_set(&v49, 0x10u, 0);
      LODWORD(v49) = next_lower_bandwidth;
      if ( i == 102 )
        __break(0x5512u);
      if ( wlan_reg_is_5ghz_ch_freq(s[i])
        && (unsigned int)wlan_reg_get_5g_bonded_channel_state_for_pwrmode(
                           a1,
                           s[i],
                           (unsigned int *)&v49,
                           0,
                           v19,
                           v20,
                           v21,
                           v22,
                           v23,
                           v24,
                           v25,
                           v26) == 2 )
      {
        *a3 = s[i];
        break;
      }
    }
LABEL_24:
    while ( 1 )
    {
      a2 = *a3;
      if ( !next_lower_bandwidth || a2 )
        break;
      if ( (unsigned int)wlan_get_next_lower_bandwidth() == 8 )
      {
        a2 = *a3;
        break;
      }
      next_lower_bandwidth = wlan_get_next_lower_bandwidth();
      qdf_trace_msg(
        0x98u,
        8u,
        "%s: try next bw %d",
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        "pre_cac_validate_and_get_freq",
        next_lower_bandwidth);
      if ( v51 )
        goto LABEL_18;
    }
    if ( !a2 )
    {
      v27 = "%s: unable to find outdoor channel";
      goto LABEL_7;
    }
LABEL_31:
    qdf_trace_msg(
      0x98u,
      8u,
      "%s: selected pre cac channel:%d bw %d",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "pre_cac_validate_and_get_freq",
      a2,
      next_lower_bandwidth,
      v49);
    result = 0;
    goto LABEL_32;
  }
  v27 = "%s: pre cac is already in progress";
LABEL_7:
  qdf_trace_msg(0x98u, 2u, v27, v19, v20, v21, v22, v23, v24, v25, v26, "pre_cac_validate_and_get_freq", v49);
  result = 4294967274LL;
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return result;
}
