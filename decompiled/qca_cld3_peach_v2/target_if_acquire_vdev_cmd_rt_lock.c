__int64 __fastcall target_if_acquire_vdev_cmd_rt_lock(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0

  if ( *(_BYTE *)(a1 + 96) == 1 )
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Lock has already been acquired",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "target_if_acquire_vdev_cmd_rt_lock");
  result = qdf_runtime_pm_prevent_suspend((__int64 *)(a1 + 104));
  if ( !(_DWORD)result )
    *(_BYTE *)(a1 + 96) = 1;
  return result;
}
