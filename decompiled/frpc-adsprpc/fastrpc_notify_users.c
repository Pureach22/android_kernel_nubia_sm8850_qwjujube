__int64 __fastcall fastrpc_notify_users(__int64 a1)
{
  __int64 *v2; // x20
  __int64 v3; // x8
  __int64 v4; // x9
  __int64 v5; // x9
  __int64 *v6; // x20
  __int64 v7; // x20
  __int64 v8; // x23
  __int64 v9; // x22
  __int64 i; // x21
  __int64 v11; // x0

  raw_spin_lock(a1 + 320);
  v2 = *(__int64 **)(a1 + 32);
  if ( v2 != (__int64 *)(a1 + 32) )
  {
    _ReadStatusReg(SP_EL0);
    do
    {
      v3 = v2[23];
      if ( *(int *)(v3 + 628) < 3
        || v3 && (v4 = *(_QWORD *)(v3 + 128)) != 0 && *(_DWORD *)(v4 + 64136)
        || (v5 = *(_QWORD *)(v3 + 184)) == 0
        || *(_QWORD *)(v5 + 24) == *(_QWORD *)(v5 + 32)
        || *(_DWORD *)(v3 + 268) == 3
        || *((_DWORD *)v2 + 40) != 1 )
      {
        *((_DWORD *)v2 + 6) = -32;
        *((_BYTE *)v2 + 96) = 1;
        complete(v2 + 14);
      }
      v2 = (__int64 *)*v2;
    }
    while ( v2 != (__int64 *)(a1 + 32) );
  }
  v6 = *(__int64 **)(a1 + 48);
  if ( v6 != (__int64 *)(a1 + 48) )
  {
    _ReadStatusReg(SP_EL0);
    do
    {
      *((_DWORD *)v6 + 6) = -32;
      *((_BYTE *)v6 + 96) = 1;
      complete(v6 + 14);
      v6 = (__int64 *)*v6;
    }
    while ( v6 != (__int64 *)(a1 + 48) );
  }
  v7 = raw_spin_lock_irqsave(a1 + 324);
  v8 = 0;
  _ReadStatusReg(SP_EL0);
  do
  {
    v9 = *(_QWORD *)(a1 + 504 + 8 * v8);
    if ( v9 )
    {
      for ( i = 0; i != 256; ++i )
      {
        v11 = v9 + 40 * i;
        if ( *(_DWORD *)(v11 + 32) == 1 )
        {
          *(_DWORD *)(v11 + 32) = 3;
          complete_all();
        }
      }
    }
    ++v8;
  }
  while ( v8 != 4 );
  raw_spin_unlock_irqrestore(a1 + 324, v7);
  return raw_spin_unlock(a1 + 320);
}
