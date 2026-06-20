__int64 __fastcall sme_reconfig_obss_scan_param(
        __int64 a1,
        char a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v13; // x0

  if ( a1 )
  {
    v13 = _qdf_mem_malloc(6u, "sme_reconfig_obss_scan_param", 13473);
    if ( v13 )
    {
      *(_BYTE *)(v13 + 4) = a2;
      *(_BYTE *)(v13 + 5) = a3 & 1;
      *(_DWORD *)v13 = 398370;
      return umac_send_mb_message_to_mac(v13);
    }
    else
    {
      return 2;
    }
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Invalid mac_handle pointer",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "sme_reconfig_obss_scan_param");
    return 5;
  }
}
