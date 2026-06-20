__int64 __fastcall fastrpc_set_dsp_recovery_mode(__int64 a1, int a2)
{
  raw_spin_lock(a1 + 320);
  *(_BYTE *)(a1 + 636) = a2 != 0;
  return raw_spin_unlock(a1 + 320);
}
