__int64 __fastcall ttlm_lock_create(__int64 a1)
{
  return qdf_mutex_create(a1 + 656);
}
