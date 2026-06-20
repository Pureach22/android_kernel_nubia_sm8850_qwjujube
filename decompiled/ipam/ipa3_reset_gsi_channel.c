__int64 __fastcall ipa3_reset_gsi_channel(_QWORD *a1)
{
  __int64 v1; // x13
  unsigned int v2; // w19
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x22
  __int64 v6; // x22
  int v7; // t1
  int v8; // w23
  int v9; // w0
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 result; // x0
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x0
  int v16; // w20
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  _QWORD v20[5]; // [xsp+18h] [xbp-28h] BYREF

  v2 = (unsigned int)a1;
  v20[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = ipa3_ctx;
  memset(v20, 0, 31);
  if ( ipa3_ctx )
  {
    v4 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v4 )
    {
      ipc_log_string(v4, "ipa %s:%d entry\n", "ipa3_reset_gsi_channel", 184);
      v3 = ipa3_ctx;
    }
    a1 = *(_QWORD **)(v3 + 34160);
    if ( a1 )
    {
      a1 = (_QWORD *)ipc_log_string(a1, "ipa %s:%d entry\n", "ipa3_reset_gsi_channel", 184);
      v3 = ipa3_ctx;
    }
  }
  if ( *(_DWORD *)(v3 + 34308) <= v2 )
    goto LABEL_35;
  if ( v2 >= 0x24 )
  {
    __break(0x5512u);
    *a1 = v1;
    JUMPOUT(0x8D2B0);
  }
  v5 = v3 + 480LL * v2;
  v7 = *(_DWORD *)(v5 + 168);
  v6 = v5 + 168;
  if ( !v7 )
  {
LABEL_35:
    printk(&unk_3D52A7, "ipa3_reset_gsi_channel");
    v13 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_40;
    v14 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v14 )
    {
      ipc_log_string(v14, "ipa %s:%d Bad parameter\n", "ipa3_reset_gsi_channel", 187);
      v13 = ipa3_ctx;
    }
    v15 = *(_QWORD *)(v13 + 34160);
    if ( v15 )
    {
      ipc_log_string(v15, "ipa %s:%d Bad parameter\n", "ipa3_reset_gsi_channel", 187);
      result = 4294967274LL;
    }
    else
    {
LABEL_40:
      result = 4294967274LL;
    }
    goto LABEL_31;
  }
  if ( (*(_BYTE *)(v6 + 405) & 1) == 0 )
  {
    ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v2);
    if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v2) <= 0x85 )
      ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v2);
    ipa3_inc_client_enable_clks();
    v3 = ipa3_ctx;
  }
  if ( *(_DWORD *)(v3 + 32240) < 0xEu || *(_DWORD *)(v6 + 244) || !*(_DWORD *)(v6 + 240) )
  {
    v8 = 0;
  }
  else
  {
    ipahal_read_reg_n_fields(99, 0, v20);
    v8 = 0;
    if ( HIBYTE(v20[0]) == 1 )
    {
      HIBYTE(v20[0]) = 0;
      ((void (__fastcall *)(__int64, _QWORD, _QWORD *))ipahal_write_reg_n_fields)(99, 0, v20);
      v8 = 1;
    }
  }
  usleep_range_state(1010, 1050, 2);
  v9 = gsi_reset_channel(*(_QWORD *)(v6 + 8));
  if ( v9 )
  {
    v16 = v9;
    printk(&unk_3F1BD8, "ipa3_reset_gsi_channel");
    v17 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v18 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v18 )
      {
        ipc_log_string(v18, "ipa %s:%d Error resetting channel: %d\n", "ipa3_reset_gsi_channel", 222, v16);
        v17 = ipa3_ctx;
      }
      v19 = *(_QWORD *)(v17 + 34160);
      if ( v19 )
        ipc_log_string(v19, "ipa %s:%d Error resetting channel: %d\n", "ipa3_reset_gsi_channel", 222, v16);
    }
    if ( (v8 & 1) != 0 )
    {
      HIBYTE(v20[0]) = 0;
      ((void (__fastcall *)(__int64, _QWORD, _QWORD *))ipahal_write_reg_n_fields)(99, 0, v20);
    }
    if ( (*(_BYTE *)(v6 + 405) & 1) == 0 )
    {
      ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v2);
      if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v2) <= 0x85 )
        ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v2);
      ipa3_dec_client_disable_clks();
    }
    result = 4294967282LL;
    goto LABEL_31;
  }
  if ( v8 )
  {
    HIBYTE(v20[0]) = 0;
    ((void (__fastcall *)(__int64, _QWORD, _QWORD *))ipahal_write_reg_n_fields)(99, 0, v20);
    if ( (*(_BYTE *)(v6 + 405) & 1) == 0 )
      goto LABEL_19;
  }
  else if ( (*(_BYTE *)(v6 + 405) & 1) == 0 )
  {
LABEL_19:
    ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v2);
    if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v2) <= 0x85 )
      ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v2);
    ipa3_dec_client_disable_clks();
    v10 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_30;
    goto LABEL_26;
  }
  v10 = ipa3_ctx;
  if ( !ipa3_ctx )
    goto LABEL_30;
LABEL_26:
  v11 = *(_QWORD *)(v10 + 34152);
  if ( v11 )
  {
    ipc_log_string(v11, "ipa %s:%d exit\n", "ipa3_reset_gsi_channel", 236);
    v10 = ipa3_ctx;
  }
  result = *(_QWORD *)(v10 + 34160);
  if ( result )
  {
    ipc_log_string(result, "ipa %s:%d exit\n", "ipa3_reset_gsi_channel", 236);
LABEL_30:
    result = 0;
  }
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return result;
}
