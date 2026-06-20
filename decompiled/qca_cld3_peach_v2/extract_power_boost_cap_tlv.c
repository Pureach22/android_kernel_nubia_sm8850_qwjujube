__int64 __fastcall extract_power_boost_cap_tlv(
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
        unsigned __int8 a11,
        _BYTE *a12)
{
  unsigned int v12; // w5
  __int64 v13; // x8

  if ( a10 )
  {
    v12 = *(_DWORD *)(a10 + 72);
    if ( !v12 )
      return 0;
    if ( v12 <= a11 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: TPB: phy_idx: %d >= num_hal_reg_caps: %d",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_power_boost_cap_tlv");
      return 4;
    }
    else
    {
      v13 = *(_QWORD *)(a10 + 288);
      if ( v13 )
      {
        *a12 = (*(_DWORD *)(v13 + 8LL * a11 + 4) & 0x10u) >> 4;
        qdf_trace_msg(
          0x31u,
          8u,
          "%s: TPB: phy_id: %u, enabled: %s",
          a1,
          a2,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          "extract_power_boost_cap_tlv");
        return 0;
      }
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: TPB: Power Boost capabilities is NULL",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_power_boost_cap_tlv");
      *a12 = 0;
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: TPB: Event buffer is empty",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_power_boost_cap_tlv");
    return 16;
  }
}
