__int64 __fastcall mlo_peer_detach_link_peer(__int64 a1, __int64 a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x8
  _QWORD *v13; // x22
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x8
  char v17; // w8
  __int64 v19; // x0
  unsigned int v26; // w10
  int v27; // [xsp+0h] [xbp-20h]
  int v28; // [xsp+8h] [xbp-18h]
  int v29; // [xsp+10h] [xbp-10h]
  int v30; // [xsp+18h] [xbp-8h]

  qdf_mutex_acquire(a1 + 120);
  v13 = (_QWORD *)(a1 + 16);
  v12 = *(_QWORD *)(a1 + 16);
  if ( v12 && v12 == a2 || (v13 = (_QWORD *)(a1 + 56), (v14 = *(_QWORD *)(a1 + 56)) != 0) && v14 == a2 )
  {
    v15 = v13[3];
    if ( v15 )
    {
      _qdf_nbuf_free(v15);
      v13[3] = 0;
    }
    v16 = *(_QWORD *)(a2 + 96);
    if ( v16 )
    {
      _X8 = (unsigned int *)(v16 + 228);
      __asm { PRFM            #0x11, [X8] }
      do
        v26 = __ldxr(_X8);
      while ( __stxr(v26 - 1, _X8) );
    }
    else
    {
      v30 = *(unsigned __int8 *)(a2 + 797);
      v29 = *(unsigned __int8 *)(a2 + 794);
      v28 = *(unsigned __int8 *)(a2 + 793);
      v27 = *(unsigned __int8 *)(a2 + 792);
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: vdev is null for ml_peer: %02x:%02x:%02x:**:**:%02xmld mac addr: %02x:%02x:%02x:**:**:%02x",
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        "mlo_peer_detach_link_peer",
        *(unsigned __int8 *)(a2 + 48),
        *(unsigned __int8 *)(a2 + 49),
        *(unsigned __int8 *)(a2 + 50),
        *(unsigned __int8 *)(a2 + 53),
        v27,
        v28,
        v29,
        v30);
      v19 = printk(
              &unk_AAA255,
              "vdev",
              "mlo_peer_detach_link_peer",
              "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/umac/mlo_mgr/src/wlan_mlo_mgr_peer.c");
      dump_stack(v19);
    }
    wlan_objmgr_peer_release_ref(a2, 0x5Au, v4, v5, v6, v7, v8, v9, v10, v11);
    v17 = *(_BYTE *)(a1 + 96);
    *v13 = 0;
    *(_BYTE *)(a1 + 96) = v17 - 1;
  }
  return qdf_mutex_release(a1 + 120);
}
