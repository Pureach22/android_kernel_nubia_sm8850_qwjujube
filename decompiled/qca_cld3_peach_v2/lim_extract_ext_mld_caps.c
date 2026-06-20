__int64 __fastcall lim_extract_ext_mld_caps(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  _QWORD *peer_by_mac; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x8
  int v17; // w11
  bool v18; // w9
  __int64 v20; // x19
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7

  peer_by_mac = wlan_objmgr_get_peer_by_mac(*(_QWORD *)(a1 + 21624), (_BYTE *)a3, 7u);
  if ( !peer_by_mac )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: peer is null",
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             "lim_extract_ext_mld_caps");
  v16 = peer_by_mac[98];
  if ( v16 )
  {
    if ( (*(_BYTE *)(*(_QWORD *)(a2 + 16) + 60LL) & 2) != 0 )
    {
      *(_BYTE *)(a3 + 399) = *(_BYTE *)(v16 + 632);
      *(_DWORD *)(a3 + 816) = *(_DWORD *)(a3 + 816) & 0xFFFFFFBF | (((*(_DWORD *)(v16 + 636) >> 6) & 1) << 6);
    }
    else
    {
      v17 = *(_DWORD *)(a3 + 816);
      v18 = (*(_WORD *)(a4 + 5344) & 0x400) != 0;
      *(_BYTE *)(a3 + 399) = v18;
      *(_DWORD *)(a3 + 816) = v17 & 0xFFFFFFBF | (((*(unsigned __int16 *)(a4 + 5364) >> 6) & 1) << 6);
      *(_BYTE *)(v16 + 632) = v18;
      *(_DWORD *)(v16 + 636) = *(_DWORD *)(v16 + 636) & 0xFFFFFFBF | (((*(_DWORD *)(a3 + 816) >> 6) & 1) << 6);
    }
    wlan_objmgr_peer_release_ref((__int64)peer_by_mac, 7u, v8, v9, v10, v11, v12, v13, v14, v15);
    return qdf_trace_msg(
             0x35u,
             8u,
             "%s: Ext mld caps: %d, single link emlsr support: %d",
             v29,
             v30,
             v31,
             v32,
             v33,
             v34,
             v35,
             v36,
             "lim_extract_ext_mld_caps",
             *(unsigned __int8 *)(a3 + 399),
             (*(_DWORD *)(a3 + 816) >> 6) & 1);
  }
  else
  {
    v20 = (__int64)peer_by_mac;
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: mlo peer ctx is null",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "lim_extract_ext_mld_caps");
    return wlan_objmgr_peer_release_ref(v20, 7u, v21, v22, v23, v24, v25, v26, v27, v28);
  }
}
