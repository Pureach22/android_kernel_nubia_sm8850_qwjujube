__int64 __fastcall ieee80211_rx_napi(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v8; // x0
  __int64 result; // x0
  _QWORD *v10; // x1
  _QWORD *v11; // x8
  _QWORD *v12; // x21
  _QWORD *v13; // x9
  _QWORD v14[3]; // [xsp+8h] [xbp-18h] BYREF

  v14[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14[0] = v14;
  v14[1] = v14;
  _rcu_read_lock(a1, a2);
  v8 = ieee80211_rx_list(a1, a2, a3, (__int64)v14);
  result = _rcu_read_unlock(v8);
  if ( a4 )
  {
    v10 = (_QWORD *)v14[0];
    if ( (_QWORD *)v14[0] != v14 )
    {
      do
      {
        v12 = (_QWORD *)*v10;
        v11 = (_QWORD *)v10[1];
        if ( (_QWORD *)*v11 == v10 && (_QWORD *)v12[1] == v10 )
        {
          v12[1] = v11;
          *v11 = v12;
        }
        else
        {
          _list_del_entry_valid_or_report(v10);
          v10 = v13;
        }
        *v10 = 0;
        result = napi_gro_receive(a4);
        v10 = v12;
      }
      while ( v12 != v14 );
    }
  }
  else
  {
    result = netif_receive_skb_list(v14);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
