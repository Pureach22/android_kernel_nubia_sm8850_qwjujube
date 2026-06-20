__int64 __fastcall ipa3_send_pkt_threshold(unsigned __int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  unsigned int v4; // w21
  unsigned __int8 *v5; // x20
  __int64 v6; // x0
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x0
  int v23; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v24; // [xsp+8h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = _kmalloc_cache_noprof(kfree, 3520, 16);
  v3 = v2;
  if ( !v2 )
  {
    v4 = -12;
    goto LABEL_33;
  }
  if ( inline_copy_from_user(v2, a1, 0x10u) )
    goto LABEL_3;
  if ( *(_DWORD *)(v3 + 8) != 8 )
  {
    printk(&unk_3F71FA, "ipa3_send_pkt_threshold");
    v13 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v14 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v14 )
      {
        ipc_log_string(
          v14,
          "ipa %s:%d IPA_IOC_SET_PKT_THRESHOLD size not match(%d,%lu)!\n",
          "ipa3_send_pkt_threshold",
          2624,
          *(_DWORD *)(v3 + 8),
          8);
        v13 = ipa3_ctx;
      }
      v15 = *(_QWORD *)(v13 + 34160);
      if ( v15 )
        ipc_log_string(
          v15,
          "ipa %s:%d IPA_IOC_SET_PKT_THRESHOLD size not match(%d,%lu)!\n",
          "ipa3_send_pkt_threshold",
          2624,
          *(_DWORD *)(v3 + 8),
          8);
    }
LABEL_3:
    v4 = -14;
LABEL_4:
    v5 = (unsigned __int8 *)v3;
LABEL_5:
    kfree(v5);
    goto LABEL_33;
  }
  v6 = _kmalloc_cache_noprof(sg_next, 3520, 8);
  v5 = (unsigned __int8 *)v6;
  if ( !v6 )
  {
    printk(&unk_3B45FD, "ipa3_send_pkt_threshold");
    v20 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v21 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v21 )
      {
        ipc_log_string(v21, "ipa %s:%d ipa_set_pkt_threshold buff2 allocate failure\n", "ipa3_send_pkt_threshold", 2632);
        v20 = ipa3_ctx;
      }
      v22 = *(_QWORD *)(v20 + 34160);
      if ( v22 )
        ipc_log_string(v22, "ipa %s:%d ipa_set_pkt_threshold buff2 allocate failure\n", "ipa3_send_pkt_threshold", 2632);
    }
    v4 = -12;
    goto LABEL_4;
  }
  if ( inline_copy_from_user(v6, *(_QWORD *)v3, 8u) )
  {
    printk(&unk_3D4F9A, "ipa3_send_pkt_threshold");
    v16 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v17 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v17 )
      {
        ipc_log_string(v17, "ipa %s:%d Failed to copy ipa_set_pkt_threshold\n", "ipa3_send_pkt_threshold", 2640);
        v16 = ipa3_ctx;
      }
      v18 = *(_QWORD *)(v16 + 34160);
      if ( v18 )
        ipc_log_string(v18, "ipa %s:%d Failed to copy ipa_set_pkt_threshold\n", "ipa3_send_pkt_threshold", 2640);
    }
    kfree(v3);
    v4 = -14;
    goto LABEL_5;
  }
  v7 = ipa3_ctx;
  v23 = 524338;
  if ( ipa3_ctx )
  {
    v8 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v8 )
    {
      ipc_log_string(
        v8,
        "ipa %s:%d pkt thr enable: %d, pkt_threshold: %d\n",
        "ipa3_send_pkt_threshold",
        2653,
        *v5,
        *((_DWORD *)v5 + 1));
      v7 = ipa3_ctx;
    }
    v9 = *(_QWORD *)(v7 + 34160);
    if ( v9 )
      ipc_log_string(
        v9,
        "ipa %s:%d pkt thr enable: %d, pkt_threshold: %d\n",
        "ipa3_send_pkt_threshold",
        2653,
        *v5,
        *((_DWORD *)v5 + 1));
  }
  v4 = ipa_send_msg(&v23, v5, ipa3_general_free_cb);
  if ( v4 )
  {
    printk(&unk_3A29B0, "ipa3_send_pkt_threshold");
    v10 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v11 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v11 )
      {
        ipc_log_string(
          v11,
          "ipa %s:%d ipa_send_msg failed: %d, msg_type %d\n",
          "ipa3_send_pkt_threshold",
          2660,
          v4,
          (unsigned __int8)v23);
        v10 = ipa3_ctx;
      }
      v12 = *(_QWORD *)(v10 + 34160);
      if ( v12 )
        ipc_log_string(
          v12,
          "ipa %s:%d ipa_send_msg failed: %d, msg_type %d\n",
          "ipa3_send_pkt_threshold",
          2660,
          v4,
          (unsigned __int8)v23);
    }
    kfree(v3);
    goto LABEL_5;
  }
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return v4;
}
