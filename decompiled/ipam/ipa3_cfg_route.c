__int64 __fastcall ipa3_cfg_route(_DWORD *a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 result; // x0
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0

  _ReadStatusReg(SP_EL0);
  v2 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v3 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v3 )
    {
      ipc_log_string(
        v3,
        "ipa %s:%d disable_route_block=%d, default_pipe=%d, default_hdr_tbl=%d\n",
        "ipa3_cfg_route",
        7961,
        *a1,
        a1[1],
        a1[2]);
      v2 = ipa3_ctx;
    }
    v4 = *(_QWORD *)(v2 + 34160);
    if ( v4 )
    {
      ipc_log_string(
        v4,
        "ipa %s:%d disable_route_block=%d, default_pipe=%d, default_hdr_tbl=%d\n",
        "ipa3_cfg_route",
        7961,
        *a1,
        a1[1],
        a1[2]);
      v2 = ipa3_ctx;
    }
    if ( v2 )
    {
      v5 = *(_QWORD *)(v2 + 34152);
      if ( v5 )
      {
        ipc_log_string(
          v5,
          "ipa %s:%d default_hdr_ofst=%d, default_frag_pipe=%d\n",
          "ipa3_cfg_route",
          7964,
          a1[3],
          *((unsigned __int8 *)a1 + 16));
        v2 = ipa3_ctx;
      }
      v6 = *(_QWORD *)(v2 + 34160);
      if ( v6 )
      {
        ipc_log_string(
          v6,
          "ipa %s:%d default_hdr_ofst=%d, default_frag_pipe=%d\n",
          "ipa3_cfg_route",
          7964,
          a1[3],
          *((unsigned __int8 *)a1 + 16));
        v2 = ipa3_ctx;
      }
      if ( v2 )
      {
        v7 = *(_QWORD *)(v2 + 34152);
        if ( v7 )
        {
          ipc_log_string(v7, "ipa %s:%d default_retain_hdr=%d\n", "ipa3_cfg_route", 7967, a1[5]);
          v2 = ipa3_ctx;
        }
        v8 = *(_QWORD *)(v2 + 34160);
        if ( v8 )
          ipc_log_string(v8, "ipa %s:%d default_retain_hdr=%d\n", "ipa3_cfg_route", 7967, a1[5]);
      }
    }
  }
  if ( *a1 )
  {
    printk(&unk_3B8BED, "ipa3_cfg_route");
    v10 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v11 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v11 )
      {
        ipc_log_string(v11, "ipa %s:%d Route disable is not supported!\n", "ipa3_cfg_route", 7970);
        v10 = ipa3_ctx;
      }
      v12 = *(_QWORD *)(v10 + 34160);
      if ( v12 )
        ipc_log_string(v12, "ipa %s:%d Route disable is not supported!\n", "ipa3_cfg_route", 7970);
    }
    result = 0xFFFFFFFFLL;
  }
  else
  {
    ipa3_inc_client_enable_clks();
    ((void (__fastcall *)(_QWORD, _QWORD, _DWORD *))ipahal_write_reg_n_fields)(0, 0, a1);
    ipa3_dec_client_disable_clks();
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
