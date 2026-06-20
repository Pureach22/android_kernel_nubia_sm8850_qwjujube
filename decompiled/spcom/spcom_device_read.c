__int64 __fastcall spcom_device_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, __int64 a4)
{
  const char *v8; // x20
  __int64 v9; // x8
  unsigned __int64 v10; // x25
  unsigned __int64 StatusReg; // x27
  unsigned int v12; // w26
  __int64 v13; // x2
  __int64 v14; // x2
  __int64 v15; // x19
  _DWORD *v16; // x20
  size_t v17; // x23
  __int64 v18; // x0
  __int64 v19; // x24
  int v20; // w5
  __int64 v21; // x0
  __int64 v22; // x24
  void *v23; // x0
  __int64 v24; // x0
  __int64 v25; // x23
  unsigned __int64 v26; // x8
  unsigned int v27; // w0
  unsigned __int64 v28; // x8
  unsigned __int64 v34; // x9
  unsigned __int64 v35; // x8
  unsigned __int64 v37; // x9
  unsigned int v38; // w22
  const char *v40; // [xsp+0h] [xbp-10h]
  unsigned int v41; // [xsp+Ch] [xbp-4h]

  v8 = "unknown";
  if ( a1 )
  {
    v9 = *(_QWORD *)(a1 + 72);
    if ( v9 )
      v8 = (const char *)(v9 + 56);
  }
  v10 = (unsigned __int64)"el name\n";
  StatusReg = _ReadStatusReg(SP_EL0);
  v12 = *(_DWORD *)(StatusReg + 1804);
  ipc_log_string(
    spcom_ipc_log_context,
    "%sspcom:%s: read file [%s], size = %d bytes\n",
    "spcom_device_read",
    (const char *)&unk_F80E,
    v8,
    a3);
  if ( *(_DWORD *)(spcom_dev + 58428) )
  {
    printk(&unk_1146C, "spcom_device_read", v13);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: module remove in progress\n",
      "spcom_device_read",
      (const char *)&unk_F80E);
    return -19;
  }
  if ( !strcmp(v8, "unknown") )
  {
    printk(&unk_118C7, "spcom_device_read", v14);
    ipc_log_string(spcom_ipc_log_context, "%sspcom:%s: name is unknown\n", "spcom_device_read", &unk_F80E);
    return -22;
  }
  if ( a3 - 4097 < 0xFFFFFFFFFFFFF000LL || !a2 || !a4 )
  {
    printk(&unk_FF3B, "spcom_device_read", v14);
    ipc_log_string(spcom_ipc_log_context, "%sspcom:%s: invalid parameters\n", "spcom_device_read", &unk_F80E);
    return -22;
  }
  v15 = *(_QWORD *)(a1 + 32);
  if ( !v15 )
  {
    printk(&unk_10E4D, "spcom_device_read", v8);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: invalid ch pointer, file [%s]\n",
      "spcom_device_read",
      &unk_F80E,
      v8);
    return -22;
  }
  if ( !*(_QWORD *)(v15 + 152) )
  {
    printk(&unk_10E78, "spcom_device_read", v8);
    ipc_log_string(spcom_ipc_log_context, "%sspcom:%s: ch is not open, file [%s]\n", "spcom_device_read", &unk_F80E, v8);
    return -22;
  }
  v16 = (_DWORD *)_kmalloc_noprof(a3, 3520);
  if ( !v16 )
  {
LABEL_46:
    v22 = -12;
    goto LABEL_65;
  }
  while ( 1 )
  {
    if ( (_DWORD)a3 == 4095 )
    {
      *(_BYTE *)(v15 + 84) = 1;
      LODWORD(v17) = spcom_get_next_request_size(v15);
      if ( (v17 & 0x80000000) == 0 )
      {
        v18 = *(_QWORD *)(v10 + 4032);
        *v16 = v17;
        ipc_log_string(
          v18,
          "%sspcom:%s: next_req_size [%d]\n",
          "spcom_handle_get_req_size",
          (const char *)&unk_F80E,
          v17);
        LODWORD(v17) = 4;
      }
      goto LABEL_49;
    }
    if ( !*(_QWORD *)(v15 + 152) || !*(_QWORD *)(v15 + 160) )
    {
      printk(&unk_10AFC, "spcom_handle_read_req_resp", v15);
      ipc_log_string(
        *(_QWORD *)(v10 + 4032),
        "%sspcom:%s: ch [%s] remote side not connect\n",
        "spcom_handle_read_req_resp",
        (const char *)&unk_F80E,
        (const char *)v15);
      LODWORD(v17) = -107;
      goto LABEL_49;
    }
    if ( (unsigned int)a3 >= 0x10D )
    {
      printk(&unk_118E4, "spcom_handle_read_req_resp", v15);
      ipc_log_string(
        *(_QWORD *)(v10 + 4032),
        "%sspcom:%s: ch [%s] invalid size [%d]\n",
        "spcom_handle_read_req_resp",
        (const char *)&unk_F80E,
        (const char *)v15,
        a3);
      LODWORD(v17) = -22;
      goto LABEL_49;
    }
    v10 = (unsigned int)(a3 + 8);
    v19 = _kmalloc_noprof(v10, 3520);
    if ( !v19 )
      break;
    v41 = v12;
    if ( (*(_BYTE *)(v15 + 84) & 1) != 0 )
    {
      v17 = 0;
    }
    else
    {
      v17 = *(unsigned int *)(v15 + 88);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: response_timeout_msec:%d\n",
        "spcom_handle_read_req_resp",
        (const char *)&unk_F80E,
        *(_DWORD *)(v15 + 88));
    }
    v12 = spcom_rx(v15, v19, (unsigned int)v10, (unsigned int)v17);
    if ( (v12 & 0x80000000) != 0 )
    {
      v23 = &unk_1190B;
      LODWORD(v17) = v12;
      v40 = "%sspcom:%s: rx error %d\n";
LABEL_41:
      printk(v23, "spcom_handle_read_req_resp", v12);
      v10 = (unsigned __int64)"el name\n";
      ipc_log_string(spcom_ipc_log_context, v40, "spcom_handle_read_req_resp", &unk_F80E, v12);
      kfree(v19);
      v12 = v41;
      goto LABEL_49;
    }
    if ( *(_BYTE *)(v15 + 84) == 1 )
    {
      if ( (v10 & 0x7FFFFFFC) == 4 )
      {
        __break(1u);
LABEL_43:
        v24 = 17;
        goto LABEL_45;
      }
      v20 = *(_DWORD *)(v19 + 4);
      v21 = spcom_ipc_log_context;
      *(_DWORD *)(v15 + 80) = v20;
      ipc_log_string(
        v21,
        "%sspcom:%s: ch[%s]:request txn_id [0x%x]\n",
        "spcom_handle_read_req_resp",
        (const char *)&unk_F80E,
        (const char *)v15,
        v20);
    }
    if ( v12 < 9 )
    {
      LODWORD(v17) = -14;
      v40 = "%sspcom:%s: rx size [%d] too small\n";
      v23 = &unk_10885;
      goto LABEL_41;
    }
    v17 = v12 - 8;
    if ( v17 > a3 )
      goto LABEL_43;
    v12 = v41;
    if ( v10 - 8 >= v17 )
    {
      memcpy(v16, (const void *)(v19 + 8), v17);
      kfree(v19);
      goto LABEL_48;
    }
    v24 = 16;
