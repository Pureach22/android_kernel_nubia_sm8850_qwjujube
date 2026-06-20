__int64 __fastcall ipa3_wdi3_gsi_evt_ring_err_cb(__int64 a1)
{
  int v1; // w3
  __int64 v2; // x0
  long double v3; // q0
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x8
  __int64 v14; // x0

  v1 = *(_DWORD *)(a1 + 8);
  if ( v1 > 1 )
  {
    if ( v1 == 2 )
    {
      v2 = printk(&unk_3F20AC, "ipa3_wdi3_gsi_evt_ring_err_cb");
      v13 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v14 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v14 )
        {
          v3 = ipc_log_string(
                 v14,
                 "ipa %s:%d Got GSI_EVT_UNSUPPORTED_INTER_EE_OP_ERR\n",
                 "ipa3_wdi3_gsi_evt_ring_err_cb",
                 32);
          v13 = ipa3_ctx;
        }
        v2 = *(_QWORD *)(v13 + 34160);
        if ( v2 )
          v3 = ipc_log_string(
                 v2,
                 "ipa %s:%d Got GSI_EVT_UNSUPPORTED_INTER_EE_OP_ERR\n",
                 "ipa3_wdi3_gsi_evt_ring_err_cb",
                 32);
      }
    }
    else
    {
      if ( v1 != 3 )
      {
LABEL_16:
        v2 = printk(&unk_3C9A50, "ipa3_wdi3_gsi_evt_ring_err_cb");
        v9 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v10 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v10 )
          {
            v3 = ipc_log_string(
                   v10,
                   "ipa %s:%d Unexpected err evt: %d\n",
                   "ipa3_wdi3_gsi_evt_ring_err_cb",
                   38,
                   *(_DWORD *)(a1 + 8));
            v9 = ipa3_ctx;
          }
          v2 = *(_QWORD *)(v9 + 34160);
          if ( v2 )
            v3 = ipc_log_string(
                   v2,
                   "ipa %s:%d Unexpected err evt: %d\n",
                   "ipa3_wdi3_gsi_evt_ring_err_cb",
                   38,
                   *(_DWORD *)(a1 + 8));
        }
        return ((__int64 (__fastcall *)(__int64, long double))ipa_assert)(v2, v3);
      }
      v2 = printk(&unk_3A6B54, "ipa3_wdi3_gsi_evt_ring_err_cb");
      v6 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v7 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v7 )
        {
          v3 = ipc_log_string(v7, "ipa %s:%d Got GSI_EVT_EVT_RING_EMPTY_ERR\n", "ipa3_wdi3_gsi_evt_ring_err_cb", 35);
          v6 = ipa3_ctx;
        }
        v2 = *(_QWORD *)(v6 + 34160);
        if ( v2 )
          v3 = ipc_log_string(v2, "ipa %s:%d Got GSI_EVT_EVT_RING_EMPTY_ERR\n", "ipa3_wdi3_gsi_evt_ring_err_cb", 35);
      }
    }
  }
  else
  {
    if ( v1 )
    {
      if ( v1 == 1 )
      {
        v2 = printk(&unk_3CF9B1, "ipa3_wdi3_gsi_evt_ring_err_cb");
        v4 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v5 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v5 )
          {
            v3 = ipc_log_string(v5, "ipa %s:%d Got GSI_EVT_OUT_OF_RESOURCES_ERR\n", "ipa3_wdi3_gsi_evt_ring_err_cb", 29);
            v4 = ipa3_ctx;
          }
          v2 = *(_QWORD *)(v4 + 34160);
          if ( v2 )
            v3 = ipc_log_string(v2, "ipa %s:%d Got GSI_EVT_OUT_OF_RESOURCES_ERR\n", "ipa3_wdi3_gsi_evt_ring_err_cb", 29);
        }
        return ((__int64 (__fastcall *)(__int64, long double))ipa_assert)(v2, v3);
      }
      goto LABEL_16;
    }
    v2 = printk(&unk_3E3A9B, "ipa3_wdi3_gsi_evt_ring_err_cb");
    v11 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v12 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v12 )
      {
        v3 = ipc_log_string(v12, "ipa %s:%d Got GSI_EVT_OUT_OF_BUFFERS_ERR\n", "ipa3_wdi3_gsi_evt_ring_err_cb", 26);
        v11 = ipa3_ctx;
      }
      v2 = *(_QWORD *)(v11 + 34160);
      if ( v2 )
        v3 = ipc_log_string(v2, "ipa %s:%d Got GSI_EVT_OUT_OF_BUFFERS_ERR\n", "ipa3_wdi3_gsi_evt_ring_err_cb", 26);
    }
  }
  return ((__int64 (__fastcall *)(_QWORD, long double))ipa_assert)(v2, v3);
}
