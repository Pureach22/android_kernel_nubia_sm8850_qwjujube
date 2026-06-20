__int64 __fastcall ipa_gsi_evt_ring_err_cb_0(__int64 a1)
{
  int v1; // w3
  __int64 v2; // x0
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x0

  v1 = *(_DWORD *)(a1 + 8);
  if ( v1 > 1 )
  {
    if ( v1 == 2 )
    {
      v2 = printk(&unk_3F20AC, "ipa_gsi_evt_ring_err_cb");
      v12 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v13 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v13 )
        {
          ipc_log_string(v13, "ipa %s:%d Got GSI_EVT_UNSUPPORTED_INTER_EE_OP_ERR\n", "ipa_gsi_evt_ring_err_cb", 1067);
          v12 = ipa3_ctx;
        }
        v2 = *(_QWORD *)(v12 + 34160);
        if ( v2 )
          v2 = ipc_log_string(
                 v2,
                 "ipa %s:%d Got GSI_EVT_UNSUPPORTED_INTER_EE_OP_ERR\n",
                 "ipa_gsi_evt_ring_err_cb",
                 1067);
      }
    }
    else
    {
      if ( v1 != 3 )
      {
LABEL_16:
        v2 = printk(&unk_3C9A50, "ipa_gsi_evt_ring_err_cb");
        v8 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v9 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v9 )
          {
            ipc_log_string(
              v9,
              "ipa %s:%d Unexpected err evt: %d\n",
              "ipa_gsi_evt_ring_err_cb",
              1073,
              *(_DWORD *)(a1 + 8));
            v8 = ipa3_ctx;
          }
          v2 = *(_QWORD *)(v8 + 34160);
          if ( v2 )
            v2 = ipc_log_string(
                   v2,
                   "ipa %s:%d Unexpected err evt: %d\n",
                   "ipa_gsi_evt_ring_err_cb",
                   1073,
                   *(_DWORD *)(a1 + 8));
        }
        return ((__int64 (__fastcall *)(__int64))ipa_assert)(v2);
      }
      v2 = printk(&unk_3A6B54, "ipa_gsi_evt_ring_err_cb");
      v5 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v6 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v6 )
        {
          ipc_log_string(v6, "ipa %s:%d Got GSI_EVT_EVT_RING_EMPTY_ERR\n", "ipa_gsi_evt_ring_err_cb", 1070);
          v5 = ipa3_ctx;
        }
        v2 = *(_QWORD *)(v5 + 34160);
        if ( v2 )
          v2 = ipc_log_string(v2, "ipa %s:%d Got GSI_EVT_EVT_RING_EMPTY_ERR\n", "ipa_gsi_evt_ring_err_cb", 1070);
      }
    }
  }
  else
  {
    if ( v1 )
    {
      if ( v1 == 1 )
      {
        v2 = printk(&unk_3CF9B1, "ipa_gsi_evt_ring_err_cb");
        v3 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v4 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v4 )
          {
            ipc_log_string(v4, "ipa %s:%d Got GSI_EVT_OUT_OF_RESOURCES_ERR\n", "ipa_gsi_evt_ring_err_cb", 1064);
            v3 = ipa3_ctx;
          }
          v2 = *(_QWORD *)(v3 + 34160);
          if ( v2 )
            v2 = ipc_log_string(v2, "ipa %s:%d Got GSI_EVT_OUT_OF_RESOURCES_ERR\n", "ipa_gsi_evt_ring_err_cb", 1064);
        }
        return ((__int64 (__fastcall *)(__int64))ipa_assert)(v2);
      }
      goto LABEL_16;
    }
    v2 = printk(&unk_3E3A9B, "ipa_gsi_evt_ring_err_cb");
    v10 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v11 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v11 )
      {
        ipc_log_string(v11, "ipa %s:%d Got GSI_EVT_OUT_OF_BUFFERS_ERR\n", "ipa_gsi_evt_ring_err_cb", 1061);
        v10 = ipa3_ctx;
      }
      v2 = *(_QWORD *)(v10 + 34160);
      if ( v2 )
        v2 = ipc_log_string(v2, "ipa %s:%d Got GSI_EVT_OUT_OF_BUFFERS_ERR\n", "ipa_gsi_evt_ring_err_cb", 1061);
    }
  }
  return ((__int64 (__fastcall *)(_QWORD))ipa_assert)(v2);
}
