__int64 __fastcall ipa3_uc_reg_rdyCB(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x8
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0

  if ( a1 )
  {
    result = ipa3_uc_state_check();
    if ( (_DWORD)result )
    {
      *(_BYTE *)a1 = 0;
      v3 = ipa3_ctx + 40960;
      *(_QWORD *)(ipa3_ctx + 43168) = *(_QWORD *)(a1 + 16);
      *(_QWORD *)(v3 + 2200) = *(_QWORD *)(a1 + 8);
      return 0;
    }
    else
    {
      *(_BYTE *)a1 = 1;
    }
  }
  else
  {
    printk(&unk_3D0697, "ipa3_uc_reg_rdyCB");
    v4 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v5 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v5 )
      {
        ipc_log_string(v5, "ipa %s:%d bad parm. inout=%pK ", "ipa3_uc_reg_rdyCB", 3205, nullptr);
        v4 = ipa3_ctx;
      }
      v6 = *(_QWORD *)(v4 + 34160);
      if ( v6 )
        ipc_log_string(v6, "ipa %s:%d bad parm. inout=%pK ", "ipa3_uc_reg_rdyCB", 3205, nullptr);
    }
    return 4294967274LL;
  }
  return result;
}
