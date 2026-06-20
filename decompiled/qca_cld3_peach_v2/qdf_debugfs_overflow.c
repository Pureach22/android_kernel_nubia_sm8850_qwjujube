bool __fastcall qdf_debugfs_overflow(__int64 a1)
{
  return *(_QWORD *)(a1 + 24) == *(_QWORD *)(a1 + 8);
}
