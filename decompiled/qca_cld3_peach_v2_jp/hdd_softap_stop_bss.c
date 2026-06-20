__int64 __fastcall hdd_softap_stop_bss(__int64 a1)
{
  __int64 v2; // x20
  __int64 *v3; // x21
  unsigned int indoor_chnl_marking; // w19
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned __int64 StatusReg; // x8
  __int64 v14; // x8
  __int64 updated; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned __int64 v24; // x26
  __int64 v25; // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w20
  __int64 values; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v45; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v46[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v47; // [xsp+18h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)a1;
  v45 = 0;
  v46[0] = 0;
  v3 = *(__int64 **)(v2 + 24);
  indoor_chnl_marking = ucfg_policy_mgr_get_indoor_chnl_marking(*v3, v46);
  if ( indoor_chnl_marking )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: can't get indoor channel marking, using default",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "hdd_softap_stop_bss");
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v2 + 38872);
  }
  else
  {
    raw_spin_lock_bh(v2 + 38872);
    *(_QWORD *)(v2 + 38880) |= 1uLL;
  }
  hdd_get_front_sta_info_no_lock(v2 + 38848, &v45);
  if ( v45 )
    hdd_take_sta_info_ref(v2 + 38848, v45, 0, 25);
  hdd_get_next_sta_info_no_lock(v2 + 38848);
  v14 = *(_QWORD *)(v2 + 38880);
  if ( (v14 & 1) != 0 )
  {
    *(_QWORD *)(v2 + 38880) = v14 & 0xFFFFFFFFFFFFFFFELL;
    updated = raw_spin_unlock_bh(v2 + 38872);
    if ( !v45 )
      goto LABEL_23;
  }
  else
  {
    updated = raw_spin_unlock(v2 + 38872);
    if ( !v45 )
      goto LABEL_23;
  }
  v24 = _ReadStatusReg(SP_EL0);
  do
  {
    while ( 1 )
    {
      indoor_chnl_marking = hdd_softap_deregister_sta(v2, &v45, v16, v17, v18, v19, v20, v21, v22, v23);
      hdd_put_sta_info_ref(v2 + 38848, &v45, 1, 25);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(v24 + 16) & 0xF0000) != 0
        || (*(_DWORD *)(v24 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v2 + 38872);
      }
      else
      {
        raw_spin_lock_bh(v2 + 38872);
        *(_QWORD *)(v2 + 38880) |= 1uLL;
      }
      v45 = 0;
      hdd_get_next_sta_info_no_lock(v2 + 38848);
      v25 = *(_QWORD *)(v2 + 38880);
      if ( (v25 & 1) != 0 )
        break;
      updated = raw_spin_unlock(v2 + 38872);
      if ( !v45 )
        goto LABEL_23;
    }
    *(_QWORD *)(v2 + 38880) = v25 & 0xFFFFFFFFFFFFFFFELL;
    updated = raw_spin_unlock_bh(v2 + 38872);
  }
  while ( v45 );
LABEL_23:
  if ( *(_DWORD *)(v2 + 40) == 1 && (*(_BYTE *)(v3[13] + 17) & 1) == 0 )
    updated = wlan_hdd_restore_channels(v3, v16, v17, v18, v19, v20, v21, v22, v23);
  if ( v46[0] && *(_DWORD *)(v2 + 40) == 1 )
  {
    hdd_update_indoor_channel(v3, 0, v16, v17, v18, v19, v20, v21, v22, v23);
    updated = sme_update_channel_list(v3[2]);
  }
  if ( (ucfg_ipa_is_enabled(updated) & 1) != 0
    && (unsigned int)ucfg_ipa_wlan_evt(
                       v3[1],
                       *(_QWORD *)(v2 + 32),
                       *(unsigned int *)(v2 + 40),
                       *(unsigned __int8 *)(a1 + 8),
                       3,
                       *(_QWORD *)(*(_QWORD *)(v2 + 32) + 1008LL),
                       0) )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: WLAN_AP_DISCONNECT event failed",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "hdd_softap_stop_bss");
  }
  v34 = *(unsigned __int8 *)(*(_QWORD *)(v2 + 52824) + 8LL);
  values = cfg_psoc_get_values(*v3);
  if ( (unsigned int)sme_cli_set_command(v34, 44, *(unsigned int *)(values + 1192), 1) )
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Failed to set RTS_PROFILE",
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      "hdd_softap_stop_bss");
  _ReadStatusReg(SP_EL0);
  return indoor_chnl_marking;
}
