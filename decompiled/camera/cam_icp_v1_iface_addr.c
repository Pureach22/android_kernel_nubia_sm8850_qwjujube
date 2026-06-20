__int64 __fastcall cam_icp_v1_iface_addr(__int64 a1)
{
  if ( a1 )
    return *(_QWORD *)(a1 + 408) + 64LL;
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    256,
    1,
    "cam_icp_v1_iface_addr",
    552,
    "invalid ICP device info");
  return -22;
}
