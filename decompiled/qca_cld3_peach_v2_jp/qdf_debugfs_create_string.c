__int64 __fastcall qdf_debugfs_create_string(__int64 result, __int16 a2, __int64 a3, __int64 a4)
{
  if ( result )
  {
    if ( !a3 )
      a3 = qdf_debugfs_root;
    return debugfs_create_file(result, a2 & 0x1B6, a3, a4, &qdf_string_fops);
  }
  return result;
}
