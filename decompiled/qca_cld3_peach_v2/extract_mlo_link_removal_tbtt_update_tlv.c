__int64 __fastcall extract_mlo_link_removal_tbtt_update_tlv(
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
  __int64 v11; // x8
  __int64 v13; // x20
  __int64 v14; // x20

  if ( a10 )
  {
    if ( a11 )
    {
      v11 = *(_QWORD *)(a10 + 16);
      *(_DWORD *)a11 = *(_DWORD *)(v11 + 4);
      *(_QWORD *)(a11 + 16) = *(_QWORD *)(v11 + 16);
      *(_QWORD *)(a11 + 8) = *(_QWORD *)(v11 + 8);
      return 0;
    }
    v14 = jiffies;
    if ( extract_mlo_link_removal_tbtt_update_tlv___last_ticks_65 - jiffies + 125 < 0 )
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
        "extract_mlo_link_removal_tbtt_update_tlv");
      extract_mlo_link_removal_tbtt_update_tlv___last_ticks_65 = v14;
    }
  }
  else
  {
    v13 = jiffies;
    if ( extract_mlo_link_removal_tbtt_update_tlv___last_ticks - jiffies + 125 < 0 )
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
        "extract_mlo_link_removal_tbtt_update_tlv");
      extract_mlo_link_removal_tbtt_update_tlv___last_ticks = v13;
    }
  }
  return 29;
}
