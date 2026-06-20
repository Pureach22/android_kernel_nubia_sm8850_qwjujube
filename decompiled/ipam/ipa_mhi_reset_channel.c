__int64 __fastcall ipa_mhi_reset_channel(__int64 a1, char a2)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  unsigned int v6; // w21
  __int64 v7; // x0
  __int64 v8; // x0
  long double v9; // q0
  __int64 v10; // x0
  unsigned int v11; // w0
  __int64 v12; // x0
  long double v13; // q0
  __int64 v14; // x0
  unsigned int v15; // w0
  char v16; // w21
  __int64 v17; // x0
  long double v18; // q0
  __int64 v19; // x0
  unsigned int v20; // w0
  unsigned int v21; // w0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  long double v25; // q0
  __int64 v26; // x0
  unsigned int v27; // w0
  unsigned int v28; // w0
  __int64 v29; // x0
  __int64 v30; // x0
  unsigned int v31; // w0
  __int64 v32; // x0
  __int64 result; // x0
  __int64 v34; // x0
  unsigned int v35; // w19
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x0
  __int64 v46; // x0
  long double v47; // q0
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v51; // x0
  __int64 v52; // x0

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_reset_channel", 1184);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_reset_channel", 1184);
  }
  v6 = *(_DWORD *)(a1 + 4);
  v7 = ipa3_get_ipc_logbuf();
  if ( v6 <= 0x85 && (v6 & 1) == 0 )
  {
    if ( v7 )
    {
      v8 = ipa3_get_ipc_logbuf();
      ipc_log_string(v8, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_reset_ul_channel", 1106);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v10 = ipa3_get_ipc_logbuf_low();
      v9 = ipc_log_string(v10, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_reset_ul_channel", 1106);
    }
    v11 = ipa_mhi_suspend_gsi_channel(a1, v9);
    if ( v11 )
    {
      v35 = v11;
      printk(&unk_3D9DD1, "ipa_mhi_reset_ul_channel");
      if ( ipa3_get_ipc_logbuf() )
      {
        v38 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v38,
          "ipa_mhi_client %s:%d ipa_mhi_suspend_gsi_channel failed %d\n",
          "ipa_mhi_reset_ul_channel",
          1111,
          v35);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v39 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v39,
          "ipa_mhi_client %s:%d ipa_mhi_suspend_gsi_channel failed %d\n",
          "ipa_mhi_reset_ul_channel",
          1111,
          v35);
      }
      goto LABEL_75;
    }
    if ( (ipa_mhi_wait_for_ul_empty_timeout() & 1) != 0 )
      goto LABEL_24;
    if ( ipa3_get_ipc_logbuf() )
    {
      v12 = ipa3_get_ipc_logbuf();
      ipc_log_string(v12, "ipa_mhi_client %s:%d not empty\n", "ipa_mhi_reset_ul_channel", 1118);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v14 = ipa3_get_ipc_logbuf_low();
      v13 = ipc_log_string(v14, "ipa_mhi_client %s:%d not empty\n", "ipa_mhi_reset_ul_channel", 1118);
    }
    v15 = ((__int64 (__fastcall *)(_QWORD, long double))ipa_mhi_enable_force_clear)(
            *(unsigned int *)(ipa_mhi_client_ctx + 1296),
            v13);
    if ( v15 )
    {
      v35 = v15;
      printk(&unk_3D123E, "ipa_mhi_reset_ul_channel");
      if ( ipa3_get_ipc_logbuf() )
      {
        v46 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v46,
          "ipa_mhi_client %s:%d ipa_mhi_enable_force_clear failed %d\n",
          "ipa_mhi_reset_ul_channel",
          1123,
          v35);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v48 = ipa3_get_ipc_logbuf_low();
        v47 = ipc_log_string(
                v48,
                "ipa_mhi_client %s:%d ipa_mhi_enable_force_clear failed %d\n",
                "ipa_mhi_reset_ul_channel",
                1123,
                v35);
      }
    }
    else
    {
      v16 = ipa_mhi_wait_for_ul_empty_timeout();
      if ( ipa3_get_ipc_logbuf() )
      {
        v17 = ipa3_get_ipc_logbuf();
        ipc_log_string(v17, "ipa_mhi_client %s:%d empty=%d\n", "ipa_mhi_reset_ul_channel", 1130, v16 & 1);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v19 = ipa3_get_ipc_logbuf_low();
        v18 = ipc_log_string(v19, "ipa_mhi_client %s:%d empty=%d\n", "ipa_mhi_reset_ul_channel", 1130, v16 & 1);
      }
      v20 = ipa_mhi_disable_force_clear(*(unsigned int *)(ipa_mhi_client_ctx + 1296), v18);
      if ( !v20 )
      {
        ++*(_DWORD *)(ipa_mhi_client_ctx + 1296);
LABEL_24:
        v21 = ipa3_mhi_reset_channel_internal(*(unsigned int *)(a1 + 4));
        if ( !v21 )
        {
          if ( ipa3_get_ipc_logbuf() )
          {
            v22 = ipa3_get_ipc_logbuf();
            ipc_log_string(v22, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_reset_ul_channel", 1150);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v23 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v23, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_reset_ul_channel", 1150);
          }
          goto LABEL_39;
        }
        v35 = v21;
        printk(&unk_3D9E0F, "ipa_mhi_reset_ul_channel");
        if ( ipa3_get_ipc_logbuf() )
        {
          v42 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v42,
            "ipa_mhi_client %s:%d ipa_mhi_reset_ul_channel_internal failed %d\n",
            "ipa_mhi_reset_ul_channel",
            1146,
            v35);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v43 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v43,
            "ipa_mhi_client %s:%d ipa_mhi_reset_ul_channel_internal failed %d\n",
            "ipa_mhi_reset_ul_channel",
            1146,
            v35);
        }
