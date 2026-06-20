__int64 __fastcall rtc6226_vidioc_dqbuf(__int64 a1, __int64 a2, unsigned int *a3)
{
  __int64 v4; // x22
  __int64 v5; // x24
  unsigned __int64 v6; // x23
  int v7; // w20
  __int64 v8; // x21
  __int64 v9; // x0
  __int64 v10; // x24
  __int64 v11; // x22
  unsigned int v12; // w20
  int v13; // w19
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v15; // x9
  unsigned __int64 v16; // x9
  unsigned __int64 v22; // x8
  unsigned __int64 v23; // x8
  unsigned __int64 v25; // x9
  void *v27; // x0
  _QWORD v28[5]; // [xsp+0h] [xbp-130h] BYREF
  _QWORD v29[33]; // [xsp+28h] [xbp-108h] BYREF

  v29[32] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(video_devdata() + 336);
  memset(v29, 0, 256);
  if ( !a3 || !v4 )
  {
    printk(&unk_DCAA, "rtc6226_vidioc_dqbuf");
    v13 = -6;
    goto LABEL_20;
  }
  v5 = *a3;
  if ( (unsigned int)v5 > 0xC )
  {
    v27 = &unk_D773;
LABEL_26:
    printk(v27, "rtc6226_vidioc_dqbuf");
    v13 = -22;
    goto LABEL_20;
  }
  v6 = *((_QWORD *)a3 + 8);
  v7 = a3[18];
  v8 = v4 + 24LL * (unsigned int)v5 + 3136;
  if ( (_DWORD)v5 == 1 && *(_DWORD *)(v4 + 3160) == *(_DWORD *)(v4 + 3164) )
  {
    memset(v28, 0, sizeof(v28));
    init_wait_entry(v28, 0);
    while ( 1 )
    {
      v9 = prepare_to_wait_event(v4 + 2520, v28, 1);
      if ( *(_DWORD *)(v4 + 24LL * (unsigned int)v5 + 3136) != *(_DWORD *)(v4 + 24LL * (unsigned int)v5 + 3140) )
      {
        finish_wait(v4 + 2520, v28);
        goto LABEL_11;
      }
      if ( v9 )
        break;
      schedule();
    }
    if ( (v9 & 0x80000000) != 0 )
    {
      v13 = -4;
      goto LABEL_20;
    }
  }
LABEL_11:
  if ( v7 > 256 )
  {
    v27 = &unk_CDE2;
    goto LABEL_26;
  }
  v10 = v4 + 4 * v5;
  v11 = raw_spin_lock_irqsave(v10 + 1972);
  v12 = _kfifo_out(v8, v29, (unsigned int)v7);
  raw_spin_unlock_irqrestore(v10 + 1972, v11);
  a3[2] = v12;
  v13 = v12;
  if ( v12 >= 0x101 )
  {
    _copy_overflow(256, v12);
  }
  else
  {
    _check_object_size(v29, v12, 1);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v15 = v6, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v15 = v6 & ((__int64)(v6 << 8) >> 8);
    if ( 0x8000000000LL - (unsigned __int64)v12 >= v15 )
    {
      v16 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v22 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v22 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v22);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v16);
      v13 = _arch_copy_to_user(v6 & 0xFF7FFFFFFFFFFFFFLL, v29, v12);
      v23 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v25 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v25 - 4096);
      _WriteStatusReg(TTBR1_EL1, v25);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v23);
    }
  }
  if ( v13 > 0 )
  {
    printk(&unk_D474, "rtc6226_vidioc_dqbuf");
    v13 = -11;
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v13;
}
