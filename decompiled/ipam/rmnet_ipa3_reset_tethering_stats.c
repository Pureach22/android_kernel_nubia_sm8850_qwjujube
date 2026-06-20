__int64 __fastcall rmnet_ipa3_reset_tethering_stats(char *a1)
{
  int upstream_type; // w0
  __int64 v3; // x0
  __int64 result; // x0
  __int64 v5; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  unsigned int v8; // w19
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0

  a1[15] = 0;
  upstream_type = find_upstream_type(a1);
  if ( upstream_type == 2 )
  {
    printk(&unk_3D9465, "rmnet_ipa3_reset_tethering_stats");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa-wan %s:%d  reset wifi-backhaul stats\n", "rmnet_ipa3_reset_tethering_stats", 5712);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        ipc_logbuf_low,
        "ipa-wan %s:%d  reset wifi-backhaul stats\n",
        "rmnet_ipa3_reset_tethering_stats",
        5712);
    }
    result = rmnet_ipa3_query_tethering_stats_wifi(nullptr, 1);
    if ( !(_DWORD)result )
      return result;
    v8 = result;
    printk(&unk_3D9491, "rmnet_ipa3_reset_tethering_stats");
    if ( ipa3_get_ipc_logbuf() )
    {
      v9 = ipa3_get_ipc_logbuf();
      ipc_log_string(v9, "ipa-wan %s:%d reset WLAN stats failed\n", "rmnet_ipa3_reset_tethering_stats", 5716);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v10 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v10, "ipa-wan %s:%d reset WLAN stats failed\n", "rmnet_ipa3_reset_tethering_stats", 5716);
    }
    return v8;
  }
  if ( upstream_type == 3 )
  {
    printk(&unk_3E1E82, "rmnet_ipa3_reset_tethering_stats");
    if ( ipa3_get_ipc_logbuf() )
    {
      v3 = ipa3_get_ipc_logbuf();
      ipc_log_string(v3, "ipa-wan %s:%d  Wrong upstreamIface name %s\n", "rmnet_ipa3_reset_tethering_stats", 5710, a1);
    }
    result = ipa3_get_ipc_logbuf_low();
    if ( result )
    {
      v5 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v5, "ipa-wan %s:%d  Wrong upstreamIface name %s\n", "rmnet_ipa3_reset_tethering_stats", 5710, a1);
      return 0;
    }
    return result;
  }
  printk(&unk_3D6B4F, "rmnet_ipa3_reset_tethering_stats");
  if ( ipa3_get_ipc_logbuf() )
  {
    v11 = ipa3_get_ipc_logbuf();
    ipc_log_string(v11, "ipa-wan %s:%d  reset modem-backhaul stats\n", "rmnet_ipa3_reset_tethering_stats", 5720);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v12 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v12, "ipa-wan %s:%d  reset modem-backhaul stats\n", "rmnet_ipa3_reset_tethering_stats", 5720);
  }
  result = rmnet_ipa3_query_tethering_stats_modem(0, 1);
  if ( (_DWORD)result )
  {
    v8 = result;
    printk(&unk_3E7744, "rmnet_ipa3_reset_tethering_stats");
    if ( ipa3_get_ipc_logbuf() )
    {
      v13 = ipa3_get_ipc_logbuf();
      ipc_log_string(v13, "ipa-wan %s:%d reset MODEM stats failed\n", "rmnet_ipa3_reset_tethering_stats", 5724);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v14 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v14, "ipa-wan %s:%d reset MODEM stats failed\n", "rmnet_ipa3_reset_tethering_stats", 5724);
    }
    return v8;
  }
  return result;
}
