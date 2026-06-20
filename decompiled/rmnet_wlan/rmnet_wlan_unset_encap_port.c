__int64 __fastcall rmnet_wlan_unset_encap_port(unsigned __int16 a1, __int64 a2)
{
  int v2; // w20
  __int64 *v4; // x8
  int v5; // w9
  __int64 *v6; // x1
  _QWORD *v7; // x9
  unsigned int v8; // w19
  _QWORD *v9; // x20

  v2 = a1;
  mutex_lock(&rmnet_wlan_encap_mutex);
  v4 = (__int64 *)rmnet_wlan_encap_hash[(unsigned int)(1640531527 * v2) >> 28];
  while ( v4 )
  {
    v5 = *((unsigned __int16 *)v4 + 16);
    v6 = v4;
    v4 = (__int64 *)*v4;
    if ( v5 == v2 )
    {
      v7 = (_QWORD *)v6[1];
      if ( v7 )
      {
        *v7 = v4;
        if ( v4 )
          v4[1] = (__int64)v7;
        v6[1] = 0;
      }
      kvfree_call_rcu(v6 + 2);
      rmnet_wlan_stats_update(15);
      v8 = 0;
      goto LABEL_12;
    }
  }
  v9 = *(_QWORD **)(a2 + 64);
  do_trace_netlink_extack("No such port value");
  if ( v9 )
    *v9 = "No such port value";
  v8 = -3;
LABEL_12:
  mutex_unlock(&rmnet_wlan_encap_mutex);
  return v8;
}
