__int64 __fastcall ipa_wdi_opt_dpath_disable_clk_per_inst(unsigned int a1)
{
  __int64 v1; // x20
  _DWORD *v2; // x19
  unsigned int v3; // w19
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  long double v7; // q0
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  const char *v11; // x2
  __int64 v12; // x4
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x0
  unsigned int v25; // w10
  char s[8]; // [xsp+8h] [xbp-108h] BYREF
  __int64 v27; // [xsp+10h] [xbp-100h]
  __int64 v28; // [xsp+18h] [xbp-F8h]
  __int64 v29; // [xsp+20h] [xbp-F0h]
  __int64 v30; // [xsp+28h] [xbp-E8h]
  __int64 v31; // [xsp+30h] [xbp-E0h]
  __int64 v32; // [xsp+38h] [xbp-D8h]
  __int64 v33; // [xsp+40h] [xbp-D0h]
  __int64 v34; // [xsp+48h] [xbp-C8h]
  __int64 v35; // [xsp+50h] [xbp-C0h]
  __int64 v36; // [xsp+58h] [xbp-B8h]
  __int64 v37; // [xsp+60h] [xbp-B0h]
  __int64 v38; // [xsp+68h] [xbp-A8h]
  __int64 v39; // [xsp+70h] [xbp-A0h]
  __int64 v40; // [xsp+78h] [xbp-98h]
  __int64 v41; // [xsp+80h] [xbp-90h]
  __int64 v42; // [xsp+88h] [xbp-88h]
  __int64 v43; // [xsp+90h] [xbp-80h]
  __int64 v44; // [xsp+98h] [xbp-78h]
  __int64 v45; // [xsp+A0h] [xbp-70h]
  __int64 v46; // [xsp+A8h] [xbp-68h]
  __int64 v47; // [xsp+B0h] [xbp-60h]
  __int64 v48; // [xsp+B8h] [xbp-58h]
  __int64 v49; // [xsp+C0h] [xbp-50h]
  __int64 v50; // [xsp+C8h] [xbp-48h]
  __int64 v51; // [xsp+D0h] [xbp-40h]
  __int64 v52; // [xsp+D8h] [xbp-38h]
  __int64 v53; // [xsp+E0h] [xbp-30h]
  __int64 v54; // [xsp+E8h] [xbp-28h]
  __int64 v55; // [xsp+F0h] [xbp-20h]
  __int64 v56; // [xsp+F8h] [xbp-18h]
  __int64 v57; // [xsp+100h] [xbp-10h]
  __int64 v58; // [xsp+108h] [xbp-8h]

  v58 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 >= 2 )
    __break(0x5512u);
  v1 = a1;
  v2 = &opt_dpath_info + 17 * a1;
  if ( !v2[18] )
  {
    printk(&unk_3CB2AD, "ipa_wdi_opt_dpath_disable_clk_per_inst");
    v8 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v9 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v9 )
      {
        v7 = ipc_log_string(
               v9,
               "ipa %s:%d ctrl dpath is not enabled.\n",
               "ipa_wdi_opt_dpath_disable_clk_per_inst",
               1929);
        v8 = ipa3_ctx;
      }
      v10 = *(_QWORD *)(v8 + 34160);
      if ( v10 )
        v7 = ipc_log_string(
               v10,
               "ipa %s:%d ctrl dpath is not enabled.\n",
               "ipa_wdi_opt_dpath_disable_clk_per_inst",
               1929);
    }
    v11 = "ipa-event-log %s:%d ctrl dpath is not enabled.\n";
    v12 = 1930;
    v56 = 0;
    v57 = 0;
    v54 = 0;
    v55 = 0;
    v52 = 0;
    v53 = 0;
    v50 = 0;
    v51 = 0;
    goto LABEL_32;
  }
  if ( !v2[27] )
  {
    printk(&unk_3AB782, "ipa_wdi_opt_dpath_disable_clk_per_inst");
    v13 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v14 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v14 )
      {
        ipc_log_string(v14, "ipa %s:%d wdi pipes is not enabled.\n", "ipa_wdi_opt_dpath_disable_clk_per_inst", 1935);
        v13 = ipa3_ctx;
      }
      v15 = *(_QWORD *)(v13 + 34160);
      if ( v15 )
      {
        ipc_log_string(v15, "ipa %s:%d wdi pipes is not enabled.\n", "ipa_wdi_opt_dpath_disable_clk_per_inst", 1935);
        v3 = -1;
        goto LABEL_9;
      }
    }
