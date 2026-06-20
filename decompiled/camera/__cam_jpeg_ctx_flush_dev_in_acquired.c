__int64 __fastcall _cam_jpeg_ctx_flush_dev_in_acquired(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  unsigned int v3; // w19
  __int64 v4[3]; // [xsp+8h] [xbp-18h] BYREF

  v4[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4[0] = a2;
  v4[1] = 1;
  result = cam_context_flush_dev_to_hw(a1, v4);
  if ( (_DWORD)result )
  {
    v3 = result;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "__cam_jpeg_ctx_flush_dev_in_acquired",
      134,
      "Failed to flush device");
    result = v3;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
