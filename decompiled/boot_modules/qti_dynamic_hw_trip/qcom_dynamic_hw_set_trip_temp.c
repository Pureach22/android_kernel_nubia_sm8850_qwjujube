__int64 __fastcall qcom_dynamic_hw_set_trip_temp(__int64 a1, __int64 a2, int a3)
{
  __int64 v4; // x0
  _DWORD **v5; // x8
  int v6; // w9
  __int64 v7; // x20
  __int64 v8; // x0
  _DWORD *v9; // x8
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 result; // x0
  unsigned int v13; // w21
  _DWORD v14[2]; // [xsp+0h] [xbp-10h] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = thermal_zone_device_priv();
  v5 = *(_DWORD ***)(v4 + 40);
  if ( v5 )
  {
    v6 = *(_DWORD *)(v4 + 64);
    v7 = v4;
    v8 = *(_QWORD *)(v4 + 48);
    v14[0] = v6;
    v14[1] = a3;
    v9 = *v5;
    if ( *(v9 - 1) != 1737159351 )
      __break(0x8228u);
    v10 = ((__int64 (__fastcall *)(__int64, _DWORD *, __int64, __int64, __int64))v9)(v8, v14, 0x6A746E7964LL, 1, 8);
    if ( (v10 & 0x80000000) != 0 )
    {
      v13 = v10;
      dev_err(*(_QWORD *)(v7 + 32), "Error to set dyntj for trip:%d for %s ret=%d\n", a3, (const char *)v7, v10);
      result = v13;
    }
    else
    {
      if ( v7 )
      {
        v10 = *(_QWORD *)(v7 + 72);
        if ( v10 )
          v10 = ipc_log_string(
                  v10,
                  "[%s] Dynamic threshold request for %s: %d\n",
                  (const char *)(_ReadStatusReg(SP_EL0) + 2320),
                  (const char *)v7,
                  a3);
      }
      *(_DWORD *)(v7 + 80) = a3;
      v11 = sched_clock(v10);
      result = 0;
      *(_QWORD *)(v7 + 88) = v11;
    }
  }
  else
  {
    result = 0xFFFFFFFFLL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
