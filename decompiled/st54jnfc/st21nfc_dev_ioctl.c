__int64 __fastcall st21nfc_dev_ioctl(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  __int64 v3; // x21
  unsigned __int64 StatusReg; // x9
  __int64 v5; // x10
  unsigned __int64 v6; // x9
  unsigned __int64 v7; // x9
  __int64 v8; // x10
  unsigned __int64 v9; // x9
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x9
  void (__fastcall *v13)(__int64, __int64); // x8
  unsigned __int64 v15; // x10
  unsigned __int64 v21; // x8
  __int64 v23; // x1
  __int64 v24; // x0
  int v25; // w8
  __int64 v26; // x0
  __int64 v27; // x1
  unsigned __int64 v28; // x0
  unsigned __int64 v29; // x0
  __int64 v30; // x8
  void (__fastcall *v31)(__int64, __int64); // x8
  __int64 v32; // x1
  void (__fastcall *v33)(_QWORD, __int64); // x8
  __int64 v34; // x1

  if ( (a2 & 0xFF00) != 0xEA00 )
    return -25;
  v3 = *(_QWORD *)(a1 + 32);
  if ( (a2 & 0x80000000) != 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v5 = *(_QWORD *)StatusReg, v6 = a3, (v5 & 0x4000000) != 0) )
      v6 = a3 & ((__int64)(a3 << 8) >> 8);
    if ( 0x8000000000LL - (unsigned __int64)(WORD1(a2) & 0x3FFF) < v6 )
      return -14;
  }
  if ( (a2 & 0x40000000) != 0 )
  {
    v7 = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(v7 + 70) & 0x20) != 0 || (v8 = *(_QWORD *)v7, v9 = a3, (v8 & 0x4000000) != 0) )
      v9 = a3 & ((__int64)(a3 << 8) >> 8);
    if ( 0x8000000000LL - (unsigned __int64)(WORD1(a2) & 0x3FFF) < v9 )
      return -14;
  }
  if ( (int)a2 <= 59904 )
  {
    if ( (int)a2 > -2147161596 )
    {
      if ( (_DWORD)a2 == -2147161593 )
        goto LABEL_31;
      if ( (_DWORD)a2 != -2147161595 )
      {
        v25 = -2147161592;
        goto LABEL_53;
      }
      goto LABEL_46;
    }
    if ( (_DWORD)a2 == -2147161599 )
    {
LABEL_29:
      LODWORD(v13) = gpiod_get_value(*(_QWORD *)(v3 + 768)) != 0;
      return (int)v13;
    }
    if ( (_DWORD)a2 != -2147161598 )
    {
      if ( (_DWORD)a2 != -2147161597 )
        goto LABEL_64;
      goto LABEL_47;
    }
LABEL_49:
    printk(&unk_8408, "st21nfc_dev_ioctl");
    v28 = *(_QWORD *)(v3 + 776);
    if ( v28 && v28 <= 0xFFFFFFFFFFFFF000LL )
    {
      v31 = (void (__fastcall *)(__int64, __int64))st21nfc_st54spi_cb;
      if ( st21nfc_st54spi_cb )
      {
        v32 = st21nfc_st54spi_data;
        if ( *((_DWORD *)st21nfc_st54spi_cb - 1) != 127008684 )
          __break(0x8228u);
        v31(1, v32);
        v28 = *(_QWORD *)(v3 + 776);
      }
      gpiod_set_value(v28, 0);
      msleep(20);
      gpiod_set_value(*(_QWORD *)(v3 + 776), 1);
      usleep_range_state(10000, 11000, 2);
      gpiod_set_value(*(_QWORD *)(v3 + 776), 0);
      msleep(20);
      gpiod_set_value(*(_QWORD *)(v3 + 776), 1);
      printk(&unk_8AEA, "st21nfc_dev_ioctl");
      v33 = (void (__fastcall *)(_QWORD, __int64))st21nfc_st54spi_cb;
      if ( st21nfc_st54spi_cb )
      {
        v34 = st21nfc_st54spi_data;
        if ( *((_DWORD *)st21nfc_st54spi_cb - 1) != 127008684 )
          __break(0x8228u);
        v33(0, v34);
      }
    }
    LODWORD(v13) = 0;
    *(_DWORD *)(v3 + 364) = 0;
    return (int)v13;
  }
  if ( (int)a2 <= 59910 )
  {
    if ( (int)a2 < 59906 )
      goto LABEL_29;
    if ( (_DWORD)a2 != 59906 )
    {
      if ( (_DWORD)a2 != 59907 )
      {
        if ( (_DWORD)a2 != 59909 )
          goto LABEL_64;
LABEL_46:
        printk(&unk_8BA9, a2);
        v26 = v3 - 176;
        v27 = 4;
LABEL_48:
        st21nfc_loc_set_polaritymode(v26, v27);
        LODWORD(v13) = 0;
        return (int)v13;
      }
LABEL_47:
      printk(&unk_853F, a2);
      v26 = v3 - 176;
      v27 = 1;
      goto LABEL_48;
    }
    goto LABEL_49;
  }
  if ( (_DWORD)a2 == 59911 )
  {
LABEL_31:
    LODWORD(v13) = *(_DWORD *)(v3 + 804);
    return (int)v13;
  }
  if ( (_DWORD)a2 == 1074063881 )
  {
    v11 = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(v11 + 70) & 0x20) != 0 || (v12 = a3, (*(_QWORD *)v11 & 0x4000000) != 0) )
      v12 = a3 & ((__int64)(a3 << 8) >> 8);
    if ( v12 <= 0x7FFFFFFFFCLL )
    {
      _X9 = a3 & 0xFF7FFFFFFFFFFFFFLL;
      v15 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v21 = *(_QWORD *)(v11 + 8);
      _WriteStatusReg(TTBR1_EL1, v21 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v21);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v15);
      __asm { LDTR            W19, [X9] }
      uaccess_ttbr0_disable();
      v13 = (void (__fastcall *)(__int64, __int64))st21nfc_st54spi_cb;
      if ( st21nfc_st54spi_cb )
      {
        v23 = st21nfc_st54spi_data;
        if ( (_DWORD)_X19 )
          v24 = 3;
        else
          v24 = 2;
        if ( *((_DWORD *)st21nfc_st54spi_cb - 1) != 127008684 )
          __break(0x8228u);
        v13(v24, v23);
        LODWORD(v13) = 0;
      }
    }
    else
    {
      LODWORD(v13) = -14;
    }
    return (int)v13;
  }
  v25 = 59912;
