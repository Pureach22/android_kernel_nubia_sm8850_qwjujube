__int64 __fastcall dfs_mlme_set_tx_flag(__int64 result, char a2)
{
  __int64 (__fastcall *v2)(__int64, __int64); // x8
  __int64 v3; // x1

  v2 = (__int64 (__fastcall *)(__int64, __int64))off_9323B0;
  if ( off_9323B0 )
  {
    v3 = a2 & 1;
    if ( *((_DWORD *)off_9323B0 - 1) != 1845289881 )
      __break(0x8228u);
    return v2(result, v3);
  }
  return result;
}
