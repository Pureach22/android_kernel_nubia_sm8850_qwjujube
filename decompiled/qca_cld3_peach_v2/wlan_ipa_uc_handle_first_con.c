__int64 __fastcall wlan_ipa_uc_handle_first_con(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x0
  __int64 lan_rx_napi; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  void (__fastcall *v29)(__int64, __int64); // x20
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x0

  v10 = qdf_trace_msg(0x61u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_ipa_uc_handle_first_con");
  lan_rx_napi = ipa_get_lan_rx_napi(v10);
  if ( (lan_rx_napi & 1) != 0 && *(unsigned __int8 *)(a1 + 3705) >= 2u )
  {
    qdf_trace_msg(
      0x61u,
      8u,
      "%s: Multiple SAP connected. Not enabling pipes. Exit",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wlan_ipa_uc_handle_first_con");
    return 12;
  }
  if ( (ipa_get_lan_rx_napi(lan_rx_napi) & 1) != 0 )
  {
    if ( *(_BYTE *)(a1 + 3710) )
    {
      v29 = *(void (__fastcall **)(__int64, __int64))(a1 + 7376);
      if ( v29 )
      {
        if ( *(_DWORD *)(a1 + 1096) )
        {
          if ( *(_DWORD *)(a1 + 1224) )
            goto LABEL_9;
        }
        else
        {
          v38 = *(unsigned __int8 *)(a1 + 1116);
          if ( *((_DWORD *)v29 - 1) != 2130452855 )
            __break(0x8234u);
          v29(v38, 1);
          if ( *(_DWORD *)(a1 + 1224) )
          {
LABEL_9:
            if ( *(_DWORD *)(a1 + 1352) )
              goto LABEL_10;
LABEL_20:
            v40 = *(unsigned __int8 *)(a1 + 1372);
            if ( *((_DWORD *)v29 - 1) != 2130452855 )
              __break(0x8234u);
            v29(v40, 1);
            goto LABEL_10;
          }
        }
        v39 = *(unsigned __int8 *)(a1 + 1244);
        if ( *((_DWORD *)v29 - 1) != 2130452855 )
          __break(0x8234u);
        v29(v39, 1);
        if ( *(_DWORD *)(a1 + 1352) )
          goto LABEL_10;
        goto LABEL_20;
      }
    }
  }
LABEL_10:
  if ( (unsigned int)wlan_ipa_uc_enable_pipes(a1, v21, v22, v23, v24, v25, v26, v27, v28) )
  {
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: IPA WDI Pipe activation failed",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "wlan_ipa_uc_handle_first_con");
    return 8;
  }
  else
  {
    qdf_trace_msg(0x61u, 8u, "%s: exit", v30, v31, v32, v33, v34, v35, v36, v37, "wlan_ipa_uc_handle_first_con");
    return 0;
  }
}
