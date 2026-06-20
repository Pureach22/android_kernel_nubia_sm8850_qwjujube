__int64 __fastcall ipa3_wigig_tx_bit_to_ep(unsigned __int8 a1, _DWORD *a2)
{
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 result; // x0
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0

  v4 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v5 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v5 )
    {
      ipc_log_string(v5, "ipa %s:%d tx_bit_num %d\n", "ipa3_wigig_tx_bit_to_ep", 150, a1);
      v4 = ipa3_ctx;
    }
    v6 = *(_QWORD *)(v4 + 34160);
    if ( v6 )
      ipc_log_string(v6, "ipa %s:%d tx_bit_num %d\n", "ipa3_wigig_tx_bit_to_ep", 150, a1);
  }
  if ( (unsigned __int8)(a1 - 2) >= 4u )
  {
    printk(&unk_3E1D12, "ipa3_wigig_tx_bit_to_ep");
    v10 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v11 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v11 )
      {
        ipc_log_string(v11, "ipa %s:%d invalid tx_bit_num %d\n", "ipa3_wigig_tx_bit_to_ep", 166, a1);
        v10 = ipa3_ctx;
      }
      v12 = *(_QWORD *)(v10 + 34160);
      if ( v12 )
        ipc_log_string(v12, "ipa %s:%d invalid tx_bit_num %d\n", "ipa3_wigig_tx_bit_to_ep", 166, a1);
    }
    return 4294967274LL;
  }
  else
  {
    *a2 = (unsigned __int8)(2 * (a1 - 2) + 87);
    v7 = ipa3_ctx;
    if ( !ipa3_ctx )
      return 0;
    v8 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v8 )
    {
      ipc_log_string(v8, "ipa %s:%d exit\n", "ipa3_wigig_tx_bit_to_ep", 170);
      v7 = ipa3_ctx;
    }
    result = *(_QWORD *)(v7 + 34160);
    if ( result )
    {
      ipc_log_string(result, "ipa %s:%d exit\n", "ipa3_wigig_tx_bit_to_ep", 170);
      return 0;
    }
  }
  return result;
}
