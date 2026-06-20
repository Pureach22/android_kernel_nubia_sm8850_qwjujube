__int64 __fastcall spcom_ioctl_handle_copy_and_send_message(__int64 a1, size_t a2, char a3)
{
  __int64 v3; // x23
  size_t v4; // x28
  char *v8; // x19
  __int64 v9; // x2
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v11; // x9
  size_t v12; // x22
  size_t v13; // x1
  unsigned __int64 v14; // x9
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x8
  unsigned __int64 v23; // x9
  int v24; // w27
  size_t v25; // x0
  __int64 v26; // x2
  __int64 v27; // x23
  __int64 v28; // x22
  unsigned int v29; // w24
  _DWORD *v30; // x26
  __int64 v31; // x2
  __int64 v32; // x10
  int v33; // w8
  int v34; // w8
  unsigned __int64 v35; // x1
  int v36; // w28
  int v37; // w0
  int v38; // w25
  _BYTE *v39; // x8
  __int64 v40; // x2
  unsigned __int64 v41; // x22
  _BYTE *v43; // [xsp+8h] [xbp-8h]

  v4 = *(unsigned int *)(a1 + 36);
  v8 = (char *)_kmalloc_noprof(v4, 3520);
  if ( !v8 )
  {
LABEL_84:
    LODWORD(a2) = -12;
    return (unsigned int)a2;
  }
  while ( 1 )
  {
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: copying message buffer from user space, size[%u]\n",
      "spcom_ioctl_handle_copy_and_send_message",
      (const char *)&unk_F80E,
      v4);
    if ( (v4 & 0x80000000) != 0 )
    {
      __break(0x800u);
      v12 = v4;
      if ( (_DWORD)v4 )
      {
LABEL_12:
        printk(&unk_F2CB, "spcom_ioctl_handle_copy_and_send_message", (unsigned int)v12);
        ipc_log_string(
          spcom_ipc_log_context,
          "%sspcom:%s: failed to copy from user, ret [%d]\n",
          "spcom_ioctl_handle_copy_and_send_message",
          (const char *)&unk_F80E,
          v12);
        LODWORD(a2) = -14;
        goto LABEL_86;
      }
    }
    else
    {
      _check_object_size(v8, v4, 0);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v11 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v11 = a2 & ((__int64)(a2 << 8) >> 8);
      v12 = v4;
      if ( 0x8000000000LL - v4 < v11 )
        goto LABEL_7;
      v14 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v20 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v20 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v20);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v14);
      v12 = _arch_copy_from_user(v8, a2 & 0xFF7FFFFFFFFFFFFFLL, v4);
      v21 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v23 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v23 - 4096);
      _WriteStatusReg(TTBR1_EL1, v23);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v21);
      if ( v12 )
      {
LABEL_7:
        if ( v4 >= v4 - v12 )
          v13 = v12;
        else
          v13 = 0;
        if ( v13 < v12 )
          goto LABEL_80;
        memset(&v8[v4 - v12], 0, v12);
        if ( (_DWORD)v12 )
          goto LABEL_12;
      }
    }
    if ( !a1 || !*(_BYTE *)a1 )
    {
LABEL_36:
      printk(&unk_1128C, "spcom_send_message", v9);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: invalid channel name\n",
        "spcom_send_message",
        (const char *)&unk_F80E);
      LODWORD(a2) = -22;
      goto LABEL_86;
    }
    v24 = *(_DWORD *)(a1 + 32);
    a2 = *(unsigned int *)(a1 + 36);
    v25 = strnlen((const char *)a1, 0x20u);
    if ( v25 == -1 )
      goto LABEL_79;
    if ( v25 >= 0x20 )
      goto LABEL_36;
    if ( (unsigned int)a2 >= 0x10D )
    {
      printk(&unk_12B24, "spcom_send_message", a1);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: ch [%s] message size is too big [%d]\n",
        "spcom_send_message",
        (const char *)&unk_F80E,
        (const char *)a1,
        a2);
      LODWORD(a2) = -22;
      goto LABEL_86;
    }
    v25 = strnlen((const char *)a1, 0x20u);
    if ( v25 == -1 )
    {
LABEL_79:
      _fortify_panic(2, -1, v25 + 1);
LABEL_80:
      _fortify_panic(15, v13, v12);
LABEL_81:
      __break(1u);
      _fortify_panic(15, v3, v31);
LABEL_82:
      _fortify_panic(17, v35, a2);
      goto LABEL_83;
    }
    if ( v25 <= 0x1F && !strcmp((const char *)a1, "spcom") )
    {
      printk(&unk_F905, "spcom_send_message", v26);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: cannot send message on control channel\n",
        "spcom_send_message",
        (const char *)&unk_F80E);
      LODWORD(a2) = -14;
      goto LABEL_86;
    }
    v27 = 32;
    v28 = spcom_dev + 1200;
    while ( strcmp((const char *)v28, (const char *)a1) )
    {
      --v27;
      v28 += 1784;
      if ( !v27 )
        goto LABEL_35;
    }
    if ( !v28 )
    {
LABEL_35:
      LODWORD(a2) = -19;
      goto LABEL_86;
    }
    if ( !*(_QWORD *)(v28 + 152) || !*(_QWORD *)(v28 + 160) )
    {
      printk(&unk_108D0, "spcom_send_message", a1);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: ch [%s] remote side not connected\n",
        "spcom_send_message",
        (const char *)&unk_F80E,
        (const char *)a1);
      LODWORD(a2) = -107;
      goto LABEL_86;
    }
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: sending message with size [%d], ch [%s]\n",
      "spcom_send_message",
      (const char *)&unk_F80E,
      a2,
      (const char *)a1);
    v29 = a2 + 8;
    v3 = (unsigned int)(a2 + 8);
    v30 = (_DWORD *)_kmalloc_noprof(v3, 3520);
    if ( !v30 )
    {
      LODWORD(a2) = -12;
      goto LABEL_86;
    }
    if ( *(_BYTE *)(v28 + 233) == 1 )
      mutex_lock(v28 + 248);
    mutex_lock(v28 + 32);
    if ( (*(_BYTE *)(v28 + 85) & 1) != 0 )
    {
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: client ch [%s] sending it's first message\n",
        "spcom_send_message",
        (const char *)&unk_F80E,
        (const char *)a1);
      *(_WORD *)(v28 + 84) = 0;
      v32 = v28 + 84;
      if ( (*(_BYTE *)(v28 + 233) & 1) == 0 )
        goto LABEL_43;
      goto LABEL_39;
    }
    v32 = v28 + 84;
    if ( (*(_BYTE *)(v28 + 233) & 1) != 0 )
    {
      if ( (*(_BYTE *)(v28 + 84) & 1) != 0 )
      {
        mutex_unlock(v28 + 248);
        printk(&unk_F2FB, "spcom_send_message", v40);
        ipc_log_string(
          spcom_ipc_log_context,
          "%sspcom:%s: server spcom channel cannot be shared\n",
          "spcom_send_message",
          (const char *)&unk_F80E);
        v39 = (_BYTE *)(v28 + 84);
        LODWORD(a2) = 0;
        goto LABEL_69;
      }
LABEL_39:
      *(_DWORD *)(v28 + 240) = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1804);
      goto LABEL_43;
    }
    if ( (*(_BYTE *)(v28 + 84) & 1) != 0 )
    {
      v33 = *(_DWORD *)(v28 + 80);
      goto LABEL_44;
    }
