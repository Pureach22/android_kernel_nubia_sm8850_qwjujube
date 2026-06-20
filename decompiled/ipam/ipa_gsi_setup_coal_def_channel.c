__int64 __fastcall ipa_gsi_setup_coal_def_channel(__int64 a1, __int64 a2, __int64 a3)
{
  int v3; // w9
  __int64 result; // x0
  unsigned int v6; // w19
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x9

  v3 = *(_DWORD *)(a1 + 196);
  *(_QWORD *)(a2 + 16) = *(_QWORD *)(a3 + 16);
  result = ipa_gsi_setup_transfer_ring(a2, (unsigned int)(2 * v3), *(_QWORD *)(a3 + 472), 2080);
  if ( (_DWORD)result )
  {
    v6 = result;
    if ( *(_QWORD *)(a2 + 40) )
      dma_free_attrs(
        *(_QWORD *)(ipa3_ctx + 34216),
        *(unsigned int *)(a2 + 48),
        *(_QWORD *)(a2 + 64),
        *(_QWORD *)(a2 + 56),
        0);
    printk(&unk_3EEFFB, "ipa_gsi_setup_coal_def_channel");
    v7 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v8 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v8 )
      {
        ipc_log_string(v8, "ipa %s:%d Destroying WAN_COAL_CONS evt_ring", "ipa_gsi_setup_coal_def_channel", 7108);
        v7 = ipa3_ctx;
      }
      v9 = *(_QWORD *)(v7 + 34160);
      if ( v9 )
        ipc_log_string(v9, "ipa %s:%d Destroying WAN_COAL_CONS evt_ring", "ipa_gsi_setup_coal_def_channel", 7108);
    }
    v10 = *(_QWORD *)(a2 + 16);
    if ( v10 != -1 )
    {
      gsi_dealloc_evt_ring(v10);
      *(_QWORD *)(a2 + 16) = -1;
    }
    printk(&unk_3DB4BA, "ipa_gsi_setup_coal_def_channel");
    v11 = ipa3_ctx;
    result = v6;
    if ( ipa3_ctx )
    {
      if ( *(_QWORD *)(ipa3_ctx + 34152) )
      {
        ipc_log_string(
          *(_QWORD *)(ipa3_ctx + 34152),
          "ipa %s:%d Return with err: %d\n",
          "ipa_gsi_setup_coal_def_channel",
          7113,
          v6);
        v11 = ipa3_ctx;
        result = v6;
      }
      if ( *(_QWORD *)(v11 + 34160) )
      {
        ipc_log_string(
          *(_QWORD *)(v11 + 34160),
          "ipa %s:%d Return with err: %d\n",
          "ipa_gsi_setup_coal_def_channel",
          7113,
          v6);
        return v6;
      }
    }
  }
  return result;
}
