__int64 __fastcall cam_vfe_camif_ver3_dump_timestamps(__int64 a1)
{
  _QWORD *v1; // x8

  v1 = *(_QWORD **)(a1 + 24);
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_camif_ver3_dump_timestamps",
    827,
    "CAMIF ERROR timestamp:[%lld.%09lld] SOF timestamp:[%lld.%09lld] EPOCH timestamp:[%lld.%09lld] EOF timestamp:[%lld.%09lld]",
    v1[2850],
    v1[2851],
    v1[2844],
    v1[2845],
    v1[2846],
    v1[2847],
    v1[2848],
    v1[2849]);
  return 0;
}
