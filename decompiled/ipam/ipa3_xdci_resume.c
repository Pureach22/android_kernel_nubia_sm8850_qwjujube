__int64 __fastcall ipa3_xdci_resume(unsigned int a1, unsigned int a2, char a3)
{
  __int64 v6; // x8
  unsigned int v7; // w22
  __int64 v8; // x0
  __int64 v9; // x0
  unsigned int v10; // w9
  __int64 v11; // x8
  __int64 v12; // x27
  __int64 v13; // x28
  int started; // w0
  unsigned int v15; // w8
  unsigned int v16; // w0
  int v17; // w0
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 result; // x0
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  int v24; // w23
  __int64 v25; // x8
  int v26; // w4
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x8
  __int64 v30; // x0
  __int64 v31; // x0
  int v32; // w21
  __int64 v33; // x8
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // [xsp+20h] [xbp-20h] BYREF
  __int64 v37; // [xsp+28h] [xbp-18h]
  __int16 v38; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v39; // [xsp+38h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = ipa3_ctx;
  v38 = 0;
  v7 = *(_DWORD *)(ipa3_ctx + 34924);
  v36 = 0;
  v37 = 0;
  if ( ipa3_ctx )
  {
    v8 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v8 )
    {
      ipc_log_string(v8, "ipa %s:%d entry\n", "ipa3_xdci_resume", 1916);
      v6 = ipa3_ctx;
    }
    v9 = *(_QWORD *)(v6 + 34160);
    if ( v9 )
    {
      ipc_log_string(v9, "ipa %s:%d entry\n", "ipa3_xdci_resume", 1916);
      v6 = ipa3_ctx;
    }
  }
  v10 = *(_DWORD *)(v6 + 34308);
  if ( v10 <= a2 )
    goto LABEL_35;
  if ( a2 >= 0x24 )
    goto LABEL_57;
  v11 = v6 + 168;
  v12 = v11 + 480LL * a2;
  if ( !*(_DWORD *)v12 )
    goto LABEL_35;
  if ( (a3 & 1) == 0 )
  {
    if ( v10 <= a1 )
      goto LABEL_35;
    if ( a1 <= 0x23 )
    {
      v13 = v11 + 480LL * a1;
      if ( *(_DWORD *)v13 )
        goto LABEL_14;
LABEL_35:
      printk(&unk_3F1C01, "ipa3_xdci_resume");
      v21 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v22 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v22 )
        {
          ipc_log_string(v22, "ipa %s:%d Bad parameter.\n", "ipa3_xdci_resume", 1921);
          v21 = ipa3_ctx;
        }
        v23 = *(_QWORD *)(v21 + 34160);
        if ( v23 )
          ipc_log_string(v23, "ipa %s:%d Bad parameter.\n", "ipa3_xdci_resume", 1921);
      }
      result = 4294967274LL;
      goto LABEL_41;
    }
LABEL_57:
    __break(0x5512u);
  }
  v13 = 0;
LABEL_14:
  ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a2);
  if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a2) <= 0x85 )
    ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a2);
  ipa3_inc_client_enable_clks();
  if ( *(_DWORD *)(ipa3_ctx + 32240) <= 0xDu )
  {
    v38 = 0;
    ipa_cfg_ep_ctrl(a2, &v38);
  }
  started = gsi_start_channel(*(_QWORD *)(v12 + 8));
  if ( started )
  {
    v24 = started;
    printk(&unk_3FD8F4, "ipa3_xdci_resume");
    v25 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v26 = v24;
      v27 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v27 )
      {
        ipc_log_string(v27, "ipa %s:%d Error starting DL channel: %d\n", "ipa3_xdci_resume", 1940, v24);
        v25 = ipa3_ctx;
        v26 = v24;
      }
      v28 = *(_QWORD *)(v25 + 34160);
      if ( v28 )
        ipc_log_string(v28, "ipa %s:%d Error starting DL channel: %d\n", "ipa3_xdci_resume", 1940, v26);
    }
  }
  v15 = *(_DWORD *)(v12 + 4);
  if ( v15 <= 0x85 && (v15 & 1) != 0 && (a3 & 1) == 0 )
  {
    v36 = 0;
    v37 = 0;
    ipa3_cfg_ep_holb(a2, &v36);
  }
  v16 = a2;
  if ( (a3 & 1) == 0 )
  {
    if ( (unsigned int)((__int64 (__fastcall *)(_QWORD, __int64, _QWORD, _QWORD))ipa3_uc_client_add_holb_monitor)(
                         *(unsigned __int16 *)(v12 + 8),
                         3,
                         v7,
                         0) )
    {
      printk(&unk_3C68A9, "ipa3_xdci_resume");
      v29 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v30 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v30 )
        {
          ipc_log_string(
            v30,
            "ipa %s:%d Add HOLB monitor failed for gsi ch %lu\n",
            "ipa3_xdci_resume",
            1954,
            *(_QWORD *)(v12 + 8));
          v29 = ipa3_ctx;
        }
        v31 = *(_QWORD *)(v29 + 34160);
        if ( v31 )
          ipc_log_string(
            v31,
            "ipa %s:%d Add HOLB monitor failed for gsi ch %lu\n",
            "ipa3_xdci_resume",
            1954,
            *(_QWORD *)(v12 + 8));
      }
    }
    ipa3_start_gsi_debug_monitor(a2);
    v17 = gsi_start_channel(*(_QWORD *)(v13 + 8));
    if ( v17 )
    {
      v32 = v17;
      printk(&unk_3CBF6F, "ipa3_xdci_resume");
      v33 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v34 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v34 )
        {
          ipc_log_string(v34, "ipa %s:%d Error starting UL channel: %d\n", "ipa3_xdci_resume", 1962, v32);
          v33 = ipa3_ctx;
        }
        v35 = *(_QWORD *)(v33 + 34160);
        if ( v35 )
          ipc_log_string(v35, "ipa %s:%d Error starting UL channel: %d\n", "ipa3_xdci_resume", 1962, v32);
      }
    }
    v16 = a1;
  }
  ipa3_start_gsi_debug_monitor(v16);
  ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a2);
  if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a2) <= 0x85 )
    ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a2);
  ipa3_dec_client_disable_clks();
  v18 = ipa3_ctx;
  if ( !ipa3_ctx )
    goto LABEL_34;
  v19 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v19 )
  {
    ipc_log_string(v19, "ipa %s:%d exit\n", "ipa3_xdci_resume", 1968);
    v18 = ipa3_ctx;
  }
  result = *(_QWORD *)(v18 + 34160);
  if ( result )
  {
    ipc_log_string(result, "ipa %s:%d exit\n", "ipa3_xdci_resume", 1968);
LABEL_34:
    result = 0;
  }
LABEL_41:
  _ReadStatusReg(SP_EL0);
  return result;
}
