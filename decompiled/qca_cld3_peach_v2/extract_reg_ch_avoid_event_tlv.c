__int64 __fastcall extract_reg_ch_avoid_event_tlv(
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
        _DWORD *a11)
{
  unsigned int v11; // w20
  const char *v12; // x2
  __int64 v15; // x19
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x20
  _DWORD *v26; // x23
  unsigned int *v27; // x24

  if ( !a10 )
  {
    v12 = "%s: Invalid channel avoid event buffer";
    goto LABEL_9;
  }
  if ( !*(_QWORD *)a10 )
  {
    v12 = "%s: Invalid channel avoid event fixed param buffer";
    goto LABEL_9;
  }
  if ( !a11 )
  {
    v12 = "%s: Invalid channel avoid indication buffer";
    goto LABEL_9;
  }
  v11 = *(_DWORD *)(*(_QWORD *)a10 + 4LL);
  if ( *(_DWORD *)(a10 + 24) < v11 )
  {
    v12 = "%s: no.of freq ranges exceeded the limit";
LABEL_9:
    qdf_trace_msg(0x31u, 2u, v12, a1, a2, a3, a4, a5, a6, a7, a8, "extract_reg_ch_avoid_event_tlv");
    return 4;
  }
  if ( v11 >= 0x2A )
    v15 = 42;
  else
    v15 = v11;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: Channel avoid event received with %d ranges",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "extract_reg_ch_avoid_event_tlv",
    (unsigned int)v15);
  *a11 = v15;
  if ( v11 )
  {
    v25 = 0;
    v26 = a11 + 2;
    v27 = (unsigned int *)(*(_QWORD *)(a10 + 16) + 4LL);
    do
    {
      *(v26 - 1) = *v27;
      *v26 = v27[1];
      v26 += 4;
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: range %d tlv id %u, start freq %u, end freq %u",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "extract_reg_ch_avoid_event_tlv",
        (unsigned int)v25++,
        *(v27 - 1),
        *v27);
      v27 += 3;
    }
    while ( v15 != v25 );
  }
  return 0;
}
