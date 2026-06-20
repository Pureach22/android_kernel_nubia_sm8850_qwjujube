__int64 __fastcall sme_acquire_global_lock(__int64 a1)
{
  if ( a1 )
    return qdf_mutex_acquire(a1 + 8);
  else
    return 4;
}
