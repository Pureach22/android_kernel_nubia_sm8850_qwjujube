__int64 __fastcall slim_free_txn_tid(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 v5; // x1
  __int64 v6; // x19

  v4 = raw_spin_lock_irqsave(a1 + 168);
  v5 = *(unsigned __int8 *)(a2 + 6);
  v6 = v4;
  idr_remove(a1 + 144, v5);
  return raw_spin_unlock_irqrestore(a1 + 168, v6);
}
