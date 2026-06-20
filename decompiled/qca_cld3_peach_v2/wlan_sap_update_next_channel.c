__int64 __fastcall wlan_sap_update_next_channel(
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
  __int64 v11; // x29
  __int64 v12; // x30

  if ( a1 )
  {
    *(_BYTE *)(a1 + 1629) = a2;
    *(_BYTE *)(a1 + 1630) = a3;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: Invalid SAP pointer",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wlan_sap_update_next_channel",
      v11,
      v12);
    return 5;
  }
}
