__int64 __fastcall syna_cdev_ioctl_raw_read(__int64 a1, unsigned __int64 a2, __int64 a3, unsigned int a4)
{
  unsigned int v4; // w19
  size_t v7; // x22
  void *v8; // x0
  __int64 v9; // x22
  __int64 v10; // x0
  __int64 v11; // x2
  __int64 v12; // x0
  __int64 v13; // x2
  __int64 v14; // x2
  __int64 v15; // x0
  __int64 (*v16)(void); // x8
  __int64 v17; // x22
  int v18; // w0
  __int64 v19; // x2
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v21; // x9
  unsigned __int64 v22; // x9
  unsigned __int64 v28; // x8
  __int64 v29; // x0
  unsigned __int64 v30; // x8
  unsigned __int64 v32; // x9
  int v33; // w21
  void *v34; // x0
  void *v35; // x0
  __int64 v36; // x0
  char v37; // w8

  v4 = a4;
  if ( a4 > (unsigned int)a3 )
  {
    printk(&unk_388A5, "syna_cdev_ioctl_raw_read", a3);
    return (unsigned int)-22;
  }
  if ( !a4 )
  {
    printk(&unk_3A9D0, "syna_cdev_ioctl_raw_read", a3);
    return v4;
  }
  mutex_lock(*(_QWORD *)a1 + 840LL);
  if ( (_BYTE)qword_31698 )
    printk(&unk_38244, "syna_tcm_buf_lock", (unsigned __int8)qword_31698);
  mutex_lock(&qword_31668);
  v7 = (unsigned int)qword_31660;
  v8 = (void *)qword_31658;
  LOBYTE(qword_31698) = qword_31698 + 1;
  if ( (unsigned int)qword_31660 < v4 )
  {
    if ( qword_31658 )
    {
      v9 = qword_31658;
      v10 = syna_request_managed_device(qword_31658);
      if ( !v10 )
      {
        v36 = printk(&unk_3BE43, "syna_pal_mem_free", v11);
        v12 = syna_request_managed_device(v36);
        if ( v12 )
          goto LABEL_10;
        goto LABEL_36;
      }
      v8 = (void *)devm_kfree(v10, v9);
    }
    v12 = syna_request_managed_device(v8);
    if ( v12 )
    {
LABEL_10:
      if ( (int)v4 > 0 )
      {
        v7 = v4;
        v8 = (void *)devm_kmalloc(v12, v4, 3520);
        qword_31658 = (__int64)v8;
        if ( v8 )
        {
          LODWORD(qword_31660) = v4;
          goto LABEL_13;
        }
LABEL_38:
        printk(&unk_3703C, "syna_tcm_buf_alloc", v4);
        qword_31660 = 0;
        printk(&unk_376CF, "syna_cdev_ioctl_raw_read", v4);
        v4 = -243;
        goto LABEL_39;
      }
      v35 = &unk_38286;
LABEL_37:
      printk(v35, "syna_pal_mem_alloc", v13);
      qword_31658 = 0;
      goto LABEL_38;
    }
LABEL_36:
    v35 = &unk_3BE43;
    goto LABEL_37;
  }
LABEL_13:
  memset(v8, 0, v7);
  HIDWORD(qword_31660) = 0;
  if ( !*(_QWORD *)a1 )
  {
    v33 = -241;
    v34 = &unk_3365A;
LABEL_31:
    printk(v34, "syna_tcm_read", v14);
LABEL_33:
    printk(&unk_3B845, "syna_cdev_ioctl_raw_read", v4);
    v4 = v33;
    goto LABEL_39;
  }
  v15 = *(_QWORD *)(*(_QWORD *)a1 + 72LL);
  if ( !v15 )
  {
    v33 = -241;
    v34 = &unk_37DFA;
    goto LABEL_31;
  }
  v16 = *(__int64 (**)(void))(v15 + 32);
  if ( !v16 )
  {
    v33 = -245;
    v34 = &unk_3617E;
    goto LABEL_31;
  }
  v17 = qword_31658;
  if ( *((_DWORD *)v16 - 1) != 681844767 )
    __break(0x8228u);
  v18 = v16();
  if ( v18 < 0 )
  {
    v33 = v18;
    goto LABEL_33;
  }
  if ( (v4 & 0x80000000) != 0 )
  {
    __break(0x800u);
  }
  else
  {
    _check_object_size(v17, v4, 1);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v21 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v21 = a2 & ((__int64)(a2 << 8) >> 8);
    if ( 0x8000000000LL - (unsigned __int64)v4 >= v21 )
    {
      v22 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v28 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v28 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v28);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v22);
      v29 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL, v17, v4);
      v30 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v32 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v32 - 4096);
      _WriteStatusReg(TTBR1_EL1, v32);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v30);
      if ( !v29 )
        goto LABEL_39;
    }
  }
  printk(&unk_36141, "syna_cdev_ioctl_raw_read", v19);
  v4 = -52;
LABEL_39:
  if ( (unsigned __int8)qword_31698 == 1 )
  {
    v37 = 0;
  }
  else
  {
    printk(&unk_38244, "syna_tcm_buf_unlock", (unsigned __int8)qword_31698);
    v37 = qword_31698 - 1;
  }
  LOBYTE(qword_31698) = v37;
  mutex_unlock(&qword_31668);
  mutex_unlock(*(_QWORD *)a1 + 840LL);
  return v4;
}
