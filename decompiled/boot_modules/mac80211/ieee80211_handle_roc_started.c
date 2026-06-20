__int64 __fastcall ieee80211_handle_roc_started(__int64 result, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x19
  __int64 v4; // x20
  __int64 v5; // x21
  unsigned int v6; // w22
  __int64 v7; // x0

  if ( *(_BYTE *)(result + 35) == 1 )
  {
    __break(0x800u);
  }
  else
  {
    v2 = *(_QWORD *)(result + 72);
    v3 = result;
    *(_QWORD *)(result + 40) = a2;
    *(_BYTE *)(result + 32) = 1;
    if ( v2 )
    {
      v4 = *(_QWORD *)(result + 56);
      if ( v4 )
      {
        v5 = *(_QWORD *)(result + 16);
        v6 = **(_DWORD **)(result + 24);
        _rcu_read_lock(result, a2);
        v7 = _ieee80211_tx_skb_tid_band(v5, v4, 7, 0xFFFFFFFFLL, v6);
        result = _rcu_read_unlock(v7);
        *(_QWORD *)(v3 + 56) = 0;
      }
      else
      {
        __break(0x800u);
      }
    }
    else
    {
      result = cfg80211_ready_on_channel(
                 *(_QWORD *)(result + 16) + 16LL,
                 *(_QWORD *)(result + 64),
                 *(_QWORD *)(result + 24),
                 *(unsigned int *)(result + 52),
                 3264);
    }
    *(_BYTE *)(v3 + 35) = 1;
  }
  return result;
}
