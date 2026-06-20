void __fastcall ipa_mhi_update_host_ch_state(char a1, long double a2)
{
  unsigned __int64 *v3; // x20
  __int64 ipc_logbuf; // x0
  __int64 v5; // x8
  const char *v6; // x5
  __int64 ipc_logbuf_low; // x0
  __int64 v8; // x8
  const char *v9; // x5
  unsigned __int64 *v10; // x20
  __int64 v11; // x0
  __int64 v12; // x8
  const char *v13; // x5
  __int64 v14; // x0
  __int64 v15; // x8
  const char *v16; // x5
  int v17; // w20
  __int64 v18; // x27
  __int64 v19; // x23
  unsigned __int64 v20; // x2
  unsigned int *v21; // x23
  __int64 v22; // x0
  __int64 v23; // x8
  const char *v24; // x5
  __int64 v25; // x0
  __int64 v26; // x8
  const char *v27; // x5
  __int64 v28; // x0
  long double v29; // q0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x0

  v3 = (unsigned __int64 *)ipa_mhi_client_ctx;
  if ( *(_BYTE *)(ipa_mhi_client_ctx + 40) == 1 )
  {
    if ( (a1 & 1) != 0 )
    {
      if ( (unsigned int)((__int64 (__fastcall *)(_QWORD, __int64))ipa3_mhi_query_ch_info)(
                           *(unsigned int *)(ipa_mhi_client_ctx + 44),
                           ipa_mhi_client_ctx + 56) )
        goto LABEL_50;
      if ( (unsigned int)ipa_mhi_read_write_host(0, v3 + 8, v3[12] + 28, 8u) )
        goto LABEL_58;
    }
    if ( (unsigned int)ipa_mhi_read_write_host(0, v3 + 6, v3[12], 1u) )
      goto LABEL_46;
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      v5 = *((unsigned int *)v3 + 12);
      if ( (unsigned int)v5 > 5 )
        v6 = "INVALID";
      else
        v6 = ipa_mhi_channel_state_str[v5];
      ipc_log_string(
        ipc_logbuf,
        "ipa_mhi_client %s:%d Updated UL CH=%d state to %s on host\n",
        "ipa_mhi_update_host_ch_state",
        1777,
        0,
        v6);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      v8 = *((unsigned int *)v3 + 12);
      if ( (unsigned int)v8 > 5 )
        v9 = "INVALID";
      else
        v9 = ipa_mhi_channel_state_str[v8];
      a2 = ipc_log_string(
             ipc_logbuf_low,
             "ipa_mhi_client %s:%d Updated UL CH=%d state to %s on host\n",
             "ipa_mhi_update_host_ch_state",
             1777,
             0,
             v9);
    }
  }
  v10 = (unsigned __int64 *)ipa_mhi_client_ctx;
  if ( *(_BYTE *)(ipa_mhi_client_ctx + 240) == 1 )
  {
    if ( (a1 & 1) == 0 )
      goto LABEL_20;
    if ( !(unsigned int)((__int64 (__fastcall *)(_QWORD, __int64, long double))ipa3_mhi_query_ch_info)(
                          *(unsigned int *)(ipa_mhi_client_ctx + 244),
                          ipa_mhi_client_ctx + 256,
                          a2) )
    {
      if ( !(unsigned int)ipa_mhi_read_write_host(0, v10 + 33, v10[37] + 28, 8u) )
      {
LABEL_20:
        if ( !(unsigned int)ipa_mhi_read_write_host(0, v10 + 31, v10[37], 1u) )
        {
          if ( ipa3_get_ipc_logbuf() )
          {
            v11 = ipa3_get_ipc_logbuf();
            v12 = *((unsigned int *)v10 + 62);
            if ( (unsigned int)v12 > 5 )
              v13 = "INVALID";
            else
              v13 = ipa_mhi_channel_state_str[v12];
            ipc_log_string(
              v11,
              "ipa_mhi_client %s:%d Updated UL CH=%d state to %s on host\n",
              "ipa_mhi_update_host_ch_state",
              1777,
              1,
              v13);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v14 = ipa3_get_ipc_logbuf_low();
            v15 = *((unsigned int *)v10 + 62);
            if ( (unsigned int)v15 > 5 )
              v16 = "INVALID";
            else
              v16 = ipa_mhi_channel_state_str[v15];
            a2 = ipc_log_string(
                   v14,
                   "ipa_mhi_client %s:%d Updated UL CH=%d state to %s on host\n",
                   "ipa_mhi_update_host_ch_state",
                   1777,
                   1,
                   v16);
          }
          goto LABEL_31;
        }
LABEL_46:
        printk(&unk_3F64BC, "ipa_mhi_update_host_ch_state");
        if ( ipa3_get_ipc_logbuf() )
        {
          v28 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v28,
            "ipa_mhi_client %s:%d ipa_mhi_read_write_host failed\n",
            "ipa_mhi_update_host_ch_state",
            1772);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v30 = ipa3_get_ipc_logbuf_low();
          v29 = ipc_log_string(
                  v30,
                  "ipa_mhi_client %s:%d ipa_mhi_read_write_host failed\n",
                  "ipa_mhi_update_host_ch_state",
                  1772);
        }
        goto LABEL_70;
      }
LABEL_58:
      printk(&unk_3F64BC, "ipa_mhi_update_host_ch_state");
      if ( ipa3_get_ipc_logbuf() )
      {
        v35 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v35,
          "ipa_mhi_client %s:%d ipa_mhi_read_write_host failed\n",
          "ipa_mhi_update_host_ch_state",
          1761);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v36 = ipa3_get_ipc_logbuf_low();
        v29 = ipc_log_string(
                v36,
                "ipa_mhi_client %s:%d ipa_mhi_read_write_host failed\n",
                "ipa_mhi_update_host_ch_state",
                1761);
      }
      goto LABEL_70;
    }
