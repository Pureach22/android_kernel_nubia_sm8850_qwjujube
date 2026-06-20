__int64 __fastcall dp_debug_put(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x20

  if ( result )
  {
    v1 = result;
    v2 = result - 160;
    debugfs_remove(*(_QWORD *)(result - 160));
    if ( *(_QWORD *)(v2 + 424) )
      dp_sim_destroy_bridge();
    return devm_kfree(*(_QWORD *)(v1 - 8));
  }
  return result;
}
