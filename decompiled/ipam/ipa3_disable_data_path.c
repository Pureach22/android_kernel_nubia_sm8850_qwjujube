__int64 __fastcall ipa3_disable_data_path(unsigned int a1)
{
  __int64 v3; // x8
  __int64 v4; // x22
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x20
  _DWORD *v8; // x20
  unsigned int v9; // t1
  int v10; // w10
  __int64 result; // x0
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x0
  unsigned int v16; // w20
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  unsigned int v20; // w20
  __int64 v21; // x0
  __int64 v22; // x8
  __int64 v23; // x0
  _QWORD v24[3]; // [xsp+8h] [xbp-38h] BYREF
  int v25; // [xsp+20h] [xbp-20h]
  __int16 v26; // [xsp+24h] [xbp-1Ch] BYREF
  __int128 v27; // [xsp+28h] [xbp-18h] BYREF
  __int64 v28; // [xsp+38h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 >= 0x25 )
    __break(0x5512u);
  v3 = ipa3_ctx;
  v27 = 0u;
  v26 = 0;
  v4 = ipa3_ctx + 168;
  v25 = 0;
  memset(v24, 0, sizeof(v24));
  if ( ipa3_ctx )
  {
    v5 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v5 )
    {
      ipc_log_string(v5, "ipa %s:%d Disabling data path\n", "ipa3_disable_data_path", 127);
      v3 = ipa3_ctx;
    }
    v6 = *(_QWORD *)(v3 + 34160);
    if ( v6 )
    {
      ipc_log_string(v6, "ipa %s:%d Disabling data path\n", "ipa3_disable_data_path", 127);
      v3 = ipa3_ctx;
    }
  }
  v7 = v4 + 480LL * a1;
  v9 = *(_DWORD *)(v7 + 4);
  v8 = (_DWORD *)(v7 + 4);
  v10 = v9 & 1;
  if ( v9 > 0x85 || v10 == 0 )
  {
    result = 0;
  }
  else
  {
    if ( *(_BYTE *)(v3 + 43308) == 1 && (unsigned int)ipa3_uc_state_check() )
    {
      v13 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v14 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v14 )
        {
          ipc_log_string(v14, "ipa %s:%d uC is not loaded yet, waiting...\n", "ipa3_disable_data_path", 134);
          v13 = ipa3_ctx;
        }
        v15 = *(_QWORD *)(v13 + 34160);
        if ( v15 )
        {
          ipc_log_string(v15, "ipa %s:%d uC is not loaded yet, waiting...\n", "ipa3_disable_data_path", 134);
          v13 = ipa3_ctx;
        }
      }
      if ( !(unsigned int)wait_for_completion_timeout(v13 + 43688, 15000) )
      {
        v17 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v18 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v18 )
          {
            ipc_log_string(v18, "ipa %s:%d timeout waiting for uC load\n", "ipa3_disable_data_path", 139);
            v17 = ipa3_ctx;
          }
          v19 = *(_QWORD *)(v17 + 34160);
          if ( v19 )
            ipc_log_string(v19, "ipa %s:%d timeout waiting for uC load\n", "ipa3_disable_data_path", 139);
        }
      }
    }
    HIDWORD(v27) = 1;
    *(_QWORD *)((char *)&v27 + 4) = 0;
    LODWORD(v27) = 0;
    result = ipa3_cfg_ep_holb(a1, &v27);
    v3 = ipa3_ctx;
  }
  if ( *(_DWORD *)(v3 + 32240) <= 0xDu )
  {
    if ( *v8 <= 0x85u && (*v8 & 1) != 0 )
    {
      v26 = 1;
      LODWORD(result) = ipa_cfg_ep_ctrl(a1, &v26);
    }
    v16 = result;
    _const_udelay(429500);
    ipahal_read_reg_n_fields(43, a1, v24);
    result = v16;
    if ( LODWORD(v24[0]) )
    {
      result = ipa3_tag_aggr_force_close(a1);
      if ( (_DWORD)result )
      {
        v20 = result;
        v21 = printk(&unk_3AF1C9, "ipa3_disable_data_path");
        v22 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v23 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v23 )
          {
            ipc_log_string(
              v23,
              "ipa %s:%d tag process timeout client:%d err:%d\n",
              "ipa3_disable_data_path",
              167,
              a1,
              v20);
            v22 = ipa3_ctx;
          }
          v21 = *(_QWORD *)(v22 + 34160);
          if ( v21 )
            v21 = ipc_log_string(
                    v21,
                    "ipa %s:%d tag process timeout client:%d err:%d\n",
                    "ipa3_disable_data_path",
                    167,
                    a1,
                    v20);
        }
        ((void (__fastcall *)(__int64))ipa_assert)(v21);
        result = v20;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
