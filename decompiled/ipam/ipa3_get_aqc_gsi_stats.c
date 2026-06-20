__int64 __fastcall ipa3_get_aqc_gsi_stats(_DWORD *a1)
{
  __int64 v2; // x24
  int v3; // w0
  __int64 v4; // x23
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  if ( *(_QWORD *)(ipa3_ctx + 45080) )
  {
    ipa3_inc_client_enable_clks();
    v2 = ipa3_ctx;
    *a1 = readl(*(_QWORD *)(ipa3_ctx + 45080));
    a1[1] = readl(*(_QWORD *)(v2 + 45080) + 4LL);
    a1[2] = readl(*(_QWORD *)(v2 + 45080) + 8LL);
    a1[3] = readl(*(_QWORD *)(v2 + 45080) + 12LL);
    v3 = readl(*(_QWORD *)(v2 + 45080) + 16LL);
    v4 = ipa3_ctx;
    a1[4] = v3;
    a1[5] = readl(*(_QWORD *)(v4 + 45080) + 20LL);
    a1[6] = readl(*(_QWORD *)(v4 + 45080) + 24LL);
    a1[7] = readl(*(_QWORD *)(v4 + 45080) + 28LL);
    a1[8] = readl(*(_QWORD *)(v4 + 45080) + 32LL);
    a1[9] = readl(*(_QWORD *)(v4 + 45080) + 36LL);
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
