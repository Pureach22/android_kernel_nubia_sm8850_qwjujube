__int64 __fastcall hif_allow_l1(__int64 result)
{
  __int64 v1; // x19
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  unsigned int v16; // w10

  if ( *(int *)(result + 3944) >= 1 )
  {
    v1 = result;
    if ( (unsigned int)hif_force_wake_release(result) )
    {
      return qdf_trace_msg(0x3Du, 2u, "%s: Force wake release error", v2, v3, v4, v5, v6, v7, v8, v9, "hif_allow_l1");
    }
    else
    {
      _X8 = (unsigned int *)(v1 + 3944);
      __asm { PRFM            #0x11, [X8] }
      do
        v16 = __ldxr(_X8);
      while ( __stxr(v16 - 1, _X8) );
      return qdf_trace_msg(
               0x3Du,
               5u,
               "%s: opt_dp: pcie link down count %d",
               v2,
               v3,
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               "hif_allow_l1",
               *(unsigned int *)(v1 + 3944));
    }
  }
  return result;
}
