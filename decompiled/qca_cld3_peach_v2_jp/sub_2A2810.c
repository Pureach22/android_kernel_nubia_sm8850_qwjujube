__int64 sub_2A2810()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2A97E4);
  return ucfg_mlme_get_dfs_pri_multiplier();
}
