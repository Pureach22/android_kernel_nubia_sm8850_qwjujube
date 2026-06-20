__int64 __fastcall qdf_spinlock_acquire(__int64 a1)
{
  raw_spin_lock(a1);
  return 0;
}
