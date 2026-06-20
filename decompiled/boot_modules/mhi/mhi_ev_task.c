__int64 __fastcall mhi_ev_task(__int64 *a1)
{
  __int64 v2; // x20
  void (__fastcall *v3)(__int64, __int64 *, __int64); // x8

  v2 = *a1;
  raw_spin_lock_bh(a1 + 30);
  v3 = (void (__fastcall *)(__int64, __int64 *, __int64))a1[31];
  if ( *((_DWORD *)v3 - 1) != 1550939421 )
    __break(0x8228u);
  v3(v2, a1, 0xFFFFFFFFLL);
  return raw_spin_unlock_bh(a1 + 30);
}
