__int64 __fastcall dp_get_peer_mac_from_peer_id(__int64 a1, unsigned __int16 a2, void *a3)
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v8; // x21
  __int64 v9; // x8
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int v18; // w8
  unsigned int v25; // w10
  unsigned int v28; // w9

  result = 16;
  if ( !a1 || !a3 )
    return result;
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
  if ( *(_DWORD *)(a1 + 13324) <= (unsigned int)a2 )
    goto LABEL_10;
  v8 = *(_QWORD *)(*(_QWORD *)(a1 + 13136) + 8LL * a2);
  if ( v8 )
  {
    if ( *(unsigned __int8 *)(v8 + 388) <= 2u )
    {
      v18 = *(_DWORD *)(v8 + 40);
      while ( v18 )
      {
        _X12 = (unsigned int *)(v8 + 40);
        __asm { PRFM            #0x11, [X12] }
        while ( 1 )
        {
          v25 = __ldxr(_X12);
          if ( v25 != v18 )
            break;
          if ( !__stlxr(v18 + 1, _X12) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v25 == v18;
        v18 = v25;
        if ( _ZF )
        {
          _X8 = (unsigned int *)(v8 + 292);
          __asm { PRFM            #0x11, [X8] }
          do
            v28 = __ldxr(_X8);
          while ( __stxr(v28 + 1, _X8) );
          goto LABEL_11;
        }
      }
    }
LABEL_10:
    v8 = 0;
  }
LABEL_11:
  v9 = *(_QWORD *)(a1 + 13312);
  if ( (v9 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 13312) = v9 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 13304);
    if ( v8 )
      goto LABEL_13;
  }
  else
  {
    raw_spin_unlock(a1 + 13304);
    if ( v8 )
    {
LABEL_13:
      qdf_mem_copy(a3, (const void *)(v8 + 44), 6u);
      dp_peer_unref_delete(v8, 7u, v10, v11, v12, v13, v14, v15, v16, v17);
      return 0;
    }
  }
  return 16;
}
