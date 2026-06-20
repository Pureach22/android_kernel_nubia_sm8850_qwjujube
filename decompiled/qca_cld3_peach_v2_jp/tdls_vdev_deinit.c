__int64 __fastcall tdls_vdev_deinit(__int64 a1)
{
  qdf_mc_timer_stop_sync(a1 + 392);
  qdf_mc_timer_stop_sync(a1 + 560);
  qdf_mc_timer_destroy(a1 + 392);
  qdf_mc_timer_destroy(a1 + 560);
  _qdf_mem_free(*(_QWORD *)(a1 + 952));
  *(_QWORD *)(a1 + 952) = 0;
  tdls_peer_idle_timers_destroy(a1);
  return tdls_free_peer_list(a1);
}
