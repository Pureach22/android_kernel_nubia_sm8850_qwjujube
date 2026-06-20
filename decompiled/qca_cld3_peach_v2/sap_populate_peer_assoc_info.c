__int64 __fastcall sap_populate_peer_assoc_info(__int64 a1, __int64 a2, __int64 a3)
{
  _QWORD *peer_by_mac; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w4
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 result; // x0
  __int64 v33; // x8
  int v34; // w8

  _ReadStatusReg(SP_EL0);
  peer_by_mac = wlan_objmgr_get_peer_by_mac(*(_QWORD *)(a1 + 21624), (_BYTE *)(a2 + 23), 7u);
  if ( !peer_by_mac )
  {
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: Peer object not found",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "sap_populate_peer_assoc_info");
    result = 16;
    goto LABEL_15;
  }
  v14 = (__int64)peer_by_mac;
  qdf_trace_msg(
    0x39u,
    8u,
    "%s: mlo peer assoc:%d",
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    "sap_populate_peer_assoc_info",
    *((unsigned __int8 *)peer_by_mac + 88));
  if ( !(*(_DWORD *)(v14 + 792) | *(unsigned __int16 *)(v14 + 796)) || *(_BYTE *)(v14 + 88) == 1 )
  {
    v23 = *(_DWORD *)(a2 + 112);
    if ( v23 <= 3 )
    {
      qdf_trace_msg(
        0x39u,
        2u,
        "%s: Invalid assoc request length:%d",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "sap_populate_peer_assoc_info");
      wlan_objmgr_peer_release_ref(v14, 7u, v24, v25, v26, v27, v28, v29, v30, v31);
      result = 4;
      goto LABEL_15;
    }
    *(_DWORD *)(a3 + 32) = v23 - 4;
    v33 = *(_QWORD *)(a2 + 120);
    *(_QWORD *)(a3 + 24) = v33 + 4;
    if ( *(_BYTE *)(a2 + 16) == 1 )
    {
      *(_DWORD *)(a3 + 32) = v23 - 10;
      *(_QWORD *)(a3 + 24) = v33 + 10;
    }
  }
  if ( *(_BYTE *)(a2 + 72) )
  {
    if ( wlan_get_vendor_ie_ptr_from_oui(&unk_969516, 4u, *(unsigned __int8 **)(a2 + 80), *(unsigned __int8 *)(a2 + 72)) )
      v34 = 2;
    else
      v34 = 1;
    *(_DWORD *)(a3 + 16) = v34;
  }
  wlan_objmgr_peer_release_ref(v14, 7u, v15, v16, v17, v18, v19, v20, v21, v22);
  result = 0;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
