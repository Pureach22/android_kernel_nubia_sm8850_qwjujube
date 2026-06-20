__int64 __fastcall sme_get_ht2040_mode(
        __int64 a1,
        unsigned __int8 a2,
        unsigned int *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  __int64 v12; // x20
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  int v22; // w8
  int v23; // w8

  if ( a1 && a2 <= 5u && (v11 = *(_QWORD *)(a1 + 17296)) != 0 && (v12 = v11 + 96LL * a2, (*(_BYTE *)(v12 + 1) & 1) != 0) )
  {
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: Get HT operation beacon IE, channel_type=%d cur cbmode %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "sme_get_ht2040_mode",
      *a3,
      *(unsigned int *)(v12 + 44));
    v22 = *(_DWORD *)(v12 + 44);
    switch ( v22 )
    {
      case 3:
        v23 = 2;
        goto LABEL_13;
      case 1:
        v23 = 3;
        goto LABEL_13;
      case 0:
        v23 = 1;
LABEL_13:
        *a3 = v23;
        return 0;
    }
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Error!!! Invalid HT20/40 mode !",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "sme_get_ht2040_mode");
    return 16;
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Session not valid for session id %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "sme_get_ht2040_mode",
      a2);
    return 4;
  }
}
