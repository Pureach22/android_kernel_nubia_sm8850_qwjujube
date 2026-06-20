__int64 __fastcall sme_set_auto_rate_he_ltf(
        __int64 a1,
        unsigned __int8 a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  int v13; // w8
  __int64 v14; // x2
  unsigned int v15; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w19

  if ( a3 < 4u )
  {
    v13 = (1 << (a3 - 1)) & 7;
    if ( !a3 )
      v13 = 7;
    v14 = *(_DWORD *)(a1 + 21632) & 0xFFFFFFF8 | v13;
    *(_DWORD *)(a1 + 21632) = v14;
    v15 = wma_cli_set_command(a2, 128, v14, 1);
    if ( v15 )
    {
      v24 = v15;
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: failed to set he_ltf_sgi",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "sme_set_auto_rate_he_ltf");
      return v24;
    }
    else
    {
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: HE SGI_LTF is set to 0x%08X",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "sme_set_auto_rate_he_ltf",
        *(unsigned int *)(a1 + 21632));
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(0x34u, 2u, "%s: invalid HE LTF cfg %d", a4, a5, a6, a7, a8, a9, a10, a11, "sme_set_auto_rate_he_ltf");
    return 4294967274LL;
  }
}
