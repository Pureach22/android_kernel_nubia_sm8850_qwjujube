__int64 __fastcall extract_ndp_responder_rsp_tlv(__int64 a1, __int64 *a2, __int64 a3)
{
  __int64 v3; // x20
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  int v14; // w8
  int v15; // w9
  int v16; // w10
  _BOOL4 v17; // w11
  int v18; // w12
  int v19; // w13
  int v20; // w14
  int v21; // w15

  v3 = *a2;
  v5 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
         **(_QWORD **)(a1 + 760),
         *(unsigned int *)(*a2 + 4),
         20);
  *(_QWORD *)a3 = v5;
  if ( v5 )
  {
    v14 = *(_DWORD *)(v3 + 8);
    *(_DWORD *)(a3 + 8) = v14;
    v15 = *(_DWORD *)(v3 + 16);
    *(_DWORD *)(a3 + 16) = v15;
    v16 = *(_DWORD *)(v3 + 12);
    *(_DWORD *)(a3 + 12) = v16;
    v17 = *(_DWORD *)(v3 + 32) != 0;
    *(_BYTE *)(a3 + 26) = v17;
    v18 = *(_DWORD *)(v3 + 24);
    *(_BYTE *)(a3 + 20) = v18;
    v19 = *(_DWORD *)(v3 + 24);
    *(_BYTE *)(a3 + 21) = BYTE1(v19);
    v20 = *(_DWORD *)(v3 + 24);
    *(_BYTE *)(a3 + 22) = BYTE2(v20);
    *(_BYTE *)(a3 + 23) = *(_BYTE *)(v3 + 27);
    *(_BYTE *)(a3 + 24) = *(_DWORD *)(v3 + 28);
    v21 = *(_DWORD *)(v3 + 28);
    *(_BYTE *)(a3 + 25) = BYTE1(v21);
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: WMI_NDP_RESPONDER_RSP_EVENTID(0x%X) received. vdev_id: %d, peer_mac_addr: %02x:%02x:%02x:**:**:%02x,transactio"
      "n_id: %d, status_code %d, reason_code: %d, create_peer: %d",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "extract_ndp_responder_rsp_tlv",
      229379,
      *(unsigned int *)(v3 + 4),
      (unsigned __int8)v18,
      BYTE1(v19),
      BYTE2(v20),
      BYTE1(v21),
      v14,
      v16,
      v15,
      v17);
    return 0;
  }
  else
  {
    qdf_trace_msg(0x31u, 2u, "%s: vdev is null", v6, v7, v8, v9, v10, v11, v12, v13, "extract_ndp_responder_rsp_tlv");
    return 4;
  }
}
