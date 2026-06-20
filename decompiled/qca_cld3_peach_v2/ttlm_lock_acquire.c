__int64 __fastcall ttlm_lock_acquire(__int64 a1)
{
  return qdf_mutex_acquire(a1 + 656);
}
