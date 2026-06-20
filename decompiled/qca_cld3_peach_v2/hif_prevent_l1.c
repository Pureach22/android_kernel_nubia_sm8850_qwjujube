__int64 __fastcall hif_prevent_l1(__int64 a1)
{
  unsigned int v2; // w19
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned int v18; // w9

  v2 = hif_force_wake_request(a1);
  if ( v2 )
  {
    qdf_trace_msg(0x3Du, 2u, "%s: Force wake request error", v3, v4, v5, v6, v7, v8, v9, v10, "hif_prevent_l1");
  }
  else
  {
    _X8 = (unsigned int *)(a1 + 3944);
    __asm { PRFM            #0x11, [X8] }
    do
      v18 = __ldxr(_X8);
    while ( __stxr(v18 + 1, _X8) );
    qdf_trace_msg(
      0x3Du,
      5u,
      "%s: opt_dp: pcie link up count %d",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "hif_prevent_l1",
      *(unsigned int *)(a1 + 3944));
  }
  return v2;
}
