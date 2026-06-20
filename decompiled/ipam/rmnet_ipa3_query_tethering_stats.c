__int64 __fastcall rmnet_ipa3_query_tethering_stats(char *a1)
{
  int upstream_type; // w0
  long double v3; // q0
  __int64 v4; // x0
  unsigned int tethering_stats_modem; // w8
  __int64 result; // x0
  unsigned int v7; // w19
  __int64 v8; // x0
  __int64 v9; // x0
  long double v10; // q0
  __int64 ipc_logbuf_low; // x0
  unsigned int tethering_stats_wifi; // w8
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 ipc_logbuf; // x0
  __int64 v16; // x0

  a1[15] = 0;
  a1[31] = 0;
  upstream_type = find_upstream_type(a1);
  if ( upstream_type == 2 )
  {
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      v10 = ipc_log_string(
              ipc_logbuf_low,
              "ipa-wan %s:%d  query wifi-backhaul stats\n",
              "rmnet_ipa3_query_tethering_stats",
              5602);
    }
    tethering_stats_wifi = rmnet_ipa3_query_tethering_stats_wifi(a1, 0, v10);
    result = 0;
    if ( tethering_stats_wifi )
    {
      v7 = tethering_stats_wifi;
      printk(&unk_3F9161, "rmnet_ipa3_query_tethering_stats");
      if ( ipa3_get_ipc_logbuf() )
      {
        ipc_logbuf = ipa3_get_ipc_logbuf();
        ipc_log_string(
          ipc_logbuf,
          "ipa-wan %s:%d wlan WAN_IOC_QUERY_TETHER_STATS failed\n",
          "rmnet_ipa3_query_tethering_stats",
          5606);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v16 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v16,
          "ipa-wan %s:%d wlan WAN_IOC_QUERY_TETHER_STATS failed\n",
          "rmnet_ipa3_query_tethering_stats",
          5606);
      }
      return v7;
    }
  }
  else if ( upstream_type == 3 )
  {
    printk(&unk_3E1E82, "rmnet_ipa3_query_tethering_stats");
    if ( ipa3_get_ipc_logbuf() )
    {
      v13 = ipa3_get_ipc_logbuf();
      ipc_log_string(v13, "ipa-wan %s:%d  Wrong upstreamIface name %s\n", "rmnet_ipa3_query_tethering_stats", 5600, a1);
    }
    result = ipa3_get_ipc_logbuf_low();
    if ( result )
    {
      v14 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v14, "ipa-wan %s:%d  Wrong upstreamIface name %s\n", "rmnet_ipa3_query_tethering_stats", 5600, a1);
      return 0;
    }
  }
  else
  {
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v4 = ipa3_get_ipc_logbuf_low();
      v3 = ipc_log_string(v4, "ipa-wan %s:%d  query modem-backhaul stats\n", "rmnet_ipa3_query_tethering_stats", 5610);
    }
    tethering_stats_modem = rmnet_ipa3_query_tethering_stats_modem(a1, 0, v3);
    result = 0;
    if ( tethering_stats_modem )
    {
      v7 = tethering_stats_modem;
      printk(&unk_3BC32A, "rmnet_ipa3_query_tethering_stats");
      if ( ipa3_get_ipc_logbuf() )
      {
        v8 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v8,
          "ipa-wan %s:%d modem WAN_IOC_QUERY_TETHER_STATS failed\n",
          "rmnet_ipa3_query_tethering_stats",
          5614);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v9 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v9,
          "ipa-wan %s:%d modem WAN_IOC_QUERY_TETHER_STATS failed\n",
          "rmnet_ipa3_query_tethering_stats",
          5614);
      }
      return v7;
    }
  }
  return result;
}
