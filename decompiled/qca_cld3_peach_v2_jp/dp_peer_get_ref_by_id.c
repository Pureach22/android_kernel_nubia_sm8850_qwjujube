__int64 __fastcall dp_peer_get_ref_by_id(__int64 a1, unsigned __int16 a2, unsigned int a3)
{
  unsigned __int64 StatusReg; // x8
  __int64 v7; // x8
  __int64 v8; // x8
  unsigned int v10; // w9
  unsigned int v17; // w11
  __int64 v19; // x20
  __int64 v20; // x8
  unsigned int v22; // w10

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 13256);
  }
  else
  {
    raw_spin_lock_bh(a1 + 13256);
    *(_QWORD *)(a1 + 13264) |= 1uLL;
  }
  if ( *(_DWORD *)(a1 + 13276) > (unsigned int)a2 )
  {
    v7 = *(_QWORD *)(*(_QWORD *)(a1 + 13088) + 8LL * a2);
    if ( v7 )
    {
      if ( *(unsigned __int8 *)(v7 + 380) <= 2u )
      {
        v10 = *(_DWORD *)(v7 + 40);
        while ( v10 )
        {
          _X13 = (unsigned int *)(v7 + 40);
          __asm { PRFM            #0x11, [X13] }
          while ( 1 )
          {
            v17 = __ldxr(_X13);
            if ( v17 != v10 )
              break;
            if ( !__stlxr(v10 + 1, _X13) )
            {
              __dmb(0xBu);
              break;
            }
          }
          _ZF = v17 == v10;
          v10 = v17;
          if ( _ZF )
          {
            if ( a3 >= 3 )
            {
              _X9 = (unsigned int *)(v7 + 4LL * a3 + 256);
              __asm { PRFM            #0x11, [X9] }
              do
                v22 = __ldxr(_X9);
              while ( __stxr(v22 + 1, _X9) );
            }
            v19 = v7;
            v20 = *(_QWORD *)(a1 + 13264);
            if ( (v20 & 1) != 0 )
            {
              *(_QWORD *)(a1 + 13264) = v20 & 0xFFFFFFFFFFFFFFFELL;
              raw_spin_unlock_bh(a1 + 13256);
            }
            else
            {
              raw_spin_unlock(a1 + 13256);
            }
            return v19;
          }
        }
      }
    }
  }
  v8 = *(_QWORD *)(a1 + 13264);
  if ( (v8 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 13264) = v8 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 13256);
  }
  else
  {
    raw_spin_unlock(a1 + 13256);
  }
  return 0;
}
