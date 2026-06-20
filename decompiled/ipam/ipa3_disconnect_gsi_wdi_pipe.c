__int64 __fastcall ipa3_disconnect_gsi_wdi_pipe(unsigned int a1)
{
  __int64 v2; // x21
  unsigned int v3; // w0
  long double v4; // q0
  long double v5; // q1
  long double v6; // q2
  long double v7; // q3
  float v8; // s4
  __int64 v9; // x8
  unsigned int v10; // w9
  __int64 v11; // x0
  __int64 result; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  unsigned int v18; // w19
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x0

  _ReadStatusReg(SP_EL0);
  if ( a1 >= 0x25 )
    __break(0x5512u);
  v2 = ipa3_ctx + 480LL * a1;
  if ( *(_DWORD *)(v2 + 620) == 1 )
  {
    if ( (*(_BYTE *)(v2 + 573) & 1) == 0 )
    {
      ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1);
      if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1) <= 0x85 )
        ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1);
      ipa3_inc_client_enable_clks();
    }
    ipa3_reset_gsi_channel((_QWORD *)a1);
    ((void (__fastcall *)(_QWORD))ipa3_reset_gsi_event_ring)(a1);
    if ( (*(_BYTE *)(v2 + 573) & 1) == 0 )
    {
      ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1);
      if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1) <= 0x85 )
        ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1);
      ipa3_dec_client_disable_clks();
    }
    v3 = ((__int64 (__fastcall *)(_QWORD))ipa3_release_gsi_channel)(a1);
    if ( v3 )
    {
      v18 = v3;
      printk(&unk_3B5A13, "ipa3_disconnect_gsi_wdi_pipe");
      v19 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_42;
      v20 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v20 )
      {
        ipc_log_string(v20, "ipa %s:%d GSI dealloc channel failed %d\n", "ipa3_disconnect_gsi_wdi_pipe", 2309, v18);
        v19 = ipa3_ctx;
      }
      v21 = *(_QWORD *)(v19 + 34160);
      if ( v21 )
      {
        ipc_log_string(v21, "ipa %s:%d GSI dealloc channel failed %d\n", "ipa3_disconnect_gsi_wdi_pipe", 2309, v18);
        result = v18;
      }
      else
      {
LABEL_42:
        result = v18;
      }
    }
    else
    {
      ipa_release_ap_smmu_mappings(a1, v4, v5, v6, v7, v8);
      v9 = ipa3_ctx;
      if ( *(_QWORD *)(ipa3_ctx + 43176) )
      {
        *(_QWORD *)(ipa3_ctx + 43176) = 0;
      }
      else if ( ipa3_ctx )
      {
        v13 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v13 )
        {
          ipc_log_string(v13, "ipa %s:%d uc_wdi_ctx.stats_notify already null\n", "ipa3_disconnect_gsi_wdi_pipe", 2318);
          v9 = ipa3_ctx;
        }
        v14 = *(_QWORD *)(v9 + 34160);
        if ( v14 )
        {
          ipc_log_string(v14, "ipa %s:%d uc_wdi_ctx.stats_notify already null\n", "ipa3_disconnect_gsi_wdi_pipe", 2318);
          v9 = ipa3_ctx;
        }
      }
      v10 = *(_DWORD *)(v9 + 32240);
      if ( v10 < 0x11 || v10 <= 0x17 && ((1 << v10) & 0x940000) != 0 )
      {
        if ( !v9 )
        {
LABEL_22:
          result = 0;
          goto LABEL_23;
        }
      }
      else
      {
        ipa3_uc_debug_stats_dealloc(3);
        v9 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_22;
      }
      v11 = *(_QWORD *)(v9 + 34152);
      if ( v11 )
      {
        ipc_log_string(v11, "ipa %s:%d client (ep: %d) disconnected\n", "ipa3_disconnect_gsi_wdi_pipe", 2324, a1);
        v9 = ipa3_ctx;
      }
      result = *(_QWORD *)(v9 + 34160);
      if ( result )
      {
        ipc_log_string(result, "ipa %s:%d client (ep: %d) disconnected\n", "ipa3_disconnect_gsi_wdi_pipe", 2324, a1);
        goto LABEL_22;
      }
    }
  }
  else
  {
    printk(&unk_3C4C2C, "ipa3_disconnect_gsi_wdi_pipe");
    v15 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_41;
    v16 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v16 )
    {
      ipc_log_string(
        v16,
        "ipa %s:%d WDI channel bad state %d\n",
        "ipa3_disconnect_gsi_wdi_pipe",
        2293,
        *(_DWORD *)(v2 + 620));
      v15 = ipa3_ctx;
    }
    v17 = *(_QWORD *)(v15 + 34160);
    if ( v17 )
    {
      ipc_log_string(
        v17,
        "ipa %s:%d WDI channel bad state %d\n",
        "ipa3_disconnect_gsi_wdi_pipe",
        2293,
        *(_DWORD *)(v2 + 620));
      result = 4294967282LL;
    }
    else
    {
LABEL_41:
      result = 4294967282LL;
    }
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
