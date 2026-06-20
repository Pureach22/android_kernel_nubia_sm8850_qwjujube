__int64 __fastcall hif_close(__int64 a1)
{
  __int64 v2; // x0

  if ( !a1 )
    return qdf_trace_msg(61, 2, "%s: hif_opaque_softc is NULL", "hif_close");
  qdf_ssr_driver_dump_unregister_region("hif");
  hif_desc_history_log_unregister();
  hif_ce_desc_history_log_unregister();
  if ( *(_BYTE *)(a1 + 736) == 1 )
  {
    athdiag_procfs_remove();
    *(_BYTE *)(a1 + 736) = 0;
  }
  v2 = *(_QWORD *)(a1 + 32);
  if ( v2 )
  {
    *(_QWORD *)(a1 + 32) = "ErrUnloading";
    _qdf_mem_free(v2);
  }
  qdf_runtime_lock_deinit(a1 + 4000);
  hif_bus_close(a1);
  return _qdf_mem_free(a1);
}
