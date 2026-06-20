__int64 __fastcall hdd_set_p2p_go_bcn_int(
        unsigned __int8 *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w20
  __int64 v12; // x21
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  v10 = *(unsigned __int16 *)(a2 + 4);
  v12 = *(_QWORD *)(*(_QWORD *)a1 + 24LL);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: configure P2P GO beacon interval %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "hdd_set_p2p_go_bcn_int",
    *(unsigned __int16 *)(a2 + 4));
  result = sme_set_p2p_go_bcn_int(*(_QWORD *)(v12 + 16), a1[8], v10);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to configure GO beacon interval",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "hdd_set_p2p_go_bcn_int");
    return 4294967274LL;
  }
  return result;
}
