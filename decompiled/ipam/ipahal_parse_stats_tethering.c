__int64 __fastcall ipahal_parse_stats_tethering(_DWORD *a1, __int64 a2, char *s)
{
  __int64 ipc_logbuf_low; // x0
  __int64 v7; // x21
  int v8; // w22
  _QWORD *v9; // x26
  __int64 v10; // x25
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x27
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  _QWORD *v19; // [xsp+8h] [xbp-8h]

  memset(s, 0, 0xA200u);
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipahal %s:%d \n", "ipahal_parse_stats_tethering", 516);
  }
  v7 = 0;
  v8 = 0;
  v9 = s + 16;
  do
  {
    v10 = 0;
    v19 = v9;
    do
    {
      if ( (*a1 & (1 << v7)) != 0 && ((a1[2 * v7 + 2] >> v10) & 1) != 0 )
      {
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v11 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v11, "ipahal %s:%d prod %d cons %d\n", "ipahal_parse_stats_tethering", 521, v7, v10);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v12 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v12, "ipahal %s:%d stat_idx %d\n", "ipahal_parse_stats_tethering", 522, v8);
        }
        v13 = a2 + 24LL * v8;
        *(v9 - 2) = *(_QWORD *)v13;
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v14 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v14, "ipahal %s:%d num_ipv4_bytes %lld\n", "ipahal_parse_stats_tethering", 526, *(v9 - 2));
        }
        *v9 = *(unsigned int *)(v13 + 8);
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v15 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v15, "ipahal %s:%d num_ipv4_pkts %lld\n", "ipahal_parse_stats_tethering", 530, *v9);
        }
        v9[1] = *(unsigned int *)(v13 + 12);
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v16 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v16, "ipahal %s:%d num_ipv6_pkts %lld\n", "ipahal_parse_stats_tethering", 534, v9[1]);
        }
        *(v9 - 1) = *(_QWORD *)(v13 + 16);
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v17 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v17, "ipahal %s:%d num_ipv6_bytes %lld\n", "ipahal_parse_stats_tethering", 538, *(v9 - 1));
        }
        ++v8;
      }
      ++v10;
      v9 += 4;
    }
    while ( v10 != 32 );
    ++v7;
    v9 = v19 + 144;
  }
  while ( v7 != 32 );
  return 0;
}
