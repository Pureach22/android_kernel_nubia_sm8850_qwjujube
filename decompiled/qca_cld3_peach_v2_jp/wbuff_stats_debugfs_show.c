__int64 __fastcall wbuff_stats_debugfs_show(__int64 a1)
{
  __int64 v2; // x20
  _QWORD *v3; // x22
  __int64 v4; // x20
  _QWORD *v5; // x22

  wbuff_debugfs_print(a1, "WBUFF POOL STATS:\n");
  wbuff_debugfs_print(a1, "=================\n");
  if ( byte_869EE0 == 1 )
  {
    wbuff_debugfs_print(a1, "Module (%d) : %s\n", 0, "WBUFF_MODULE_WMI_TX");
    wbuff_debugfs_print(
      a1,
      "%s %25s %20s %20s\n",
      "Pool ID",
      "Mem Allocated (In Bytes)",
      "Wbuff Success Count",
      "Wbuff Fail Count");
    v2 = 0;
    v3 = &unk_869F30;
    do
    {
      if ( *((_BYTE *)v3 - 40) == 1 )
        wbuff_debugfs_print(a1, "%d %30llu %20llu %20llu\n", v2, *v3, *(v3 - 2), *(v3 - 1));
      ++v2;
      v3 += 6;
    }
    while ( v2 != 16 );
    wbuff_debugfs_print(a1, "\n");
  }
  if ( byte_86A208 == 1 )
  {
    wbuff_debugfs_print(a1, "Module (%d) : %s\n", 1, "WBUFF_MODULE_CE_RX");
    wbuff_debugfs_print(
      a1,
      "%s %25s %20s %20s\n",
      "Pool ID",
      "Mem Allocated (In Bytes)",
      "Wbuff Success Count",
      "Wbuff Fail Count");
    v4 = 0;
    v5 = &unk_86A258;
    do
    {
      if ( *((_BYTE *)v5 - 40) == 1 )
        wbuff_debugfs_print(a1, "%d %30llu %20llu %20llu\n", v4, *v5, *(v5 - 2), *(v5 - 1));
      ++v4;
      v5 += 6;
    }
    while ( v4 != 16 );
    wbuff_debugfs_print(a1, "\n");
  }
  return 0;
}
