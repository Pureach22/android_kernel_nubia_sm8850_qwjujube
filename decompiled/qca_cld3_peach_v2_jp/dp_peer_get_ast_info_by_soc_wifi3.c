__int64 __fastcall dp_peer_get_ast_info_by_soc_wifi3(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int64 StatusReg; // x8
  __int64 soc; // x0
  __int64 v8; // x21
  unsigned int v9; // w22
  unsigned __int64 v10; // x8
  __int64 v11; // x22
  __int64 v12; // x8
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8
  unsigned int v23; // w8
  unsigned int v30; // w10
  __int64 v32; // x8
  unsigned int v34; // w9

  if ( (*(_BYTE *)(a1 + 17650) & 1) != 0 )
    return 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 17576);
  }
  else
  {
    raw_spin_lock_bh(a1 + 17576);
    *(_QWORD *)(a1 + 17584) |= 1uLL;
  }
  soc = dp_peer_ast_hash_find_soc(a1, a2);
  if ( !soc )
    goto LABEL_33;
  v8 = soc;
  if ( *(_BYTE *)(soc + 28) == 1 && !*(_QWORD *)(soc + 32) )
    goto LABEL_33;
  v9 = *(unsigned __int16 *)(soc + 2);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v10 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v10 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 13256);
  }
  else
  {
    raw_spin_lock_bh(a1 + 13256);
    *(_QWORD *)(a1 + 13264) |= 1uLL;
  }
  if ( *(_DWORD *)(a1 + 13276) > v9 )
  {
    v11 = *(_QWORD *)(*(_QWORD *)(a1 + 13088) + 8LL * v9);
    if ( !v11 )
      goto LABEL_17;
    if ( *(unsigned __int8 *)(v11 + 380) <= 2u )
    {
      v23 = *(_DWORD *)(v11 + 40);
      while ( v23 )
      {
        _X12 = (unsigned int *)(v11 + 40);
        __asm { PRFM            #0x11, [X12] }
        while ( 1 )
        {
          v30 = __ldxr(_X12);
          if ( v30 != v23 )
            break;
          if ( !__stlxr(v23 + 1, _X12) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v30 == v23;
        v23 = v30;
        if ( _ZF )
        {
          _X8 = (unsigned int *)(v11 + 316);
          __asm { PRFM            #0x11, [X8] }
          do
            v34 = __ldxr(_X8);
          while ( __stxr(v34 + 1, _X8) );
          goto LABEL_17;
        }
      }
    }
  }
  v11 = 0;
LABEL_17:
  v12 = *(_QWORD *)(a1 + 13264);
  if ( (v12 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 13264) = v12 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 13256);
    if ( v11 )
      goto LABEL_19;
    goto LABEL_33;
  }
  raw_spin_unlock(a1 + 13256);
  if ( !v11 )
  {
LABEL_33:
    v32 = *(_QWORD *)(a1 + 17584);
    if ( (v32 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 17584) = v32 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 17576);
    }
    else
    {
      raw_spin_unlock(a1 + 17576);
    }
    return 0;
  }
LABEL_19:
  *(_DWORD *)(a3 + 8) = *(_DWORD *)(v8 + 24);
  *(_BYTE *)(a3 + 13) = *(_BYTE *)(v8 + 15);
  *(_BYTE *)(a3 + 12) = *(_BYTE *)(v8 + 16);
  *(_WORD *)(a3 + 14) = *(_WORD *)(v8 + 2);
  qdf_mem_copy((void *)a3, (const void *)(v11 + 44), 6u);
  dp_peer_unref_delete(v11, 0xFu, v13, v14, v15, v16, v17, v18, v19, v20);
  v21 = *(_QWORD *)(a1 + 17584);
  if ( (v21 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 17584) = v21 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 17576);
  }
  else
  {
    raw_spin_unlock(a1 + 17576);
  }
  return 1;
}
