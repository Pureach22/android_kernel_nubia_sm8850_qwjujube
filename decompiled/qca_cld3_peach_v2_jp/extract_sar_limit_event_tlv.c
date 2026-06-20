__int64 __fastcall extract_sar_limit_event_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 *a10,
        _DWORD *a11)
{
  __int64 v11; // x8
  unsigned int v12; // w4
  const char *v13; // x2
  _DWORD *v16; // x19
  __int64 v17; // x10
  unsigned int v18; // w8
  _DWORD *v19; // x9
  int *v20; // x10
  int v21; // t1

  if ( !a10 )
  {
    v13 = "%s: input event is NULL";
LABEL_9:
    qdf_trace_msg(0x31u, 2u, v13, a1, a2, a3, a4, a5, a6, a7, a8, "extract_sar_limit_event_tlv");
    return 4;
  }
  if ( !a11 )
  {
    v13 = "%s: output event is NULL";
    goto LABEL_9;
  }
  v11 = *a10;
  if ( !*a10 )
  {
    v13 = "%s: Invalid fixed param";
    goto LABEL_9;
  }
  *a11 = *(_DWORD *)(v11 + 4);
  v12 = *(_DWORD *)(v11 + 8);
  a11[1] = v12;
  if ( v12 > *((_DWORD *)a10 + 6) )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Num rows %d exceeds sar_get_limits rows len %d",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_sar_limit_event_tlv");
    return 4;
  }
  if ( v12 > 0x40 )
  {
    v16 = a11;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Num rows %d exceeds max of %d",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_sar_limit_event_tlv");
    v16[1] = 64;
    a11 = v16;
    v17 = a10[2];
    if ( !v17 )
      goto LABEL_19;
    goto LABEL_16;
  }
  v17 = a10[2];
  if ( !v17 )
  {
LABEL_19:
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: sar_get_limits is NULL",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_sar_limit_event_tlv");
    return 0;
  }
  if ( v12 )
  {
LABEL_16:
    v18 = 0;
    v19 = a11 + 2;
    v20 = (int *)(v17 + 16);
    do
    {
      ++v18;
      *v19 = *(v20 - 3);
      v19[1] = *(v20 - 2);
      v19[2] = *(v20 - 1);
      v21 = *v20;
      v20 += 5;
      v19[3] = v21;
      v19 += 4;
    }
    while ( v18 < a11[1] );
  }
  return 0;
}
