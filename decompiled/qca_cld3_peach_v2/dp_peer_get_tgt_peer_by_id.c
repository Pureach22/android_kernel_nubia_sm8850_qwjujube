__int64 __fastcall dp_peer_get_tgt_peer_by_id(__int64 a1, unsigned __int16 a2)
{
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x19
  __int64 v6; // x8
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x8
  unsigned int v16; // w9
  unsigned int v23; // w11
  __int64 v24; // x20
  unsigned int v26; // w8
  unsigned int v29; // w10

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
      v26 = *(_DWORD *)(v5 + 40);
      while ( v26 )
      {
        _X12 = (unsigned int *)(v5 + 40);
        __asm { PRFM            #0x11, [X12] }
        while ( 1 )
        {
          v29 = __ldxr(_X12);
          if ( v29 != v26 )
            break;
          if ( !__stlxr(v26 + 1, _X12) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v29 == v26;
        v26 = v29;
        if ( _ZF )
          goto LABEL_9;
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
      return v5;
  }
  else
  {
    raw_spin_unlock(a1 + 13304);
    if ( !v5 )
      return v5;
  }
  if ( *(_DWORD *)(v5 + 408) == 1 )
  {
    v15 = *(_QWORD *)(v5 + 416);
    if ( v15 )
    {
      v16 = *(_DWORD *)(v15 + 40);
      while ( v16 )
      {
        _X13 = (unsigned int *)(v15 + 40);
        __asm { PRFM            #0x11, [X13] }
        while ( 1 )
        {
          v23 = __ldxr(_X13);
          if ( v23 != v16 )
            break;
          if ( !__stlxr(v16 + 1, _X13) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v23 == v16;
        v16 = v23;
        if ( _ZF )
        {
          v24 = *(_QWORD *)(v5 + 416);
          goto LABEL_23;
        }
      }
      v24 = 0;
LABEL_23:
      dp_peer_unref_delete(v5, 2u, v7, v8, v9, v10, v11, v12, v13, v14);
      return v24;
    }
  }
  return v5;
}
