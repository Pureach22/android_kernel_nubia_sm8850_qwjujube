__int64 __fastcall hal_srng_dump(
        unsigned __int8 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x4
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x4
  const char *v20; // x2
  __int64 v21; // x6
  __int64 v22; // x7
  __int64 v23; // x5

  v9 = *a1;
  if ( *((_DWORD *)a1 + 29) )
  {
    qdf_trace_msg(0x46u, 8u, "%s: === DST RING %d ===", a2, a3, a4, a5, a6, a7, a8, a9, "hal_srng_dump", v9);
    v19 = *((unsigned int *)a1 + 30);
    v20 = "%s: tp %u, hp %u, cached tp %u, loop_cnt %u";
    v21 = *((unsigned int *)a1 + 34);
    v22 = *((unsigned int *)a1 + 38);
    v23 = **((unsigned int **)a1 + 16);
  }
  else
  {
    qdf_trace_msg(0x46u, 8u, "%s: === SRC RING %d ===", a2, a3, a4, a5, a6, a7, a8, a9, "hal_srng_dump", v9);
    v22 = *((unsigned int *)a1 + 34);
    v20 = "%s: hp %u, reap_hp %u, tp %u, cached tp %u";
    v19 = *((unsigned int *)a1 + 30);
    v23 = *((unsigned int *)a1 + 31);
    v21 = **((unsigned int **)a1 + 16);
  }
  return qdf_trace_msg(0x46u, 8u, v20, v11, v12, v13, v14, v15, v16, v17, v18, "hal_srng_dump", v19, v23, v21, v22);
}
