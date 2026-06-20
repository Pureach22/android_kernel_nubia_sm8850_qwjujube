__int64 __fastcall qdf_debugfs_string_open(__int64 a1, __int64 a2)
{
  return single_open(a2, qdf_debugfs_string_show, *(_QWORD *)(a1 + 696));
}
