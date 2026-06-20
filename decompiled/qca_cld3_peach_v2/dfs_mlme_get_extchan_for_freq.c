__int64 __fastcall dfs_mlme_get_extchan_for_freq(__int64 a1)
{
  __int64 (__fastcall *v1)(__int64); // x8

  v1 = (__int64 (__fastcall *)(__int64))off_932308;
  if ( !off_932308 )
    return 16;
  if ( *((_DWORD *)off_932308 - 1) != -830013184 )
    __break(0x8228u);
  return v1(a1);
}
