__int64 __fastcall extract_oob_connect_response_event_tlv(
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
        int a11,
        __int64 a12)
{
  __int64 v12; // x8
  int v14; // w4
  int v15; // w8

  if ( a10 && a11 )
  {
    v12 = *a10;
    if ( *a10 )
    {
      if ( (unsigned int)(*(_DWORD *)(v12 + 8) - 2) >= 3 )
        v14 = 5;
      else
        v14 = *(_DWORD *)(v12 + 8);
      *(_DWORD *)(a12 + 4) = v14;
      v15 = *(_DWORD *)(v12 + 4);
      *(_BYTE *)a12 = v15;
      qdf_trace_msg(
        0x31u,
        8u,
        "LL_LT_SAP FW vdev %d OOB connect response %d",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        (unsigned __int8)v15);
      return 4 * (unsigned int)(*(_DWORD *)(a12 + 4) == 5);
    }
    else
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: received null event data from target",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_oob_connect_response_event_tlv");
      return 4;
    }
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: Empty transport switch request event",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_oob_connect_response_event_tlv");
    return 16;
  }
}
