__int64 __fastcall mem_prot_debuginfo_show(__int64 a1)
{
  _UNKNOWN **v1; // x27
  __int64 v3; // x2
  const char *v4; // x2
  void *v5; // x25

  v1 = (_UNKNOWN **)debugfs_pool_list;
  if ( debugfs_pool_list != (_UNKNOWN *)&debugfs_pool_list )
  {
    do
    {
      v5 = v1[2];
      seq_printf(a1, "Pool Type: %s\n", (const char *)v1[8]);
      seq_printf(a1, "managed (bytes): %zu\n", (size_t)v1[5]);
      if ( v5 )
        v3 = gen_pool_avail(v5);
      else
        v3 = 0;
      seq_printf(a1, "available (bytes): %zu\n", v3);
      if ( *((_BYTE *)v1 + 48) )
        v4 = "true";
      else
        v4 = "false";
      seq_printf(a1, "Enabled: %s\n", v4);
      seq_write(a1, "-----------------------------\n", 30);
      v1 = (_UNKNOWN **)*v1;
    }
    while ( v1 != &debugfs_pool_list );
  }
  return 0;
}
