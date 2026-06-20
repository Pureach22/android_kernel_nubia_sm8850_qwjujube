__int64 __fastcall ipa3_send_vlan_l2tp_msg(unsigned __int64 a1, unsigned __int8 a2)
{
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  int v7; // w8
  __int64 v8; // x0
  __int64 v9; // x21
  unsigned __int64 v10; // x1
  __int16 v11; // w20
  __int64 result; // x0
  __int64 v13; // x0
  unsigned __int64 v14; // x1
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  unsigned __int64 v19; // x1
  unsigned int v20; // w0
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x0
  unsigned int v26; // w20
  __int64 v27; // x8
  __int64 v28; // x0
  __int64 v29; // x0
  int v30; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v31; // [xsp+8h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v5 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v5 )
    {
      ipc_log_string(v5, "ipa %s:%d type %d\n", "ipa3_send_vlan_l2tp_msg", 1178, a2);
      v4 = ipa3_ctx;
    }
    v6 = *(_QWORD *)(v4 + 34160);
    if ( v6 )
      ipc_log_string(v6, "ipa %s:%d type %d\n", "ipa3_send_vlan_l2tp_msg", 1178, a2);
  }
  v7 = a2 & 0xFE;
  v30 = a2;
  if ( v7 == 32 )
  {
    v13 = _kmalloc_cache_noprof(ipc_log_string, 3520, 44);
    v9 = v13;
    if ( !v13 )
      goto LABEL_41;
    v14 = a1;
    v11 = 44;
    if ( !inline_copy_from_user(v13, v14, 0x2Cu) )
      goto LABEL_21;
    kfree(v9);
    printk(&unk_3C31B7, "ipa3_send_vlan_l2tp_msg");
    v15 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v16 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v16 )
      {
        ipc_log_string(v16, "ipa %s:%d copy from user failed\n", "ipa3_send_vlan_l2tp_msg", 1227);
        v15 = ipa3_ctx;
      }
      v17 = *(_QWORD *)(v15 + 34160);
      if ( v17 )
      {
        ipc_log_string(v17, "ipa %s:%d copy from user failed\n", "ipa3_send_vlan_l2tp_msg", 1227);
LABEL_33:
        result = 4294967282LL;
        goto LABEL_42;
      }
    }
LABEL_40:
    result = 4294967282LL;
    goto LABEL_42;
  }
  if ( v7 == 28 )
  {
    v18 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 84);
    v9 = v18;
    if ( v18 )
    {
      v19 = a1;
      v11 = 84;
      if ( inline_copy_from_user(v18, v19, 0x54u) )
        goto LABEL_11;
      goto LABEL_21;
    }
LABEL_41:
    result = 4294967284LL;
    goto LABEL_42;
  }
  if ( v7 != 26 )
  {
    printk(&unk_3E8C5C, "ipa3_send_vlan_l2tp_msg");
    v23 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v24 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v24 )
      {
        ipc_log_string(v24, "ipa %s:%d Unexpected event\n", "ipa3_send_vlan_l2tp_msg", 1235);
        v23 = ipa3_ctx;
      }
      v25 = *(_QWORD *)(v23 + 34160);
      if ( v25 )
      {
        ipc_log_string(v25, "ipa %s:%d Unexpected event\n", "ipa3_send_vlan_l2tp_msg", 1235);
        goto LABEL_33;
      }
    }
    goto LABEL_40;
  }
  v8 = _kmalloc_cache_noprof(ipc_log_string, 3520, 33);
  v9 = v8;
  if ( !v8 )
    goto LABEL_41;
  v10 = a1;
  v11 = 33;
  if ( inline_copy_from_user(v8, v10, 0x21u) )
  {
LABEL_11:
    kfree(v9);
    result = 4294967282LL;
    goto LABEL_42;
  }
LABEL_21:
  HIWORD(v30) = v11;
  v20 = ipa_send_msg(&v30, v9, ipa3_vlan_l2tp_msg_free_cb);
  if ( v20 )
  {
    v26 = v20;
    printk(&unk_3A29B0, "ipa3_send_vlan_l2tp_msg");
    v27 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v28 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v28 )
      {
        ipc_log_string(
          v28,
          "ipa %s:%d ipa_send_msg failed: %d, msg_type %d\n",
          "ipa3_send_vlan_l2tp_msg",
          1244,
          v26,
          a2);
        v27 = ipa3_ctx;
      }
      v29 = *(_QWORD *)(v27 + 34160);
      if ( v29 )
        ipc_log_string(
          v29,
          "ipa %s:%d ipa_send_msg failed: %d, msg_type %d\n",
          "ipa3_send_vlan_l2tp_msg",
          1244,
          v26,
          a2);
    }
    kfree(v9);
    result = v26;
  }
  else
  {
    v21 = ipa3_ctx;
    if ( !ipa3_ctx )
    {
LABEL_27:
      result = 0;
      goto LABEL_42;
    }
    v22 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v22 )
    {
      ipc_log_string(v22, "ipa %s:%d exit\n", "ipa3_send_vlan_l2tp_msg", 1248);
      v21 = ipa3_ctx;
    }
    result = *(_QWORD *)(v21 + 34160);
    if ( result )
    {
      ipc_log_string(result, "ipa %s:%d exit\n", "ipa3_send_vlan_l2tp_msg", 1248);
      goto LABEL_27;
    }
  }
LABEL_42:
  _ReadStatusReg(SP_EL0);
  return result;
}
