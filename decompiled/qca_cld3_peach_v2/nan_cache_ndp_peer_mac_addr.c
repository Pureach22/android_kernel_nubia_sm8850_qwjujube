__int64 __fastcall nan_cache_ndp_peer_mac_addr(
        __int64 a1,
        const void *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 comp_private_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v21; // x20
  const void *v22; // x1
  unsigned int v23; // w19
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7

  if ( !a1 )
  {
    qdf_trace_msg(0x53u, 2u, "%s: psoc is null", a3, a4, a5, a6, a7, a8, a9, a10, "nan_get_psoc_priv_obj");
    goto LABEL_6;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xFu);
  if ( !comp_private_obj )
  {
LABEL_6:
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: NAN PSOC priv obj is null",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "nan_cache_ndp_peer_mac_addr");
    return 29;
  }
  if ( *(unsigned __int8 *)(comp_private_obj + 382) < 8u )
  {
    v21 = comp_private_obj;
    v22 = a2;
    v23 = *(unsigned __int8 *)(comp_private_obj + 382);
    qdf_mem_copy((void *)(comp_private_obj + 6LL * *(unsigned __int8 *)(comp_private_obj + 382) + 334), v22, 6u);
    qdf_trace_msg(
      0x53u,
      8u,
      "%s: cached peer at index %d",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "nan_cache_ndp_peer_mac_addr",
      v23);
    ++*(_BYTE *)(v21 + 382);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: num peers %d more than max NDP peers",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "nan_cache_ndp_peer_mac_addr");
    return 16;
  }
}
