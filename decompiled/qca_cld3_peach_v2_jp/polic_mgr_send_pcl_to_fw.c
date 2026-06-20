__int64 __fastcall polic_mgr_send_pcl_to_fw(__int64 a1, int a2)
{
  __int64 context; // x20
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 *v14; // x21
  __int64 i; // x25
  __int64 result; // x0
  unsigned int v17; // w24
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  _DWORD *v26; // x8
  _DWORD *v27; // x8

  context = _cds_get_context(52, "polic_mgr_send_pcl_to_fw");
  v5 = policy_mgr_get_context(a1);
  if ( !v5 )
    return qdf_trace_msg(
             0x4Fu,
             2u,
             "%s: Invalid Context",
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             "polic_mgr_send_pcl_to_fw");
  v14 = (__int64 *)v5;
  for ( i = 0; i != 180; i += 36 )
  {
    qdf_mutex_acquire((__int64)(v14 + 7));
    if ( *(_DWORD *)((char *)&pm_conc_connection_list + i) || (*((_BYTE *)&pm_conc_connection_list + i + 28) & 1) == 0 )
    {
      result = qdf_mutex_release((__int64)(v14 + 7));
    }
    else
    {
      v17 = *((unsigned __int8 *)&pm_conc_connection_list + i + 24);
      qdf_mutex_release((__int64)(v14 + 7));
      if ( a2 == 1 && (wlan_cm_roaming_in_progress(v14[1], v17) & 1) != 0 )
      {
        result = qdf_trace_msg(
                   0x4Fu,
                   8u,
                   "%s: Roaming is in progress, don't stop RSO for vdev_id: %d",
                   v18,
                   v19,
                   v20,
                   v21,
                   v22,
                   v23,
                   v24,
                   v25,
                   "polic_mgr_send_pcl_to_fw",
                   v17);
      }
      else
      {
        v26 = (_DWORD *)v14[55];
        if ( *(v26 - 1) != 491867520 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD, __int64, __int64))v26)(context, v17, 48, 32);
        policy_mgr_set_pcl_for_existing_combo(*v14, 0, v17);
        v27 = (_DWORD *)v14[54];
        if ( *(v27 - 1) != 491867520 )
          __break(0x8228u);
        result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64))v27)(context, v17, 43, 32);
      }
    }
  }
  return result;
}
