__int64 __fastcall dp_sim_set_sim_mode(__int64 a1, int a2)
{
  if ( !a1 || (*(_DWORD *)(a1 + 16) & 0x80000000) == 0 )
    return 4294967274LL;
  mutex_lock(a1 + 80);
  *(_DWORD *)(a1 + 2256) = a2;
  mutex_unlock(a1 + 80);
  return 0;
}
