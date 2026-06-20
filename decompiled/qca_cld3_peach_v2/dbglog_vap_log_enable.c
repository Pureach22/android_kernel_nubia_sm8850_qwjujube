__int64 __fastcall dbglog_vap_log_enable(
        __int64 a1,
        unsigned __int16 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  if ( a2 < 0x10u )
  {
    wma_config_debug_module_cmd(a1);
    return 0;
  }
  else
  {
    if ( (dword_183E4 & 1) != 0 )
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: dbglog_vap_log_enable:Invalid vap_id %d\n",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "dbglog_vap_log_enable");
    return 4294967274LL;
  }
}
