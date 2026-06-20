__int64 __fastcall sme_set11dinfo(__int64 a1, __int64 a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned int v12; // w19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  qdf_trace(52, 3u, 255, 0);
  if ( a2 )
  {
    v12 = ((__int64 (__fastcall *)(__int64, __int64))csr_set_channels)(a1, a2);
    if ( v12 )
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: csr_set_channels failed with status: %d",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "sme_set11dinfo",
        v12);
  }
  else
  {
    qdf_trace_msg(0x34u, 2u, "%s: SME config params empty", v4, v5, v6, v7, v8, v9, v10, v11, "sme_set11dinfo");
    return 16;
  }
  return v12;
}
