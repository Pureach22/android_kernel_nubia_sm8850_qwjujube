__int64 __fastcall reg_get_cc_and_src(
        __int64 a1,
        void *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 psoc_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x20

  psoc_obj = reg_get_psoc_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( psoc_obj )
  {
    v20 = psoc_obj;
    qdf_mem_copy(a2, (const void *)(psoc_obj + 91099), 3u);
    return *(unsigned int *)(v20 + 91112);
  }
  else
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: reg psoc private obj is NULL",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "reg_get_cc_and_src");
    return 0;
  }
}
