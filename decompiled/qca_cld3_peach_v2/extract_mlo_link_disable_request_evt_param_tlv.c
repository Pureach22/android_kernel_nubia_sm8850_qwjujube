__int64 __fastcall extract_mlo_link_disable_request_evt_param_tlv(
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
        __int64 a11)
{
  __int64 v11; // x8
  int v12; // w12
  __int64 v14; // x20
  __int64 v15; // x20

  if ( a10 )
  {
    if ( a11 )
    {
      v11 = *a10;
      *(_WORD *)a11 = *(_DWORD *)(*a10 + 4);
      *(_BYTE *)(a11 + 2) = BYTE2(*(_DWORD *)(v11 + 4));
      *(_BYTE *)(a11 + 3) = *(_BYTE *)(v11 + 7);
      *(_BYTE *)(a11 + 4) = *(_DWORD *)(v11 + 8);
      v12 = *(_DWORD *)(v11 + 8);
      *(_BYTE *)(a11 + 5) = BYTE1(v12);
      *(_DWORD *)(a11 + 8) = *(_DWORD *)(v11 + 12);
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: Link id bitmap 0x%x MLD addr %02x:%02x:%02x:**:**:%02x",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_mlo_link_disable_request_evt_param_tlv",
        BYTE1(v12));
      return 0;
    }
    v15 = jiffies;
    if ( extract_mlo_link_disable_request_evt_param_tlv___last_ticks_70 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: params is NULL",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_mlo_link_disable_request_evt_param_tlv");
      extract_mlo_link_disable_request_evt_param_tlv___last_ticks_70 = v15;
    }
  }
  else
  {
    v14 = jiffies;
    if ( extract_mlo_link_disable_request_evt_param_tlv___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Param_buf is NULL",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_mlo_link_disable_request_evt_param_tlv");
      extract_mlo_link_disable_request_evt_param_tlv___last_ticks = v14;
    }
  }
  return 29;
}
