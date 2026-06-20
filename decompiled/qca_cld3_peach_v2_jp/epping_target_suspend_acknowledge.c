__int64 __fastcall epping_target_suspend_acknowledge(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        char a10)
{
  __int64 v10; // x29
  __int64 v11; // x30
  __int64 result; // x0

  if ( !g_epping_ctx )
    return qdf_trace_msg(
             0x33u,
             1u,
             "%s: epping_ctx is NULL",
             a1,
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             "epping_target_suspend_acknowledge",
             v10,
             v11);
  *(_BYTE *)(g_epping_ctx + 44) = a10 & 1;
  return result;
}
