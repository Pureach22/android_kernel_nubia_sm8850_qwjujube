__int64 __fastcall ipahal_parse_stats_drop_v5_0(__int64 a1, __int64 a2, char *s)
{
  __int64 ipc_logbuf_low; // x0
  __int64 v7; // x21
  int v8; // w23
  _DWORD *i; // x22
  unsigned int ep_reg_idx; // w0
  int v11; // w24
  unsigned __int64 v12; // x8

  memset(s, 0, 0x120u);
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipahal %s:%d \n", "ipahal_parse_stats_drop_v5_0", 909);
  }
  v7 = 0;
  v8 = 0;
  for ( i = s + 4; ; i += 2 )
  {
    ep_reg_idx = ipahal_get_ep_reg_idx((unsigned int)v7);
    if ( ep_reg_idx >= 2 )
      break;
    v11 = *(_DWORD *)(a1 + 4LL * ep_reg_idx);
    if ( ((unsigned int)ipahal_get_ep_bit((unsigned int)v7) & v11) != 0 )
    {
      *i = *(_QWORD *)(a2 + 8LL * v8);
      v12 = *(_QWORD *)(a2 + 8LL * v8++);
      *(i - 1) = v12 >> 40;
    }
    if ( ++v7 == 36 )
      return 0;
  }
  __break(0x5512u);
  return ipahal_generate_init_pyld_tethering_v5_2();
}
