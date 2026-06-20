unsigned __int64 __fastcall qdf_debugfs_create_dir(unsigned __int64 result, __int64 a2)
{
  unsigned __int64 v2; // x19
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  if ( result )
  {
    v2 = result;
    if ( !a2 )
      a2 = qdf_debugfs_root;
    result = debugfs_create_dir(result, a2);
    if ( !result || result >= 0xFFFFFFFFFFFFF001LL )
    {
      qdf_trace_msg(0x38u, 2u, "%s creation failed", v3, v4, v5, v6, v7, v8, v9, v10, v2);
      return 0;
    }
  }
  return result;
}
