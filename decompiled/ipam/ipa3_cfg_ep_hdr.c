__int64 __fastcall ipa3_cfg_ep_hdr(unsigned int a1, _DWORD *a2)
{
  __int64 v3; // x8
  unsigned int v4; // w23
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x21
  __int64 v16; // x10
  __int64 v17; // x12
  __int64 v18; // x11
  __int64 result; // x0
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x8
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x8
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x8
  __int64 v33; // x0
  __int64 v34; // x0

  _ReadStatusReg(SP_EL0);
  v3 = ipa3_ctx;
  if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
  {
    if ( a1 <= 0x23 )
    {
      v4 = a1;
      goto LABEL_31;
    }
LABEL_61:
    __break(0x5512u);
  }
  if ( a1 >= 0x24 )
    goto LABEL_61;
  v4 = a1;
  if ( a2 && *(_DWORD *)(ipa3_ctx + 480LL * a1 + 168) )
  {
    if ( ipa3_ctx )
    {
      v6 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v6 )
      {
        ipc_log_string(v6, "ipa %s:%d pipe=%d metadata_reg_valid=%d\n", "ipa3_cfg_ep_hdr", 9193, a1, a2[8]);
        v3 = ipa3_ctx;
      }
      v7 = *(_QWORD *)(v3 + 34160);
      if ( v7 )
      {
        ipc_log_string(v7, "ipa %s:%d pipe=%d metadata_reg_valid=%d\n", "ipa3_cfg_ep_hdr", 9193, a1, a2[8]);
        v3 = ipa3_ctx;
      }
      if ( v3 )
      {
        v8 = *(_QWORD *)(v3 + 34152);
        if ( v8 )
        {
          ipc_log_string(
            v8,
            "ipa %s:%d remove_additional=%d, a5_mux=%d, ofst_pkt_size=0x%x\n",
            "ipa3_cfg_ep_hdr",
            9198,
            a2[7],
            a2[6],
            a2[5]);
          v3 = ipa3_ctx;
        }
        v9 = *(_QWORD *)(v3 + 34160);
        if ( v9 )
        {
          ipc_log_string(
            v9,
            "ipa %s:%d remove_additional=%d, a5_mux=%d, ofst_pkt_size=0x%x\n",
            "ipa3_cfg_ep_hdr",
            9198,
            a2[7],
            a2[6],
            a2[5]);
          v3 = ipa3_ctx;
        }
        if ( v3 )
        {
          v10 = *(_QWORD *)(v3 + 34152);
          if ( v10 )
          {
            ipc_log_string(
              v10,
              "ipa %s:%d ofst_pkt_size_valid=%d, additional_const_len=0x%x\n",
              "ipa3_cfg_ep_hdr",
              9202,
              a2[4],
              a2[3]);
            v3 = ipa3_ctx;
          }
          v11 = *(_QWORD *)(v3 + 34160);
          if ( v11 )
          {
            ipc_log_string(
              v11,
              "ipa %s:%d ofst_pkt_size_valid=%d, additional_const_len=0x%x\n",
              "ipa3_cfg_ep_hdr",
              9202,
              a2[4],
              a2[3]);
            v3 = ipa3_ctx;
          }
          if ( v3 )
          {
            v12 = *(_QWORD *)(v3 + 34152);
            if ( v12 )
            {
              ipc_log_string(
                v12,
                "ipa %s:%d ofst_metadata=0x%x, ofst_metadata_valid=%d, len=0x%x\n",
                "ipa3_cfg_ep_hdr",
                9207,
                a2[2],
                a2[1],
                *a2);
              v3 = ipa3_ctx;
            }
            v13 = *(_QWORD *)(v3 + 34160);
            if ( v13 )
            {
              ipc_log_string(
                v13,
                "ipa %s:%d ofst_metadata=0x%x, ofst_metadata_valid=%d, len=0x%x\n",
                "ipa3_cfg_ep_hdr",
                9207,
                a2[2],
                a2[1],
                *a2);
              v3 = ipa3_ctx;
            }
          }
        }
      }
    }
    v14 = v3 + 480LL * a1;
    *(_QWORD *)(v14 + 324) = *(_QWORD *)a2;
    v15 = v14 + 324;
    v17 = *((_QWORD *)a2 + 2);
    v16 = *((_QWORD *)a2 + 3);
    v18 = *((_QWORD *)a2 + 1);
    *(_DWORD *)(v14 + 356) = a2[8];
    *(_QWORD *)(v14 + 340) = v17;
    *(_QWORD *)(v14 + 348) = v16;
    *(_QWORD *)(v14 + 332) = v18;
    if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
    {
      printk(&unk_3E7136, "ipa3_get_client_mapping");
      v23 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v24 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v24 )
        {
          ipc_log_string(v24, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
          v23 = ipa3_ctx;
        }
        v25 = *(_QWORD *)(v23 + 34160);
        if ( v25 )
          ipc_log_string(v25, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
      }
      __break(0x800u);
      if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
      {
        printk(&unk_3E7136, "ipa3_get_client_mapping");
        v26 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v27 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v27 )
          {
            ipc_log_string(v27, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
            v26 = ipa3_ctx;
          }
          v28 = *(_QWORD *)(v26 + 34160);
          if ( v28 )
            ipc_log_string(v28, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
        }
        __break(0x800u);
      }
    }
    ipa3_inc_client_enable_clks();
    ((void (__fastcall *)(__int64, _QWORD, __int64))ipahal_write_reg_n_fields)(41, a1, v15);
    if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
    {
      printk(&unk_3E7136, "ipa3_get_client_mapping");
      v29 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v30 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v30 )
        {
          ipc_log_string(v30, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
          v29 = ipa3_ctx;
        }
        v31 = *(_QWORD *)(v29 + 34160);
        if ( v31 )
          ipc_log_string(v31, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
      }
      __break(0x800u);
      if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
      {
        printk(&unk_3E7136, "ipa3_get_client_mapping");
        v32 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v33 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v33 )
          {
            ipc_log_string(v33, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
            v32 = ipa3_ctx;
          }
          v34 = *(_QWORD *)(v32 + 34160);
          if ( v34 )
            ipc_log_string(v34, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
        }
        __break(0x800u);
      }
    }
    ipa3_dec_client_disable_clks();
    result = 0;
    goto LABEL_28;
  }
LABEL_31:
  printk(&unk_3E4584, "ipa3_cfg_ep_hdr");
  v20 = ipa3_ctx;
  if ( !ipa3_ctx )
    goto LABEL_36;
  v21 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v21 )
  {
    ipc_log_string(
      v21,
      "ipa %s:%d bad parm, clnt_hdl = %d , ep_valid = %d\n",
      "ipa3_cfg_ep_hdr",
      9188,
      a1,
      *(_DWORD *)(ipa3_ctx + 480LL * v4 + 168));
    v20 = ipa3_ctx;
  }
  v22 = *(_QWORD *)(v20 + 34160);
  if ( v22 )
  {
    ipc_log_string(
      v22,
      "ipa %s:%d bad parm, clnt_hdl = %d , ep_valid = %d\n",
      "ipa3_cfg_ep_hdr",
      9188,
      a1,
      *(_DWORD *)(v20 + 480LL * v4 + 168));
    result = 4294967274LL;
  }
  else
  {
LABEL_36:
    result = 4294967274LL;
  }
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
