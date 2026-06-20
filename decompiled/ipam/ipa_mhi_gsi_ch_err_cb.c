__int64 __fastcall ipa_mhi_gsi_ch_err_cb(__int64 *a1)
{
  __int64 v1; // x20
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  int v5; // w3
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  long double v21; // q0
  __int64 v22; // x0

  v1 = *a1;
  printk(&unk_3AB3D5, "ipa_mhi_gsi_ch_err_cb");
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(
      ipc_logbuf,
      "ipa_mhi_client %s:%d channel id=%d client=%d state=%d\n",
      "ipa_mhi_gsi_ch_err_cb",
      914,
      *(unsigned __int8 *)(v1 + 1),
      *(_DWORD *)(v1 + 4),
      *(_DWORD *)(v1 + 8));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      ipc_logbuf_low,
      "ipa_mhi_client %s:%d channel id=%d client=%d state=%d\n",
      "ipa_mhi_gsi_ch_err_cb",
      914,
      *(unsigned __int8 *)(v1 + 1),
      *(_DWORD *)(v1 + 4),
      *(_DWORD *)(v1 + 8));
  }
  v5 = *((_DWORD *)a1 + 2);
  if ( v5 > 2 )
  {
    switch ( v5 )
    {
      case 3:
        printk(&unk_3A523D, "ipa_mhi_gsi_ch_err_cb");
        if ( ipa3_get_ipc_logbuf() )
        {
          v12 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v12,
            "ipa_mhi_client %s:%d Received GSI_CHAN_OUT_OF_RESOURCES_ERR\n",
            "ipa_mhi_gsi_ch_err_cb",
            926);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v13 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v13,
            "ipa_mhi_client %s:%d Received GSI_CHAN_OUT_OF_RESOURCES_ERR\n",
            "ipa_mhi_gsi_ch_err_cb",
            926);
        }
        break;
      case 4:
        printk(&unk_3A837D, "ipa_mhi_gsi_ch_err_cb");
        if ( ipa3_get_ipc_logbuf() )
        {
          v18 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v18,
            "ipa_mhi_client %s:%d Received GSI_CHAN_UNSUPPORTED_INTER_EE_OP_ERR\n",
            "ipa_mhi_gsi_ch_err_cb",
            929);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v19 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v19,
            "ipa_mhi_client %s:%d Received GSI_CHAN_UNSUPPORTED_INTER_EE_OP_ERR\n",
            "ipa_mhi_gsi_ch_err_cb",
            929);
        }
        break;
      case 5:
        printk(&unk_3D712E, "ipa_mhi_gsi_ch_err_cb");
        if ( ipa3_get_ipc_logbuf() )
        {
          v8 = ipa3_get_ipc_logbuf();
          ipc_log_string(v8, "ipa_mhi_client %s:%d Received GSI_CHAN_HWO_1_ERR\n", "ipa_mhi_gsi_ch_err_cb", 932);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v9 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v9, "ipa_mhi_client %s:%d Received GSI_CHAN_HWO_1_ERR\n", "ipa_mhi_gsi_ch_err_cb", 932);
        }
        break;
      default:
LABEL_28:
        printk(&unk_3A527C, "ipa_mhi_gsi_ch_err_cb");
        if ( ipa3_get_ipc_logbuf() )
        {
          v14 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v14,
            "ipa_mhi_client %s:%d Unexpected err evt: %d\n",
            "ipa_mhi_gsi_ch_err_cb",
            935,
            *((_DWORD *)a1 + 2));
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v15 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v15,
            "ipa_mhi_client %s:%d Unexpected err evt: %d\n",
            "ipa_mhi_gsi_ch_err_cb",
            935,
            *((_DWORD *)a1 + 2));
        }
        break;
    }
  }
  else if ( v5 )
  {
    if ( v5 != 1 )
    {
      if ( v5 == 2 )
      {
        printk(&unk_3EABFB, "ipa_mhi_gsi_ch_err_cb");
        if ( ipa3_get_ipc_logbuf() )
        {
          v6 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v6,
            "ipa_mhi_client %s:%d Received GSI_CHAN_OUT_OF_BUFFERS_ERR\n",
            "ipa_mhi_gsi_ch_err_cb",
            923);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v7 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v7,
            "ipa_mhi_client %s:%d Received GSI_CHAN_OUT_OF_BUFFERS_ERR\n",
            "ipa_mhi_gsi_ch_err_cb",
            923);
        }
        goto LABEL_40;
      }
      goto LABEL_28;
    }
    printk(&unk_3BF4FE, "ipa_mhi_gsi_ch_err_cb");
    if ( ipa3_get_ipc_logbuf() )
    {
      v16 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v16,
        "ipa_mhi_client %s:%d Received GSI_CHAN_NON_ALLOCATED_EVT_ACCESS_ERR\n",
        "ipa_mhi_gsi_ch_err_cb",
        920);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v17 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v17,
        "ipa_mhi_client %s:%d Received GSI_CHAN_NON_ALLOCATED_EVT_ACCESS_ERR\n",
        "ipa_mhi_gsi_ch_err_cb",
        920);
    }
  }
  else
  {
    printk(&unk_3D9CF8, "ipa_mhi_gsi_ch_err_cb");
    if ( ipa3_get_ipc_logbuf() )
    {
      v10 = ipa3_get_ipc_logbuf();
      ipc_log_string(v10, "ipa_mhi_client %s:%d Received GSI_CHAN_INVALID_TRE_ERR\n", "ipa_mhi_gsi_ch_err_cb", 917);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v11 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v11, "ipa_mhi_client %s:%d Received GSI_CHAN_INVALID_TRE_ERR\n", "ipa_mhi_gsi_ch_err_cb", 917);
    }
  }
LABEL_40:
  printk(&unk_3D9D32, "ipa_mhi_gsi_ch_err_cb");
  if ( ipa3_get_ipc_logbuf() )
  {
    v20 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v20,
      "ipa_mhi_client %s:%d err_desc=0x%x\n",
      "ipa_mhi_gsi_ch_err_cb",
      937,
      *((unsigned __int16 *)a1 + 6));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v22 = ipa3_get_ipc_logbuf_low();
    v21 = ipc_log_string(
            v22,
            "ipa_mhi_client %s:%d err_desc=0x%x\n",
            "ipa_mhi_gsi_ch_err_cb",
            937,
            *((unsigned __int16 *)a1 + 6));
  }
  return ((__int64 (__fastcall *)(long double))ipa_assert)(v21);
}
