__int64 __fastcall gpuobj_free_fence_func(unsigned int *a1)
{
  __int64 v2; // x8
  int v3; // w20
  __int64 v4; // x8
  int v5; // w21
  __int64 v6; // x22
  __int64 v7; // x23
  __int64 v8; // x24
  __int64 v9; // x10
  int v10; // w8
  int v12; // w8
  int v13; // w10
  int v18; // w8

  _X19 = a1;
  v2 = *(_QWORD *)(*((_QWORD *)a1 + 32) + 8LL);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 112);
    v4 = *((_QWORD *)a1 + 1);
    if ( v4 )
    {
LABEL_3:
      v5 = *(_DWORD *)(v4 + 24);
      goto LABEL_6;
    }
  }
  else
  {
    v3 = 0;
    v4 = *((_QWORD *)a1 + 1);
    if ( v4 )
      goto LABEL_3;
  }
  v5 = 0;
LABEL_6:
  if ( memfree )
  {
    v6 = *((_QWORD *)a1 + 10);
    v7 = *((_QWORD *)a1 + 6);
    v8 = *((_QWORD *)a1 + 4);
    raw_spin_lock(&memfree_lock);
    v9 = memfree + 40LL * (int)qword_17D100;
    v10 = qword_17D100 + 1;
    *(_DWORD *)(v9 + 24) = v3;
    *(_DWORD *)v9 = v5;
    *(_QWORD *)(v9 + 8) = v8;
    *(_QWORD *)(v9 + 16) = v7;
    *(_QWORD *)(v9 + 32) = v6;
    LODWORD(v9) = -v10;
    _NF = -v10 < 0;
    v12 = v10 & 0x1FF;
    v13 = v9 & 0x1FF;
    if ( !_NF )
      v12 = -v13;
    LODWORD(qword_17D100) = v12;
    if ( v12 == HIDWORD(qword_17D100) )
      HIDWORD(qword_17D100) = (__int16)(v12
                                      + 1
                                      - ((v12 + 1 + (((unsigned int)(__int16)(v12 + 1) >> 22) & 0x1FF)) & 0xFE00));
    raw_spin_unlock(&memfree_lock);
  }
  if ( _X19 )
  {
    __asm { PRFM            #0x11, [X19] }
    do
      v18 = __ldxr(_X19);
    while ( __stlxr(v18 - 1, _X19) );
    if ( v18 == 1 )
    {
      __dmb(9u);
      *((_QWORD *)_X19 + 42) = 0xFFFFFFFE00000LL;
      *((_QWORD *)_X19 + 43) = _X19 + 86;
      *((_QWORD *)_X19 + 44) = _X19 + 86;
      *((_QWORD *)_X19 + 45) = deferred_destroy;
      queue_work_on(32, qword_3A908, _X19 + 84);
    }
    else if ( v18 <= 0 )
    {
      refcount_warn_saturate(_X19, 3);
    }
  }
  return 1;
}
