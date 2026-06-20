__int64 __fastcall ipa_enable_wdi_pipe(_QWORD *a1)
{
  __int64 v1; // x13
  unsigned int v2; // w19
  __int64 result; // x0
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x23
  unsigned int v8; // w0
  unsigned int v9; // w24
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0
  unsigned int v13; // w8
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // [xsp+18h] [xbp-18h] BYREF
  __int64 v21; // [xsp+20h] [xbp-10h]
  __int64 v22; // [xsp+28h] [xbp-8h]

  v2 = (unsigned int)a1;
  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  v21 = 0;
  if ( *(_BYTE *)(ipa3_ctx + 51102) == 1 )
  {
    result = ipa_pm_wrapper_enable_wdi_pipe((unsigned int)a1);
LABEL_37:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( *(_DWORD *)(ipa3_ctx + 34308) <= (unsigned int)a1 )
  {
LABEL_23:
    printk(&unk_3A77D5, "ipa_enable_wdi_pipe");
    v10 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_36;
    v11 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v11 )
    {
      ipc_log_string(v11, "ipa %s:%d bad parm, %d\n", "ipa_enable_wdi_pipe", 2533, v2);
      v10 = ipa3_ctx;
    }
    v12 = *(_QWORD *)(v10 + 34160);
    if ( v12 )
    {
      ipc_log_string(v12, "ipa %s:%d bad parm, %d\n", "ipa_enable_wdi_pipe", 2533, v2);
      result = 4294967274LL;
    }
    else
    {
LABEL_36:
      result = 4294967274LL;
    }
    goto LABEL_37;
  }
  if ( (unsigned int)a1 < 0x24 )
  {
    if ( *(_DWORD *)(ipa3_ctx + 480LL * (unsigned int)a1 + 168) )
    {
      if ( *(_BYTE *)(ipa3_ctx + 32265) == 1 && (unsigned int)ipa_get_wdi_version() == 1 )
      {
        result = ipa3_enable_gsi_wdi_pipe(v2);
      }
      else
      {
        result = ipa3_uc_state_check();
        if ( !(_DWORD)result )
        {
          v4 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v5 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v5 )
            {
              ipc_log_string(v5, "ipa %s:%d ep=%d\n", "ipa_enable_wdi_pipe", 2544, v2);
              v4 = ipa3_ctx;
            }
            v6 = *(_QWORD *)(v4 + 34160);
            if ( v6 )
            {
              ipc_log_string(v6, "ipa %s:%d ep=%d\n", "ipa_enable_wdi_pipe", 2544, v2);
              v4 = ipa3_ctx;
            }
          }
          v7 = v4 + 480LL * v2;
          if ( *(_DWORD *)(v7 + 616) == 1 )
          {
            ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v2);
            if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v2) <= 0x85 )
              ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v2);
            ipa3_inc_client_enable_clks();
            v8 = ipa3_uc_send_cmd(v2, 0x63u, 0x60u, 0, 2500);
            if ( v8 )
            {
              v9 = -14;
            }
            else
            {
              v13 = *(_DWORD *)(v7 + 172);
              if ( v13 <= 0x85 && (v13 & 1) != 0 )
              {
                v20 = 0;
                v21 = 0;
                v8 = ipa3_cfg_ep_holb(v2, &v20);
              }
              v9 = v8;
              *(_DWORD *)(v7 + 616) |= 2u;
              v14 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v15 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v15 )
                {
                  ipc_log_string(v15, "ipa %s:%d client (ep: %d) enabled\n", "ipa_enable_wdi_pipe", 2573, v2);
                  v14 = ipa3_ctx;
                }
                v16 = *(_QWORD *)(v14 + 34160);
                if ( v16 )
                  ipc_log_string(v16, "ipa %s:%d client (ep: %d) enabled\n", "ipa_enable_wdi_pipe", 2573, v2);
              }
            }
            ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v2);
            if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v2) <= 0x85 )
              ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v2);
            ipa3_dec_client_disable_clks();
            result = v9;
          }
          else
          {
            printk(&unk_3C4C2C, "ipa_enable_wdi_pipe");
            v17 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v18 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v18 )
              {
                ipc_log_string(
                  v18,
                  "ipa %s:%d WDI channel bad state %d\n",
                  "ipa_enable_wdi_pipe",
                  2549,
                  *(_DWORD *)(v7 + 616));
                v17 = ipa3_ctx;
              }
              v19 = *(_QWORD *)(v17 + 34160);
              if ( v19 )
                ipc_log_string(
                  v19,
                  "ipa %s:%d WDI channel bad state %d\n",
                  "ipa_enable_wdi_pipe",
                  2549,
                  *(_DWORD *)(v7 + 616));
            }
            result = 4294967282LL;
          }
        }
      }
      goto LABEL_37;
    }
    goto LABEL_23;
  }
  __break(0x5512u);
  *a1 = v1;
  return ipa_pm_wrapper_enable_wdi_pipe((char *)a1 + 217);
}
