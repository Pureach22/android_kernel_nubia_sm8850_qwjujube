__int64 __fastcall drm_dp_pcon_pps_default(_QWORD *a1)
{
  __int64 result; // x0
  int v3; // w0
  _BYTE v4[4]; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v5[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4[0] = 0;
  result = drm_dp_dpcd_read(a1, 0x3052u, (__int64)v4, 1);
  if ( (result & 0x80000000) == 0 )
  {
    v4[0] = v4[0] & 0xF1 | 2;
    v5[0] = v4[0];
    v3 = drm_dp_dpcd_write(a1, 0x3052u, (__int64)v5, 1);
    result = v3 & (unsigned int)(v3 >> 31);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
