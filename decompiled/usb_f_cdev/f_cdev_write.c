__int64 __fastcall f_cdev_write(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, __int64 a4)
{
  __int64 v4; // x27
  unsigned __int64 v5; // x21
  __int64 v7; // x1
  _QWORD *v8; // x19
  __int64 v9; // x20
  _QWORD *v10; // x8
  __int64 v11; // x22
  __int64 v12; // x9
  __int64 v13; // x25
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v15; // x9
  size_t v16; // x26
  __int64 v17; // x3
  unsigned __int64 v18; // x9
  unsigned __int64 v24; // x8
  unsigned __int64 v25; // x8
  unsigned __int64 v27; // x9
  int v28; // w8
  unsigned int v29; // w0
  __int64 v30; // x3
  __int64 v31; // x1
  __int64 v32; // x0
  __int64 v34; // x3
  __int64 v35; // x9
  __int64 v36; // x24
  _QWORD *v37; // x2

  v4 = *(_QWORD *)(a1 + 32);
  if ( !v4 )
  {
    printk(&unk_90C6, "f_cdev_write", a3, a4);
    return -22;
  }
  v5 = a3;
  v7 = raw_spin_lock_irqsave(v4 + 1068);
  if ( (*(_BYTE *)(v4 + 1560) & 1) == 0 )
  {
    raw_spin_unlock_irqrestore(v4 + 1068, v7);
    printk(&unk_8FE6, "f_cdev_write", "f_cdev_write", v34);
    return -19;
  }
  v8 = *(_QWORD **)(v4 + 1152);
  v9 = v4 + 1152;
  if ( v8 != (_QWORD *)(v4 + 1152) )
  {
    v10 = (_QWORD *)v8[1];
    v11 = *(_QWORD *)(v4 + 1424);
    if ( (_QWORD *)*v10 == v8 && (v12 = *v8, *(_QWORD **)(*v8 + 8LL) == v8) )
    {
      *(_QWORD *)(v12 + 8) = v10;
      *v10 = v12;
    }
    else
    {
      _list_del_entry_valid_or_report(*(_QWORD *)(v4 + 1152));
      v7 = v35;
    }
    *v8 = v8;
    v8[1] = v8;
    raw_spin_unlock_irqrestore(v4 + 1068, v7);
    v13 = *(v8 - 8);
    if ( v5 >= 0x800 )
      v5 = 2048;
    _check_object_size(*(v8 - 8), v5, 0);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v15 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v15 = a2 & ((__int64)(a2 << 8) >> 8);
    v16 = v5;
    if ( 0x8000000000LL - v5 >= v15 )
    {
      v18 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v24 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v24 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v24);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v18);
      v16 = _arch_copy_from_user(v13, a2 & 0xFF7FFFFFFFFFFFFFLL, v5);
      v25 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v27 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v27 - 4096);
      _WriteStatusReg(TTBR1_EL1, v27);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v25);
      if ( !v16 )
        goto LABEL_17;
    }
    memset((void *)(v13 + v5 - v16), 0, v16);
    if ( (_DWORD)v16 )
    {
      printk(&unk_9145, "f_cdev_write", (unsigned int)v16, v17);
      v5 = -14;
    }
    else
    {
LABEL_17:
      v28 = *((_DWORD *)v8 - 6);
      *((_DWORD *)v8 - 14) = v5;
      *((_DWORD *)v8 - 6) = v28 | 0x40000;
      v29 = usb_ep_queue(v11, v8 - 8, 3264);
      if ( !v29 )
      {
        v31 = raw_spin_lock_irqsave(v4 + 1068);
        v32 = v4 + 1068;
        *(_QWORD *)(v4 + 1592) += *((unsigned int *)v8 - 14);
LABEL_19:
        raw_spin_unlock_irqrestore(v32, v31);
        return v5;
      }
      printk(&unk_8D62, "f_cdev_write", v29, v30);
      v5 = -5;
    }
    v36 = raw_spin_lock_irqsave(v4 + 1068);
    if ( *(_BYTE *)(v4 + 1560) == 1 )
    {
      v37 = *(_QWORD **)v9;
      if ( *(_QWORD *)(*(_QWORD *)v9 + 8LL) != v9 || v37 == v8 )
      {
        _list_add_valid_or_report(v8, v4 + 1152);
      }
      else
      {
        v37[1] = v8;
        *v8 = v37;
        v8[1] = v9;
        *(_QWORD *)v9 = v8;
      }
    }
    else if ( v8 != qword_40 )
    {
      kfree(*(v8 - 8));
      usb_ep_free_request(v11, v8 - 8);
    }
    v32 = v4 + 1068;
    v31 = v36;
    goto LABEL_19;
  }
  raw_spin_unlock_irqrestore(v4 + 1068, v7);
  return 0;
}
