__int64 __fastcall kgsl_snapshot_get_object(
        __int64 a1,
        unsigned __int64 a2,
        unsigned __int64 a3,
        unsigned __int64 a4,
        int a5)
{
  __int64 v11; // x8
  unsigned int v12; // w20
  int v13; // w8
  unsigned __int64 v14; // x8
  unsigned __int64 v15; // x2
  unsigned __int64 v16; // x20
  _QWORD *v17; // x9
  _QWORD *v18; // x19
  _QWORD *v19; // t1
  unsigned __int64 v20; // x12
  unsigned __int64 v21; // x14
  __int64 v22; // x15
  bool v23; // w16
  unsigned __int64 v24; // x15
  unsigned __int64 v25; // x8
  unsigned __int64 v26; // x23
  unsigned __int64 v27; // x24
  unsigned __int64 v28; // x22
  __int64 v29; // x8
  _QWORD *v30; // x2
  _QWORD *v31; // x9
  _QWORD *v32; // x8
  unsigned __int64 v33; // x19
  unsigned int v36; // w9
  int v42; // w8
  unsigned int v46; // w9

  if ( !a3 )
    return 0;
  _X0 = kgsl_sharedmem_find(a2, a3);
  if ( !_X0 )
    return (unsigned int)-22;
  v11 = *(_QWORD *)(_X0 + 80);
  if ( (v11 & 0xE0) != 0 )
    goto LABEL_4;
  if ( (*(_QWORD *)(_X0 + 80) & 0xFE00LL) == 0x600 )
  {
    v12 = 0;
    goto LABEL_45;
  }
  v13 = BYTE1(v11);
  v12 = 0;
  if ( v13 != 8 && v13 != 18 )
  {
    if ( a4 )
    {
      v14 = a4;
      v15 = a3;
      v16 = a3 - *(_QWORD *)(_X0 + 32);
    }
    else
    {
      v15 = *(_QWORD *)(_X0 + 32);
      v16 = 0;
      v14 = *(_QWORD *)(_X0 + 48);
    }
    if ( v14 + v16 > *(_QWORD *)(_X0 + 48) )
    {
      v32 = *(_QWORD **)(a1 + 248);
      v33 = _X0;
      dev_err(*v32, "snapshot: invalid size for GPU buffer 0x%016llx\n", v15);
      _X0 = v33;
LABEL_4:
      v12 = -22;
      goto LABEL_45;
    }
    v19 = *(_QWORD **)(a1 + 128);
    v18 = (_QWORD *)(a1 + 128);
    v17 = v19;
    if ( v19 != v18 )
    {
      v20 = v15 + v14;
      while ( 1 )
      {
        if ( *(_QWORD *)(*(v17 - 1) + 256LL) == a2 && *((_DWORD *)v17 - 4) == a5 )
        {
          v21 = *(v17 - 5);
          v22 = *(v17 - 4);
          v23 = __CFADD__(v21, v22);
          if ( v14 <= ~v15 && !v23 && v20 > v21 )
          {
            v24 = v22 + v21;
            if ( v24 > v15 )
              break;
          }
        }
        v17 = (_QWORD *)*v17;
        if ( v17 == v18 )
          goto LABEL_36;
      }
      if ( v21 > v15 )
      {
        v21 = v15;
        *(v17 - 5) = v15;
      }
      v12 = 0;
      if ( v24 <= v20 )
        v25 = v15 + v14;
      else
        v25 = v24;
      *(v17 - 4) = v25 - v21;
      *(v17 - 3) = v21 - *(_QWORD *)(_X0 + 32);
      goto LABEL_45;
    }
LABEL_36:
    v26 = v14;
    v27 = v15;
    v28 = _X0;
    v29 = _kmalloc_cache_noprof(raw_read_unlock, 3520, 56);
    _X0 = v28;
    if ( !v29 )
      goto LABEL_4;
    v30 = (_QWORD *)*v18;
    *(_DWORD *)(v29 + 24) = a5;
    *(_QWORD *)(v29 + 32) = v28;
    *(_QWORD *)v29 = v27;
    *(_QWORD *)(v29 + 8) = v26;
    *(_QWORD *)(v29 + 16) = v16;
    v31 = (_QWORD *)(v29 + 40);
    if ( (_QWORD *)v30[1] != v18 || v31 == v18 || v30 == v31 )
    {
      _list_add_valid_or_report(v29 + 40, v18);
      _X0 = v28;
      if ( (*(_DWORD *)(v28 + 56) & 4) == 0 )
        goto LABEL_41;
    }
    else
    {
      v30[1] = v31;
      *(_QWORD *)(v29 + 40) = v30;
      *(_QWORD *)(v29 + 48) = v18;
      *v18 = v31;
      if ( (*(_DWORD *)(v28 + 56) & 4) == 0 )
      {
LABEL_41:
        v12 = *(_DWORD *)(_X0 + 48);
        goto LABEL_54;
      }
    }
    v12 = 0;
LABEL_54:
    _X8 = (unsigned int *)(_X0 + 56);
    __asm { PRFM            #0x11, [X8] }
    do
      v46 = __ldxr(_X8);
    while ( __stxr(v46 | 4, _X8) );
    return v12;
  }
LABEL_45:
  _X8 = (unsigned int *)(_X0 + 56);
  __asm { PRFM            #0x11, [X8] }
  do
    v36 = __ldxr(_X8);
  while ( __stxr(v36 & 0xFFFFEFFF, _X8) );
  if ( _X0 <= 0xFFFFFFFFFFFFF000LL )
  {
    __asm { PRFM            #0x11, [X0] }
    do
      v42 = __ldxr((unsigned int *)_X0);
    while ( __stlxr(v42 - 1, (unsigned int *)_X0) );
    if ( v42 == 1 )
    {
      __dmb(9u);
      kgsl_mem_entry_destroy((_QWORD *)_X0);
    }
    else if ( v42 <= 0 )
    {
      refcount_warn_saturate(_X0, 3);
    }
  }
  return v12;
}
