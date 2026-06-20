__int64 __fastcall cam_actuator_establish_link(__int64 a1)
{
  __int64 device_priv; // x0
  __int64 v3; // x19
  __int64 v4; // x8
  const char *v5; // x5
  __int64 v6; // x4

  if ( !a1 )
  {
    v5 = "Invalid Args";
    v6 = 352;
LABEL_7:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x2000,
      1,
      "cam_actuator_establish_link",
      v6,
      v5);
    return 4294967274LL;
  }
  device_priv = cam_get_device_priv(*(_DWORD *)(a1 + 8));
  if ( !device_priv )
  {
    v5 = "Device data is NULL";
    v6 = 359;
    goto LABEL_7;
  }
  v3 = device_priv;
  mutex_lock(device_priv + 3672);
  if ( *(_DWORD *)a1 )
  {
    *(_DWORD *)(v3 + 4592) = *(_DWORD *)(a1 + 4);
    v4 = *(_QWORD *)(a1 + 24);
  }
  else
  {
    v4 = 0;
    *(_DWORD *)(v3 + 4592) = -1;
  }
  *(_QWORD *)(v3 + 4656) = v4;
  mutex_unlock(v3 + 3672);
  return 0;
}
