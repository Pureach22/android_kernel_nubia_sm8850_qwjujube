__int64 __fastcall cam_vfe_camif_dump_timestamps(__int64 a1)
{
  _QWORD *v1; // x8

  v1 = *(_QWORD **)(a1 + 24);
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_camif_dump_timestamps",
    650,
    "CAMIF ERROR timestamp:[%lld.%09lld] SOF timestamp:[%lld.%09lld] EPOCH timestamp:[%lld.%09lld] EOF timestamp:[%lld.%09lld]",
    v1[2842],
    v1[2843],
    v1[2836],
    v1[2837],
    v1[2838],
    v1[2839],
    v1[2840],
    v1[2841]);
  return 0;
}
