__int64 __fastcall extract_twt_disable_comp_event_tlv(
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
  __int64 v11; // x29
  __int64 v12; // x30
  __int64 v13; // x8
  __int64 result; // x0
  unsigned int v15; // w8

  if ( a10 )
  {
    v13 = *a10;
    result = 0;
    *a11 = *(_DWORD *)(*a10 + 4);
    v15 = *(_DWORD *)(v13 + 8);
    if ( v15 >= 4 )
      v15 = 4;
    a11[1] = v15;
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: evt_buf is NULL",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_twt_disable_comp_event_tlv",
      v11,
      v12);
    return 4;
  }
  return result;
}
