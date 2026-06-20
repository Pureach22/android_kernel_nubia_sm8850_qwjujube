__int64 __fastcall ipa3_ioctl_fnr_counter_alloc(unsigned __int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 result; // x0
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0
  unsigned int v12; // w0
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v14; // x9
  unsigned __int64 v15; // x9
  unsigned __int64 v21; // x8
  unsigned __int64 v22; // x8
  unsigned __int64 v24; // x9
  __int64 v25; // x8
  __int64 v26; // x0
  __int64 v27; // x0
  unsigned int v28; // w19
  __int64 v29; // x8
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // [xsp+8h] [xbp-88h] BYREF
  __int64 v33; // [xsp+10h] [xbp-80h]
  __int64 v34; // [xsp+18h] [xbp-78h]
  __int64 v35; // [xsp+20h] [xbp-70h]
  __int64 v36; // [xsp+28h] [xbp-68h]
  __int64 v37; // [xsp+30h] [xbp-60h]
  __int64 v38; // [xsp+38h] [xbp-58h]
  __int64 v39; // [xsp+40h] [xbp-50h]
  __int64 v40; // [xsp+48h] [xbp-48h]
  __int64 v41; // [xsp+50h] [xbp-40h]
  __int64 v42; // [xsp+58h] [xbp-38h]
  __int64 v43; // [xsp+60h] [xbp-30h]
  __int64 v44; // [xsp+68h] [xbp-28h]
  __int64 v45; // [xsp+70h] [xbp-20h]
  __int64 v46; // [xsp+78h] [xbp-18h]
  __int64 v47; // [xsp+80h] [xbp-10h]
  __int64 v48; // [xsp+88h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v46 = 0;
  v47 = 0;
  v44 = 0;
  v45 = 0;
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  if ( inline_copy_from_user((__int64)&v32, a1, 0xCu) )
  {
    if ( (unsigned int)__ratelimit(&ipa3_ioctl_fnr_counter_alloc__rs, "ipa3_ioctl_fnr_counter_alloc") )
      printk(&unk_3F47D5, "ipa3_ioctl_fnr_counter_alloc");
    v2 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v3 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v3 )
      {
        ipc_log_string(v3, "ipa %s:%d copy_from_user fails\n", "ipa3_ioctl_fnr_counter_alloc", 2369);
        v2 = ipa3_ctx;
      }
      v4 = *(_QWORD *)(v2 + 34160);
      if ( v4 )
        ipc_log_string(v4, "ipa %s:%d copy_from_user fails\n", "ipa3_ioctl_fnr_counter_alloc", 2369);
    }
LABEL_9:
    result = 4294967282LL;
    goto LABEL_29;
  }
  if ( BYTE4(v32) > 0x18u || (unsigned __int8)v33 >= 9u )
  {
    if ( (unsigned int)__ratelimit(&ipa3_ioctl_fnr_counter_alloc__rs_606, "ipa3_ioctl_fnr_counter_alloc") )
      printk(&unk_3FD5E8, "ipa3_ioctl_fnr_counter_alloc");
    v9 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v10 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v10 )
      {
        ipc_log_string(v10, "ipa %s:%d failed: wrong sw/hw num_counters\n", "ipa3_ioctl_fnr_counter_alloc", 2378);
        v9 = ipa3_ctx;
      }
      v11 = *(_QWORD *)(v9 + 34160);
      if ( v11 )
      {
        ipc_log_string(v11, "ipa %s:%d failed: wrong sw/hw num_counters\n", "ipa3_ioctl_fnr_counter_alloc", 2378);
        goto LABEL_27;
      }
    }
LABEL_28:
    result = 0xFFFFFFFFLL;
    goto LABEL_29;
  }
  if ( !(BYTE4(v32) | (unsigned __int8)v33) )
  {
    if ( (unsigned int)__ratelimit(&ipa3_ioctl_fnr_counter_alloc__rs_609, "ipa3_ioctl_fnr_counter_alloc") )
      printk(&unk_3E8C7A, "ipa3_ioctl_fnr_counter_alloc");
    v6 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v7 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v7 )
      {
        ipc_log_string(v7, "ipa %s:%d failed: both sw/hw num_counters 0\n", "ipa3_ioctl_fnr_counter_alloc", 2385);
        v6 = ipa3_ctx;
      }
      v8 = *(_QWORD *)(v6 + 34160);
      if ( v8 )
      {
        ipc_log_string(v8, "ipa %s:%d failed: both sw/hw num_counters 0\n", "ipa3_ioctl_fnr_counter_alloc", 2385);
LABEL_27:
        result = 0xFFFFFFFFLL;
        goto LABEL_29;
      }
    }
    goto LABEL_28;
  }
  v12 = ipa3_alloc_counter_id(&v32);
  if ( (v12 & 0x80000000) != 0 )
  {
    v28 = v12;
    if ( (unsigned int)__ratelimit(&ipa3_ioctl_fnr_counter_alloc__rs_612, "ipa3_ioctl_fnr_counter_alloc") )
      printk(&unk_3D7C0E, "ipa3_ioctl_fnr_counter_alloc");
    v29 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_51;
    v30 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v30 )
    {
      ipc_log_string(v30, "ipa %s:%d ipa3_alloc_counter_id failed\n", "ipa3_ioctl_fnr_counter_alloc", 2391);
      v29 = ipa3_ctx;
    }
    v31 = *(_QWORD *)(v29 + 34160);
    if ( v31 )
    {
      ipc_log_string(v31, "ipa %s:%d ipa3_alloc_counter_id failed\n", "ipa3_ioctl_fnr_counter_alloc", 2391);
      result = v28;
    }
    else
    {
LABEL_51:
      result = v28;
    }
  }
  else
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v14 = a1, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v14 = a1 & ((__int64)(a1 << 8) >> 8);
    if ( v14 > 0x7FFFFFFFF4LL )
      goto LABEL_54;
    v15 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v21 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v21 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v21);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v15);
    result = _arch_copy_to_user(a1 & 0xFF7FFFFFFFFFFFFFLL, &v32, 12);
    v22 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v24 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v24 - 4096);
    _WriteStatusReg(TTBR1_EL1, v24);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v22);
    if ( result )
    {
LABEL_54:
      if ( (unsigned int)__ratelimit(&ipa3_ioctl_fnr_counter_alloc__rs_615, "ipa3_ioctl_fnr_counter_alloc") )
        printk(&unk_3F1771, "ipa3_ioctl_fnr_counter_alloc");
      v25 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v26 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v26 )
        {
          ipc_log_string(v26, "ipa %s:%d copy_to_user fails\n", "ipa3_ioctl_fnr_counter_alloc", 2396);
          v25 = ipa3_ctx;
        }
        v27 = *(_QWORD *)(v25 + 34160);
        if ( v27 )
          ipc_log_string(v27, "ipa %s:%d copy_to_user fails\n", "ipa3_ioctl_fnr_counter_alloc", 2396);
      }
      ((void (__fastcall *)(_QWORD))ipa3_counter_remove_hdl)((unsigned int)v32);
      goto LABEL_9;
    }
  }
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
