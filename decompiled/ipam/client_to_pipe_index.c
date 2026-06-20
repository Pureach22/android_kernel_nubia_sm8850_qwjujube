__int64 __fastcall client_to_pipe_index(int a1)
{
  __int64 v2; // x0
  long double v3; // q0
  __int64 v4; // x8
  __int64 v5; // x0

  if ( a1 > 107 )
  {
    if ( a1 > 115 )
    {
      if ( a1 == 116 )
        return 7;
      if ( a1 == 117 )
        return 6;
    }
    else
    {
      if ( a1 == 108 )
        return 3;
      if ( a1 == 109 )
        return 2;
    }
  }
  else if ( a1 > 101 )
  {
    if ( a1 == 102 )
      return 5;
    if ( a1 == 103 )
      return 4;
  }
  else
  {
    if ( a1 == 48 )
      return 1;
    if ( a1 == 49 )
      return 0;
  }
  v2 = printk(&unk_3FC8E0, "client_to_pipe_index");
  v4 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v5 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v5 )
    {
      v3 = ipc_log_string(v5, "ipa %s:%d invalid eth client_type\n", "client_to_pipe_index", 120);
      v4 = ipa3_ctx;
    }
    v2 = *(_QWORD *)(v4 + 34160);
    if ( v2 )
      v3 = ipc_log_string(v2, "ipa %s:%d invalid eth client_type\n", "client_to_pipe_index", 120);
  }
  ((void (__fastcall *)(__int64, long double))ipa_assert)(v2, v3);
  return 0;
}
