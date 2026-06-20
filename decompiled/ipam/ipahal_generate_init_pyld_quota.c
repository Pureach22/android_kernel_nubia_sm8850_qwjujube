_WORD *__fastcall ipahal_generate_init_pyld_quota(_DWORD *a1, char a2)
{
  unsigned int v3; // w9
  unsigned int v4; // w19
  __int64 ipc_logbuf_low; // x0
  __int64 v6; // x1
  _WORD *result; // x0
  __int64 ipc_logbuf; // x0
  __int64 v9; // x8
  __int64 v10; // x0

  v3 = *a1 - ((*a1 >> 1) & 0x55555555);
  v4 = (16843009
      * (((v3 & 0x33333333) + ((v3 >> 2) & 0x33333333) + (((v3 & 0x33333333) + ((v3 >> 2) & 0x33333333)) >> 4))
       & 0xF0F0F0F)) >> 24;
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipahal %s:%d entries = %d\n", "ipahal_generate_init_pyld_quota", 40, v4);
  }
  if ( (a2 & 1) != 0 )
    v6 = 2336;
  else
    v6 = 3520;
  result = (_WORD *)_kmalloc_noprof((24 * v4) | 4, v6);
  if ( result )
  {
    *result = 24 * v4;
  }
  else
  {
    printk(&unk_3B3E69, "ipahal_generate_init_pyld_quota");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipahal %s:%d no mem\n", "ipahal_generate_init_pyld_quota", 44);
    }
    v9 = ipa3_get_ipc_logbuf_low();
    result = nullptr;
    if ( v9 )
    {
      v10 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v10, "ipahal %s:%d no mem\n", "ipahal_generate_init_pyld_quota", 44);
      return nullptr;
    }
  }
  return result;
}
