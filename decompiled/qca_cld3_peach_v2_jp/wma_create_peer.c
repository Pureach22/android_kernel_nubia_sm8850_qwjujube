__int64 __fastcall wma_create_peer(
        __int64 a1,
        _BYTE *a2,
        __int64 a3,
        unsigned int a4,
        unsigned int a5,
        __int64 a6,
        char a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15)
{
  __int64 **context; // x0
  __int64 **v23; // x26
  __int64 result; // x0
  _QWORD *peer_by_mac; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x8
  __int64 v35; // x9
  _DWORD *v36; // x9
  _QWORD *v37; // x20
  _QWORD *v38; // x19

  context = (__int64 **)_cds_get_context(71, (__int64)"wma_create_peer", a8, a9, a10, a11, a12, a13, a14, a15);
  if ( !context )
    return 16;
  v23 = context;
  result = wma_add_peer(a1, a2, a3, a4, a5, a6, a7 & 1);
  if ( (_DWORD)result )
    return result;
  peer_by_mac = wlan_objmgr_get_peer_by_mac(*(_QWORD *)(a1 + 24), a2, 8u);
  if ( !peer_by_mac )
    return 16;
  v34 = *(_QWORD *)(a1 + 520) + 488LL * (unsigned __int8)a5;
  ++*(_DWORD *)(v34 + 244);
  if ( *v23 )
  {
    v35 = **v23;
    if ( v35 )
    {
      v36 = *(_DWORD **)(v35 + 80);
      if ( v36 )
      {
        v37 = peer_by_mac;
        if ( *(v36 - 1) != 1226871712 )
          __break(0x8229u);
        ((void (__fastcall *)(__int64 **, _QWORD, _QWORD *, _QWORD))v36)(v23, a5, peer_by_mac + 6, 0);
        peer_by_mac = v37;
      }
    }
  }
  else
  {
    v38 = peer_by_mac;
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v26, v27, v28, v29, v30, v31, v32, v33, "cdp_peer_setup");
    peer_by_mac = v38;
  }
  wlan_objmgr_peer_release_ref((__int64)peer_by_mac, 8u, v26, v27, v28, v29, v30, v31, v32, v33);
  return 0;
}
