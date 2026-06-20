__int64 __fastcall tmc_etr_byte_cntr_start(__int64 result)
{
  __int64 v1; // x19

  if ( result )
  {
    v1 = result;
    mutex_lock(result + 312);
    if ( *(_DWORD *)(v1 + 152) )
    {
      if ( (*(_BYTE *)(v1 + 145) & 1) == 0 )
      {
        *(_DWORD *)(v1 + 160) = 0;
        *(_BYTE *)(v1 + 144) = 1;
      }
    }
    return mutex_unlock(v1 + 312);
  }
  return result;
}
