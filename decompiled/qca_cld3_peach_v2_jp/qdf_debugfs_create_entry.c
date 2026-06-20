unsigned __int64 __fastcall qdf_debugfs_create_entry(__int64 a1, __int16 a2, __int64 a3, __int64 a4, __int64 a5)
{
  unsigned __int64 result; // x0
  __int64 v7; // x19
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7

  result = 0;
  if ( a1 && a5 )
  {
    v7 = a1;
    if ( !a3 )
      a3 = qdf_debugfs_root;
    result = debugfs_create_file(a1, a2 & 0x1B6, a3, a4, a5);
    if ( !result || result >= 0xFFFFFFFFFFFFF001LL )
    {
      qdf_trace_msg(0x38u, 2u, "%s creation failed 0x%pK", v8, v9, v10, v11, v12, v13, v14, v15, v7, result);
      return 0;
    }
  }
  return result;
}
