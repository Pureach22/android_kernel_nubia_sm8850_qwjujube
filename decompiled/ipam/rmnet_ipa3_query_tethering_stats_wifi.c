__int64 __fastcall rmnet_ipa3_query_tethering_stats_wifi(_QWORD *a1, char a2)
{
  unsigned __int8 *v4; // x0
  unsigned __int8 *v5; // x19
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  unsigned int wlan_stats; // w0
  unsigned int v9; // w21
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x9
  __int64 v13; // x10
  __int64 v14; // x8
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0

  v4 = (unsigned __int8 *)_kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 72);
  v5 = v4;
  if ( !v4 )
    return (unsigned int)-12;
  *((_QWORD *)v4 + 7) = 0;
  *((_QWORD *)v4 + 8) = 0;
  *((_QWORD *)v4 + 5) = 0;
  *((_QWORD *)v4 + 6) = 0;
  *((_QWORD *)v4 + 3) = 0;
  *((_QWORD *)v4 + 4) = 0;
  *((_QWORD *)v4 + 1) = 0;
  *((_QWORD *)v4 + 2) = 0;
  *(_QWORD *)v4 = 0;
  *v4 = a2 & 1;
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(
      ipc_logbuf,
      "ipa-wan %s:%d reset the pipe stats %d\n",
      "rmnet_ipa3_query_tethering_stats_wifi",
      4745,
      *v5);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      ipc_logbuf_low,
      "ipa-wan %s:%d reset the pipe stats %d\n",
      "rmnet_ipa3_query_tethering_stats_wifi",
      4745,
      *v5);
  }
  wlan_stats = ipa3_get_wlan_stats((__int64)v5);
  if ( !wlan_stats )
  {
    if ( a1 )
    {
      if ( v5[1] )
      {
        v12 = *((_QWORD *)v5 + 2);
        a1[5] = *((_QWORD *)v5 + 1);
        a1[6] = v12;
        v13 = *((_QWORD *)v5 + 4);
        a1[7] = *((_QWORD *)v5 + 3);
        a1[8] = v13;
        v14 = *((_QWORD *)v5 + 6);
        a1[9] = *((_QWORD *)v5 + 5);
        a1[10] = v14;
        v15 = *((_QWORD *)v5 + 8);
        a1[11] = *((_QWORD *)v5 + 7);
        a1[12] = v15;
      }
      if ( ipa3_get_ipc_logbuf() )
      {
        v16 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v16,
          "ipa-wan %s:%d v4_rx_p(%lu) v6_rx_p(%lu) v4_rx_b(%lu) v6_rx_b(%lu)\n",
          "rmnet_ipa3_query_tethering_stats_wifi",
          4773,
          a1[7],
          a1[11],
          a1[8],
          a1[12]);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v17 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v17,
          "ipa-wan %s:%d v4_rx_p(%lu) v6_rx_p(%lu) v4_rx_b(%lu) v6_rx_b(%lu)\n",
          "rmnet_ipa3_query_tethering_stats_wifi",
          4773,
          a1[7],
          a1[11],
          a1[8],
          a1[12]);
      }
      if ( ipa3_get_ipc_logbuf() )
      {
        v18 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v18,
          "ipa-wan %s:%d tx_p_v4(%lu)v6(%lu)tx_b_v4(%lu) v6(%lu)\n",
          "rmnet_ipa3_query_tethering_stats_wifi",
          4778,
          a1[5],
          a1[9],
          a1[6],
          a1[10]);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v19 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v19,
          "ipa-wan %s:%d tx_p_v4(%lu)v6(%lu)tx_b_v4(%lu) v6(%lu)\n",
          "rmnet_ipa3_query_tethering_stats_wifi",
          4778,
          a1[5],
          a1[9],
          a1[6],
          a1[10]);
      }
    }
    else
    {
      if ( ipa3_get_ipc_logbuf() )
      {
        v20 = ipa3_get_ipc_logbuf();
        ipc_log_string(v20, "ipa-wan %s:%d only reset wlan stats\n", "rmnet_ipa3_query_tethering_stats_wifi", 4753);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v21 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v21, "ipa-wan %s:%d only reset wlan stats\n", "rmnet_ipa3_query_tethering_stats_wifi", 4753);
      }
    }
    v9 = 0;
    goto LABEL_28;
  }
  v9 = wlan_stats;
  if ( !(unsigned int)__ratelimit(&rmnet_ipa3_query_tethering_stats_wifi__rs, "rmnet_ipa3_query_tethering_stats_wifi") )
  {
    if ( !ipa3_get_ipc_logbuf() )
      goto LABEL_10;
    goto LABEL_9;
  }
  printk(&unk_3ADDCA, "rmnet_ipa3_query_tethering_stats_wifi");
  if ( ipa3_get_ipc_logbuf() )
  {
LABEL_9:
    v10 = ipa3_get_ipc_logbuf();
    ipc_log_string(v10, "ipa-wan %s:%d can't get ipa3_get_wlan_stats\n", "rmnet_ipa3_query_tethering_stats_wifi", 4749);
  }
LABEL_10:
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v11 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v11, "ipa-wan %s:%d can't get ipa3_get_wlan_stats\n", "rmnet_ipa3_query_tethering_stats_wifi", 4749);
  }
LABEL_28:
  kfree(v5);
  return v9;
}
