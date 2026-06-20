__int64 __fastcall extract_mlo_link_removal_evt_fixed_param_tlv(
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
        _BYTE *a11)
{
  __int64 v12; // x20
  __int64 v13; // x20

  if ( a10 )
  {
    if ( a11 )
    {
      *a11 = *(_DWORD *)(*(_QWORD *)a10 + 4LL);
      return 0;
    }
    v13 = jiffies;
    if ( extract_mlo_link_removal_evt_fixed_param_tlv___last_ticks_62 - jiffies + 125 < 0 )
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
        "extract_mlo_link_removal_evt_fixed_param_tlv");
      extract_mlo_link_removal_evt_fixed_param_tlv___last_ticks_62 = v13;
    }
  }
  else
  {
    v12 = jiffies;
    if ( extract_mlo_link_removal_evt_fixed_param_tlv___last_ticks - jiffies + 125 < 0 )
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
        "extract_mlo_link_removal_evt_fixed_param_tlv");
      extract_mlo_link_removal_evt_fixed_param_tlv___last_ticks = v12;
    }
  }
  return 29;
}
