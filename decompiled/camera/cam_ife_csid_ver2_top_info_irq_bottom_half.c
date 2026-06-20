__int64 __fastcall cam_ife_csid_ver2_top_info_irq_bottom_half(__int64 a1, __int64 a2)
{
  unsigned int v2; // w8
  __int64 result; // x0
  _QWORD v5[2]; // [xsp+0h] [xbp-10h] BYREF

  v5[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 )
  {
    v2 = *(_DWORD *)(a2 + 16);
    v5[0] = a2;
    cam_ife_csid_ver2_process_top_info(a1, v2);
    cam_ife_csid_ver2_put_evt_payload(a1, v5, a1 + 30952, a1 + 30972);
    result = 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_top_info_irq_bottom_half",
      3138,
      "Invalid params");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
