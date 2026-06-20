__int64 __fastcall dp_parser_get_io_buf(__int64 result, char *s2)
{
  unsigned int v2; // w22
  __int64 v3; // x19
  unsigned int i; // w21
  __int64 v6; // x23
  __int64 ipc_log_context; // x0

  if ( result )
  {
    v2 = *(_DWORD *)(result + 400);
    v3 = result;
    if ( v2 )
    {
      for ( i = 0; i < v2; ++i )
      {
        v6 = *(_QWORD *)(v3 + 408) + 32LL * (int)i;
        result = strcmp(*(const char **)v6, s2);
        if ( !(_DWORD)result && !*(_QWORD *)(v6 + 8) )
        {
          result = devm_kmalloc(*(_QWORD *)v3 + 16LL, *(unsigned int *)(v6 + 16), 3520);
          *(_QWORD *)(v6 + 8) = result;
          v2 = *(_DWORD *)(v3 + 400);
        }
      }
    }
  }
  else
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_275B6D, "dp_parser_get_io_buf");
  }
  return result;
}
