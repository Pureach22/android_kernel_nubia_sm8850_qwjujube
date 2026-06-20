unsigned __int8 *__fastcall p2p_parse_assoc_ie_for_device_info(unsigned __int8 *a1, unsigned __int16 a2)
{
  unsigned __int8 *vendor_ie_ptr_from_oui; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned int v11; // w4
  const char *v12; // x2
  unsigned __int8 *result; // x0
  unsigned int v14; // w22
  unsigned __int8 *v15; // x23
  __int64 v16; // x8
  unsigned int v17; // w21
  __int64 v18; // x5

  vendor_ie_ptr_from_oui = wlan_get_vendor_ie_ptr_from_oui(&unk_89A401, 4u, a1, a2);
  if ( vendor_ie_ptr_from_oui )
  {
    v11 = vendor_ie_ptr_from_oui[1];
    if ( v11 >= 4
      && vendor_ie_ptr_from_oui[2] == 80
      && vendor_ie_ptr_from_oui[3] == 111
      && vendor_ie_ptr_from_oui[4] == 154
      && vendor_ie_ptr_from_oui[5] == 9 )
    {
      if ( v11 <= 5 )
      {
        v12 = "%s: Invalid IE len %d";
        goto LABEL_11;
      }
      v14 = v11 - 4;
      v15 = vendor_ie_ptr_from_oui + 6;
      while ( 1 )
      {
        v17 = *(unsigned __int16 *)(v15 + 1);
        v18 = *v15;
        if ( v17 > v14 )
        {
          qdf_trace_msg(
            0x4Eu,
            2u,
            "%s: Invalid len %d for elem:%d",
            v3,
            v4,
            v5,
            v6,
            v7,
            v8,
            v9,
            v10,
            "p2p_parse_assoc_ie_for_device_info",
            *(unsigned __int16 *)(v15 + 1),
            v18);
          return nullptr;
        }
        if ( (unsigned int)v18 <= 0x11 )
        {
          if ( ((1 << v18) & 0x24C5D) != 0 )
            goto LABEL_16;
          if ( (_DWORD)v18 == 13 )
          {
            if ( v17 <= 0x10 )
            {
              v12 = "%s: Invalid Device info attr len %d";
              goto LABEL_11;
            }
            return v15 + 3;
          }
        }
        qdf_trace_msg(
          0x4Eu,
          2u,
          "%s: Unknown attribute in P2P IE %d",
          v3,
          v4,
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          "p2p_parse_assoc_ie_for_device_info",
          *v15);
LABEL_16:
        v16 = v17 + 3;
        result = nullptr;
        v14 -= v16;
        v15 += v16;
        if ( !v14 )
          return result;
      }
    }
    v12 = "%s: P2P OUI not found";
  }
  else
  {
    v12 = "%s: P2P IE not found";
  }
LABEL_11:
  qdf_trace_msg(0x4Eu, 2u, v12, v3, v4, v5, v6, v7, v8, v9, v10, "p2p_parse_assoc_ie_for_device_info");
  return nullptr;
}
