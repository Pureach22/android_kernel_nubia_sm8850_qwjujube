__int64 __fastcall ipa_odl_ctl_fops_ioctl(__int64 a1, int a2, unsigned __int64 a3)
{
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x9
  unsigned __int64 StatusReg; // x8
  int v10; // w9
  char v11; // w11
  unsigned __int64 v12; // x9
  unsigned __int64 v13; // x9
  unsigned __int64 v19; // x8
  __int64 result; // x0
  unsigned __int64 v21; // x8
  unsigned __int64 v23; // x9
  __int64 v24; // x8
  __int64 v25; // x0
  __int64 v26; // x0
  unsigned __int64 v27; // x8
  unsigned __int64 v28; // x9
  unsigned __int64 v29; // x9
  unsigned __int64 v31; // x8
  unsigned __int64 v32; // x2
  unsigned __int64 v33; // x8
  unsigned __int64 v35; // x9
  int v36; // w4
  __int64 v37; // x8
  __int64 v38; // x0
  __int64 v39; // x8
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x0
  _BYTE v43[4]; // [xsp+4h] [xbp-1Ch] BYREF
  _DWORD v44[2]; // [xsp+8h] [xbp-18h] BYREF
  __int64 v45; // [xsp+10h] [xbp-10h]
  __int64 v46; // [xsp+18h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = ipa3_ctx;
  v43[0] = 0;
  if ( ipa3_ctx )
  {
    v6 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v6 )
    {
      ipc_log_string(v6, "ipa %s:%d Calling odl ioctl cmd = %d\n", "ipa_odl_ctl_fops_ioctl", 162, a2);
      v5 = ipa3_ctx;
    }
    v7 = *(_QWORD *)(v5 + 34160);
    if ( v7 )
      ipc_log_string(v7, "ipa %s:%d Calling odl ioctl cmd = %d\n", "ipa_odl_ctl_fops_ioctl", 162, a2);
  }
  v8 = ipa3_odl_ctx;
  if ( (*(_WORD *)(ipa3_odl_ctx + 692) & 0x20) == 0 )
  {
    printk(&unk_3A7086, "ipa_odl_ctl_fops_ioctl");
    v39 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v40 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v40 )
      {
        ipc_log_string(
          v40,
          "ipa %s:%d Before complete the odl setup trying calling ioctl\n",
          "ipa_odl_ctl_fops_ioctl",
          164);
        v39 = ipa3_ctx;
      }
      v41 = *(_QWORD *)(v39 + 34160);
      if ( v41 )
        ipc_log_string(
          v41,
          "ipa %s:%d Before complete the odl setup trying calling ioctl\n",
          "ipa_odl_ctl_fops_ioctl",
          164);
    }
    print_ipa_odl_state_bit_mask();
    result = -19;
    goto LABEL_37;
  }
  if ( a2 != -1073623233 )
  {
    if ( a2 != -1072640195 )
    {
      result = -515;
      goto LABEL_37;
    }
    StatusReg = _ReadStatusReg(SP_EL0);
    v10 = *(_DWORD *)(v8 + 688);
    v11 = *(_BYTE *)(StatusReg + 70);
    v45 = 0x200000003LL;
    v44[0] = -1;
    v44[1] = v10;
    if ( (v11 & 0x20) != 0 || (v12 = a3, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v12 = a3 & ((__int64)(a3 << 8) >> 8);
    if ( v12 <= 0x7FFFFFFFF0LL )
    {
      v13 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v19 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v19 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v19);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v13);
      result = _arch_copy_to_user(a3 & 0xFF7FFFFFFFFFFFFFLL, v44, 16);
      v21 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v23 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v23 - 4096);
      _WriteStatusReg(TTBR1_EL1, v23);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v21);
      if ( !result )
      {
        *(_WORD *)(ipa3_odl_ctx + 692) |= 0x40u;
        goto LABEL_37;
      }
    }
    goto LABEL_36;
  }
  v24 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v25 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v25 )
    {
      ipc_log_string(v25, "ipa %s:%d Received the IPA_IOC_ODL_QUERY_MODEM_CONFIG :\n", "ipa_odl_ctl_fops_ioctl", 186);
      v24 = ipa3_ctx;
    }
    v26 = *(_QWORD *)(v24 + 34160);
    if ( v26 )
      ipc_log_string(v26, "ipa %s:%d Received the IPA_IOC_ODL_QUERY_MODEM_CONFIG :\n", "ipa_odl_ctl_fops_ioctl", 186);
  }
  v27 = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(v27 + 70) & 0x20) != 0 || (v28 = a3, (*(_QWORD *)v27 & 0x4000000) != 0) )
    v28 = a3 & ((__int64)(a3 << 8) >> 8);
  if ( v28 >> 39 )
  {
    v32 = 1;
  }
  else
  {
    v29 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v31 = *(_QWORD *)(v27 + 8);
    _WriteStatusReg(TTBR1_EL1, v31 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v31);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v29);
    v32 = _arch_copy_from_user(v43, a3 & 0xFF7FFFFFFFFFFFFFLL, 1);
    v33 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v35 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v35 - 4096);
    _WriteStatusReg(TTBR1_EL1, v35);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v33);
    if ( !v32 )
    {
      v36 = v43[0];
      if ( v43[0] == 1 )
        *(_WORD *)(ipa3_odl_ctx + 692) |= 0x80u;
      v37 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v38 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v38 )
        {
          ipc_log_string(
            v38,
            "ipa %s:%d status.config_status = %d odl_connected = %d\n",
            "ipa_odl_ctl_fops_ioctl",
            195,
            v36,
            (*(unsigned __int16 *)(ipa3_odl_ctx + 692) >> 7) & 1);
          v37 = ipa3_ctx;
        }
        result = *(_QWORD *)(v37 + 34160);
        if ( !result )
          goto LABEL_37;
        ipc_log_string(
          result,
          "ipa %s:%d status.config_status = %d odl_connected = %d\n",
          "ipa_odl_ctl_fops_ioctl",
          195,
          v43[0],
          (*(unsigned __int16 *)(ipa3_odl_ctx + 692) >> 7) & 1);
      }
      result = 0;
LABEL_37:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  if ( v32 < 2 )
  {
LABEL_36:
    result = -14;
    goto LABEL_37;
  }
  v42 = _fortify_panic(15, 0, v32);
  return ipa_odl_ctl_fops_open(v42);
}
