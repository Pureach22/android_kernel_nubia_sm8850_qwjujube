__int64 __fastcall dp_peer_get_ref_by_id_4(__int64 a1, unsigned __int16 a2)
{
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x8
  __int64 v6; // x8
  unsigned int v8; // w9
  unsigned int v15; // w11
  __int64 v16; // x20
  __int64 v17; // x8
  unsigned int v20; // w10

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
    v5 = *(_QWORD *)(*(_QWORD *)(a1 + 13088) + 8LL * a2);
    if ( v5 )
    {
      if ( *(unsigned __int8 *)(v5 + 380) <= 2u )
      {
        v8 = *(_DWORD *)(v5 + 40);
        while ( v8 )
        {
          _X13 = (unsigned int *)(v5 + 40);
          __asm { PRFM            #0x11, [X13] }
          while ( 1 )
          {
            v15 = __ldxr(_X13);
            if ( v15 != v8 )
              break;
            if ( !__stlxr(v8 + 1, _X13) )
            {
              __dmb(0xBu);
              break;
            }
          }
          _ZF = v15 == v8;
          v8 = v15;
          if ( _ZF )
          {
            _X9 = (unsigned int *)(v5 + 280);
            __asm { PRFM            #0x11, [X9] }
            do
              v20 = __ldxr(_X9);
            while ( __stxr(v20 + 1, _X9) );
            v16 = v5;
            v17 = *(_QWORD *)(a1 + 13264);
            if ( (v17 & 1) != 0 )
            {
              *(_QWORD *)(a1 + 13264) = v17 & 0xFFFFFFFFFFFFFFFELL;
              raw_spin_unlock_bh(a1 + 13256);
            }
            else
            {
              raw_spin_unlock(a1 + 13256);
            }
            return v16;
          }
        }
      }
    }
  }
  v6 = *(_QWORD *)(a1 + 13264);
  if ( (v6 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 13264) = v6 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 13256);
  }
  else
  {
    raw_spin_unlock(a1 + 13256);
  }
  return 0;
}
