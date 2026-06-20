__int64 __fastcall dp_sim_remove(__int64 a1)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(a1 + 168);
  if ( v1 )
  {
    debugfs_remove(*(_QWORD *)(v1 + 144));
    dp_sim_destroy_bridge(v1 + 8);
  }
  return 0;
}
