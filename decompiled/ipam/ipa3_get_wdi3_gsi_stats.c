__int64 __fastcall ipa3_get_wdi3_gsi_stats(_DWORD *a1)
{
  int v2; // w0
  __int64 v3; // x8
  int v4; // w0
  __int64 v5; // x8
  int v6; // w0
  __int64 v7; // x8
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  if ( *(_QWORD *)(ipa3_ctx + 45032) )
  {
    ipa3_inc_client_enable_clks();
    *a1 = readl_1(*(_QWORD *)(ipa3_ctx + 45032));
    a1[1] = readl_1(*(_QWORD *)(ipa3_ctx + 45032) + 4LL);
    v2 = readl_1(*(_QWORD *)(ipa3_ctx + 45032) + 8LL);
    v3 = ipa3_ctx;
    a1[2] = v2;
    v4 = readl_1(*(_QWORD *)(v3 + 45032) + 12LL);
    v5 = ipa3_ctx;
    a1[3] = v4;
    v6 = readl_1(*(_QWORD *)(v5 + 45032) + 16LL);
    v7 = ipa3_ctx;
    a1[4] = v6;
    a1[5] = readl_1(*(_QWORD *)(v7 + 45032) + 20LL);
    a1[6] = readl_1(*(_QWORD *)(ipa3_ctx + 45032) + 24LL);
    a1[7] = readl_1(*(_QWORD *)(ipa3_ctx + 45032) + 28LL);
    a1[8] = readl_1(*(_QWORD *)(ipa3_ctx + 45032) + 32LL);
    a1[9] = readl_1(*(_QWORD *)(ipa3_ctx + 45032) + 36LL);
    a1[10] = readl_1(*(_QWORD *)(ipa3_ctx + 45032) + 40LL);
    a1[11] = readl_1(*(_QWORD *)(ipa3_ctx + 45032) + 44LL);
    a1[12] = readl_1(*(_QWORD *)(ipa3_ctx + 45032) + 48LL);
    a1[13] = readl_1(*(_QWORD *)(ipa3_ctx + 45032) + 52LL);
    a1[14] = readl_1(*(_QWORD *)(ipa3_ctx + 45032) + 56LL);
    ipa3_dec_client_disable_clks();
    result = 0;
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
