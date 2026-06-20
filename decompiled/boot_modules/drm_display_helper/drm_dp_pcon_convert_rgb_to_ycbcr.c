__int64 __fastcall drm_dp_pcon_convert_rgb_to_ycbcr(_QWORD *a1, char a2)
{
  __int64 result; // x0
  char v5; // w8
  int v6; // w0
  _BYTE v7[4]; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v8[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7[0] = 0;
  result = drm_dp_dpcd_read(a1, 0x3052u, (__int64)v7, 1);
  if ( (result & 0x80000000) == 0 )
  {
    v5 = v7[0] | a2 & 0x70;
    if ( (a2 & 0x70) == 0 )
      v5 = v7[0] & 0x8F;
    v7[0] = v5;
    v8[0] = v5;
    v6 = drm_dp_dpcd_write(a1, 0x3052u, (__int64)v8, 1);
    result = v6 & (unsigned int)(v6 >> 31);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
