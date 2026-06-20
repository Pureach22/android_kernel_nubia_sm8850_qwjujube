__int64 __fastcall dbglog_block_read(__int64 a1, unsigned __int64 a2, __int64 a3, _QWORD *a4)
{
  __int64 **v5; // x25
  __int64 v8; // x0
  __int64 v9; // x19
  unsigned __int64 v10; // x21
  __int64 *v11; // x24
  __int64 v12; // x8
  _QWORD *v13; // x9
  size_t v14; // x2
  __int64 *v15; // x8
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v17; // x9
  __int64 v18; // x0
  unsigned __int64 v19; // x9
  unsigned __int64 v25; // x8
  unsigned __int64 v26; // x8
  unsigned __int64 v28; // x9

  v5 = *(__int64 ***)(a1 + 32);
  v8 = _qdf_mem_valloc(a3, "dbglog_block_read", 4107);
  if ( v8 )
  {
    v9 = v8;
    raw_spin_lock_bh((char *)v5 + 20);
    if ( !*((_DWORD *)v5 + 4) )
    {
      *((_DWORD *)v5 + 6) = 0;
      _init_swait_queue_head(v5 + 4, "&x->wait", &init_completion___key_2);
      raw_spin_unlock_bh((char *)v5 + 20);
      if ( (unsigned int)wait_for_completion_interruptible(v5 + 3) == -512 )
      {
        v10 = -512;
LABEL_24:
        _qdf_mem_vfree(v9);
        return v10;
      }
      raw_spin_lock_bh((char *)v5 + 20);
    }
    v11 = *v5;
    v10 = 0;
    if ( *v5 != (__int64 *)v5 && v11 )
    {
      v10 = 0;
      while ( 1 )
      {
        --*((_DWORD *)v5 + 4);
        v12 = *v11;
        v13 = (_QWORD *)v11[1];
        *v11 = 0;
        v11[1] = 0;
        *(_QWORD *)(v12 + 8) = v13;
        *v13 = v12;
        v14 = *((unsigned int *)v11 + 28);
        if ( a3 - v10 < v14 )
          break;
        memcpy((void *)(v9 + v10), (const void *)v11[28], v14);
        v10 += *((unsigned int *)v11 + 28);
        sk_skb_reason_drop(0, v11, 2);
        v11 = *v5;
        if ( *v5 == (__int64 *)v5 || !v11 )
          goto LABEL_15;
      }
      v15 = *v5;
      *v11 = (__int64)*v5;
      v11[1] = (__int64)v5;
      v15[1] = (__int64)v11;
      *v5 = v11;
      ++*((_DWORD *)v5 + 4);
    }
LABEL_15:
    raw_spin_unlock_bh((char *)v5 + 20);
    if ( v10 >> 31 )
    {
      __break(0x800u);
      v10 = -14;
    }
    else
    {
      _check_object_size(v9, v10, 1);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v17 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v17 = a2 & ((__int64)(a2 << 8) >> 8);
      v18 = v10;
      if ( 0x8000000000LL - v10 >= v17 )
      {
        v19 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v25 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v25 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v25);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v19);
        v18 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL, v9, v10);
        v26 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v28 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v28 - 4096);
        _WriteStatusReg(TTBR1_EL1, v28);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v26);
      }
      if ( v18 )
        v10 = -14;
      else
        *a4 += v10;
    }
    goto LABEL_24;
  }
  return -12;
}
