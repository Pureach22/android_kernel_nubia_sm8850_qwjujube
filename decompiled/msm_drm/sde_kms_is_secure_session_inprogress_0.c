__int64 __fastcall sde_kms_is_secure_session_inprogress_0(__int64 a1)
{
  unsigned int v2; // w8
  unsigned int v3; // w20
  unsigned int v4; // w8

  if ( a1 && *(_QWORD *)(a1 + 152) )
  {
    mutex_lock(a1 + 3696);
    if ( (*(_QWORD *)(*(_QWORD *)(a1 + 152) + 22008LL) & 0x400000000LL) == 0
      || *(_DWORD *)(a1 + 3664) != 1
      || (v2 = *(_DWORD *)(a1 + 3656), v2 > 6)
      || (LOBYTE(v3) = 1, ((1 << v2) & 0x64) == 0) )
    {
      v4 = *(_DWORD *)(a1 + 3656);
      if ( v4 > 4 )
        LOBYTE(v3) = 0;
      else
        v3 = 0x1Au >> v4;
    }
    mutex_unlock(a1 + 3696);
  }
  else
  {
    LOBYTE(v3) = 0;
  }
  return v3 & 1;
}
