__int64 __fastcall ipa3_clear_endpoint_delay(unsigned int a1)
{
  __int64 v2; // x23
  __int64 v3; // x23
  int v4; // t1
  int ep_bit; // w20
  unsigned int ep_reg_idx; // w0
  __int64 v7; // x8
  unsigned int v8; // w21
  __int64 v9; // x0
  __int64 v10; // x0
  int v11; // w0
  __int64 v12; // x8
  int v13; // w20
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 result; // x0
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 v24; // x0
  __int16 v25; // [xsp+24h] [xbp-2Ch] BYREF
  __int64 v26; // [xsp+28h] [xbp-28h] BYREF
  _QWORD v27[2]; // [xsp+30h] [xbp-20h]
  int v28; // [xsp+40h] [xbp-10h]
  __int64 v29; // [xsp+48h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25 = 0;
  v28 = 0;
  v27[0] = 0;
  v27[1] = 0;
  v26 = 0;
  if ( !ipa3_ctx )
  {
    printk(&unk_3D53CC, "ipa3_clear_endpoint_delay");
    v22 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v23 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v23 )
      {
        ipc_log_string(v23, "ipa %s:%d IPA driver was not initialized\n", "ipa3_clear_endpoint_delay", 1995);
        v22 = ipa3_ctx;
      }
      v24 = *(_QWORD *)(v22 + 34160);
      if ( v24 )
      {
        ipc_log_string(v24, "ipa %s:%d IPA driver was not initialized\n", "ipa3_clear_endpoint_delay", 1995);
        goto LABEL_40;
      }
    }
LABEL_46:
    result = 4294967274LL;
    goto LABEL_34;
  }
  if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
    goto LABEL_35;
  if ( a1 >= 0x24 )
    goto LABEL_47;
  v2 = ipa3_ctx + 480LL * a1;
  v4 = *(_DWORD *)(v2 + 168);
  v3 = v2 + 168;
  if ( !v4 )
  {
LABEL_35:
    printk(&unk_3F1C1D, "ipa3_clear_endpoint_delay");
    v19 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v20 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v20 )
      {
        ipc_log_string(v20, "ipa %s:%d bad parm.\n", "ipa3_clear_endpoint_delay", 2001);
        v19 = ipa3_ctx;
      }
      v21 = *(_QWORD *)(v19 + 34160);
      if ( v21 )
      {
        ipc_log_string(v21, "ipa %s:%d bad parm.\n", "ipa3_clear_endpoint_delay", 2001);
LABEL_40:
        result = 4294967274LL;
        goto LABEL_34;
      }
    }
    goto LABEL_46;
  }
  if ( (*(_BYTE *)(ipa3_ctx + 43636) & 1) != 0 )
    goto LABEL_24;
  ep_bit = ipahal_get_ep_bit(a1);
  ep_reg_idx = ipahal_get_ep_reg_idx(a1);
  v7 = ipa3_ctx;
  v8 = ep_reg_idx;
  if ( ipa3_ctx )
  {
    v9 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v9 )
    {
      ipc_log_string(v9, "ipa %s:%d APPS flow control is not enabled\n", "ipa3_clear_endpoint_delay", 2010);
      v7 = ipa3_ctx;
    }
    v10 = *(_QWORD *)(v7 + 34160);
    if ( v10 )
    {
      ipc_log_string(v10, "ipa %s:%d APPS flow control is not enabled\n", "ipa3_clear_endpoint_delay", 2010);
      v7 = ipa3_ctx;
    }
  }
  HIDWORD(v26) = a1;
  if ( *(_DWORD *)(v7 + 32240) <= 0x14u )
  {
    if ( v8 )
      __break(0x800u);
    LODWORD(v26) = ep_bit;
    goto LABEL_17;
  }
  BYTE2(v27[0]) = 1;
  if ( v8 > 3 )
LABEL_47:
    __break(0x5512u);
  *((_DWORD *)v27 + v8 + 1) = ep_bit;
LABEL_17:
  v11 = ipa3_qmi_enable_force_clear_datapath_send(&v26);
  if ( v11 )
  {
    v12 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v13 = v11;
      v14 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v14 )
      {
        ipc_log_string(v14, "ipa %s:%d enable_force_clear_datapath failed %d\n", "ipa3_clear_endpoint_delay", 2024, v13);
        v12 = ipa3_ctx;
      }
      v15 = *(_QWORD *)(v12 + 34160);
      if ( v15 )
        ipc_log_string(v15, "ipa %s:%d enable_force_clear_datapath failed %d\n", "ipa3_clear_endpoint_delay", 2024, v13);
    }
  }
  *(_DWORD *)(v3 + 460) = 1;
LABEL_24:
  ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1);
  if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1) <= 0x85 )
    ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1);
  ipa3_inc_client_enable_clks();
  *(_DWORD *)(v3 + 456) = 1;
  v25 = 0;
  ipa_cfg_ep_ctrl(a1, &v25);
  ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1);
  if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1) <= 0x85 )
    ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1);
  ipa3_dec_client_disable_clks();
  v16 = ipa3_ctx;
  if ( !ipa3_ctx )
    goto LABEL_33;
  v17 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v17 )
  {
    ipc_log_string(v17, "ipa %s:%d client (ep: %d) removed ep delay\n", "ipa3_clear_endpoint_delay", 2042, a1);
    v16 = ipa3_ctx;
  }
  result = *(_QWORD *)(v16 + 34160);
  if ( result )
  {
    ipc_log_string(result, "ipa %s:%d client (ep: %d) removed ep delay\n", "ipa3_clear_endpoint_delay", 2042, a1);
LABEL_33:
    result = 0;
  }
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return result;
}
