__int64 __fastcall tpg_hw_v_1_3_dump_status(_DWORD *a1)
{
  __int64 v1; // x8
  __int64 v2; // x20
  __int64 v3; // x21
  int v5; // w0
  int v6; // w0

  if ( a1 && (v1 = *((_QWORD *)a1 + 4)) != 0 && (v2 = *(_QWORD *)(v1 + 24)) != 0 )
  {
    v3 = *((_QWORD *)a1 + 5);
    if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x200000000LL,
        4,
        "tpg_hw_v_1_3_dump_status",
        740,
        "TPG V1.3 HWL status dump");
    v5 = cam_io_r_mb(*(_QWORD *)(v3 + 288) + *(unsigned int *)(v2 + 4));
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x200000000LL,
      3,
      "tpg_hw_v_1_3_dump_status",
      745,
      "TPG[%d] TPG HW status: 0x%x started",
      *a1,
      v5);
    v6 = cam_io_r_mb(*(_QWORD *)(v3 + 288) + *(unsigned int *)(v2 + 380));
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x200000000LL,
      3,
      "tpg_hw_v_1_3_dump_status",
      749,
      "TPG[%d] TPG HW irq status: 0x%x started",
      *a1,
      v6);
    return 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x200000000LL,
      1,
      "tpg_hw_v_1_3_dump_status",
      733,
      "invalid params");
    return 4294967274LL;
  }
}
