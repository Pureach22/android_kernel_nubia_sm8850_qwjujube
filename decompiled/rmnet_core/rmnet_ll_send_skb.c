__int64 __fastcall rmnet_ll_send_skb(__int64 a1)
{
  __int64 (__fastcall *v2)(); // x8
  unsigned int v3; // w19

  raw_spin_lock_bh(&rmnet_ll_tx_lock);
  v2 = off_66A8[0];
  if ( *((_DWORD *)off_66A8[0] - 1) != -1282094308 )
    __break(0x8228u);
  v3 = ((__int64 (__fastcall *)(__int64))v2)(a1);
  raw_spin_unlock_bh(&rmnet_ll_tx_lock);
  ++rmnet_ll_stats[v3 != 0];
  return v3;
}
