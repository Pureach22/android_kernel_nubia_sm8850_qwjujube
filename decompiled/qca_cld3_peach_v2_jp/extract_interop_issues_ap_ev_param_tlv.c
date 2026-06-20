__int64 __fastcall extract_interop_issues_ap_ev_param_tlv(
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
  __int64 v13; // x20
  __int64 v14; // x20
  __int64 v15; // x20

  if ( a10 )
  {
    v11 = *a10;
    if ( *a10 )
    {
      if ( *(_DWORD *)(v11 + 8) == 1 )
      {
        *(_DWORD *)(a11 + 16) = *(_DWORD *)(v11 + 4);
        *(_WORD *)(a11 + 20) = *(_DWORD *)(v11 + 12);
        *(_BYTE *)(a11 + 22) = *(_WORD *)(v11 + 14);
        *(_BYTE *)(a11 + 23) = *(_BYTE *)(v11 + 15);
        *(_WORD *)(a11 + 24) = *(_DWORD *)(v11 + 16);
        return 0;
      }
      v15 = jiffies;
      if ( extract_interop_issues_ap_ev_param_tlv___last_ticks_3 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x31u,
          2u,
          "%s: Invalid type",
          a1,
          a2,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          "extract_interop_issues_ap_ev_param_tlv");
        extract_interop_issues_ap_ev_param_tlv___last_ticks_3 = v15;
      }
    }
    else
    {
      v14 = jiffies;
      if ( extract_interop_issues_ap_ev_param_tlv___last_ticks_1 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x31u,
          2u,
          "%s: Invalid fixed_praram",
          a1,
          a2,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          "extract_interop_issues_ap_ev_param_tlv");
        extract_interop_issues_ap_ev_param_tlv___last_ticks_1 = v14;
      }
    }
  }
  else
  {
    v13 = jiffies;
    if ( extract_interop_issues_ap_ev_param_tlv___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Invalid param_buf",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_interop_issues_ap_ev_param_tlv");
      extract_interop_issues_ap_ev_param_tlv___last_ticks = v13;
    }
  }
  return 4294967274LL;
}
