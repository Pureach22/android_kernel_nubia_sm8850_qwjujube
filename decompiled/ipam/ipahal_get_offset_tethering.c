__int64 __fastcall ipahal_get_offset_tethering(_DWORD *a1, __int64 a2)
{
  __int64 v4; // x19
  int v5; // w21
  __int64 v6; // x9
  unsigned int v7; // w11
  __int64 ipc_logbuf_low; // x0
  __int64 result; // x0
  unsigned int v10; // w8
  __int64 ipc_logbuf; // x0
  __int64 v12; // x0

  v4 = 0;
  v5 = 0;
  v6 = 2;
  while ( ((*a1 >> v4) & 1) == 0 )
  {
LABEL_2:
    ++v4;
    v6 += 2;
    if ( v4 == 32 )
    {
      if ( ipa3_get_ipc_logbuf_low() )
      {
        ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
        ipc_log_string(ipc_logbuf_low, "ipahal %s:%d sum all entries = %d\n", "ipahal_get_offset_tethering", 453, v5);
      }
      result = 0;
      v10 = *a1 - ((*a1 >> 1) & 0x55555555);
      *(_WORD *)(a2 + 4) = 24 * v5;
      *(_DWORD *)a2 = ((16843009
                      * (((v10 & 0x33333333)
                        + ((v10 >> 2) & 0x33333333)
                        + (((v10 & 0x33333333) + ((v10 >> 2) & 0x33333333)) >> 4))
                       & 0xF0F0F0F)) >> 21)
                    & 0x7F8;
      return result;
    }
  }
  v7 = a1[v6];
  if ( v7 )
  {
    v5 += (16843009
         * ((((v7 - ((v7 >> 1) & 0x55555555)) & 0x33333333)
           + (((v7 - ((v7 >> 1) & 0x55555555)) >> 2) & 0x33333333)
           + ((((v7 - ((v7 >> 1) & 0x55555555)) & 0x33333333) + (((v7 - ((v7 >> 1) & 0x55555555)) >> 2) & 0x33333333)) >> 4))
          & 0xF0F0F0F)) >> 24;
    goto LABEL_2;
  }
  printk(&unk_3E877F, "ipahal_get_offset_tethering");
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipahal %s:%d no cons bitmask for prod %d\n", "ipahal_get_offset_tethering", 447, v4);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v12 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v12, "ipahal %s:%d no cons bitmask for prod %d\n", "ipahal_get_offset_tethering", 447, v4);
  }
  return 0xFFFFFFFFLL;
}
