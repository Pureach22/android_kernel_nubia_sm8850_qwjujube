__int64 __fastcall ipa_resume_wdi_pipe(_QWORD *a1)
{
  __int64 v1; // x13
  unsigned int v2; // w19
  __int64 result; // x0
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  _DWORD *v7; // x22
  const char *v8; // x8
  const char *v9; // x8
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0
  unsigned int v13; // w20
  __int64 v14; // x9
  __int64 v15; // x9
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x9
  const char *v20; // [xsp+0h] [xbp-20h] BYREF
  char *v21; // [xsp+8h] [xbp-18h]
  __int64 v22; // [xsp+10h] [xbp-10h]
  __int64 v23; // [xsp+18h] [xbp-8h]

  v2 = (unsigned int)a1;
  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(ipa3_ctx + 34308) <= (unsigned int)a1 )
    goto LABEL_20;
  if ( (unsigned int)a1 < 0x24 )
  {
    if ( *(_DWORD *)(ipa3_ctx + 480LL * (unsigned int)a1 + 168) )
    {
      if ( *(_BYTE *)(ipa3_ctx + 32265) == 1 && (unsigned int)ipa_get_wdi_version() == 1 )
      {
        result = ipa3_resume_gsi_wdi_pipe(v2);
LABEL_41:
        _ReadStatusReg(SP_EL0);
        return result;
      }
      result = ipa3_uc_state_check();
      if ( (_DWORD)result )
        goto LABEL_41;
      v4 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v5 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v5 )
        {
          ipc_log_string(v5, "ipa %s:%d ep=%d\n", "ipa_resume_wdi_pipe", 2798, v2);
          v4 = ipa3_ctx;
        }
        v6 = *(_QWORD *)(v4 + 34160);
        if ( v6 )
        {
          ipc_log_string(v6, "ipa %s:%d ep=%d\n", "ipa_resume_wdi_pipe", 2798, v2);
          v4 = ipa3_ctx;
        }
      }
      v7 = (_DWORD *)(v4 + 480LL * v2 + 616);
      if ( *v7 != 3 )
      {
        printk(&unk_3C4C2C, "ipa_resume_wdi_pipe");
        v16 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v17 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v17 )
          {
            ipc_log_string(v17, "ipa %s:%d WDI channel bad state %d\n", "ipa_resume_wdi_pipe", 2803, *v7);
            v16 = ipa3_ctx;
          }
          v18 = *(_QWORD *)(v16 + 34160);
          if ( v18 )
            ipc_log_string(v18, "ipa %s:%d WDI channel bad state %d\n", "ipa_resume_wdi_pipe", 2803, *v7);
        }
        goto LABEL_40;
      }
      v21 = "ipa_uc_wdi.c";
      v22 = 2806;
      ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v2);
      if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v2) <= 0x85 )
        v8 = ipa_clients_strings[(unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v2)];
      else
        v8 = "Invalid Client";
      v20 = v8;
      ipa3_inc_client_enable_clks();
      if ( (unsigned int)ipa3_uc_send_cmd(v2, 0x66u, 0x60u, 0, 2500) )
      {
        v21 = "ipa_uc_wdi.c";
        v22 = 2816;
        ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v2);
        if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v2) <= 0x85 )
          v9 = ipa_clients_strings[(unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v2)];
        else
          v9 = "Invalid Client";
        v20 = v9;
        ipa3_dec_client_disable_clks();
LABEL_40:
        result = 4294967282LL;
        goto LABEL_41;
      }
      LOWORD(v20) = 0;
      result = ipa_cfg_ep_ctrl(v2, &v20);
      v13 = result;
      if ( (_DWORD)result )
      {
        printk(&unk_3C7B03, "ipa_resume_wdi_pipe");
        v19 = ipa3_ctx;
        result = v13;
        if ( !ipa3_ctx )
          goto LABEL_33;
        if ( *(_QWORD *)(ipa3_ctx + 34152) )
        {
          ipc_log_string(
            *(_QWORD *)(ipa3_ctx + 34152),
            "ipa %s:%d client (ep: %d) fail un-susp/delay result=%d\n",
            "ipa_resume_wdi_pipe",
            2824,
            v2,
            v13);
          v19 = ipa3_ctx;
          result = v13;
        }
        if ( !*(_QWORD *)(v19 + 34160) )
          goto LABEL_33;
        ipc_log_string(
          *(_QWORD *)(v19 + 34160),
          "ipa %s:%d client (ep: %d) fail un-susp/delay result=%d\n",
          "ipa_resume_wdi_pipe",
          2824,
          v2,
          v13);
      }
      else
      {
        v14 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_33;
        if ( *(_QWORD *)(ipa3_ctx + 34152) )
        {
          ipc_log_string(
            *(_QWORD *)(ipa3_ctx + 34152),
            "ipa %s:%d client (ep: %d) un-susp/delay\n",
            "ipa_resume_wdi_pipe",
            2826,
            v2);
          v14 = ipa3_ctx;
          result = 0;
        }
        if ( !*(_QWORD *)(v14 + 34160) )
          goto LABEL_33;
        ipc_log_string(
          *(_QWORD *)(v14 + 34160),
          "ipa %s:%d client (ep: %d) un-susp/delay\n",
          "ipa_resume_wdi_pipe",
          2826,
          v2);
      }
      result = v13;
LABEL_33:
      *v7 |= 4u;
      v15 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        if ( *(_QWORD *)(ipa3_ctx + 34152) )
        {
          ipc_log_string(
            *(_QWORD *)(ipa3_ctx + 34152),
            "ipa %s:%d client (ep: %d) resumed\n",
            "ipa_resume_wdi_pipe",
            2829,
            v2);
          v15 = ipa3_ctx;
          result = v13;
        }
        if ( *(_QWORD *)(v15 + 34160) )
        {
          ipc_log_string(
            *(_QWORD *)(v15 + 34160),
            "ipa %s:%d client (ep: %d) resumed\n",
            "ipa_resume_wdi_pipe",
            2829,
            v2);
          result = v13;
        }
      }
      goto LABEL_41;
    }
LABEL_20:
    printk(&unk_3A77D5, "ipa_resume_wdi_pipe");
    v10 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v11 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v11 )
      {
        ipc_log_string(v11, "ipa %s:%d bad parm, %d\n", "ipa_resume_wdi_pipe", 2787, v2);
        v10 = ipa3_ctx;
      }
      v12 = *(_QWORD *)(v10 + 34160);
      if ( v12 )
        ipc_log_string(v12, "ipa %s:%d bad parm, %d\n", "ipa_resume_wdi_pipe", 2787, v2);
    }
    result = 4294967274LL;
    goto LABEL_41;
  }
  __break(0x5512u);
  *a1 = v1;
  return ipa3_suspend_gsi_wdi_pipe((char *)a1 + 217);
}
