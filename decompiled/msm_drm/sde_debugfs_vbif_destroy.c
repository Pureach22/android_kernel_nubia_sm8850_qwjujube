__int64 __fastcall sde_debugfs_vbif_destroy(__int64 a1)
{
  __int64 result; // x0

  result = debugfs_remove(*(_QWORD *)(a1 + 1744));
  *(_QWORD *)(a1 + 1744) = 0;
  return result;
}
