__int64 __fastcall rmnet_wlan_act_encap_port_pass_through(unsigned __int16 a1)
{
  __int64 *v1; // x9
  int v2; // w10
  __int64 *v3; // x1
  _QWORD *v4; // x8

  v1 = (__int64 *)rmnet_wlan_act_encap_drop_hash[(1640531527 * (unsigned int)a1) >> 28];
  while ( v1 )
  {
    v2 = *((unsigned __int16 *)v1 + 16);
    v3 = v1;
    v1 = (__int64 *)*v1;
    if ( v2 == a1 )
    {
      v4 = (_QWORD *)v3[1];
      if ( v4 )
      {
        *v4 = v1;
        if ( v1 )
          v1[1] = (__int64)v4;
        v3[1] = 0;
      }
      kvfree_call_rcu(v3 + 2);
      rmnet_wlan_stats_update(17);
      return 0;
    }
  }
  return 0;
}
