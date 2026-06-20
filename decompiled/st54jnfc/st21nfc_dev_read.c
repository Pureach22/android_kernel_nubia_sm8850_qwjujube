__int64 __fastcall st21nfc_dev_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  __int64 v3; // x23
  size_t v5; // x21
  unsigned int v6; // w22
  size_t v7; // x20
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v9; // x9
  __int64 v10; // x0
  unsigned __int64 v11; // x9
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x8
  unsigned __int64 v20; // x9

  if ( !a3 )
    return 0;
  v3 = *(_QWORD *)(a1 + 32);
  if ( a3 >= 0x104 )
    v5 = 260;
  else
    v5 = a3;
  if ( !(unsigned int)gpiod_get_value(*(_QWORD *)(v3 + 768)) )
  {
    printk(&unk_84E6, "st21nfc_dev_read");
    memset((void *)(v3 + 80), 126, v5);
    _check_object_size(v3 + 80, v5, 1);
    v7 = v5;
    if ( !inline_copy_to_user(a2, v3 + 80, v5) )
      return v7;
    goto LABEL_14;
  }
  mutex_lock(v3 - 152);
  v6 = i2c_transfer_buffer_flags(*(_QWORD *)(v3 - 8), v3 + 80, (unsigned int)v5, 1);
  mutex_unlock(v3 - 152);
  if ( (v6 & 0x80000000) != 0 )
  {
    printk(&unk_877E, "st21nfc_dev_read");
    return (int)v6;
  }
  v7 = v6;
  if ( v5 < v6 )
  {
    printk(&unk_884D, "st21nfc_dev_read");
    return -5;
  }
  _check_object_size(v3 + 80, v6, 1);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v9 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v9 = a2 & ((__int64)(a2 << 8) >> 8);
  v10 = v6;
  if ( 0x8000000000LL - (unsigned __int64)v6 >= v9 )
  {
    v11 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v17 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v17 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v17);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v11);
    v10 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL, v3 + 80, v6);
    v18 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v20 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v20 - 4096);
    _WriteStatusReg(TTBR1_EL1, v20);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v18);
  }
  if ( v10 )
  {
LABEL_14:
    printk(&unk_86C4, "st21nfc_dev_read");
    return -14;
  }
  return v7;
}
