__int64 __fastcall mlo_peer_allocate_aid(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  unsigned __int16 v13; // w0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v23; // x4
  const char *v24; // x2

  v10 = *(_QWORD *)(a1 + 2232);
  if ( !v10 )
  {
    v23 = *(unsigned __int8 *)(a1 + 16);
    v24 = "%s: MLD ID %d ap_ctx is NULL";
LABEL_7:
    qdf_trace_msg(0x8Fu, 2u, v24, a3, a4, a5, a6, a7, a8, a9, a10, "mlo_peer_allocate_aid", v23);
    return 4;
  }
  if ( !*(_QWORD *)(v10 + 8) )
  {
    v23 = *(unsigned __int8 *)(a1 + 16);
    v24 = "%s: MLD ID %d aid mgr is NULL";
    goto LABEL_7;
  }
  v13 = wlan_mlo_peer_alloc_aid();
  if ( v13 == 0xFFFF )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: MLD ID %d AID alloc failed",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "mlo_peer_allocate_aid",
      *(unsigned __int8 *)(a1 + 16));
    return 17;
  }
  else
  {
    *(_WORD *)(a2 + 184) = v13;
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: MLD ID %d ML Peer %02x:%02x:%02x:**:**:%02x ML assoc id %d",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "mlo_peer_allocate_aid",
      *(unsigned __int8 *)(a1 + 16),
      *(unsigned __int8 *)(a2 + 104),
      *(unsigned __int8 *)(a2 + 105),
      *(unsigned __int8 *)(a2 + 106),
      *(unsigned __int8 *)(a2 + 109),
      v13);
    return 0;
  }
}
