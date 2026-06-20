__int64 __fastcall cam_flash_shutdown(__int64 result)
{
  int v1; // w8
  __int64 v2; // x19
  void (*v3)(void); // x8
  int v4; // w0
  _DWORD *v5; // x8
  int v6; // w0
  int v7; // w20

  v1 = *(_DWORD *)(result + 6200);
  v2 = result;
  if ( (unsigned int)(v1 - 2) >= 2 )
  {
    if ( !v1 )
      return result;
  }
  else
  {
    v3 = *(void (**)(void))(result + 6232);
    if ( *((_DWORD *)v3 - 1) != 1074490795 )
      __break(0x8228u);
    v3();
    v4 = ((__int64 (__fastcall *)(__int64))cam_flash_off)(v2);
    if ( v4 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4096,
        1,
        "cam_flash_shutdown",
        2271,
        "LED OFF FAILED: %d",
        v4);
    v5 = *(_DWORD **)(v2 + 6224);
    if ( v5 )
    {
      if ( *(v5 - 1) != 1815403504 )
        __break(0x8228u);
      v6 = ((__int64 (__fastcall *)(__int64, _QWORD))v5)(v2, 0);
      if ( v6 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          4096,
          1,
          "cam_flash_shutdown",
          2277,
          "Power Down Failed rc: %d",
          v6);
    }
  }
  result = *(unsigned int *)(v2 + 6024);
  if ( (_DWORD)result != 1 )
  {
    result = cam_destroy_device_hdl(result);
    if ( (_DWORD)result )
    {
      v7 = result;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4096,
        1,
        "cam_flash_release_dev",
        2248,
        "Failed in destroying device handle rc = %d",
        result);
      *(_QWORD *)(v2 + 6024) = -1;
      *(_DWORD *)(v2 + 6032) = -1;
      *(_DWORD *)(v2 + 6712) = 0;
      result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 4096,
                 1,
                 "cam_flash_shutdown",
                 2283,
                 "Release failed rc: %d",
                 v7);
    }
    else
    {
      *(_DWORD *)(v2 + 6712) = 0;
      *(_QWORD *)(v2 + 6024) = -1;
      *(_DWORD *)(v2 + 6032) = -1;
    }
  }
  *(_DWORD *)(v2 + 6200) = 0;
  return result;
}
