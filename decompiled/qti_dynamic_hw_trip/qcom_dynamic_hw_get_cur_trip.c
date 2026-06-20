__int64 __fastcall qcom_dynamic_hw_get_cur_trip(__int64 a1, _DWORD *a2)
{
  __int64 v3; // x0
  __int64 v4; // x8
  int v5; // w9
  __int64 (__fastcall *v6)(__int64, int *, __int64, __int64, __int64, __int64); // x8
  __int64 v7; // x20
  __int64 v8; // x0
  __int64 result; // x0
  unsigned int v10; // w19
  int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = thermal_zone_device_priv();
  v4 = *(_QWORD *)(v3 + 40);
  if ( v4 )
  {
    v5 = *(_DWORD *)(v3 + 64);
    v6 = *(__int64 (__fastcall **)(__int64, int *, __int64, __int64, __int64, __int64))(v4 + 8);
    v7 = v3;
    v8 = *(_QWORD *)(v3 + 48);
    v11 = v5;
    if ( *((_DWORD *)v6 - 1) != 1134762728 )
      __break(0x8228u);
    result = v6(v8, &v11, 0x6A746E7964LL, 1, 4, 4);
    if ( (result & 0x80000000) != 0 )
    {
      v10 = result;
      dev_err(*(_QWORD *)(v7 + 32), "Error to get dyntj trip for %s ret=%d\n", (const char *)v7, result);
      result = v10;
    }
    else
    {
      *a2 = v11;
    }
  }
  else
  {
    result = 0xFFFFFFFFLL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
