__int64 __fastcall ipa3_send_mac_flt_list(unsigned __int64 a1)
{
  __int64 v2; // x0
  _DWORD *v3; // x19
  unsigned int v4; // w20
  __int64 result; // x0
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0
  int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = _kmalloc_cache_noprof(raw_spin_lock_irqsave, 3520, 200);
  v3 = (_DWORD *)v2;
  if ( !v2 )
  {
    result = 4294967284LL;
    goto LABEL_17;
  }
  if ( inline_copy_from_user(v2, a1, 0xC8u) )
  {
    v4 = -14;
LABEL_4:
    kfree(v3);
    result = v4;
    goto LABEL_17;
  }
  v6 = ipa3_ctx;
  v12 = 13107245;
  if ( ipa3_ctx )
  {
    v7 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v7 )
    {
      ipc_log_string(
        v7,
        "ipa %s:%d No of clients: %d, flt state: %d\n",
        "ipa3_send_mac_flt_list",
        2589,
        *v3,
        *((unsigned __int8 *)v3 + 196));
      v6 = ipa3_ctx;
    }
    v8 = *(_QWORD *)(v6 + 34160);
    if ( v8 )
      ipc_log_string(
        v8,
        "ipa %s:%d No of clients: %d, flt state: %d\n",
        "ipa3_send_mac_flt_list",
        2589,
        *v3,
        *((unsigned __int8 *)v3 + 196));
  }
  result = ipa_send_msg(&v12, v3, ipa3_general_free_cb);
  if ( (_DWORD)result )
  {
    v4 = result;
    printk(&unk_3A29B0, "ipa3_send_mac_flt_list");
    v9 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v10 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v10 )
      {
        ipc_log_string(
          v10,
          "ipa %s:%d ipa_send_msg failed: %d, msg_type %d\n",
          "ipa3_send_mac_flt_list",
          2596,
          v4,
          (unsigned __int8)v12);
        v9 = ipa3_ctx;
      }
      v11 = *(_QWORD *)(v9 + 34160);
      if ( v11 )
        ipc_log_string(
          v11,
          "ipa %s:%d ipa_send_msg failed: %d, msg_type %d\n",
          "ipa3_send_mac_flt_list",
          2596,
          v4,
          (unsigned __int8)v12);
    }
    goto LABEL_4;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
