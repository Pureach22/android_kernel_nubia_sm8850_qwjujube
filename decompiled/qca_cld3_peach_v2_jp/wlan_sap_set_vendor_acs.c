__int64 __fastcall wlan_sap_set_vendor_acs(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30

  if ( a1 )
  {
    *(_BYTE *)(a1 + 1612) = a2 & 1;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: Invalid SAP pointer",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_sap_set_vendor_acs",
      v10,
      v11);
    return 5;
  }
}
