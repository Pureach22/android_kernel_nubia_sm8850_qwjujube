__int64 __fastcall drm_dp_pcon_reset_frl_config(_QWORD *a1)
{
  int v1; // w0
  _BYTE v3[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3[0] = 0;
  v1 = drm_dp_dpcd_write(a1, 0x305Au, (__int64)v3, 1);
  _ReadStatusReg(SP_EL0);
  return v1 & (unsigned int)(v1 >> 31);
}
