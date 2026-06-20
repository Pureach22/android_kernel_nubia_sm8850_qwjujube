__int64 __fastcall tdls_process_update_peer(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x20
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  const char *v19; // x2
  unsigned int v20; // w20
  double updated; // d0
  unsigned int v22; // w0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v31; // w20
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  bool v40; // cf
  __int64 v41; // [xsp+8h] [xbp-38h] BYREF
  __int64 (__fastcall *v42)(); // [xsp+10h] [xbp-30h]
  __int64 v43; // [xsp+18h] [xbp-28h]
  __int64 v44; // [xsp+20h] [xbp-20h]
  __int64 v45; // [xsp+28h] [xbp-18h]
  __int64 *v46; // [xsp+30h] [xbp-10h]
  __int64 v47; // [xsp+38h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v45 = 0;
  v46 = nullptr;
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = nullptr;
  if ( a1 )
  {
    v10 = *a1;
    if ( *a1 )
    {
      if ( (tdls_check_is_tdls_allowed(*a1) & 1) != 0 )
      {
        if ( (mlo_mgr_is_link_switch_in_progress(v10) & 1) == 0 )
        {
          v41 = 14;
          v42 = tdls_update_peer_serialize_callback;
          LODWORD(v43) = 10;
          LODWORD(v44) = 4000;
          v45 = *a1;
          v46 = a1;
          BYTE4(v43) = 2;
          v31 = wlan_serialization_request((unsigned int *)&v41, v11, v12, v13, v14, v15, v16, v17, v18);
          qdf_trace_msg(
            0,
            8u,
            "%s: req: 0x%pK wlan_serialization_request status:%d",
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            "tdls_process_update_peer",
            a1,
            v31);
          v40 = v31 >= 2;
          v20 = 0;
          if ( !v40 )
            goto LABEL_11;
          goto LABEL_9;
        }
        v19 = "%s: Link Switch in progress, reject update sta for vdev: %d";
      }
      else
      {
        v19 = "%s: TDLS not allowed, reject update station for vdev: %d";
      }
      qdf_trace_msg(
        0,
        2u,
        v19,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "tdls_process_update_peer",
        *(unsigned __int8 *)(v10 + 168));
LABEL_9:
      updated = tdls_internal_update_peer_rsp(a1);
      v20 = v22;
      wlan_objmgr_vdev_release_ref(*a1, 0x11u, (unsigned int *)*a1, updated, v23, v24, v25, v26, v27, v28, v29);
      goto LABEL_10;
    }
  }
  qdf_trace_msg(0, 2u, "%s: req: %pK", a2, a3, a4, a5, a6, a7, a8, a9, "tdls_process_update_peer", a1);
  v20 = 16;
LABEL_10:
  _qdf_mem_free((__int64)a1);
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return v20;
}
