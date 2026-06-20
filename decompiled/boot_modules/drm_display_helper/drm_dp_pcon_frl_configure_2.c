__int64 __fastcall drm_dp_pcon_frl_configure_2(_QWORD *a1, char a2, char a3)
{
  int v3; // w0
  _BYTE v5[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5[0] = a2 & 0xBF | ((a3 == 64) << 6);
  v3 = drm_dp_dpcd_write(a1, 0x305Bu, (__int64)v5, 1);
  _ReadStatusReg(SP_EL0);
  return v3 & (unsigned int)(v3 >> 31);
}
