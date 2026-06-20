__int64 __fastcall adreno_ioctl_read_calibrated_ts(__int64 *a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x22
  __int64 result; // x0
  unsigned __int64 v6; // x21
  __int64 v7; // x19
  __int64 v8; // x8
  __int64 v9; // x23
  unsigned __int64 v10; // x24
  unsigned __int64 StatusReg; // x25
  unsigned __int64 v12; // x8
  size_t v13; // x24
  size_t v14; // x1
  __int64 v15; // x23
  __int64 v16; // x20
  unsigned __int64 v17; // x8
  unsigned __int64 v23; // x9
  unsigned __int64 v24; // x8
  unsigned __int64 v26; // x9
  __int64 v27; // x8
  __int64 v28; // x8
  unsigned __int64 v29; // x9
  unsigned __int64 v30; // x26
  __int64 raw; // x25
  __int64 v33; // x1
  __int64 v34; // x8
  __int64 v35; // x9
  __int64 v36; // x11
  __int64 v37; // x21
  __int64 v38; // x20
  unsigned __int64 v39; // x23
  __int64 v40; // x24
  __int64 cx_timer; // [xsp+0h] [xbp-20h]
  __int64 v42; // [xsp+8h] [xbp-18h]
  __int64 v43; // [xsp+10h] [xbp-10h]
  __int64 v44; // [xsp+18h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a1;
  v42 = 0;
  v43 = 0;
  cx_timer = 0;
  if ( (*(_QWORD *)(v3 + 14240) & 0x20000) == 0 )
  {
    result = -95;
    goto LABEL_46;
  }
  if ( (unsigned int)(*(_DWORD *)(a3 + 24) - 7) < 0xFFFFFFFA )
  {
    result = -22;
    goto LABEL_46;
  }
  v6 = 4LL * *(unsigned int *)(a3 + 24);
  v7 = _kvmalloc_node_noprof(v6, 0, 3520, 0xFFFFFFFFLL);
  if ( !v7 )
  {
LABEL_43:
    result = -12;
    goto LABEL_46;
  }
  while ( 1 )
  {
    v8 = *(unsigned int *)(a3 + 24);
    if ( (unsigned int)v8 >> 29 )
    {
      v15 = 0;
      __break(0x800u);
      v16 = -14;
      goto LABEL_45;
    }
    v9 = 4 * v8;
    v10 = *(_QWORD *)a3;
    _check_object_size(v7, 4 * v8, 0);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v12 = v10, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v12 = v10 & ((__int64)(v10 << 8) >> 8);
    if ( 0x8000000000LL - v9 >= v12 )
    {
      v17 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v23 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v23 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v23);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v17);
      v13 = _arch_copy_from_user(v7, v10 & 0xFF7FFFFFFFFFFFFFLL, v9);
      v24 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v26 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v26 - 4096);
      _WriteStatusReg(TTBR1_EL1, v26);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v24);
      if ( !v13 )
        goto LABEL_19;
    }
    else
    {
      v13 = v9;
    }
    v14 = v6 >= v9 - v13 ? v6 - (v9 - v13) : 0LL;
    if ( v14 >= v13 )
      break;
LABEL_42:
    _fortify_panic(15, v14, v13);
    v39 = _ReadStatusReg(SP_EL0);
    v40 = *(_QWORD *)(v39 + 80);
    *(_QWORD *)(v39 + 80) = &adreno_ioctl_read_calibrated_ts__alloc_tag;
    v6 = 4LL * *(unsigned int *)(a3 + 24);
    v7 = _kvmalloc_node_noprof(v6, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(v39 + 80) = v40;
    if ( !v7 )
      goto LABEL_43;
  }
  memset((void *)(v7 + v9 - v13), 0, v13);
  if ( v13 )
  {
    v15 = 0;
    v16 = -14;
    goto LABEL_45;
  }
LABEL_19:
  v27 = *(unsigned int *)(a3 + 24);
  if ( (_DWORD)v27 )
  {
    v28 = 4 * v27;
    v29 = 0;
    while ( v6 > v29 )
    {
      if ( *(_DWORD *)(v7 + v29) > 2u )
      {
        v15 = 0;
        v16 = -22;
        goto LABEL_45;
      }
      v29 += 4LL;
      if ( v28 == v29 )
        goto LABEL_24;
    }
    goto LABEL_40;
  }
LABEL_24:
  v13 = 8LL * *(unsigned int *)(a3 + 24);
  v15 = _kvmalloc_node_noprof(v13, 0, 3520, 0xFFFFFFFFLL);
  if ( !v15 )
  {
    v16 = -12;
    goto LABEL_45;
  }
  v30 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  raw = ktime_get_raw();
  cx_timer = adreno_read_cx_timer(v3, v33);
  v42 = ktime_get(cx_timer);
  v43 = ktime_get_raw();
  _WriteStatusReg(DAIF, v30);
  v34 = *(unsigned int *)(a3 + 24);
  *(_QWORD *)(a3 + 16) = v43 - raw;
  if ( (_DWORD)v34 )
  {
    v35 = 0;
    while ( v6 > 4 * v35 )
    {
      v36 = *(unsigned int *)(v7 + 4 * v35);
      if ( (unsigned int)v36 > 2 )
        goto LABEL_41;
      if ( v13 <= 8 * v35 )
        break;
      *(_QWORD *)(v15 + 8 * v35++) = *(&cx_timer + v36);
      if ( v35 == v34 )
      {
        v37 = 8 * v34;
        goto LABEL_34;
      }
    }
LABEL_40:
    __break(1u);
LABEL_41:
    __break(0x5512u);
    goto LABEL_42;
  }
  v37 = 0;
LABEL_34:
  if ( (unsigned int)v34 >> 28 )
  {
    __break(0x800u);
    v16 = -14;
  }
  else
  {
    v38 = *(_QWORD *)(a3 + 8);
    _check_object_size(v15, v37, 1);
    if ( inline_copy_to_user(v38, v15, v37) )
      v16 = -14;
    else
      v16 = 0;
  }
LABEL_45:
  kvfree(v15);
  kvfree(v7);
  result = v16;
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return result;
}
