__int64 __fastcall rmnet_map_tx_qmap_cmd(__int64 a1, unsigned __int8 a2, char a3)
{
  __int64 v4; // x0
  unsigned __int8 v6; // w21
  __int64 port; // x0
  __int64 v8; // x21
  void (*v9)(void); // x8
  __int64 (__fastcall *v11)(_QWORD); // x8

  v4 = *(_QWORD *)(a1 + 16);
  if ( a2 >= 2u )
    v6 = 0;
  else
    v6 = a2;
  port = rmnet_get_port(v4);
  if ( !port )
    return sk_skb_reason_drop(0, a1, 2);
  v8 = port + 200LL * v6 + 2072;
  if ( (a3 & 1) != 0 && (*(_DWORD *)(port + 8) & 0x80000000) != 0 )
  {
    raw_spin_lock_bh(v8 + 136);
    if ( *(_QWORD *)(v8 + 144) )
    {
      v9 = *(void (**)(void))(v8 + 152);
      *(_QWORD *)(v8 + 144) = 0;
      *(_BYTE *)(v8 + 164) = 0;
      *(_QWORD *)(v8 + 8) = 0;
      *(_QWORD *)(v8 + 16) = 0;
      *(_DWORD *)(v8 + 160) = 0;
      if ( *((_DWORD *)v9 - 1) != -1282094308 )
        __break(0x8228u);
      v9();
      raw_spin_unlock_bh(v8 + 136);
      hrtimer_cancel(v8 + 40);
    }
    else
    {
      raw_spin_unlock_bh(v8 + 136);
    }
  }
  v11 = *(__int64 (__fastcall **)(_QWORD))(v8 + 152);
  if ( *((_DWORD *)v11 - 1) != -1282094308 )
    __break(0x8228u);
  return v11(a1);
}
