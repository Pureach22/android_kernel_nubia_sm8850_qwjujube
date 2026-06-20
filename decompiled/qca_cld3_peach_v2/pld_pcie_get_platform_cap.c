__int64 __fastcall pld_pcie_get_platform_cap(__int64 a1, _DWORD *a2)
{
  __int64 result; // x0
  int v4; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    v4 = 0;
    result = cnss_get_platform_cap(a1, &v4);
    if ( !(_DWORD)result )
      *a2 = v4;
  }
  else
  {
    result = 4294967277LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
