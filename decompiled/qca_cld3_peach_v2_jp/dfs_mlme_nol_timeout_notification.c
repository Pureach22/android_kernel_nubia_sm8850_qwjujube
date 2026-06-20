__int64 dfs_mlme_nol_timeout_notification()
{
  __int64 (*v0)(void); // x8
  __int64 result; // x0

  v0 = (__int64 (*)(void))off_8690C8;
  if ( off_8690C8 )
  {
    if ( *((_DWORD *)off_8690C8 - 1) != -2099273483 )
      __break(0x8228u);
    return v0();
  }
  return result;
}
