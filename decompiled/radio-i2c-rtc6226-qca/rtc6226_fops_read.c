__int64 __fastcall rtc6226_fops_read(__int64 a1, unsigned __int64 a2, unsigned int a3)
{
  __int64 v5; // x21
  __int64 v6; // x22
  __int64 v8; // x20
  __int64 v9; // x0
  __int64 v10; // x22
  __int64 v11; // x21
  unsigned int v12; // w20
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v14; // x9
  int v15; // w0
  unsigned __int64 v16; // x9
  unsigned __int64 v21; // x8
  unsigned __int64 v22; // x8
  unsigned __int64 v24; // x9
  __int64 result; // x0
  _QWORD v26[5]; // [xsp+0h] [xbp-130h] BYREF
  _QWORD v27[33]; // [xsp+28h] [xbp-108h] BYREF

  v27[32] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(video_devdata() + 336);
  memset(v27, 0, 256);
  if ( a2 && v5 )
  {
    if ( a3 > 0xC )
    {
      printk(&unk_D773, "rtc6226_fops_read");
      result = -22;
    }
    else
    {
      v6 = a3 & 0xF;
      _ZF = a3 == 1;
      v8 = v5 + 24 * v6 + 3136;
      if ( !_ZF || *(_DWORD *)(v5 + 24 * v6 + 3136) != *(_DWORD *)(v5 + 24 * v6 + 3140) )
        goto LABEL_12;
      memset(v26, 0, sizeof(v26));
      init_wait_entry(v26, 0);
      while ( 1 )
      {
        v9 = prepare_to_wait_event(v5 + 2520, v26, 1);
        if ( *(_DWORD *)(v5 + 24 * v6 + 3136) != *(_DWORD *)(v5 + 24 * v6 + 3140) )
        {
          finish_wait(v5 + 2520, v26);
          goto LABEL_12;
        }
        if ( v9 )
          break;
        schedule();
      }
      if ( (v9 & 0x80000000) != 0 )
      {
        result = -4;
      }
      else
      {
LABEL_12:
        v10 = v5 + 4 * v6;
        v11 = raw_spin_lock_irqsave(v10 + 1972);
        v12 = _kfifo_out(v8, v27, 256);
        raw_spin_unlock_irqrestore(v10 + 1972, v11);
        if ( v12 >= 0x101 )
        {
          _copy_overflow(256, v12);
          v15 = v12;
        }
        else
        {
          _check_object_size(v27, v12, 1);
          StatusReg = _ReadStatusReg(SP_EL0);
          if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v14 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
            v14 = a2 & ((__int64)(a2 << 8) >> 8);
          v15 = v12;
          if ( 0x8000000000LL - (unsigned __int64)v12 >= v14 )
          {
            v16 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v21 = *(_QWORD *)(StatusReg + 8);
            _WriteStatusReg(TTBR1_EL1, v21 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
            _WriteStatusReg(TTBR0_EL1, v21);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v16);
            v15 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL, v27, v12);
            v22 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v24 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
            _WriteStatusReg(TTBR0_EL1, v24 - 4096);
            _WriteStatusReg(TTBR1_EL1, v24);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v22);
          }
        }
        if ( v15 >= 1 )
        {
          printk(&unk_D474, "rtc6226_fops_read");
          result = -11;
        }
        else
        {
          result = (int)v12;
        }
      }
    }
  }
  else
  {
    printk(&unk_DCAA, "rtc6226_fops_read");
    result = -6;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
