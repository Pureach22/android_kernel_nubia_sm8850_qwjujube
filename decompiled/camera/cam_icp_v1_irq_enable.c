__int64 __fastcall cam_icp_v1_irq_enable(__int64 a1)
{
  if ( a1 )
    return cam_io_w_mb(3, *(_QWORD *)(a1 + 408) + 16LL);
  else
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             256,
             1,
             "cam_icp_v1_irq_enable",
             537,
             "invalid ICP device info");
}
