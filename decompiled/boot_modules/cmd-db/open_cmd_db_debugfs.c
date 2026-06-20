__int64 __fastcall open_cmd_db_debugfs(__int64 a1, __int64 a2)
{
  return single_open(a2, cmd_db_debugfs_dump, *(_QWORD *)(a1 + 696));
}
