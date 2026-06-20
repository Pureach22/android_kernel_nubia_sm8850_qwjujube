__int64 __fastcall qdf_spinlock_release(__int64 a1)
{
  raw_spin_unlock(a1);
  return 0;
}
