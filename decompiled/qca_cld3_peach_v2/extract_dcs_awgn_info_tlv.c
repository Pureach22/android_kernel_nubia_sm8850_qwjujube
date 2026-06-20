__int64 __fastcall extract_dcs_awgn_info_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        unsigned int *a11)
{
  unsigned int *v11; // x20
  unsigned int v13; // w0
  unsigned int v14; // w8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  if ( !a10 )
    return 4;
  v11 = *(unsigned int **)(a10 + 48);
  if ( v11 )
  {
    v13 = wmi_map_ch_width(v11[1]);
    *a11 = v13;
    a11[1] = v11[2];
    a11[2] = v11[3];
    a11[3] = v11[4];
    v14 = v11[5];
    a11[4] = v14;
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: width: %u, freq: %u, freq0: %u, freq1: %u, bitmap: 0x%x",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "extract_dcs_awgn_info_tlv",
      v13,
      v14);
    return 0;
  }
  else
  {
    qdf_trace_msg(0x31u, 2u, "%s: Invalid awgn info", a1, a2, a3, a4, a5, a6, a7, a8, "extract_dcs_awgn_info_tlv");
    return 4;
  }
}
