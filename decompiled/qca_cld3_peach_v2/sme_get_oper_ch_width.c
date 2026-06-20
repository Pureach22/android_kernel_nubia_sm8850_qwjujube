__int64 __fastcall sme_get_oper_ch_width(
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
  __int64 v9; // x8
  const char *v11; // x2
  unsigned int v12; // w1

  if ( a1 )
  {
    v9 = *(_QWORD *)(a1 + 40);
    if ( v9 )
      return *(unsigned int *)(v9 + 24);
    v11 = "%s: NULL des_chan";
    v12 = 8;
  }
  else
  {
    v11 = "%s: Invalid vdev id is passed";
    v12 = 2;
  }
  qdf_trace_msg(0x34u, v12, v11, a2, a3, a4, a5, a6, a7, a8, a9, "sme_get_oper_ch_width");
  return 8;
}
