__int64 __fastcall target_if_sops_start_spectral_scan(
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
  __int64 result; // x0
  unsigned __int8 v13[4]; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v14[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14[0] = 1;
  v13[0] = 0;
  if ( (unsigned int)target_if_spectral_info_read(a1, a2, 1, v13, 1, a3, a4, a5, a6, a7, a8, a9, a10) )
  {
    v13[0] = 0;
  }
  else if ( v13[0] )
  {
LABEL_6:
    result = target_if_spectral_info_write(a1, a2, 0, v14, 1);
    goto LABEL_7;
  }
  result = target_if_spectral_info_write(a1, a2, 1, v14, 1);
  if ( !(_DWORD)result )
    goto LABEL_6;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
