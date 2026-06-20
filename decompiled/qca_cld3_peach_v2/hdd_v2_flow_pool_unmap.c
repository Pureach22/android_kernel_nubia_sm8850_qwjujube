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
  __int64 v29; // x8
  __int64 v30; // x8
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  _QWORD *v40; // x0

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
  if ( v19 )
  {
    v28 = v19;
    if ( (*(_BYTE *)(v19 + 67) & 2) == 0 )
    {
      v29 = *(_QWORD *)(v19 + 216);
      if ( v29 )
      {
        if ( (policy_mgr_is_set_link_in_progress(*(_QWORD *)(v29 + 80)) & 1) != 0 )
          goto LABEL_6;
      }
      else if ( (policy_mgr_is_set_link_in_progress(0) & 1) != 0 )
      {
        goto LABEL_6;
      }
      v40 = _cds_get_context(71, (__int64)"hdd_v2_flow_pool_unmap", v20, v21, v22, v23, v24, v25, v26, v27);
      if ( v40 && *v40 )
      {
        v30 = *(_QWORD *)(*v40 + 112LL);
        if ( v30 )
        {
          v30 = *(_QWORD *)(v30 + 8);
          if ( v30 )
          {
            if ( *(_DWORD *)(v30 - 4) != 1944199495 )
              __break(0x8228u);
            ((void (*)(void))v30)();
          }
        }
      }
      else
      {
        qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v31, v32, v33, v34, v35, v36, v37, v38, "cdp_flow_pool_unmap");
      }
      return wlan_objmgr_vdev_release_ref(v28, 6u, (unsigned int *)v30, v31, v32, v33, v34, v35, v36, v37, v38);
    }
LABEL_6:
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: vdev:%d Link switch/set_link is ongoing do not invoke flow pool unmap",
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
    return wlan_objmgr_vdev_release_ref(v28, 6u, (unsigned int *)v30, v31, v32, v33, v34, v35, v36, v37, v38);
  }
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
}
