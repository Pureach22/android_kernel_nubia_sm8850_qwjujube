__int64 __fastcall utils_get_dfsdomain(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = 0;
  wlan_reg_get_dfs_region(a1, &v10, a2, a3, a4, a5, a6, a7, a8, a9);
  _ReadStatusReg(SP_EL0);
  return v10;
}
