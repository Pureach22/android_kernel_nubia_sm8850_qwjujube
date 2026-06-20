__int64 __fastcall adreno_setproperty_compat(__int64 *a1, int a2, unsigned __int64 a3, int a4)
{
  __int64 v4; // x19
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v6; // x9
  unsigned __int64 v8; // x9
  unsigned __int64 v14; // x8
  unsigned __int64 v15; // x2
  unsigned __int64 v16; // x8
  unsigned __int64 v18; // x9
  __int64 v19; // x20
  __int64 v20; // x22
  unsigned int v22; // w24
  unsigned int v24; // w8
  __int64 (*v27)(void); // x8
  __int64 result; // x0
  unsigned int v29; // w19
  int v31; // w8
  int v33; // w8
  unsigned int v34; // w19
  __int64 v35; // [xsp+0h] [xbp-30h] BYREF
  __int64 v36; // [xsp+8h] [xbp-28h]
  __int64 v37; // [xsp+10h] [xbp-20h]
  __int64 v38; // [xsp+18h] [xbp-18h] BYREF
  __int64 v39; // [xsp+20h] [xbp-10h]
  __int64 v40; // [xsp+28h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a1;
  if ( a2 != 34 && a2 != 18 )
  {
    v27 = *(__int64 (**)(void))(*(_QWORD *)(v4 + 8752) + 168LL);
    if ( *((_DWORD *)v27 - 1) != 1016354318 )
      __break(0x8228u);
    result = v27();
    goto LABEL_32;
  }
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v35 = 0;
  if ( a4 != 16 )
    goto LABEL_31;
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v6 = a3, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v6 = a3 & ((__int64)(a3 << 8) >> 8);
  if ( v6 > 0x7FFFFFFFF0LL )
  {
    v15 = 16;
  }
  else
  {
    v8 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v14 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v14 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v14);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v8);
    v15 = _arch_copy_from_user(&v38, a3 & 0xFF7FFFFFFFFFFFFFLL, 16);
    v16 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v18 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v18 - 4096);
    _WriteStatusReg(TTBR1_EL1, v18);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v16);
    if ( !v15 )
    {
      v19 = HIDWORD(v38);
      v20 = *a1;
      v35 = v38;
      v36 = (unsigned int)v39;
      v37 = HIDWORD(v39);
      raw_read_lock(v20 + 11208);
      _X0 = idr_find(v20 + 11184, v19);
      if ( _X0 && (*(_QWORD *)(_X0 + 32) & 2) == 0 )
      {
        v22 = *(_DWORD *)_X0;
        if ( *(_DWORD *)_X0 )
        {
          do
          {
            __asm { PRFM            #0x11, [X0] }
            do
              v24 = __ldxr((unsigned int *)_X0);
            while ( v24 == v22 && __stxr(v22 + 1, (unsigned int *)_X0) );
            if ( v24 == v22 )
              break;
            v22 = v24;
          }
          while ( v24 );
        }
        _X20 = _X0;
        if ( (((v22 + 1) | v22) & 0x80000000) != 0 )
          refcount_warn_saturate(_X0, 0);
        raw_read_unlock(v20 + 11208);
        if ( !v22 )
          goto LABEL_31;
        _X0 = (unsigned int *)_X20;
        if ( *(__int64 **)(_X20 + 16) != a1 )
          goto LABEL_36;
        result = adreno_set_constraint(v4, (unsigned int *)_X20, (__int64)&v35);
        __asm { PRFM            #0x11, [X20] }
        do
          v33 = __ldxr((unsigned int *)_X20);
        while ( __stlxr(v33 - 1, (unsigned int *)_X20) );
        if ( v33 == 1 )
        {
          __dmb(9u);
          v29 = result;
          kgsl_context_destroy(_X20);
          result = v29;
        }
        else if ( v33 <= 0 )
        {
          v34 = result;
          refcount_warn_saturate(_X20, 3);
          result = v34;
        }
        goto LABEL_32;
      }
      raw_read_unlock(v20 + 11208);
LABEL_31:
      result = 4294967274LL;
      goto LABEL_32;
    }
  }
  if ( v15 >= 0x11 )
  {
    _X0 = (unsigned int *)_fortify_panic(15, 0, v15);
LABEL_36:
    __asm { PRFM            #0x11, [X0] }
    do
      v31 = __ldxr(_X0);
    while ( __stlxr(v31 - 1, _X0) );
    if ( v31 == 1 )
    {
      __dmb(9u);
      kgsl_context_destroy((__int64)_X0);
    }
    else if ( v31 <= 0 )
    {
      refcount_warn_saturate(_X0, 3);
    }
    goto LABEL_31;
  }
  result = 4294967282LL;
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return result;
}
