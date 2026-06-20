__int64 __fastcall gpumem_free_entry(unsigned __int64 a1)
{
  __int64 v3; // x9
  __int64 v4; // x8
  int v5; // w20
  __int64 v6; // x8
  int v7; // w21
  __int64 v8; // x22
  __int64 v9; // x23
  __int64 v10; // x24
  __int64 v11; // x10
  int v12; // w8
  int v14; // w8
  int v15; // w10
  int v20; // w8

  if ( !a1 )
    return -16;
  _X19 = a1;
  raw_spin_lock(*(_QWORD *)(a1 + 256) + 32LL);
  if ( *(_DWORD *)(_X19 + 264) )
  {
    raw_spin_unlock(*(_QWORD *)(_X19 + 256) + 32LL);
    return -16;
  }
  v3 = *(_QWORD *)(_X19 + 256);
  *(_DWORD *)(_X19 + 264) = 1;
  raw_spin_unlock(v3 + 32);
  v4 = *(_QWORD *)(*(_QWORD *)(_X19 + 256) + 8LL);
  if ( !v4 )
  {
    v5 = 0;
    v6 = *(_QWORD *)(_X19 + 8);
    if ( v6 )
      goto LABEL_7;
LABEL_9:
    v7 = 0;
    goto LABEL_10;
  }
  v5 = *(_DWORD *)(v4 + 112);
  v6 = *(_QWORD *)(_X19 + 8);
  if ( !v6 )
    goto LABEL_9;
LABEL_7:
  v7 = *(_DWORD *)(v6 + 24);
LABEL_10:
  if ( memfree )
  {
    v8 = *(_QWORD *)(_X19 + 80);
    v9 = *(_QWORD *)(_X19 + 48);
    v10 = *(_QWORD *)(_X19 + 32);
    raw_spin_lock(&memfree_lock);
    v11 = memfree + 40LL * (int)qword_17D100;
    v12 = qword_17D100 + 1;
    *(_DWORD *)(v11 + 24) = v5;
    *(_DWORD *)v11 = v7;
    *(_QWORD *)(v11 + 8) = v10;
    *(_QWORD *)(v11 + 16) = v9;
    *(_QWORD *)(v11 + 32) = v8;
    LODWORD(v11) = -v12;
    _NF = -v12 < 0;
    v14 = v12 & 0x1FF;
    v15 = v11 & 0x1FF;
    if ( !_NF )
      v14 = -v15;
    LODWORD(qword_17D100) = v14;
    if ( v14 == HIDWORD(qword_17D100) )
      HIDWORD(qword_17D100) = (__int16)(v14
                                      + 1
                                      - ((v14 + 1 + (((unsigned int)(__int16)(v14 + 1) >> 22) & 0x1FF)) & 0xFE00));
    raw_spin_unlock(&memfree_lock);
  }
  if ( _X19 <= 0xFFFFFFFFFFFFF000LL )
  {
    __asm { PRFM            #0x11, [X19] }
    do
      v20 = __ldxr((unsigned int *)_X19);
    while ( __stlxr(v20 - 1, (unsigned int *)_X19) );
    if ( v20 == 1 )
    {
      __dmb(9u);
      kgsl_mem_entry_destroy((_QWORD *)_X19);
    }
    else if ( v20 <= 0 )
    {
      refcount_warn_saturate(_X19, 3);
    }
  }
  return 0;
}
