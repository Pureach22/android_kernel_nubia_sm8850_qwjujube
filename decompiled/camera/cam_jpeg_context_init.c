__int64 __fastcall cam_jpeg_context_init(__int64 *a1, __int64 a2, __int64 a3, int a4, int a5)
{
  _QWORD *v6; // x24
  __int64 result; // x0
  unsigned int v12; // w19

  if ( a1 && a2 )
  {
    v6 = a1 + 1;
    memset(a1 + 1, 0, 0xDC0u);
    a1[103] = (__int64)(a1 + 5);
    a1[121] = (__int64)(a1 + 9);
    a1[139] = (__int64)(a1 + 13);
    a1[157] = (__int64)(a1 + 17);
    a1[175] = (__int64)(a1 + 21);
    a1[193] = (__int64)(a1 + 25);
    a1[211] = (__int64)(a1 + 29);
    a1[229] = (__int64)(a1 + 33);
    a1[247] = (__int64)(a1 + 37);
    a1[265] = (__int64)(a1 + 41);
    a1[283] = (__int64)(a1 + 45);
    a1[301] = (__int64)(a1 + 49);
    a1[319] = (__int64)(a1 + 53);
    a1[337] = (__int64)(a1 + 57);
    a1[355] = (__int64)(a1 + 61);
    a1[373] = (__int64)(a1 + 65);
    a1[391] = (__int64)(a1 + 69);
    a1[409] = (__int64)(a1 + 73);
    *a1 = a2;
    a1[85] = (__int64)v6;
    a1[427] = (__int64)(a1 + 77);
    result = cam_context_init(a2, "cam-jpeg", 512, a4, 0, a3, (__int64)(a1 + 81), 20, a5);
    if ( (_DWORD)result )
    {
      v12 = result;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        512,
        1,
        "cam_jpeg_context_init",
        376,
        "Camera Context Base init failed");
      return v12;
    }
    else
    {
      *(_QWORD *)(a2 + 248) = &cam_jpeg_ctx_state_machine;
      *(_QWORD *)(a2 + 256) = a1;
      *(_QWORD *)(a2 + 468) = 0x1400000014LL;
      *(_DWORD *)(a2 + 476) = 20;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_context_init",
      361,
      "Invalid Context");
    return 4294967282LL;
  }
  return result;
}
