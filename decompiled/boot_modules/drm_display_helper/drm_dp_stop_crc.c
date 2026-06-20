__int64 __fastcall drm_dp_stop_crc(_QWORD *a1)
{
  __int64 result; // x0
  _BYTE v3[4]; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v4[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3[0] = 0;
  result = drm_dp_dpcd_read(a1, 0x270u, (__int64)v3, 1);
  if ( (result & 0x80000000) == 0 )
  {
    v4[0] = v3[0] & 0xFE;
    result = drm_dp_dpcd_write(a1, 0x270u, (__int64)v4, 1);
    if ( (result & 0x80000000) == 0 )
    {
      flush_work(a1 + 165);
      result = 0;
      a1[158] = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
