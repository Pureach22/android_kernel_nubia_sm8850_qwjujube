__int64 __fastcall ipa3_get_usb_gsi_stats(_DWORD *a1)
{
  int v2; // w0
  __int64 v3; // x8
  int v4; // w0
  __int64 v5; // x8
  int v6; // w0
  __int64 v7; // x8
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  if ( *(_QWORD *)(ipa3_ctx + 45048) )
  {
    ipa3_inc_client_enable_clks();
    *a1 = readl(*(_QWORD *)(ipa3_ctx + 45048));
    a1[1] = readl(*(_QWORD *)(ipa3_ctx + 45048) + 4LL);
    v2 = readl(*(_QWORD *)(ipa3_ctx + 45048) + 8LL);
    v3 = ipa3_ctx;
    a1[2] = v2;
    v4 = readl(*(_QWORD *)(v3 + 45048) + 12LL);
    v5 = ipa3_ctx;
    a1[3] = v4;
    v6 = readl(*(_QWORD *)(v5 + 45048) + 16LL);
    v7 = ipa3_ctx;
    a1[4] = v6;
    a1[5] = readl(*(_QWORD *)(v7 + 45048) + 20LL);
    a1[6] = readl(*(_QWORD *)(ipa3_ctx + 45048) + 24LL);
    a1[7] = readl(*(_QWORD *)(ipa3_ctx + 45048) + 28LL);
    a1[8] = readl(*(_QWORD *)(ipa3_ctx + 45048) + 32LL);
    a1[9] = readl(*(_QWORD *)(ipa3_ctx + 45048) + 36LL);
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
