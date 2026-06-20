__int64 __fastcall ipa_wdi_opt_dpath_register_flt_cb_per_inst(unsigned int a1, void *a2, void *a3, void *a4, void *a5)
{
  _UNKNOWN **v5; // x8
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 result; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v12; // x0
  __int64 v13; // x0

  if ( a1 >= 2 )
  {
    printk(&unk_3F6766, "ipa_wdi_opt_dpath_register_flt_cb_per_inst");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipa_wdi %s:%d Invalid Handle %d\n",
        "ipa_wdi_opt_dpath_register_flt_cb_per_inst",
        1119,
        a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        ipc_logbuf_low,
        "ipa_wdi %s:%d Invalid Handle %d\n",
        "ipa_wdi_opt_dpath_register_flt_cb_per_inst",
        1119,
        a1);
    }
    return 4294967282LL;
  }
  else if ( ipa_wdi_ctx_list[a1] )
  {
    v5 = &opt_dpath_info + 17 * a1;
    *v5 = a2;
    v5[1] = a3;
    v5[2] = a4;
    v5[3] = a5;
    *(_UNKNOWN **)((char *)v5 + 68) = (_UNKNOWN *)(&_ksymtab_ipa3_add_hdr_hpc + 1);
    v6 = ipa3_ctx;
    if ( !ipa3_ctx )
      return 0;
    v7 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v7 )
    {
      ipc_log_string(
        v7,
        "ipa %s:%d wdi_opt_dpath_register_flt_cb: callbacks registered.\n",
        "ipa_wdi_opt_dpath_register_flt_cb_per_inst",
        1136);
      v6 = ipa3_ctx;
    }
    result = *(_QWORD *)(v6 + 34160);
    if ( result )
    {
      ipc_log_string(
        result,
        "ipa %s:%d wdi_opt_dpath_register_flt_cb: callbacks registered.\n",
        "ipa_wdi_opt_dpath_register_flt_cb_per_inst",
        1136);
      return 0;
    }
  }
  else
  {
    printk(&unk_3F0CD4, "ipa_wdi_opt_dpath_register_flt_cb_per_inst");
    if ( ipa3_get_ipc_logbuf() )
    {
      v12 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v12,
        "ipa_wdi %s:%d wdi ctx is not initialized.\n",
        "ipa_wdi_opt_dpath_register_flt_cb_per_inst",
        1124);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v13 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v13,
        "ipa_wdi %s:%d wdi ctx is not initialized.\n",
        "ipa_wdi_opt_dpath_register_flt_cb_per_inst",
        1124);
    }
    return 0xFFFFFFFFLL;
  }
  return result;
}
