void __fastcall ipahal_set_flt_rt_sw_stats(_QWORD *a1, __int64 a2, __int64 a3)
{
  __int64 ipc_logbuf_low; // x0

  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipahal %s:%d \n", "ipahal_set_flt_rt_sw_stats", 1103);
  }
  *a1 = __ROR8__(a2, 32);
  a1[1] = a3;
}
