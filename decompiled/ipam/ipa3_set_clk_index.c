__int64 __fastcall ipa3_set_clk_index(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  int v4; // w0
  __int64 v5; // x1
  int v7; // w20
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  _BYTE v14[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v3 = a3;
  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14[0] = 0;
  v4 = kstrtos8_from_user(a2, a3, 0, v14);
  if ( v4 )
  {
    v3 = v4;
  }
  else
  {
    v7 = v14[0];
    if ( (unsigned int)v14[0] >= 5 )
    {
      printk(&unk_3C96F7, v14[0]);
      v3 = -14;
    }
    else
    {
      printk(&unk_3EBFC8, v5);
      *(_DWORD *)(ipa3_ctx + 34236) = 1;
      if ( (unsigned int)ipa3_set_clock_plan_from_pm(v7) )
      {
        printk(&unk_3A30CA, "ipa3_set_clk_index");
        v11 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v12 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v12 )
          {
            ipc_log_string(v12, "ipa %s:%d Failed to vote for bus BW (%u)\n", "ipa3_set_clk_index", 504, v7);
            v11 = ipa3_ctx;
          }
          v13 = *(_QWORD *)(v11 + 34160);
          if ( v13 )
            ipc_log_string(v13, "ipa %s:%d Failed to vote for bus BW (%u)\n", "ipa3_set_clk_index", 504, v7);
        }
        v3 = -14;
      }
      else
      {
        *(_DWORD *)(ipa3_ctx + 34236) = 0;
        printk(&unk_3FACF6, "ipa3_set_clk_index");
        v8 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v9 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v9 )
          {
            ipc_log_string(v9, "ipa %s:%d Clock scaling is done sucessful\n", "ipa3_set_clk_index", 508);
            v8 = ipa3_ctx;
          }
          v10 = *(_QWORD *)(v8 + 34160);
          if ( v10 )
            ipc_log_string(v10, "ipa %s:%d Clock scaling is done sucessful\n", "ipa3_set_clk_index", 508);
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return v3;
}
