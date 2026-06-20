__int64 __fastcall cam_ois_power_down(__int64 a1)
{
  int v2; // w0
  unsigned int v3; // w19
  const char *v5; // x5
  __int64 v6; // x4

  if ( !a1 )
  {
    v5 = "failed: o_ctrl %pK";
    v6 = 220;
LABEL_7:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      0x100000,
      1,
      "cam_ois_power_down",
      v6,
      v5,
      0);
    return 4294967274LL;
  }
  if ( *(_QWORD *)(a1 + 3376) == -16 )
  {
    v5 = "failed: power_info %pK";
    v6 = 230;
    goto LABEL_7;
  }
  v2 = cam_sensor_util_power_down(*(_QWORD *)(a1 + 3376) + 16LL, a1 + 80);
  if ( v2 )
  {
    v3 = v2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x100000,
      1,
      "cam_ois_power_down",
      236,
      "power down the core is failed:%d",
      v2);
    return v3;
  }
  else
  {
    camera_io_release(a1 + 3656);
    *(_DWORD *)(a1 + 4512) = 1;
    return 0;
  }
}
