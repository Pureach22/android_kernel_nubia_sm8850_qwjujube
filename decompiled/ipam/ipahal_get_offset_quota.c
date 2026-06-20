__int64 __fastcall ipahal_get_offset_quota(unsigned int *a1, __int64 a2)
{
  unsigned int v2; // w20
  __int64 ipc_logbuf_low; // x0
  unsigned int v6; // w8

  v2 = *a1;
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipahal %s:%d \n", "ipahal_get_offset_quota", 83);
  }
  *(_DWORD *)a2 = 0;
  v6 = ((v2 - ((v2 >> 1) & 0x55555555)) & 0x33333333) + (((v2 - ((v2 >> 1) & 0x55555555)) >> 2) & 0x33333333);
  *(_WORD *)(a2 + 4) = 24 * ((unsigned __int16)((16843009 * ((v6 + (v6 >> 4)) & 0xF0F0F0F)) >> 16) >> 8);
  return 0;
}
