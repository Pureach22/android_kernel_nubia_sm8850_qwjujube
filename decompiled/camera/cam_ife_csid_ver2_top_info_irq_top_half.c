__int64 __fastcall cam_ife_csid_ver2_top_info_irq_top_half(__int64 a1, __int64 *a2)
{
  __int64 v3; // x21
  unsigned int evt_payload; // w19
  __int64 v5; // x0
  __int64 v6; // x21
  __int64 v7; // x0
  __int64 v8; // x1
  _QWORD v10[2]; // [xsp+0h] [xbp-10h] BYREF

  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a2;
  v10[0] = 0;
  evt_payload = cam_ife_csid_ver2_get_evt_payload(v3, v10, v3 + 30952, v3 + 30972);
  if ( evt_payload )
  {
    if ( (unsigned int)__ratelimit(
                         &cam_ife_csid_ver2_top_info_irq_top_half__rs,
                         "cam_ife_csid_ver2_top_info_irq_top_half") )
      v5 = 3;
    else
      v5 = 2;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD))cam_print_log)(
      v5,
      8,
      2,
      "cam_ife_csid_ver2_top_info_irq_top_half",
      813,
      "CSID:%u get payload failed, TOP info status: 0x%x",
      *(unsigned int *)(*(_QWORD *)(v3 + 31120) + 4LL),
      *(unsigned int *)a2[2]);
  }
  else
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_csid_ver2_top_info_irq_top_half",
        818,
        "CSID:%u TOP info status: 0x%x",
        *(_DWORD *)(*(_QWORD *)(v3 + 31120) + 4LL),
        *(_DWORD *)a2[2]);
    v6 = v10[0];
    *(_DWORD *)((char *)&qword_10 + v10[0]) = *(_DWORD *)a2[2];
    v7 = ktime_get_with_offset(1);
    *(__int64 *)((char *)&_ksymtab_cam_cdm_detect_hang_error + v6) = ns_to_timespec64(v7);
    *(__int64 *)((char *)&_ksymtab_cam_cdm_detect_hang_error + v6 + 8) = v8;
    a2[3] = v6;
  }
  _ReadStatusReg(SP_EL0);
  return evt_payload;
}
