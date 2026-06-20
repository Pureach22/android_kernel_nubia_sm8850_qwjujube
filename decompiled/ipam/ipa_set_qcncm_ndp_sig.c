__int64 __fastcall ipa_set_qcncm_ndp_sig(unsigned __int8 *a1)
{
  __int64 result; // x0
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // [xsp+18h] [xbp-18h] BYREF
  int v10; // [xsp+20h] [xbp-10h]
  __int64 v11; // [xsp+28h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = 0;
  v9 = 0;
  if ( *(_DWORD *)(ipa3_ctx + 32240) >= 0xEu )
  {
    printk(&unk_3FEC5A, "ipa_set_qcncm_ndp_sig");
    v3 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_15;
    v4 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v4 )
    {
      ipc_log_string(v4, "ipa %s:%d QCNCM mode is not supported staring 4.0\n", "ipa_set_qcncm_ndp_sig", 10200);
      v3 = ipa3_ctx;
    }
    v5 = *(_QWORD *)(v3 + 34160);
    if ( v5 )
    {
      ipc_log_string(v5, "ipa %s:%d QCNCM mode is not supported staring 4.0\n", "ipa_set_qcncm_ndp_sig", 10200);
      result = 0xFFFFFFFFLL;
    }
    else
    {
LABEL_15:
      result = 0xFFFFFFFFLL;
    }
  }
  else if ( a1 )
  {
    ipa3_inc_client_enable_clks();
    ipahal_read_reg_n_fields(70, 0, &v9);
    HIDWORD(v9) = (*a1 << 16) | (a1[1] << 8) | a1[2];
    ((void (__fastcall *)(__int64, _QWORD, __int64 *))ipahal_write_reg_n_fields)(70, 0, &v9);
    ipa3_dec_client_disable_clks();
    result = 0;
  }
  else
  {
    printk(&unk_3AD8D3, "ipa_set_qcncm_ndp_sig");
    v6 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_16;
    v7 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v7 )
    {
      ipc_log_string(v7, "ipa %s:%d bad argument\n", "ipa_set_qcncm_ndp_sig", 10205);
      v6 = ipa3_ctx;
    }
    v8 = *(_QWORD *)(v6 + 34160);
    if ( v8 )
    {
      ipc_log_string(v8, "ipa %s:%d bad argument\n", "ipa_set_qcncm_ndp_sig", 10205);
      result = 4294967274LL;
    }
    else
    {
LABEL_16:
      result = 4294967274LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
