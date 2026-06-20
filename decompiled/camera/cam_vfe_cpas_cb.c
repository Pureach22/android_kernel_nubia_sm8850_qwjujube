__int64 __fastcall cam_vfe_cpas_cb(__int64 a1, __int64 a2, unsigned int *a3)
{
  __int64 v3; // x29
  __int64 v4; // x30
  __int64 v6; // x0
  __int64 v8; // [xsp+8h] [xbp-18h]

  if ( !a3 || (*a3 & 0xFFFFFFFC) != 4 )
    return 0;
  v8 = v4;
  if ( (unsigned int)__ratelimit(&cam_vfe_cpas_cb__rs, "cam_vfe_cpas_cb") )
    v6 = 3;
  else
    v6 = 2;
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, __int64, __int64))cam_print_log)(
    v6,
    8,
    1,
    "cam_vfe_cpas_cb",
    29,
    "IFE UBWC Encode error type=%d status=%x",
    *a3,
    a3[1],
    v3,
    v8);
  return 1;
}
