__int64 __fastcall _cam_icp_flush_dev_in_ready(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  unsigned int v4; // w20
  __int64 v5[3]; // [xsp+8h] [xbp-18h] BYREF

  v5[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5[0] = a2;
  v5[1] = 0;
  result = cam_context_flush_dev_to_hw(a1, v5);
  if ( (_DWORD)result )
  {
    v4 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "__cam_icp_flush_dev_in_ready",
      172,
      "[%s] ctx[%u]: Failed to flush device",
      (const char *)a1,
      *(_DWORD *)(a1 + 32));
    result = v4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
