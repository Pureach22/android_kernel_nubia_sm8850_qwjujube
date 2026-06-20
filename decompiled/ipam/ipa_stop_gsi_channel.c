__int64 __fastcall ipa_stop_gsi_channel(unsigned int a1)
{
  unsigned int v2; // w9
  unsigned int v3; // w20
  unsigned int v4; // w9
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0

  _ReadStatusReg(SP_EL0);
  if ( (a1 & 0x80000000) != 0 || (v2 = *(_DWORD *)(ipa3_ctx + 34308), v2 <= a1) )
  {
    printk(&unk_3E7136, "ipa3_get_client_mapping");
    v6 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v7 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v7 )
      {
        ipc_log_string(v7, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
        v6 = ipa3_ctx;
      }
      v8 = *(_QWORD *)(v6 + 34160);
      if ( v8 )
        ipc_log_string(v8, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
    }
    __break(0x800u);
    v2 = *(_DWORD *)(ipa3_ctx + 34308);
    if ( (a1 & 0x80000000) != 0 )
      goto LABEL_20;
  }
  else
  {
    if ( a1 >= 0x24 )
      goto LABEL_38;
    if ( (a1 & 0x80000000) != 0 )
      goto LABEL_20;
  }
  if ( v2 <= a1 )
  {
LABEL_20:
    printk(&unk_3E7136, "ipa3_get_client_mapping");
    v9 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v10 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v10 )
      {
        ipc_log_string(v10, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
        v9 = ipa3_ctx;
      }
      v11 = *(_QWORD *)(v9 + 34160);
      if ( v11 )
        ipc_log_string(v11, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
    }
    __break(0x800u);
    goto LABEL_7;
  }
  if ( a1 >= 0x24 )
    goto LABEL_38;
LABEL_7:
  ipa3_inc_client_enable_clks();
  v3 = ((__int64 (__fastcall *)(_QWORD))_ipa_stop_gsi_channel)(a1);
  if ( (a1 & 0x80000000) != 0 || (v4 = *(_DWORD *)(ipa3_ctx + 34308), v4 <= a1) )
  {
    printk(&unk_3E7136, "ipa3_get_client_mapping");
    v12 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v13 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v13 )
      {
        ipc_log_string(v13, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
        v12 = ipa3_ctx;
      }
      v14 = *(_QWORD *)(v12 + 34160);
      if ( v14 )
        ipc_log_string(v14, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
    }
    __break(0x800u);
    v4 = *(_DWORD *)(ipa3_ctx + 34308);
    if ( (a1 & 0x80000000) != 0 )
      goto LABEL_32;
    goto LABEL_11;
  }
  if ( a1 >= 0x24 )
    goto LABEL_38;
  if ( (a1 & 0x80000000) == 0 )
  {
LABEL_11:
    if ( v4 > a1 )
    {
      if ( a1 < 0x24 )
        goto LABEL_13;
LABEL_38:
      __break(0x5512u);
    }
  }
LABEL_32:
  printk(&unk_3E7136, "ipa3_get_client_mapping");
  v15 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v16 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v16 )
    {
      ipc_log_string(v16, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
      v15 = ipa3_ctx;
    }
    v17 = *(_QWORD *)(v15 + 34160);
    if ( v17 )
      ipc_log_string(v17, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
  }
  __break(0x800u);
LABEL_13:
  ipa3_dec_client_disable_clks();
  _ReadStatusReg(SP_EL0);
  return v3;
}
