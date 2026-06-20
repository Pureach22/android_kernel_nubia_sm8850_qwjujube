__int64 ipa3_setup_uc_act_tbl()
{
  __int64 v0; // x20
  __int64 v1; // x0
  __int64 v2; // x0
  __int64 result; // x0
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0
  int v10; // [xsp+20h] [xbp-20h] BYREF
  int v11; // [xsp+24h] [xbp-1Ch] BYREF
  __int64 v12; // [xsp+28h] [xbp-18h] BYREF
  int v13; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+38h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = 0;
  v10 = 0;
  if ( *(_DWORD *)(ipa3_ctx + 32240) <= 0x10u )
  {
    printk(&unk_3DF1BA, "ipa3_setup_uc_act_tbl");
    v4 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_17;
    v5 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v5 )
    {
      ipc_log_string(v5, "ipa %s:%d Not support!\n", "ipa3_setup_uc_act_tbl", 14515);
      v4 = ipa3_ctx;
    }
    v6 = *(_QWORD *)(v4 + 34160);
    if ( v6 )
    {
      ipc_log_string(v6, "ipa %s:%d Not support!\n", "ipa3_setup_uc_act_tbl", 14515);
      result = 0xFFFFFFFFLL;
    }
    else
    {
LABEL_17:
      result = 0xFFFFFFFFLL;
    }
  }
  else
  {
    v0 = ipa3_ctx + 51304;
    if ( *(_BYTE *)(ipa3_ctx + 51328) == 1 )
    {
      printk(&unk_3D9201, "ipa3_setup_uc_act_tbl");
      v7 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_18;
      v8 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v8 )
      {
        ipc_log_string(v8, "ipa %s:%d  already allocate uC act tbl\n", "ipa3_setup_uc_act_tbl", 14520);
        v7 = ipa3_ctx;
      }
      v9 = *(_QWORD *)(v7 + 34160);
      if ( v9 )
      {
        ipc_log_string(v9, "ipa %s:%d  already allocate uC act tbl\n", "ipa3_setup_uc_act_tbl", 14520);
        result = 4294967279LL;
      }
      else
      {
LABEL_18:
        result = 4294967279LL;
      }
    }
    else
    {
      v1 = *(_QWORD *)(ipa3_ctx + 34216);
      *(_DWORD *)(ipa3_ctx + 51320) = 128000;
      v2 = dma_alloc_attrs(v1, 128000, v0 + 8, 3264, 0);
      *(_QWORD *)v0 = v2;
      if ( v2 )
      {
        memset(*(void **)v0, 0, *(unsigned int *)(v0 + 16));
        *(_BYTE *)(ipa3_ctx + 51328) = 1;
        ipa3_inc_client_enable_clks();
        v13 = *(_QWORD *)(v0 + 8);
        ((void (__fastcall *)(__int64, _QWORD, int *))ipahal_write_reg_n_fields)(143, 0, &v13);
        HIDWORD(v12) = *(unsigned __int16 *)(v0 + 12);
        ((void (__fastcall *)(__int64, _QWORD, __int64 *))ipahal_write_reg_n_fields)(145, 0, &v12);
        v11 = *(_QWORD *)(v0 + 8);
        ((void (__fastcall *)(__int64, _QWORD, int *))ipahal_write_reg_n_fields)(146, 0, &v11);
        HIWORD(v10) = *(_DWORD *)(v0 + 12);
        ((void (__fastcall *)(__int64, _QWORD, int *))ipahal_write_reg_n_fields)(148, 0, &v10);
        ipa3_dec_client_disable_clks();
        result = 0;
      }
      else
      {
        result = 4294967284LL;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
