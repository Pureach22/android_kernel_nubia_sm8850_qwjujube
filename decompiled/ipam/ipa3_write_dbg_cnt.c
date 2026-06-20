__int64 __fastcall ipa3_write_dbg_cnt(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  int v4; // w0
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  _QWORD v9[2]; // [xsp+20h] [xbp-20h] BYREF
  int v10; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+38h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = 0;
  if ( *(_DWORD *)(ipa3_ctx + 32240) >= 0xEu )
  {
    printk(&unk_3EC0A2, "ipa3_write_dbg_cnt");
    v6 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v7 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v7 )
      {
        ipc_log_string(v7, "ipa %s:%d IPA_DEBUG_CNT_CTRL is not supported in IPA 4.0\n", "ipa3_write_dbg_cnt", 2177);
        v6 = ipa3_ctx;
      }
      v8 = *(_QWORD *)(v6 + 34160);
      if ( v8 )
        ipc_log_string(v8, "ipa %s:%d IPA_DEBUG_CNT_CTRL is not supported in IPA 4.0\n", "ipa3_write_dbg_cnt", 2177);
    }
    v3 = -1;
  }
  else
  {
    v3 = a3;
    v4 = kstrtouint_from_user(a2, a3, 0, &v10);
    if ( v4 )
    {
      v3 = v4;
    }
    else
    {
      v9[0] = 0x200000000LL;
      v9[1] = 65281;
      LOBYTE(v9[0]) = v10 == 1;
      ipa3_inc_client_enable_clks();
      ((void (__fastcall *)(__int64, _QWORD, _QWORD *))ipahal_write_reg_n_fields)(65, 0, v9);
      ipa3_dec_client_disable_clks();
    }
  }
  _ReadStatusReg(SP_EL0);
  return v3;
}
