__int64 __fastcall dfs_mlme_ieee2mhz(__int64 a1, __int64 a2, __int64 a3)
{
  void (__fastcall *v3)(__int64, __int64, __int64, unsigned int *); // x8
  __int64 result; // x0
  unsigned int v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = (void (__fastcall *)(__int64, __int64, __int64, unsigned int *))off_932318;
  v5 = 0;
  if ( off_932318 )
  {
    if ( *((_DWORD *)off_932318 - 1) != -117820135 )
      __break(0x8228u);
    v3(a1, a2, a3, &v5);
    result = v5;
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
