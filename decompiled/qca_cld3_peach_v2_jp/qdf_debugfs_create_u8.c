__int64 __fastcall qdf_debugfs_create_u8(__int64 result)
{
  if ( result )
    return debugfs_create_u8();
  return result;
}
