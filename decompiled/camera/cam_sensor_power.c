__int64 __fastcall cam_sensor_power(__int64 a1, int a2)
{
  __int64 v2; // x19

  v2 = *(_QWORD *)(a1 + 240);
  if ( v2 )
  {
    mutex_lock(v2 + 3608);
    if ( !a2 && *(_DWORD *)(v2 + 6544) == 4 )
    {
      cam_sensor_power_down(v2);
      *(_DWORD *)(v2 + 6544) = 1;
    }
    mutex_unlock(v2 + 3608);
    return 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      32,
      1,
      "cam_sensor_power",
      1959,
      "s_ctrl ptr is NULL");
    return 4294967274LL;
  }
}