LABEL_43:
    v34 = *(_DWORD *)(v28 + 80);
    *(_DWORD *)(v28 + 88) = v24;
    v33 = v34 + 1;
    *(_DWORD *)(v28 + 80) = v33;
LABEL_44:
    if ( (v3 & 0x7FFFFFFC) == 4 )
      goto LABEL_81;
    v35 = v29 - 8LL;
    v30[1] = v33;
    if ( v35 < a2 )
      goto LABEL_82;
    v43 = (_BYTE *)v32;
    if ( v4 >= a2 )
      break;
LABEL_83:
    _fortify_panic(16, v35, a2);
    v41 = _ReadStatusReg(SP_EL0);
    v3 = *(_QWORD *)(v41 + 80);
    *(_QWORD *)(v41 + 80) = &spcom_ioctl_handle_copy_and_send_message__alloc_tag;
    v8 = (char *)_kmalloc_noprof(v4, 3520);
    *(_QWORD *)(v41 + 80) = v3;
    if ( !v8 )
      goto LABEL_84;
  }
  memcpy(v30 + 2, v8, a2);
  if ( (a3 & 1) != 0
    && ((*(_DWORD *)(a1 + 40) & 0x80000000) == 0
     && (unsigned int)modify_dma_buf_addr(
                        (const char *)v28,
                        (__int64)(v30 + 2),
                        (unsigned int)a2,
                        (unsigned int *)(a1 + 40))
     || (*(_DWORD *)(a1 + 48) & 0x80000000) == 0
     && (unsigned int)modify_dma_buf_addr(
                        (const char *)v28,
                        (__int64)(v30 + 2),
                        (unsigned int)a2,
                        (unsigned int *)(a1 + 48))
     || (*(_DWORD *)(a1 + 56) & 0x80000000) == 0
     && (unsigned int)modify_dma_buf_addr(
                        (const char *)v28,
                        (__int64)(v30 + 2),
                        (unsigned int)a2,
                        (unsigned int *)(a1 + 56))
     || (*(_DWORD *)(a1 + 64) & 0x80000000) == 0
     && (unsigned int)modify_dma_buf_addr(
                        (const char *)v28,
                        (__int64)(v30 + 2),
                        (unsigned int)a2,
                        (unsigned int *)(a1 + 64))) )
  {
    if ( *(_BYTE *)(v28 + 233) == 1 && *(_DWORD *)(v28 + 240) == *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1804) )
    {
      *(_DWORD *)(v28 + 240) = 0;
      mutex_unlock(v28 + 248);
    }
    LODWORD(a2) = -14;
  }
  else
  {
    v36 = 0;
    while ( *(_BYTE *)(v28 + 316) != 1 )
    {
      v37 = rpmsg_trysend(*(_QWORD *)(*(_QWORD *)(v28 + 160) + 968LL), v30, v29);
      if ( !v37 )
      {
        ipc_log_string(
          spcom_ipc_log_context,
          "%sspcom:%s: ch[%s]: successfully sent txn_id=%d\n",
          "spcom_send_message",
          (const char *)&unk_F80E,
          (const char *)a1,
          *(_DWORD *)(v28 + 80));
        goto LABEL_68;
      }
      v38 = v37;
      mutex_unlock(v28 + 32);
      msleep(100);
      mutex_lock(v28 + 32);
      if ( v38 == -11 || v38 == -16 )
      {
        v36 += 100;
        if ( v36 < v24 )
          continue;
      }
      goto LABEL_75;
    }
    printk(&unk_114B0, "spcom_send_message", a1);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: ch [%s] aborted\n",
      "spcom_send_message",
      (const char *)&unk_F80E,
      (const char *)a1);
    v38 = -125;
LABEL_75:
    printk(&unk_12303, "spcom_send_message", a1);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: Tx failed: ch [%s], err [%d], timeout [%d]ms\n",
      "spcom_send_message",
      (const char *)&unk_F80E,
      (const char *)a1,
      v38,
      v24);
  }
LABEL_68:
  v39 = v43;
LABEL_69:
  if ( *v39 == 1 )
  {
    _pm_relax(*(_QWORD *)(spcom_dev + 1192));
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: ch[%s]:pm_relax() called for server, after tx\n",
      "spcom_send_message",
      (const char *)&unk_F80E,
      (const char *)v28);
  }
  mutex_unlock(v28 + 32);
  memset(v30, 0, v29);
  kfree(v30);
LABEL_86:
  kfree(v8);
  return (unsigned int)a2;
}
