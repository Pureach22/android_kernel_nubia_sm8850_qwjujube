__int64 __fastcall kgsl_ioctl_get_fault_report(__int64 *a1, __int64 a2, __int64 a3)
{
  unsigned int v4; // w8
  unsigned __int64 v5; // x21
  size_t v6; // x22
  __int64 owner; // x0
  __int64 v9; // x24
  unsigned int v10; // w24
  __int64 v11; // x26
  __int64 result; // x0
  unsigned __int64 v13; // x23
  unsigned int v14; // w8
  unsigned __int64 v15; // x21
  __int64 v16; // x20
  __int64 *v17; // x8
  __int64 v18; // x11
  unsigned __int64 v19; // x8
  unsigned __int64 v20; // x9
  unsigned __int64 v26; // x8
  unsigned __int64 v27; // x8
  unsigned __int64 v29; // x9
  unsigned int v30; // w25
  size_t v31; // x21
  __int64 v32; // x20
  int v33; // w27
  _QWORD *v34; // x8
  __int64 v35; // x10
  __int64 v36; // x11
  __int64 *v37; // x25
  __int64 v38; // x10
  __int64 v39; // x27
  __int64 v40; // x8
  unsigned int v41; // w28
  unsigned int v42; // w9
  unsigned int v43; // w10
  __int64 v44; // x23
  __int64 v45; // x8
  __int64 v46; // x22
  unsigned __int64 v47; // x26
  unsigned __int64 v48; // x8
  unsigned __int64 v49; // x8
  unsigned __int64 v51; // x9
  unsigned __int64 v52; // x8
  unsigned __int64 v54; // x9
  int v56; // w8
  int v58; // w8
  unsigned __int64 StatusReg; // [xsp+10h] [xbp-30h]
  __int64 v60; // [xsp+18h] [xbp-28h] BYREF
  __int64 v61; // [xsp+20h] [xbp-20h]
  __int64 v62; // [xsp+28h] [xbp-18h]
  _QWORD v63[2]; // [xsp+30h] [xbp-10h]

  v63[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)(a3 + 12);
  v5 = *(_QWORD *)a3;
  if ( v4 >= 0x18 )
    v6 = 24;
  else
    v6 = v4;
  owner = kgsl_context_get_owner(a1, *(_DWORD *)(a3 + 16));
  if ( !owner )
  {
    result = -22;
    goto LABEL_85;
  }
  _X19 = owner;
  v9 = 0xFFFFFFEA00000000LL;
  if ( (*(_BYTE *)(owner + 203) & 0x40) == 0 || (*(_QWORD *)(owner + 32) & 4) == 0 )
    goto LABEL_79;
  if ( *(_QWORD *)a3 )
  {
    if ( *(_DWORD *)(a3 + 8) )
    {
      v10 = 0;
      while ( 1 )
      {
        v61 = 0;
        v62 = 0;
        v60 = 0;
        _check_object_size(&v60, v6, 0);
        if ( inline_copy_from_user_0((int)&v60, v5, v6) )
          goto LABEL_35;
        if ( v60 )
          break;
        LODWORD(v11) = *(_DWORD *)(a3 + 8);
        ++v10;
        LODWORD(v5) = v5 + *(_DWORD *)(a3 + 12);
        if ( v10 >= (unsigned int)v11 )
          goto LABEL_19;
      }
      LODWORD(v11) = *(_DWORD *)(a3 + 8);
LABEL_19:
      v13 = *(_QWORD *)a3;
      if ( v10 == (_DWORD)v11 )
        goto LABEL_20;
      v30 = *(_DWORD *)(a3 + 12);
      v63[0] = 0;
      if ( v30 >= 0x18 )
        v31 = 24;
      else
        v31 = v30;
      v32 = _kmalloc_cache_noprof(raw_read_unlock, 3520, 48);
      if ( v32 )
      {
        if ( (_DWORD)v11 )
        {
          v33 = 0;
          v11 = (unsigned int)v11;
          v9 = 0xFFFFFFF200000000LL;
          do
          {
            v61 = 0;
            v62 = 0;
            v60 = 0;
            _check_object_size(&v60, v31, 0);
            if ( inline_copy_from_user_0((int)&v60, (int)v13 + v33, v31) )
              goto LABEL_67;
            if ( (unsigned int)v61 >= 2 )
            {
              v9 = 0xFFFFFFEA00000000LL;
              goto LABEL_67;
            }
            v34 = (_QWORD *)(v32 + 24LL * (unsigned int)v61);
            v35 = v61;
            v36 = v62;
            --v11;
            v33 += v30;
            *v34 = v60;
            v34[1] = v35;
            v34[2] = v36;
          }
          while ( v11 );
        }
        mutex_lock(_X19 + 312);
        v37 = *(__int64 **)(_X19 + 296);
        v38 = _X19 + 296;
        if ( v37 == (__int64 *)(_X19 + 296) )
        {
LABEL_64:
          v9 = 0;
LABEL_65:
          mutex_unlock(_X19 + 312);
LABEL_67:
          kfree(v32);
          goto LABEL_79;
        }
        v9 = 0xFFFFFFF200000000LL;
        StatusReg = _ReadStatusReg(SP_EL0);
        while ( 1 )
        {
          v39 = *((unsigned int *)v37 + 4);
          if ( (unsigned int)v39 >= 2 )
            goto LABEL_68;
          v40 = v32 + 24LL * (unsigned int)v39;
          v41 = *((_DWORD *)v63 + v39);
          if ( v41 < *(_DWORD *)(v40 + 12) )
          {
            v42 = *(_DWORD *)(v40 + 16);
            if ( (_DWORD)v39 == 1 )
              v43 = 32;
            else
              v43 = v31;
            v44 = v37[3];
            v45 = *(_QWORD *)v40;
            if ( v43 >= v42 )
              LODWORD(v31) = v42;
            else
              LODWORD(v31) = v43;
            v46 = (unsigned int)v31;
            v47 = v45 + v42 * v41;
            _check_object_size(v37[3], (unsigned int)v31, 1);
            if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v48 = v47, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
              v48 = v47 & ((__int64)(v47 << 8) >> 8);
            if ( 0x8000000000LL - (unsigned __int64)(unsigned int)v31 >= v48 )
            {
              v49 = _ReadStatusReg(DAIF);
              __asm { MSR             DAIFSet, #3 }
              v51 = *(_QWORD *)(StatusReg + 8);
              _WriteStatusReg(TTBR1_EL1, v51 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
              _WriteStatusReg(TTBR0_EL1, v51);
              __isb(0xFu);
              _WriteStatusReg(DAIF, v49);
              v46 = _arch_copy_to_user(v47 & 0xFF7FFFFFFFFFFFFFLL, v44, (unsigned int)v31);
              v52 = _ReadStatusReg(DAIF);
              __asm { MSR             DAIFSet, #3 }
              v54 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
              _WriteStatusReg(TTBR0_EL1, v54 - 4096);
              _WriteStatusReg(TTBR1_EL1, v54);
              __isb(0xFu);
              _WriteStatusReg(DAIF, v52);
            }
            if ( v46 )
              goto LABEL_65;
            v38 = _X19 + 296;
            *((_DWORD *)v63 + v39) = v41 + 1;
          }
          v37 = (__int64 *)*v37;
          if ( v37 == (__int64 *)v38 )
            goto LABEL_64;
        }
      }
      v9 = 0xFFFFFFF400000000LL;
    }
    else
    {
      v13 = *(_QWORD *)a3;
      v10 = 0;
LABEL_20:
      v14 = *(_DWORD *)(a3 + 12);
      v15 = v13;
      v63[0] = 0;
      if ( v14 >= 0x18 )
        v16 = 24;
      else
        v16 = v14;
      mutex_lock(_X19 + 312);
      v17 = *(__int64 **)(_X19 + 296);
      if ( v17 != (__int64 *)(_X19 + 296) )
      {
        while ( 1 )
        {
          v18 = *((unsigned int *)v17 + 4);
          if ( (unsigned int)v18 >= 3 )
            break;
          if ( (_DWORD)v18 == 2 )
            goto LABEL_69;
          v17 = (__int64 *)*v17;
          ++*((_DWORD *)v63 + v18);
          if ( v17 == (__int64 *)(_X19 + 296) )
            goto LABEL_27;
        }
LABEL_68:
        __break(0x5512u);
LABEL_69:
        __break(1u);
        goto LABEL_70;
      }
LABEL_27:
      mutex_unlock(_X19 + 312);
      if ( !v10 )
        goto LABEL_36;
      v61 = 0;
      v62 = 0;
      v60 = 0;
      if ( !HIDWORD(v63[0]) )
        goto LABEL_36;
      LODWORD(v61) = 1;
      HIDWORD(v61) = HIDWORD(v63[0]);
      _check_object_size(&v60, v16, 1);
      v19 = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(v19 + 70) & 0x20) != 0 || (*(_QWORD *)v19 & 0x4000000) != 0 )
        v15 = v13 & ((__int64)(v13 << 8) >> 8);
      if ( 0x8000000000LL - v16 >= v15 )
      {
        v20 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v26 = *(_QWORD *)(v19 + 8);
        _WriteStatusReg(TTBR1_EL1, v26 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v26);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v20);
        v16 = _arch_copy_to_user(v13 & 0xFF7FFFFFFFFFFFFFLL, &v60, v16);
        v27 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v29 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v29 - 4096);
        _WriteStatusReg(TTBR1_EL1, v29);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v27);
      }
      if ( v16 )
LABEL_35:
        v9 = 0xFFFFFFF200000000LL;
      else
LABEL_36:
        v9 = 0;
    }
LABEL_79:
    __asm { PRFM            #0x11, [X19] }
    do
      v58 = __ldxr((unsigned int *)_X19);
    while ( __stlxr(v58 - 1, (unsigned int *)_X19) );
    if ( v58 == 1 )
    {
      __dmb(9u);
      kgsl_context_destroy(_X19);
    }
    else if ( v58 <= 0 )
    {
      refcount_warn_saturate(_X19, 3);
    }
    result = v9 >> 32;
    goto LABEL_85;
  }
  *(_DWORD *)(a3 + 8) = 2;
LABEL_70:
  __asm { PRFM            #0x11, [X19] }
  do
    v56 = __ldxr((unsigned int *)_X19);
  while ( __stlxr(v56 - 1, (unsigned int *)_X19) );
  if ( v56 == 1 )
  {
    __dmb(9u);
    kgsl_context_destroy(_X19);
    result = 0;
  }
  else
  {
    if ( v56 <= 0 )
      refcount_warn_saturate(_X19, 3);
    result = 0;
  }
LABEL_85:
  _ReadStatusReg(SP_EL0);
  return result;
}
