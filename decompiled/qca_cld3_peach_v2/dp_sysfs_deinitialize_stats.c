__int64 __fastcall dp_sysfs_deinitialize_stats(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  if ( !a1 )
    return qdf_trace_msg(
             0x89u,
             2u,
             "%s: %pK: soc_hdl is NULL",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "dp_sysfs_deinitialize_stats",
             0);
  v10 = *(_QWORD *)(a1 + 17584);
  if ( !v10 )
    return qdf_trace_msg(
             0x89u,
             2u,
             "%s: soc->sysfs_config is NULL",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "dp_sysfs_deinitialize_stats");
  if ( (unsigned int)qdf_event_destroy(v10 + 96, a2) )
    qdf_trace_msg(
      0x89u,
      2u,
      "%s: Failed to destroy event sysfs_txrx_fw_request_done",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "dp_sysfs_deinitialize_stats");
  qdf_mutex_destroy(*(_QWORD *)(a1 + 17584) + 16LL);
  return _qdf_mem_free(*(_QWORD *)(a1 + 17584));
}
