__int64 __fastcall cam_ife_csid_ver2_discard_sof_top_half(__int64 a1, _QWORD *a2)
{
  __int64 v3; // x0
  _QWORD *v4; // x19

  if ( *a2 )
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v4 = a2;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_csid_ver2_discard_sof_top_half",
        1175,
        "CSID: %u status: 0x%x for res: %s",
        *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*a2 + 16LL) + 112LL) + 3680LL) + 31120LL) + 4LL),
        *(_DWORD *)(a2[2] + 4LL * *(unsigned int *)(*(_QWORD *)(*a2 + 24LL) + 220LL)),
        (const char *)(*a2 + 128LL));
      a2 = v4;
    }
    a2[3] = 0;
    return 0;
  }
  else
  {
    if ( (unsigned int)__ratelimit(
                         &cam_ife_csid_ver2_discard_sof_top_half__rs,
                         "cam_ife_csid_ver2_discard_sof_top_half") )
      v3 = 3;
    else
      v3 = 2;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      v3,
      8,
      1,
      "cam_ife_csid_ver2_discard_sof_top_half",
      1164,
      "No private returned");
    return 4294967277LL;
  }
}
