__int64 __fastcall cam_jpeg_enc_dump_debug_regs(__int64 a1)
{
  __int64 v2; // x20

  v2 = *(_QWORD *)(a1 + 3680);
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    512,
    3,
    "cam_jpeg_enc_dump_debug_regs",
    753,
    "******** JPEG ENCODER REGISTER DUMP *********");
  ((void (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, __int64, _QWORD))cam_soc_util_reg_dump)(
    a1 + 96,
    0,
    *(unsigned int *)(*(_QWORD *)(v2 + 8) + 40LL),
    *(unsigned int *)(*(_QWORD *)(v2 + 8) + 44LL),
    512,
    0);
  ((void (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, __int64, _QWORD))cam_soc_util_reg_dump)(
    a1 + 96,
    0,
    *(unsigned int *)(*(_QWORD *)(v2 + 8) + 48LL),
    *(unsigned int *)(*(_QWORD *)(v2 + 8) + 52LL),
    512,
    0);
  ((void (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, __int64, _QWORD))cam_soc_util_reg_dump)(
    a1 + 96,
    0,
    *(unsigned int *)(*(_QWORD *)(v2 + 8) + 56LL),
    *(unsigned int *)(*(_QWORD *)(v2 + 8) + 60LL),
    512,
    0);
  ((void (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, __int64, _QWORD))cam_soc_util_reg_dump)(
    a1 + 96,
    0,
    *(unsigned int *)(*(_QWORD *)(v2 + 8) + 64LL),
    *(unsigned int *)(*(_QWORD *)(v2 + 8) + 68LL),
    512,
    0);
  return 0;
}
