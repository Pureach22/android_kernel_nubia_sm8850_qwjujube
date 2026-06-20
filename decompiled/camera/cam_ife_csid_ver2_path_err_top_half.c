__int64 __fastcall cam_ife_csid_ver2_path_err_top_half(__int64 a1, __int64 *a2)
{
  __int64 v2; // x8
  __int64 v3; // x9
  __int64 v4; // x24
  __int64 v6; // x21
  unsigned int evt_payload; // w20
  char **irq_reg_tag_ptr; // x0
  char **v9; // x22
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x21
  __int64 v13; // x0
  __int64 v14; // x1
  _QWORD v16[2]; // [xsp+10h] [xbp-10h] BYREF

  v16[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a2;
  if ( *a2 )
  {
    v3 = *(_QWORD *)(v2 + 16);
    v4 = *(_QWORD *)(v2 + 24);
    v16[0] = 0;
    v6 = *(_QWORD *)(*(_QWORD *)(v3 + 112) + 3680LL);
    evt_payload = cam_ife_csid_ver2_get_evt_payload(v6, v16, (_QWORD **)(v6 + 30952), v6 + 30972);
    irq_reg_tag_ptr = cam_ife_csid_get_irq_reg_tag_ptr();
    v9 = irq_reg_tag_ptr;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_csid_ver2_path_err_top_half",
        978,
        "CSID:%u %s status: 0x%x",
        *(_DWORD *)(*(_QWORD *)(v6 + 31120) + 4LL),
        irq_reg_tag_ptr[*(unsigned int *)(v4 + 220)],
        *(_DWORD *)a2[2]);
      if ( evt_payload )
        goto LABEL_5;
    }
    else if ( evt_payload )
    {
LABEL_5:
      if ( (unsigned int)__ratelimit(
                           &cam_ife_csid_ver2_path_err_top_half__rs_261,
                           "cam_ife_csid_ver2_path_err_top_half") )
        v10 = 3;
      else
        v10 = 2;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, char *, _DWORD))cam_print_log)(
        v10,
        8,
        3,
        "cam_ife_csid_ver2_path_err_top_half",
        984,
        "CSID:%u %s status: 0x%x",
        *(unsigned int *)(*(_QWORD *)(v6 + 31120) + 4LL),
        v9[*(unsigned int *)(v4 + 220)],
        *(_DWORD *)a2[2]);
      goto LABEL_15;
    }
    v12 = v16[0];
    *(_DWORD *)((char *)&qword_10 + v16[0]) = *(_DWORD *)a2[2];
    v13 = ktime_get_with_offset(1);
    *(_QWORD *)v4 = ns_to_timespec64(v13);
    *(_QWORD *)(v4 + 8) = v14;
    a2[3] = v12;
    goto LABEL_15;
  }
  if ( (unsigned int)__ratelimit(&cam_ife_csid_ver2_path_err_top_half__rs, "cam_ife_csid_ver2_path_err_top_half") )
    v11 = 3;
  else
    v11 = 2;
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    v11,
    8,
    1,
    "cam_ife_csid_ver2_path_err_top_half",
    962,
    "No private returned");
  evt_payload = -19;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return evt_payload;
}
