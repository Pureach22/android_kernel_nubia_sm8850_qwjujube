__int64 __fastcall slim_alloc_txn_tid(__int64 a1, __int64 a2)
{
  __int64 v4; // x20
  unsigned int v5; // w22

  v4 = raw_spin_lock_irqsave(a1 + 168);
  v5 = idr_alloc_cyclic(a1 + 144, a2, 1, 256, 2080);
  if ( (v5 & 0x80000000) == 0 )
  {
    *(_BYTE *)(a2 + 6) = v5;
    v5 = 0;
  }
  raw_spin_unlock_irqrestore(a1 + 168, v4);
  return v5;
}
