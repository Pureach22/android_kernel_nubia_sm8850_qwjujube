void __fastcall ipa_gsb_tx_dp_notify(__int64 a1, unsigned int a2, __int64 a3)
{
  unsigned int *v5; // x9
  unsigned int v6; // w8
  unsigned int v7; // w21
  __int64 v8; // x23
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 v11; // x0
  _DWORD *v12; // x9
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  if ( a3 )
  {
    if ( a2 >= 2 )
    {
      printk(&unk_3C5755, "ipa_gsb_tx_dp_notify");
      if ( ipa3_get_ipc_logbuf() )
      {
        ipc_logbuf = ipa3_get_ipc_logbuf();
        ipc_log_string(ipc_logbuf, "ipa_gsb %s:%d unexpected event: %d\n", "ipa_gsb_tx_dp_notify", 761, a2);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
        ipc_log_string(ipc_logbuf_low, "ipa_gsb %s:%d unexpected event: %d\n", "ipa_gsb_tx_dp_notify", 761, a2);
      }
    }
    else
    {
      v5 = *(unsigned int **)(a3 + 224);
      v6 = bswap32(*v5);
      v7 = (unsigned __int8)v6;
      *v5 = v6;
      if ( (unsigned __int8)v6 <= 4u )
      {
        v8 = v6 & 7;
        if ( *(_QWORD *)(ipa_gsb_ctx + 8 * v8 + 96) )
        {
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v9 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v9, "ipa_gsb %s:%d evt: %d, hdl in tx_dp_notify: %d\n", "ipa_gsb_tx_dp_notify", 777, a2, v7);
          }
          skb_pull(a3, 4);
          v10 = *(_QWORD *)(ipa_gsb_ctx + 8 * v8 + 96);
          v11 = *(_QWORD *)(v10 + 40);
          v12 = *(_DWORD **)(v10 + 48);
          if ( *(v12 - 1) != 420538815 )
            __break(0x8229u);
          ((void (__fastcall *)(__int64, _QWORD, __int64))v12)(v11, a2, a3);
          return;
        }
      }
      printk(&unk_3F08DC, "ipa_gsb_tx_dp_notify");
      if ( ipa3_get_ipc_logbuf() )
      {
        v13 = ipa3_get_ipc_logbuf();
        ipc_log_string(v13, "ipa_gsb %s:%d invalid hdl: %d and cb, drop the skb\n", "ipa_gsb_tx_dp_notify", 773, v7);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v14 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v14, "ipa_gsb %s:%d invalid hdl: %d and cb, drop the skb\n", "ipa_gsb_tx_dp_notify", 773, v7);
      }
    }
    dev_kfree_skb_any_reason(a3, 2);
    return;
  }
  printk(&unk_3B66EE, "ipa_gsb_tx_dp_notify");
  if ( ipa3_get_ipc_logbuf() )
  {
    v15 = ipa3_get_ipc_logbuf();
    ipc_log_string(v15, "ipa_gsb %s:%d unexpected NULL data\n", "ipa_gsb_tx_dp_notify", 755);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v16 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v16, "ipa_gsb %s:%d unexpected NULL data\n", "ipa_gsb_tx_dp_notify", 755);
  }
  __break(0x800u);
}
