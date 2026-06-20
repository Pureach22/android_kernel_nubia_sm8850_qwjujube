_WORD *__fastcall ipahal_generate_init_pyld_drop_v5_0(_DWORD *a1, char a2)
{
  unsigned int v3; // w9
  unsigned int v4; // w10
  unsigned int v5; // w19
  __int64 ipc_logbuf_low; // x0
  __int64 v7; // x1
  _WORD *result; // x0

  v3 = a1[1] - ((a1[1] >> 1) & 0x55555555);
  v4 = *a1 - ((*a1 >> 1) & 0x55555555);
  v5 = ((16843009
       * (((v3 & 0x33333333) + ((v3 >> 2) & 0x33333333) + (((v3 & 0x33333333) + ((v3 >> 2) & 0x33333333)) >> 4))
        & 0xF0F0F0F)) >> 24)
     + ((16843009
       * (((v4 & 0x33333333) + ((v4 >> 2) & 0x33333333) + (((v4 & 0x33333333) + ((v4 >> 2) & 0x33333333)) >> 4))
        & 0xF0F0F0F)) >> 24);
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipahal %s:%d entries = %d\n", "ipahal_generate_init_pyld_drop_v5_0", 826, v5);
  }
  if ( (a2 & 1) != 0 )
    v7 = 2336;
  else
    v7 = 3520;
  result = (_WORD *)_kmalloc_noprof((8 * v5) | 4, v7);
  if ( result )
    *result = 8 * v5;
  return result;
}
