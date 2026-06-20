__int64 __fastcall extract_audio_transport_switch_req_event_tlv(
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
        int a11,
        unsigned int *a12)
{
  int v12; // w8
  int v14; // w9
  unsigned int v15; // w8

  if ( a10 && a11 )
  {
    if ( *(_QWORD *)a10 )
    {
      v12 = *(_DWORD *)(*(_QWORD *)a10 + 4LL);
      if ( v12 == 1 )
        v14 = 1;
      else
        v14 = 2;
      if ( v12 )
        v15 = v14;
      else
        v15 = 0;
      *a12 = v15;
      qdf_trace_msg(0x31u, 8u, "LL_LT_SAP FW requested bearer switch to %d", a1, a2, a3, a4, a5, a6, a7, a8, v15);
      return 4 * (unsigned int)(*a12 == 2);
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
        "extract_audio_transport_switch_req_event_tlv");
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
      "extract_audio_transport_switch_req_event_tlv");
    return 16;
  }
}