LABEL_53:
  if ( (_DWORD)a2 != v25 )
  {
LABEL_64:
    printk(&unk_8678, "st21nfc_dev_ioctl");
    LODWORD(v13) = -22;
    return (int)v13;
  }
  printk(&unk_8CA0, "st21nfc_dev_ioctl");
  mutex_lock(v3 - 56);
  v29 = *(_QWORD *)(v3 + 776);
  if ( v29 && v29 <= 0xFFFFFFFFFFFFF000LL )
  {
    if ( *(_BYTE *)(v3 + 352) == 1 )
    {
      devm_free_irq(*(_QWORD *)(v3 - 8) + 32LL, *(unsigned int *)(*(_QWORD *)(v3 - 8) + 948LL), v3 - 176);
      v29 = *(_QWORD *)(v3 + 776);
      *(_BYTE *)(v3 + 352) = 0;
    }
    gpiod_set_value(v29, 0);
    usleep_range_state(10000, 11000, 2);
    if ( (unsigned int)gpiod_direction_output(*(_QWORD *)(v3 + 768), 1) )
    {
      printk(&unk_8B4B, "st21nfc_dev_ioctl");
      mutex_unlock(v3 - 56);
      LODWORD(v13) = -19;
      return (int)v13;
    }
    gpiod_set_value(*(_QWORD *)(v3 + 768), 1);
    usleep_range_state(10000, 11000, 2);
    gpiod_set_value(*(_QWORD *)(v3 + 776), 1);
    printk(&unk_8A6E, "st21nfc_dev_ioctl");
  }
  msleep(20);
  gpiod_set_value(*(_QWORD *)(v3 + 768), 0);
  msleep(20);
  gpiod_set_value(*(_QWORD *)(v3 + 768), 1);
  msleep(20);
  gpiod_set_value(*(_QWORD *)(v3 + 768), 0);
  msleep(20);
  printk(&unk_88FB, "st21nfc_dev_ioctl");
  if ( (unsigned int)gpiod_direction_input(*(_QWORD *)(v3 + 768)) )
    printk(&unk_8B0A, "st21nfc_dev_ioctl");
  v30 = *(_QWORD *)(v3 - 8);
  *(_BYTE *)(v3 + 340) = 1;
  if ( !(unsigned int)devm_request_threaded_irq(
                        v30 + 32,
                        *(unsigned int *)(v30 + 948),
                        st21nfc_dev_irq_handler,
                        0,
                        *(unsigned int *)(v3 + 804),
                        v30 + 4,
                        v3 - 176) )
  {
    *(_BYTE *)(v3 + 352) = 1;
    st21nfc_disable_irq(v3 - 176);
    mutex_unlock(v3 - 56);
    LODWORD(v13) = 0;
    return (int)v13;
  }
  printk(&unk_84B9, "st21nfc_dev_ioctl");
  mutex_unlock(v3 - 56);
  return -19;
}
