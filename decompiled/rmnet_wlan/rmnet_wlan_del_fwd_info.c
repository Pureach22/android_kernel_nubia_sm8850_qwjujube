__int64 __fastcall rmnet_wlan_del_fwd_info(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 lock; // x0
  int v6; // w8
  __int64 *v7; // x19
  int v8; // w9
  unsigned __int8 *v9; // x8
  unsigned int v10; // w0
  unsigned int v11; // w21
  _QWORD *v12; // x20
  _QWORD *v13; // x20
  _QWORD *v15; // x20
  _QWORD *v16; // x8
  __int64 *v17; // x9

  v4 = mutex_lock(&rmnet_wlan_fwd_mutex);
  lock = _rcu_read_lock(v4);
  v6 = *(_DWORD *)(a1 + 8);
  v7 = (__int64 *)rmnet_wlan_fwd_hash[(unsigned int)(1640531527 * v6) >> 28];
  if ( v7 )
  {
    v8 = *(unsigned __int8 *)(a1 + 24);
    do
    {
      if ( *((unsigned __int8 *)v7 + 96) == v8 )
      {
        if ( v8 == 4 )
        {
          if ( *((_DWORD *)v7 + 20) == v6 )
          {
LABEL_8:
            _rcu_read_unlock(lock);
            v9 = *(unsigned __int8 **)a1;
            if ( *((unsigned __int8 *)v7 + 56) == *(unsigned __int8 *)(*(_QWORD *)a1 + 296LL)
              && (!*((_BYTE *)v7 + 57)
               || *((unsigned __int8 *)v7 + 57) == v9[297]
               && (!*((_BYTE *)v7 + 58)
                || *((unsigned __int8 *)v7 + 58) == v9[298]
                && (!*((_BYTE *)v7 + 59)
                 || *((unsigned __int8 *)v7 + 59) == v9[299]
                 && (!*((_BYTE *)v7 + 60)
                  || *((unsigned __int8 *)v7 + 60) == v9[300]
                  && (!*((_BYTE *)v7 + 61)
                   || *((unsigned __int8 *)v7 + 61) == v9[301]
                   && (!*((_BYTE *)v7 + 62)
                    || *((unsigned __int8 *)v7 + 62) == v9[302]
                    && (!*((_BYTE *)v7 + 63)
                     || *((unsigned __int8 *)v7 + 63) == v9[303]
                     && (!*((_BYTE *)v7 + 64)
                      || *((unsigned __int8 *)v7 + 64) == v9[304]
                      && (!*((_BYTE *)v7 + 65)
                       || *((unsigned __int8 *)v7 + 65) == v9[305]
                       && (!*((_BYTE *)v7 + 66)
                        || *((unsigned __int8 *)v7 + 66) == v9[306]
                        && (!*((_BYTE *)v7 + 67)
                         || *((unsigned __int8 *)v7 + 67) == v9[307]
                         && (!*((_BYTE *)v7 + 68)
                          || *((unsigned __int8 *)v7 + 68) == v9[308]
                          && (!*((_BYTE *)v7 + 69)
                           || *((unsigned __int8 *)v7 + 69) == v9[309]
                           && (!*((_BYTE *)v7 + 70)
                            || *((unsigned __int8 *)v7 + 70) == v9[310]
                            && (!*((_BYTE *)v7 + 71) || *((unsigned __int8 *)v7 + 71) == v9[311]))))))))))))))) )
            {
              v10 = unregister_netdevice_notifier(v7 + 4);
              if ( v10 )
              {
                v11 = v10;
                v12 = *(_QWORD **)(a2 + 64);
                do_trace_netlink_extack("Unregistering notifier failed");
                if ( v12 )
                  *v12 = "Unregistering notifier failed";
              }
              else
              {
                v16 = (_QWORD *)v7[1];
                if ( v16 )
                {
                  v17 = (__int64 *)*v7;
                  *v16 = *v7;
                  if ( v17 )
                    v17[1] = (__int64)v16;
                  v7[1] = 0;
                }
                rmnet_wlan_fragment_del_fwd_info((__int64)(v7 + 9));
                kvfree_call_rcu(v7 + 2);
                v11 = 0;
              }
            }
            else
            {
              v15 = *(_QWORD **)(a2 + 64);
              do_trace_netlink_extack("Incorrect FWD device");
              if ( v15 )
                *v15 = "Incorrect FWD device";
              v11 = -19;
            }
            goto LABEL_45;
          }
        }
        else if ( *(_QWORD *)(a1 + 8) == v7[10] )
        {
          goto LABEL_8;
        }
      }
      v7 = (__int64 *)*v7;
    }
    while ( v7 );
  }
  _rcu_read_unlock(lock);
  v13 = *(_QWORD **)(a2 + 64);
  do_trace_netlink_extack("No such FWD information");
  if ( v13 )
    *v13 = "No such FWD information";
  v11 = -3;
LABEL_45:
  mutex_unlock(&rmnet_wlan_fwd_mutex);
  return v11;
}
