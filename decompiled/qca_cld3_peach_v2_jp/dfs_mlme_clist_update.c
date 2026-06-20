__int64 dfs_mlme_clist_update()
{
  __int64 (*v0)(void); // x8
  __int64 result; // x0

  v0 = (__int64 (*)(void))off_8690D0;
  if ( off_8690D0 )
  {
    if ( *((_DWORD *)off_8690D0 - 1) != 1503696012 )
      __break(0x8228u);
    return v0();
  }
  return result;
}
