__int64 __fastcall rndis_get_next_response(__int64 a1, _DWORD *a2)
{
  __int64 *v4; // x21
  int v5; // w9

  if ( !a2 )
    return 0;
  raw_spin_lock(a1 + 96);
  v4 = (__int64 *)(a1 + 80);
  while ( 1 )
  {
    v4 = (__int64 *)*v4;
    if ( v4 == (__int64 *)(a1 + 80) )
      break;
    if ( !*((_DWORD *)v4 + 7) )
    {
      v5 = *((_DWORD *)v4 + 6);
      *((_DWORD *)v4 + 7) = 1;
      *a2 = v5;
      raw_spin_unlock(a1 + 96);
      return v4[2];
    }
  }
  raw_spin_unlock(a1 + 96);
  return 0;
}
