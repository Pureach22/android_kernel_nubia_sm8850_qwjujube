__int64 __fastcall syna_cdev_ioctl_raw_write(__int64 a1, unsigned __int64 a2, __int64 a3, unsigned int a4)
{
  unsigned int v4; // w19
  size_t v7; // x22
  void *v8; // x0
  __int64 v9; // x22
  __int64 v10; // x0
  __int64 v11; // x2
  __int64 v12; // x0
  __int64 v13; // x2
  __int64 v14; // x22
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v16; // x9
  size_t v17; // x24
  __int64 v18; // x2
  unsigned __int64 v19; // x9
  unsigned __int64 v25; // x8
  unsigned __int64 v26; // x8
  unsigned __int64 v28; // x9
  __int64 v29; // x0
  __int64 (*v30)(void); // x8
  int v31; // w0
  int v32; // w21
  void *v33; // x0
  void *v34; // x0
  __int64 v35; // x0
  char v36; // w8

  v4 = a4;
  if ( a4 > (unsigned int)a3 )
  {
    printk(unk_38935, "syna_cdev_ioctl_raw_write", a3);
    return (unsigned int)-22;
  }
  if ( !a4 )
  {
    printk(unk_3CBAE, "syna_cdev_ioctl_raw_write", a3);
    return (unsigned int)-22;
  }
  mutex_lock(*(_QWORD *)a1 + 840LL);
  if ( (_BYTE)qword_31698 )
    printk(unk_38244, "syna_tcm_buf_lock", (unsigned __int8)qword_31698);
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
        v35 = printk(unk_3BE43, "syna_pal_mem_free", v11);
        v12 = syna_request_managed_device(v35);
        if ( v12 )
          goto LABEL_10;
        goto LABEL_37;
      }
      devm_kfree(v10, v9);
      v8 = NULL;
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
LABEL_39:
        printk(unk_3703C, "syna_tcm_buf_alloc", v4);
        qword_31660 = 0;
        printk(unk_376CF, "syna_cdev_ioctl_raw_write", v4);
        v4 = -243;
        goto LABEL_40;
      }
      v34 = unk_38286;
LABEL_38:
      printk(v34, "syna_pal_mem_alloc", v13);
      qword_31658 = 0;
      goto LABEL_39;
    }
LABEL_37:
    v34 = unk_3BE43;
    goto LABEL_38;
  }
LABEL_13:
  memset(v8, 0, v7);
  HIDWORD(qword_31660) = 0;
  if ( (v4 & 0x80000000) == 0 )
  {
    v14 = qword_31658;
    v17 = copy_from_user((void *)v14, (const void __user *)a2, v4);
    if ( v17 )
    {
LABEL_48:
      memset((void *)(v14 + v4 - v17), 0, v17);
      if ( (_DWORD)v17 )
        goto LABEL_19;
    }
    if ( *(_QWORD *)a1 )
    {
      v29 = *(_QWORD *)(*(_QWORD *)a1 + 72LL);
      if ( v29 )
      {
        v30 = *(__int64 (**)(void))(v29 + 40);
        if ( v30 )
        {
          /* CFI check removed */
          v31 = v30();
          if ( (v31 & 0x80000000) == 0 )
            goto LABEL_40;
          v32 = v31;
          goto LABEL_34;
        }
        v32 = -245;
        v33 = unk_37E2D;
      }
      else
      {
        v32 = -241;
        v33 = unk_37DFA;
      }
    }
    else
    {
      v32 = -241;
      v33 = unk_3365A;
    }
    printk(v33, "syna_tcm_write", v18);
LABEL_34:
    printk(unk_3706F, "syna_cdev_ioctl_raw_write", v4);
    v4 = v32;
    goto LABEL_40;
  }
  __break(0x800u);
  LODWORD(v17) = v4;
LABEL_19:
  printk(unk_3489E, "syna_cdev_ioctl_raw_write", (unsigned int)v17);
  v4 = -52;
LABEL_40:
  if ( (unsigned __int8)qword_31698 == 1 )
  {
    v36 = 0;
  }
  else
  {
    printk(unk_38244, "syna_tcm_buf_unlock", (unsigned __int8)qword_31698);
    v36 = qword_31698 - 1;
  }
  LOBYTE(qword_31698) = v36;
  mutex_unlock(&qword_31668);
  mutex_unlock(*(_QWORD *)a1 + 840LL);
  return v4;
}