LABEL_33:
    v3 = -1;
    goto LABEL_9;
  }
  if ( !v2[26] )
  {
    printk(&unk_3DFC67, "ipa_wdi_opt_dpath_disable_clk_per_inst");
    v16 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v17 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v17 )
      {
        v7 = ipc_log_string(
               v17,
               "ipa %s:%d trying to disable clocks with num ctrl pkts 0\n",
               "ipa_wdi_opt_dpath_disable_clk_per_inst",
               1940);
        v16 = ipa3_ctx;
      }
      v18 = *(_QWORD *)(v16 + 34160);
      if ( v18 )
        v7 = ipc_log_string(
               v18,
               "ipa %s:%d trying to disable clocks with num ctrl pkts 0\n",
               "ipa_wdi_opt_dpath_disable_clk_per_inst",
               1940);
    }
    v56 = 0;
    v57 = 0;
    v11 = "ipa-event-log %s:%d trying to disable clocks with num ctrl pkts 0\n";
    v54 = 0;
    v55 = 0;
    v52 = 0;
    v53 = 0;
    v50 = 0;
    v51 = 0;
    v12 = 1941;
LABEL_32:
    v48 = 0;
    v49 = 0;
    v46 = 0;
    v47 = 0;
    v44 = 0;
    v45 = 0;
    v42 = 0;
    v43 = 0;
    v40 = 0;
    v41 = 0;
    v38 = 0;
    v39 = 0;
    v36 = 0;
    v37 = 0;
    v34 = 0;
    v35 = 0;
    v32 = 0;
    v33 = 0;
    v30 = 0;
    v31 = 0;
    v28 = 0;
    v29 = 0;
    *(_QWORD *)s = 0;
    v27 = 0;
    snprintf(s, 0x100u, v11, "ipa_wdi_opt_dpath_disable_clk_per_inst", v12, *(double *)&v7);
    ipa3_send_opt_log_msg(s);
    goto LABEL_33;
  }
  mutex_lock(ipa_wdi_ctx_list[a1] + 96);
  _X8 = v2 + 26;
  __asm { PRFM            #0x11, [X8] }
  do
    v25 = __ldxr(_X8);
  while ( __stxr(v25 - 1, _X8) );
  v56 = 0;
  v57 = 0;
  v54 = 0;
  v55 = 0;
  v52 = 0;
  v53 = 0;
  v50 = 0;
  v51 = 0;
  v48 = 0;
  v49 = 0;
  v46 = 0;
  v47 = 0;
  v44 = 0;
  v45 = 0;
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  *(_QWORD *)s = 0;
  v27 = 0;
  snprintf(s, 0x100u, "ipa-event-log %s:%d num_ctrl_pkts: %d\n", "ipa_wdi_opt_dpath_disable_clk_per_inst", 1947, v2[26]);
  ipa3_send_opt_log_msg(s);
  if ( v2[26] )
  {
    v3 = 0;
  }
  else
  {
    v3 = ((__int64 (__fastcall *)(_QWORD))ipa_pm_deferred_deactivate)((unsigned int)v2[25]);
    if ( v3 )
    {
      if ( ipa3_get_ipc_logbuf() )
      {
        ipc_logbuf = ipa3_get_ipc_logbuf();
        ipc_log_string(
          ipc_logbuf,
          "ipa_wdi %s:%d fail to deactivate ipa pm\n",
          "ipa_wdi_opt_dpath_disable_clk_per_inst",
          1952);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          ipc_logbuf_low,
          "ipa_wdi %s:%d fail to deactivate ipa pm\n",
          "ipa_wdi_opt_dpath_disable_clk_per_inst",
          1952);
      }
    }
  }
  mutex_unlock(ipa_wdi_ctx_list[v1] + 96);
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return v3;
}
