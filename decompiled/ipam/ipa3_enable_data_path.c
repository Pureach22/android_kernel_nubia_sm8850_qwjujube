__int64 __fastcall ipa3_enable_data_path(unsigned int a1)
{
  __int64 v1; // x21
  int v3; // w0
  __int64 v4; // x8
  int v5; // w20
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  unsigned int v11; // w8
  __int64 result; // x0
  __int64 v13; // x8
  unsigned int v14; // w20
  char should_pipe_be_suspended; // w8
  unsigned int v16; // w9
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  int v20; // [xsp+0h] [xbp-20h] BYREF
  __int16 v21; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v22; // [xsp+8h] [xbp-18h] BYREF
  __int64 v23; // [xsp+10h] [xbp-10h]
  __int64 v24; // [xsp+18h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 >= 0x25 )
    __break(0x5512u);
  v22 = 0;
  v23 = 0;
  v1 = ipa3_ctx + 480LL * a1;
  v3 = ((__int64 (__fastcall *)(_QWORD))ipa_get_ep_group)(*(unsigned int *)(v1 + 172));
  v20 = v3;
  if ( v3 != -1 )
  {
    v4 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v5 = v3;
      v6 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v6 )
      {
        ipc_log_string(v6, "ipa %s:%d Setting group %d for pipe %d\n", "ipa3_enable_data_path", 55, v5, a1);
        v4 = ipa3_ctx;
      }
      v7 = *(_QWORD *)(v4 + 34160);
      if ( v7 )
        ipc_log_string(v7, "ipa %s:%d Setting group %d for pipe %d\n", "ipa3_enable_data_path", 55, v5, a1);
    }
    ((void (__fastcall *)(__int64, _QWORD, int *))ipahal_write_reg_n_fields)(62, a1, &v20);
    v8 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v9 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v9 )
      {
        ipc_log_string(v9, "ipa %s:%d Enabling data path\n", "ipa3_enable_data_path", 59);
        v8 = ipa3_ctx;
      }
      v10 = *(_QWORD *)(v8 + 34160);
      if ( v10 )
        ipc_log_string(v10, "ipa %s:%d Enabling data path\n", "ipa3_enable_data_path", 59);
    }
    v11 = *(_DWORD *)(v1 + 172);
    result = 0;
    if ( v11 > 0x85 || (v11 & 1) == 0 )
      goto LABEL_20;
    v22 = 0;
    v23 = 0;
    if ( (unsigned int)(unsigned __int8)v11 - 81 <= 0x2C
      && ((1LL << ((unsigned __int8)v11 - 81)) & 0x100004000001LL) != 0
      || (unsigned __int8)v11 == 27 )
    {
      WORD2(v23) = 1;
LABEL_19:
      result = ipa3_cfg_ep_holb(a1, &v22);
LABEL_20:
      if ( *(_DWORD *)(ipa3_ctx + 32240) <= 0xDu )
      {
        v13 = *(unsigned int *)(v1 + 172);
        if ( (unsigned int)v13 <= 0x85 && (v13 & 1) != 0 )
        {
          if ( (*(_BYTE *)(v1 + 573) & 1) != 0
            || (*(_BYTE *)(ipa3_ctx + v13 + 17500) & 1) != 0
            || (v14 = result,
                should_pipe_be_suspended = ipa3_should_pipe_be_suspended((unsigned int)v13),
                result = v14,
                (should_pipe_be_suspended & 1) == 0) )
          {
            v21 = 0;
            result = ipa_cfg_ep_ctrl(a1, &v21);
          }
        }
      }
      goto LABEL_37;
    }
    v16 = *(_DWORD *)(ipa3_ctx + 32240);
    if ( v16 == 20 )
    {
      if ( (unsigned __int8)v11 <= 0x13u && ((1 << v11) & 0x82800) != 0 )
      {
        WORD2(v23) = 1;
        LODWORD(v22) = 31;
      }
      goto LABEL_19;
    }
    if ( v16 < 0x16 )
    {
      if ( v11 != 19 || v16 != 17 )
        goto LABEL_19;
    }
    else
    {
      if ( v11 == 19 && *(_DWORD *)(ipa3_ctx + 32256) == 2 )
      {
        WORD2(v23) = 1;
        LODWORD(v22) = 31;
        goto LABEL_19;
      }
      if ( v16 == 22 || (unsigned __int8)v11 != 35 && (unsigned __int8)v11 != 19 && (v11 != 95 || v16 < 0x18) )
        goto LABEL_19;
    }
    LODWORD(v22) = 31;
    WORD2(v23) = 1;
    goto LABEL_19;
  }
  printk(&unk_3D2409, "ipa3_enable_data_path");
  v17 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v18 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v18 )
    {
      ipc_log_string(v18, "ipa %s:%d invalid group for client %d\n", "ipa3_enable_data_path", 49, *(_DWORD *)(v1 + 172));
      v17 = ipa3_ctx;
    }
    v19 = *(_QWORD *)(v17 + 34160);
    if ( v19 )
      ipc_log_string(v19, "ipa %s:%d invalid group for client %d\n", "ipa3_enable_data_path", 49, *(_DWORD *)(v1 + 172));
  }
  __break(0x800u);
  result = 4294967282LL;
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return result;
}
