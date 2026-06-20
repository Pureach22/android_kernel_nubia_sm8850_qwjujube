__int64 dfs_mlme_is_pdev_valid()
{
  __int64 (*v0)(void); // x8

  v0 = (__int64 (*)(void))off_869140;
  if ( !off_869140 )
    return 0;
  if ( *((_DWORD *)off_869140 - 1) != -1102235987 )
    __break(0x8228u);
  return v0() & 1;
}
