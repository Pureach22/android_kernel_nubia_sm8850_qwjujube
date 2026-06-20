__int64 __fastcall rmnet_wlan_deliver_skb(__int64 a1, __int64 *a2)
{
  __int64 v2; // x20
  unsigned int v4; // w19
  __int64 v5; // x0

  v2 = *a2;
  if ( *a2 )
  {
    rmnet_wlan_tcp_mss_clamp(a1, 4608);
    *(_QWORD *)(a1 + 16) = v2;
    _dev_queue_xmit(a1, 0);
    v4 = 0;
    v5 = 3;
  }
  else
  {
    v4 = -19;
    v5 = 4;
  }
  rmnet_wlan_stats_update(v5);
  return v4;
}
