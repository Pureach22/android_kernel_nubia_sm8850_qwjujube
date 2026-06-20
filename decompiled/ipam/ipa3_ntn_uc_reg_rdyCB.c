__int64 __fastcall ipa3_ntn_uc_reg_rdyCB(__int64 a1, __int64 a2)
{
  __int64 v5; // x8
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0

  if ( ipa3_ctx )
  {
    if ( (unsigned int)ipa3_uc_state_check() )
    {
      v5 = ipa3_ctx + 40960;
      *(_QWORD *)(ipa3_ctx + 43208) = a1;
      *(_QWORD *)(v5 + 2240) = a2;
      return 0;
    }
    else
    {
      return 4294967279LL;
    }
  }
  else
  {
    printk(&unk_3A437D, "ipa3_ntn_uc_reg_rdyCB");
    v6 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v7 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v7 )
      {
        ipc_log_string(v7, "ipa %s:%d IPA ctx is null\n", "ipa3_ntn_uc_reg_rdyCB", 132);
        v6 = ipa3_ctx;
      }
      v8 = *(_QWORD *)(v6 + 34160);
      if ( v8 )
        ipc_log_string(v8, "ipa %s:%d IPA ctx is null\n", "ipa3_ntn_uc_reg_rdyCB", 132);
    }
    return 4294967290LL;
  }
}
