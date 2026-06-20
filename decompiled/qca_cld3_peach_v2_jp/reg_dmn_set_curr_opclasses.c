__int64 __fastcall reg_dmn_set_curr_opclasses(
        unsigned __int8 a1,
        const void *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  if ( a1 <= 0x20u )
  {
    if ( a1 )
      memcpy(&unk_76DE39, a2, a1);
    reg_dmn_curr_supp_opp_classes = a1;
  }
  else
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: invalid num classes %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "reg_dmn_set_curr_opclasses");
  }
  return 0;
}
