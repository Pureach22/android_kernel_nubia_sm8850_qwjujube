__int64 __fastcall wlan_sap_getstation_ie_information(
        __int64 a1,
        unsigned int *a2,
        unsigned __int8 *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v13; // w21
  size_t v14; // x2
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7

  if ( a1 )
  {
    if ( a2
      && (v13 = *a2,
          *a2 = *(_DWORD *)(a1 + 1224),
          qdf_trace_msg(
            0x39u,
            4u,
            "%s: WPAIE len : %x",
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            "wlan_sap_getstation_ie_information"),
          a3)
      && (v14 = *(unsigned int *)(a1 + 1224), v13 >= (unsigned int)v14) )
    {
      qdf_mem_copy(a3, (const void *)(a1 + 1228), v14);
      qdf_trace_msg(
        0x39u,
        4u,
        "%s: WPAIE: %02x:%02x:%02x:**:**:%02x",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "wlan_sap_getstation_ie_information",
        *a3,
        a3[1],
        a3[2],
        a3[5]);
      return 0;
    }
    else
    {
      return 16;
    }
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
      "wlan_sap_getstation_ie_information");
    return 5;
  }
}
