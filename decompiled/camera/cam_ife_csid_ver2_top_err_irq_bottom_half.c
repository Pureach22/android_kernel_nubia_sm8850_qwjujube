__int64 __fastcall cam_ife_csid_ver2_top_err_irq_bottom_half(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v4; // x2
  __int64 v5; // x3
  __int64 v6; // x0
  __int64 result; // x0
  __int64 v9; // x0
  _QWORD v10[2]; // [xsp+0h] [xbp-10h] BYREF

  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 )
  {
    v2 = *(_QWORD *)(a1 + 31136);
    v10[0] = a2;
    if ( *(_QWORD *)(*(_QWORD *)v2 + 592LL) )
    {
      cam_ife_csid_ver2_top_err_process_bottom_half(a1, a2);
      v4 = a1 + 30952;
      v5 = a1 + 30972;
      v6 = a1;
    }
    else
    {
      if ( (unsigned int)__ratelimit(
                           &cam_ife_csid_ver2_top_err_irq_bottom_half__rs,
                           "cam_ife_csid_ver2_top_err_irq_bottom_half") )
        v9 = 3;
      else
        v9 = 2;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        v9,
        8,
        2,
        "cam_ife_csid_ver2_top_err_irq_bottom_half",
        3175,
        "CSID:%u Unexpected Scenario no top error irqs",
        *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL));
      v4 = a1 + 30952;
      v5 = a1 + 30972;
      v6 = a1;
    }
    cam_ife_csid_ver2_put_evt_payload(v6, v10, v4, v5);
    result = 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_top_err_irq_bottom_half",
      3164,
      "Invalid params");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
