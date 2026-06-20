void __fastcall ipa_gsb_cons_cb(__int64 a1, int a2, __int64 a3)
{
  unsigned __int8 *v4; // x8
  __int64 v5; // x20
  int v6; // w24
  unsigned __int16 v7; // w26
  __int64 v8; // x0
  __int64 v9; // x0
  unsigned int v10; // w24
  __int64 v11; // x23
  __int64 v12; // x8
  void (__fastcall *v13)(__int64, __int64); // x9
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0

  if ( a2 )
  {
    printk(&unk_3A5106, "ipa_gsb_cons_cb");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_gsb %s:%d unexpected event\n", "ipa_gsb_cons_cb", 685);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipa_gsb %s:%d unexpected event\n", "ipa_gsb_cons_cb", 685);
    }
    goto LABEL_17;
  }
  if ( !a3 )
  {
    printk(&unk_3B66EE, "ipa_gsb_cons_cb");
    if ( ipa3_get_ipc_logbuf() )
    {
      v18 = ipa3_get_ipc_logbuf();
      ipc_log_string(v18, "ipa_gsb %s:%d unexpected NULL data\n", "ipa_gsb_cons_cb", 693);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v19 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v19, "ipa_gsb %s:%d unexpected NULL data\n", "ipa_gsb_cons_cb", 693);
    }
LABEL_17:
    __break(0x800u);
    return;
  }
  if ( *(_DWORD *)(a3 + 112) )
  {
    while ( 1 )
    {
      v4 = *(unsigned __int8 **)(a3 + 224);
      v5 = *v4;
      if ( (unsigned int)v5 >= 5 )
        break;
      v6 = *((unsigned __int16 *)v4 + 1);
      v7 = ((v6 + 63) & 0xFFFC) - v6 - 60;
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v8 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v8,
          "ipa_gsb %s:%d pkt_size: %d, pad_byte: %d, hdl: %d\n",
          "ipa_gsb_cons_cb",
          712,
          v6,
          (unsigned __int16)(((v6 + 63) & 0xFFFC) - v6 - 60),
          v5);
      }
      skb_pull(a3, 46);
      v9 = skb_clone(a3, 3264);
      if ( !v9 )
      {
        printk(&unk_3B0DDB, "ipa_gsb_cons_cb");
        if ( ipa3_get_ipc_logbuf() )
        {
          v22 = ipa3_get_ipc_logbuf();
          ipc_log_string(v22, "ipa_gsb %s:%d skb_clone failed\n", "ipa_gsb_cons_cb", 719);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v23 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v23, "ipa_gsb %s:%d skb_clone failed\n", "ipa_gsb_cons_cb", 719);
        }
        __break(0x800u);
        goto LABEL_12;
      }
      v10 = v6 + 14;
      v11 = v9;
      skb_trim(v9, v10);
      raw_spin_lock_bh(ipa_gsb_ctx + 4LL * (unsigned int)v5 + 376);
      v12 = *(_QWORD *)(ipa_gsb_ctx + 8LL * (unsigned int)v5 + 96);
      if ( !v12 )
      {
        printk(&unk_3F3BD7, "ipa_gsb_cons_cb");
        if ( ipa3_get_ipc_logbuf() )
        {
          v24 = ipa3_get_ipc_logbuf();
          ipc_log_string(v24, "ipa_gsb %s:%d Invalid hdl: %d, drop the skb\n", "ipa_gsb_cons_cb", 732, v5);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v25 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v25, "ipa_gsb %s:%d Invalid hdl: %d, drop the skb\n", "ipa_gsb_cons_cb", 732, v5);
        }
        raw_spin_unlock_bh(ipa_gsb_ctx + 4 * v5 + 376);
        dev_kfree_skb_any_reason(v11, 2);
        goto LABEL_12;
      }
      v13 = *(void (__fastcall **)(__int64, __int64))(v12 + 56);
      v14 = *(_QWORD *)(v12 + 40);
      if ( *((_DWORD *)v13 - 1) != 1347576298 )
        __break(0x8229u);
      v13(v14, v11);
      v15 = ipa_gsb_ctx + 4 * v5 + 376;
      ++*(_QWORD *)(*(_QWORD *)(ipa_gsb_ctx + 8 * v5 + 96) + 72LL);
      raw_spin_unlock_bh(v15);
      skb_pull(a3, v10 + v7);
      if ( !*(_DWORD *)(a3 + 112) )
        goto LABEL_12;
    }
    printk(&unk_3E7C9B, "ipa_gsb_cons_cb");
    if ( ipa3_get_ipc_logbuf() )
    {
      v20 = ipa3_get_ipc_logbuf();
      ipc_log_string(v20, "ipa_gsb %s:%d invalid hdl: %d\n", "ipa_gsb_cons_cb", 708, v5);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v21 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v21, "ipa_gsb %s:%d invalid hdl: %d\n", "ipa_gsb_cons_cb", 708, v5);
    }
  }
LABEL_12:
  dev_kfree_skb_any_reason(a3, 2);
}
