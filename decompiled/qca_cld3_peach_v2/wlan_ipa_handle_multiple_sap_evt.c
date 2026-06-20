__int64 __fastcall wlan_ipa_handle_multiple_sap_evt(
        __int64 result,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7

  v10 = result;
  if ( a2 == 2 )
  {
    result = qdf_trace_msg(
               0x61u,
               8u,
               "%s: Multiple SAP connected. Disabling IPA",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "wlan_ipa_handle_multiple_sap_evt");
    if ( *(_DWORD *)(v10 + 1096) == 1 )
      result = wlan_ipa_uc_offload_enable_disable(
                 (_QWORD *)v10,
                 0,
                 *(_BYTE *)(v10 + 1116),
                 0,
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 v26,
                 v27);
    if ( *(_DWORD *)(v10 + 1224) == 1 )
      result = wlan_ipa_uc_offload_enable_disable(
                 (_QWORD *)v10,
                 0,
                 *(_BYTE *)(v10 + 1244),
                 0,
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 v26,
                 v27);
    if ( *(_DWORD *)(v10 + 1352) == 1 )
      result = wlan_ipa_uc_offload_enable_disable(
                 (_QWORD *)v10,
                 0,
                 *(_BYTE *)(v10 + 1372),
                 0,
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 v26,
                 v27);
    if ( (*(_BYTE *)(v10 + 3440) & 1) == 0 )
      return wlan_ipa_uc_handle_last_discon(v10, 1);
  }
  else
  {
    if ( a2 != 3 )
      return result;
    result = qdf_trace_msg(
               0x61u,
               8u,
               "%s: Multiple SAP disconnecting. Enabling IPA",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "wlan_ipa_handle_multiple_sap_evt");
    if ( *(_WORD *)(v10 + 3706) )
      result = wlan_ipa_uc_handle_first_con(v10);
    if ( *(_DWORD *)(v10 + 1096) == 1 )
    {
      v19 = v10 + 1064;
    }
    else if ( *(_DWORD *)(v10 + 1224) == 1 )
    {
      v19 = v10 + 1192;
    }
    else
    {
      if ( *(_DWORD *)(v10 + 1352) != 1 )
        return result;
      v19 = v10 + 1320;
    }
    return wlan_ipa_uc_offload_enable_disable(
             (_QWORD *)v10,
             0,
             *(_BYTE *)(v19 + 52),
             1,
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18);
  }
  return result;
}
