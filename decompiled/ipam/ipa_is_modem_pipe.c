__int64 __fastcall ipa_is_modem_pipe(unsigned int a1)
{
  unsigned int v2; // w20
  int v3; // w8
  __int64 result; // x0
  __int64 v5; // x8
  __int64 v6; // x0

  if ( (a1 & 0x80000000) != 0 || *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
  {
    printk(&unk_3E7136, "ipa_is_modem_pipe");
    v5 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v6 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v6 )
      {
        ipc_log_string(v6, "ipa %s:%d Bad pipe index!\n", "ipa_is_modem_pipe", 11706);
        v5 = ipa3_ctx;
      }
      result = *(_QWORD *)(v5 + 34160);
      if ( !result )
        return result;
      ipc_log_string(result, "ipa %s:%d Bad pipe index!\n", "ipa_is_modem_pipe", 11706);
    }
    return 0;
  }
  v2 = 0;
  while ( 1 )
  {
    if ( v2 == 84
      || v2 == 114
      || v2 == 74
      || v2 == 122
      || (v3 = v2 & 0xFD, v3 == 56)
      || v3 == 52
      || v2 == 50
      || v2 == 85
      || v2 == 115
      || v3 == 77
      || v2 == 75
      || v2 == 61
      || v3 == 57
      || v2 == 53
      || (v2 & 0xFB) == 0x33 )
    {
      if ( (unsigned int)ipa_get_ep_mapping(v2) == a1 )
        break;
    }
    if ( ++v2 == 134 )
      return 0;
  }
  return 1;
}
