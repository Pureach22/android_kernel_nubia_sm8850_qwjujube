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
  unsigned int v19; // w20
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  bool v28; // cf
  unsigned int v29; // w20
  double updated; // d0
  unsigned int v31; // w0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v40; // [xsp+8h] [xbp-38h] BYREF
  __int64 (__fastcall *v41)(); // [xsp+10h] [xbp-30h]
  __int64 v42; // [xsp+18h] [xbp-28h]
  __int64 v43; // [xsp+20h] [xbp-20h]
  __int64 v44; // [xsp+28h] [xbp-18h]
  __int64 *v45; // [xsp+30h] [xbp-10h]
  __int64 v46; // [xsp+38h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v44 = 0;
  v45 = nullptr;
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = nullptr;
  if ( a1 && (v10 = *a1) != 0 )
  {
    if ( (tdls_check_is_tdls_allowed(*a1) & 1) != 0 )
    {
      v40 = 14;
      v41 = tdls_update_peer_serialize_callback;
      LODWORD(v42) = 10;
      LODWORD(v43) = 4000;
      v44 = *a1;
      v45 = a1;
      BYTE4(v42) = 2;
      v19 = wlan_serialization_request((unsigned int *)&v40, v11, v12, v13, v14, v15, v16, v17, v18);
      qdf_trace_msg(
        0,
        8u,
        "%s: req: 0x%pK wlan_serialization_request status:%d",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "tdls_process_update_peer",
        a1,
        v19);
      v28 = v19 >= 2;
      v29 = 0;
      if ( !v28 )
        goto LABEL_10;
    }
    else
    {
      qdf_trace_msg(
        0,
        2u,
        "%s: TDLS not allowed, reject update station for vdev: %d",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "tdls_process_update_peer",
        *(unsigned __int8 *)(v10 + 104));
    }
    updated = tdls_internal_update_peer_rsp(a1);
    v29 = v31;
    wlan_objmgr_vdev_release_ref(*a1, 0x11u, (unsigned int *)*a1, updated, v32, v33, v34, v35, v36, v37, v38);
  }
  else
  {
    qdf_trace_msg(0, 2u, "%s: req: %pK", a2, a3, a4, a5, a6, a7, a8, a9, "tdls_process_update_peer", a1);
    v29 = 16;
  }
  _qdf_mem_free((__int64)a1);
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return v29;
}
