__int64 __fastcall ipa_wdi_opt_dpath_register_flt_cb_per_inst_v2(
        unsigned int a1,
        void *a2,
        void *a3,
        void *a4,
        void *a5,
        void *a6,
        void *a7,
        void *a8)
{
  _UNKNOWN **v8; // x8
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 result; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v15; // x0
  __int64 v16; // x0

  if ( a1 >= 2 )
  {
    printk(&unk_3F6766, "ipa_wdi_opt_dpath_register_flt_cb_per_inst_v2");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipa_wdi %s:%d Invalid Handle %d\n",
        "ipa_wdi_opt_dpath_register_flt_cb_per_inst_v2",
        1164,
        a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        ipc_logbuf_low,
        "ipa_wdi %s:%d Invalid Handle %d\n",
        "ipa_wdi_opt_dpath_register_flt_cb_per_inst_v2",
        1164,
        a1);
    }
    return 4294967282LL;
  }
  else if ( ipa_wdi_ctx_list[a1] )
  {
    v8 = &opt_dpath_info + 17 * a1;
    *v8 = a2;
    v8[1] = a3;
    v8[2] = a4;
    v8[3] = a5;
    v8[4] = a6;
    v8[5] = a7;
    v8[6] = a8;
    v8[14] = nullptr;
    v8[15] = nullptr;
    v8[16] = nullptr;
    *((_DWORD *)v8 + 17) = 1;
    *((_DWORD *)v8 + 18) = 1;
    *((_DWORD *)v8 + 26) = 0;
    v9 = ipa3_ctx;
    if ( !ipa3_ctx )
      return 0;
    v10 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v10 )
    {
      ipc_log_string(
        v10,
        "ipa %s:%d wdi_opt_dpath_register_flt_cb_v2: callbacks registered.\n",
        "ipa_wdi_opt_dpath_register_flt_cb_per_inst_v2",
        1188);
      v9 = ipa3_ctx;
    }
    result = *(_QWORD *)(v9 + 34160);
    if ( result )
    {
      ipc_log_string(
        result,
        "ipa %s:%d wdi_opt_dpath_register_flt_cb_v2: callbacks registered.\n",
        "ipa_wdi_opt_dpath_register_flt_cb_per_inst_v2",
        1188);
      return 0;
    }
  }
  else
  {
    printk(&unk_3F0CD4, "ipa_wdi_opt_dpath_register_flt_cb_per_inst_v2");
    if ( ipa3_get_ipc_logbuf() )
    {
      v15 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v15,
        "ipa_wdi %s:%d wdi ctx is not initialized.\n",
        "ipa_wdi_opt_dpath_register_flt_cb_per_inst_v2",
        1169);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v16 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v16,
        "ipa_wdi %s:%d wdi ctx is not initialized.\n",
        "ipa_wdi_opt_dpath_register_flt_cb_per_inst_v2",
        1169);
    }
    return 0xFFFFFFFFLL;
  }
  return result;
}
