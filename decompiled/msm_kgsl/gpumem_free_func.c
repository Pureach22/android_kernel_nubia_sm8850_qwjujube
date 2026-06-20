__int64 __fastcall gpumem_free_func(__int64 result, __int64 a2, __int64 a3)
{
  __int64 (*v4)(void); // x8
  __int64 v5; // x8
  int v6; // w20
  __int64 v7; // x8
  int v8; // w21
  __int64 v9; // x22
  __int64 v10; // x23
  __int64 v11; // x24
  __int64 v12; // x10
  int v13; // w8
  int v15; // w8
  int v16; // w10
  int v21; // w8

  _X19 = a3;
  _ReadStatusReg(SP_EL0);
  if ( result )
  {
    v4 = *(__int64 (**)(void))(*(_QWORD *)(result + 8752) + 64LL);
    if ( *((_DWORD *)v4 - 1) != -362688460 )
      __break(0x8228u);
    result = v4();
  }
  v5 = *(_QWORD *)(*(_QWORD *)(_X19 + 256) + 8LL);
  if ( v5 )
  {
    v6 = *(_DWORD *)(v5 + 112);
    v7 = *(_QWORD *)(_X19 + 8);
    if ( v7 )
    {
LABEL_7:
      v8 = *(_DWORD *)(v7 + 24);
      goto LABEL_10;
    }
  }
  else
  {
    v6 = 0;
    v7 = *(_QWORD *)(_X19 + 8);
    if ( v7 )
      goto LABEL_7;
  }
  v8 = 0;
LABEL_10:
  if ( memfree )
  {
    v9 = *(_QWORD *)(_X19 + 80);
    v10 = *(_QWORD *)(_X19 + 48);
    v11 = *(_QWORD *)(_X19 + 32);
    raw_spin_lock(&memfree_lock);
    v12 = memfree + 40LL * (int)qword_17D100;
    v13 = qword_17D100 + 1;
    *(_DWORD *)(v12 + 24) = v6;
    *(_DWORD *)v12 = v8;
    *(_QWORD *)(v12 + 8) = v11;
    *(_QWORD *)(v12 + 16) = v10;
    *(_QWORD *)(v12 + 32) = v9;
    LODWORD(v12) = -v13;
    _NF = -v13 < 0;
    v15 = v13 & 0x1FF;
    v16 = v12 & 0x1FF;
    if ( !_NF )
      v15 = -v16;
    LODWORD(qword_17D100) = v15;
    if ( v15 == HIDWORD(qword_17D100) )
      HIDWORD(qword_17D100) = (__int16)(v15
                                      + 1
                                      - ((v15 + 1 + (((unsigned int)(__int16)(v15 + 1) >> 22) & 0x1FF)) & 0xFE00));
    result = raw_spin_unlock(&memfree_lock);
  }
  if ( _X19 )
  {
    __asm { PRFM            #0x11, [X19] }
    do
      v21 = __ldxr((unsigned int *)_X19);
    while ( __stlxr(v21 - 1, (unsigned int *)_X19) );
    if ( v21 == 1 )
    {
      __dmb(9u);
      *(_QWORD *)(_X19 + 336) = 0xFFFFFFFE00000LL;
      *(_QWORD *)(_X19 + 344) = _X19 + 344;
      *(_QWORD *)(_X19 + 352) = _X19 + 344;
      *(_QWORD *)(_X19 + 360) = deferred_destroy;
      result = queue_work_on(32, qword_3A908, _X19 + 336);
    }
    else if ( v21 <= 0 )
    {
      result = refcount_warn_saturate(_X19, 3);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
