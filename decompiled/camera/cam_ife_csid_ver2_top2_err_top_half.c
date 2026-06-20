__int64 __fastcall cam_ife_csid_ver2_top2_err_top_half(__int64 a1, __int64 *a2)
{
  __int64 v2; // x20
  unsigned int evt_payload; // w0
  unsigned int v5; // w22
  __int64 v6; // x0
  __int64 result; // x0
  __int64 v8; // x0
  __int64 v9; // x20
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x1
  _QWORD v13[2]; // [xsp+0h] [xbp-10h] BYREF

  v13[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a2;
  if ( *a2 )
  {
    v13[0] = 0;
    evt_payload = cam_ife_csid_ver2_get_evt_payload(v2, v13, v2 + 30952, v2 + 30972);
    if ( evt_payload )
    {
      v5 = evt_payload;
      if ( (unsigned int)__ratelimit(
                           &cam_ife_csid_ver2_top2_err_top_half__rs_166,
                           "cam_ife_csid_ver2_top2_err_top_half") )
        v6 = 3;
      else
        v6 = 2;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD))cam_print_log)(
        v6,
        8,
        3,
        "cam_ife_csid_ver2_top2_err_top_half",
        1549,
        "CSID:%d TOP2 status: 0x%X",
        *(unsigned int *)(*(_QWORD *)(v2 + 31120) + 4LL),
        *(unsigned int *)a2[2]);
      result = v5;
    }
    else
    {
      v9 = v13[0];
      *(_DWORD *)((char *)&qword_10 + v13[0]) = *(_DWORD *)a2[2];
      v10 = ktime_get_with_offset(1);
      v11 = ns_to_timespec64(v10);
      result = 0;
      *(__int64 *)((char *)&_ksymtab_cam_cdm_detect_hang_error + v9) = v11;
      *(__int64 *)((char *)&_ksymtab_cam_cdm_detect_hang_error + v9 + 8) = v12;
      a2[3] = v9;
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&cam_ife_csid_ver2_top2_err_top_half__rs, "cam_ife_csid_ver2_top2_err_top_half") )
      v8 = 3;
    else
      v8 = 2;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      v8,
      8,
      1,
      "cam_ife_csid_ver2_top2_err_top_half",
      1540,
      "No private returned");
    result = 4294967277LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
