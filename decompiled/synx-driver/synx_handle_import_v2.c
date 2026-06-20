__int64 __fastcall synx_handle_import_v2(__int64 a1, __int64 a2)
{
  int v2; // w8
  __int64 v4; // x1
  __int64 result; // x0
  int v7; // w8
  unsigned __int64 fence; // x0
  __int64 v9; // x5
  int v10; // w0
  __int64 v11; // x9
  int v13; // w19
  int v19; // w10
  __int64 v20; // x19
  unsigned __int64 v21; // x20
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v23; // x9
  unsigned __int64 v24; // x9
  unsigned __int64 v26; // x8
  unsigned __int64 v27; // x8
  unsigned __int64 v29; // x9
  __int64 v30; // [xsp+8h] [xbp-68h] BYREF
  _QWORD *v31; // [xsp+10h] [xbp-60h]
  __int64 v32; // [xsp+18h] [xbp-58h]
  __int64 *v33; // [xsp+20h] [xbp-50h]
  __int64 v34; // [xsp+28h] [xbp-48h]
  __int64 v35; // [xsp+30h] [xbp-40h]
  __int64 v36; // [xsp+38h] [xbp-38h] BYREF
  _QWORD v37[2]; // [xsp+40h] [xbp-30h] BYREF
  __int64 v38; // [xsp+50h] [xbp-20h]
  __int64 v39; // [xsp+58h] [xbp-18h]
  __int64 v40; // [xsp+60h] [xbp-10h]
  __int64 v41; // [xsp+68h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a1 + 4);
  v33 = nullptr;
  v34 = 0;
  v31 = nullptr;
  v32 = 0;
  v30 = 0;
  if ( v2 != 48 )
    goto LABEL_24;
  v4 = *(_QWORD *)(a1 + 16);
  v39 = 0;
  v40 = 0;
  v37[1] = 0;
  v38 = 0;
  v36 = 0;
  v37[0] = 0;
  if ( inline_copy_from_user((int)&v36, v4, 0x30u) )
  {
    result = 4294967282LL;
    goto LABEL_25;
  }
  v7 = HIDWORD(v36);
  if ( (v36 & 0x800000000LL) != 0 && (_DWORD)v38 )
  {
    fence = sync_file_get_fence();
    v33 = (__int64 *)fence;
    if ( !fence || fence > 0xFFFFFFFFFFFFF000LL )
    {
      if ( (synx_debug & 1) != 0 )
        printk(&unk_27836, &unk_29207, "synx_handle_import_v2", 2935, (unsigned int)v38, v9);
      goto LABEL_24;
    }
    v7 = HIDWORD(v36);
  }
  else if ( (v36 & 0x400000000LL) != 0 && (_DWORD)v36 )
  {
    v33 = &v36;
  }
  LODWORD(v30) = 3;
  v31 = v37;
  LODWORD(v32) = v7;
  v35 = v40;
  v10 = synx_import(a2, &v30);
  v11 = a1;
  if ( (v36 & 0x800000000LL) == 0 || !(_DWORD)v36 || !v33 )
    goto LABEL_23;
  _X8 = (unsigned int *)(v33 + 7);
  __asm { PRFM            #0x11, [X8] }
  do
    v19 = __ldxr(_X8);
  while ( __stlxr(v19 - 1, _X8) );
  if ( v19 == 1 )
  {
    __dmb(9u);
    v13 = v10;
    dma_fence_release(_X8);
LABEL_17:
    v10 = v13;
    v11 = a1;
    goto LABEL_23;
  }
  if ( v19 <= 0 )
  {
    v13 = v10;
    refcount_warn_saturate(_X8, 3);
    goto LABEL_17;
  }
LABEL_23:
  if ( v10 )
  {
LABEL_24:
    result = 4294967274LL;
    goto LABEL_25;
  }
  v20 = *(unsigned int *)(v11 + 4);
  if ( (unsigned int)v20 >= 0x31 )
  {
    _copy_overflow(48, *(unsigned int *)(v11 + 4));
    result = 4294967282LL;
  }
  else
  {
    v21 = *(_QWORD *)(v11 + 16);
    _check_object_size(&v36, *(unsigned int *)(v11 + 4), 1);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v23 = v21, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v23 = v21 & ((__int64)(v21 << 8) >> 8);
    if ( 0x8000000000LL - v20 >= v23 )
    {
      v24 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v26 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v26 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v26);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v24);
      v20 = _arch_copy_to_user(v21 & 0xFF7FFFFFFFFFFFFFLL, &v36, v20);
      v27 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v29 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v29 - 4096);
      _WriteStatusReg(TTBR1_EL1, v29);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v27);
    }
    if ( v20 )
      result = 4294967282LL;
    else
      result = 0;
  }
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
