__int64 __fastcall fastrpc_put_args(__int64 a1, int a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  int v6; // w24
  __int64 v7; // x26
  __int64 v9; // x27
  __int64 v11; // x25
  __int64 v12; // x28
  __int64 v13; // x9
  __int64 v14; // x8
  unsigned __int64 v15; // x22
  const void *v16; // x1
  unsigned __int64 v17; // x21
  const void *v18; // x23
  unsigned __int64 v19; // x8
  unsigned __int64 v20; // x8
  unsigned __int64 v26; // x9
  unsigned __int64 v27; // x8
  unsigned __int64 v29; // x9
  __int64 v30; // x27
  __int64 v31; // x22
  __int64 *v32; // x28
  __int64 v33; // x25
  unsigned int v34; // w24
  unsigned __int64 v35; // x23
  __int64 i; // x8
  int v37; // w24
  int v40; // w8
  unsigned __int64 v41; // x8
  unsigned __int64 v42; // x9
  unsigned __int64 v43; // x10
  unsigned __int64 v44; // x10
  unsigned __int64 v46; // x9
  __int64 v47; // x0
  unsigned __int64 v48; // x8
  unsigned __int64 v50; // x9
  __int64 result; // x0
  unsigned __int64 v52; // x8
  unsigned __int64 v53; // x9
  unsigned __int64 v54; // x10
  unsigned __int64 v55; // x10
  unsigned __int64 v57; // x9
  __int64 v58; // x1
  unsigned __int64 v59; // x8
  unsigned __int64 v61; // x9
  __int64 v62; // [xsp+0h] [xbp-20h]
  __int64 v63; // [xsp+10h] [xbp-10h]
  unsigned __int64 StatusReg; // [xsp+18h] [xbp-8h]

  v6 = *(_DWORD *)(a1 + 36);
  v7 = *(_QWORD *)(a1 + 184);
  v9 = BYTE2(v6);
  v62 = *(int *)(a1 + 16);
  v63 = *(_QWORD *)(a1 + 192);
  if ( BYTE2(v6) < *(int *)(a1 + 20) )
  {
    v11 = 0;
    v12 = 24LL * BYTE2(v6);
    StatusReg = _ReadStatusReg(SP_EL0);
    do
    {
      if ( !*(_QWORD *)(*(_QWORD *)(a1 + 208) + 8 * v9) )
      {
        v13 = *(_QWORD *)(a1 + 224);
        v14 = *(_QWORD *)(a1 + 200) + v11;
        v15 = *(_QWORD *)(v13 + v12);
        v16 = *(const void **)v14;
        v17 = *(_QWORD *)(v14 + 8);
        if ( a2 )
        {
          memcpy(*(void **)(v13 + v12), v16, *(_QWORD *)(v14 + 8));
        }
        else
        {
          if ( v17 >> 31 )
          {
            __break(0x800u);
            return 4294967282LL;
          }
          v18 = *(const void **)v14;
          _check_object_size(v16, v17, 1);
          if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v19 = v15, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
            v19 = v15 & ((__int64)(v15 << 8) >> 8);
          if ( 0x8000000000LL - v17 >= v19 )
          {
            v20 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v26 = *(_QWORD *)(StatusReg + 8);
            _WriteStatusReg(TTBR1_EL1, v26 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
            _WriteStatusReg(TTBR0_EL1, v26);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v20);
            v17 = _arch_copy_to_user(v15 & 0xFF7FFFFFFFFFFFFFLL, v18, v17);
            v27 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v29 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
            _WriteStatusReg(TTBR0_EL1, v29 - 4096);
            _WriteStatusReg(TTBR1_EL1, v29);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v27);
          }
          if ( v17 )
            return 4294967282LL;
        }
      }
      ++v9;
      v11 += 16;
      v12 += 24;
    }
    while ( v9 < *(int *)(a1 + 20) );
  }
  v30 = 0;
  v31 = 0;
  v32 = (__int64 *)(v7 + 16);
  v33 = v63
      + 16 * v62
      + 8 * v62
      + 16LL * BYTE2(v6)
      + 16LL * BYTE1(v6)
      + 16LL * (((unsigned __int8)v6 >> 4) + (v6 & 0xFu));
  do
  {
    if ( !*(_QWORD *)(v33 + 8 * v30) )
      break;
    mutex_lock(v7 + 328);
    v34 = *(_DWORD *)(v33 + 8 * v30);
    v35 = dma_buf_get(v34);
    if ( v35 < 0xFFFFFFFFFFFFF001LL )
    {
      raw_spin_lock(v7 + 320);
      for ( i = *v32; (__int64 *)i != v32; i = *(_QWORD *)i )
      {
        if ( *(_QWORD *)(i + 32) == v35 && *(_DWORD *)(i + 24) == v34 )
        {
          v37 = 0;
          v31 = i;
          goto LABEL_26;
        }
      }
      v37 = -2;
LABEL_26:
      raw_spin_unlock(v7 + 320);
      dma_buf_put(v35);
      if ( !v37 && *(_DWORD *)(v31 + 108) == 0x20000 )
      {
        *(_DWORD *)(v31 + 108) = 0;
        if ( v31 )
        {
          _X0 = (unsigned int *)(v31 + 112);
          __asm { PRFM            #0x11, [X0] }
          do
            v40 = __ldxr(_X0);
          while ( __stlxr(v40 - 1, _X0) );
          if ( v40 == 1 )
          {
            __dmb(9u);
            _fastrpc_free_map(v31);
          }
          else if ( v40 <= 0 )
          {
            refcount_warn_saturate(_X0, 3);
          }
        }
      }
    }
    mutex_unlock(v7 + 328);
    ++v30;
  }
  while ( v30 != 16 );
  if ( v63 )
  {
    v41 = *(_QWORD *)(a1 + 48);
    if ( v41 )
    {
      if ( v33 != -128 )
      {
        v42 = _ReadStatusReg(SP_EL0);
        if ( (*(_BYTE *)(v42 + 70) & 0x20) != 0 || (v43 = v41, (*(_QWORD *)v42 & 0x4000000) != 0) )
          v43 = v41 & ((__int64)(v41 << 8) >> 8);
        if ( v43 > 0x7FFFFFFF00LL )
          return 4294967282LL;
        v44 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v46 = *(_QWORD *)(v42 + 8);
        _WriteStatusReg(TTBR1_EL1, v46 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v46);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v44);
        v47 = _arch_copy_to_user(v41 & 0xFF7FFFFFFFFFFFFFLL, v33 + 128, 256);
        v48 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v50 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v50 - 4096);
        _WriteStatusReg(TTBR1_EL1, v50);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v48);
        if ( v47 )
          return 4294967282LL;
      }
    }
  }
  v52 = *(_QWORD *)(a1 + 72);
  result = 0;
  if ( v52 && v33 != -388 )
  {
    v53 = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(v53 + 70) & 0x20) != 0 || (v54 = v52, (*(_QWORD *)v53 & 0x4000000) != 0) )
      v54 = v52 & ((__int64)(v52 << 8) >> 8);
    if ( v54 > 0x7FFFFFFFA0LL )
    {
      v58 = 96;
    }
    else
    {
      v55 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v57 = *(_QWORD *)(v53 + 8);
      _WriteStatusReg(TTBR1_EL1, v57 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v57);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v55);
      v58 = _arch_copy_to_user(v52 & 0xFF7FFFFFFFFFFFFFLL, v33 + 388, 96);
      v59 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v61 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v61 - 4096);
      _WriteStatusReg(TTBR1_EL1, v61);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v59);
      if ( !(_DWORD)v58 )
        return 0;
    }
    printk(&unk_2441C, v58, a3, a4, a5, a6);
    return 0;
  }
  return result;
}
