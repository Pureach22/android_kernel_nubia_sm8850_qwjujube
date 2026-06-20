__int64 __fastcall dp_parser_get_io(__int64 a1, char *s2)
{
  int v2; // w20
  __int64 v3; // x21
  int v5; // w8
  __int64 v6; // x22
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    v2 = *(_DWORD *)(a1 + 400);
    if ( v2 )
    {
      v3 = *(_QWORD *)(a1 + 408);
      v5 = 0;
      while ( 1 )
      {
        v6 = v5;
        if ( !strcmp(*(const char **)(v3 + 32LL * v5), s2) )
          break;
        v5 = v6 + 1;
        if ( v2 == (_DWORD)v6 + 1 )
          return 0;
      }
      return v3 + 32 * v6;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_parser_get_io");
    return 0;
  }
}
