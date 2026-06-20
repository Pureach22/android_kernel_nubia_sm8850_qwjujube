__int64 __fastcall mlme_ext_handler_destroy(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x19
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x20
  __int64 v20; // x20

  if ( result )
  {
    v1 = *(_QWORD *)(result + 536);
    v2 = result;
    if ( v1 )
    {
      qdf_runtime_lock_deinit((__int64 *)(v1 + 24904));
      _qdf_wake_lock_destroy(*(_QWORD *)(v2 + 536) + 24704LL);
      qdf_runtime_lock_deinit((__int64 *)(*(_QWORD *)(v2 + 536) + 24912LL));
      qdf_runtime_lock_deinit((__int64 *)(*(_QWORD *)(v2 + 536) + 25136LL));
      _qdf_wake_lock_destroy(*(_QWORD *)(v2 + 536) + 24936LL);
      *(_DWORD *)(*(_QWORD *)(v2 + 536) + 25144LL) = 0;
      mlme_free_peer_disconnect_ies(*(_QWORD *)(v2 + 520), v3, v4, v5, v6, v7, v8, v9, v10);
      mlme_free_sae_auth_retry(*(_QWORD *)(v2 + 520), v11, v12, v13, v14, v15, v16, v17, v18);
      v19 = *(_QWORD *)(v2 + 536);
      qdf_mc_timer_stop(v19 + 24280);
      qdf_mc_timer_destroy(v19 + 24280);
      v20 = *(_QWORD *)(v2 + 536);
      _qdf_mem_free(*(_QWORD *)(v20 + 24080));
      _qdf_mem_free(*(_QWORD *)(v20 + 24064));
      *(_QWORD *)(v20 + 24064) = 0;
      *(_DWORD *)(v20 + 24072) = 0;
      *(_QWORD *)(v20 + 24080) = 0;
      mlme_cm_free_roam_stats_info(*(_QWORD *)(v2 + 536));
      result = _qdf_mem_free(*(_QWORD *)(v2 + 536));
      *(_QWORD *)(v2 + 536) = 0;
    }
  }
  return result;
}
