__int64 __fastcall policy_mgr_incr_active_session(__int64 a1, unsigned int a2, unsigned int a3, char a4)
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
  __int64 v17; // x19
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x25
  _DWORD *v27; // x8
  __int64 v28; // x2
  void (__fastcall *v29)(_QWORD); // x8
  int v30; // w24
  __int64 result; // x0
  int v32; // w0
  void (__fastcall *v33)(_QWORD); // x8
  int v34; // w23
  int v35; // w23
  void (__fastcall *v36)(_QWORD); // x8
  int v37; // w23
  void (__fastcall *v38)(_QWORD); // x8
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 (__fastcall *v55)(_QWORD); // x8
  unsigned int v56; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v57; // [xsp+8h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v56 = 0;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    result = qdf_trace_msg(
               0x4Fu,
               2u,
               "%s: Invalid Context",
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               v15,
               v16,
               "policy_mgr_incr_active_session");
    goto LABEL_52;
  }
  v17 = context;
  qdf_mutex_acquire(context + 56);
  v26 = v17 + a2;
  if ( a2 <= 0x10 && ((1 << a2) & 0x1080F) != 0 )
  {
    ++*(_BYTE *)(v26 + 989);
    if ( a2 == 16 )
      goto LABEL_19;
    if ( a2 == 11 )
    {
      v27 = *(_DWORD **)(v17 + 352);
      if ( v27 )
      {
        v28 = *(unsigned __int8 *)(v17 + 1000);
        if ( *(v27 - 1) != -1125204353 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD, __int64))v27)(a1, a3, v28);
      }
    }
  }
  v29 = *(void (__fastcall **)(_QWORD))(v17 + 512);
  if ( v29 && (a4 & 1) != 0 )
  {
    if ( *((_DWORD *)v29 - 1) != 1162514891 )
      __break(0x8228u);
    v29((unsigned __int8)a3);
  }
  if ( (a2 & 0xFFFFFFFD) == 1 )
  {
    policy_mgr_get_ap_6ghz_capable(a1, a3, &v56);
    v30 = 1;
    goto LABEL_20;
  }
  if ( a2 > 0x10 )
  {
    __break(0x5512u);
    JUMPOUT(0x6A8F000);
  }
LABEL_19:
  v30 = 0;
LABEL_20:
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: No.# of active sessions for mode %d = %d",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    "policy_mgr_incr_active_session",
    a2,
    *(unsigned __int8 *)(v26 + 989));
  policy_mgr_incr_connection_count(a1, (unsigned __int8)a3, a2);
  v32 = policy_mgr_mode_specific_connection_count(a1, 0, nullptr);
  if ( a2 && v32 )
  {
    qdf_mutex_release(v17 + 56);
    polic_mgr_send_pcl_to_fw(a1, a2);
    qdf_mutex_acquire(v17 + 56);
  }
  v33 = *(void (__fastcall **)(_QWORD))(v17 + 464);
  if ( v33 )
  {
    if ( *((_DWORD *)v33 - 1) != 1588979751 )
      __break(0x8228u);
    v33(a1);
  }
  if ( (unsigned int)policy_mgr_mode_specific_connection_count(a1, 0, nullptr) > 1
    || (v34 = policy_mgr_mode_specific_connection_count(a1, 1, nullptr),
        v35 = policy_mgr_mode_specific_connection_count(a1, 6, nullptr) + v34,
        v35 + (unsigned int)policy_mgr_mode_specific_connection_count(a1, 3, nullptr))
    || (unsigned int)policy_mgr_mode_specific_connection_count(a1, 2, nullptr)
    || (unsigned int)policy_mgr_mode_specific_connection_count(a1, 4, nullptr) )
  {
    v36 = *(void (__fastcall **)(_QWORD))(v17 + 488);
    if ( v36 )
    {
      if ( *((_DWORD *)v36 - 1) != -1560483463 )
        __break(0x8228u);
      v36(1);
    }
  }
  v37 = policy_mgr_mode_specific_connection_count(a1, 1, nullptr);
  if ( (unsigned int)policy_mgr_mode_specific_connection_count(a1, 6, nullptr) + v37 == 1 )
  {
    v38 = *(void (__fastcall **)(_QWORD))(v17 + 496);
    if ( v38 )
    {
      if ( *((_DWORD *)v38 - 1) != -1560483463 )
        __break(0x8228u);
      v38(1);
    }
  }
  if ( v30 )
    policy_mgr_init_ap_6ghz_capable(a1, a3, v56);
  if ( a2 <= 3 )
    policy_mgr_update_dfs_master_dynamic_enabled(a1, 0, nullptr);
  policy_mgr_dump_current_concurrency(a1);
  if ( (policy_mgr_update_indoor_concurrency(a1, a3, 0, 0) & 1) != 0 )
    wlan_reg_recompute_current_chan_list(a1, *(_QWORD *)(v17 + 8), v39, v40, v41, v42, v43, v44, v45, v46);
  qdf_mutex_release(v17 + 56);
  result = wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(v17 + 8), a3);
  if ( !a2 )
  {
    result = wlan_reg_is_dfs_for_freq(*(_QWORD *)(v17 + 8), result, v47, v48, v49, v50, v51, v52, v53, v54);
    if ( (result & 1) != 0 )
    {
      v55 = *(__int64 (__fastcall **)(_QWORD))(v17 + 544);
      if ( v55 )
      {
        if ( *((_DWORD *)v55 - 1) != -1560483463 )
          __break(0x8228u);
        result = v55(1);
      }
    }
  }
LABEL_52:
  _ReadStatusReg(SP_EL0);
  return result;
}
