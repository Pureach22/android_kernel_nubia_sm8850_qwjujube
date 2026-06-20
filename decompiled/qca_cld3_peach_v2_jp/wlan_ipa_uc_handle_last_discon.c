__int64 __fastcall wlan_ipa_uc_handle_last_discon(
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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  _DWORD *v29; // x20
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0

  qdf_trace_msg(0x61u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_ipa_uc_handle_last_discon");
  v20 = wlan_ipa_uc_disable_pipes(a1, a2, v12, v13, v14, v15, v16, v17, v18, v19);
  if ( (ipa_get_lan_rx_napi(v20) & 1) == 0 )
    return qdf_trace_msg(
             0x61u,
             8u,
             "%s: exit: IPA WDI Pipes deactivated",
             v21,
             v22,
             v23,
             v24,
             v25,
             v26,
             v27,
             v28,
             "wlan_ipa_uc_handle_last_discon");
  if ( !*(_BYTE *)(a1 + 3710) )
    return qdf_trace_msg(
             0x61u,
             8u,
             "%s: exit: IPA WDI Pipes deactivated",
             v21,
             v22,
             v23,
             v24,
             v25,
             v26,
             v27,
             v28,
             "wlan_ipa_uc_handle_last_discon");
  v29 = *(_DWORD **)(a1 + 7376);
  if ( !v29 )
    return qdf_trace_msg(
             0x61u,
             8u,
             "%s: exit: IPA WDI Pipes deactivated",
             v21,
             v22,
             v23,
             v24,
             v25,
             v26,
             v27,
             v28,
             "wlan_ipa_uc_handle_last_discon");
  if ( *(_DWORD *)(a1 + 1096) )
  {
    if ( *(_DWORD *)(a1 + 1224) )
      goto LABEL_6;
  }
  else
  {
    v31 = *(unsigned __int8 *)(a1 + 1116);
    if ( *(v29 - 1) != 2130452855 )
      __break(0x8234u);
    ((void (__fastcall *)(__int64, _QWORD))v29)(v31, 0);
    if ( *(_DWORD *)(a1 + 1224) )
    {
LABEL_6:
      if ( *(_DWORD *)(a1 + 1352) )
        return qdf_trace_msg(
                 0x61u,
                 8u,
                 "%s: exit: IPA WDI Pipes deactivated",
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 v26,
                 v27,
                 v28,
                 "wlan_ipa_uc_handle_last_discon");
      goto LABEL_14;
    }
  }
  v32 = *(unsigned __int8 *)(a1 + 1244);
  if ( *(v29 - 1) != 2130452855 )
    __break(0x8234u);
  ((void (__fastcall *)(__int64, _QWORD))v29)(v32, 0);
  if ( !*(_DWORD *)(a1 + 1352) )
  {
LABEL_14:
    v33 = *(unsigned __int8 *)(a1 + 1372);
    if ( *(v29 - 1) != 2130452855 )
      __break(0x8234u);
    ((void (__fastcall *)(__int64, _QWORD))v29)(v33, 0);
  }
  return qdf_trace_msg(
           0x61u,
           8u,
           "%s: exit: IPA WDI Pipes deactivated",
           v21,
           v22,
           v23,
           v24,
           v25,
           v26,
           v27,
           v28,
           "wlan_ipa_uc_handle_last_discon");
}
