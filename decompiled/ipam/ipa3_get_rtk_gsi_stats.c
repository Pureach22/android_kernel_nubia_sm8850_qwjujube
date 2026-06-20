__int64 __fastcall ipa3_get_rtk_gsi_stats(__int64 a1)
{
  __int64 v2; // x20
  int v3; // w0
  __int64 v4; // x8
  int v5; // w0
  __int64 v6; // x8
  int v7; // w0
  __int64 v8; // x8
  int v9; // w0
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x20
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  if ( *(_QWORD *)(ipa3_ctx + 45096) )
  {
    ipa3_inc_client_enable_clks();
    v2 = ipa3_ctx;
    *(_DWORD *)a1 = readl(*(_QWORD *)(ipa3_ctx + 45096));
    *(_DWORD *)(a1 + 4) = readl(*(_QWORD *)(v2 + 45096) + 4LL);
    *(_DWORD *)(a1 + 8) = readl(*(_QWORD *)(v2 + 45096) + 8LL);
    *(_DWORD *)(a1 + 12) = readl(*(_QWORD *)(v2 + 45096) + 12LL);
    v3 = readl(*(_QWORD *)(v2 + 45096) + 16LL);
    v4 = ipa3_ctx;
    *(_DWORD *)(a1 + 16) = v3;
    v5 = readl(*(_QWORD *)(v4 + 45096) + 20LL);
    v6 = ipa3_ctx;
    *(_DWORD *)(a1 + 20) = v5;
    v7 = readl(*(_QWORD *)(v6 + 45096) + 24LL);
    v8 = ipa3_ctx;
    *(_DWORD *)(a1 + 24) = v7;
    v9 = readl(*(_QWORD *)(v8 + 45096) + 28LL);
    v10 = ipa3_ctx;
    *(_DWORD *)(a1 + 28) = v9;
    LODWORD(v2) = readl(*(_QWORD *)(v10 + 45096) + 32LL);
    v11 = readl(*(_QWORD *)(ipa3_ctx + 45096) + 36LL);
    v12 = (unsigned int)v2;
    v13 = ipa3_ctx;
    *(_QWORD *)(a1 + 32) = v12 | (v11 << 32);
    *(_DWORD *)(a1 + 40) = readl(*(_QWORD *)(v13 + 45096) + 20LL);
    *(_DWORD *)(a1 + 44) = readl(*(_QWORD *)(v13 + 45096) + 24LL);
    *(_DWORD *)(a1 + 48) = readl(*(_QWORD *)(v13 + 45096) + 28LL);
    *(_DWORD *)(a1 + 52) = readl(*(_QWORD *)(v13 + 45096) + 32LL);
    *(_DWORD *)(a1 + 56) = readl(*(_QWORD *)(v13 + 45096) + 36LL);
    *(_DWORD *)(a1 + 60) = readl(*(_QWORD *)(ipa3_ctx + 45096) + 60LL);
    *(_DWORD *)(a1 + 64) = readl(*(_QWORD *)(ipa3_ctx + 45096) + 64LL);
    *(_DWORD *)(a1 + 68) = readl(*(_QWORD *)(ipa3_ctx + 45096) + 68LL);
    LODWORD(v13) = readl(*(_QWORD *)(ipa3_ctx + 45096) + 72LL);
    *(_QWORD *)(a1 + 72) = (unsigned int)v13 | (unsigned __int64)(readl(*(_QWORD *)(ipa3_ctx + 45096) + 76LL) << 32);
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
