__int64 __fastcall ipa_gsi_chan_err_cb_1(__int64 a1)
{
  int v1; // w3
  __int64 v2; // x0
  long double v3; // q0
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x8
  __int64 v18; // x0

  v1 = *(_DWORD *)(a1 + 8);
  if ( v1 > 2 )
  {
    switch ( v1 )
    {
      case 3:
        v2 = printk(&unk_3D2934, "ipa_gsi_chan_err_cb");
        v10 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v11 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v11 )
          {
            v3 = ipc_log_string(v11, "ipa %s:%d Got GSI_CHAN_OUT_OF_RESOURCES_ERR\n", "ipa_gsi_chan_err_cb", 571);
            v10 = ipa3_ctx;
          }
          v2 = *(_QWORD *)(v10 + 34160);
          if ( v2 )
            v3 = ipc_log_string(v2, "ipa %s:%d Got GSI_CHAN_OUT_OF_RESOURCES_ERR\n", "ipa_gsi_chan_err_cb", 571);
        }
        break;
      case 4:
        v2 = printk(&unk_3BB098, "ipa_gsi_chan_err_cb");
        v17 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v18 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v18 )
          {
            v3 = ipc_log_string(v18, "ipa %s:%d Got GSI_CHAN_UNSUPPORTED_INTER_EE_OP_ERR\n", "ipa_gsi_chan_err_cb", 574);
            v17 = ipa3_ctx;
          }
          v2 = *(_QWORD *)(v17 + 34160);
          if ( v2 )
            v3 = ipc_log_string(v2, "ipa %s:%d Got GSI_CHAN_UNSUPPORTED_INTER_EE_OP_ERR\n", "ipa_gsi_chan_err_cb", 574);
        }
        break;
      case 5:
        v2 = printk(&unk_3F5243, "ipa_gsi_chan_err_cb");
        v6 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v7 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v7 )
          {
            v3 = ipc_log_string(v7, "ipa %s:%d Got GSI_CHAN_HWO_1_ERR\n", "ipa_gsi_chan_err_cb", 577);
            v6 = ipa3_ctx;
          }
          v2 = *(_QWORD *)(v6 + 34160);
          if ( v2 )
            v3 = ipc_log_string(v2, "ipa %s:%d Got GSI_CHAN_HWO_1_ERR\n", "ipa_gsi_chan_err_cb", 577);
        }
        break;
      default:
LABEL_28:
        v2 = printk(&unk_3C9A50, "ipa_gsi_chan_err_cb");
        v13 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v14 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v14 )
          {
            v3 = ipc_log_string(
                   v14,
                   "ipa %s:%d Unexpected err evt: %d\n",
                   "ipa_gsi_chan_err_cb",
                   580,
                   *(_DWORD *)(a1 + 8));
            v13 = ipa3_ctx;
          }
          v2 = *(_QWORD *)(v13 + 34160);
          if ( v2 )
            v3 = ipc_log_string(
                   v2,
                   "ipa %s:%d Unexpected err evt: %d\n",
                   "ipa_gsi_chan_err_cb",
                   580,
                   *(_DWORD *)(a1 + 8));
        }
        return ((__int64 (__fastcall *)(__int64, long double))ipa_assert)(v2, v3);
    }
  }
  else if ( v1 )
  {
    if ( v1 != 1 )
    {
      if ( v1 == 2 )
      {
        v2 = printk(&unk_3E0E65, "ipa_gsi_chan_err_cb");
        v4 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v5 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v5 )
          {
            v3 = ipc_log_string(v5, "ipa %s:%d Got GSI_CHAN_OUT_OF_BUFFERS_ERR\n", "ipa_gsi_chan_err_cb", 568);
            v4 = ipa3_ctx;
          }
          v2 = *(_QWORD *)(v4 + 34160);
          if ( v2 )
            v3 = ipc_log_string(v2, "ipa %s:%d Got GSI_CHAN_OUT_OF_BUFFERS_ERR\n", "ipa_gsi_chan_err_cb", 568);
        }
        return ((__int64 (__fastcall *)(__int64, long double))ipa_assert)(v2, v3);
      }
      goto LABEL_28;
    }
    v2 = printk(&unk_3FDE8E, "ipa_gsi_chan_err_cb");
    v15 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v16 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v16 )
      {
        v3 = ipc_log_string(v16, "ipa %s:%d Got GSI_CHAN_NON_ALLOCATED_EVT_ACCESS_ERR\n", "ipa_gsi_chan_err_cb", 565);
        v15 = ipa3_ctx;
      }
      v2 = *(_QWORD *)(v15 + 34160);
      if ( v2 )
        v3 = ipc_log_string(v2, "ipa %s:%d Got GSI_CHAN_NON_ALLOCATED_EVT_ACCESS_ERR\n", "ipa_gsi_chan_err_cb", 565);
    }
  }
  else
  {
    v2 = printk(&unk_3F7F94, "ipa_gsi_chan_err_cb");
    v8 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v9 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v9 )
      {
        v3 = ipc_log_string(v9, "ipa %s:%d Got GSI_CHAN_INVALID_TRE_ERR\n", "ipa_gsi_chan_err_cb", 562);
        v8 = ipa3_ctx;
      }
      v2 = *(_QWORD *)(v8 + 34160);
      if ( v2 )
        v3 = ipc_log_string(v2, "ipa %s:%d Got GSI_CHAN_INVALID_TRE_ERR\n", "ipa_gsi_chan_err_cb", 562);
    }
  }
  return ((__int64 (__fastcall *)(_QWORD, long double))ipa_assert)(v2, v3);
}
