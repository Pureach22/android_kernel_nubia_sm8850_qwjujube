__int64 __fastcall cam_ife_csid_ver2_rx2_err_bottom_half(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  _QWORD v4[2]; // [xsp+0h] [xbp-10h] BYREF

  v4[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 )
  {
    v4[0] = a2;
    cam_ife_csid_ver2_rx_err_process_bottom_half(a1, a2, 1);
    cam_ife_csid_ver2_put_evt_payload(a1, v4, a1 + 30936, a1 + 30976);
    result = 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_rx2_err_bottom_half",
      2491,
      "Invalid params");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
