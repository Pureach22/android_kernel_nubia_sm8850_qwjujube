__int64 __fastcall btfmcodec_dev_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  __int64 v6; // x26
  __int64 v7; // x25
  _QWORD *v8; // x21
  __int64 v9; // x23
  __int64 v10; // x21
  unsigned __int64 v11; // x8
  __int64 v12; // x20
  __int64 v13; // x22
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v15; // x9
  int v16; // w23
  unsigned __int64 v17; // x9
  unsigned __int64 v23; // x8
  unsigned __int64 v24; // x8
  unsigned __int64 v26; // x9
  int v27; // w19
  __int64 result; // x0
  __int64 v29; // x0
  unsigned int v30; // w9
  void *v31; // x0
  _QWORD v32[6]; // [xsp+0h] [xbp-30h] BYREF

  v32[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 32);
  if ( (unsigned __int8)log_lvl >= 4u )
  {
    printk(&unk_C70A, "btfmcodec_dev_read");
    if ( !v6 )
      goto LABEL_33;
  }
  else if ( !v6 )
  {
    goto LABEL_33;
  }
  v7 = *(_QWORD *)(v6 + 976);
  if ( !v7 || *(_DWORD *)(v7 + 136) == 1 )
  {
LABEL_33:
    v30 = (unsigned __int8)log_lvl;
    _ReadStatusReg(SP_EL0);
    if ( v30 < 8 )
      v31 = &unk_D856;
    else
      v31 = &unk_C2E8;
    printk(v31, "btfmcodec_dev_read");
    result = -22;
    goto LABEL_37;
  }
  v8 = (_QWORD *)(v7 + 528);
  v9 = raw_spin_lock_irqsave(v7 + 520);
  if ( *(_QWORD *)(v7 + 528) == v7 + 528 )
  {
    raw_spin_unlock_irqrestore(v7 + 520, v9);
    if ( (*(_BYTE *)(a1 + 49) & 8) != 0 )
    {
      result = -11;
      goto LABEL_37;
    }
    if ( (_QWORD *)*v8 == v8 )
    {
      memset(v32, 0, 40);
      init_wait_entry(v32, 0);
      v29 = prepare_to_wait_event(v7 + 496, v32, 1);
      if ( *(_QWORD **)(v7 + 528) == v8 )
      {
        while ( !v29 )
        {
          schedule();
          v29 = prepare_to_wait_event(v7 + 496, v32, 1);
          if ( (_QWORD *)*v8 != v8 )
            goto LABEL_26;
        }
        if ( (_DWORD)v29 )
        {
          result = -512;
          goto LABEL_37;
        }
      }
      else
      {
LABEL_26:
        finish_wait(v7 + 496, v32);
      }
    }
    if ( *(_DWORD *)(*(_QWORD *)(v6 + 976) + 136LL) == 1 )
    {
      result = -102;
      goto LABEL_37;
    }
    v9 = raw_spin_lock_irqsave(v7 + 520);
  }
  v10 = skb_dequeue(v7 + 528);
  raw_spin_unlock_irqrestore(v7 + 520, v9);
  if ( v10 )
  {
    v11 = *(unsigned int *)(v10 + 112);
    if ( v11 >= a3 )
      LODWORD(v11) = a3;
    v12 = (int)v11;
    if ( (unsigned __int64)(int)v11 >> 31 )
    {
      __break(0x800u);
      v27 = -14;
    }
    else
    {
      v13 = *(_QWORD *)(v10 + 224);
      _check_object_size(v13, (int)v11, 1);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v15 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v15 = a2 & ((__int64)(a2 << 8) >> 8);
      v16 = v12;
      if ( 0x8000000000LL - v12 >= v15 )
      {
        v17 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v23 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v23 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v23);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v17);
        v12 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL, v13, v12);
        v24 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v26 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v26 - 4096);
        _WriteStatusReg(TTBR1_EL1, v26);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v24);
      }
      if ( v12 )
        v27 = -14;
      else
        v27 = v16;
    }
    sk_skb_reason_drop(0, v10, 2);
    if ( (unsigned __int8)log_lvl >= 4u )
    {
      _ReadStatusReg(SP_EL0);
      printk(&unk_C4D1, "btfmcodec_dev_read");
    }
    result = v27;
  }
  else
  {
    result = -14;
  }
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return result;
}
