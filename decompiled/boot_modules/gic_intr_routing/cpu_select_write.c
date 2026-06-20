unsigned __int64 __fastcall cpu_select_write(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  __int64 v5; // x21
  int v6; // w0
  char *v7; // x22
  __int64 v8; // x24
  unsigned __int64 v9; // x25
  char *v10; // x20
  unsigned __int64 v11; // x23
  char *v12; // x0
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v14; // x9
  size_t v15; // x28
  unsigned __int64 v16; // x1
  unsigned __int64 v17; // x0
  unsigned __int64 v18; // x9
  unsigned __int64 v23; // x8
  unsigned __int64 v24; // x8
  unsigned __int64 v26; // x9
  unsigned __int64 v27; // x2
  __int64 v28; // x0
  unsigned __int64 v29; // x9
  unsigned __int64 v31; // x9
  unsigned __int64 v32; // x25
  unsigned __int64 v33; // x23
  __int64 v34; // x27
  unsigned __int64 v37; // x10
  int v38; // w8
  __int64 v39; // x9
  __int64 v40; // x8
  __int64 v41; // x9
  __int64 v42; // x8
  unsigned __int64 v45; // x11
  unsigned __int64 v48; // x11
  unsigned __int64 v51; // x10
  char *stringp; // [xsp+8h] [xbp-18h] BYREF
  int v54; // [xsp+14h] [xbp-Ch]
  __int64 v55; // [xsp+18h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 696LL);
  v6 = _sw_hweight64(_cpu_possible_mask);
  v7 = (char *)v6;
  v54 = 0;
  if ( v6 < a3 >> 1 )
  {
    a3 = -22;
    goto LABEL_72;
  }
  LODWORD(v8) = v6;
  v9 = a3 + 1;
  v10 = (char *)_kmalloc_noprof(a3 + 1, 3264);
  if ( !v10 )
  {
LABEL_46:
    a3 = -12;
    goto LABEL_72;
  }
  while ( 1 )
  {
    stringp = v10;
    if ( (unsigned __int64)v7 >> 62
      || (v11 = 4LL * (int)v8, v12 = (char *)_kmalloc_noprof(v11, 3264), (v7 = v12) == nullptr) )
    {
      a3 = -12;
      v7 = v10;
      goto LABEL_71;
    }
    memset(v12, 255, 4LL * (int)v8);
    if ( a3 >= 0x21 )
    {
      _copy_overflow(32, a3);
      a3 = -14;
      goto LABEL_70;
    }
    _check_object_size(debugfs_buf, a3, 0);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v14 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v14 = a2 & ((__int64)(a2 << 8) >> 8);
    v15 = a3;
    if ( 0x8000000000LL - a3 < v14 )
      goto LABEL_11;
    v18 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v23 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v23 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v23);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v18);
    v17 = _arch_copy_from_user(debugfs_buf, a2 & 0xFF7FFFFFFFFFFFFFLL, a3);
    v15 = v17;
    v24 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v26 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v26 - 4096);
    _WriteStatusReg(TTBR1_EL1, v26);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v24);
    if ( v17 )
    {
LABEL_11:
      if ( a3 - v15 <= 0x20 )
        v16 = 32 - (a3 - v15);
      else
        v16 = 0;
      if ( v16 < v15 )
        goto LABEL_45;
      v17 = (unsigned __int64)memset(&debugfs_buf[a3 - v15], 0, v15);
      if ( v15 )
      {
        a3 = -14;
        goto LABEL_70;
      }
    }
    if ( a3 != 32 )
      break;
    __break(0x5512u);
LABEL_43:
    _fortify_panic(2, 32, v17 + 1);
LABEL_44:
    _fortify_panic(7, v9, v27);
