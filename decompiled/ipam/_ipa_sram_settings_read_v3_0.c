__int64 ipa_sram_settings_read_v3_0()
{
  __int64 result; // x0
  __int16 v1; // w10
  __int64 v2; // x12
  __int64 v3; // x11
  __int16 v4; // w8
  int v5; // w8
  __int64 v6; // x8
  bool v7; // w9
  _QWORD v8[2]; // [xsp+0h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8[0] = 0;
  result = ipahal_read_reg_n_fields(63, 0, v8);
  v1 = 8 * LOWORD(v8[0]);
  v2 = ipa3_ctx + 29176;
  v3 = *(_QWORD *)(ipa3_ctx + 34176);
  *(_WORD *)(ipa3_ctx + 29522) = 8 * WORD2(v8[0]);
  *(_WORD *)(v2 + 344) = v1;
  v4 = *(_DWORD *)(*(_QWORD *)v3 + 244LL);
  *(_BYTE *)(v2 + 1232) = 1;
  *(_WORD *)(v2 + 348) = v4;
  v5 = *(_DWORD *)(*(_QWORD *)v3 + 164LL);
  *(_WORD *)(v2 + 1288) = 0;
  *(_BYTE *)(v2 + 1290) = 0;
  *(_DWORD *)v2 = v5;
  *(_BYTE *)(ipa3_ctx + 30467) = 0;
  *(_WORD *)(ipa3_ctx + 30468) = 0;
  v6 = ipa3_ctx + 28672;
  v7 = *(_DWORD *)(ipa3_ctx + 32240) == 21;
  *(_BYTE *)(ipa3_ctx + 30470) = v7;
  *(_BYTE *)(v6 + 1799) = v7;
  _ReadStatusReg(SP_EL0);
  return result;
}
