__int64 sub_625020()
{
  __int16 v0; // w13

  if ( (v0 & 0x200) != 0 )
    JUMPOUT(0x627784);
  return utils_dfs_get_rcsa_flags();
}
