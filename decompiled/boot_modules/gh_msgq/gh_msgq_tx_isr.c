__int64 __fastcall gh_msgq_tx_isr(__int64 a1, __int64 a2)
{
  raw_spin_lock(a2 + 56);
  *(_BYTE *)(a2 + 64) = 0;
  raw_spin_unlock(a2 + 56);
  _wake_up(a2 + 72, 1, 1, 0);
  return 1;
}
