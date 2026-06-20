__int64 __fastcall drm_dp_start_crc(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v5; // x1
  _BYTE v6[4]; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v7[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6[0] = 0;
  result = drm_dp_dpcd_read((_QWORD *)a1, 0x270u, (__int64)v6, 1);
  if ( (result & 0x80000000) == 0 )
  {
    v7[0] = v6[0] | 1;
    result = drm_dp_dpcd_write((_QWORD *)a1, 0x270u, (__int64)v7, 1);
    if ( (result & 0x80000000) == 0 )
    {
      v5 = system_wq;
      *(_BYTE *)(a1 + 1352) = 0;
      *(_QWORD *)(a1 + 1264) = a2;
      queue_work_on(32, v5, a1 + 1320);
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
