__int64 __fastcall dfs_mlme_get_cac_timeout_for_freq(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  void (__fastcall *v4)(__int64, __int64, __int64, __int64, unsigned int *); // x8
  __int64 result; // x0
  unsigned int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = (void (__fastcall *)(__int64, __int64, __int64, __int64, unsigned int *))off_932358;
  v6 = 0;
  if ( off_932358 )
  {
    if ( *((_DWORD *)off_932358 - 1) != 2120200930 )
      __break(0x8228u);
    v4(a1, a2, a3, a4, &v6);
    result = v6;
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
