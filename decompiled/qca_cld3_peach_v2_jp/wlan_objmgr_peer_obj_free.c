__int64 __fastcall wlan_objmgr_peer_obj_free(
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
  __int64 v9; // x19
  int v11; // w0
  __int64 v12; // x8
  __int64 v13; // x21
  unsigned int v14; // w8
  int v15; // w23
  int v16; // w22
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x4
  __int64 v26; // x5
  const char *v27; // x2
  __int64 v28; // x6
  __int64 v29; // x7
  __int64 v30; // x4
  __int64 v31; // x5
  const char *v32; // x2
  int v34; // [xsp+0h] [xbp-10h]

  if ( !a1 )
  {
    qdf_trace_msg(0x57u, 2u, "%s: PEER is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_objmgr_peer_obj_free");
    return 16;
  }
  v9 = *(_QWORD *)(a1 + 88);
  if ( !v9 )
  {
    v30 = *(unsigned __int8 *)(a1 + 48);
    v31 = *(unsigned __int8 *)(a1 + 49);
    v32 = "%s: VDEV is NULL for peer(%02x:%02x:%02x:**:**:%02x)";
    goto LABEL_13;
  }
  v11 = qdf_mem_cmp((const void *)(a1 + 48), (const void *)(v9 + 74), 6u);
  v12 = *(_QWORD *)(v9 + 152);
  if ( !v12 || (v13 = *(_QWORD *)(v12 + 80)) == 0 )
  {
    v30 = *(unsigned __int8 *)(a1 + 48);
    v31 = *(unsigned __int8 *)(a1 + 49);
    v32 = "%s: PSOC is NULL for peer(%02x:%02x:%02x:**:**:%02x)";
LABEL_13:
    qdf_trace_msg(
      0x57u,
      2u,
      v32,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_objmgr_peer_obj_free",
      v30,
      v31,
      *(unsigned __int8 *)(a1 + 50),
      *(unsigned __int8 *)(a1 + 53));
    return 16;
  }
  v14 = *(_DWORD *)(a1 + 68);
  v15 = *(unsigned __int8 *)(v9 + 104);
  v16 = v11;
  if ( v14 <= 8 && ((1 << v14) & 0x130) != 0 )
    wlan_objmgr_peer_release_ref(*(_QWORD *)(v9 + 120), 0, a2, a3, a4, a5, a6, a7, a8, a9);
  wlan_objmgr_vdev_get_ref(v9, 0);
  if ( (unsigned int)wlan_objmgr_vdev_peer_detach(v9, a1) == 16 )
  {
    v25 = *(unsigned __int8 *)(a1 + 48);
    v26 = *(unsigned __int8 *)(a1 + 49);
    v27 = "%s: Peer(%02x:%02x:%02x:**:**:%02x) VDEV detach fail, vdev id: %d";
    v28 = *(unsigned __int8 *)(a1 + 50);
    v29 = *(unsigned __int8 *)(a1 + 53);
    v34 = v15;
LABEL_18:
    qdf_trace_msg(
      0x57u,
      2u,
      v27,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "wlan_objmgr_peer_obj_free",
      v25,
      v26,
      v28,
      v29,
      v34);
    wlan_objmgr_vdev_release_ref(v9, 0);
    return 16;
  }
  if ( (unsigned int)wlan_objmgr_psoc_peer_detach(v13, a1) == 16 )
  {
    v25 = *(unsigned __int8 *)(a1 + 48);
    v26 = *(unsigned __int8 *)(a1 + 49);
    v27 = "%s: Peer(%02x:%02x:%02x:**:**:%02x) PSOC detach failure";
    v28 = *(unsigned __int8 *)(a1 + 50);
    v29 = *(unsigned __int8 *)(a1 + 53);
    goto LABEL_18;
  }
  _qdf_mem_free(a1);
  if ( v16 )
    wlan_objmgr_vdev_peer_freed_notify(v9);
  wlan_objmgr_vdev_release_ref(v9, 0);
  return 0;
}
