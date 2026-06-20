__int64 __fastcall wcd939x_swr_probe(_QWORD *a1)
{
  _QWORD *v2; // x0
  __int64 v3; // x8
  _QWORD *v4; // x20
  __int64 v5; // x0
  unsigned __int64 dir; // x0
  __int64 file; // x0
  __int64 v8; // x2
  __int64 v9; // x0
  __int64 v10; // x2

  v2 = (_QWORD *)devm_kmalloc(a1 + 9, 64, 3520);
  if ( !v2 )
    return 4294967284LL;
  v3 = v2[1];
  a1[28] = v2;
  *v2 = a1;
  if ( !v3 )
  {
    v4 = v2;
    v5 = a1[23];
    if ( !v5 )
      v5 = a1[9];
    dir = debugfs_create_dir(v5, 0);
    v4[1] = dir;
    if ( dir <= 0xFFFFFFFFFFFFF000LL )
    {
      file = debugfs_create_file("swrslave_peek", 33060, dir, a1, &codec_debug_read_ops);
      v8 = v4[1];
      v4[2] = file;
      v9 = debugfs_create_file("swrslave_poke", 33060, v8, a1, &codec_debug_write_ops);
      v10 = v4[1];
      v4[3] = v9;
      v4[4] = debugfs_create_file("swrslave_reg_dump", 33060, v10, a1, &codec_debug_dump_ops);
    }
  }
  return component_add(a1 + 9, wcd939x_slave_comp_ops);
}
