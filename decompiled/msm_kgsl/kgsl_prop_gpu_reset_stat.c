__int64 __fastcall kgsl_prop_gpu_reset_stat(__int64 *a1, __int64 a2)
{
  __int64 v3; // x1
  __int64 result; // x0
  unsigned int v7; // w8
  __int64 v8; // x8
  signed int v14; // w8
  bool v15; // cc
  unsigned __int64 StatusReg; // x9
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x10
  unsigned __int64 v19; // x10
  unsigned __int64 v21; // x9
  __int64 v22; // x0
  unsigned __int64 v23; // x8
  unsigned __int64 v25; // x9
  unsigned int v26; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v27; // [xsp+8h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_QWORD *)(a2 + 16) != 4 )
    goto LABEL_8;
  v3 = *(_QWORD *)(a2 + 8);
  v26 = 0;
  if ( inline_copy_from_user_0((int)&v26, v3, 4u) )
  {
LABEL_3:
    result = -14;
    goto LABEL_9;
  }
  _X0 = (unsigned int *)kgsl_context_get_owner(a1, v26);
  if ( !_X0 )
  {
LABEL_8:
    result = -22;
    goto LABEL_9;
  }
  v7 = _X0[12];
  _X0[12] = 0;
  v26 = v7;
  __asm { PRFM            #0x11, [X0] }
  do
    v14 = __ldxr(_X0);
  while ( __stlxr(v14 - 1, _X0) );
  if ( v14 == 1 )
  {
    __dmb(9u);
    kgsl_context_destroy((__int64)_X0);
  }
  else
  {
    v15 = v14 <= 0;
    v8 = a2;
    if ( !v15 )
      goto LABEL_13;
    refcount_warn_saturate(_X0, 3);
  }
  v8 = a2;
LABEL_13:
  StatusReg = _ReadStatusReg(SP_EL0);
  v17 = *(_QWORD *)(v8 + 8);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v18 = v17, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v18 = v17 & ((__int64)(v17 << 8) >> 8);
  if ( v18 > 0x7FFFFFFFFCLL )
    goto LABEL_3;
  v19 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v21 = *(_QWORD *)(StatusReg + 8);
  _WriteStatusReg(TTBR1_EL1, v21 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v21);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v19);
  v22 = _arch_copy_to_user(v17 & 0xFF7FFFFFFFFFFFFFLL, &v26, 4);
  v23 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v25 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v25 - 4096);
  _WriteStatusReg(TTBR1_EL1, v25);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v23);
  if ( v22 )
    result = -14;
  else
    result = 0;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
