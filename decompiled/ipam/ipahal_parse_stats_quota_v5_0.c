__int64 __fastcall ipahal_parse_stats_quota_v5_0(__int64 a1, __int64 a2, char *s)
{
  __int64 ipc_logbuf_low; // x0
  __int64 v7; // x21
  int v8; // w22
  _QWORD *i; // x25
  __int64 v10; // x8
  unsigned int ep_reg_idx; // w0
  int v12; // w27
  __int64 v13; // x0

  memset(s, 0, 0x480u);
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipahal %s:%d \n", "ipahal_parse_stats_quota_v5_0", 152);
  }
  v7 = 0;
  v8 = 0;
  for ( i = s + 16; ; i += 4 )
  {
    ep_reg_idx = ipahal_get_ep_reg_idx((unsigned int)v7);
    if ( ep_reg_idx >= 2 )
      break;
    v12 = *(_DWORD *)(a1 + 4LL * ep_reg_idx);
    if ( ((unsigned int)ipahal_get_ep_bit((unsigned int)v7) & v12) != 0 )
    {
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v13 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v13, "ipahal %s:%d pipe %d stat_idx %d\n", "ipahal_parse_stats_quota_v5_0", 156, v7, v8);
      }
      v10 = a2 + 24LL * v8++;
      *(i - 2) = *(_QWORD *)v10;
      *i = *(unsigned int *)(v10 + 8);
      i[1] = *(unsigned int *)(v10 + 12);
      *(i - 1) = *(_QWORD *)(v10 + 16);
    }
    if ( ++v7 == 36 )
      return 0;
  }
  __break(0x5512u);
  return ipahal_generate_init_pyld_tethering_v5_0();
}
