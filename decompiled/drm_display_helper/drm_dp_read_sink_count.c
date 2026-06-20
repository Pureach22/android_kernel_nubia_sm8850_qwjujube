__int64 __fastcall drm_dp_read_sink_count(_QWORD *a1)
{
  __int64 result; // x0
  _BYTE v2[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v3; // [xsp+8h] [xbp-8h]

  v3 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2[0] = 0;
  result = drm_dp_dpcd_read(a1, 0x200u, (__int64)v2, 1);
  if ( (result & 0x80000000) == 0 )
  {
    if ( (_DWORD)result == 1 )
      result = v2[0] & 0x3F | (((v2[0] >> 7) & 1u) << 6);
    else
      result = 4294967291LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
