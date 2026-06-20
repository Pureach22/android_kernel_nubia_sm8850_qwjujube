__int64 __fastcall rmnet_wlan_del_tuples(__int64 a1, int a2, __int64 a3)
{
  __int64 v6; // x22
  unsigned __int16 *v7; // x9
  int v8; // w10
  __int64 *v9; // x8
  int v10; // w11
  int v11; // w12
  __int64 *v12; // x1
  _QWORD *v13; // x9
  _QWORD *v14; // x27

  mutex_lock(&rmnet_wlan_tuple_mutex);
  if ( a2 )
  {
    v6 = 0;
    do
    {
      v7 = (unsigned __int16 *)(a1 + 8 * v6);
      v8 = *v7;
      v9 = (__int64 *)rmnet_wlan_tuple_hash[(unsigned int)(1640531527 * v8) >> 28];
      if ( v9 )
      {
        v10 = *((unsigned __int8 *)v7 + 4);
        do
        {
          v11 = *((unsigned __int8 *)v9 + 36);
          v12 = v9;
          v9 = (__int64 *)*v9;
          if ( v11 == v10 && *((unsigned __int8 *)v12 + 37) == *((unsigned __int8 *)v7 + 5) )
          {
            if ( v10 == 50 )
            {
              if ( *((_DWORD *)v12 + 8) == *(_DWORD *)v7 )
                goto LABEL_14;
            }
            else if ( *((unsigned __int16 *)v12 + 16) == v8 )
            {
LABEL_14:
              v13 = (_QWORD *)v12[1];
              if ( v13 )
              {
                *v13 = v9;
                if ( v9 )
                  v9[1] = (__int64)v13;
                v12[1] = 0;
              }
              kvfree_call_rcu(v12 + 2);
              rmnet_wlan_stats_update(1);
              --rmnet_wlan_tuple_count;
              goto LABEL_5;
            }
          }
        }
        while ( v9 );
      }
      v14 = *(_QWORD **)(a3 + 64);
      do_trace_netlink_extack("No such tuple");
      if ( v14 )
        *v14 = "No such tuple";
LABEL_5:
      ++v6;
    }
    while ( v6 != a2 );
  }
  mutex_unlock(&rmnet_wlan_tuple_mutex);
  return 0;
}
