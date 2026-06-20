__int64 dfs_mlme_is_opmode_sta()
{
  __int64 (*v0)(void); // x8

  v0 = (__int64 (*)(void))off_8690D8;
  if ( !off_8690D8 )
    return 0;
  if ( *((_DWORD *)off_8690D8 - 1) != -1102235987 )
    __break(0x8228u);
  return v0() & 1;
}
