__int64 __fastcall drm_dp_pcon_pps_override_buf(_QWORD *a1, __int64 a2)
{
  __int64 result; // x0
  int v4; // w0
  __int64 v5; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v6[4]; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v7[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+18h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = a2;
  result = drm_dp_dpcd_write(a1, 0x3100u, (__int64)&v5, 128);
  if ( (result & 0x80000000) == 0 )
  {
    v6[0] = 0;
    result = drm_dp_dpcd_read(a1, 0x3052u, (__int64)v6, 1);
    if ( (result & 0x80000000) == 0 )
    {
      v6[0] = v6[0] & 0xF1 | 0xA;
      v7[0] = v6[0];
      v4 = drm_dp_dpcd_write(a1, 0x3052u, (__int64)v7, 1);
      result = v4 & (unsigned int)(v4 >> 31);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
