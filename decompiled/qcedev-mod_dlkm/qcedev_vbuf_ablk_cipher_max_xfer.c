__int64 __fastcall qcedev_vbuf_ablk_cipher_max_xfer(__int64 a1, unsigned int *a2, __int64 *a3, __int64 a4)
{
  __int64 v4; // x21
  unsigned int v8; // w27
  unsigned __int64 v9; // x23
  __int64 v10; // x26
  size_t v11; // x24
  unsigned int v12; // w22
  unsigned __int64 v13; // x8
  unsigned int *v14; // x28
  unsigned __int64 v15; // x20
  __int64 v16; // x23
  unsigned int v17; // t1
  unsigned __int64 v18; // x24
  size_t v19; // x25
  int v20; // w8
  __int64 v21; // x2
  int v22; // w8
  unsigned int v23; // w8
  __int64 v24; // x25
  unsigned __int64 StatusReg; // x27
  _DWORD *v26; // x24
  __int64 v27; // x23
  unsigned __int64 v28; // x20
  unsigned __int64 v29; // x8
  unsigned __int64 v30; // x8
  unsigned __int64 v36; // x9
  unsigned __int64 v37; // x8
  unsigned __int64 v39; // x9
  __int64 v40; // x9
  __int64 v42; // x23
  unsigned __int64 v43; // x20
  unsigned __int64 v44; // x8
  unsigned __int64 v45; // x9
  unsigned __int64 v46; // x9
  unsigned __int64 v48; // x8
  __int64 v49; // x0
  unsigned __int64 v50; // x8
  unsigned __int64 v52; // x9
  _DWORD *v53; // [xsp+0h] [xbp-30h]
  _QWORD v54[5]; // [xsp+8h] [xbp-28h] BYREF

  v4 = a4;
  v54[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a1 + 716) == 2 )
    v8 = *(_DWORD *)(a1 + 708);
  else
    v8 = 0;
  v9 = *(_QWORD *)(a1 + 64);
  v10 = *a2;
  memset(v54, 0, 32);
  if ( !v9 )
    goto LABEL_8;
  v11 = *(unsigned int *)(a1 + 72);
  if ( (v11 & 0x80000000) != 0 )
  {
LABEL_43:
    __break(0x800u);
    v12 = -14;
    goto LABEL_34;
  }
  _check_object_size(a4 + v8, *(unsigned int *)(a1 + 72), 0);
  if ( !inline_copy_from_user(v4 + v8, v9, v11) )
  {
LABEL_8:
    v13 = *(unsigned int *)(a1 + 592);
    v53 = a2;
    if ( (unsigned int)v13 >= 2 )
    {
      v14 = (unsigned int *)(a1 + 88);
      v15 = 1;
      v16 = v4 + *(_DWORD *)(a1 + 72) + v8;
      do
      {
        if ( v15 == 16 )
LABEL_47:
          __break(0x5512u);
        v18 = *((_QWORD *)v14 - 1);
        if ( v18 )
        {
          v19 = *v14;
          if ( (v19 & 0x80000000) != 0 )
            goto LABEL_43;
          _check_object_size(v16, *v14, 0);
          if ( inline_copy_from_user(v16, v18, v19) )
            goto LABEL_7;
          v13 = *(unsigned int *)(a1 + 592);
        }
        v17 = *v14;
        v14 += 4;
        ++v15;
        v16 += v17;
      }
      while ( v15 < v13 );
    }
    v20 = *(_DWORD *)(a1 + 596);
    *(_QWORD *)(a1 + 832) = v54;
    v21 = v20 + v8;
    *(_QWORD *)(a1 + 840) = v54;
    *(_DWORD *)(a1 + 596) = v21;
    sg_init_one(v54, v4, v21);
    v22 = *(_DWORD *)(a1 + 596);
    *(_QWORD *)(a1 + 824) = a1 + 672;
    *(_DWORD *)(a1 + 816) = v22;
    *(_DWORD *)(a1 + 592) = 1;
    v12 = submit_req((__int64 *)a1, a3);
    v23 = *(_DWORD *)(a1 + 596) - v8;
    *(_DWORD *)(a1 + 596) = v23;
    if ( v23 )
    {
      v24 = v8;
      StatusReg = _ReadStatusReg(SP_EL0);
      v26 = (_DWORD *)(a1 + 16 * v10 + 328);
      while ( 1 )
      {
        if ( (unsigned int)v10 > 0xF )
          goto LABEL_47;
        v27 = (unsigned int)*v26;
        if ( (unsigned int)v27 > v23 )
          break;
        if ( !v12 )
        {
          if ( (v27 & 0x80000000) != 0 )
            goto LABEL_44;
          v28 = *((_QWORD *)v26 - 1);
          _check_object_size(v4 + v24, (unsigned int)*v26, 1);
          if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v29 = v28, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
            v29 = v28 & ((__int64)(v28 << 8) >> 8);
          if ( 0x8000000000LL - v27 >= v29 )
          {
            v30 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v36 = *(_QWORD *)(StatusReg + 8);
            _WriteStatusReg(TTBR1_EL1, v36 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
            _WriteStatusReg(TTBR0_EL1, v36);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v30);
            v27 = _arch_copy_to_user(v28 & 0xFF7FFFFFFFFFFFFFLL, v4 + v24, v27);
            v37 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v39 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
            _WriteStatusReg(TTBR0_EL1, v39 - 4096);
            _WriteStatusReg(TTBR1_EL1, v39);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v37);
          }
          if ( v27 )
            goto LABEL_41;
          LODWORD(v27) = *v26;
          v23 = *(_DWORD *)(a1 + 596);
        }
        v4 += (unsigned int)v27;
        v23 -= v27;
        LODWORD(v10) = v10 + 1;
        v26 += 4;
        *(_DWORD *)(a1 + 596) = v23;
        if ( !v23 )
          goto LABEL_32;
      }
      if ( !v12 )
      {
        if ( (v23 & 0x80000000) != 0 )
        {
LABEL_44:
          __break(0x800u);
          v12 = -14;
          goto LABEL_33;
        }
        v42 = v23;
        v43 = *((_QWORD *)v26 - 1);
        _check_object_size(v4 + v24, v23, 1);
        v44 = _ReadStatusReg(SP_EL0);
        if ( (*(_BYTE *)(v44 + 70) & 0x20) != 0 || (v45 = v43, (*(_QWORD *)v44 & 0x4000000) != 0) )
          v45 = v43 & ((__int64)(v43 << 8) >> 8);
        if ( 0x8000000000LL - v42 < v45 )
          goto LABEL_41;
        v46 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v48 = *(_QWORD *)(v44 + 8);
        _WriteStatusReg(TTBR1_EL1, v48 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v48);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v46);
        v49 = _arch_copy_to_user(v43 & 0xFF7FFFFFFFFFFFFFLL, v4 + v24, v42);
        v50 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v52 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v52 - 4096);
        _WriteStatusReg(TTBR1_EL1, v52);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v50);
        if ( v49 )
        {
LABEL_41:
          v12 = -14;
          goto LABEL_33;
        }
        v23 = *(_DWORD *)(a1 + 596);
        LODWORD(v27) = *v26;
      }
      v40 = *((_QWORD *)v26 - 1);
      *v26 = v27 - v23;
      *((_QWORD *)v26 - 1) = v40 + v23;
      *(_DWORD *)(a1 + 596) = 0;
    }
LABEL_32:
    *v53 = v10;
LABEL_33:
    *(_QWORD *)(a1 + 832) = 0;
    *(_QWORD *)(a1 + 840) = 0;
    goto LABEL_34;
  }
LABEL_7:
  v12 = -14;
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return v12;
}
