__int64 __fastcall dfs_mlme_nol_alloc_nol(__int64 a1)
{
  void (__fastcall *v1)(__int64, _QWORD *); // x8
  __int64 result; // x0
  _QWORD v3[2]; // [xsp+0h] [xbp-10h] BYREF

  v3[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = (void (__fastcall *)(__int64, _QWORD *))off_932388;
  v3[0] = 0;
  if ( off_932388 )
  {
    if ( *((_DWORD *)off_932388 - 1) != -332006558 )
      __break(0x8228u);
    v1(a1, v3);
    result = v3[0];
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
