__int64 __fastcall dfs_mlme_find_dot11_chan_for_freq(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 (__fastcall *v4)(__int64, __int64, __int64, __int64); // x8

  v4 = (__int64 (__fastcall *)(__int64, __int64, __int64, __int64))off_932320;
  if ( !off_932320 )
    return 16;
  if ( *((_DWORD *)off_932320 - 1) != 605052135 )
    __break(0x8228u);
  return v4(a1, a2, a3, a4);
}
