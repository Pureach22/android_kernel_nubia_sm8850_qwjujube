__int64 __fastcall hdd_update_multi_client_thermal_support(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 v11; // x19

  if ( *(_QWORD *)result )
  {
    v9 = *(_QWORD *)(*(_QWORD *)result + 2800LL);
    if ( v9 )
    {
      v10 = *(_QWORD *)(v9 + 16);
      if ( v10 )
      {
        v11 = result;
        result = wmi_service_enabled(v10, 0xD9u, a2, a3, a4, a5, a6, a7, a8, a9);
        *(_BYTE *)(v11 + 6922) = result & 1;
      }
    }
  }
  return result;
}
