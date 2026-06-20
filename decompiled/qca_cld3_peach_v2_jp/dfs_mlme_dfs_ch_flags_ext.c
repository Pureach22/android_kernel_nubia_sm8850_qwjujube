__int64 __fastcall dfs_mlme_dfs_ch_flags_ext(__int64 a1)
{
  void (__fastcall *v1)(__int64, unsigned __int16 *); // x8
  __int64 result; // x0
  unsigned __int16 v3; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = (void (__fastcall *)(__int64, unsigned __int16 *))off_8690B8;
  v3 = 0;
  if ( off_8690B8 )
  {
    if ( *((_DWORD *)off_8690B8 - 1) != 102236042 )
      __break(0x8228u);
    v1(a1, &v3);
    result = v3;
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
