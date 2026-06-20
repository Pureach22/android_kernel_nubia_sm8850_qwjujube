__int64 __fastcall dp_peer_get_ast_info_by_pdevid_wifi3(__int64 a1, __int64 a2, unsigned int a3, __int64 a4)
{
  unsigned __int64 StatusReg; // x8
  __int64 v9; // x0
  __int64 v10; // x21
  unsigned int v11; // w22
  unsigned __int64 v12; // x8
  __int64 v13; // x22
  __int64 v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x8
  unsigned int v25; // w8
  unsigned int v32; // w10
  __int64 v34; // x8
  unsigned int v36; // w9

  if ( (*(_BYTE *)(a1 + 17706) & 1) != 0 )
    return 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 17632);
  }
  else
  {
    raw_spin_lock_bh(a1 + 17632);
    *(_QWORD *)(a1 + 17640) |= 1uLL;
  }
  v9 = dp_peer_ast_hash_find_by_pdevid(a1, a2, a3);
  if ( !v9 )
    goto LABEL_33;
  v10 = v9;
  if ( *(_BYTE *)(v9 + 28) == 1 && !*(_QWORD *)(v9 + 32) )
    goto LABEL_33;
  v11 = *(unsigned __int16 *)(v9 + 2);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v12 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v12 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v12 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 13304);
  }
  else
  {
    raw_spin_lock_bh(a1 + 13304);
    *(_QWORD *)(a1 + 13312) |= 1uLL;
  }
  if ( *(_DWORD *)(a1 + 13324) > v11 )
  {
    v13 = *(_QWORD *)(*(_QWORD *)(a1 + 13136) + 8LL * v11);
    if ( !v13 )
      goto LABEL_17;
    if ( *(unsigned __int8 *)(v13 + 388) <= 2u )
    {
      v25 = *(_DWORD *)(v13 + 40);
      while ( v25 )
      {
        _X12 = (unsigned int *)(v13 + 40);
        __asm { PRFM            #0x11, [X12] }
        while ( 1 )
        {
          v32 = __ldxr(_X12);
          if ( v32 != v25 )
            break;
          if ( !__stlxr(v25 + 1, _X12) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v32 == v25;
        v25 = v32;
        if ( _ZF )
        {
          _X8 = (unsigned int *)(v13 + 324);
          __asm { PRFM            #0x11, [X8] }
          do
            v36 = __ldxr(_X8);
          while ( __stxr(v36 + 1, _X8) );
          goto LABEL_17;
        }
      }
    }
  }
  v13 = 0;
LABEL_17:
  v14 = *(_QWORD *)(a1 + 13312);
  if ( (v14 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 13312) = v14 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 13304);
    if ( v13 )
      goto LABEL_19;
    goto LABEL_33;
  }
  raw_spin_unlock(a1 + 13304);
  if ( !v13 )
  {
LABEL_33:
    v34 = *(_QWORD *)(a1 + 17640);
    if ( (v34 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 17640) = v34 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 17632);
    }
    else
    {
      raw_spin_unlock(a1 + 17632);
    }
    return 0;
  }
LABEL_19:
  *(_DWORD *)(a4 + 8) = *(_DWORD *)(v10 + 24);
  *(_BYTE *)(a4 + 13) = *(_BYTE *)(v10 + 15);
  *(_BYTE *)(a4 + 12) = *(_BYTE *)(v10 + 16);
  *(_WORD *)(a4 + 14) = *(_WORD *)(v10 + 2);
  qdf_mem_copy((void *)a4, (const void *)(v13 + 44), 6u);
  dp_peer_unref_delete(v13, 0xFu, v15, v16, v17, v18, v19, v20, v21, v22);
  v23 = *(_QWORD *)(a1 + 17640);
  if ( (v23 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 17640) = v23 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 17632);
  }
  else
  {
    raw_spin_unlock(a1 + 17632);
  }
  return 1;
}
