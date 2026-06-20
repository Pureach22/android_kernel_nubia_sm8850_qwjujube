__int64 __fastcall ipa3_enable_gsi_wdi_pipe(unsigned int a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x22
  __int64 v6; // x0
  unsigned int ep_mapping; // w0
  unsigned int v8; // w20
  unsigned int v9; // w8
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 result; // x0
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // [xsp+20h] [xbp-20h] BYREF
  __int64 v20; // [xsp+28h] [xbp-18h]
  __int16 v21; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+38h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = ipa3_ctx;
  v21 = 0;
  v19 = 0;
  v20 = 0;
  if ( ipa3_ctx )
  {
    v3 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v3 )
    {
      ipc_log_string(v3, "ipa %s:%d ep=%d\n", "ipa3_enable_gsi_wdi_pipe", 2411, a1);
      v2 = ipa3_ctx;
    }
    v4 = *(_QWORD *)(v2 + 34160);
    if ( v4 )
      ipc_log_string(v4, "ipa %s:%d ep=%d\n", "ipa3_enable_gsi_wdi_pipe", 2411, a1);
  }
  if ( a1 >= 0x25 )
    __break(0x5512u);
  v5 = ipa3_ctx + 480LL * a1;
  if ( *(_DWORD *)(v5 + 620) == 1 )
  {
    v6 = ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1);
    ep_mapping = ipa_get_ep_mapping(v6);
    if ( ep_mapping == -1 )
    {
      printk(&unk_3F4B4C, "ipa3_enable_gsi_wdi_pipe");
      v16 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_34;
      v17 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v17 )
      {
        ipc_log_string(v17, "ipa %s:%d fail to alloc EP.\n", "ipa3_enable_gsi_wdi_pipe", 2421);
        v16 = ipa3_ctx;
      }
      v18 = *(_QWORD *)(v16 + 34160);
      if ( v18 )
      {
        ipc_log_string(v18, "ipa %s:%d fail to alloc EP.\n", "ipa3_enable_gsi_wdi_pipe", 2421);
        result = 0xFFFFFFFFLL;
      }
      else
      {
LABEL_34:
        result = 0xFFFFFFFFLL;
      }
    }
    else
    {
      v8 = ep_mapping;
      ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1);
      if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1) <= 0x85 )
        ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1);
      ipa3_inc_client_enable_clks();
      v21 = 0;
      ipa_cfg_ep_ctrl(v8, &v21);
      v9 = *(_DWORD *)(v5 + 172);
      if ( v9 <= 0x85 && (v9 & 1) != 0 )
      {
        v19 = 0;
        v20 = 0;
        ipa3_cfg_ep_holb(a1, &v19);
      }
      ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1);
      if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1) <= 0x85 )
        ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1);
      ipa3_dec_client_disable_clks();
      *(_DWORD *)(v5 + 620) |= 2u;
      v10 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_21;
      v11 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v11 )
      {
        ipc_log_string(v11, "ipa %s:%d client (ep: %d) enabled\n", "ipa3_enable_gsi_wdi_pipe", 2440, a1);
        v10 = ipa3_ctx;
      }
      result = *(_QWORD *)(v10 + 34160);
      if ( result )
      {
        ipc_log_string(result, "ipa %s:%d client (ep: %d) enabled\n", "ipa3_enable_gsi_wdi_pipe", 2440, a1);
LABEL_21:
        result = 0;
      }
    }
  }
  else
  {
    printk(&unk_3C4C2C, "ipa3_enable_gsi_wdi_pipe");
    v13 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_33;
    v14 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v14 )
    {
      ipc_log_string(
        v14,
        "ipa %s:%d WDI channel bad state %d\n",
        "ipa3_enable_gsi_wdi_pipe",
        2415,
        *(_DWORD *)(v5 + 620));
      v13 = ipa3_ctx;
    }
    v15 = *(_QWORD *)(v13 + 34160);
    if ( v15 )
    {
      ipc_log_string(
        v15,
        "ipa %s:%d WDI channel bad state %d\n",
        "ipa3_enable_gsi_wdi_pipe",
        2415,
        *(_DWORD *)(v5 + 620));
      result = 4294967282LL;
    }
    else
    {
LABEL_33:
      result = 4294967282LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
