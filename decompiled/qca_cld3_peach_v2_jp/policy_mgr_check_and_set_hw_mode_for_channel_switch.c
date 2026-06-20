__int64 __fastcall policy_mgr_check_and_set_hw_mode_for_channel_switch(
        __int64 a1,
        unsigned __int8 a2,
        unsigned int a3,
        unsigned int a4)
{
  __int64 context; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x22
  __int64 v18; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  const char *v36; // x2
  const char *v37; // x3
  __int64 result; // x0
  unsigned int v39; // w23
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x0
  __int64 v49; // x20
  bool v50; // [xsp+4h] [xbp-3Ch] BYREF
  unsigned int v51; // [xsp+8h] [xbp-38h] BYREF
  _BYTE v52[4]; // [xsp+Ch] [xbp-34h] BYREF
  _QWORD v53[4]; // [xsp+10h] [xbp-30h] BYREF
  int v54; // [xsp+30h] [xbp-10h]
  int v55; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v56; // [xsp+38h] [xbp-8h]

  v56 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v54 = 0;
  memset(v53, 0, sizeof(v53));
  v52[0] = 0;
  v51 = 0;
  v50 = 0;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v36 = "%s: Invalid context";
    v37 = "policy_mgr_check_and_set_hw_mode_for_channel_switch";
    goto LABEL_14;
  }
  v17 = context;
  wlan_psoc_mlme_get_11be_capab(a1, &v50);
  if ( v50 && (unsigned int)policy_mgr_mode_specific_connection_count(a1, 1, 0) == 1 )
  {
    v18 = policy_mgr_get_context(a1);
    if ( v18 )
    {
      if ( *(_DWORD *)(v18 + 268) == 21 )
        qdf_mc_timer_stop(v18 + 120);
    }
    else
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Invalid context",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "policy_mgr_stop_opportunistic_timer");
    }
  }
  else
  {
    if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) == 0
      || (policy_mgr_is_hw_dbs_2x2_capable(a1) & 1) == 0 && (policy_mgr_is_hw_dbs_required_for_band(a1, 1) & 1) == 0 )
    {
      goto LABEL_31;
    }
    v27 = policy_mgr_get_context(a1);
    if ( v27 )
    {
      if ( *(_DWORD *)(v27 + 268) == 21 )
        qdf_mc_timer_stop(v27 + 120);
    }
    else
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Invalid context",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "policy_mgr_stop_opportunistic_timer");
    }
    if ( (unsigned int)wlan_reg_freq_to_band(a3) )
      goto LABEL_31;
  }
  qdf_mutex_acquire(v17 + 56);
  ((void (__fastcall *)(__int64, _QWORD, _QWORD *, _BYTE *))policy_mgr_store_and_del_conn_info_by_vdev_id)(
    a1,
    a2,
    v53,
    v52);
  v39 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, unsigned int *))policy_mgr_get_next_action)(
          a1,
          a2,
          a3,
          a4,
          &v51);
  if ( v52[0] )
    policy_mgr_restore_deleted_conn_info(a1, v53);
  qdf_mutex_release(v17 + 56);
  result = v39;
  if ( !v39 )
  {
    if ( v51 )
    {
      result = policy_mgr_next_actions(a1, a2, v51, a4, 0);
      if ( (_DWORD)result != 16 )
        goto LABEL_32;
      goto LABEL_27;
    }
LABEL_31:
    result = 11;
    goto LABEL_32;
  }
  if ( v39 != 16 )
    goto LABEL_32;
LABEL_27:
  qdf_trace_msg(
    0x4Fu,
    2u,
    "%s: Failed to update HW modeStatus %d",
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    "policy_mgr_check_and_set_hw_mode_for_channel_switch",
    16);
  v55 = 0;
  v48 = policy_mgr_get_context(a1);
  if ( v48 )
  {
    v49 = v48;
    if ( !(unsigned int)policy_mgr_need_opportunistic_upgrade(a1, &v55) )
      goto LABEL_15;
    qdf_mc_timer_stop(v49 + 120);
    if ( !(unsigned int)qdf_mc_timer_start(v49 + 120, 0x1388u) )
      goto LABEL_15;
    v36 = "%s: Failed to start dbs opportunistic timer";
  }
  else
  {
    v36 = "%s: PM ctx not valid. Oppurtunistic timer cannot start";
  }
  v37 = "policy_mgr_check_n_start_opportunistic_timer";
LABEL_14:
  qdf_trace_msg(0x4Fu, 2u, v36, v9, v10, v11, v12, v13, v14, v15, v16, v37);
LABEL_15:
  result = 16;
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return result;
}
