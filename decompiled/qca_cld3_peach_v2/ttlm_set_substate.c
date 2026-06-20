__int64 __fastcall ttlm_set_substate(
        __int64 result,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30

  if ( a2 - 4 > 5 )
    return qdf_trace_msg(
             0x99u,
             2u,
             "%s: ML peer %d sub state (%d) is invalid",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "ttlm_set_substate",
             *(unsigned int *)(result + 100),
             a2,
             v10,
             v11);
  *(_DWORD *)(result + 732) = a2;
  return result;
}
