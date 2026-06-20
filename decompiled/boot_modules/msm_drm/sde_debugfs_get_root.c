__int64 __fastcall sde_debugfs_get_root(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x8

  if ( result )
  {
    v1 = *(_QWORD *)(result + 136);
    if ( v1 && (v2 = *(_QWORD *)(v1 + 56)) != 0 )
      return *(_QWORD *)(v2 + 5688);
    else
      return 0;
  }
  return result;
}
