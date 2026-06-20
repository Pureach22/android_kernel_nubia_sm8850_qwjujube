__int64 __fastcall hw_sync_debugfs_release(__int64 a1, __int64 a2)
{
  __int64 v2; // x0

  v2 = *(_QWORD *)(a2 + 32);
  if ( !v2 )
    return 4294967274LL;
  kfree(v2);
  return 0;
}
