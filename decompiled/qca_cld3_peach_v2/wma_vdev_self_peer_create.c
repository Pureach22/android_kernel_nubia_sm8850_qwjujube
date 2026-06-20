__int64 __fastcall wma_vdev_self_peer_create(
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
  __int64 v10; // x22
  _QWORD *context; // x0
  __int64 v12; // x19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 result; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // w19
  int v31; // w8
  __int64 v32; // x21
  _QWORD *peer_by_mac; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 objmgr_peer; // x8
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7

  _ReadStatusReg(SP_EL0);
  v10 = *(_QWORD *)(a1 + 520);
  context = _cds_get_context(54, (__int64)"wma_vdev_self_peer_create", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
  {
    result = 16;
    goto LABEL_18;
  }
  v12 = (__int64)context;
  if ( mlme_vdev_uses_self_peer(*(unsigned __int8 *)(a1 + 179), *(unsigned __int8 *)(a1 + 180)) )
  {
    result = wma_create_peer(
               v12,
               (_BYTE *)(v10 + 74),
               0,
               0,
               *(unsigned __int8 *)(v10 + 168),
               0,
               0,
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20);
    if ( (_DWORD)result )
    {
      v30 = result;
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Failed to create peer %d",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "wma_vdev_self_peer_create",
        (unsigned int)result);
      result = v30;
    }
    goto LABEL_18;
  }
  v31 = *(unsigned __int8 *)(a1 + 179);
  if ( v31 != 5 && v31 != 2 )
  {
LABEL_15:
    result = 0;
    goto LABEL_18;
  }
  if ( *(_DWORD *)(v10 + 80) | *(unsigned __int16 *)(v10 + 84) )
    v32 = v10 + 80;
  else
    v32 = v10 + 74;
  if ( v32 )
  {
    if ( *(_DWORD *)v32 | *(unsigned __int16 *)(v32 + 4) )
    {
      peer_by_mac = wlan_objmgr_get_peer_by_mac(*(_QWORD *)(v12 + 24), (_BYTE *)v32, 8u);
      if ( peer_by_mac )
      {
        wlan_objmgr_peer_release_ref((__int64)peer_by_mac, 8u, v34, v35, v36, v37, v38, v39, v40, v41);
        goto LABEL_15;
      }
    }
  }
  objmgr_peer = wma_create_objmgr_peer(
                  v12,
                  *(unsigned __int8 *)(v10 + 168),
                  (unsigned __int8 *)v32,
                  0,
                  (unsigned __int8 *)(v10 + 74));
  result = 0;
  if ( !objmgr_peer )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to create obj mgr peer for self",
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      "wma_vdev_self_peer_create");
    result = 4;
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
