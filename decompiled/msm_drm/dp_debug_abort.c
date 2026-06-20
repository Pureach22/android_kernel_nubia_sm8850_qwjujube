__int64 __fastcall dp_debug_abort(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x20

  if ( result )
  {
    v1 = result - 160;
    v2 = result;
    mutex_lock(result + 216);
    *(_BYTE *)(v2 - 136) = 0;
    dp_debug_set_sim_mode(v1, 0);
    return mutex_unlock(v2 + 216);
  }
  return result;
}
