__int64 __fastcall target_if_dp_get_arp_stats_event_handler(
        __int64 a1,
        _QWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *v10; // x5
  __int64 v11; // x4
  __int64 v12; // x20
  __int64 psoc_from_scn_hdl; // x0
  __int64 v14; // x19
  __int64 comp_private_obj; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  int v24; // w10
  int v25; // w9
  int v26; // w11
  int v27; // w8
  int v28; // w9
  int v29; // w8
  int v30; // w5
  __int64 v31; // x20
  _DWORD *v32; // x8
  __int64 result; // x0
  const char *v34; // x2
  _DWORD v35[9]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v36; // [xsp+2Ch] [xbp-14h]
  int v37; // [xsp+34h] [xbp-Ch]
  __int64 v38; // [xsp+38h] [xbp-8h]

  v10 = a2;
  v11 = a1;
  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v37 = 0;
  v36 = 0;
  if ( !a1 || !a2 )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: scn: 0x%pK, data: 0x%pK",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_dp_get_arp_stats_event_handler",
      a1,
      a2);
LABEL_16:
    result = 4294967274LL;
    goto LABEL_17;
  }
  v12 = *a2;
  if ( !*a2 )
  {
    v34 = "%s: Invalid get arp stats data event";
LABEL_15:
    qdf_trace_msg(0x45u, 2u, v34, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_dp_get_arp_stats_event_handler", v11, v10);
    goto LABEL_16;
  }
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v34 = "%s: null psoc";
    goto LABEL_15;
  }
  v14 = psoc_from_scn_hdl;
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(psoc_from_scn_hdl, 0x2Eu);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: psoc private object is null",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "dp_intf_get_rx_ops");
    v34 = "%s: null tx ops";
    goto LABEL_15;
  }
  v24 = *(_DWORD *)(v12 + 12);
  v25 = *(_DWORD *)(v12 + 16);
  v26 = *(_DWORD *)(v12 + 20);
  v35[1] = *(_DWORD *)(v12 + 8);
  v27 = *(_DWORD *)(v12 + 4);
  v35[3] = v25;
  v35[4] = v26;
  v35[2] = v24;
  v35[0] = v27;
  v28 = *(_DWORD *)(v12 + 28);
  v35[5] = *(_DWORD *)(v12 + 24);
  v35[6] = v28;
  v29 = *(_DWORD *)(v12 + 36);
  v35[7] = *(_DWORD *)(v12 + 32);
  v35[8] = v29;
  if ( *(_WORD *)(v12 + 46) == 715 )
  {
    LOBYTE(v36) = 1;
    HIDWORD(v36) = *(_DWORD *)(v12 + 48);
    v30 = *(_DWORD *)(v12 + 52);
    v31 = comp_private_obj;
    v37 = v30;
    qdf_trace_msg(
      0x45u,
      8u,
      "%s: tcp_ack_recvd %d icmpv4_rsp_recvd %d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "target_if_dp_get_arp_stats_event_handler");
    comp_private_obj = v31;
  }
  v32 = *(_DWORD **)(comp_private_obj + 840);
  if ( *(v32 - 1) != 586705355 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, _DWORD *))v32)(v14, v35);
  result = 0;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
