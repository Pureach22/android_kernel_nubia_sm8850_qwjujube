__int64 __fastcall ipa3_nat_get_sram_info(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x9
  int v6; // w23
  int v7; // w24
  unsigned int v8; // w20
  int v9; // w8
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0

  v2 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v3 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v3 )
      ipc_log_string(v3, "ipa %s:%d In\n", "ipa3_nat_get_sram_info", 2495);
    v4 = *(_QWORD *)(ipa3_ctx + 34160);
    if ( v4 )
      ipc_log_string(v4, "ipa %s:%d In\n", "ipa3_nat_get_sram_info", 2495);
  }
  if ( !a1 )
  {
    printk(&unk_3F5604, "ipa3_nat_get_sram_info");
    v10 = ipa3_ctx;
    if ( !ipa3_ctx )
      return (unsigned int)-22;
    v15 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v15 )
    {
      ipc_log_string(v15, "ipa %s:%d Bad argument passed\n", "ipa3_nat_get_sram_info", 2498);
      v10 = ipa3_ctx;
    }
    v16 = *(_QWORD *)(v10 + 34160);
    if ( v16 )
    {
      ipc_log_string(v16, "ipa %s:%d Bad argument passed\n", "ipa3_nat_get_sram_info", 2498);
      v8 = -22;
      goto LABEL_15;
    }
    v8 = -22;
    goto LABEL_16;
  }
  if ( (*(_BYTE *)(v2 + 29750) & 1) != 0 )
  {
    *(_QWORD *)a1 = 0;
    *(_DWORD *)(a1 + 8) = 0;
    *(_DWORD *)a1 = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 184LL);
    v5 = *(_QWORD *)(ipa3_ctx + 34176);
    v6 = *(_DWORD *)(ipa3_ctx + 28640);
    sram_compatible = 1;
    v7 = *(_DWORD *)(v5 + 36);
    v8 = 0;
    v9 = ((_WORD)v7
        + (_WORD)v6
        + (unsigned __int16)((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(64, 0, 0)
        + (unsigned __int16)*(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 180LL))
       & 0xFFF;
    *(_DWORD *)(a1 + 4) = v9;
    *(_DWORD *)(a1 + 8) = (v9 + *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 184LL) + 4095) & 0xFFFFF000;
LABEL_15:
    v10 = ipa3_ctx;
    goto LABEL_16;
  }
  if ( (unsigned int)__ratelimit(&ipa3_nat_get_sram_info__rs, "ipa3_nat_get_sram_info") )
  {
    printk(&unk_3B8435, "ipa3_nat_get_sram_info");
    v10 = ipa3_ctx;
    if ( ipa3_ctx )
      goto LABEL_11;
    return (unsigned int)-1;
  }
  v10 = ipa3_ctx;
  if ( !ipa3_ctx )
    return (unsigned int)-1;
LABEL_11:
  v11 = *(_QWORD *)(v10 + 34152);
  if ( v11 )
  {
    ipc_log_string(v11, "ipa %s:%d NAT hasn't been initialized\n", "ipa3_nat_get_sram_info", 2504);
    v10 = ipa3_ctx;
  }
  v12 = *(_QWORD *)(v10 + 34160);
  if ( v12 )
  {
    ipc_log_string(v12, "ipa %s:%d NAT hasn't been initialized\n", "ipa3_nat_get_sram_info", 2504);
    v8 = -1;
    goto LABEL_15;
  }
  v8 = -1;
LABEL_16:
  if ( v10 )
  {
    v13 = *(_QWORD *)(v10 + 34152);
    if ( v13 )
    {
      ipc_log_string(v13, "ipa %s:%d Out\n", "ipa3_nat_get_sram_info", 2547);
      v10 = ipa3_ctx;
    }
    v14 = *(_QWORD *)(v10 + 34160);
    if ( v14 )
      ipc_log_string(v14, "ipa %s:%d Out\n", "ipa3_nat_get_sram_info", 2547);
  }
  return v8;
}
