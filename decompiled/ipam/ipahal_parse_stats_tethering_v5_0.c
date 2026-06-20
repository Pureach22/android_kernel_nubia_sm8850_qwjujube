__int64 __fastcall ipahal_parse_stats_tethering_v5_0(__int64 a1, __int64 a2, char *s)
{
  __int64 ipc_logbuf_low; // x0
  __int64 v6; // x21
  int v7; // w22
  _QWORD *v8; // x27
  __int64 v9; // x25
  __int64 ep_reg_idx; // x28
  __int64 ep_bit; // x0
  unsigned int v12; // w26
  int v13; // w19
  int v14; // w19
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x26
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  _QWORD *v23; // [xsp+10h] [xbp-10h]

  memset(s, 0, 0xA200u);
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipahal %s:%d \n", "ipahal_parse_stats_tethering_v5_0", 561);
  }
  v6 = 0;
  v7 = 0;
  v8 = s + 16;
  while ( 2 )
  {
    v9 = 0;
    ep_reg_idx = (unsigned int)ipahal_get_ep_reg_idx((unsigned int)v6);
    v23 = v8;
    do
    {
      ep_bit = ipahal_get_ep_reg_idx((unsigned int)v9);
      if ( (unsigned int)ep_reg_idx >= 2 )
      {
LABEL_25:
        __break(0x5512u);
        return ipahal_generate_init_pyld_drop_v5_0(ep_bit);
      }
      v12 = ep_bit;
      v13 = *(_DWORD *)(a1 + 4 * ep_reg_idx);
      ep_bit = ipahal_get_ep_bit((unsigned int)v6);
      if ( ((unsigned int)ep_bit & v13) != 0 )
      {
        if ( v12 > 1 )
          goto LABEL_25;
        v14 = *(_DWORD *)(a1 + 8 + 8 * v6 + 4LL * v12);
        if ( ((unsigned int)ipahal_get_ep_bit((unsigned int)v9) & v14) != 0 )
        {
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v15 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v15, "ipahal %s:%d prod %d cons %d\n", "ipahal_parse_stats_tethering_v5_0", 570, v6, v9);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v16 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v16, "ipahal %s:%d stat_idx %d\n", "ipahal_parse_stats_tethering_v5_0", 571, v7);
          }
          v17 = a2 + 24LL * v7;
          *(v8 - 2) = *(_QWORD *)v17;
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v18 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v18,
              "ipahal %s:%d num_ipv4_bytes %lld\n",
              "ipahal_parse_stats_tethering_v5_0",
              575,
              *(v8 - 2));
          }
          *v8 = *(unsigned int *)(v17 + 8);
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v19 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v19, "ipahal %s:%d num_ipv4_pkts %lld\n", "ipahal_parse_stats_tethering_v5_0", 579, *v8);
          }
          v8[1] = *(unsigned int *)(v17 + 12);
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v20 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v20, "ipahal %s:%d num_ipv6_pkts %lld\n", "ipahal_parse_stats_tethering_v5_0", 583, v8[1]);
          }
          *(v8 - 1) = *(_QWORD *)(v17 + 16);
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v21 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v21,
              "ipahal %s:%d num_ipv6_bytes %lld\n",
              "ipahal_parse_stats_tethering_v5_0",
              587,
              *(v8 - 1));
          }
          ++v7;
        }
      }
      ++v9;
      v8 += 4;
    }
    while ( v9 != 36 );
    ++v6;
    v8 = v23 + 144;
    if ( v6 != 36 )
      continue;
    return 0;
  }
}
