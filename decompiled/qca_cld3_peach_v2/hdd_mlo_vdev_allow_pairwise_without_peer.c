__int64 __fastcall hdd_mlo_vdev_allow_pairwise_without_peer(__int64 a1, unsigned __int8 *a2, _DWORD *a3)
{
  __int64 v3; // x29
  __int64 v4; // x30
  unsigned int v6; // w20
  __int64 ap_link_by_link_id; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v19; // x4
  __int64 v20; // x5
  __int64 v21; // x6
  __int64 v22; // x7
  __int64 v23; // [xsp+8h] [xbp-28h]

  if ( (*(_BYTE *)(a1 + 60) & 2) == 0 )
    return 0;
  v23 = v4;
  v6 = *(unsigned __int8 *)(a1 + 93);
  ap_link_by_link_id = mlo_mgr_get_ap_link_by_link_id(*(_QWORD *)(a1 + 1360), *(unsigned __int8 *)(a1 + 93));
  if ( ap_link_by_link_id )
  {
    if ( *(_DWORD *)(ap_link_by_link_id + 24) == *(_DWORD *)a2
      && *(unsigned __int16 *)(ap_link_by_link_id + 28) == *((unsigned __int16 *)a2 + 2) )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: UC key install for partner VDEV BSS peer",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "hdd_mlo_vdev_allow_pairwise_without_peer",
        v3,
        v23);
      *a3 = 2;
      return 1;
    }
    if ( a2 )
    {
      v19 = *a2;
      v20 = a2[1];
      v21 = a2[2];
      v22 = a2[5];
    }
    else
    {
      v21 = 0;
      v19 = 0;
      v20 = 0;
      v22 = 0;
    }
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: %02x:%02x:%02x:**:**:%02x non BSS peer is not found",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "hdd_mlo_vdev_allow_pairwise_without_peer",
      v19,
      v20,
      v21,
      v22,
      v3,
      v23);
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: MLO link info not found for link id %d",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "hdd_mlo_vdev_allow_pairwise_without_peer",
      v6,
      v3,
      v23);
  }
  return 0;
}
