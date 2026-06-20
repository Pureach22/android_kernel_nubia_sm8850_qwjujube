__int64 __fastcall ipa3_should_pipe_be_suspended(__int64 a1)
{
  int v1; // w19
  unsigned int ep_mapping; // w0
  __int64 result; // x0
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0

  v1 = a1;
  ep_mapping = ipa_get_ep_mapping(a1);
  if ( ep_mapping == -1 )
  {
    printk(&unk_3AC96C, "ipa3_should_pipe_be_suspended");
    v4 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v5 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v5 )
      {
        ipc_log_string(v5, "ipa %s:%d Invalid client.\n", "ipa3_should_pipe_be_suspended", 7535);
        v4 = ipa3_ctx;
      }
      v6 = *(_QWORD *)(v4 + 34160);
      if ( v6 )
        ipc_log_string(v6, "ipa %s:%d Invalid client.\n", "ipa3_should_pipe_be_suspended", 7535);
    }
    result = 0;
    __break(0x800u);
  }
  else if ( ep_mapping >= 0x25 )
  {
    __break(0x5512u);
    return ipa3_suspend_resource_sync();
  }
  else if ( *(_DWORD *)(ipa3_ctx + 32240) > 0xDu || (*(_BYTE *)(ipa3_ctx + 480LL * ep_mapping + 573) & 1) != 0 )
  {
    return 0;
  }
  else
  {
    result = 1;
    switch ( v1 )
    {
      case 1:
      case 11:
      case 13:
      case 15:
      case 17:
      case 19:
      case 21:
      case 27:
      case 39:
      case 41:
      case 43:
      case 49:
      case 81:
      case 107:
      case 117:
      case 119:
        return result;
      default:
        return 0;
    }
  }
  return result;
}
