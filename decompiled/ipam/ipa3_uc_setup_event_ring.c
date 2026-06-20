__int64 ipa3_uc_setup_event_ring()
{
  __int64 v0; // x24
  __int64 v1; // x20
  __int64 v2; // x0
  __int64 v3; // x2
  __int64 v4; // x0
  __int64 v5; // x0
  _DWORD *v6; // x0
  _DWORD *v7; // x19
  unsigned int v8; // w23
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 result; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  _DWORD *v14; // [xsp+20h] [xbp-20h]
  __int64 v15; // [xsp+28h] [xbp-18h] BYREF
  __int64 v16; // [xsp+30h] [xbp-10h]
  __int64 v17; // [xsp+38h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  v16 = 0;
  v0 = ipa3_ctx + 0x8000;
  v1 = ipa3_ctx + 34872;
  v2 = *(_QWORD *)(ipa3_ctx + 34224);
  v3 = ipa3_ctx + 34872;
  *(_DWORD *)(ipa3_ctx + 34880) = 160;
  v4 = dma_alloc_attrs(v2, 160, v3, 3264, 0);
  *(_QWORD *)(v0 + 2096) = v4;
  if ( !v4 )
    goto LABEL_7;
  v5 = *(_QWORD *)(ipa3_ctx + 34224);
  LODWORD(v16) = 24;
  v6 = (_DWORD *)dma_alloc_attrs(v5, 24, &v15, 3264, 0);
  v14 = v6;
  if ( !v6 )
  {
    dma_free_attrs(
      *(_QWORD *)(ipa3_ctx + 34224),
      *(unsigned int *)(v0 + 2112),
      *(_QWORD *)(v0 + 2096),
      *(_QWORD *)(v0 + 2104),
      0);
LABEL_7:
    result = 4294967284LL;
    goto LABEL_8;
  }
  v7 = v6;
  *v6 = *(_QWORD *)v1;
  v6[1] = *(_DWORD *)(v1 + 4);
  v6[2] = 10;
  ipa3_inc_client_enable_clks();
  v8 = ipa3_uc_send_cmd_64b_param(v15, 0, 12, 0, 0, 2500);
  if ( v8 )
  {
    printk(&unk_3BBA6C, "ipa3_uc_setup_event_ring");
    v10 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v12 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v12 )
      {
        ipc_log_string(
          v12,
          "ipa %s:%d  faile to setup event ring 0x%x 0x%x, size %d\n",
          "ipa3_uc_setup_event_ring",
          1708,
          *v7,
          v7[1],
          v7[2]);
        v10 = ipa3_ctx;
      }
      v13 = *(_QWORD *)(v10 + 34160);
      if ( v13 )
      {
        ipc_log_string(
          v13,
          "ipa %s:%d  faile to setup event ring 0x%x 0x%x, size %d\n",
          "ipa3_uc_setup_event_ring",
          1708,
          *v7,
          v7[1],
          v7[2]);
        v10 = ipa3_ctx;
      }
    }
  }
  else
  {
    v9 = ipa3_ctx + 0x8000;
    *(_BYTE *)(ipa3_ctx + 34856) = 1;
    *(_DWORD *)(v9 + 2124) = 0;
    *(_DWORD *)(v9 + 2120) = *(_DWORD *)(v0 + 2112) - 16;
    ((void (__fastcall *)(__int64, _QWORD, __int64, _QWORD))ipahal_write_reg_mn)(66, 0, 1, 0);
    ((void (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD))ipahal_write_reg_mn)(
      66,
      0,
      0,
      *(unsigned int *)(ipa3_ctx + 34888));
    v10 = ipa3_ctx;
    *(_QWORD *)(ipa3_ctx + 34896) = *(unsigned int *)(ipa3_ctx + 34888);
  }
  dma_free_attrs(*(_QWORD *)(v10 + 34224), (unsigned int)v16, v14, v15, 0);
  ipa3_dec_client_disable_clks();
  result = v8;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
