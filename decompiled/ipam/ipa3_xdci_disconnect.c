__int64 __fastcall ipa3_xdci_disconnect(unsigned int a1, char a2, unsigned int a3)
{
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x25
  __int64 v10; // x25
  int v11; // t1
  unsigned int v12; // w5
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x0
  unsigned int v16; // w0
  __int64 v17; // x0
  __int64 v18; // x0
  unsigned int ep_bit; // w22
  unsigned int ep_reg_idx; // w0
  unsigned int v21; // w0
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 result; // x0
  __int64 v25; // x8
  __int64 v26; // x0
  __int64 v27; // x0
  unsigned int v28; // w20
  __int64 v29; // x8
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x8
  __int64 v33; // x0
  __int64 v34; // x0
  __int16 v35; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v36; // [xsp+28h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = ipa3_ctx;
  v35 = 0;
  if ( ipa3_ctx )
  {
    v7 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v7 )
    {
      ipc_log_string(v7, "ipa %s:%d entry\n", "ipa3_xdci_disconnect", 1566);
      v6 = ipa3_ctx;
    }
    v8 = *(_QWORD *)(v6 + 34160);
    if ( v8 )
    {
      ipc_log_string(v8, "ipa %s:%d entry\n", "ipa3_xdci_disconnect", 1566);
      v6 = ipa3_ctx;
    }
  }
  if ( *(_DWORD *)(v6 + 34308) <= a1 )
    goto LABEL_38;
  if ( a1 < 0x24 )
  {
    v9 = v6 + 480LL * a1;
    v11 = *(_DWORD *)(v9 + 168);
    v10 = v9 + 168;
    if ( v11 )
    {
      if ( (*(_BYTE *)(v10 + 405) & 1) == 0 )
      {
        ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1);
        if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1) <= 0x85 )
          ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1);
        ipa3_inc_client_enable_clks();
      }
      ipa3_disable_data_path(a1);
      v12 = *(_DWORD *)(v10 + 4);
      v13 = ipa3_ctx;
      if ( v12 <= 0x85 && (v12 & 1) != 0 )
      {
        if ( ipa3_ctx )
        {
          v14 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v14 )
          {
            ipc_log_string(
              v14,
              "ipa %s:%d Stopping CONS channel - hdl=%d clnt=%d\n",
              "ipa3_xdci_disconnect",
              1595,
              a1,
              v12);
            v13 = ipa3_ctx;
          }
          v15 = *(_QWORD *)(v13 + 34160);
          if ( v15 )
            ipc_log_string(
              v15,
              "ipa %s:%d Stopping CONS channel - hdl=%d clnt=%d\n",
              "ipa3_xdci_disconnect",
              1595,
              a1,
              *(_DWORD *)(v10 + 4));
        }
        v16 = ipa_stop_gsi_channel(a1);
        if ( !v16 )
        {
          if ( *(_DWORD *)(ipa3_ctx + 32240) <= 0xDu )
          {
            v35 = 0;
            ipa_cfg_ep_ctrl(a1, &v35);
          }
          goto LABEL_29;
        }
        v28 = v16;
        printk(&unk_3E3579, "ipa3_xdci_disconnect");
        v32 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v33 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v33 )
          {
            ipc_log_string(
              v33,
              "ipa %s:%d Error stopping channel (CONS client): %d\n",
              "ipa3_xdci_disconnect",
              1599,
              v28);
            v32 = ipa3_ctx;
          }
          v34 = *(_QWORD *)(v32 + 34160);
          if ( v34 )
            ipc_log_string(
              v34,
              "ipa %s:%d Error stopping channel (CONS client): %d\n",
              "ipa3_xdci_disconnect",
              1599,
              v28);
        }
      }
      else
      {
        if ( ipa3_ctx )
        {
          v17 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v17 )
          {
            ipc_log_string(
              v17,
              "ipa %s:%d Stopping PROD channel - hdl=%d clnt=%d\n",
              "ipa3_xdci_disconnect",
              1582,
              a1,
              v12);
            v13 = ipa3_ctx;
          }
          v18 = *(_QWORD *)(v13 + 34160);
          if ( v18 )
            ipc_log_string(
              v18,
              "ipa %s:%d Stopping PROD channel - hdl=%d clnt=%d\n",
              "ipa3_xdci_disconnect",
              1582,
              a1,
              *(_DWORD *)(v10 + 4));
        }
        ep_bit = ipahal_get_ep_bit(a1);
        ep_reg_idx = ipahal_get_ep_reg_idx(a1);
        v21 = ipa3_stop_ul_chan_with_data_drain(a3, ep_bit, ep_reg_idx, a2 & 1, a1, 1);
        if ( !v21 )
        {
LABEL_29:
          ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1);
          if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1) <= 0x85 )
            ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1);
          ipa3_dec_client_disable_clks();
          v22 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v23 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v23 )
            {
              ipc_log_string(v23, "ipa %s:%d exit\n", "ipa3_xdci_disconnect", 1611);
              v22 = ipa3_ctx;
            }
            result = *(_QWORD *)(v22 + 34160);
            if ( !result )
              goto LABEL_37;
            ipc_log_string(result, "ipa %s:%d exit\n", "ipa3_xdci_disconnect", 1611);
          }
          result = 0;
LABEL_37:
          _ReadStatusReg(SP_EL0);
          return result;
        }
        v28 = v21;
        printk(&unk_3C07B0, "ipa3_xdci_disconnect");
        v29 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v30 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v30 )
          {
            ipc_log_string(v30, "ipa %s:%d Fail to stop UL channel with data drain\n", "ipa3_xdci_disconnect", 1589);
            v29 = ipa3_ctx;
          }
          v31 = *(_QWORD *)(v29 + 34160);
          if ( v31 )
            ipc_log_string(v31, "ipa %s:%d Fail to stop UL channel with data drain\n", "ipa3_xdci_disconnect", 1589);
        }
        __break(0x800u);
      }
      if ( (*(_BYTE *)(v10 + 405) & 1) == 0 )
      {
        ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1);
        if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1) <= 0x85 )
          ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1);
        ipa3_dec_client_disable_clks();
      }
      result = v28;
      goto LABEL_37;
    }
LABEL_38:
    printk(&unk_3F1C01, "ipa3_xdci_disconnect");
    v25 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v26 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v26 )
      {
        ipc_log_string(v26, "ipa %s:%d Bad parameter.\n", "ipa3_xdci_disconnect", 1569);
        v25 = ipa3_ctx;
      }
      v27 = *(_QWORD *)(v25 + 34160);
      if ( v27 )
        ipc_log_string(v27, "ipa %s:%d Bad parameter.\n", "ipa3_xdci_disconnect", 1569);
    }
    result = 4294967274LL;
    goto LABEL_37;
  }
  __break(0x5512u);
  return ((__int64 (*)(void))ipa3_stop_ul_chan_with_data_drain)();
}
