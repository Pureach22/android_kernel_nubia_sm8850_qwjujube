__int64 __fastcall extract_tgtr2p_table_event_tlv(
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

  if ( a10 )
  {
    v11 = *a10;
    *a11 = *(_DWORD *)(*a10 + 8);
    v12 = *(_DWORD *)(v11 + 4);
    a11[1] = v12;
    if ( v12 >= 2 )
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Rate2Power table update failed. Status = %d",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_tgtr2p_table_event_tlv");
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Invalid TGTR2P event buf",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_tgtr2p_table_event_tlv");
    return 16;
  }
}
