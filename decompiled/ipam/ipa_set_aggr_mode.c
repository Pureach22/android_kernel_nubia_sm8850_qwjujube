__int64 __fastcall ipa_set_aggr_mode(int a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 result; // x0
  __int64 v6; // [xsp+18h] [xbp-18h] BYREF
  int v7; // [xsp+20h] [xbp-10h]
  __int64 v8; // [xsp+28h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = 0;
  v6 = 0;
  if ( *(_DWORD *)(ipa3_ctx + 32240) < 0xEu )
  {
    ipa3_inc_client_enable_clks();
    ipahal_read_reg_n_fields(70, 0, &v6);
    LOBYTE(v6) = a1 != 0;
    ((void (__fastcall *)(__int64, _QWORD, __int64 *))ipahal_write_reg_n_fields)(70, 0, &v6);
    ipa3_dec_client_disable_clks();
    goto LABEL_9;
  }
  if ( !a1 )
  {
LABEL_9:
    result = 0;
    goto LABEL_10;
  }
  printk(&unk_3CA649, "ipa_set_aggr_mode");
  v2 = ipa3_ctx;
  if ( !ipa3_ctx )
    goto LABEL_11;
  v3 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v3 )
  {
    ipc_log_string(v3, "ipa %s:%d Only MBIM mode is supported staring 4.0\n", "ipa_set_aggr_mode", 10169);
    v2 = ipa3_ctx;
  }
  v4 = *(_QWORD *)(v2 + 34160);
  if ( v4 )
  {
    ipc_log_string(v4, "ipa %s:%d Only MBIM mode is supported staring 4.0\n", "ipa_set_aggr_mode", 10169);
    result = 0xFFFFFFFFLL;
  }
  else
  {
LABEL_11:
    result = 0xFFFFFFFFLL;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
