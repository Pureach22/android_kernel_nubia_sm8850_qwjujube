__int64 __fastcall tpg_hw_v_1_2_init(__int64 a1)
{
  __int64 v1; // x19
  _DWORD *v2; // x20
  int v3; // w0
  __int64 v4; // x19

  if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
  {
    v4 = a1;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x200000000LL,
      4,
      "tpg_hw_v_1_2_init",
      279,
      "TPG V1.2 HWL init");
    a1 = v4;
    if ( v4 )
      goto LABEL_4;
LABEL_6:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x200000000LL,
      1,
      "tpg_hw_v_1_2_reset",
      166,
      "invalid params");
    return 0;
  }
  if ( !a1 )
    goto LABEL_6;
LABEL_4:
  v1 = *(_QWORD *)(a1 + 40);
  v2 = (_DWORD *)a1;
  cam_io_w_mb(0, *(_QWORD *)(v1 + 288) + 96LL);
  v3 = cam_io_r_mb(*(_QWORD *)(v1 + 288));
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x200000000LL,
    3,
    "tpg_hw_v_1_2_reset",
    179,
    "TPG[%d] TPG HW version: 0x%x started",
    *v2,
    v3);
  return 0;
}
