__int64 __fastcall zs_page_migrate(unsigned __int64 a1, __int64 a2)
{
  int *v2; // x21
  unsigned int *v5; // x23
  __int64 v7; // x24
  unsigned __int64 v8; // x10
  unsigned __int64 StatusReg; // x25
  __int64 v10; // x26
  unsigned __int64 v11; // x22
  __int64 v12; // x0
  __int64 v13; // x8
  unsigned __int64 *v14; // x10
  int v15; // w13
  unsigned __int64 v16; // x13
  __int64 v17; // x8
  __int64 v18; // x9
  int v19; // w10
  int v20; // w11
  unsigned __int64 v21; // x9
  unsigned __int64 v22; // x11
  int v23; // w12
  unsigned __int64 v24; // x12
  int v25; // w13
  unsigned __int64 v26; // x13
  int v27; // w14
  unsigned __int64 v28; // x14
  int v29; // w15
  unsigned __int64 v30; // x15
  int v31; // w16
  __int64 v32; // x16
  int v33; // w17
  int v34; // w16
  __int64 v35; // x9
  __int64 v36; // x8
  unsigned int v40; // w9
  unsigned __int64 v42; // x9
  unsigned int v45; // w20
  unsigned int v46; // w20
  unsigned __int64 v52; // x17

  _X19 = a2;
  if ( *(unsigned __int8 *)(a1 + 51) != 246 )
    *(_DWORD *)(a1 + 48) = -167772160;
  v5 = *(unsigned int **)(a2 + 40);
  _X8 = *v5 & 0x3FC000;
  if ( (_DWORD)_X8 != 1441792 )
    goto LABEL_113;
  v7 = *((_QWORD *)v5 + 5);
  raw_write_lock(v7 + 2120);
  _X8 = ((unsigned __int64)*v5 >> 5) & 0x1FF;
  if ( (unsigned int)_X8 >= 0xFF )
    goto LABEL_66;
  v2 = *(int **)(v7 + 8 * _X8 + 8);
  raw_spin_lock(v2);
  raw_write_lock(v5 + 12);
  StatusReg = _ReadStatusReg(SP_EL0);
  v10 = *(unsigned __int16 *)(_X19 + 48);
  ++*(_DWORD *)(StatusReg + 16);
  ++*(_DWORD *)(StatusReg + 3220);
  ++*(_DWORD *)(StatusReg + 16);
  ++*(_DWORD *)(StatusReg + 3220);
  v11 = ((_X19 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL;
  v12 = copy_page(((a1 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL, v11);
  --*(_DWORD *)(StatusReg + 3220);
  v13 = *(_QWORD *)(StatusReg + 16) - 1LL;
  *(_DWORD *)(StatusReg + 16) = v13;
  if ( !v13 || !*(_QWORD *)(StatusReg + 16) )
    v12 = preempt_schedule(v12);
  _X8 = v11 + v10;
  if ( v11 + v10 < v11 + 4096 )
  {
    v14 = (unsigned __int64 *)(_X19 + 32);
    while ( 1 )
    {
      v15 = **(_DWORD **)(_X19 + 40);
      if ( (v15 & 0x3FC000) != 0x160000 )
      {
        __break(0x800u);
        goto LABEL_111;
      }
      if ( (v15 & 1) != 0 )
        break;
      v16 = *(_QWORD *)_X8;
      if ( (*(_QWORD *)_X8 & 1) != 0 )
        goto LABEL_13;
LABEL_9:
      _X8 += v2[50];
      if ( _X8 >= v11 + 4096 )
        goto LABEL_16;
    }
    v16 = *v14;
    if ( (*v14 & 1) == 0 )
      goto LABEL_9;
LABEL_13:
    *(_QWORD *)(v16 & 0xFFFFFFFFFFFFFFFELL) = (((a1 - -64LL * (memstart_addr >> 12)) << 18) + 0x5000000000000LL)
                                            | *(_QWORD *)(v16 & 0xFFFFFFFFFFFFFFFELL) & 0xFFFFFFLL;
    goto LABEL_9;
  }
LABEL_16:
  --*(_DWORD *)(StatusReg + 3220);
  v17 = *(_QWORD *)(StatusReg + 16) - 1LL;
  *(_DWORD *)(StatusReg + 16) = v17;
  if ( !v17 || !*(_QWORD *)(StatusReg + 16) )
    preempt_schedule(v12);
  v18 = *((_QWORD *)v5 + 2);
  v19 = **(_DWORD **)(v18 + 40);
  if ( v18 == _X19 )
    _X8 = a1;
  else
    _X8 = *((_QWORD *)v5 + 2);
  if ( (v19 & 0x3FC000) != 0x160000 )
    goto LABEL_112;
  if ( (v19 & 1) != 0 )
  {
    v21 = 0;
    goto LABEL_107;
  }
  v8 = *(_QWORD *)(v18 + 32);
  if ( !v8 )
  {
LABEL_67:
    v21 = 0;
    goto LABEL_68;
  }
  v20 = **(_DWORD **)(v8 + 40);
  if ( v8 == _X19 )
    v21 = a1;
  else
    v21 = *(_QWORD *)(v18 + 32);
  if ( (v20 & 0x3FC000) != 0x160000 )
    goto LABEL_112;
  if ( (v20 & 1) != 0 )
  {
LABEL_107:
    v8 = 0;
    goto LABEL_68;
  }
  v22 = *(_QWORD *)(v8 + 32);
  if ( !v22 )
  {
    v8 = 0;
    goto LABEL_70;
  }
  v23 = **(_DWORD **)(v22 + 40);
  if ( v22 == _X19 )
    v8 = a1;
  else
    v8 = *(_QWORD *)(v8 + 32);
  if ( (v23 & 0x3FC000) != 0x160000 )
    goto LABEL_112;
  if ( (v23 & 1) != 0 )
  {
LABEL_68:
    v22 = 0;
    goto LABEL_70;
  }
  v24 = *(_QWORD *)(v22 + 32);
  if ( !v24 )
  {
    v22 = 0;
    v26 = 0;
    goto LABEL_72;
  }
  v25 = **(_DWORD **)(v24 + 40);
  v22 = v24 == _X19 ? a1 : *(_QWORD *)(v22 + 32);
  if ( (v25 & 0x3FC000) != 0x160000 )
    goto LABEL_112;
  if ( (v25 & 1) != 0 )
  {
LABEL_70:
    v24 = 0;
    goto LABEL_71;
  }
  v26 = *(_QWORD *)(v24 + 32);
  if ( !v26 )
  {
    v24 = 0;
    goto LABEL_72;
  }
  v27 = **(_DWORD **)(v26 + 40);
  v24 = v26 == _X19 ? a1 : *(_QWORD *)(v24 + 32);
  if ( (v27 & 0x3FC000) != 0x160000 )
    goto LABEL_112;
  if ( (v27 & 1) != 0 )
  {
LABEL_71:
    v26 = 0;
    goto LABEL_72;
  }
  v28 = *(_QWORD *)(v26 + 32);
  if ( !v28 )
  {
    v26 = 0;
    goto LABEL_73;
  }
  v29 = **(_DWORD **)(v28 + 40);
  v26 = v28 == _X19 ? a1 : *(_QWORD *)(v26 + 32);
  if ( (v29 & 0x3FC000) != 0x160000 )
    goto LABEL_112;
  if ( (v29 & 1) != 0 )
  {
LABEL_72:
    v28 = 0;
LABEL_73:
    v30 = 0;
    goto LABEL_74;
  }
  v30 = *(_QWORD *)(v28 + 32);
  if ( !v30 )
  {
    v28 = 0;
    goto LABEL_74;
  }
  v31 = **(_DWORD **)(v30 + 40);
  v28 = v30 == _X19 ? a1 : *(_QWORD *)(v28 + 32);
  if ( (v31 & 0x3FC000) != 0x160000 )
    goto LABEL_112;
  if ( (v31 & 1) != 0 )
    goto LABEL_73;
  v32 = *(_QWORD *)(v30 + 32);
  if ( !v32 )
    goto LABEL_73;
  v33 = **(_DWORD **)(v32 + 40);
  v30 = v32 == _X19 ? a1 : *(_QWORD *)(v30 + 32);
  if ( (v33 & 0x3FC000) != 0x160000 )
  {
LABEL_112:
    __break(0x800u);
LABEL_113:
    __break(0x800u);
    goto LABEL_114;
  }
  if ( (v33 & 1) == 0 && *(_QWORD *)(v32 + 32) )
  {
LABEL_66:
    __break(0x5512u);
    goto LABEL_67;
  }
LABEL_74:
  v34 = v2[52];
  if ( v34 >= 1 )
  {
    *(_QWORD *)(_X8 + 32) = 0;
    *(_QWORD *)(_X8 + 40) = v5;
    *((_QWORD *)v5 + 2) = _X8;
    __asm { PRFM            #0x11, [X8] }
    do
      v52 = __ldxr((unsigned __int64 *)_X8);
    while ( __stxr(v52 | 0x8000, (unsigned __int64 *)_X8) );
    if ( v2[51] == 1 && v2[52] == 1 )
    {
      *v5 |= 1u;
      if ( v34 != 1 )
      {
LABEL_79:
        *(_QWORD *)(v21 + 32) = 0;
        *(_QWORD *)(v21 + 40) = v5;
        *(_QWORD *)(_X8 + 32) = v21;
        if ( v34 == 2 )
          goto LABEL_86;
        *(_QWORD *)(v8 + 32) = 0;
        *(_QWORD *)(v8 + 40) = v5;
        *(_QWORD *)(v21 + 32) = v8;
        if ( v34 == 3 )
          goto LABEL_86;
        *(_QWORD *)(v22 + 32) = 0;
        *(_QWORD *)(v22 + 40) = v5;
        *(_QWORD *)(v8 + 32) = v22;
        if ( v34 == 4 )
          goto LABEL_86;
        *(_QWORD *)(v24 + 32) = 0;
        *(_QWORD *)(v24 + 40) = v5;
        *(_QWORD *)(v22 + 32) = v24;
        if ( v34 == 5 )
          goto LABEL_86;
        *(_QWORD *)(v26 + 32) = 0;
        *(_QWORD *)(v26 + 40) = v5;
        *(_QWORD *)(v24 + 32) = v26;
        if ( v34 == 6 )
          goto LABEL_86;
        *(_QWORD *)(v28 + 32) = 0;
        *(_QWORD *)(v28 + 40) = v5;
        *(_QWORD *)(v26 + 32) = v28;
        if ( v34 == 7 )
          goto LABEL_86;
        *(_QWORD *)(v30 + 32) = 0;
        *(_QWORD *)(v30 + 40) = v5;
        *(_QWORD *)(v28 + 32) = v30;
        if ( v34 == 8 )
          goto LABEL_86;
LABEL_111:
        __break(1u);
        goto LABEL_112;
      }
    }
    else if ( v34 != 1 )
    {
      goto LABEL_79;
    }
  }
LABEL_86:
  *(_WORD *)(a1 + 48) = *(_DWORD *)(_X19 + 48);
  if ( (*(_BYTE *)v5 & 1) != 0 )
    *(_QWORD *)(a1 + 32) = *(_QWORD *)(_X19 + 32);
  _SetPageMovable(a1, zsmalloc_mops);
  raw_write_unlock(v7 + 2120);
  raw_spin_unlock(v2);
  raw_write_unlock(v5 + 12);
  v35 = *(_QWORD *)(a1 + 8);
  _X8 = a1;
  if ( (v35 & 1) != 0 )
    _X8 = v35 - 1;
LABEL_114:
  _X8 = (unsigned int *)(_X8 + 52);
  __asm { PRFM            #0x11, [X8] }
  do
    v40 = __ldxr(_X8);
  while ( __stxr(v40 + 1, _X8) );
  if ( (*(_QWORD *)_X19 ^ *(_QWORD *)a1) >> 62 )
  {
    dec_zone_page_state(_X19, 9);
    inc_zone_page_state(a1, 9);
  }
  _ClearPageMovable(_X19);
  __asm { PRFM            #0x11, [X19] }
  do
    v42 = __ldxr((unsigned __int64 *)_X19);
  while ( __stxr(v42 & 0xFFFFFFFFFFFF7FFFLL, (unsigned __int64 *)_X19) );
  *(_QWORD *)(_X19 + 32) = 0;
  *(_QWORD *)(_X19 + 40) = 0;
  *(_DWORD *)(_X19 + 48) = -1;
  v36 = *(_QWORD *)(_X19 + 8);
  if ( (v36 & 1) != 0 )
    _X19 = v36 - 1;
  _X8 = (unsigned int *)(_X19 + 52);
  __asm { PRFM            #0x11, [X8] }
  do
  {
    v45 = __ldxr(_X8);
    v46 = v45 - 1;
  }
  while ( __stlxr(v46, _X8) );
  __dmb(0xBu);
  if ( !v46 )
    _folio_put(_X19);
  return 0;
}
