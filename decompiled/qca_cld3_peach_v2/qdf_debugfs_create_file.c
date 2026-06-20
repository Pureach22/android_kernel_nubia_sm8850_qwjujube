unsigned __int64 __fastcall qdf_debugfs_create_file(__int64 a1, __int16 a2, __int64 a3, __int64 a4)
{
  unsigned __int64 v4; // x4
  unsigned __int64 file; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7

  v4 = 0;
  if ( a1 && a4 )
  {
    if ( !a3 )
      a3 = qdf_debugfs_root;
    file = debugfs_create_file(a1, a2 & 0x1B6, a3, a4, &_qdf_debugfs_fops);
    v4 = file;
    if ( !file || file >= 0xFFFFFFFFFFFFF001LL )
    {
      qdf_trace_msg(0x38u, 2u, "%s creation failed 0x%pK", v7, v8, v9, v10, v11, v12, v13, v14, a1, file);
      return 0;
    }
  }
  return v4;
}
