__int64 sub_692AF4()
{
  __int16 v0; // w13

  if ( (v0 & 0x200) != 0 )
    JUMPOUT(0x695258);
  return utils_dfs_get_rcsa_flags();
}
