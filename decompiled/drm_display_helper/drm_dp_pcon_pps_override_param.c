__int64 __fastcall drm_dp_pcon_pps_override_param(_QWORD *a1, __int64 a2)
{
  __int64 result; // x0
  int v5; // w0
  _BYTE v6[4]; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v7[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = drm_dp_dpcd_write(a1, 0x3180u, a2, 2);
  if ( (result & 0x80000000) == 0 )
  {
    result = drm_dp_dpcd_write(a1, 0x3182u, a2 + 2, 2);
    if ( (result & 0x80000000) == 0 )
    {
      result = drm_dp_dpcd_write(a1, 0x3184u, a2 + 4, 2);
      if ( (result & 0x80000000) == 0 )
      {
        v6[0] = 0;
        result = drm_dp_dpcd_read(a1, 0x3052u, (__int64)v6, 1);
        if ( (result & 0x80000000) == 0 )
        {
          v6[0] = v6[0] & 0xF1 | 0xA;
          v7[0] = v6[0];
          v5 = drm_dp_dpcd_write(a1, 0x3052u, (__int64)v7, 1);
          result = v5 & (unsigned int)(v5 >> 31);
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
