__int64 __fastcall mlme_peer_oper_mode_change_event_handler(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 psoc_from_scn_hdl; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x8
  __int64 v15; // x8
  _DWORD *v16; // x9
  __int64 v17; // x21
  unsigned int v18; // w0
  __int64 v19; // x4
  __int64 ext_hdl; // x0
  _DWORD *v21; // x8
  __int64 result; // x0
  const char *v23; // x2
  unsigned int v24; // w0
  _QWORD v25[3]; // [xsp+8h] [xbp-28h] BYREF
  int v26; // [xsp+20h] [xbp-10h]
  __int64 v27; // [xsp+28h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = 0;
  memset(v25, 0, sizeof(v25));
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v23 = "%s: psoc is null";
    v24 = 73;
    goto LABEL_17;
  }
  v14 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  if ( !v14 || (v15 = *(_QWORD *)(v14 + 16)) == 0 )
  {
    v23 = "%s: wmi_handle is null";
    goto LABEL_15;
  }
  v16 = *(_DWORD **)(*(_QWORD *)(v15 + 728) + 120LL);
  if ( !v16 )
  {
    v19 = 16;
LABEL_21:
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: parsing of event failed, %d",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "mlme_peer_oper_mode_change_event_handler",
      v19);
    goto LABEL_18;
  }
  v17 = psoc_from_scn_hdl;
  if ( *(v16 - 1) != 1059370538 )
    __break(0x8229u);
  v18 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD *))v16)(v15, a2, a3, v25);
  v19 = v18;
  if ( v18 )
    goto LABEL_21;
  ext_hdl = wlan_psoc_mlme_get_ext_hdl(v17);
  if ( !ext_hdl )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: psoc legacy private object is NULL",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "mlme_get_rx_ops");
    goto LABEL_23;
  }
  v21 = *(_DWORD **)(ext_hdl + 7400);
  if ( !v21 )
  {
LABEL_23:
    v23 = "%s: No valid roam rx ops";
    goto LABEL_15;
  }
  if ( *(v21 - 1) != 592221396 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, _QWORD *))v21)(v17, v25);
  if ( (_DWORD)result )
  {
    v23 = "%s: peer_oper_mode_change_event Failed";
LABEL_15:
    v24 = 104;
LABEL_17:
    qdf_trace_msg(v24, 2u, v23, v6, v7, v8, v9, v10, v11, v12, v13, "mlme_peer_oper_mode_change_event_handler");
LABEL_18:
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
