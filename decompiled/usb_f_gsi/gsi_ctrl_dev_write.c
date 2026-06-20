__int64 __fastcall gsi_ctrl_dev_write(__int64 a1, unsigned __int64 a2, size_t a3)
{
  size_t v3; // x19
  char *v4; // x20
  __int64 v5; // x8
  __int64 v6; // x21
  char v8; // w22
  _QWORD *v10; // x0
  __int64 v11; // x22
  _QWORD *v12; // x21
  unsigned __int64 StatusReg; // x9
  unsigned __int64 v14; // x8
  unsigned __int64 v15; // x10
  size_t v16; // x23
  unsigned __int64 v17; // x10
  unsigned __int64 v23; // x9
  unsigned __int64 v24; // x8
  unsigned __int64 v26; // x9
  __int64 v27; // x6
  __int64 v28; // x0
  char *v29; // x2
  __int64 *v30; // x1
  __int64 v31; // x9
  __int64 v32; // x1
  __int64 v33; // x1

  v5 = **(unsigned int **)(a1 + 32);
  if ( (unsigned int)v5 >= 7 )
  {
    __break(0x5512u);
    goto LABEL_54;
  }
  if ( (_DWORD)v5 == 4 )
    return -22;
  v6 = v5 << 6;
  v3 = a3;
  v4 = (char *)&inst_status + 64 * v5;
  mutex_lock(v4);
  v5 = v6 | 0x30;
  if ( (v6 | 0x30uLL) > 0x180 )
    goto LABEL_54;
  v8 = v4[48];
  mutex_unlock((char *)&inst_status + v6);
  if ( (v8 & 1) == 0 )
  {
    if ( (unsigned int)__ratelimit(&gsi_ctrl_dev_write__rs, "gsi_ctrl_dev_write") )
      printk(&unk_1045C, "gsi_ctrl_dev_write");
    return -19;
  }
  v5 = v6 | 0x38;
  if ( (v6 | 0x38uLL) > 0x180 )
  {
LABEL_54:
    __break(1u);
    goto LABEL_55;
  }
  v4 = *(char **)(*((_QWORD *)v4 + 7) + 176LL);
  if ( v3 - 8193 <= 0xFFFFFFFFFFFFDFFFLL )
  {
    if ( v4 )
    {
      ipc_log_string(*((_QWORD *)v4 + 168), "error: ctrl pkt length %zu", v3);
      printk(&unk_11E89, v3);
      return -22;
    }
    return -22;
  }
  if ( *((_DWORD *)v4 + 68) )
  {
    if ( v4[284] != 1 || (v4[285] & 1) != 0 )
    {
      v10 = (_QWORD *)gsi_ctrl_pkt_alloc((unsigned int)v3, 3264);
      if ( (unsigned __int64)v10 >= 0xFFFFFFFFFFFFF001LL )
      {
        if ( v4 )
        {
          ipc_log_string(*((_QWORD *)v4 + 168), "failed to allocate ctrl pkt");
          printk(&unk_108AE, v33);
        }
        return -12;
      }
      v11 = *v10;
      v12 = v10;
      _check_object_size(*v10, v3, 0);
      StatusReg = _ReadStatusReg(SP_EL0);
      v14 = a2;
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v15 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v15 = a2 & ((__int64)(a2 << 8) >> 8);
      v16 = v3;
      if ( 0x8000000000LL - v3 < v15 )
        goto LABEL_58;
      v17 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v23 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v23 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v23);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v17);
      v16 = _arch_copy_from_user(v11, v14 & 0xFF7FFFFFFFFFFFFFLL, v3);
      v24 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v26 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v26 - 4096);
      _WriteStatusReg(TTBR1_EL1, v26);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v24);
      if ( v16 )
      {
LABEL_58:
        memset((void *)(v11 + v3 - v16), 0, v16);
        if ( (_DWORD)v16 )
        {
          if ( v4 )
          {
            ipc_log_string(*((_QWORD *)v4 + 168), "copy_from_user failed err:%d", v16);
            printk(&unk_10487, (unsigned int)v16);
            if ( !v12 )
              return (int)v16;
          }
          else if ( !v12 )
          {
            return (int)v16;
          }
          kfree(*v12);
          kfree(v12);
          return (int)v16;
        }
      }
      *((_DWORD *)v12 + 3) = 4;
      _ZF = byte_FD50 == 1;
      ++*((_DWORD *)v4 + 331);
      if ( _ZF )
      {
        if ( (unsigned int)v3 >= 0x1E )
          v27 = 30;
        else
          v27 = (unsigned int)v3;
        print_hex_dump(&unk_11B5D, "WRITE:", 2, 16, 1, *v12, v27, 0);
      }
      v28 = raw_spin_lock_irqsave(v4 + 1304);
      v5 = (__int64)(v12 + 2);
      v29 = v4 + 1280;
      v30 = *((__int64 **)v4 + 161);
      v31 = v28;
      if ( v12 + 2 != (_QWORD *)(v4 + 1280) && v30 != (__int64 *)v5 && (char *)*v30 == v29 )
      {
        *((_QWORD *)v4 + 161) = v5;
        v12[2] = v29;
        v12[3] = v30;
        *v30 = v5;
LABEL_43:
        raw_spin_unlock_irqrestore(v4 + 1304, v31);
        if ( !(unsigned int)gsi_ctrl_send_notification(v4) )
          ++*((_DWORD *)v4 + 332);
        if ( v4 )
          ipc_log_string(*((_QWORD *)v4 + 168), "Exit %zu", v3);
        return v3;
      }
LABEL_55:
      _list_add_valid_or_report(v5);
      goto LABEL_43;
    }
    ++*((_DWORD *)v4 + 333);
    if ( v4 )
    {
      ipc_log_string(*((_QWORD *)v4 + 168), "drop ctrl pkt of len %zu", v3);
      printk(&unk_10298, v3);
    }
    return -95;
  }
  else
  {
    if ( v4 )
    {
      ipc_log_string(*((_QWORD *)v4 + 168), "USB cable not connected\n");
      printk(&unk_11883, v32);
    }
    return -104;
  }
}
