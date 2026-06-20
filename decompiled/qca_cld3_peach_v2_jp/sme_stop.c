__int64 __fastcall sme_stop(__int64 a1)
{
  unsigned int v2; // w20
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned int v11; // w0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w21

  v2 = rrm_stop();
  if ( v2 )
    qdf_trace_msg(0x34u, 2u, "%s: rrm_stop failed with status: %d", v3, v4, v5, v6, v7, v8, v9, v10, "sme_stop", v2);
  v11 = csr_stop(a1);
  if ( v11 )
  {
    v20 = v11;
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: csr_stop failed with status: %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "sme_stop",
      v11);
    v2 = v20;
  }
  *(_DWORD *)(a1 + 12768) = 0;
  return v2;
}
