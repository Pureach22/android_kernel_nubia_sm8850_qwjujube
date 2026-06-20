__int64 utils_dfs_deliver_event()
{
  __int64 (*v0)(void); // x8
  __int64 result; // x0

  v0 = (__int64 (*)(void))off_869108;
  if ( off_869108 )
  {
    if ( *((_DWORD *)off_869108 - 1) != 395402626 )
      __break(0x8228u);
    return v0();
  }
  return result;
}
