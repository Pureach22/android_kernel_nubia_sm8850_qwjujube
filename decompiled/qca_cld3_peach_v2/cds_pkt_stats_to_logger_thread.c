unsigned __int16 *__fastcall cds_pkt_stats_to_logger_thread(
        unsigned __int16 *result,
        _BYTE *a2,
        const void *a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x8
  unsigned __int16 *v13; // x20
  _BYTE *v14; // x21
  const void *v15; // x22

  v12 = gp_cds_context;
  if ( !gp_cds_context )
  {
    v13 = result;
    v14 = a2;
    v15 = a3;
    printk(&unk_A3062F, "cds_get_global_context", a3, a4);
    v12 = gp_cds_context;
    result = v13;
    a2 = v14;
    a3 = v15;
    if ( !gp_cds_context )
      return (unsigned __int16 *)qdf_trace_msg(
                                   0x38u,
                                   2u,
                                   "%s: cds context is Invalid",
                                   a5,
                                   a6,
                                   a7,
                                   a8,
                                   a9,
                                   a10,
                                   a11,
                                   a12,
                                   "cds_get_ring_log_level");
  }
  if ( *(_DWORD *)(v12 + 96) == 3 )
    return (unsigned __int16 *)wlan_pkt_stats_to_logger_thread(result, a2, a3, a5, a6, a7, a8, a9, a10, a11, a12);
  return result;
}
