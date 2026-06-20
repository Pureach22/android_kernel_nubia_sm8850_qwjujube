__int64 __fastcall qdf_debugfs_single_open(__int64 a1, __int64 a2)
{
  return single_open(a2, qdf_debugfs_single_show, *(_QWORD *)(a1 + 696));
}
