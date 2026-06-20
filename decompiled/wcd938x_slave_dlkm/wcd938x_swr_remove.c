__int64 __fastcall wcd938x_swr_remove(__int64 a1)
{
  __int64 v2; // x20

  if ( a1 )
  {
    v2 = *(_QWORD *)(a1 + 224);
    if ( v2 )
    {
      debugfs_remove(*(_QWORD *)(v2 + 8));
      *(_QWORD *)(v2 + 8) = 0;
    }
  }
  component_del(a1 + 72, wcd938x_slave_comp_ops);
  *(_QWORD *)(a1 + 224) = 0;
  swr_remove_device(a1);
  return 0;
}
