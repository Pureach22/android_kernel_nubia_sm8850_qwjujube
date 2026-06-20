__int64 __fastcall qdf_debugfs_create_u32(__int64 result)
{
  if ( result )
    return debugfs_create_u32();
  return result;
}
