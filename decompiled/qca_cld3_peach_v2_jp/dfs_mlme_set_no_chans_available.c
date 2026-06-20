__int64 dfs_mlme_set_no_chans_available()
{
  __int64 (*v0)(void); // x8
  __int64 result; // x0

  v0 = (__int64 (*)(void))off_869098;
  if ( off_869098 )
  {
    if ( *((_DWORD *)off_869098 - 1) != 443231604 )
      __break(0x8228u);
    return v0();
  }
  return result;
}
