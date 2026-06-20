__int64 __fastcall dp_sim_debug_read_dpcd(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x24
  unsigned __int64 v5; // x20
  char *v9; // x19
  int v10; // w0
  unsigned int v11; // w8
  unsigned int v12; // w27
  unsigned __int64 v13; // x8
  unsigned __int64 v14; // x9
  __int64 v15; // x0
  _QWORD *v17; // x9
  unsigned __int64 v18; // x9
  unsigned __int64 v23; // x8
  unsigned __int64 v24; // x8
  unsigned __int64 v26; // x10
  unsigned __int64 StatusReg; // x20
  __int64 v28; // x21

  v4 = *(_QWORD *)(a1 + 32);
  if ( !v4 )
    return -19;
  if ( *a4 )
    return 0;
  v9 = (char *)_kmalloc_cache_noprof(kthread_park, 3520, 4096);
  if ( !v9 )
    return -12;
LABEL_6:
  mutex_lock(v4 + 88);
  v10 = snprintf(v9, 0x1000u, "0x%x", *(_DWORD *)(v4 + 2224));
  v11 = *(_DWORD *)(v4 + 2224);
  LODWORD(v5) = v10;
  if ( v11 <= 0xFFF )
  {
    v12 = 0;
    while ( v12 < *(_DWORD *)(v4 + 2228) )
    {
      if ( v11 >= 0x800 )
      {
        __break(0x5512u);
        StatusReg = _ReadStatusReg(SP_EL0);
        v28 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &dp_sim_debug_read_dpcd__alloc_tag;
        v9 = (char *)_kmalloc_cache_noprof(kthread_park, 3520, 4096);
        *(_QWORD *)(StatusReg + 80) = v28;
        if ( v9 )
          goto LABEL_6;
        return -12;
      }
      ++v12;
      LODWORD(v5) = snprintf(
                      &v9[(unsigned int)v5],
                      (unsigned int)(4096 - v5),
                      "0x%x",
                      *(unsigned __int8 *)(v4 + 160 + v11))
                  + v5;
      v11 = *(_DWORD *)(v4 + 2224) + v12;
      if ( v11 >= 0x1000 )
        break;
    }
  }
  mutex_unlock(v4 + 88);
  if ( (unsigned int)v5 >= a3 )
    v5 = a3;
  else
    v5 = (unsigned int)v5;
  if ( v5 > 0x1000 )
  {
    _copy_overflow(4096, v5);
  }
  else
  {
    _check_object_size(v9, v5, 1);
    v13 = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(v13 + 70) & 0x20) != 0 || (v14 = a2, (*(_QWORD *)v13 & 0x4000000) != 0) )
      v14 = a2 & ((__int64)(a2 << 8) >> 8);
    v15 = v5;
    _CF = 0x8000000000LL - v5 >= v14;
    v17 = a4;
    if ( _CF )
    {
      v18 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v23 = *(_QWORD *)(v13 + 8);
      _WriteStatusReg(TTBR1_EL1, v23 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v23);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v18);
      v15 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL);
      v17 = a4;
      v24 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v26 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v26 - 4096);
      _WriteStatusReg(TTBR1_EL1, v26);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v24);
    }
    if ( !v15 )
      *v17 += v5;
  }
  kfree(v9);
  return v5;
}
