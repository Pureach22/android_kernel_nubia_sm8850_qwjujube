__int64 __fastcall rmnet_wlan_flush_fragment_node(__int64 a1, char a2)
{
  unsigned __int64 v3; // x20
  __int64 v4; // x0
  void (__fastcall *v5)(_QWORD); // x23
  __int64 v6; // x21
  _QWORD *v7; // x22
  bool v8; // cc
  int v9; // w25
  _QWORD *v10; // x8
  _QWORD *v11; // x26
  __int64 v12; // x0

  v3 = *(_QWORD *)(a1 + 104);
  v4 = a1 + 16;
  if ( (a2 & 1) != 0 )
    v5 = (void (__fastcall *)(_QWORD))&netif_receive_skb;
  else
    v5 = (void (__fastcall *)(_QWORD))&_netif_rx;
  v6 = raw_spin_lock_irqsave(v4);
  v7 = *(_QWORD **)(a1 + 24);
  if ( v7 != (_QWORD *)(a1 + 24) )
  {
    if ( v3 )
      v8 = v3 > 0xFFFFFFFFFFFFF000LL;
    else
      v8 = 1;
    v9 = v8;
    do
    {
      v11 = (_QWORD *)*v7;
      v10 = (_QWORD *)v7[1];
      if ( (_QWORD *)*v10 == v7 && (_QWORD *)v11[1] == v7 )
      {
        v11[1] = v10;
        *v10 = v11;
        *v7 = 0;
        v7[1] = 0;
        if ( v9 )
          goto LABEL_11;
      }
      else
      {
        _list_del_entry_valid_or_report(v7);
        *v7 = 0;
        v7[1] = 0;
        if ( v9 )
        {
LABEL_11:
          if ( *((_DWORD *)v5 - 1) != -1282094308 )
            __break(0x8237u);
          v5(v7);
          goto LABEL_14;
        }
      }
      if ( (unsigned int)rmnet_wlan_deliver_skb(v7, v3) )
      {
        if ( *((_DWORD *)v5 - 1) != -1282094308 )
          __break(0x8237u);
        v5(v7);
        v12 = 7;
      }
      else
      {
        v12 = 6;
      }
      rmnet_wlan_stats_update(v12);
LABEL_14:
      v7 = v11;
    }
    while ( v11 != (_QWORD *)(a1 + 24) );
  }
  return raw_spin_unlock_irqrestore(a1 + 16, v6);
}
