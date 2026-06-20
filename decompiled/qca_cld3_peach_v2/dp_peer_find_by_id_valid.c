bool __fastcall dp_peer_find_by_id_valid(__int64 a1, unsigned __int16 a2)
{
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x20
  __int64 v6; // x8
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int v16; // w8
  unsigned int v23; // w10
  unsigned int v26; // w9

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 13304);
  }
  else
  {
    raw_spin_lock_bh(a1 + 13304);
    *(_QWORD *)(a1 + 13312) |= 1uLL;
  }
  if ( *(_DWORD *)(a1 + 13324) > (unsigned int)a2 )
  {
    v5 = *(_QWORD *)(*(_QWORD *)(a1 + 13136) + 8LL * a2);
    if ( !v5 )
      goto LABEL_9;
    if ( *(unsigned __int8 *)(v5 + 388) <= 2u )
    {
      v16 = *(_DWORD *)(v5 + 40);
      while ( v16 )
      {
        _X12 = (unsigned int *)(v5 + 40);
        __asm { PRFM            #0x11, [X12] }
        while ( 1 )
        {
          v23 = __ldxr(_X12);
          if ( v23 != v16 )
            break;
          if ( !__stlxr(v16 + 1, _X12) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v23 == v16;
        v16 = v23;
        if ( _ZF )
        {
          _X8 = (unsigned int *)(v5 + 316);
          __asm { PRFM            #0x11, [X8] }
          do
            v26 = __ldxr(_X8);
          while ( __stxr(v26 + 1, _X8) );
          goto LABEL_9;
        }
      }
    }
  }
  v5 = 0;
LABEL_9:
  v6 = *(_QWORD *)(a1 + 13312);
  if ( (v6 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 13312) = v6 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 13304);
    if ( !v5 )
      return v5 != 0;
    goto LABEL_11;
  }
  raw_spin_unlock(a1 + 13304);
  if ( v5 )
LABEL_11:
    dp_peer_unref_delete(v5, 0xDu, v7, v8, v9, v10, v11, v12, v13, v14);
  return v5 != 0;
}
