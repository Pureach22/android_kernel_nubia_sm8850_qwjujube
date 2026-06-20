__int64 __fastcall ipa_wdi_opt_dpath_enable_clk_per_inst(unsigned int a1)
{
  __int64 v1; // x19
  _DWORD *v2; // x20
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x0
  unsigned int v6; // w0
  __int64 v7; // x8
  unsigned int v8; // w19
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x0
  unsigned int v22; // w9
  char s[8]; // [xsp+8h] [xbp-108h] BYREF
  __int64 v24; // [xsp+10h] [xbp-100h]
  __int64 v25; // [xsp+18h] [xbp-F8h]
  __int64 v26; // [xsp+20h] [xbp-F0h]
  __int64 v27; // [xsp+28h] [xbp-E8h]
  __int64 v28; // [xsp+30h] [xbp-E0h]
  __int64 v29; // [xsp+38h] [xbp-D8h]
  __int64 v30; // [xsp+40h] [xbp-D0h]
  __int64 v31; // [xsp+48h] [xbp-C8h]
  __int64 v32; // [xsp+50h] [xbp-C0h]
  __int64 v33; // [xsp+58h] [xbp-B8h]
  __int64 v34; // [xsp+60h] [xbp-B0h]
  __int64 v35; // [xsp+68h] [xbp-A8h]
  __int64 v36; // [xsp+70h] [xbp-A0h]
  __int64 v37; // [xsp+78h] [xbp-98h]
  __int64 v38; // [xsp+80h] [xbp-90h]
  __int64 v39; // [xsp+88h] [xbp-88h]
  __int64 v40; // [xsp+90h] [xbp-80h]
  __int64 v41; // [xsp+98h] [xbp-78h]
  __int64 v42; // [xsp+A0h] [xbp-70h]
  __int64 v43; // [xsp+A8h] [xbp-68h]
  __int64 v44; // [xsp+B0h] [xbp-60h]
  __int64 v45; // [xsp+B8h] [xbp-58h]
  __int64 v46; // [xsp+C0h] [xbp-50h]
  __int64 v47; // [xsp+C8h] [xbp-48h]
  __int64 v48; // [xsp+D0h] [xbp-40h]
  __int64 v49; // [xsp+D8h] [xbp-38h]
  __int64 v50; // [xsp+E0h] [xbp-30h]
  __int64 v51; // [xsp+E8h] [xbp-28h]
  __int64 v52; // [xsp+F0h] [xbp-20h]
  __int64 v53; // [xsp+F8h] [xbp-18h]
  __int64 v54; // [xsp+100h] [xbp-10h]
  __int64 v55; // [xsp+108h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 >= 2 )
    __break(0x5512u);
  v1 = a1;
  v2 = &opt_dpath_info + 17 * a1;
  if ( !v2[18] )
  {
    printk(&unk_3CB2AD, "ipa_wdi_opt_dpath_enable_clk_per_inst");
    v10 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v11 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v11 )
      {
        ipc_log_string(v11, "ipa %s:%d ctrl dpath is not enabled.\n", "ipa_wdi_opt_dpath_enable_clk_per_inst", 1893);
        v10 = ipa3_ctx;
      }
      v12 = *(_QWORD *)(v10 + 34160);
      if ( v12 )
        ipc_log_string(v12, "ipa %s:%d ctrl dpath is not enabled.\n", "ipa_wdi_opt_dpath_enable_clk_per_inst", 1893);
    }
    goto LABEL_22;
  }
  if ( !v2[27] )
  {
    printk(&unk_3AB782, "ipa_wdi_opt_dpath_enable_clk_per_inst");
    v13 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v14 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v14 )
      {
        ipc_log_string(v14, "ipa %s:%d wdi pipes is not enabled.\n", "ipa_wdi_opt_dpath_enable_clk_per_inst", 1898);
        v13 = ipa3_ctx;
      }
      v15 = *(_QWORD *)(v13 + 34160);
      if ( v15 )
        ipc_log_string(v15, "ipa %s:%d wdi pipes is not enabled.\n", "ipa_wdi_opt_dpath_enable_clk_per_inst", 1898);
    }
LABEL_22:
    v8 = -1;
    goto LABEL_11;
  }
  mutex_lock(ipa_wdi_ctx_list[a1] + 96);
  _X8 = v2 + 26;
  __asm { PRFM            #0x11, [X8] }
  do
    v22 = __ldxr(_X8);
  while ( __stxr(v22 + 1, _X8) );
  v3 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v4 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v4 )
    {
      ipc_log_string(v4, "ipa %s:%d enabling clk: %d\n", "ipa_wdi_opt_dpath_enable_clk_per_inst", 1906, v2[26]);
      v3 = ipa3_ctx;
    }
    v5 = *(_QWORD *)(v3 + 34160);
    if ( v5 )
      ipc_log_string(v5, "ipa %s:%d enabling clk: %d\n", "ipa_wdi_opt_dpath_enable_clk_per_inst", 1906, v2[26]);
  }
  v53 = 0;
  v54 = 0;
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  *(_QWORD *)s = 0;
  v24 = 0;
  snprintf(s, 0x100u, "ipa-event-log %s:%d enabling clk: %d\n", "ipa_wdi_opt_dpath_enable_clk_per_inst", 1908, v2[26]);
  ipa3_send_opt_log_msg(s);
  v6 = ipa_pm_activate(v2[25]);
  v7 = ipa_wdi_ctx_list[v1];
  v8 = v6;
  mutex_unlock(v7 + 96);
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return v8;
}
