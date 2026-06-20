__int64 __fastcall ipa_disconnect_wdi_pipe(_QWORD *a1)
{
  __int64 v1; // x13
  unsigned int v2; // w19
  __int64 result; // x0
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x23
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  unsigned int v11; // w20
  long double v12; // q0
  long double v13; // q1
  long double v14; // q2
  long double v15; // q3
  float v16; // s4
  _QWORD *v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  _QWORD *v20; // x9
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x0

  v2 = (unsigned int)a1;
  _ReadStatusReg(SP_EL0);
  if ( *(_BYTE *)(ipa3_ctx + 51102) == 1 )
  {
    result = ipa_pm_wrapper_disconnect_wdi_pipe((unsigned int)a1);
LABEL_46:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( *(_DWORD *)(ipa3_ctx + 34308) <= (unsigned int)a1 )
    goto LABEL_19;
  if ( (unsigned int)a1 < 0x24 )
  {
    if ( *(_DWORD *)(ipa3_ctx + 480LL * (unsigned int)a1 + 168) )
    {
      if ( *(_BYTE *)(ipa3_ctx + 32265) == 1 && (unsigned int)ipa_get_wdi_version() == 1 )
      {
        result = ipa3_disconnect_gsi_wdi_pipe(v2);
        goto LABEL_46;
      }
      result = ipa3_uc_state_check();
      if ( (_DWORD)result )
        goto LABEL_46;
      v4 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v5 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v5 )
        {
          ipc_log_string(v5, "ipa %s:%d ep=%d\n", "ipa_disconnect_wdi_pipe", 2360, v2);
          v4 = ipa3_ctx;
        }
        v6 = *(_QWORD *)(v4 + 34160);
        if ( v6 )
        {
          ipc_log_string(v6, "ipa %s:%d ep=%d\n", "ipa_disconnect_wdi_pipe", 2360, v2);
          v4 = ipa3_ctx;
        }
      }
      v7 = v4 + 480LL * v2;
      if ( *(_DWORD *)(v7 + 616) != 1 )
      {
        printk(&unk_3C4C2C, "ipa_disconnect_wdi_pipe");
        v23 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v24 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v24 )
          {
            ipc_log_string(
              v24,
              "ipa %s:%d WDI channel bad state %d\n",
              "ipa_disconnect_wdi_pipe",
              2365,
              *(_DWORD *)(v7 + 616));
            v23 = ipa3_ctx;
          }
          v25 = *(_QWORD *)(v23 + 34160);
          if ( v25 )
            ipc_log_string(
              v25,
              "ipa %s:%d WDI channel bad state %d\n",
              "ipa_disconnect_wdi_pipe",
              2365,
              *(_DWORD *)(v7 + 616));
        }
        result = 4294967282LL;
        goto LABEL_46;
      }
      if ( (*(_BYTE *)(v7 + 573) & 1) == 0 )
      {
        ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v2);
        if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v2) <= 0x85 )
          ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v2);
        ipa3_inc_client_enable_clks();
      }
      if ( (unsigned int)ipa3_uc_send_cmd(v2, 0x67u, 0x60u, 0, 2500) )
      {
        v11 = -14;
LABEL_43:
        ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v2);
        if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v2) <= 0x85 )
          ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v2);
        ipa3_dec_client_disable_clks();
        result = v11;
        goto LABEL_46;
      }
      v12 = ((long double (__fastcall *)(_QWORD))ipa3_delete_dflt_flt_rules)(v2);
      ipa_release_uc_smmu_mappings(*(_DWORD *)(v7 + 172), v12, v13, v14, v15, v16);
      memset((void *)(ipa3_ctx + 480LL * v2 + 168), 0, 0x1E0u);
      v17 = (_QWORD *)ipa3_ctx;
      if ( ipa3_ctx )
      {
        v18 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v18 )
        {
          ipc_log_string(v18, "ipa %s:%d client (ep: %d) disconnected\n", "ipa_disconnect_wdi_pipe", 2389, v2);
          v17 = (_QWORD *)ipa3_ctx;
        }
        v19 = v17[4270];
        if ( v19 )
        {
          ipc_log_string(v19, "ipa %s:%d client (ep: %d) disconnected\n", "ipa_disconnect_wdi_pipe", 2389, v2);
          v17 = (_QWORD *)ipa3_ctx;
        }
        v20 = v17 + 5397;
        if ( !v17[5397] )
        {
          if ( v17 )
          {
            v21 = v17[4269];
            if ( v21 )
            {
              ipc_log_string(v21, "ipa %s:%d uc_wdi_ctx.stats_notify already null\n", "ipa_disconnect_wdi_pipe", 2395);
              v17 = (_QWORD *)ipa3_ctx;
            }
            v22 = v17[4270];
            if ( v22 )
              ipc_log_string(v22, "ipa %s:%d uc_wdi_ctx.stats_notify already null\n", "ipa_disconnect_wdi_pipe", 2395);
          }
          goto LABEL_42;
        }
      }
      else
      {
        v20 = &qword_A8A8;
        if ( !qword_A8A8 )
        {
LABEL_42:
          v11 = 0;
          goto LABEL_43;
        }
      }
      v11 = 0;
      *v20 = 0;
      goto LABEL_43;
    }
LABEL_19:
    printk(&unk_3A77D5, "ipa_disconnect_wdi_pipe");
    v8 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_24;
    v9 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v9 )
    {
      ipc_log_string(v9, "ipa %s:%d bad parm, %d\n", "ipa_disconnect_wdi_pipe", 2349, v2);
      v8 = ipa3_ctx;
    }
    v10 = *(_QWORD *)(v8 + 34160);
    if ( v10 )
    {
      ipc_log_string(v10, "ipa %s:%d bad parm, %d\n", "ipa_disconnect_wdi_pipe", 2349, v2);
      result = 4294967274LL;
    }
    else
    {
LABEL_24:
      result = 4294967274LL;
    }
    goto LABEL_46;
  }
  __break(0x5512u);
  *a1 = v1;
  return ipa_pm_wrapper_disconnect_wdi_pipe((char *)a1 + 217);
}
