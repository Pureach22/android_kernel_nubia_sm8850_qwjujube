__int64 __fastcall extract_mgmt_rx_mlo_link_removal_info_tlv(
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
        __int64 a11,
        unsigned int a12)
{
  __int64 v12; // x8
  unsigned int v13; // w9
  __int64 v14; // x10
  _WORD *v15; // x12
  __int64 v17; // x20
  __int64 v18; // x20
  __int64 v19; // x20

  if ( !a10 )
  {
    v17 = jiffies;
    if ( extract_mgmt_rx_mlo_link_removal_info_tlv___last_ticks - jiffies + 125 < 0 )
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
        "extract_mgmt_rx_mlo_link_removal_info_tlv");
      extract_mgmt_rx_mlo_link_removal_info_tlv___last_ticks = v17;
    }
    return 29;
  }
  if ( !a11 )
  {
    v18 = jiffies;
    if ( extract_mgmt_rx_mlo_link_removal_info_tlv___last_ticks_67 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Writable argument is NULL",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_mgmt_rx_mlo_link_removal_info_tlv");
      extract_mgmt_rx_mlo_link_removal_info_tlv___last_ticks_67 = v18;
    }
    return 29;
  }
  if ( *(_DWORD *)(a10 + 152) == a12 )
  {
    if ( a12 )
    {
      v12 = *(_QWORD *)(a10 + 144);
      v13 = 0;
      do
      {
        v14 = v12 + 8LL * (int)v13;
        v15 = (_WORD *)(a11 + 4LL * (int)v13++);
        *v15 = *(_DWORD *)(v14 + 4);
        v15[1] = *(_WORD *)(v14 + 6);
      }
      while ( v13 < *(_DWORD *)(a10 + 152) );
    }
    return 0;
  }
  else
  {
    v19 = jiffies;
    if ( extract_mgmt_rx_mlo_link_removal_info_tlv___last_ticks_68 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: link_removal_info array size (%d) is not equal tonumber of corresponding TLVs(%d) present in event",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_mgmt_rx_mlo_link_removal_info_tlv",
        a12);
      extract_mgmt_rx_mlo_link_removal_info_tlv___last_ticks_68 = v19;
    }
    return 46;
  }
}
