__int64 __fastcall rmnet_map_send_agg_skb(__int64 a1)
{
  __int64 v1; // x8
  void (__fastcall *v2)(_QWORD); // x9

  v1 = *(_QWORD *)(a1 + 144);
  if ( !v1 )
    return raw_spin_unlock_bh(a1 + 136);
  v2 = *(void (__fastcall **)(_QWORD))(a1 + 152);
  *(_QWORD *)(a1 + 144) = 0;
  *(_BYTE *)(a1 + 164) = 0;
  *(_QWORD *)(a1 + 8) = 0;
  *(_QWORD *)(a1 + 16) = 0;
  *(_DWORD *)(a1 + 160) = 0;
  if ( *((_DWORD *)v2 - 1) != -1282094308 )
    __break(0x8229u);
  v2(v1);
  raw_spin_unlock_bh(a1 + 136);
  return hrtimer_cancel(a1 + 40);
}
