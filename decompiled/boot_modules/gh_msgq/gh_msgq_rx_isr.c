__int64 __fastcall gh_msgq_rx_isr(__int64 a1, __int64 a2)
{
  raw_spin_lock(a2 + 60);
  *(_BYTE *)(a2 + 65) = 0;
  raw_spin_unlock(a2 + 60);
  _wake_up(a2 + 96, 1, 1, 0);
  return 1;
}
