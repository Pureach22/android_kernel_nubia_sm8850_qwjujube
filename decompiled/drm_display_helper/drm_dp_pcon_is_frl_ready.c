__int64 __fastcall drm_dp_pcon_is_frl_ready(_QWORD *a1)
{
  int v1; // w0
  unsigned int v2; // w8
  unsigned int v3; // w8
  _BYTE v5[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5[0] = 0;
  v1 = drm_dp_dpcd_read(a1, 0x303Bu, (__int64)v5, 1);
  v2 = v5[0];
  _ReadStatusReg(SP_EL0);
  v3 = (v2 >> 1) & 1;
  if ( v1 >= 0 )
    return v3;
  else
    return 0;
}
