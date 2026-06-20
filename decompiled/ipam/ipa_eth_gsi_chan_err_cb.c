__int64 __fastcall ipa_eth_gsi_chan_err_cb(__int64 a1)
{
  int v1; // w3
  __int64 v2; // x0
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x8
  __int64 v17; // x0

  v1 = *(_DWORD *)(a1 + 8);
  if ( v1 > 2 )
  {
    switch ( v1 )
    {
      case 3:
        v2 = printk(&unk_3D2934, "ipa_eth_gsi_chan_err_cb");
        v9 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v10 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v10 )
          {
            ipc_log_string(v10, "ipa %s:%d Got GSI_CHAN_OUT_OF_RESOURCES_ERR\n", "ipa_eth_gsi_chan_err_cb", 291);
            v9 = ipa3_ctx;
          }
          v2 = *(_QWORD *)(v9 + 34160);
          if ( v2 )
            v2 = ipc_log_string(v2, "ipa %s:%d Got GSI_CHAN_OUT_OF_RESOURCES_ERR\n", "ipa_eth_gsi_chan_err_cb", 291);
        }
        break;
      case 4:
        v2 = printk(&unk_3BB098, "ipa_eth_gsi_chan_err_cb");
        v16 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v17 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v17 )
          {
            ipc_log_string(v17, "ipa %s:%d Got GSI_CHAN_UNSUPPORTED_INTER_EE_OP_ERR\n", "ipa_eth_gsi_chan_err_cb", 294);
            v16 = ipa3_ctx;
          }
          v2 = *(_QWORD *)(v16 + 34160);
          if ( v2 )
            v2 = ipc_log_string(
                   v2,
                   "ipa %s:%d Got GSI_CHAN_UNSUPPORTED_INTER_EE_OP_ERR\n",
                   "ipa_eth_gsi_chan_err_cb",
                   294);
        }
        break;
      case 5:
        v2 = printk(&unk_3F5243, "ipa_eth_gsi_chan_err_cb");
        v5 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v6 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v6 )
          {
            ipc_log_string(v6, "ipa %s:%d Got GSI_CHAN_HWO_1_ERR\n", "ipa_eth_gsi_chan_err_cb", 297);
            v5 = ipa3_ctx;
          }
          v2 = *(_QWORD *)(v5 + 34160);
          if ( v2 )
            v2 = ipc_log_string(v2, "ipa %s:%d Got GSI_CHAN_HWO_1_ERR\n", "ipa_eth_gsi_chan_err_cb", 297);
        }
        break;
      default:
LABEL_28:
        v2 = printk(&unk_3C9A50, "ipa_eth_gsi_chan_err_cb");
        v12 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v13 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v13 )
          {
            ipc_log_string(
              v13,
              "ipa %s:%d Unexpected err evt: %d\n",
              "ipa_eth_gsi_chan_err_cb",
              300,
              *(_DWORD *)(a1 + 8));
            v12 = ipa3_ctx;
          }
          v2 = *(_QWORD *)(v12 + 34160);
          if ( v2 )
            v2 = ipc_log_string(
                   v2,
                   "ipa %s:%d Unexpected err evt: %d\n",
                   "ipa_eth_gsi_chan_err_cb",
                   300,
                   *(_DWORD *)(a1 + 8));
        }
        return ((__int64 (__fastcall *)(__int64))ipa_assert)(v2);
    }
  }
  else if ( v1 )
  {
    if ( v1 != 1 )
    {
      if ( v1 == 2 )
      {
        v2 = printk(&unk_3E0E65, "ipa_eth_gsi_chan_err_cb");
        v3 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v4 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v4 )
          {
            ipc_log_string(v4, "ipa %s:%d Got GSI_CHAN_OUT_OF_BUFFERS_ERR\n", "ipa_eth_gsi_chan_err_cb", 288);
            v3 = ipa3_ctx;
          }
          v2 = *(_QWORD *)(v3 + 34160);
          if ( v2 )
            v2 = ipc_log_string(v2, "ipa %s:%d Got GSI_CHAN_OUT_OF_BUFFERS_ERR\n", "ipa_eth_gsi_chan_err_cb", 288);
        }
        return ((__int64 (__fastcall *)(__int64))ipa_assert)(v2);
      }
      goto LABEL_28;
    }
    v2 = printk(&unk_3FDE8E, "ipa_eth_gsi_chan_err_cb");
    v14 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v15 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v15 )
      {
        ipc_log_string(v15, "ipa %s:%d Got GSI_CHAN_NON_ALLOCATED_EVT_ACCESS_ERR\n", "ipa_eth_gsi_chan_err_cb", 285);
        v14 = ipa3_ctx;
      }
      v2 = *(_QWORD *)(v14 + 34160);
      if ( v2 )
        v2 = ipc_log_string(v2, "ipa %s:%d Got GSI_CHAN_NON_ALLOCATED_EVT_ACCESS_ERR\n", "ipa_eth_gsi_chan_err_cb", 285);
    }
  }
  else
  {
    v2 = printk(&unk_3F7F94, "ipa_eth_gsi_chan_err_cb");
    v7 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v8 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v8 )
      {
        ipc_log_string(v8, "ipa %s:%d Got GSI_CHAN_INVALID_TRE_ERR\n", "ipa_eth_gsi_chan_err_cb", 282);
        v7 = ipa3_ctx;
      }
      v2 = *(_QWORD *)(v7 + 34160);
      if ( v2 )
        v2 = ipc_log_string(v2, "ipa %s:%d Got GSI_CHAN_INVALID_TRE_ERR\n", "ipa_eth_gsi_chan_err_cb", 282);
    }
  }
  return ((__int64 (__fastcall *)(_QWORD))ipa_assert)(v2);
}