LABEL_50:
    printk(&unk_3A52AB, "ipa_mhi_update_host_ch_state");
    if ( ipa3_get_ipc_logbuf() )
    {
      v31 = ipa3_get_ipc_logbuf();
      ipc_log_string(v31, "ipa_mhi_client %s:%d gsi_query_channel_info failed\n", "ipa_mhi_update_host_ch_state", 1750);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v32 = ipa3_get_ipc_logbuf_low();
      v29 = ipc_log_string(
              v32,
              "ipa_mhi_client %s:%d gsi_query_channel_info failed\n",
              "ipa_mhi_update_host_ch_state",
              1750);
    }
    goto LABEL_70;
  }
LABEL_31:
  v17 = 0;
  v18 = -800;
  while ( 1 )
  {
    v19 = ipa_mhi_client_ctx;
    if ( *(_BYTE *)(ipa_mhi_client_ctx + v18 + 1240) != 1 )
      goto LABEL_33;
    if ( (a1 & 1) != 0 )
      break;
LABEL_38:
    v20 = *(_QWORD *)(v19 + v18 + 1296);
    v21 = (unsigned int *)(v19 + v18 + 1248);
    if ( (unsigned int)ipa_mhi_read_write_host(0, v21, v20, 1u) )
    {
      printk(&unk_3F64BC, "ipa_mhi_update_host_ch_state");
      if ( ipa3_get_ipc_logbuf() )
      {
        v33 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v33,
          "ipa_mhi_client %s:%d ipa_mhi_read_write_host failed\n",
          "ipa_mhi_update_host_ch_state",
          1811);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v34 = ipa3_get_ipc_logbuf_low();
        v29 = ipc_log_string(
                v34,
                "ipa_mhi_client %s:%d ipa_mhi_read_write_host failed\n",
                "ipa_mhi_update_host_ch_state",
                1811);
      }
      goto LABEL_70;
    }
    if ( ipa3_get_ipc_logbuf() )
    {
      v22 = ipa3_get_ipc_logbuf();
      v23 = *v21;
      v24 = "INVALID";
      if ( (unsigned int)v23 <= 5 )
        v24 = ipa_mhi_channel_state_str[v23];
      ipc_log_string(
        v22,
        "ipa_mhi_client %s:%d Updated DL CH=%d state to %s on host\n",
        "ipa_mhi_update_host_ch_state",
        1816,
        v17,
        v24);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v25 = ipa3_get_ipc_logbuf_low();
      v26 = *v21;
      v27 = "INVALID";
      if ( (unsigned int)v26 <= 5 )
        v27 = ipa_mhi_channel_state_str[v26];
      a2 = ipc_log_string(
             v25,
             "ipa_mhi_client %s:%d Updated DL CH=%d state to %s on host\n",
             "ipa_mhi_update_host_ch_state",
             1816,
             v17,
             v27);
    }
LABEL_33:
    v18 += 200;
    ++v17;
    if ( !v18 )
      return;
  }
  if ( !(unsigned int)((__int64 (__fastcall *)(_QWORD, __int64, long double))ipa3_mhi_query_ch_info)(
                        *(unsigned int *)(ipa_mhi_client_ctx + v18 + 1244),
                        ipa_mhi_client_ctx + v18 + 1256,
                        a2) )
  {
    if ( (unsigned int)ipa_mhi_read_write_host(0, (void *)(v19 + v18 + 1264), *(_QWORD *)(v19 + v18 + 1296) + 28LL, 8u) )
    {
      printk(&unk_3F64BC, "ipa_mhi_update_host_ch_state");
      if ( ipa3_get_ipc_logbuf() )
      {
        v39 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v39,
          "ipa_mhi_client %s:%d ipa_mhi_read_write_host failed\n",
          "ipa_mhi_update_host_ch_state",
          1800);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v40 = ipa3_get_ipc_logbuf_low();
        v29 = ipc_log_string(
                v40,
                "ipa_mhi_client %s:%d ipa_mhi_read_write_host failed\n",
                "ipa_mhi_update_host_ch_state",
                1800);
      }
      goto LABEL_70;
    }
    goto LABEL_38;
  }
  printk(&unk_3A52AB, "ipa_mhi_update_host_ch_state");
  if ( ipa3_get_ipc_logbuf() )
  {
    v37 = ipa3_get_ipc_logbuf();
    ipc_log_string(v37, "ipa_mhi_client %s:%d gsi_query_channel_info failed\n", "ipa_mhi_update_host_ch_state", 1789);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v38 = ipa3_get_ipc_logbuf_low();
    v29 = ipc_log_string(
            v38,
            "ipa_mhi_client %s:%d gsi_query_channel_info failed\n",
            "ipa_mhi_update_host_ch_state",
            1789);
  }
LABEL_70:
  ((void (__fastcall *)(long double))ipa_assert)(v29);
}
