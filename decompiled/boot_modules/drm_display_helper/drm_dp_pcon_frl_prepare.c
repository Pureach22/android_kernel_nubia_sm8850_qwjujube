__int64 __fastcall drm_dp_pcon_frl_prepare(_QWORD *a1, char a2)
{
  __int64 v2; // x8
  char v3; // w9
  __int64 result; // x0
  char v5[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v2 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a2 & 1) != 0 )
    v3 = 104;
  else
    v3 = 40;
  v6 = v2;
  v5[0] = v3;
  result = drm_dp_dpcd_write(a1, 0x305Au, (__int64)v5, 1);
  _ReadStatusReg(SP_EL0);
  return result;
}
