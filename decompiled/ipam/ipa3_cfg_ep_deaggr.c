__int64 __fastcall ipa3_cfg_ep_deaggr(unsigned int a1, _DWORD *a2)
{
  __int64 v3; // x8
  unsigned int v4; // w22
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
  __int64 v16; // x10
  __int64 v17; // x11
  __int64 v18; // x8
  __int64 v19; // x20
  __int64 result; // x0
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x8
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x8
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x8
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x8
  __int64 v34; // x0
  __int64 v35; // x0

  _ReadStatusReg(SP_EL0);
  v3 = ipa3_ctx;
  if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
  {
    if ( a1 <= 0x23 )
    {
      v4 = a1;
      goto LABEL_36;
    }
LABEL_66:
    __break(0x5512u);
  }
  if ( a1 >= 0x24 )
    goto LABEL_66;
  v4 = a1;
  if ( a2 && *(_DWORD *)(ipa3_ctx + 480LL * a1 + 168) )
  {
    if ( ipa3_ctx )
    {
      v6 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v6 )
      {
        ipc_log_string(v6, "ipa %s:%d pipe=%d deaggr_hdr_len=%d\n", "ipa3_cfg_ep_deaggr", 9991, a1, *a2);
        v3 = ipa3_ctx;
      }
      v7 = *(_QWORD *)(v3 + 34160);
      if ( v7 )
      {
        ipc_log_string(v7, "ipa %s:%d pipe=%d deaggr_hdr_len=%d\n", "ipa3_cfg_ep_deaggr", 9991, a1, *a2);
        v3 = ipa3_ctx;
      }
      if ( v3 )
      {
        v8 = *(_QWORD *)(v3 + 34152);
        if ( v8 )
        {
          ipc_log_string(
            v8,
            "ipa %s:%d syspipe_err_detection=%d\n",
            "ipa3_cfg_ep_deaggr",
            9994,
            *((unsigned __int8 *)a2 + 4));
          v3 = ipa3_ctx;
        }
        v9 = *(_QWORD *)(v3 + 34160);
        if ( v9 )
        {
          ipc_log_string(
            v9,
            "ipa %s:%d syspipe_err_detection=%d\n",
            "ipa3_cfg_ep_deaggr",
            9994,
            *((unsigned __int8 *)a2 + 4));
          v3 = ipa3_ctx;
        }
        if ( v3 )
        {
          v10 = *(_QWORD *)(v3 + 34152);
          if ( v10 )
          {
            ipc_log_string(
              v10,
              "ipa %s:%d packet_offset_valid=%d\n",
              "ipa3_cfg_ep_deaggr",
              9997,
              *((unsigned __int8 *)a2 + 5));
            v3 = ipa3_ctx;
          }
          v11 = *(_QWORD *)(v3 + 34160);
          if ( v11 )
          {
            ipc_log_string(
              v11,
              "ipa %s:%d packet_offset_valid=%d\n",
              "ipa3_cfg_ep_deaggr",
              9997,
              *((unsigned __int8 *)a2 + 5));
            v3 = ipa3_ctx;
          }
          if ( v3 )
          {
            v12 = *(_QWORD *)(v3 + 34152);
            if ( v12 )
            {
              ipc_log_string(
                v12,
                "ipa %s:%d packet_offset_location=%d max_packet_len=%d\n",
                "ipa3_cfg_ep_deaggr",
                10001,
                a2[2],
                a2[4]);
              v3 = ipa3_ctx;
            }
            v13 = *(_QWORD *)(v3 + 34160);
            if ( v13 )
            {
              ipc_log_string(
                v13,
                "ipa %s:%d packet_offset_location=%d max_packet_len=%d\n",
                "ipa3_cfg_ep_deaggr",
                10001,
                a2[2],
                a2[4]);
              v3 = ipa3_ctx;
            }
            if ( v3 )
            {
              v14 = *(_QWORD *)(v3 + 34152);
              if ( v14 )
              {
                ipc_log_string(
                  v14,
                  "ipa %s:%d ignore_min_pkt_err=%d\n",
                  "ipa3_cfg_ep_deaggr",
                  10004,
                  *((unsigned __int8 *)a2 + 12));
                v3 = ipa3_ctx;
              }
              v15 = *(_QWORD *)(v3 + 34160);
              if ( v15 )
              {
                ipc_log_string(
                  v15,
                  "ipa %s:%d ignore_min_pkt_err=%d\n",
                  "ipa3_cfg_ep_deaggr",
                  10004,
                  *((unsigned __int8 *)a2 + 12));
                v3 = ipa3_ctx;
              }
            }
          }
        }
      }
    }
    v16 = *(_QWORD *)a2;
    v17 = *((_QWORD *)a2 + 1);
    v18 = v3 + 480LL * a1;
    *(_DWORD *)(v18 + 452) = a2[4];
    *(_QWORD *)(v18 + 436) = v16;
    v19 = v18 + 436;
    *(_QWORD *)(v18 + 444) = v17;
    if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
    {
      printk(&unk_3E7136, "ipa3_get_client_mapping");
      v24 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v25 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v25 )
        {
          ipc_log_string(v25, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
          v24 = ipa3_ctx;
        }
        v26 = *(_QWORD *)(v24 + 34160);
        if ( v26 )
          ipc_log_string(v26, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
      }
      __break(0x800u);
      if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
      {
        printk(&unk_3E7136, "ipa3_get_client_mapping");
        v27 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v28 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v28 )
          {
            ipc_log_string(v28, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
            v27 = ipa3_ctx;
          }
          v29 = *(_QWORD *)(v27 + 34160);
          if ( v29 )
            ipc_log_string(v29, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
        }
        __break(0x800u);
      }
    }
    ipa3_inc_client_enable_clks();
    ((void (__fastcall *)(__int64, _QWORD, __int64))ipahal_write_reg_n_fields)(54, a1, v19);
    if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
    {
      printk(&unk_3E7136, "ipa3_get_client_mapping");
      v30 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v31 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v31 )
        {
          ipc_log_string(v31, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
          v30 = ipa3_ctx;
        }
        v32 = *(_QWORD *)(v30 + 34160);
        if ( v32 )
          ipc_log_string(v32, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
      }
      __break(0x800u);
      if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
      {
        printk(&unk_3E7136, "ipa3_get_client_mapping");
        v33 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v34 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v34 )
          {
            ipc_log_string(v34, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
            v33 = ipa3_ctx;
          }
          v35 = *(_QWORD *)(v33 + 34160);
          if ( v35 )
            ipc_log_string(v35, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
        }
        __break(0x800u);
      }
    }
    ipa3_dec_client_disable_clks();
    result = 0;
    goto LABEL_33;
  }
LABEL_36:
  printk(&unk_3E4584, "ipa3_cfg_ep_deaggr");
  v21 = ipa3_ctx;
  if ( !ipa3_ctx )
    goto LABEL_41;
  v22 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v22 )
  {
    ipc_log_string(
      v22,
      "ipa %s:%d bad parm, clnt_hdl = %d , ep_valid = %d\n",
      "ipa3_cfg_ep_deaggr",
      9985,
      a1,
      *(_DWORD *)(ipa3_ctx + 480LL * v4 + 168));
    v21 = ipa3_ctx;
  }
  v23 = *(_QWORD *)(v21 + 34160);
  if ( v23 )
  {
    ipc_log_string(
      v23,
      "ipa %s:%d bad parm, clnt_hdl = %d , ep_valid = %d\n",
      "ipa3_cfg_ep_deaggr",
      9985,
      a1,
      *(_DWORD *)(v21 + 480LL * v4 + 168));
    result = 4294967274LL;
  }
  else
  {
LABEL_41:
    result = 4294967274LL;
  }
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
