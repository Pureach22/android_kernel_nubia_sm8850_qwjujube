__int64 __fastcall ipa_set_single_ndp_per_mbim(char a1)
{
  char v1; // w21
  __int64 result; // x0
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x0
  _QWORD v6[2]; // [xsp+20h] [xbp-10h] BYREF

  v6[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6[0] = 0;
  if ( *(_DWORD *)(ipa3_ctx + 32240) >= 0xEu )
  {
    printk(&unk_3FEC5A, "ipa_set_single_ndp_per_mbim");
    v3 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v4 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v4 )
      {
        ipc_log_string(v4, "ipa %s:%d QCNCM mode is not supported staring 4.0\n", "ipa_set_single_ndp_per_mbim", 10230);
        v3 = ipa3_ctx;
      }
      v5 = *(_QWORD *)(v3 + 34160);
      if ( v5 )
        ipc_log_string(v5, "ipa %s:%d QCNCM mode is not supported staring 4.0\n", "ipa_set_single_ndp_per_mbim", 10230);
    }
    result = 0xFFFFFFFFLL;
  }
  else
  {
    v1 = a1 & 1;
    ipa3_inc_client_enable_clks();
    ipahal_read_reg_n_fields(69, 0, v6);
    LOBYTE(v6[0]) = v1;
    ((void (__fastcall *)(__int64, _QWORD, _QWORD *))ipahal_write_reg_n_fields)(69, 0, v6);
    ipa3_dec_client_disable_clks();
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
