long double __fastcall ipahal_get_fltrt_cache_flush_valmask(unsigned __int8 *a1, _DWORD *a2)
{
  int v2; // w8
  __int64 ipc_logbuf; // x0
  long double result; // q0
  __int64 ipc_logbuf_low; // x0

  if ( a1 && a2 )
  {
    *(_QWORD *)a2 = 0;
    v2 = *a1;
    if ( v2 == 1 )
      *a2 = 1;
    else
      v2 = 0;
    if ( a1[1] == 1 )
    {
      v2 |= 0x10u;
      *a2 = v2;
    }
    a2[1] = v2;
  }
  else
  {
    printk(&unk_3E5560, "ipahal_get_fltrt_cache_flush_valmask");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipahal %s:%d Input error: flush=%pK ; valmask=%pK\n",
        "ipahal_get_fltrt_cache_flush_valmask",
        5825,
        a1,
        a2);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      return ipc_log_string(
               ipc_logbuf_low,
               "ipahal %s:%d Input error: flush=%pK ; valmask=%pK\n",
               "ipahal_get_fltrt_cache_flush_valmask",
               5825,
               a1,
               a2);
    }
  }
  return result;
}
