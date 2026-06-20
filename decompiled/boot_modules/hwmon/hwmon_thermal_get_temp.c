__int64 __fastcall hwmon_thermal_get_temp(__int64 a1, _DWORD *a2)
{
  __int64 v3; // x0
  __int64 v4; // x8
  __int64 v5; // x3
  _DWORD *v6; // x9
  __int64 result; // x0
  _QWORD v8[2]; // [xsp+0h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = thermal_zone_device_priv();
  v4 = *(_QWORD *)(v3 + 16);
  v8[0] = 0;
  v5 = *(unsigned int *)(v3 + 24);
  v6 = *(_DWORD **)(**(_QWORD **)(v4 + 912) + 8LL);
  if ( *(v6 - 1) != -2054292729 )
    __break(0x8229u);
  result = ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64, _QWORD *))v6)(v4, 1, 1, v5, v8);
  if ( (result & 0x80000000) == 0 )
  {
    result = 0;
    *a2 = v8[0];
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
