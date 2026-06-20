__int64 __fastcall extract_mlo_link_switch_request_event_tlv(
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
        __int64 a11)
{
  _DWORD *v11; // x8
  __int64 v13; // x20
  __int64 v14; // x20

  if ( a10 )
  {
    if ( a11 )
    {
      v11 = *(_DWORD **)a10;
      *(_BYTE *)a11 = *(_DWORD *)(*(_QWORD *)a10 + 4LL);
      *(_BYTE *)(a11 + 1) = v11[2];
      *(_BYTE *)(a11 + 2) = v11[3];
      *(_DWORD *)(a11 + 12) = v11[4];
      *(_DWORD *)(a11 + 16) = v11[5];
      *(_DWORD *)(a11 + 24) = v11[6];
      return 0;
    }
    v14 = jiffies;
    if ( extract_mlo_link_switch_request_event_tlv___last_ticks_78 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: req is NULL",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_mlo_link_switch_request_event_tlv");
      extract_mlo_link_switch_request_event_tlv___last_ticks_78 = v14;
    }
  }
  else
  {
    v13 = jiffies;
    if ( extract_mlo_link_switch_request_event_tlv___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: buf is NULL",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_mlo_link_switch_request_event_tlv");
      extract_mlo_link_switch_request_event_tlv___last_ticks = v13;
    }
  }
  return 29;
}
