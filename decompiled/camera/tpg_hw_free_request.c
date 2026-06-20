__int64 __fastcall tpg_hw_free_request(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v4; // x20

  result = 4294967274LL;
  if ( a1 )
  {
    if ( a2 )
    {
      v4 = a2;
      mutex_lock(a1 + 48);
      LODWORD(v4) = tpg_hw_release_vc_slots_locked(a1, v4);
      mutex_unlock(a1 + 48);
      return (unsigned int)v4;
    }
  }
  return result;
}
