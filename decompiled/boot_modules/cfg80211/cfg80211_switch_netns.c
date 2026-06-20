__int64 __fastcall cfg80211_switch_netns(__int64 a1, unsigned __int64 a2)
{
  __int64 result; // x0
  _QWORD *v3; // x23
  _QWORD *i; // x22
  __int64 v7; // x8
  _QWORD *v8; // x21
  __int64 v9; // x19
  __int64 v10; // x8
  _QWORD *j; // x21
  __int64 *v12; // x0
  __int64 v13; // x1
  _QWORD *k; // x20

  if ( (*(_BYTE *)(a1 + 1092) & 8) == 0 )
    return 4294967201LL;
  v3 = *(_QWORD **)(a1 + 2328);
  for ( i = (_QWORD *)(a1 + 2328); v3 != i; v3 = (_QWORD *)*v3 )
  {
    v7 = v3[2];
    if ( v7 )
    {
      *(_BYTE *)(v7 + 2418) &= ~4u;
      result = _dev_change_net_namespace(v3[2], a2, "wlan%d", 0);
      if ( (_DWORD)result )
      {
        v8 = (_QWORD *)v3[1];
        if ( v8 != i )
        {
          v9 = *(_QWORD *)(a1 + 2344);
          do
          {
            v10 = v8[2];
            if ( v10 )
            {
              *(_BYTE *)(v10 + 2418) &= ~4u;
              result = _dev_change_net_namespace(v8[2], v9, "wlan%d", 0);
              if ( (_DWORD)result )
                __break(0x800u);
              *(_BYTE *)(v8[2] + 2418LL) |= 4u;
            }
            v8 = (_QWORD *)v8[1];
          }
          while ( v8 != i );
        }
        return result;
      }
      *(_BYTE *)(v3[2] + 2418LL) |= 4u;
    }
  }
  mutex_lock(a1 + 992);
  for ( j = (_QWORD *)*i; j != i; j = (_QWORD *)*j )
  {
    if ( j[2] )
      nl80211_notify_iface(a1, j - 2, 8);
  }
  nl80211_notify_wiphy(a1, 4);
  atomic_store(a2, (unsigned __int64 *)(a1 + 2344));
  v12 = (__int64 *)(a1 + 1384);
  v13 = *(_QWORD *)(a1 + 1496);
  if ( !v13 )
    v13 = *v12;
  if ( (unsigned int)device_rename(v12, v13) )
    __break(0x800u);
  nl80211_notify_wiphy(a1, 3);
  for ( k = *(_QWORD **)(a1 + 2328); k != i; k = (_QWORD *)*k )
  {
    if ( k[2] )
      nl80211_notify_iface(a1, k - 2, 7);
  }
  mutex_unlock(a1 + 992);
  return 0;
}
