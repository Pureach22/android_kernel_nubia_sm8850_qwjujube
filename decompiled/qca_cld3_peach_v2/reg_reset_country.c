__int64 __fastcall reg_reset_country(
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
  __int64 psoc_obj; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x20
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7

  psoc_obj = reg_get_psoc_obj(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( psoc_obj )
  {
    v18 = psoc_obj;
    qdf_mem_copy((void *)(psoc_obj + 91099), (const void *)(psoc_obj + 91102), 3u);
    qdf_trace_msg(
      0x51u,
      8u,
      "%s: set cur_country %.2s",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "reg_reset_country",
      v18 + 91099);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: psoc reg component is NULL",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "reg_reset_country");
    return 4;
  }
}
