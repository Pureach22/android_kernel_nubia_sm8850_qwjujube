_QWORD *__fastcall p2p_peer_authorized(
        __int64 a1,
        _BYTE *a2,
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
  __int64 v11; // x20
  _QWORD *result; // x0
  __int64 v14; // x19
  __int64 comp_private_obj; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  int v24; // w8
  int v25; // w9
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  const char *v50; // x2

  if ( !a1 )
  {
    v50 = "%s: vdev:%pK";
    return (_QWORD *)qdf_trace_msg(0x4Eu, 2u, v50, a3, a4, a5, a6, a7, a8, a9, a10, "p2p_peer_authorized", 0);
  }
  v10 = *(_QWORD *)(a1 + 216);
  if ( !v10 || (v11 = *(_QWORD *)(v10 + 80)) == 0 )
  {
    v50 = "%s: psoc:%pK";
    return (_QWORD *)qdf_trace_msg(0x4Eu, 2u, v50, a3, a4, a5, a6, a7, a8, a9, a10, "p2p_peer_authorized", 0);
  }
  result = wlan_objmgr_get_peer(*(_QWORD *)(v10 + 80), *(_BYTE *)(v10 + 40), a2, 0xFu);
  if ( result )
  {
    v14 = (__int64)result;
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 5u);
    if ( comp_private_obj )
    {
      v24 = *(_DWORD *)(v14 + 68);
      v25 = *(_DWORD *)(a1 + 16);
      if ( v24 == 4 )
        ++*(_WORD *)(comp_private_obj + 18);
      if ( v25 == 3 && *(_WORD *)(comp_private_obj + 18) && v24 == 4 && (*(_BYTE *)(comp_private_obj + 16) & 1) != 0 )
      {
        *(_BYTE *)(comp_private_obj + 16) = (unsigned int)ucfg_p2p_set_noa(v11, *(unsigned __int8 *)(a1 + 168), 1) != 0;
        qdf_trace_msg(0x4Eu, 8u, "%s: NoA status: %d", v26, v27, v28, v29, v30, v31, v32, v33, "process_peer_for_noa");
      }
      qdf_trace_msg(
        0x4Eu,
        8u,
        "%s: process_peer_for_noa",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "process_peer_for_noa");
      wlan_objmgr_peer_release_ref(v14, 0xFu, v34, v35, v36, v37, v38, v39, v40, v41);
      return (_QWORD *)qdf_trace_msg(
                         0x4Eu,
                         8u,
                         "%s: peer is authorized",
                         v42,
                         v43,
                         v44,
                         v45,
                         v46,
                         v47,
                         v48,
                         v49,
                         "p2p_peer_authorized");
    }
    else
    {
      return (_QWORD *)wlan_objmgr_peer_release_ref(v14, 0xFu, v16, v17, v18, v19, v20, v21, v22, v23);
    }
  }
  return result;
}
