__int64 __fastcall hdd_v2_flow_pool_unmap(
        unsigned int a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x20
  _QWORD *v29; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x8

  context = _cds_get_context(51, (__int64)"hdd_v2_flow_pool_unmap", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: HDD context null",
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             "hdd_v2_flow_pool_unmap");
  v19 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(*context, a1, 6);
  if ( !v19 )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: Invalid VDEV %d",
             v20,
             v21,
             v22,
             v23,
             v24,
             v25,
             v26,
             v27,
             "hdd_v2_flow_pool_unmap",
             a1);
  v28 = v19;
  v29 = _cds_get_context(71, (__int64)"hdd_v2_flow_pool_unmap", v20, v21, v22, v23, v24, v25, v26, v27);
  if ( v29 && *v29 )
  {
    v38 = *(_QWORD *)(*v29 + 112LL);
    if ( v38 )
    {
      v38 = *(_QWORD *)(v38 + 8);
      if ( v38 )
      {
        if ( *(_DWORD *)(v38 - 4) != 1944199495 )
          __break(0x8228u);
        ((void (*)(void))v38)();
      }
    }
  }
  else
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v30, v31, v32, v33, v34, v35, v36, v37, "cdp_flow_pool_unmap");
  }
  return wlan_objmgr_vdev_release_ref(v28, 6u, (unsigned int *)v38, v30, v31, v32, v33, v34, v35, v36, v37);
}
