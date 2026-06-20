__int64 __fastcall hdd_pld_remove_pm_qos(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x29
  __int64 v10; // x30

  if ( !result )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: hdd_ctx is null",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "hdd_pld_remove_pm_qos",
             v9,
             v10);
  if ( *(_BYTE *)(result + 1460) == 1 && (*(_BYTE *)(result + 1461) & 1) == 0 )
    *(_BYTE *)(result + 1460) = 0;
  return result;
}
