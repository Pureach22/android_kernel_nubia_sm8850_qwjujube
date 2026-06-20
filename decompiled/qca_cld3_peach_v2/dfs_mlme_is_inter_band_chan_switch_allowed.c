__int64 dfs_mlme_is_inter_band_chan_switch_allowed()
{
  __int64 (*v0)(void); // x8

  v0 = (__int64 (*)(void))off_932398;
  if ( !off_932398 )
    return 0;
  if ( *((_DWORD *)off_932398 - 1) != -1102235987 )
    __break(0x8228u);
  return v0() & 1;
}
