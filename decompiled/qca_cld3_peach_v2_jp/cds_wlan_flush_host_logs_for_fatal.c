__int64 __fastcall cds_wlan_flush_host_logs_for_fatal(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12)
{
  __int64 v12; // x8
  __int64 result; // x0

  v12 = gp_cds_context;
  if ( gp_cds_context || (result = printk(&unk_94D98D, "cds_get_global_context", a11, a12), (v12 = gp_cds_context) != 0) )
  {
    if ( *(_BYTE *)(v12 + 120) != 1 )
      return result;
  }
  else
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: cds context is Invalid",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "cds_is_log_report_in_progress");
  }
  return wlan_flush_host_logs_for_fatal(a1, a2, a3, a4, a5, a6, a7, a8);
}
