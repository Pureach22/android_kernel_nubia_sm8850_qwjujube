__int64 __fastcall _policy_mgr_is_ll_lt_sap_restart_required(__int64 a1, __int64 a2)
{
  __int64 context; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x22
  __int64 result; // x0
  unsigned int v15; // w20
  __int64 *v16; // x8
  unsigned int v17; // w23
  unsigned __int8 ll_lt_sap_vdev_id; // w0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x22

  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid pm ctx",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "__policy_mgr_is_ll_lt_sap_restart_required");
    return 0;
  }
  v13 = context;
  result = policy_mgr_get_ll_lt_sap_freq(a1);
  if ( !(_DWORD)result )
    return result;
  v15 = result;
  qdf_mutex_acquire(v13 + 56);
  v16 = &pm_conc_connection_list;
  if ( (_DWORD)pm_conc_connection_list == 6 || v15 != HIDWORD(pm_conc_connection_list) )
  {
    v16 = &qword_81C464;
    if ( (_DWORD)qword_81C464 == 6 || v15 != HIDWORD(qword_81C464) )
    {
      v16 = &qword_81C488;
      if ( (_DWORD)qword_81C488 == 6 || v15 != HIDWORD(qword_81C488) )
      {
        v16 = &qword_81C4AC;
        if ( (_DWORD)qword_81C4AC == 6 || v15 != HIDWORD(qword_81C4AC) )
        {
          v16 = &qword_81C4D0;
          if ( (_DWORD)qword_81C4D0 == 6 || v15 != HIDWORD(qword_81C4D0) )
          {
            qdf_mutex_release(v13 + 56);
            return 0;
          }
        }
      }
    }
  }
  v17 = *((unsigned __int8 *)v16 + 24);
  qdf_mutex_release(v13 + 56);
  ll_lt_sap_vdev_id = wlan_policy_mgr_get_ll_lt_sap_vdev_id(a1);
  v27 = jiffies;
  if ( _policy_mgr_is_ll_lt_sap_restart_required___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s ll_lt_sap vdev %d with freq %d is in scc with vdev %d",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      a2,
      ll_lt_sap_vdev_id,
      v15,
      v17);
    _policy_mgr_is_ll_lt_sap_restart_required___last_ticks = v27;
  }
  return 1;
}
