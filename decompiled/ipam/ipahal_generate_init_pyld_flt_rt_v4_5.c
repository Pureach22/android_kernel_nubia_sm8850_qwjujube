_WORD *__fastcall ipahal_generate_init_pyld_flt_rt_v4_5(__int64 a1, char a2)
{
  __int64 v3; // x0
  __int64 v4; // x1
  _WORD *result; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  if ( a1 > 32 || a1 <= 0 )
  {
    printk(&unk_3B3EBD, "ipahal_generate_init_pyld_flt_rt_v4_5");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipahal %s:%d num %ld not valid\n", "ipahal_generate_init_pyld_flt_rt_v4_5", 604, a1);
    }
    result = (_WORD *)ipa3_get_ipc_logbuf_low();
    if ( result )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        ipc_logbuf_low,
        "ipahal %s:%d num %ld not valid\n",
        "ipahal_generate_init_pyld_flt_rt_v4_5",
        604,
        a1);
      return nullptr;
    }
  }
  else
  {
    v3 = (16 * a1) | 4;
    if ( (a2 & 1) != 0 )
      v4 = 2336;
    else
      v4 = 3520;
    result = (_WORD *)_kmalloc_noprof(v3, v4);
    if ( result )
      *result = 16 * a1;
  }
  return result;
}
