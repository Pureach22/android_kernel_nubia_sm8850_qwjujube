__int64 __fastcall ccid_ctrl_open(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v4; // x19
  __int64 v5; // x20
  __int64 v7; // x0

  v2 = *(_QWORD *)(a1 + 656);
  if ( !*(_DWORD *)(v2 - 96) )
    return 4294967277LL;
  if ( *(_DWORD *)(v2 - 56) )
    return 4294967280LL;
  v4 = v2 - 100;
  v5 = v2 - 328;
  *(_DWORD *)(v2 - 56) = 1;
  v7 = raw_spin_lock_irqsave(v2 - 100);
  *(_QWORD *)(a2 + 32) = v5;
  raw_spin_unlock_irqrestore(v4, v7);
  return 0;
}
