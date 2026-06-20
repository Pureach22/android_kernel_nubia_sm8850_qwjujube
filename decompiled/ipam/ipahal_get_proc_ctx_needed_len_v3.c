__int64 __fastcall ipahal_get_proc_ctx_needed_len_v3(unsigned int a1)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  if ( a1 < 0xD && ((0x1BFFu >> a1) & 1) != 0 )
    return dword_1E5630[a1];
  if ( (unsigned int)__ratelimit(&ipahal_get_proc_ctx_needed_len_v3__rs, "ipahal_get_proc_ctx_needed_len_v3") )
  {
    printk(&unk_3DA317, "ipahal_get_proc_ctx_needed_len_v3");
    if ( !ipa3_get_ipc_logbuf() )
      goto LABEL_7;
    goto LABEL_6;
  }
  if ( ipa3_get_ipc_logbuf() )
  {
LABEL_6:
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(
      ipc_logbuf,
      "ipahal %s:%d invalid ipa_hdr_proc_type %d\n",
      "ipahal_get_proc_ctx_needed_len_v3",
      2384,
      a1);
  }
LABEL_7:
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      ipc_logbuf_low,
      "ipahal %s:%d invalid ipa_hdr_proc_type %d\n",
      "ipahal_get_proc_ctx_needed_len_v3",
      2384,
      a1);
  }
  return 0xFFFFFFFFLL;
}