LABEL_45:
    _fortify_panic(v24, a3, v17);
    v25 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &spcom_device_read__alloc_tag;
    v16 = (_DWORD *)_kmalloc_noprof(a3, 3520);
    *(_QWORD *)(StatusReg + 80) = v25;
    if ( !v16 )
      goto LABEL_46;
  }
  LODWORD(v17) = -12;
LABEL_48:
  v10 = (unsigned __int64)"el name\n";
LABEL_49:
  mutex_lock(v15 + 32);
  if ( (*(_BYTE *)(v15 + 84) & 1) == 0 )
  {
    _pm_relax(*(_QWORD *)(spcom_dev + 1192));
    ipc_log_string(
      *(_QWORD *)(v10 + 4032),
      "%sspcom:%s: ch[%s]:pm_relax() called for client\n",
      "spcom_handle_read",
      (const char *)&unk_F80E,
      (const char *)v15);
  }
  mutex_unlock(v15 + 32);
  if ( (v17 & 0x80000000) != 0 )
  {
    if ( (_DWORD)v17 == -512 )
    {
      v22 = -512;
    }
    else
    {
      printk(&unk_11736, "spcom_device_read", (unsigned int)v17);
      ipc_log_string(
        *(_QWORD *)(v10 + 4032),
        "%sspcom:%s: read error [%d]\n",
        "spcom_device_read",
        (const char *)&unk_F80E,
        v17);
      v22 = (int)v17;
    }
  }
  else if ( (_DWORD)v17 && (v22 = (unsigned int)v17, (unsigned int)v17 <= a3) )
  {
    _check_object_size(v16, (unsigned int)v17, 1);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v26 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v26 = a2 & ((__int64)(a2 << 8) >> 8);
    v27 = v17;
    if ( 0x8000000000LL - (unsigned __int64)(unsigned int)v17 >= v26 )
    {
      v28 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v34 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v34 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v34);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v28);
      v27 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL, v16, (unsigned int)v17);
      v35 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v37 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v37 - 4096);
      _WriteStatusReg(TTBR1_EL1, v37);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v35);
    }
    if ( v27 )
    {
      v38 = v27;
      printk(&unk_FA29, "spcom_device_read", v27);
      ipc_log_string(
        *(_QWORD *)(v10 + 4032),
        "%sspcom:%s: Unable to copy to user, err = %d\n",
        "spcom_device_read",
        &unk_F80E,
        v38);
      goto LABEL_64;
    }
  }
  else
  {
    printk(&unk_12955, "spcom_device_read", (unsigned int)v17);
    ipc_log_string(
      *(_QWORD *)(v10 + 4032),
      "%sspcom:%s: invalid actual_size [%d]\n",
      "spcom_device_read",
      &unk_F80E,
      (unsigned int)v17);
LABEL_64:
    v22 = -14;
  }
LABEL_65:
  kfree(v16);
  if ( *(_DWORD *)(v15 + 240) == v12 )
  {
    *(_DWORD *)(v15 + 240) = 0;
    mutex_unlock(v15 + 248);
  }
  return v22;
}
