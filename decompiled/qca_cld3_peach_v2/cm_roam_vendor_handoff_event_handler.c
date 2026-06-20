__int64 __fastcall cm_roam_vendor_handoff_event_handler(__int64 a1, unsigned int *a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x23
  __int64 result; // x0
  unsigned int *v15; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x19
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7

  v4 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, *a2, 67);
  if ( !v4 )
    return qdf_trace_msg(
             0x68u,
             2u,
             "%s: vdev object is NULL for vdev %d",
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             "cm_roam_vendor_handoff_event_handler",
             *a2);
  v13 = v4;
  result = wlan_vdev_mlme_get_ext_hdl(v4, v5, v6, v7, v8, v9, v10, v11, v12);
  if ( result )
  {
    v24 = result;
    wlan_objmgr_vdev_release_ref(v13, 0x43u, v15, v16, v17, v18, v19, v20, v21, v22, v23);
    if ( (unsigned int)cm_roam_update_vendor_handoff_config(a1, a2) )
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: Failed to update params in rso_config struct",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "cm_roam_vendor_handoff_event_handler");
    if ( (unsigned int)mlme_cm_osif_get_vendor_handoff_params() )
    {
      return qdf_trace_msg(
               0x68u,
               8u,
               "%s: Failed to free vendor handoff request",
               v33,
               v34,
               v35,
               v36,
               v37,
               v38,
               v39,
               v40,
               "cm_roam_vendor_handoff_event_handler");
    }
    else
    {
      result = qdf_trace_msg(
                 0x68u,
                 8u,
                 "%s: Reset vendor handoff req in progress context",
                 v33,
                 v34,
                 v35,
                 v36,
                 v37,
                 v38,
                 v39,
                 v40,
                 "cm_roam_vendor_handoff_event_handler");
      *(_BYTE *)(v24 + 288) = 0;
      *(_QWORD *)(v24 + 280) = 0;
    }
  }
  return result;
}
