__int64 __fastcall dp_parser_clear_io_buf(__int64 result)
{
  __int64 v1; // x19
  unsigned int v2; // w20
  __int64 v3; // x21
  _QWORD *v4; // x21
  __int64 v5; // t1
  __int64 ipc_log_context; // x0

  if ( result )
  {
    v1 = result;
    if ( *(_DWORD *)(result + 400) )
    {
      v2 = 0;
      do
      {
        v3 = *(_QWORD *)(v1 + 408) + 32LL * (int)v2;
        v5 = *(_QWORD *)(v3 + 8);
        v4 = (_QWORD *)(v3 + 8);
        if ( v5 )
          result = devm_kfree(*(_QWORD *)v1 + 16LL);
        *v4 = 0;
        ++v2;
      }
      while ( v2 < *(_DWORD *)(v1 + 400) );
    }
  }
  else
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_275B6D, "dp_parser_clear_io_buf");
  }
  return result;
}
