__int64 __fastcall dp_debug_read_dpcd(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x23
  __int64 v9; // x19
  __int64 v10; // x0
  __int64 v11; // x20
  __int64 v12; // x1
  __int64 v13; // x9
  __int64 *v14; // x9
  int v15; // w8
  __int64 v16; // x9
  __int64 v17; // x10
  __int64 *v18; // t2
  unsigned int v19; // w21
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x28
  unsigned __int64 v22; // x8
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v24; // x9
  __int64 v25; // x21
  __int64 v26; // x0
  _QWORD *v28; // x9
  unsigned __int64 v29; // x9
  unsigned __int64 v34; // x8
  unsigned __int64 v35; // x8
  unsigned __int64 v37; // x10
  unsigned __int64 v38; // x20
  __int64 v39; // x21

  v4 = *(_QWORD *)(a1 + 32);
  if ( !v4 || !*(_QWORD *)(v4 + 128) )
    return -19;
  if ( *a4 )
    return 0;
  v9 = _kmalloc_cache_noprof(kthread_park, 3520, 4096);
  if ( !v9 )
    return -12;
  while ( 1 )
  {
    mutex_lock(v4 + 376);
    v10 = _kmalloc_cache_noprof(kthread_park, 3520, 4096);
    v11 = v10;
    if ( !v10 )
      break;
    if ( *(_BYTE *)(v4 + 160) == 1 )
    {
      ((void (__fastcall *)(_QWORD, __int64, _QWORD, _QWORD))dp_sim_read_dpcd_reg)(
        *(_QWORD *)(v4 + 424),
        v10,
        *(unsigned int *)(v4 + 12),
        *(unsigned int *)(v4 + 8));
    }
    else
    {
      v12 = *(unsigned int *)(v4 + 8);
      if ( (_DWORD)v12 )
      {
        v13 = *(_QWORD *)(v4 + 128);
        *(_DWORD *)(v4 + 12) = 1;
        if ( drm_dp_dpcd_read(*(_QWORD *)(v13 + 24), v12, v10, 1) != 1 )
        {
          v11 = 0;
          break;
        }
      }
      else
      {
        v14 = *(__int64 **)(v4 + 120);
        *(_DWORD *)(v4 + 12) = 20;
        v15 = *((_DWORD *)v14 + 4);
        v18 = v14;
        v16 = *v14;
        v17 = v18[1];
        *(_DWORD *)(v10 + 16) = v15;
        *(_QWORD *)v10 = v16;
        *(_QWORD *)(v10 + 8) = v17;
      }
    }
    v19 = scnprintf(v9, 4096, "%04x: ", *(_DWORD *)(v4 + 8));
    if ( !*(_DWORD *)(v4 + 12) )
    {
LABEL_18:
      kfree(v11);
      v22 = v19;
      if ( v19 >= a3 )
        v22 = a3;
      v11 = v22;
      if ( v22 > 0x1000 )
      {
        _copy_overflow(4096, v22);
      }
      else
      {
        _check_object_size(v9, v22, 1);
        StatusReg = _ReadStatusReg(SP_EL0);
        if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v24 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
          v24 = a2 & ((__int64)(a2 << 8) >> 8);
        v25 = v11;
        v26 = v11;
        _CF = 0x8000000000LL - v11 >= v24;
        v28 = a4;
        if ( _CF )
        {
          v29 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v34 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v34 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v34);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v29);
          v25 = v11;
          v26 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL);
          v28 = a4;
          v35 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v37 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v37 - 4096);
          _WriteStatusReg(TTBR1_EL1, v37);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v35);
        }
        if ( !v26 )
          *v28 += v25;
      }
      break;
    }
    v20 = 0;
    while ( v20 <= 0xFFF )
    {
      v21 = v20 + 1;
      v19 += scnprintf(v9 + v19, 4096 - v19, "%02x ", *(unsigned __int8 *)(v11 + v20));
      v20 = v21;
      if ( v21 >= *(unsigned int *)(v4 + 12) )
        goto LABEL_18;
    }
    __break(1u);
    v38 = _ReadStatusReg(SP_EL0);
    v39 = *(_QWORD *)(v38 + 80);
    *(_QWORD *)(v38 + 80) = &dp_debug_read_dpcd__alloc_tag;
    v9 = _kmalloc_cache_noprof(kthread_park, 3520, 4096);
    *(_QWORD *)(v38 + 80) = v39;
    if ( !v9 )
      return -12;
  }
  mutex_unlock(v4 + 376);
  kfree(v9);
  return v11;
}
