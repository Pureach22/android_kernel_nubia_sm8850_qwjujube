__int64 __fastcall ipa3_get_ntn_stats(_DWORD *a1)
{
  __int64 v2; // x9
  __int64 v3; // x9
  __int64 result; // x0
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0

  _ReadStatusReg(SP_EL0);
  if ( !ipa3_ctx )
  {
    printk(&unk_3D53CC, "ipa3_get_ntn_stats");
    v8 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v9 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v9 )
      {
        ipc_log_string(v9, "ipa %s:%d IPA driver was not initialized\n", "ipa3_get_ntn_stats", 74);
        v8 = ipa3_ctx;
      }
      v10 = *(_QWORD *)(v8 + 34160);
      if ( v10 )
        ipc_log_string(v10, "ipa %s:%d IPA driver was not initialized\n", "ipa3_get_ntn_stats", 74);
    }
    goto LABEL_11;
  }
  if ( !a1 || !*(_QWORD *)(ipa3_ctx + 43192) )
  {
    printk(&unk_3A434E, "ipa3_get_ntn_stats");
    v5 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v6 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v6 )
      {
        ipc_log_string(
          v6,
          "ipa %s:%d bad parms stats=%pK ntn_stats=%pK\n",
          "ipa3_get_ntn_stats",
          81,
          a1,
          *(const void **)(ipa3_ctx + 43192));
        v5 = ipa3_ctx;
      }
      v7 = *(_QWORD *)(v5 + 34160);
      if ( v7 )
        ipc_log_string(
          v7,
          "ipa %s:%d bad parms stats=%pK ntn_stats=%pK\n",
          "ipa3_get_ntn_stats",
          81,
          a1,
          *(const void **)(v5 + 43192));
    }
LABEL_11:
    result = 4294967274LL;
    goto LABEL_5;
  }
  ipa3_inc_client_enable_clks();
  v2 = ipa3_ctx;
  a1[28] = *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 43192) + 112LL);
  a1[29] = *(_DWORD *)(*(_QWORD *)(v2 + 43192) + 116LL);
  a1[30] = *(_DWORD *)(*(_QWORD *)(v2 + 43192) + 120LL);
  a1[31] = *(_DWORD *)(*(_QWORD *)(v2 + 43192) + 124LL);
  a1[32] = *(_DWORD *)(*(_QWORD *)(v2 + 43192) + 128LL);
  a1[33] = *(_DWORD *)(*(_QWORD *)(v2 + 43192) + 132LL);
  a1[34] = *(_DWORD *)(*(_QWORD *)(v2 + 43192) + 136LL);
  a1[35] = *(_DWORD *)(*(_QWORD *)(v2 + 43192) + 140LL);
  a1[36] = *(_DWORD *)(*(_QWORD *)(v2 + 43192) + 144LL);
  a1[37] = *(_DWORD *)(*(_QWORD *)(v2 + 43192) + 148LL);
  a1[38] = *(_DWORD *)(*(_QWORD *)(v2 + 43192) + 152LL);
  a1[39] = *(_DWORD *)(*(_QWORD *)(v2 + 43192) + 156LL);
  a1[40] = *(_DWORD *)(*(_QWORD *)(v2 + 43192) + 160LL);
  a1[41] = *(_DWORD *)(*(_QWORD *)(v2 + 43192) + 164LL);
  a1[42] = *(_DWORD *)(*(_QWORD *)(v2 + 43192) + 112LL);
  a1[43] = *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 43192) + 116LL);
  a1[44] = *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 43192) + 120LL);
  a1[45] = *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 43192) + 124LL);
  a1[46] = *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 43192) + 128LL);
  a1[47] = *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 43192) + 132LL);
  a1[48] = *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 43192) + 136LL);
  a1[49] = *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 43192) + 140LL);
  a1[50] = *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 43192) + 144LL);
  a1[51] = *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 43192) + 148LL);
  a1[52] = *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 43192) + 152LL);
  a1[53] = *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 43192) + 156LL);
  a1[54] = *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 43192) + 160LL);
  a1[55] = *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 43192) + 164LL);
  *a1 = **(_DWORD **)(ipa3_ctx + 43192);
  a1[1] = *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 43192) + 4LL);
  v3 = ipa3_ctx;
  a1[2] = *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 43192) + 8LL);
  a1[3] = *(_DWORD *)(*(_QWORD *)(v3 + 43192) + 12LL);
  a1[4] = *(_DWORD *)(*(_QWORD *)(v3 + 43192) + 16LL);
  a1[5] = *(_DWORD *)(*(_QWORD *)(v3 + 43192) + 20LL);
  a1[6] = *(_DWORD *)(*(_QWORD *)(v3 + 43192) + 24LL);
  a1[7] = *(_DWORD *)(*(_QWORD *)(v3 + 43192) + 28LL);
  a1[8] = *(_DWORD *)(*(_QWORD *)(v3 + 43192) + 32LL);
  a1[9] = *(_DWORD *)(*(_QWORD *)(v3 + 43192) + 36LL);
  a1[10] = *(_DWORD *)(*(_QWORD *)(v3 + 43192) + 40LL);
  a1[11] = *(_DWORD *)(*(_QWORD *)(v3 + 43192) + 44LL);
  a1[12] = *(_DWORD *)(*(_QWORD *)(v3 + 43192) + 48LL);
  a1[13] = *(_DWORD *)(*(_QWORD *)(v3 + 43192) + 52LL);
  a1[14] = *(_DWORD *)(*(_QWORD *)(v3 + 43192) + 56LL);
  a1[15] = *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 43192) + 60LL);
  a1[16] = *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 43192) + 64LL);
  a1[17] = *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 43192) + 68LL);
  a1[18] = *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 43192) + 72LL);
  a1[19] = *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 43192) + 76LL);
  a1[20] = *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 43192) + 80LL);
  a1[21] = *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 43192) + 84LL);
  a1[22] = *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 43192) + 88LL);
  a1[23] = *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 43192) + 92LL);
  a1[24] = *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 43192) + 96LL);
  a1[25] = *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 43192) + 100LL);
  a1[26] = *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 43192) + 104LL);
  a1[27] = *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 43192) + 108LL);
  ipa3_dec_client_disable_clks();
  result = 0;
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
