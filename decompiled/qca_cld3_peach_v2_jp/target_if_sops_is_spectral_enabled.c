__int64 __fastcall target_if_sops_is_spectral_enabled(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v10; // w0
  unsigned __int8 v12[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12[0] = 0;
  v10 = target_if_spectral_info_read(a1, a2, 1, v12, 1, a3, a4, a5, a6, a7, a8, a9, a10);
  _ReadStatusReg(SP_EL0);
  if ( v10 )
    return 0;
  else
    return v12[0];
}