LABEL_45:
    _fortify_panic(15, v16, v15);
    v9 = a3 + 1;
    v33 = _ReadStatusReg(SP_EL0);
    v34 = *(_QWORD *)(v33 + 80);
    *(_QWORD *)(v33 + 80) = &_start_alloc_tags;
    v10 = (char *)_kmalloc_noprof(a3 + 1, 3264);
    *(_QWORD *)(v33 + 80) = v34;
    if ( !v10 )
      goto LABEL_46;
  }
  a2 = a3 + 1;
  debugfs_buf[a3] = 0;
  v17 = strnlen(debugfs_buf, a3 + 1);
  if ( v17 >= 0x20 && v17 != a2 )
    goto LABEL_43;
  if ( v17 == a2 )
    v27 = a3 + 1;
  else
    v27 = v17 + 1;
  if ( v27 > v9 )
    goto LABEL_44;
  v28 = sized_strscpy(v10, debugfs_buf);
  if ( v9 >= a3 )
  {
    v10[a3] = 0;
    cpus_read_lock(v28);
    v28 = (__int64)strsep(&stringp, " ");
    if ( !v28 )
      goto LABEL_38;
    while ( 1 )
    {
      v28 = kstrtouint();
      if ( !(_DWORD)v28 )
      {
        if ( v54 >= (int)v8
          || ((*(_QWORD *)((char *)&_cpu_online_mask + (((unsigned __int64)(unsigned int)v54 >> 3) & 0x1FFFFFF8)) >> v54)
            & 1) == 0 )
        {
          v28 = printk(&unk_8048, "cpu_select_write");
          a3 = -22;
          goto LABEL_69;
        }
        v29 = 4LL * v54;
        _CF = v11 >= v29;
        v31 = v11 - v29;
        if ( v54 < 0 || !_CF || v31 < 4 )
          break;
        *(_DWORD *)&v7[4 * v54] = 1;
      }
      v28 = (__int64)strsep(&stringp, " ");
      if ( !v28 )
        goto LABEL_38;
    }
  }
  while ( 1 )
  {
    __break(1u);
LABEL_38:
    if ( (int)v8 < 1 )
      break;
    v32 = 0;
    v8 &= 0x7FFFFFFFu;
    while ( ((4 * v32) & 0x8000000000000000LL) == 0 && v11 >= 4 * v32 && v11 - 4 * v32 >= 4 )
    {
      v38 = *(_DWORD *)&v7[4 * v32];
      if ( v38 == -1 )
      {
        if ( (*((_QWORD *)&_cpu_online_mask + (v32 >> 6)) & (1LL << v32)) != 0
          && (gic_routing_data[(v32 >> 6) + 2] & (1LL << v32)) == 0 )
        {
          v28 = process_cpu_index(v5, v32, 1u);
          if ( (v28 & 0x80000000) != 0 )
          {
LABEL_68:
            a3 = (int)v28;
            goto LABEL_69;
          }
          v41 = (unsigned int)v32 >> 6;
          v42 = 1LL << v32;
          _X10 = (unsigned __int64 *)&gic_routing_data[v41 + 2];
          __asm { PRFM            #0x11, [X10] }
          do
            v48 = __ldxr(_X10);
          while ( __stxr(v48 | v42, _X10) );
          _X9 = (unsigned __int64 *)&gic_routing_data[v41 + 1];
          __asm { PRFM            #0x11, [X9] }
          do
            v51 = __ldxr(_X9);
          while ( __stxr(v51 & ~v42, _X9) );
        }
      }
      else if ( v38 == 1 && (((unsigned __int64)gic_routing_data[(v32 >> 6) + 1] >> v32) & 1) == 0 )
      {
        v28 = process_cpu_index(v5, v32, 0);
        if ( (v28 & 0x80000000) != 0 )
          goto LABEL_68;
        v39 = (unsigned int)v32 >> 6;
        v40 = 1LL << v32;
        _X10 = (unsigned __int64 *)&gic_routing_data[v39 + 1];
        __asm { PRFM            #0x11, [X10] }
        do
          v45 = __ldxr(_X10);
        while ( __stxr(v45 | v40, _X10) );
        _X9 = (unsigned __int64 *)&gic_routing_data[v39 + 2];
        __asm { PRFM            #0x11, [X9] }
        do
          v37 = __ldxr(_X9);
        while ( __stxr(v37 & ~v40, _X9) );
      }
      if ( ++v32 == v8 )
        goto LABEL_69;
    }
  }
LABEL_69:
  cpus_read_unlock(v28);
LABEL_70:
  kfree(v10);
LABEL_71:
  kfree(v7);
LABEL_72:
  _ReadStatusReg(SP_EL0);
  return a3;
}
