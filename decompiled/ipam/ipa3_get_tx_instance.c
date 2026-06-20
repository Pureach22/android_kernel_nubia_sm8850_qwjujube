__int64 __fastcall ipa3_get_tx_instance(
        unsigned int a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 v8; // x15
  __int64 v9; // d24
  __int64 v11; // x8
  unsigned int v12; // w20
  __int64 v13; // x0
  __int64 v14; // x0
  unsigned __int64 v15; // x8
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0

  v11 = ipa3_ctx;
  v12 = *(unsigned __int8 *)(ipa3_ctx + 32244);
  if ( ipa3_ctx )
  {
    v13 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v13 )
    {
      ipc_log_string(v13, "ipa %s:%d ipa_get_ep_group: hw_idx = %d\n", "ipa3_get_tx_instance", 8457, v12);
      v11 = ipa3_ctx;
    }
    v14 = *(_QWORD *)(v11 + 34160);
    if ( v14 )
      ipc_log_string(v14, "ipa %s:%d ipa_get_ep_group: hw_idx = %d\n", "ipa3_get_tx_instance", 8457, v12);
  }
  if ( a1 >= 0x86 )
  {
    printk(&unk_3F3029, "ipa3_get_tx_instance");
    v17 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v18 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v18 )
      {
        ipc_log_string(v18, "ipa %s:%d Bad client number! client =%d\n", "ipa3_get_tx_instance", 8460, a1);
        v17 = ipa3_ctx;
      }
      v19 = *(_QWORD *)(v17 + 34160);
      if ( v19 )
        ipc_log_string(v19, "ipa %s:%d Bad client number! client =%d\n", "ipa3_get_tx_instance", 8460, a1);
    }
  }
  else
  {
    if ( v12 >= 0x18 )
    {
LABEL_20:
      __break(0x5512u);
      *(_QWORD *)(v8 + 104) = v9;
      *(double *)(v8 + 112) = a8;
      return ipa3_set_client();
    }
    v15 = 52LL * a1 + 6968LL * v12;
    if ( v15 > 0x28D3F )
    {
LABEL_19:
      __break(1u);
      goto LABEL_20;
    }
    if ( ipa3_ep_mapping[v15] == 1 )
    {
      if ( v15 <= 0x28D0F )
        return (unsigned __int8)ipa3_ep_mapping[v15 + 48];
      goto LABEL_19;
    }
  }
  return 234;
}
