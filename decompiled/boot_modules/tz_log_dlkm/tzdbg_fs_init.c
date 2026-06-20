__int64 __fastcall tzdbg_fs_init(__int64 a1)
{
  __int64 v2; // x0
  _DWORD *v3; // x21
  __int64 v4; // x20
  char *v5; // x23
  __int64 v6; // x24
  bool v7; // cf
  __int64 result; // x0

  v2 = proc_mkdir("tzdbg", 0);
  if ( v2 )
  {
    v3 = &unk_138;
    v4 = v2;
    v5 = &byte_188;
    v6 = -11;
    do
    {
      *v3 = v6 + 11;
      if ( *v5 == 1 && !proc_create_data(*((_QWORD *)v5 - 2), 292, v4, &tzdbg_fops, v3) )
      {
        dev_err(a1 + 16, "TZ proc_create_data failed\n");
        remove_proc_subtree("tzdbg", 0);
        return 4294967284LL;
      }
      v7 = __CFADD__(v6++, 1);
      v5 += 40;
      ++v3;
    }
    while ( !v7 );
    result = 0;
    *(_QWORD *)(a1 + 168) = v4;
  }
  else
  {
    dev_err(a1 + 16, "tzdbg proc_mkdir failed\n");
    return 4294967284LL;
  }
  return result;
}
