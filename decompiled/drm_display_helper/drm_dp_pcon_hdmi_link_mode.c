__int64 __fastcall drm_dp_pcon_hdmi_link_mode(_QWORD *a1, _BYTE *a2)
{
  __int64 result; // x0
  _BYTE v4[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4[0] = 0;
  result = drm_dp_dpcd_read(a1, 0x3036u, (__int64)v4, 1);
  if ( (result & 0x80000000) == 0 )
  {
    result = v4[0] & 1;
    if ( a2 )
    {
      if ( (v4[0] & 1) != 0 )
        *a2 = (v4[0] >> 1) & 0x3F;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
