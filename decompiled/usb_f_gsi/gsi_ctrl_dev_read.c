__int64 __fastcall gsi_ctrl_dev_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  __int64 v3; // x23
  __int64 v4; // x22
  char *v7; // x21
  char v8; // w23
  __int64 v9; // x25
  __int64 result; // x0
  __int64 v11; // x0
  _QWORD *v12; // x22
  _QWORD *v13; // x26
  __int64 v14; // x24
  _QWORD *v15; // x8
  _QWORD *v16; // x21
  __int64 v17; // x9
  unsigned __int64 v18; // x3
  int v19; // w8
  __int64 v20; // x23
  __int64 v21; // x24
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v23; // x9
  unsigned __int64 v24; // x9
  unsigned __int64 v30; // x8
  unsigned __int64 v31; // x8
  unsigned __int64 v33; // x9
  __int64 v34; // x20
  __int64 v35; // x20
  __int64 v36; // x0
  __int64 v37; // x0
  int v38; // w3
  __int64 v39; // x1
  _QWORD v40[6]; // [xsp+0h] [xbp-30h] BYREF

  v40[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = **(unsigned int **)(a1 + 32);
  if ( (unsigned int)v3 >= 7 )
LABEL_69:
    __break(0x5512u);
  v4 = v3 << 6;
  v7 = (char *)&inst_status + 64 * v3;
  mutex_lock(v7);
  if ( (((unsigned __int64)(unsigned int)v3 << 6) | 0x30) > 0x180 )
    goto LABEL_68;
  v8 = v7[48];
  mutex_unlock(v7);
  if ( (v8 & 1) == 0 )
  {
    if ( (unsigned int)__ratelimit(&gsi_ctrl_dev_read__rs, "gsi_ctrl_dev_read") )
    {
      printk(&unk_1045C, "gsi_ctrl_dev_read");
      result = -19;
      goto LABEL_65;
    }
    goto LABEL_64;
  }
  if ( (v4 | 0x38uLL) > 0x180 )
  {
LABEL_68:
    __break(1u);
    goto LABEL_69;
  }
  v9 = *(_QWORD *)(*((_QWORD *)v7 + 7) + 176LL);
  if ( v9 == -1056 )
  {
LABEL_64:
    result = -19;
    goto LABEL_65;
  }
  if ( a3 > 0x2000 )
  {
    if ( v9 )
    {
      ipc_log_string(*(_QWORD *)(v9 + 1344), "Large buff size %zu, should be %d", a3, 0x2000);
      printk(&unk_11FFE, a3);
    }
    result = -22;
    goto LABEL_65;
  }
  v11 = raw_spin_lock_irqsave(v9 + 1304);
  v12 = *(_QWORD **)(v9 + 1264);
  v13 = (_QWORD *)(v9 + 1264);
  v14 = v11;
  if ( v12 != (_QWORD *)(v9 + 1264) )
  {
LABEL_11:
    v15 = (_QWORD *)v12[1];
    v16 = v12 - 2;
    if ( (_QWORD *)*v15 == v12 && (v17 = *v12, *(_QWORD **)(*v12 + 8LL) == v12) )
    {
      *(_QWORD *)(v17 + 8) = v15;
      *v15 = v17;
    }
    else
    {
      _list_del_entry_valid_or_report(v12);
    }
    *v12 = 0xDEAD000000000100LL;
    v12[1] = 0xDEAD000000000122LL;
    raw_spin_unlock_irqrestore(v9 + 1304, v14);
    v18 = *((int *)v12 - 2);
    if ( v18 > a3 )
    {
      if ( v9 )
      {
        ipc_log_string(*(_QWORD *)(v9 + 1344), "cpkt size large:%d > buf size:%zu", v18, a3);
        printk(&unk_12022, *((unsigned int *)v12 - 2));
        if ( v12 == &qword_10 )
          goto LABEL_18;
      }
      else if ( v12 == &qword_10 )
      {
LABEL_18:
        result = -12;
        goto LABEL_65;
      }
      kfree(*v16);
      kfree(v12 - 2);
      goto LABEL_18;
    }
    if ( v9 )
    {
      ipc_log_string(*(_QWORD *)(v9 + 1344), "%s: cpkt size:%d", "gsi_ctrl_dev_read", v18);
      LODWORD(v18) = *((_DWORD *)v12 - 2);
    }
    if ( byte_FD50 == 1 )
    {
      if ( (int)v18 >= 30 )
        v19 = 30;
      else
        v19 = v18;
      print_hex_dump(&unk_11B5D, "READ:", 2, 16, 1, *(v12 - 2), v19, 0);
      LODWORD(v18) = *((_DWORD *)v12 - 2);
    }
    v20 = (int)v18;
    if ( (v18 & 0x80000000) != 0 )
    {
      __break(0x800u);
    }
    else
    {
      v21 = *v16;
      _check_object_size(*v16, (int)v18, 1);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v23 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v23 = a2 & ((__int64)(a2 << 8) >> 8);
      if ( 0x8000000000LL - v20 >= v23 )
      {
        v24 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v30 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v30 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v30);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v24);
        LODWORD(v20) = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL, v21, v20);
        v31 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v33 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v33 - 4096);
        _WriteStatusReg(TTBR1_EL1, v33);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v31);
      }
    }
    if ( (_DWORD)v20 )
    {
      if ( v9 )
      {
        ipc_log_string(*(_QWORD *)(v9 + 1344), "copy_to_user failed: err %d", v20);
        printk(&unk_10B70, (unsigned int)v20);
        result = -14;
        if ( v12 == &qword_10 )
        {
LABEL_36:
          if ( v9 )
          {
            v35 = result;
            ipc_log_string(*(_QWORD *)(v9 + 1344), "%s: Exit %zu", "gsi_ctrl_dev_read", a3);
            result = v35;
          }
          goto LABEL_65;
        }
      }
      else
      {
        result = -14;
        if ( v12 == &qword_10 )
          goto LABEL_36;
      }
    }
    else
    {
      v38 = *((_DWORD *)v12 - 2);
      if ( v9 )
      {
        ipc_log_string(*(_QWORD *)(v9 + 1344), "%s: copied %d bytes to user", "gsi_ctrl_dev_read", v38);
        v38 = *((_DWORD *)v12 - 2);
      }
      result = v38;
      ++*(_DWORD *)(v9 + 1320);
      if ( v12 == &qword_10 )
        goto LABEL_36;
    }
    v34 = result;
    kfree(*v16);
    kfree(v12 - 2);
    result = v34;
    goto LABEL_36;
  }
  while ( 1 )
  {
    if ( v9 )
      ipc_log_string(*(_QWORD *)(v9 + 1344), "Requests list is empty. Wait.");
    raw_spin_unlock_irqrestore(v9 + 1304, v14);
    if ( (_QWORD *)*v13 == v13 )
    {
      memset(v40, 0, 40);
      init_wait_entry(v40, 0);
      while ( 1 )
      {
        v37 = prepare_to_wait_event(v9 + 1240, v40, 1);
        if ( (_QWORD *)*v13 != v13 )
        {
          finish_wait(v9 + 1240, v40);
          goto LABEL_48;
        }
        if ( v37 )
          break;
        schedule();
      }
      if ( (v37 & 0x80000000) != 0 )
        break;
    }
LABEL_48:
    if ( v9 )
      ipc_log_string(*(_QWORD *)(v9 + 1344), "Received request packet");
    v36 = raw_spin_lock_irqsave(v9 + 1304);
    v12 = (_QWORD *)*v13;
    v14 = v36;
    if ( (_QWORD *)*v13 != v13 )
      goto LABEL_11;
  }
  if ( v9 )
  {
    ipc_log_string(*(_QWORD *)(v9 + 1344), "Waiting failed");
    printk(&unk_12319, v39);
  }
  result = -512;
LABEL_65:
  _ReadStatusReg(SP_EL0);
  return result;
}
