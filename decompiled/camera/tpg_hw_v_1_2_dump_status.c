__int64 __fastcall tpg_hw_v_1_2_dump_status(__int64 a1)
{
  __int64 v1; // x20
  int v3; // w0

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 40);
    if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x200000000LL,
        4,
        "tpg_hw_v_1_2_dump_status",
        267,
        "TPG V1.2 HWL status dump");
    v3 = cam_io_r_mb(*(_QWORD *)(v1 + 288) + 4LL);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x200000000LL,
      3,
      "tpg_hw_v_1_2_dump_status",
      272,
      "TPG[%d] TPG HW status: 0x%x started",
      *(_DWORD *)a1,
      v3);
    return 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x200000000LL,
      1,
      "tpg_hw_v_1_2_dump_status",
      262,
      "invalid params");
    return 4294967274LL;
  }
}