LABEL_75:
        printk(&unk_3B97E3, "ipa_mhi_reset_channel");
        if ( ipa3_get_ipc_logbuf() )
        {
          v51 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v51,
            "ipa_mhi_client %s:%d failed to reset channel error %d\n",
            "ipa_mhi_reset_channel",
            1190,
            v35);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v52 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v52,
            "ipa_mhi_client %s:%d failed to reset channel error %d\n",
            "ipa_mhi_reset_channel",
            1190,
            v35);
        }
        return v35;
      }
      v35 = v20;
      printk(&unk_3A83C3, "ipa_mhi_reset_ul_channel");
      if ( ipa3_get_ipc_logbuf() )
      {
        v49 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v49,
          "ipa_mhi_client %s:%d ipa_mhi_disable_force_clear failed %d\n",
          "ipa_mhi_reset_ul_channel",
          1136,
          v35);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v50 = ipa3_get_ipc_logbuf_low();
        v47 = ipc_log_string(
                v50,
                "ipa_mhi_client %s:%d ipa_mhi_disable_force_clear failed %d\n",
                "ipa_mhi_reset_ul_channel",
                1136,
                v35);
      }
    }
    ((void (__fastcall *)(long double))ipa_assert)(v47);
    goto LABEL_75;
  }
  if ( v7 )
  {
    v24 = ipa3_get_ipc_logbuf();
    ipc_log_string(v24, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_reset_dl_channel", 1159);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v26 = ipa3_get_ipc_logbuf_low();
    v25 = ipc_log_string(v26, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_reset_dl_channel", 1159);
  }
  v27 = ipa_mhi_suspend_gsi_channel(a1, v25);
  if ( v27 )
  {
    v35 = v27;
    printk(&unk_3D9DD1, "ipa_mhi_reset_dl_channel");
    if ( ipa3_get_ipc_logbuf() )
    {
      v36 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v36,
        "ipa_mhi_client %s:%d ipa_mhi_suspend_gsi_channel failed %d\n",
        "ipa_mhi_reset_dl_channel",
        1163,
        v35);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v37 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v37,
        "ipa_mhi_client %s:%d ipa_mhi_suspend_gsi_channel failed %d\n",
        "ipa_mhi_reset_dl_channel",
        1163,
        v35);
    }
    goto LABEL_75;
  }
  v28 = ipa3_mhi_reset_channel_internal(*(unsigned int *)(a1 + 4));
  if ( v28 )
  {
    v35 = v28;
    printk(&unk_3D9E0F, "ipa_mhi_reset_dl_channel");
    if ( ipa3_get_ipc_logbuf() )
    {
      v40 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v40,
        "ipa_mhi_client %s:%d ipa_mhi_reset_ul_channel_internal failed %d\n",
        "ipa_mhi_reset_dl_channel",
        1171,
        v35);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v41 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v41,
        "ipa_mhi_client %s:%d ipa_mhi_reset_ul_channel_internal failed %d\n",
        "ipa_mhi_reset_dl_channel",
        1171,
        v35);
    }
    goto LABEL_75;
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v29 = ipa3_get_ipc_logbuf();
    ipc_log_string(v29, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_reset_dl_channel", 1175);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v30 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v30, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_reset_dl_channel", 1175);
  }
LABEL_39:
  *(_DWORD *)(a1 + 8) = 0;
  if ( (a2 & 1) != 0 )
  {
    v31 = ipa_mhi_read_write_host(0, (void *)(a1 + 8), *(_QWORD *)(a1 + 56), 1u);
    if ( v31 )
    {
      v35 = v31;
      printk(&unk_3EABAB, "ipa_mhi_reset_channel");
      if ( ipa3_get_ipc_logbuf() )
      {
        v44 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v44,
          "ipa_mhi_client %s:%d ipa_mhi_read_write_host failed %d\n",
          "ipa_mhi_reset_channel",
          1202,
          v35);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v45 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v45,
          "ipa_mhi_client %s:%d ipa_mhi_read_write_host failed %d\n",
          "ipa_mhi_reset_channel",
          1202,
          v35);
      }
      return v35;
    }
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v32 = ipa3_get_ipc_logbuf();
    ipc_log_string(v32, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_reset_channel", 1207);
  }
  result = ipa3_get_ipc_logbuf_low();
  if ( result )
  {
    v34 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v34, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_reset_channel", 1207);
    return 0;
  }
  return result;
}
