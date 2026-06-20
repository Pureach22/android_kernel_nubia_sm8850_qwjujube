__int64 __fastcall cm_update_owe_info(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  _BYTE *v5; // x19
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x8
  __int64 v23; // x4
  unsigned __int8 *vendor_ie_ptr_from_oui; // x0
  const char *v25; // x2
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7

  result = wlan_cm_get_rso_config_fl(a1, "cm_update_owe_info", 1599);
  if ( result )
  {
    v5 = (_BYTE *)result;
    result = wlan_crypto_get_param(a1, 7u);
    if ( (result & 0x400000) == 0 )
      goto LABEL_10;
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: [OWE_TRANSITION]:Update the owe open bss's ssid",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "cm_update_owe_info");
    v22 = *(_QWORD *)(a2 + 80);
    v23 = *(unsigned int *)(a2 + 72);
    if ( v22 && (unsigned int)v23 > 0x24 )
    {
      vendor_ie_ptr_from_oui = wlan_get_vendor_ie_ptr_from_oui(
                                 &unk_969AA7,
                                 4u,
                                 (unsigned __int8 *)(v22 + 36),
                                 (unsigned __int16)v23 - 36);
      if ( !vendor_ie_ptr_from_oui || vendor_ie_ptr_from_oui[1] <= 0xDu )
      {
        result = qdf_trace_msg(
                   0x68u,
                   8u,
                   "%s: [OWE_TRANSITION]: Invalid owe transition ie",
                   v14,
                   v15,
                   v16,
                   v17,
                   v18,
                   v19,
                   v20,
                   v21,
                   "cm_update_owe_info");
        goto LABEL_10;
      }
      v5[792] = 1;
      v23 = vendor_ie_ptr_from_oui[12];
      if ( (unsigned int)v23 < 0x21 )
      {
        v5[793] = v23;
        qdf_mem_copy(v5 + 794, vendor_ie_ptr_from_oui + 13, (unsigned int)v23);
        return qdf_trace_msg(
                 0x68u,
                 8u,
                 "%s: [OWE_TRANSITION] open bss ssid: \"%.*s\"",
                 v26,
                 v27,
                 v28,
                 v29,
                 v30,
                 v31,
                 v32,
                 v33,
                 "cm_update_owe_info",
                 (unsigned __int8)v5[793],
                 v5 + 794);
      }
      v25 = "%s: [OWE_TRANSITION] Invalid ssid len %d";
    }
    else
    {
      v25 = "%s: invalid beacon probe rsp len %d";
    }
    result = qdf_trace_msg(0x68u, 8u, v25, v14, v15, v16, v17, v18, v19, v20, v21, "cm_update_owe_info", v23);
LABEL_10:
    if ( v5[792] == 1 )
      v5[792] = 0;
  }
  return result;
}
