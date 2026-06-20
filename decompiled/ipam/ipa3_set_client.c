__int64 __fastcall ipa3_set_client(__int64 result, int a2, char a3)
{
  int v3; // w19
  unsigned int v4; // w9
  __int64 v5; // x9
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x0

  if ( (unsigned int)(a2 - 4) <= 0xFFFFFFFC )
  {
    result = printk(&unk_3F3029, "ipa3_set_client");
    v7 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v8 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v8 )
      {
        ipc_log_string(v8, "ipa %s:%d Bad client number! client =%d\n", "ipa3_set_client", 8481, a2);
        v7 = ipa3_ctx;
      }
      result = *(_QWORD *)(v7 + 34160);
      if ( result )
        return ipc_log_string(result, "ipa %s:%d Bad client number! client =%d\n", "ipa3_set_client", 8481, a2);
    }
  }
  else
  {
    v3 = result;
    if ( *(_DWORD *)(ipa3_ctx + 32240) <= 0x14u )
      v4 = 31;
    else
      v4 = 36;
    if ( (result & 0x80000000) != 0 || v4 <= (unsigned int)result )
    {
      result = printk(&unk_3ECE48, "ipa3_set_client");
      v9 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v10 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v10 )
        {
          ipc_log_string(v10, "ipa %s:%d Bad pipe index! index =%d\n", "ipa3_set_client", 8483, v3);
          v9 = ipa3_ctx;
        }
        result = *(_QWORD *)(v9 + 34160);
        if ( result )
          return ipc_log_string(result, "ipa %s:%d Bad pipe index! index =%d\n", "ipa3_set_client", 8483, v3);
      }
    }
    else
    {
      v5 = 8LL * (unsigned int)result;
      *(_DWORD *)(ipa3_ctx + v5 + 43348) = a2;
      *(_BYTE *)(ipa3_ctx + v5 + 43352) = a3 & 1;
    }
  }
  return result;
}
