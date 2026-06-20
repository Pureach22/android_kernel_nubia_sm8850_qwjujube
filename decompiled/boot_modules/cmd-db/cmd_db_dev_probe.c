__int64 __fastcall cmd_db_dev_probe(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 result; // x0
  const char *v5; // x1

  v2 = of_reserved_mem_lookup(*(_QWORD *)(a1 + 760));
  if ( !v2 )
  {
    v5 = "failed to acquire memory region\n";
LABEL_12:
    dev_err(a1 + 16, v5);
    return 4294967274LL;
  }
  v3 = memremap(*(_QWORD *)(v2 + 24), *(_QWORD *)(v2 + 32), 4);
  cmd_db_header = v3;
  if ( !v3 )
  {
    cmd_db_header = 0;
    return 4294967284LL;
  }
  if ( *(_DWORD *)(v3 + 4) != 201535707 )
  {
    v5 = "Invalid Command DB Magic\n";
    goto LABEL_12;
  }
  debugfs_create_file("cmd-db", 256, 0, 0, &cmd_db_debugfs_ops);
  if ( !cmd_db_header )
    return 0;
  result = 0;
  if ( *(_DWORD *)(cmd_db_header + 4) == 201535707 && (*(_DWORD *)(cmd_db_header + 140) & 1) != 0 )
  {
    printk(&unk_6A99);
    return 0;
  }
  return result;
}
