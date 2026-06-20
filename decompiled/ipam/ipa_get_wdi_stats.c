__int64 __fastcall ipa_get_wdi_stats(_DWORD *a1)
{
  __int64 v2; // x9
  __int64 v3; // x9
  __int64 result; // x0
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 v7; // x0

  _ReadStatusReg(SP_EL0);
  if ( a1 && *(_QWORD *)(ipa3_ctx + 43152) )
  {
    ipa3_inc_client_enable_clks();
    v2 = ipa3_ctx;
    a1[22] = *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 43152) + 88LL);
    a1[23] = *(_DWORD *)(*(_QWORD *)(v2 + 43152) + 92LL);
    a1[24] = *(_DWORD *)(*(_QWORD *)(v2 + 43152) + 96LL);
    a1[25] = *(_DWORD *)(*(_QWORD *)(v2 + 43152) + 100LL);
    a1[26] = *(_DWORD *)(*(_QWORD *)(v2 + 43152) + 104LL);
    a1[27] = *(_DWORD *)(*(_QWORD *)(v2 + 43152) + 108LL);
    a1[28] = *(_DWORD *)(*(_QWORD *)(v2 + 43152) + 112LL);
    a1[29] = *(_DWORD *)(*(_QWORD *)(v2 + 43152) + 116LL);
    a1[30] = *(_DWORD *)(*(_QWORD *)(v2 + 43152) + 120LL);
    a1[31] = *(_DWORD *)(*(_QWORD *)(v2 + 43152) + 124LL);
    a1[32] = *(_DWORD *)(*(_QWORD *)(v2 + 43152) + 128LL);
    a1[33] = *(_DWORD *)(*(_QWORD *)(v2 + 43152) + 132LL);
    a1[34] = *(_DWORD *)(*(_QWORD *)(v2 + 43152) + 136LL);
    a1[35] = *(_DWORD *)(*(_QWORD *)(v2 + 43152) + 140LL);
    a1[36] = *(_DWORD *)(*(_QWORD *)(v2 + 43152) + 144LL);
    a1[37] = *(_DWORD *)(*(_QWORD *)(v2 + 43152) + 148LL);
    a1[38] = *(_DWORD *)(*(_QWORD *)(v2 + 43152) + 152LL);
    a1[39] = *(_DWORD *)(*(_QWORD *)(v2 + 43152) + 156LL);
    a1[40] = *(_DWORD *)(*(_QWORD *)(v2 + 43152) + 160LL);
    *a1 = **(_DWORD **)(v2 + 43152);
    a1[1] = *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 43152) + 4LL);
    v3 = ipa3_ctx;
    a1[2] = *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 43152) + 8LL);
    a1[3] = *(_DWORD *)(*(_QWORD *)(v3 + 43152) + 12LL);
    a1[4] = *(_DWORD *)(*(_QWORD *)(v3 + 43152) + 16LL);
    a1[5] = *(_DWORD *)(*(_QWORD *)(v3 + 43152) + 20LL);
    a1[6] = *(_DWORD *)(*(_QWORD *)(v3 + 43152) + 24LL);
    a1[7] = *(_DWORD *)(*(_QWORD *)(v3 + 43152) + 28LL);
    a1[8] = *(_DWORD *)(*(_QWORD *)(v3 + 43152) + 32LL);
    a1[9] = *(_DWORD *)(*(_QWORD *)(v3 + 43152) + 36LL);
    a1[10] = *(_DWORD *)(*(_QWORD *)(v3 + 43152) + 40LL);
    a1[11] = *(_DWORD *)(*(_QWORD *)(v3 + 43152) + 44LL);
    a1[12] = *(_DWORD *)(*(_QWORD *)(v3 + 43152) + 48LL);
    a1[13] = *(_DWORD *)(*(_QWORD *)(v3 + 43152) + 52LL);
    a1[14] = *(_DWORD *)(*(_QWORD *)(v3 + 43152) + 56LL);
    a1[15] = *(_DWORD *)(*(_QWORD *)(v3 + 43152) + 60LL);
    a1[16] = *(_DWORD *)(*(_QWORD *)(v3 + 43152) + 64LL);
    a1[17] = *(_DWORD *)(*(_QWORD *)(v3 + 43152) + 68LL);
    a1[18] = *(_DWORD *)(*(_QWORD *)(v3 + 43152) + 72LL);
    a1[19] = *(_DWORD *)(*(_QWORD *)(v3 + 43152) + 76LL);
    a1[20] = *(_DWORD *)(*(_QWORD *)(v3 + 43152) + 80LL);
    a1[21] = *(_DWORD *)(*(_QWORD *)(v3 + 43152) + 84LL);
    ipa3_dec_client_disable_clks();
    result = 0;
  }
  else
  {
    printk(&unk_3A4415, "ipa_get_wdi_stats");
    v5 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v6 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v6 )
      {
        ipc_log_string(
          v6,
          "ipa %s:%d bad parms stats=%pK wdi_stats=%pK\n",
          "ipa_get_wdi_stats",
          497,
          a1,
          *(const void **)(ipa3_ctx + 43152));
        v5 = ipa3_ctx;
      }
      v7 = *(_QWORD *)(v5 + 34160);
      if ( v7 )
        ipc_log_string(
          v7,
          "ipa %s:%d bad parms stats=%pK wdi_stats=%pK\n",
          "ipa_get_wdi_stats",
          497,
          a1,
          *(const void **)(v5 + 43152));
    }
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
