__int64 __fastcall sme_set_auto_rate_he_sgi(
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
  __int64 v13; // x2
  unsigned int v14; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w19

  if ( (unsigned int)a3 - 12 > 0xFFFFFFFB )
  {
    v13 = *(_DWORD *)(a1 + 21704) & 0xFFFF00FF | (1 << a3);
    *(_DWORD *)(a1 + 21704) = v13;
    v14 = wma_cli_set_command(a2, 128, v13, 1);
    if ( v14 )
    {
      v23 = v14;
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: failed to set he_ltf_sgi",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "sme_set_auto_rate_he_sgi");
      return v23;
    }
    else
    {
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: auto rate HE SGI_LTF is set to 0x%08X",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "sme_set_auto_rate_he_sgi",
        *(unsigned int *)(a1 + 21704));
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: invalid auto rate GI cfg %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "sme_set_auto_rate_he_sgi");
    return 4294967274LL;
  }
}
