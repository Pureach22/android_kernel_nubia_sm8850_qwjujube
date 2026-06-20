__int64 __fastcall hif_rtpm_debugfs_open(__int64 a1, __int64 a2)
{
  return single_open(a2, hif_rtpm_debugfs_show, *(_QWORD *)(a1 + 696));
}
