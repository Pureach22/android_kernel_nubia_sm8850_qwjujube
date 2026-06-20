__int64 __fastcall ipahal_parse_stats_flt_rt(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 ipc_logbuf_low; // x0

  *(_QWORD *)a3 = 0;
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipahal %s:%d \n", "ipahal_parse_stats_flt_rt", 789);
  }
  *(_DWORD *)a3 = *(_DWORD *)(a2 + 4);
  *(_DWORD *)(a3 + 4) = *(_QWORD *)a2;
  return 0;
}
