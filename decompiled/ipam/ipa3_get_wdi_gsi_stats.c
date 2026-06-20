__int64 __fastcall ipa3_get_wdi_gsi_stats(_DWORD *a1)
{
  int v2; // w0
  __int64 v3; // x8
  int v4; // w0
  __int64 v5; // x8
  int v6; // w0
  __int64 v7; // x8
  __int64 result; // x0
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0

  _ReadStatusReg(SP_EL0);
  if ( *(_QWORD *)(ipa3_ctx + 44952) )
  {
    ipa3_inc_client_enable_clks();
    *a1 = readl_0(*(_QWORD *)(ipa3_ctx + 44952));
    a1[1] = readl_0(*(_QWORD *)(ipa3_ctx + 44952) + 4LL);
    v2 = readl_0(*(_QWORD *)(ipa3_ctx + 44952) + 8LL);
    v3 = ipa3_ctx;
    a1[2] = v2;
    v4 = readl_0(*(_QWORD *)(v3 + 44952) + 12LL);
    v5 = ipa3_ctx;
    a1[3] = v4;
    v6 = readl_0(*(_QWORD *)(v5 + 44952) + 16LL);
    v7 = ipa3_ctx;
    a1[4] = v6;
    a1[5] = readl_0(*(_QWORD *)(v7 + 44952) + 20LL);
    a1[6] = readl_0(*(_QWORD *)(ipa3_ctx + 44952) + 24LL);
    a1[7] = readl_0(*(_QWORD *)(ipa3_ctx + 44952) + 28LL);
    a1[8] = readl_0(*(_QWORD *)(ipa3_ctx + 44952) + 32LL);
    a1[9] = readl_0(*(_QWORD *)(ipa3_ctx + 44952) + 36LL);
    ipa3_dec_client_disable_clks();
    result = 0;
  }
  else
  {
    printk(&unk_3D8ED5, "ipa3_get_wdi_gsi_stats");
    v9 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v10 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v10 )
      {
        ipc_log_string(v10, "ipa %s:%d bad NULL parms for wdi_gsi_stats\n", "ipa3_get_wdi_gsi_stats", 446);
        v9 = ipa3_ctx;
      }
      v11 = *(_QWORD *)(v9 + 34160);
      if ( v11 )
        ipc_log_string(v11, "ipa %s:%d bad NULL parms for wdi_gsi_stats\n", "ipa3_get_wdi_gsi_stats", 446);
    }
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
