__int64 __fastcall ipa3_low_lat_rx_pyld_hdlr(__int64 a1, __int64 a2)
{
  __int64 v3; // x9
  _DWORD *v4; // x8
  __int64 v5; // x0
  __int64 v7; // x20
  __int64 v8; // x8
  __int64 v9; // x9
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x9
  __int64 v13; // x0
  __int64 v14; // x0
  void (__fastcall *v15)(_QWORD); // x8

  if ( !*(_DWORD *)(a1 + 112) )
  {
    v7 = a2;
    printk(&unk_3C9A2C, "ipa3_low_lat_rx_pyld_hdlr");
    v8 = v7;
    v9 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_18;
    v10 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v10 )
    {
      ipc_log_string(v10, "ipa %s:%d ZLT\n", "ipa3_low_lat_rx_pyld_hdlr", 4310);
      v9 = ipa3_ctx;
      v8 = v7;
    }
    v11 = *(_QWORD *)(v9 + 34160);
    if ( !v11 )
      goto LABEL_18;
    ipc_log_string(v11, "ipa %s:%d ZLT\n", "ipa3_low_lat_rx_pyld_hdlr", 4310);
    goto LABEL_17;
  }
  v3 = *(_QWORD *)(a2 + 1624);
  v4 = *(_DWORD **)(v3 + 376);
  if ( v4 )
  {
    v5 = *(_QWORD *)(v3 + 368);
    if ( *(v4 - 1) != 420538815 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD, __int64))v4)(v5, 0, a1);
    return 0;
  }
  v7 = a2;
  printk(&unk_3C0C48, "ipa3_low_lat_rx_pyld_hdlr");
  v8 = v7;
  v12 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v13 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v13 )
    {
      ipc_log_string(v13, "ipa %s:%d client_notify is NULL", "ipa3_low_lat_rx_pyld_hdlr", 4316);
      v12 = ipa3_ctx;
      v8 = v7;
    }
    v14 = *(_QWORD *)(v12 + 34160);
    if ( v14 )
    {
      ipc_log_string(v14, "ipa %s:%d client_notify is NULL", "ipa3_low_lat_rx_pyld_hdlr", 4316);
LABEL_17:
      v8 = v7;
    }
  }
LABEL_18:
  v15 = *(void (__fastcall **)(_QWORD))(v8 + 144);
  if ( *((_DWORD *)v15 - 1) != 303786302 )
    __break(0x8228u);
  v15(a1);
  return 0;
}
