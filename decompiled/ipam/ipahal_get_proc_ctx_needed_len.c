__int64 __fastcall ipahal_get_proc_ctx_needed_len(unsigned int a1)
{
  __int64 ipc_logbuf; // x0
  long double v3; // q0
  __int64 ipc_logbuf_low; // x0
  __int64 (__fastcall *v5)(_QWORD, long double); // x8
  unsigned int v6; // w19
  __int64 v7; // x0
  __int64 v8; // x0

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipahal %s:%d entry\n", "ipahal_get_proc_ctx_needed_len", 2511);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    v3 = ipc_log_string(ipc_logbuf_low, "ipahal %s:%d entry\n", "ipahal_get_proc_ctx_needed_len", 2511);
  }
  v5 = (__int64 (__fastcall *)(_QWORD, long double))hdr_funcs_2;
  if ( *((_DWORD *)hdr_funcs_2 - 1) != -1031178323 )
    __break(0x8228u);
  v6 = v5(a1, v3);
  if ( ipa3_get_ipc_logbuf() )
  {
    v7 = ipa3_get_ipc_logbuf();
    ipc_log_string(v7, "ipahal %s:%d Exit\n", "ipahal_get_proc_ctx_needed_len", 2515);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v8 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v8, "ipahal %s:%d Exit\n", "ipahal_get_proc_ctx_needed_len", 2515);
  }
  return v6;
}
