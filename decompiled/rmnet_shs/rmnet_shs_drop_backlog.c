__int64 __fastcall rmnet_shs_drop_backlog(__int64 a1, int a2)
{
  __int64 v3; // x21
  __int64 v4; // x0
  __int64 v5; // x1
  __int64 v6; // x2
  __int64 v7; // x3
  __int64 v8; // x4
  __int64 v9; // x5
  __int64 v10; // x6
  __int64 v11; // x7
  __int64 v12; // x20
  char *v13; // x21
  unsigned int v20; // w9
  __int64 v22; // [xsp+0h] [xbp+0h]
  __int64 v23; // [xsp+8h] [xbp+8h]
  __int64 v24; // [xsp+10h] [xbp+10h]
  __int64 v25; // [xsp+18h] [xbp+18h]
  __int64 vars0; // [xsp+20h] [xbp+20h]
  __int64 _28; // [xsp+28h] [xbp+28h]
  __int64 vars10; // [xsp+30h] [xbp+30h]
  __int64 _38; // [xsp+38h] [xbp+38h]

  v3 = _per_cpu_offset[a2];
  rtnl_lock();
  v4 = skb_dequeue_tail(a1);
  if ( v4 )
  {
    v12 = v4;
    v13 = (char *)&softnet_data + v3;
    do
    {
      if ( (unsigned int)rmnet_is_real_dev_registered(
                           *(_QWORD *)(v12 + 16),
                           v5,
                           v6,
                           v7,
                           v8,
                           v9,
                           v10,
                           v11,
                           v22,
                           v23,
                           v24,
                           v25,
                           vars0,
                           _28,
                           vars10,
                           _38) )
      {
        ++qword_1A468;
        netdev_core_stats_inc(*(_QWORD *)(v12 + 16), 0);
        ++*((_DWORD *)v13 + 32);
        _X8 = (unsigned int *)(v13 + 704);
        __asm { PRFM            #0x11, [X8] }
        do
          v20 = __ldxr(_X8);
        while ( __stxr(v20 + 1, _X8) );
        sk_skb_reason_drop(0, v12, 2);
      }
      v12 = skb_dequeue_tail(a1);
    }
    while ( v12 );
  }
  return rtnl_unlock();
}
