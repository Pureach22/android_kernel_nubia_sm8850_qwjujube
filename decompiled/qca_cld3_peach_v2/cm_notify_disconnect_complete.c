__int64 __fastcall cm_notify_disconnect_complete(__int64 *a1, unsigned int *a2)
{
  __int64 v4; // x21
  _DWORD *v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x22
  __int64 v15; // x0

  mlme_cm_disconnect_complete_ind(*a1);
  mlo_sta_link_disconn_notify(*a1, a2);
  mlme_cm_osif_disconnect_complete(*a1, a2);
  v4 = *a1;
  v5 = (_DWORD *)_qdf_mem_malloc(0x38u, "cm_if_mgr_inform_disconnect_complete", 261);
  if ( v5 )
  {
    v14 = (__int64)v5;
    *v5 = 0;
    if_mgr_deliver_event(v4, 3u, (__int64)v5, v6, v7, v8, v9, v10, v11, v12, v13);
    _qdf_mem_free(v14);
  }
  v15 = *(_QWORD *)(*a1 + 216);
  if ( v15 )
    dlm_update_bssid_connect_params(v15, a2[4] | ((unsigned __int64)*((unsigned __int16 *)a2 + 10) << 32), 1);
  else
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev %d cm_id 0x%x: failed to find pdev",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "cm_inform_dlm_disconnect_complete",
      *(unsigned __int8 *)(*a1 + 168),
      *a2);
  return 0;
}
