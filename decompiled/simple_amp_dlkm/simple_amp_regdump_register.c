unsigned __int64 __fastcall simple_amp_regdump_register(unsigned __int64 result, __int64 a2)
{
  _QWORD *v2; // x19
  __int64 v3; // x0
  __int64 file; // x0
  __int64 v6; // x2
  __int64 v7; // x0
  __int64 v8; // x2

  if ( !*(_QWORD *)(result + 496) )
  {
    v2 = (_QWORD *)result;
    v3 = *(_QWORD *)(a2 + 184);
    if ( !v3 )
      v3 = *(_QWORD *)(a2 + 72);
    result = debugfs_create_dir(v3, 0);
    v2[62] = result;
    if ( result <= 0xFFFFFFFFFFFFF000LL )
    {
      file = debugfs_create_file("swrslave_peek", 33060, result, a2, &codec_debug_read_ops);
      v6 = v2[62];
      v2[63] = file;
      v7 = debugfs_create_file("swrslave_poke", 33060, v6, a2, &codec_debug_write_ops);
      v8 = v2[62];
      v2[64] = v7;
      result = debugfs_create_file("swrslave_reg_dump", 33060, v8, a2, &codec_debug_dump_ops);
      v2[65] = result;
    }
  }
  return result;
}
